// MainGameDlg.cpp : implementation file
//

#include "stdafx.h"
#include "..\Logic\Statistics.h"
#include "..\Data\ChatSocket.h"
#include "..\FiveInLine.h"
#include "MainGameDlg.h"
#include "EndDlg.h"
#include "PromptDlg.h"
#include <mmsystem.h>               //����
#pragma comment(lib, "winmm.lib")   //����
#include <wingdi.h>
#include <cmath>
#include <stdlib.h>
#include <afxsock.h>
#pragma comment(lib,"ws2_32.lib")
#pragma comment(lib,"msimg32.lib")







#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMainGameDlg dialog





CMainGameDlg::CMainGameDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CMainGameDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CMainGameDlg)
	m_csALLMSG = _T("");
	m_csMSG = _T("");
	
	//}}AFX_DATA_INIT
	AfxInitRichEdit();
}


void CMainGameDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CMainGameDlg)
	DDX_Control(pDX, IDC_RICHEDIT, m_edALLMSG);
	DDX_Text(pDX, IDC_RICHEDIT, m_csALLMSG);
	DDX_Text(pDX, IDC_EDIT_MSG, m_csMSG);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CMainGameDlg, CDialog)
	//{{AFX_MSG_MAP(CMainGameDlg)
	ON_WM_PAINT()
	ON_BN_CLICKED(IDC_BUTEXIT, OnButexit)
	ON_BN_CLICKED(IDC_BUTAGAIN, OnButagain)
	ON_BN_CLICKED(IDC_BUTMUSIC, OnButmusic)
	ON_BN_CLICKED(IDC_BUTREGRET, OnButregret)
	ON_BN_CLICKED(IDC_BUTTON_SEND, OnButtonSend)
	ON_WM_LBUTTONDOWN()
	ON_WM_CTLCOLOR()
	ON_BN_CLICKED(IDC_CANCEL, OnCancel)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMainGameDlg message handlers
/////////����Ի������ر�Ч��/////////////////
#define AW_CENTER                   0x00000010		//����
#define AW_HIDE                     0x00010000		//����
/////////////////////////////////////////////////
BOOL CMainGameDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();

	

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon
	
	//[[ Step 1. �޸Ĵ�����ʽ
	ModifyStyle (WS_CAPTION, WS_MINIMIZEBOX, SWP_DRAWFRAME);
	//SetWindowText (_T ("asdf"));
	
	SetIcon (m_hIcon, TRUE);
	SetIcon (m_hIcon, FALSE);

	//Step 2.load bitmap
	m_bmpBackGround.LoadBitmap (IDB_BITMAPMAINBG);

	//Step 8. ������ť����֮��Ӧ�ĳ�Ա����
	//step 9. ���ذ�ťͼƬ
//	m_bmpbtnClose.LoadBitmaps (IDB_BITMAPCLOSENORMAL,
//		IDB_BITMAPDOWN);
//	m_bmpbtnTwoState.LoadBitmaps (IDB_BITMAPONNORMAL,
//		IDB_BITMAPONDOWN);
	
//	m_bEnable = TRUE;
/**
	m_csStatic1.SubclassDlgItem (IDC_STATIC1, this);
	m_csTwoState.SubclassDlgItem (IDC_STATIC2, this);
	m_csAttribute.SubclassDlgItem (IDC_STATIC3, this);*/
	m_csAttribute.SetTextColor (RGB (255, 0, 0));
	//]]





//////////////////////////////////////////////////////////////////////////////////
	/////////////ʹ����һ�ָ�����ʵ�ֵķ���������ťλͼ/////////////
//////////////////////////////////////////////////////////////////////////////////

	m_bmpbtnMusic.SubclassDlgItem(IDC_BUTMUSIC,this);
	//m_bmpbtnMusic.LoadBitmaps(IDB_BITMAPMUSICOFF,IDB_BITMAPMUSICON);
	m_bmpbtnMusic.LoadBitmaps(IDB_BITMAPMUSICOFF);
	
	m_bmpbtnMusic.SizeToContent();



	m_bmpbtnAgain.SubclassDlgItem(IDC_BUTAGAIN,this);
	m_bmpbtnAgain.LoadBitmaps(IDB_BITMAPAGAIN1,IDB_BITMAPAGAIN2);
	
	m_bmpbtnAgain.SizeToContent();



	m_bmpbtnRegret.SubclassDlgItem(IDC_BUTREGRET,this);
	m_bmpbtnRegret.LoadBitmaps(IDB_BITMAPREGRET1,IDB_BITMAPREGRET2);
	
	m_bmpbtnRegret.SizeToContent();



	m_bmpbtnExit.SubclassDlgItem(IDC_BUTEXIT,this);
	m_bmpbtnExit.LoadBitmaps(IDB_BITMAPEXIT1,IDB_BITMAPEXIT2);
	
	m_bmpbtnExit.SizeToContent();



	m_bmpbtnSend.SubclassDlgItem(IDC_BUTTON_SEND,this);
	m_bmpbtnSend.LoadBitmaps(IDB_BITMAPSEND1,IDB_BITMAPSEND2);
	
	m_bmpbtnSend.SizeToContent();

	m_bmpbtnExitReal.SubclassDlgItem(IDC_CANCEL,this);
	m_bmpbtnExitReal.LoadBitmaps(IDB_BITMAPEXITGAME,IDB_BITMAPEXITGAME);
	
	m_bmpbtnExitReal.SizeToContent();

//////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////

	




//////////////////////////////////////////////////////////////////////////////////
	//////////////////////����رմ�����Ч//////////////////
//////////////////////////////////////////////////////////////////////////////////
 	CenterWindow ();	
	DWORD dwStyle = AW_CENTER;
	HINSTANCE hInst = LoadLibrary("User32.DLL"); 
	
	typedef BOOL (WINAPI MYFUNC (HWND, DWORD, DWORD));
	MYFUNC *AnimateWindow;
	AnimateWindow = (MYFUNC*)::GetProcAddress (hInst, "AnimateWindow");
	AnimateWindow (this->m_hWnd, 0, dwStyle);
	Invalidate ();
	FreeLibrary (hInst); 
//////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////
	




//////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////
/////������

	for(int i = 0;i < 15;i++)
		for(int j = 0;j < 15;j++)
		{
			chess[i][j] = 0;			//	��ʼ���������飬1Ϊ���壬2Ϊ���壬0Ϊû������
		}
	m_iTheEnd = 0;						//	��ʼ��Ϊδ������Ϸ
	m_isAgreed = false;					//	��ʼ��Ϊ�ܾ����������Ϸ
	m_iPlayer = 2;						//	��ʼ��Ϊ��������
	m_iSuccess = 0;						//	��ʼ��Ϊ���Ӳ��ɹ�
	//m_iMusic =	0;						//	��ʼ������Ϊ�ص�״̬
	//m_isSingle = true;					//	��ʼ��Ϊ������Ϸ
