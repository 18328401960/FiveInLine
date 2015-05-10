// Statistics.h: interface for the CStatistics class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_STATISTICS_H__62132B36_80AC_4F6A_8467_E9244330EA0F__INCLUDED_)
#define AFX_STATISTICS_H__62132B36_80AC_4F6A_8467_E9244330EA0F__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CStatistics  
{
public:
	//int * getNext(int chess[15][15]);
	void Renew(int chess[15][15]);
	void Renew();
	int Min(int i,int j);														//�����������еĽ�Сֵ
	bool isWin(int chess[15][15],int i,int j);
	int m_iUserScore[15][15];
	int m_iCpuScore[15][15];
	int getScore(int chess[15][15],int i,int j);								//��ȡ��ǰλ�õķ���
	int m_iChess[15][15];														//�����������飬1Ϊ���壬2Ϊ����

	int Continuous(int num,int times,int color,int chess[15][15],int i,int j);	//���ҵ�ǰ����num��colorɫ������times�Σ�����ֵΪ���˲�Ϊ�յ�λ����С��

	//bool Continuous(int num,int times,int color,int chess[15][15],int i,int j,int direction[8]);//���ҵ�ǰ����num��colorɫ������times��


	int m_iCpuSum;
	int m_iUserSum;

	//double m_iTag;//ս��ѡ����
	CStatistics();
	virtual ~CStatistics();

private:
	//bool next(int direction,int chess[15][15],int i,int j,int color);//�жϸ÷����ϵ���һ��λ���Ƿ����
	int m_iFill;
};

#endif // !defined(AFX_STATISTICS_H__62132B36_80AC_4F6A_8467_E9244330EA0F__INCLUDED_)
