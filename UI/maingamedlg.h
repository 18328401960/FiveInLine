#if !defined(AFX_MAINGAMEDLG_H__8BF46AE4_B10C_4E2C_96F4_42F1F39D5387__INCLUDED_)
#define AFX_MAINGAMEDLG_H__8BF46AE4_B10C_4E2C_96F4_42F1F39D5387__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// MainGameDlg.h : header file
//
#include "ColorStatic.h"
#include "ColorBtn.h"
#include "..\Logic\Statistics.h"
#include "..\Data\Stack.h"
#include "..\Data\ClientSocket.h"
#include "..\Data\ChatSocket.h"
#include "..\Data\SrvSocket.h"
#include <afxtempl.h>
#include <afxsock.h>
/////////////////////////////////////////////////////////////////////////////
// CMainGameDlg dialog

class CMainGameDlg : public CDialog
{
// Construction
public:

////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////
////����
	CMainGameDlg(CWnd* pParent = NULL);   // standard constructor
	CBitmap	m_bmpBackGround;
	CBitmapButton m_bmpbtnMusic;
	CBitmapButton m_bmpbtnAgain;
	CBitmapButton m_bmpbtnRegret;
	CBitmapButton m_bmpbtnExit;
	CBitmapButton m_bmpbtnSend;
	CBitmapButton m_bmpbtnExitReal;

	CColorStatic	m_csAttribute;
////����
////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////


////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////
////����

	CString m_csName;										//	�ͻ����ǳ�
	bool m_isAgreed;										//	�Ƿ�ͬ���������¿�ʼ��Ϸ
	bool m_isSingle;										//	�Ƿ�Ϊ������Ϸ

	
	
	void RevMsg(CChatSocket *pChatSocket);					//	�������˽��տͻ�����Ϣ�ķ���
	void RevMsg(CClientSocket *pChatSocket);				//	�ͻ��˽��շ���������Ϣ�ķ���
	void GetMSG();											//	���ڽ����µĿͻ���
	int m_iSuccess;											//	�Ƿ����ӳɹ�					
	int	m_iMusic;											//  ��ʾ����״̬
	//void RevMsg(CSrvSocket *pChatSocket);

	CList<CChatSocket*, CChatSocket*> m_listClients;		//	�����������Socket���б�

	void ClientClose(CChatSocket *pChatSocket);				//	��ÿͻ��˹رյ���Ϣ
	CSrvSocket* m_pSrvSocket;								//	��������CSrvSocket�࣬���ڼ����ͻ���
	CChatSocket* m_Send;									//	��������Socket�࣬���ڷ�����Ϣ
	CClientSocket* m_pSocket;								//	�ͻ���Socket��
	
	CString m_csIPAddress;									//	�ͻ�����Ҫ���ӵķ���������IP��ַ
	int chess[15][15];										//	�����������飬1Ϊ���壬2Ϊ����
	int m_iPlayer;											//	���ֱ�ǣ�1Ϊ������ң�2Ϊ�������
	int m_iNet;												//	�������ӱ�ʾ����1��ʾΪ�ͻ��ˣ�2��ʾΪ��������
	void Draw(int x,int y,UINT bitmap,CDC *pDC);			//	��ͼ����
	CStatistics m_statis;									//	��װ���������˻���ս��Ҫ�õ����㷨
	//int chess[15][15];//�������̣�1Ϊ���壬2Ϊ����

	CStack m_stack;											//	����ÿһ�����ӵ�ջ�ṹ
	//Node step;
	CPoint step;											//	���浱ǰ���ӵ�λ��

	int m_iTheEnd;											//	�Ƿ���Ϸ����

////����
////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////



// Dialog Data
	//{{AFX_DATA(CMainGameDlg)
	enum { IDD = IDD_MAINGAME_DIALOG };
	CRichEditCtrl	m_edALLMSG;
	CString	m_csALLMSG;
	CString	m_csMSG;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMainGameDlg)
	public:
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	//void OnLButtonDown (UINT nFlags, CPoint point);
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CMainGameDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg void OnButexit();
	afx_msg void OnButagain();
	afx_msg void OnButmusic();
	afx_msg void OnButregret();
	afx_msg void OnButtonSend();
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	afx_msg void OnCancel();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MAINGAMEDLG_H__8BF46AE4_B10C_4E2C_96F4_42F1F39D5387__INCLUDED_)