/////������
//////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////





//////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////
/////������
	AfxSocketInit();


	//�ͻ��˽��еĲ���
	if(m_iNet==1)
	{
		SetWindowText(" ������--��ҿͻ��� ");									//	���ô��ڱ���


		m_pSocket = new CClientSocket(this);								// ����Socket�׽���


		if(!m_pSocket->Create()||!m_pSocket->Connect(m_csIPAddress, 7000))	//	���ӵ���������
		{
			delete m_pSocket;
			m_pSocket = NULL;
			MessageBox(" ��������ʧ�ܣ�");
			return FALSE;
		}

		// ��������˷���һ��ע��ɹ�����Ϣ
		CString csLogin = "Login~";
		m_pSocket->Send(csLogin, csLogin.GetLength());

	}
	

	//�������˽��еĲ���
	else if(m_iNet==2)
	{

		m_pSrvSocket = new CSrvSocket(this);									// ����Socket�׽���

		
		// ��������
		SetWindowText(" ������--�������� ");

		if (!m_pSrvSocket->Create(7000))										//	�󶨶˿�
		{
			delete m_pSrvSocket;
			m_pSrvSocket = NULL;
			MessageBox("��ʧ��!");
			return FALSE;
		}

		
		m_pSrvSocket->Listen();													// ��������
	}

/////������
//////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CMainGameDlg::OnPaint() 
{

	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, (WPARAM) dc.GetSafeHdc(), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);		
	}
	else
	{
		//Step 3. remove the follow statement
		//	CDialog::OnPaint();	
		//Step 4. Create memory-DC
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
		//Step 6, add btn and other wnd
		//step 7. add ColorBtn Class.

		CDC *pDC = GetDC();
		Draw(160,10,IDB_BITMAPBOARD,pDC);
		for(int i = 0;i<15;i++)
			for(int j = 0;j<15;j++)
			{
				if(chess[i][j]==2)
					Draw(j*33.5+160,i*33.5+10,IDB_BITMAPWHITE,pDC);
				else if(chess[i][j]==1)
					Draw(j*33.5+160,i*33.5+10,IDB_BITMAPBLACK,pDC);
			}
	}
}

//	�����괥���¼�
void CMainGameDlg::OnLButtonDown(UINT nFlags, CPoint point)
{
	PostMessage (WM_NCLBUTTONDOWN, HTCAPTION, MAKELPARAM (point.x, point.y));

	//	��δ������Ϸ����Ե����¼�������Ӧ
	if(m_iTheEnd==0)
	{
		if(point.x>160&&point.x<650&&point.y>10&&point.y<510)				//	�ж�����Ƿ�������Ч����
		{
			//�������
			
			//	����������λ������Ӧ����������
			PlaySound("res\\luozisy.wav", AfxGetInstanceHandle(), SND_FILENAME | SND_ASYNC | SND_NODEFAULT);   //������Ч
			int j = (int)((point.x-160)/33.5);
			int i = (int)((point.y-10)/33.5);
			int x = (int)(j*33.5+160);
			int y = (int)(i*33.5+10);


			CDC *pDC=GetDC();//��ȡ��ǰ�豸���

			//��ǰλ��������ʱ������в���
			if(chess[i][j] == 0)
			{

				/*CString cs;
				cs.Format("%d,%d",i,j);
				MessageBox(cs,"����");*/

//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////
//////////////////��������սģ��
				if(m_iSuccess==1)												//	�����ӳɹ����������Ӧ
				{
					if(m_iNet==2&&m_iPlayer==2)									//	�ж��Ƿ��ֵ���ǰ����
					{
						Draw(x,y,IDB_BITMAPWHITE,pDC);							//	��������
						chess[i][j] = 2;										//	����������ĸ�λ������Ϊ������"2"
						//step.point2.x=i;
						//step.point2.y=j;

						/////////////////////////////
						//	��¼��ǰ����λ�ã�����ջ
						step.x=i;
						step.y=j;
						m_stack.push(step);
						/////////////////////////////
						

						//	��������Ϣ���ӳ��ַ��������еĿͻ��˷���
						CString x;
						x.Format("%d",i);
						CString y;
						y.Format("%d",j);
						x = x+"~"+y;

						POSITION pPos = m_listClients.GetHeadPosition();		//	����б��е�һ���ͻ���λ��
						
						while(pPos)
						{
							CChatSocket* pCur = m_listClients.GetAt(pPos);
							//csMsgTo = "����Ա~" + m_strMSG;
							pCur->Send(x, x.GetLength());						//	������Ϣ
							//m_strAllMSG += "��� " + pCur->m_strNick + " ˵: " + m_strMSG + "\r\n";
							
							m_listClients.GetNext(pPos);						//	����б�����һ���ͻ���λ��
						}

						//	�ж��Ƿ��Ѿ���ʤ
						if(m_statis.isWin(chess,i,j))
						{
							m_iTheEnd = 1;
							CEndDlg dlg;
							dlg.m_iIsWin=1;
							dlg.DoModal();
							return;
						}
						m_iPlayer = 1;											//	������
					}	//	if(m_iNet==2&&m_iPlayer==2)		END

					//	�ͻ��˽��еĲ���
					else if(m_iNet==1&&m_iPlayer==1)
					{
						Draw(x,y,IDB_BITMAPBLACK,pDC);							//	�ڵ�ǰλ�û�������
						chess[i][j] = 1;										//	����������ĸ�λ������Ϊ������"1"
						//step.point1.x=i;
						//step.point1.y=j;



						/////////////////////////////
						//	��¼��ǰ����λ�ã�����ջ
						step.x=i;
						step.y=j;
						m_stack.push(step);
						/////////////////////////////


						/////////////////////////////////////////////
						//	����ǰ��������Ϣ���ӳ��ַ��������������
						/////////////////////////////////////////////
						CString x;
						x.Format("%d",i);
						CString y;
						y.Format("%d",j);
						x = x+"~"+y;
						m_pSocket->Send(x, x.GetLength());
						/////////////////////////////////////////////
						/////////////////////////////////////////////



						/////////////////////////////////////////////
						//	�ж��Ƿ��Ѿ���ʤ/////////////////////////
						/////////////////////////////////////////////
						if(m_statis.isWin(chess,i,j))
						{
							m_iTheEnd = 1;
					//		MessageBox("����Ӯ��","����");

							//	��������˷��ͶԷ��Ѿ����˵���Ϣ
							//CString lose = "Lose~";
							//m_pSocket->Send(lose, lose.GetLength());
							CEndDlg dlg;
							dlg.m_iIsWin=1;
							dlg.DoModal();
							return;
						}
						/////////////////////////////////////////////
						/////////////////////////////////////////////

						m_iPlayer = 2;													//	������
					}//else if(m_iNet==1&&m_iPlayer==1)	END
				}//if(m_iSuccess==1)  END
//////////////////��������սģ��
//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////


				



//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////
//////////////////�˻���ս�����˶�սģ��
				if(m_iNet==0||m_iSuccess==0)											//	�ж��Ƿ�Ϊ����ģʽ
				{
					if(m_iPlayer==2)
					{

						//�˶δ������ڲ��Ը������Ƿ���ȷ
						/*CString cs;
						cs.Format("%d",m_statis.getScore(chess,i,j));
						MessageBox(cs,"����");*/



						Draw(x,y,IDB_BITMAPWHITE,pDC);									//	�ڵ�ǰλ�û�������
						chess[i][j] = 2;												//	����������ĸ�λ������Ϊ������"2"


						/////////////////////////////
						//	��¼��ǰ������Ϣ������ջ
						step.x=i;
						step.y=j;
						m_stack.push(step);
						/////////////////////////////
						/////////////////////////////

						m_iPlayer=1;													//	��������

					}
					
					//	if(m_isSingle)													
					else if(!m_isSingle)
					{
						Draw(x,y,IDB_BITMAPBLACK,pDC);									//	�ڵ�ǰλ�û�������
						chess[i][j] = 1;												//	����������ĸ�λ������Ϊ������"2"


						/////////////////////////////
						//	��¼��ǰ������Ϣ������ջ
						step.x=i;
						step.y=j;
						m_stack.push(step);
						/////////////////////////////
						/////////////////////////////

						m_iPlayer=2;													//	��������

					}




					////////////////////////////////////////////////////
					//	�ж��Ƿ������Ϸ////////////////////////////////
					////////////////////////////////////////////////////
					if(m_statis.isWin(chess,i,j))
					{
						m_iTheEnd = 1;
						//	MessageBox("����Ӯ��","����");
						
						CEndDlg dlg;
						dlg.m_iIsWin=1;
						dlg.DoModal();
						return;
					}
					////////////////////////////////////////////////////
					////////////////////////////////////////////////////
					
					

					//���������
					if(m_iPlayer==1&&m_isSingle)											//	��Ϊ������Ϸ������������
					{
						m_iPlayer=2;														//	��������
						int max=0,score;
						int k,m;
						//ѭ���������̣�����ÿ����λ�õķ�������¼��ǰ��߷�ֵλ��
						for(k=0;k<15;k++)
						{
							for(m=0;m<15;m++)
							{
								score=abs(m_statis.getScore(chess,k,m))>m_statis.m_iCpuScore[k][m]?abs(m_statis.getScore(chess,k,m)):m_statis.m_iCpuScore[k][m];
								if(chess[k][m]==0&&score>=max)
								{
									max=score;
									i=k;
									j=m;
								}
							}
						}


						step.x=i;
						step.y=j;
						m_stack.push(step);

						///////////////////////////////////////////////////
						//	����ǰ����λ��ת��������
						x=(int)(j*33.5+160);
						y=(int)(i*33.5+10);

						Draw(x,y,IDB_BITMAPBLACK,pDC);									//	��������
						chess[i][j] = 1;												//	������������
						


						//�˶δ������ڲ��Ը������Ƿ���ȷ
						/*CString cs;
						cs.Format("%d",m_statis.getScore(chess,i,j));
						MessageBox(cs,"����");*/

						///////////////////////////////////////////////////
						//	�жϼ�����Ƿ�ʤ��
						///////////////////////////////////////////////////
						if(m_statis.isWin(chess,i,j))
						{
							m_iTheEnd = 1;
							//	MessageBox("����Ӯ��","����");
							CEndDlg dlg;
							dlg.m_iIsWin=0;
							dlg.DoModal();
						}
						///////////////////////////////////////////////////
						///////////////////////////////////////////////////



					}// if(m_iPlayer==1)    END
				}// if(m_iNet==0||m_iSuccess==0)   END

//////////////////�˻���սģ��
//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////

			}//	if(chess[i][j] == 0)	END
		}
	}

	CDialog::OnLButtonDown(nFlags, point);
}

