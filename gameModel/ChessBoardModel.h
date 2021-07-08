#pragma once
#include "ChessPiecesModel.h"
/**
 * @brief ����model��
 * @member m_nHeight: ���̸߶�
 * @member m_nWidth: ���̿��
 * @member m_aPieces[h][w]: �������飬��ʾ��ͼ  {0} 
*/

class ChessBoardModel
{
private:
	int m_nHeight;
	int m_nWidth;
public:
	ChessPiecesModel m_aPieces[7][9];
	ChessBoardModel(int height = 490, int width = 630);
	
	~ChessBoardModel();

	void setHeight(int height);
	void setWidth(int width);
	int  getHeight();
	int  getWidth();
	void initBoard();  //��ʼ������Ĭ�����ݣ��������̶�Ӧ���ӵ����ݽ��г�ʼ��
	void initBoard(ChessPiecesModel** pieces);  //��ʼ����������[][]

	ChessBoardModel(const ChessBoardModel& p);

}; 