// EndDlg.cpp : implementation file
//

#include "stdafx.h"
#include "..\FiveInLine.h"
#include "EndDlg.h"
#include <mmsystem.h>               //����
#pragma comment(lib, "winmm.lib")   //����

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CEndDlg dialog


CEndDlg::CEndDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CEndDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CEndDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CEndDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CEndDlg)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}

void CEndDlg::Draw(int x, int y, UINT bitmap, CDC *pDC)
{

	CRect rect;

	GetWindowRect(&rect);
	//װ��ͼƬ
	CBitmap m_bmp;
	m_bmp.LoadBitmap(bitmap);
	//��������������Ҫ�ڴ�����ʾ����pDCΪ���ھ�� 
	CDC dc;
	dc.CreateCompatibleDC(pDC); 
	//������ʵ�����������Ե���ʹ��dc.SelectObject(&m_bmp);,Ҳ�ͽ�λͼѡ��dc�� 
	// CBitmap *pOldbmp=�Ǳ��滭ˢ���ͺ������Ļָ���ˢ��Ӧ 
	//���滭ˢ�ͻָ���ˢ���Բ��ã����������Դй©�� 
	CBitmap *pOldbmp=dc.SelectObject(&m_bmp); 
	//����bm��������ȡͼƬ��Ϣ��������Ϊ�˻�ȡͼƬ�ߴ� 
	BITMAP bm;
	m_bmp.GetObject(sizeof(BITMAP),&bm); 

	//pDC->BitBlt(x,y,bm.bmWidth,bm.bmHeight,&dc,0,0,SRCCOPY); 
	SetStretchBltMode(pDC->m_hDC,STRETCH_HALFTONE); 

	pDC->StretchBlt(0,0,rect.Width(),rect.Height(),&dc, 0, 0, bm.bmWidth, bm.bmHeight,SRCCOPY);

	GetDlgItem(IDOK)->InvalidateRect(NULL, TRUE); 

	dc.SelectObject(pOldbmp);//�ָ���ˢ 
}


BEGIN_MESSAGE_MAP(CEndDlg, CDialog)
	//{{AFX_MSG_MAP(CEndDlg)
	ON_WM_PAINT()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CEndDlg message handlers

void CEndDlg::OnPaint() 
{
	CPaintDC dc(this);				// device context for painting
	mciSendString("close .\\res\\cjmlbj.mp3", NULL, 0, NULL);
	CDC *pDC=GetDC();
	if(m_iIsWin==1)
	{
		Draw(0, 0, IDB_BITMAPWIN, pDC);
		mciSendString("play .\\res\\shengli.mp3", NULL, 0, NULL);
	}
	else
	{
		Draw(0, 0, IDB_BITMAPLOSE, pDC);
		mciSendString("play .\\res\\zwshibai.mp3", NULL, 0, NULL);
	}
	// TODO: Add your message handler code here
	
	// Do not call CDialog::OnPaint() for painting messages
}

BOOL CEndDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
	//�޸Ĵ�����ʽ
	ModifyStyle (WS_CAPTION, WS_MINIMIZEBOX, SWP_DRAWFRAME);
	SetWindowText(_T ("WE-���޳�Ʒ-������"));
	// TODO: Add extra initialization here
    m_bmpbtn.LoadBitmaps(IDB_BITMAPBTNWINLOSE,IDB_BITMAPBTNWINLOSE);
	m_bmpbtn.SubclassDlgItem(IDOK,this);
	m_bmpbtn.SizeToContent();
	//͸�����Ի���
	SetWindowLong(this->GetSafeHwnd(),GWL_EXSTYLE,
	GetWindowLong(this->GetSafeHwnd(),GWL_EXSTYLE)^0x00080000);

	HINSTANCE hInst = LoadLibrary("User32.DLL");//��ʽ����DLL
	if(hInst)
	{
		typedef BOOL(WINAPI*MYFUNC)(HWND,COLORREF,BYTE,DWORD);
		MYFUNC fun = NULL;

		//ȡ��SetLayeredWindowAttributes����ָ��
		fun = (MYFUNC)GetProcAddress(hInst,"SetLayeredWindowAttributes");

		if(fun)
			fun(this->GetSafeHwnd(),0,240,2);//ͨ�����������������ô���͸���̶�
		FreeLibrary(hInst);
	}

	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CEndDlg::OnOK() 
{
	// TODO: Add extra validation here
	//mciSendString("close .\\res\\donggan.mp3", NULL, 0, NULL);
	//mciSendString("close .\\res\\zwshibai.mp3", NULL, 0, NULL);
	CDialog::OnOK();
}