void CMainGameDlg::OnButexit() 
{
	// TODO: Add your control notification handler code here
	//exit(0);
	CDialog::OnCancel();
}


///////////////////////////////////////////////////
//	����Ϸ��ť�¼���Ӧ
///////////////////////////////////////////////////
void CMainGameDlg::OnButagain() 
{
	// TODO: Add your control notification handler code here

	//	��������ģʽ��Է��Ѿ�ͬ������Ϸ����ֱ�ӽ��в���
	if(!m_iSuccess||m_iNet==0||m_isAgreed)
	{
		m_iPlayer = 2;
		m_statis.Renew(chess);											//	�����̼�¼���
		m_stack.clear();
		m_iTheEnd=0;
		Invalidate(true);												//	ˢ�½���


		//	��Ϊ�Է�ͬ������Ϸ�����ж���¼ȡ��
		if(m_isAgreed)
		{
			m_isAgreed = !m_isAgreed;

			//	����ǰΪ�������ˣ�����ÿ���ͻ��˷��ͽ��в����������
			if(m_iNet==2)
			{
				//������ÿ���յ�һ����Ϣ�������������ÿһ���ͻ��˷��ͽ��յ�����Ϣ
				POSITION pPos = m_listClients.GetHeadPosition();
				m_listClients.GetNext(pPos);
				if(pPos)																//	����ǰ�ͻ��˷ǿ�
				{
					///////////////////////////////////////////////
					//	����ǰ������Ϣ���ӳ��ַ�����Ϣ
					///////////////////////////////////////////////
					CString send = "-~";
					CString cs;
					for(int i=0;i<15;i++)
					{
						for(int j = 0;j<15;j++)
						{
							cs.Format("%d",chess[i][j]);
							send = send + cs;
						}
					}
					///////////////////////////////////////////////
					///////////////////////////////////////////////


					///////////////////////////////////////////////
					//	ѭ���������еĿͻ��ˣ������䷢����Ϣ
					///////////////////////////////////////////////
					while(pPos)
					{
						CChatSocket* pCur = m_listClients.GetAt(pPos);
						//csMsgTo = "����Ա~" + m_strMSG;
						pCur->Send(send, send.GetLength());
						m_listClients.GetNext(pPos);
					}
					///////////////////////////////////////////////
					///////////////////////////////////////////////
				}
			}
		}
	}

	///////////////////////////////////////////////////
	//	����ǰ��������Ϊ������������в���
	///////////////////////////////////////////////////
	else if(m_iNet == 2)
	{
		POSITION pPos = m_listClients.GetHeadPosition();
			
		CChatSocket* pCur = m_listClients.GetAt(pPos);
		CString renew = "Renew~";
		pCur->Send(renew, renew.GetLength());
		
	}
	///////////////////////////////////////////////////
	///////////////////////////////////////////////////


	///////////////////////////////////////////////////
	//	����ǰ��������Ϊ�ͻ��ˣ�����в���
	///////////////////////////////////////////////////
	else if(m_iNet == 1)
	{
		CString renew = "Renew~";
		m_pSocket->Send(renew, renew.GetLength());
	}
	///////////////////////////////////////////////////
	///////////////////////////////////////////////////
}
///////////////////////////////////////////////////
///////////////////////////////////////////////////







