// PromptDlg.cpp : implementation file
//

#include "stdafx.h"
#include "..\FiveInLine.h"
#include "PromptDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CPromptDlg dialog


CPromptDlg::CPromptDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CPromptDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CPromptDlg)
	//}}AFX_DATA_INIT
}


void CPromptDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CPromptDlg)
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CPromptDlg, CDialog)
	//{{AFX_MSG_MAP(CPromptDlg)
	ON_WM_PAINT()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CPromptDlg message handlers

void CPromptDlg::Draw(int x, int y, UINT bitmap, CDC *pDC)
{
	//	װ��ͼƬ
	CBitmap m_bmp;
	m_bmp.LoadBitmap(bitmap);
	//	��������������Ҫ�ڴ�����ʾ����pDCΪ���ھ�� 
	CDC dc;
	dc.CreateCompatibleDC(pDC); 
	//	������ʵ�����������Ե���ʹ��dc.SelectObject(&m_bmp);,Ҳ�ͽ�λͼѡ��dc�� 
	// CBitmap *pOldbmp=�Ǳ��滭ˢ���ͺ������Ļָ���ˢ��Ӧ 
	//	���滭ˢ�ͻָ���ˢ���Բ��ã����������Դй©�� 
	CBitmap *pOldbmp=dc.SelectObject(&m_bmp); 
	//	����bm��������ȡͼƬ��Ϣ��������Ϊ�˻�ȡͼƬ�ߴ� 
	BITMAP bm;
	m_bmp.GetObject(sizeof(BITMAP),&bm); 
	//	��ͼ 
	if(IDB_BITMAPBOARD==bitmap)//������ 
	//if(IDB_BITMAPMAINBG==bitmap)
		pDC->BitBlt(x,y,bm.bmWidth,bm.bmHeight,&dc,0,0,SRCCOPY); 
	else 
	{//	ÿ��ͼƬ����4X4�����ӣ�ֻҪ����һ�������� 
		int w=bm.bmWidth/4; 
		int h=bm.bmHeight/4; 
		TransparentBlt(pDC->m_hDC,x,y,w,h,dc.m_hDC,0,0,w,h,RGB(255,255,255)); 
	} 
	dc.SelectObject(pOldbmp);//�ָ���ˢ 
}

void CPromptDlg::OnPaint() 
{
/**	CPaintDC dc(this); // device context for painting
	
	// TODO: Add your message handler code here
	CDC *pDC = GetDC();
	if(m_iState == 1)					//	����
		Draw(0,0,IDB_BITMAPHUIQI,pDC);
	else if(m_iState == 2)				//	����Ϸ
		Draw(0,0,IDB_BITMAPZAILAI,pDC);
	// Do not call CDialog::OnPaint() for painting messages*/


		CPaintDC dc (this);
		CDC dcMem;
		dcMem.CreateCompatibleDC (&dc);

		CRect rect;
		GetClientRect (&rect);

		BITMAP bitMap;
		m_bmpBackGround.GetBitmap (&bitMap);
		//Step 5. load bitmap to dlg
		CBitmap *pbmpOld = dcMem.SelectObject (&m_bmpBackGround);
		dc.StretchBlt (0, 0, rect.Width (), rect.Height (),
			&dcMem, 0, 0, bitMap.bmWidth, 
			bitMap.bmHeight, SRCCOPY);
	
}

BOOL CPromptDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
	ModifyStyle (WS_CAPTION, WS_MINIMIZEBOX, SWP_DRAWFRAME);
	SetWindowText (_T ("asdf"));

	if(m_iState == 1) // ����
	m_bmpBackGround.LoadBitmap(IDB_BITMAPHUIQI);
	else if(m_iState == 2)
	m_bmpBackGround.LoadBitmap(IDB_BITMAPZAILAI);


	m_bmpbtnOK.LoadBitmaps(IDB_BITMAPTIPBTN1,IDB_BITMAPTIPBTN2);
	m_bmpbtnOK.SubclassDlgItem(IDOK,this);
	m_bmpbtnOK.SizeToContent();

	m_bmpbtnCancel.LoadBitmaps(IDB_BITMAPTIPBTN3,IDB_BITMAPTIPBTN4);
	m_bmpbtnCancel.SubclassDlgItem(IDCANCEL,this);
	m_bmpbtnCancel.SizeToContent();

	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}