///////////////////////////////////////////////////
//	������ֲ��Ű�ť�����¼���Ӧ
///////////////////////////////////////////////////
void CMainGameDlg::OnButmusic() 
{
	// TODO: Add your control notification handler code here
	if (m_iMusic == 0)
	{
		m_bmpbtnMusic.LoadBitmaps (IDB_BITMAPMUSICON,
			IDB_BITMAPMUSICON);
		mciSendString("play .\\res\\cjmlbj.mp3 repeat", NULL, 0, NULL);
		m_iMusic = 1;
		m_bmpbtnMusic.RedrawWindow ();
	}
	else
	{
		m_bmpbtnMusic.LoadBitmaps (IDB_BITMAPMUSICOFF,
			IDB_BITMAPMUSICOFF);
		mciSendString("close .\\res\\cjmlbj.mp3", NULL, 0, NULL);
		m_iMusic = 0;
		m_bmpbtnMusic.RedrawWindow ();
	}
	
}
///////////////////////////////////////////////////
///////////////////////////////////////////////////






///////////////////////////////////////////////////
//	������尴ť�����¼���Ӧ
///////////////////////////////////////////////////
void CMainGameDlg::OnButregret() 
{
	// TODO: Add your control notification handler code here
	CDC *pDC=GetDC();
	//m_Chip = m_Chip.reset();
	//m_Chip = m_Chip->Father;




	////////////////////////////////////////////////////////////////////////////////
	//	����ǰ�ѽ�����Ϸ��ջ�ڲ�������Ԫ�أ��򲻽��в���
	////////////////////////////////////////////////////////////////////////////////
	if(m_stack.getLength()<2||m_iTheEnd==1)
	{
		return ;
	}
	////////////////////////////////////////////////////////////////////////////////
	////////////////////////////////////////////////////////////////////////////////





	////////////////////////////////////////////////////////////////////////////////
	////////	����ǰ���Ӳ��ɹ���Է���ͬ����壬��ֱ�ӽ��в���
	////////////////////////////////////////////////////////////////////////////////
	if(!m_iSuccess||m_iNet==0||m_isAgreed)
	{

		//////////////////////////////////////////////////////////////////////////////
		//	��ջ��ȡ������Ԫ�أ�������λ�õ�������Ϣ���
		CPoint p = m_stack.pop();
		chess[p.x][p.y] = 0;
		p = m_stack.pop();
		chess[p.x][p.y] = 0;


		Draw(160,10,IDB_BITMAPBOARD,pDC);										//�ػ����̣���һ�������ǶԻ���x���꣬�ڶ���Ϊy����
		for(int i = 0;i<15;i++)
			for(int j = 0;j<15;j++)
			{																	//	�ػ�����
				if(chess[i][j]==2)
					Draw(j*33.5+160,i*33.5+10,IDB_BITMAPWHITE,pDC);
				else if(chess[i][j]==1)
					Draw(j*33.5+160,i*33.5+10,IDB_BITMAPBLACK,pDC);
			}
		//////////////////////////////////////////////////////////////////////////////
		//////////////////////////////////////////////////////////////////////////////




		///////////////////////////////////////
		//	��Ϊ�Է�ͬ����壬���ж���¼ȡ��
		if(m_isAgreed)
		{
			m_isAgreed = !m_isAgreed;
			if(m_iNet == 2)
			{
				//������ÿ���յ�һ����Ϣ�������������ÿһ���ͻ��˷��ͽ��յ�����Ϣ
				POSITION pPos = m_listClients.GetHeadPosition();
				m_listClients.GetNext(pPos);											//	��õ�ǰ�б��еĵڶ����ͻ�����Ϣ
				if(pPos)
				{
					////////////////////////////////////////////////////////////////
					//	�����л�����������Ϣ���ӳ��ַ���
					////////////////////////////////////////////////////////////////
					CString send = "-~";
					CString cs;
					for(int i=0;i<15;i++)
					{
						for(int j = 0;j<15;j++)
						{
							cs.Format("%d",chess[i][j]);
							send = send + cs;
						}
					}
					////////////////////////////////////////////////////////////////
					////////////////////////////////////////////////////////////////


					////////////////////////////////////////////////////////////////
					//	ѭ���������пͻ��ˣ������䷢�͵�ǰ������Ϣ
					////////////////////////////////////////////////////////////////
					while(pPos)
					{
						CChatSocket* pCur = m_listClients.GetAt(pPos);
						//csMsgTo = "����Ա~" + m_strMSG;
						pCur->Send(send, send.GetLength());
						m_listClients.GetNext(pPos);
					}
					////////////////////////////////////////////////////////////////
					////////////////////////////////////////////////////////////////

				}	//	if(pPos) END

			}	//	if(m_iNet == 2)	END

		}	//	if(m_isAgreed)	END

	}	//	if(!m_iSuccess||m_iNet==0||m_isAgreed)	END
	////////////////////////////////////////////////////////////////////////////////
	////////////////////////////////////////////////////////////////////////////////



	////////////////////////////////////////////////////////////////////////////////
	//	����ǰ��������Ϊ��������
	////////////////////////////////////////////////////////////////////////////////
	else if(m_iNet == 2)
	{
		POSITION pPos = m_listClients.GetHeadPosition();
			
		CChatSocket* pCur = m_listClients.GetAt(pPos);
		CString regret = "Regret~";
		pCur->Send(regret, regret.GetLength());	//	��ͻ��˷��ͻ�������
	}
	////////////////////////////////////////////////////////////////////////////////
	////////////////////////////////////////////////////////////////////////////////


	////////////////////////////////////////////////////////////////////////////////
	//	����ǰ��������Ϊ��������
	////////////////////////////////////////////////////////////////////////////////
	else if(m_iNet == 1)
	{
		CString regret = "Regret~";
		m_pSocket->Send(regret, regret.GetLength());								//	��������˷��ͻ�������
	}
	////////////////////////////////////////////////////////////////////////////////
	////////////////////////////////////////////////////////////////////////////////

	
}
//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////




//////////////////////////////////////////////////////////////////////////////
/////////���ڽ��տͻ�������Ѿ�������Ϸ����Ϣ
//////////////////////////////////////////////////////////////////////////////
void CMainGameDlg::ClientClose(CChatSocket *pChatSocket)
{
	POSITION pos = m_listClients.Find(pChatSocket);
	if(pos)
	{
		if(pos==m_listClients.GetHeadPosition())							//	�жϵ�ǰ�뿪��Ϸ�Ŀͻ����Ƿ�Ϊ���
		{
			m_iTheEnd = 1;													//	������Ϸ
			PlaySound("res\\system.wav", AfxGetInstanceHandle(), SND_FILENAME | SND_ASYNC | SND_NODEFAULT);
			MessageBox("�Է��Ѿ��뿪��Ϸ��","����");
			m_iSuccess = 0;
			//m_listClients.Remove(pos);
		}
		m_listClients.RemoveAt(pos);
		pChatSocket->Close();
		delete pChatSocket;
		pChatSocket = NULL;
	}
}
/////////���ڽ��տͻ�������Ѿ�������Ϸ����Ϣ
//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////




//////////////////////////////////////////////////////////////////////////////
/////////�ͻ��˽��ܷ���������Ϣ����
//////////////////////////////////////////////////////////////////////////////
void CMainGameDlg::RevMsg(CClientSocket *pSocket)
{
	// ������Ϣ
	char *pBuf = new char[50000];
	int iBufSize = 50000;

	CDC *pDC = GetDC();
	
	int iRes = m_pSocket->Receive(pBuf, iBufSize);								//	��һ���ַ�������շ��͹�������Ϣ
	if(iRes != SOCKET_ERROR)
	{
		pBuf[iRes] = NULL;
		
		UpdateData(TRUE);
		CString csMsgIN = pBuf;

		int nIndex = csMsgIN.Find("~");											//	��ȡ��ʾ��λ��
		CString csMsgTo = csMsgIN.Left(nIndex);
		CString csMsg = csMsgIN.Mid(nIndex + 1);

		//////////////////////////////////////////////////
		//	����ǰ��ϢΪ���ӳɹ���Ϣ
		//////////////////////////////////////////////////
		if(csMsgTo == "Login")
		{
			m_iSuccess = 1;														//	��������״̬
			PlaySound("res\\system.wav", AfxGetInstanceHandle(), SND_FILENAME | SND_ASYNC | SND_NODEFAULT);
			MessageBox("���ӳɹ�","�ɹ�");										//	��ʾ���ӳɹ�
			UpdateData(FALSE);

		}
		//////////////////////////////////////////////////
		//////////////////////////////////////////////////

		//////////////////////////////////////////////////
		//	����ǰ��ϢΪ��������
		//////////////////////////////////////////////////
		else if(csMsgTo == "Regret")
		{
			CPromptDlg dlg;
			dlg.m_iState = 1;
			PlaySound("res\\system.wav", AfxGetInstanceHandle(), SND_FILENAME | SND_ASYNC | SND_NODEFAULT);
			//dlg.m_csPrompt = "�Է�ϣ�����壬�Ƿ�ͬ�⣿";						//	������ʾ�Ի��򣬲���ȡ����ֵ
			int pos = dlg.DoModal();
			//	��ͬ����壬��ֱ�ӽ��в��������������������ͬ����Ϣ
			if(pos==IDOK)
			{
				CString accept = "Accept~";
				m_pSocket->Send(accept, accept.GetLength());
				m_isAgreed = true;
				OnButregret();
			}
			//	���ܾ����壬������������;ܾ���Ϣ
			else if(pos == IDCANCEL)
			{
				CString refuse = "Refuse~";
				m_pSocket->Send(refuse, refuse.GetLength());
			}
		}
		//////////////////////////////////////////////////
		//////////////////////////////////////////////////


		//////////////////////////////////////////////////
		//	����ǰ��ϢΪ����Ϸ������Ϣ
		//////////////////////////////////////////////////
		else if(csMsgTo == "Renew")
		{
			CPromptDlg dlg;
			dlg.m_iState = 2;
			PlaySound("res\\system.wav", AfxGetInstanceHandle(), SND_FILENAME | SND_ASYNC | SND_NODEFAULT);
			//dlg.m_csPrompt = "�Է�ϣ�����¿�ʼ��Ϸ���Ƿ�ͬ�⣿";						//	������ʾ�Ի��򣬲���ȡ����ֵ
			int pos = dlg.DoModal();
			//	��ѡ��ͬ�⣬��ֱ�ӽ��в��������Կͻ��˷���ͬ����Ϣ
			if(pos==IDOK)
			{
				CString accept = "AcceptRenew~";
				m_pSocket->Send(accept, accept.GetLength());
				m_isAgreed = true;
				OnButagain();
			}
			//	��ѡ��ܾ���������������;ܾ���Ϣ
			else if(pos == IDCANCEL)
			{
				
				CString refuse = "RefuseRenew~";
				m_pSocket->Send(refuse, refuse.GetLength());
			}
		}
		//////////////////////////////////////////////////
		//////////////////////////////////////////////////


		//////////////////////////////////////////////////
		//	��Ϊͬ�������Ϣ������л������
		//////////////////////////////////////////////////
		else if(csMsgTo == "Accept")
		{
			m_isAgreed = true;
			OnButregret();
		}
		//////////////////////////////////////////////////
		//////////////////////////////////////////////////


		//////////////////////////////////////////////////
		//	��Ϊͬ������Ϸ��Ϣ�����������Ϸ����
		//////////////////////////////////////////////////
		else if(csMsgTo == "AcceptRenew")
		{
			m_isAgreed = true;
			OnButagain();
		}
		//////////////////////////////////////////////////
		//////////////////////////////////////////////////


		//////////////////////////////////////////////////
		//	��Ϊ�ܾ�������Ϣ���򵯳���ʾ��
		//////////////////////////////////////////////////
		else if(csMsgTo == "Refuse")
		{
			PlaySound("res\\system.wav", AfxGetInstanceHandle(), SND_FILENAME | SND_ASYNC | SND_NODEFAULT);
			MessageBox("�Է��ܾ����壡","��ʾ");
		}
		//////////////////////////////////////////////////
		//////////////////////////////////////////////////


		//////////////////////////////////////////////////
		//	��Ϊ�ܾ�����Ϸ��Ϣ���򵯳���ʾ��
		//////////////////////////////////////////////////
		else if(csMsgTo == "RefuseRenew")
		{
			PlaySound("res\\system.wav", AfxGetInstanceHandle(), SND_FILENAME | SND_ASYNC | SND_NODEFAULT);
			MessageBox("�Է��ܾ����¿�ʼ��Ϸ��","��ʾ");
		}
		//////////////////////////////////////////////////
		//////////////////////////////////////////////////


		//////////////////////////////////////////////////
		//	�����͵�Ϊ��ǰ��������
		//////////////////////////////////////////////////
		else if(csMsgTo.GetAt(0)<='9'&&csMsgTo.GetAt(0)>='0')
		{
			//	����������Ϣ
			step.x=_ttoi(csMsgTo);
			step.y=_ttoi(csMsg);
			
			m_stack.push(step);													//	��������Ϣ��ջ
			Draw(step.y*33.5+160,step.x*33.5+10,IDB_BITMAPWHITE,pDC);			//	��������Ӧλ�û�������
			chess[step.x][step.y] = 2;											//	���ĵ�ǰ����λ�õ�״̬
			m_iPlayer = 1;														//	��������

			////////////////////////////////////////////////////
			//	�жϵ�ǰ�����Ƿ��ʤ
			////////////////////////////////////////////////////
			if(m_statis.isWin(chess,step.x,step.y))
			{
				//	����ǰΪ��ҿͻ��ˣ��򵯳�ʧ�ܴ�����ʾ
				if(m_iNet == 2)
				{
					m_iTheEnd = 1;
					CEndDlg dlg;
					dlg.m_iIsWin=0;
					dlg.DoModal();
				}
				//	����ǰΪ��ս�ͻ��ˣ�����ʾ��ʤ��
				else if(m_iNet == 3)
				{
					PlaySound("res\\system.wav", AfxGetInstanceHandle(), SND_FILENAME | SND_ASYNC | SND_NODEFAULT);
					if(chess[step.x][step.y]==1)
						MessageBox("����ʤ��","��ʾ");
					else if(chess[step.x][step.y]==2)
						MessageBox("����ʤ��","��ʾ");
				}
			}
		}
		//////////////////////////////////////////////////
		//////////////////////////////////////////////////


		//////////////////////////////////////////////////
		//	�����͵�Ϊ������Ϣ
		//////////////////////////////////////////////////
		else if(csMsgTo.GetAt(0)=='-')
		{
			//	��Ϊ��ս�߿ͻ��˵����ӳɹ���ʾ�������״̬Ϊ����ս�ߡ�
			if(csMsgTo=="--")
			{
				m_iNet = 3;
				m_iSuccess = 1;
				SetWindowText(" ������--��ս�ͻ��� ");
				PlaySound("res\\system.wav", AfxGetInstanceHandle(), SND_FILENAME | SND_ASYNC | SND_NODEFAULT);
				MessageBox("���ӳɹ�","�ɹ�");
			}
			CDC *pDC=GetDC();

			//	�������̣����ڸ���֮ǰ��������Ϣ
			Draw(160,10,IDB_BITMAPBOARD,pDC);

			
			int count = 0;				//	��¼��ǰ���������ַ���λ��


			//	��������ַ���������������״̬������������
			for(int i = 0;i<15;i++)
			{
				for(int j = 0;j<15;j++)
				{
					chess[i][j] = csMsg.GetAt(count++) - '0';
					if(chess[i][j]==2)
						Draw(j*33.5+160,i*33.5+10,IDB_BITMAPWHITE,pDC);
					else if(chess[i][j]==1)
						Draw(j*33.5+160,i*33.5+10,IDB_BITMAPBLACK,pDC);
				}
			}


		}
		//////////////////////////////////////////////////
		//////////////////////////////////////////////////


		//////////////////////////////////////////////////
		//	�����յ�Ϊ������Ϣ
		//////////////////////////////////////////////////
		else
		{
			UpdateData(true);										//	�����������Ϣ
			//	����������Ϣ
			CString csName = csMsgTo;
			CString msg = csMsg;
			m_csMSG = csMsgTo + "˵: " + csMsg;
			int nLen=m_csALLMSG.GetLength(); // ��ȡ���ݵĳ���
			m_edALLMSG.SetFocus ();  // �ú�����ָ���Ĵ������ü��̽��㡣�ô��ڱ���������̵߳���Ϣ������ء�
			m_edALLMSG.SetSel(nLen, nLen);  // ʹ�ı���Ĺ������Զ����ı����
			m_edALLMSG.ReplaceSel(m_csMSG);
			UpdateData(true);
			PlaySound("res\\msn.wav", AfxGetInstanceHandle(), SND_FILENAME | SND_ASYNC | SND_NODEFAULT);
		}
		//////////////////////////////////////////////////
		//////////////////////////////////////////////////

		delete pBuf;
		pBuf = NULL;
	}
}
/////////�ͻ��˽��ܷ���������Ϣ����
//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////








//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////
/////////���ڽ��տͻ��˵�������Ϣ����������뵽Socket�б���
void CMainGameDlg::GetMSG()
{
	CChatSocket* pSocket = new CChatSocket(this);

	if(!m_pSrvSocket->Accept(*pSocket))
	{
		PlaySound("res\\system.wav", AfxGetInstanceHandle(), SND_FILENAME | SND_ASYNC | SND_NODEFAULT);
		MessageBox("���ӿͻ���ʧ��!");
	}
	else
	{
		m_listClients.AddTail(pSocket);// ���Ͻ����µ�
	}
}
/////////���ڽ��տͻ��˵�������Ϣ����������뵽Socket�б���
//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////




//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////
////////�������˽��տͻ�����Ϣ����
void CMainGameDlg::RevMsg(CChatSocket *pChatSocket)
{
	char *pBuf = new char[50000];
	int iBufSize = 50000;
	
	CDC *pDC=GetDC();													//	��ȡ��ǰ�豸

	int iRes = pChatSocket->Receive(pBuf, iBufSize);					//	������Ϣ
	if(iRes != SOCKET_ERROR)
	{
		pBuf[iRes] = NULL;
		
		UpdateData(TRUE);
		CString csMsgIN = pBuf;

		int nIndex = csMsgIN.Find("~");									//	��ȡ��ʾ��λ��
		CString csMsgTo = csMsgIN.Left(nIndex);							//	�������յ�����Ϣ
		CString csMsg = csMsgIN.Mid(nIndex + 1);
		
		//////////////////////////////////////////////////////////////
		//	�����������ӳɹ�������ͻ��˷���һ�����ӳɹ���ʾ��Ϣ
		//////////////////////////////////////////////////////////////
		if(csMsgTo == "Login")
		{
			//////////////////////////////////////////////////////////////
			//	�����һ�����ӽ����Ŀͻ��˷���һ�����ӳɹ�����Ϣ
			//////////////////////////////////////////////////////////////
			POSITION pPos = m_listClients.GetTailPosition();
			CChatSocket* pCur = m_listClients.GetAt(pPos);

			/////////////////////////////////////////////////////////////////
			//	����ǰ�������б���ֻ��һ�������������������ʾ���ӳɹ�����
			/////////////////////////////////////////////////////////////////
			if(m_listClients.GetCount()==1)
			{
				CString csLogin = "Login~";
				pCur->Send(csLogin, csLogin.GetLength());							//	��ͻ��˷������ӳɹ���Ϣ
				m_iSuccess = 1;
				PlaySound("res\\system.wav", AfxGetInstanceHandle(), SND_FILENAME | SND_ASYNC | SND_NODEFAULT);
				MessageBox("���ӳɹ�","�ɹ�");

				//	��������
				m_isAgreed = true;
				OnButagain();
			}
			/////////////////////////////////////////////////////////////////
			/////////////////////////////////////////////////////////////////


			/////////////////////////////////////////////////////////////////
			//	����ǰ���ӵ�Ϊ��ս���������䷢��������Ϣ
			/////////////////////////////////////////////////////////////////
			else
			{
				//	��������Ϣ���ӳ�һ���ַ���
				CString send = "--~";
				CString cs;
				AfxSocketInit();
				for(int i=0;i<15;i++)
				{
					for(int j = 0;j<15;j++)
					{
						cs.Format("%d",chess[i][j]);
						send = send + cs;
					}
				}
				pCur->Send(send, send.GetLength());
			}
			/////////////////////////////////////////////////////////////////
			/////////////////////////////////////////////////////////////////
			UpdateData(FALSE);
		}
		/////////////////////////////////////////////////////////////////
		//	�����յ���Ϊ��������
		/////////////////////////////////////////////////////////////////
		else if(csMsgTo == "Regret")
		{
			CPromptDlg dlg;
			dlg.m_iState = 1;
			//dlg.m_csPrompt = "�Է�ϣ�����壬�Ƿ�ͬ�⣿";
			PlaySound("res\\system.wav", AfxGetInstanceHandle(), SND_FILENAME | SND_ASYNC | SND_NODEFAULT);
			int pos = dlg.DoModal();
			POSITION pPos = m_listClients.GetHeadPosition();
			CChatSocket* pCur = m_listClients.GetAt(pPos);

			//	��ѡ��Ϊͬ�⣬��ֱ�ӽ��в���������ͻ��˷���ͬ����Ϣ
			if(pos==IDOK)
			{
				CString accept = "Accept~";
				pCur->Send(accept, accept.GetLength());
				m_isAgreed = true;
				OnButregret();
			}
			//	��ѡ��Ϊ�ܾ�������ͻ��˷��;ܾ���Ϣ
			else if(pos == IDCANCEL)
			{
				
				CString refuse = "Refuse~";
				pCur->Send(refuse, refuse.GetLength());
			}
		}
		//////////////////////////////////////////////////////////////////
		//////////////////////////////////////////////////////////////////


		//////////////////////////////////////////////////////////////////
		//	�����յ���Ϊ����Ϸ����
		//////////////////////////////////////////////////////////////////
		else if(csMsgTo == "Renew")
		{
			CPromptDlg dlg;
			dlg.m_iState = 2;
			//dlg.m_csPrompt = "�Է�ϣ�����¿�ʼ��Ϸ���Ƿ�ͬ�⣿";
			PlaySound("res\\system.wav", AfxGetInstanceHandle(), SND_FILENAME | SND_ASYNC | SND_NODEFAULT);
			int pos = dlg.DoModal();
			POSITION pPos = m_listClients.GetHeadPosition();
			CChatSocket* pCur = m_listClients.GetAt(pPos);
			//	��ѡ��ͬ�⣬��ֱ�ӽ�������Ϸ����������ͻ��˷���ͬ����Ϣ
			if(pos==IDOK)
			{
				CString accept = "AcceptRenew~";
				pCur->Send(accept, accept.GetLength());
				m_isAgreed = true;
				OnButagain();
			}
			//	��ѡ��ܾ�������ͻ��˷��;ܾ���Ϣ
			else if(pos == IDCANCEL)
			{
				CString refuse = "RefuseRenew~";
				pCur->Send(refuse, refuse.GetLength());
			}
		}
		//////////////////////////////////////////////////////////////////
		//////////////////////////////////////////////////////////////////

		//////////////////////////////////////////////////////////////////
		//	�����յ�Ϊͬ�������Ϣ������л������
		//////////////////////////////////////////////////////////////////
		else if(csMsgTo == "Accept")
		{
			m_isAgreed = true;
			OnButregret();
		}
		//////////////////////////////////////////////////////////////////
		//////////////////////////////////////////////////////////////////

		//////////////////////////////////////////////////////////////////
		//	�����յ�Ϊͬ������Ϸ��Ϣ����ֱ�ӽ�������Ϸ����
		//////////////////////////////////////////////////////////////////
		else if(csMsgTo == "AcceptRenew")
		{
			m_isAgreed = true;
			OnButagain();
		}
		//////////////////////////////////////////////////////////////////
		//////////////////////////////////////////////////////////////////

		//////////////////////////////////////////////////////////////////
		//	�����յ�Ϊ�ܾ�������Ϣ���򵯳���ʾ��
		//////////////////////////////////////////////////////////////////
		else if(csMsgTo == "Refuse")
		{
			PlaySound("res\\system.wav", AfxGetInstanceHandle(), SND_FILENAME | SND_ASYNC | SND_NODEFAULT);
			MessageBox("�Է��ܾ����壡","��ʾ");
		}
		//////////////////////////////////////////////////////////////////
		//////////////////////////////////////////////////////////////////

		//////////////////////////////////////////////////////////////////
		//	�����յ�Ϊ�ܾ�����Ϸ��Ϣ���򵯳���ʾ��
		//////////////////////////////////////////////////////////////////
		else if(csMsgTo == "RefuseRenew")
		{
			PlaySound("res\\system.wav", AfxGetInstanceHandle(), SND_FILENAME | SND_ASYNC | SND_NODEFAULT);
			MessageBox("�Է��ܾ����¿�ʼ��Ϸ��","��ʾ");
		}
		//////////////////////////////////////////////////////////////////
		//////////////////////////////////////////////////////////////////



		//////////////////////////////////////////////////////////////////
		//	�����յ�Ϊ��ǰ������Ϣ
		//////////////////////////////////////////////////////////////////
		else if(csMsgTo.GetAt(0)<='9'&&csMsgTo.GetAt(0)>='0')
		{
			//	������ǰ������Ϣ����������ջ
			step.x=_ttoi(csMsgTo);
			step.y=_ttoi(csMsg);
			m_stack.push(step);

			//	�������ӣ����ı䵱ǰ����λ������״̬
			Draw(step.y*33.5+160,step.x*33.5+10,IDB_BITMAPBLACK,pDC);
			chess[step.x][step.y] = 1;

			m_iPlayer = 2;													//	��������

			//������ÿ���յ�һ����Ϣ�������������ÿһ���ͻ��˷��ͽ��յ�����Ϣ
			POSITION pPos = m_listClients.GetHeadPosition();
			m_listClients.GetNext(pPos);
			if(pPos)
			{
				CString send = "-~";
				CString cs;
				for(int i=0;i<15;i++)
				{
					for(int j = 0;j<15;j++)
					{
						cs.Format("%d",chess[i][j]);
						send = send + cs;
					}
				}
				/*CString x = "";
				CString cs = "";
				cs.Format("%d",step.x);
				x = x + cs;
				cs.Format("%d",step.y);
				x = x+"~"+cs;*/
				while(pPos)
				{
					CChatSocket* pCur = m_listClients.GetAt(pPos);
					//csMsgTo = "����Ա~" + m_strMSG;
					pCur->Send(send, send.GetLength());
					
					m_listClients.GetNext(pPos);
				}
			}
			if(m_statis.isWin(chess,step.x,step.y))
			{
				m_iTheEnd = 1;
				CEndDlg dlg;
				dlg.m_iIsWin=0;
				dlg.DoModal();
			}
		}
		//////////////////////////////////////////////////////////////////
		//////////////////////////////////////////////////////////////////

		//////////////////////////////////////////////////////////////////
		//	�����յ�Ϊ������Ϣ
		//////////////////////////////////////////////////////////////////
		else
		{
			UpdateData(true);
			CString csName = csMsgTo;
			CString msg = csMsg;
			m_csMSG = csMsgTo + "˵: " + csMsg;
			int nLen=m_csALLMSG.GetLength(); // ��ȡ���ݵĳ���
			m_edALLMSG.SetFocus ();  // �ú�����ָ���Ĵ������ü��̽��㡣�ô��ڱ���������̵߳���Ϣ������ء�
			m_edALLMSG.SetSel(nLen, nLen);  // ʹ�ı���Ĺ������Զ����ı����
			m_edALLMSG.ReplaceSel(m_csMSG);
			UpdateData(true);
			PlaySound("res\\msn.wav", AfxGetInstanceHandle(), SND_FILENAME | SND_ASYNC | SND_NODEFAULT);//������Ϣ��Ч
	
			POSITION pPos = m_listClients.GetHeadPosition();
			
			//m_listClients.GetNext(pPos);
			while(pPos)
			{
				CChatSocket* pCur = m_listClients.GetAt(pPos);
				if(pCur==pChatSocket)
				{
					m_listClients.GetNext(pPos);
					continue;
				}
				msg = csMsgTo + "~" + csMsg;
				//csMsgTo = "����Ա~" + m_strMSG;
				pCur->Send(msg, msg.GetLength());
				m_listClients.GetNext(pPos);
			}
		}
		//////////////////////////////////////////////////////////////////
		//////////////////////////////////////////////////////////////////

		delete pBuf;
		pBuf = NULL;
	}
}
////////�������˽��տͻ�����Ϣ����
//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////






//////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////
//////��������λͼ
void CMainGameDlg::Draw(int x, int y, UINT bitmap, CDC *pDC)
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
//////��������λͼ
//////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////


//////////////////////////////////////////////////////////////////////////////////
//	������Ͱ�ť��ʱ����Ӧ����
//////////////////////////////////////////////////////////////////////////////////
void CMainGameDlg::OnButtonSend() 
{
	// TODO: Add your control notification handler code here
	UpdateData(true);
	if(m_iSuccess&&m_csMSG!="")
	{
		CString cst = "��˵:"+m_csMSG + "\r\n";
		//m_csMSG = "��˵:"+m_csMSG + "\r\n";
		int nLen=m_csALLMSG.GetLength(); // ��ȡ���ݵĳ���
		m_edALLMSG.SetFocus ();  // �ú�����ָ���Ĵ������ü��̽��㡣�ô��ڱ���������̵߳���Ϣ������ء�
		m_edALLMSG.SetSel(nLen, nLen);  // ʹ�ı���Ĺ������Զ����ı����
		m_edALLMSG.ReplaceSel(cst);
		//UpdateData(false);
		//CString msg = m_csMSG;
		//m_csMSG = "";
		//UpdateData(false);
		CString news;
		if(m_iNet==3)
			news = m_csName + "(��ս��)~" + m_csMSG + "\r\n";
		else
			news = m_csName + "~" + m_csMSG + "\r\n";
		
		if(m_iNet==1||m_iNet==3)
		{
			m_pSocket->Send(news, news.GetLength());
		}
		else
		{
			POSITION pPos = m_listClients.GetHeadPosition();
			while(pPos)
			{
				CChatSocket* pCur = m_listClients.GetAt(pPos);
				CString csMsgTo = "����Ա~" + m_csMSG + "\r\n";
				pCur->Send(csMsgTo, csMsgTo.GetLength());
				m_listClients.GetNext(pPos);
			}
		}
		UpdateData(true);
		m_csMSG = "";
		UpdateData(false);
		UpdateData(true);
	}
}
//////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////

HBRUSH CMainGameDlg::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor) 
{
	HBRUSH hbr = CDialog::OnCtlColor(pDC, pWnd, nCtlColor);
     // TODO:  m_editMinute �� m_editYear ��Ӧ�ڿؼ�EditBox
/**     if( pWnd->GetSafeHwnd() == m_editMinute.GetSafeHwnd() ||
         pWnd->GetSafeHwnd() == m_editYear.GetSafeHwnd() )
     {*/
         //������ɫ��Ϊ��ɫ
         static HBRUSH   hbrEdit = ::CreateSolidBrush( RGB(217,239,248) );
         pDC->SetBkMode( TRANSPARENT );
         return hbrEdit;
  //   }
     // TODO:
     return hbr;
}

BOOL CMainGameDlg::PreTranslateMessage(MSG* pMsg) 
{
	// TODO: Add your specialized code here and/or call the base class
	if (WM_KEYFIRST <= pMsg->message && pMsg->message <= WM_KEYLAST)
	{
		//�ж��Ƿ��¼���Enter��
		if(pMsg->wParam==VK_RETURN)
		{
			//Do anything what you want to
			OnButtonSend();
			return TRUE;
		}
		//else return FALSE;
	}
	return CDialog::PreTranslateMessage(pMsg);
}

void CMainGameDlg::OnCancel() 
{
	// TODO: Add your control notification handler code here
	exit(0);
}
