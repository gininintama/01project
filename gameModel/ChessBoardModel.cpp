#include "ChessBoardModel.h"
 
/**
 * @brief ����model��
 * @member m_nHeight: ���̸߶�
 * @member m_nWidth: ���̿��
 * @member m_aPieces[h][w]: �������飬��ʾ��ͼ
*/	 
/**
ChessBoardModel::ChessBoardModel() {
	for (int y = 0; y < 7; y++)
		for (int x = 0; x < 9; x++)
		{
			setfillcolor(YELLOW);
			solidrectangle(x * 70 + 40, y * 70 + 60, x * 70 + 105, y * 70 + 125);
		}   //���̸��� 70*70   7*9
}*/

//�������̸߶�
void  ChessBoardModel:: setHeight(int height) {
	m_nHeight = height;
}
//�������̿��
void  ChessBoardModel:: setWidth(int width) {
	m_nWidth = width;
};
//��ȡ���̸߶�
int  ChessBoardModel::getHeight() {
	return m_nHeight;
};
//��ȡ���̿��
int   ChessBoardModel:: getWidth() {
	return m_nWidth;
};

//�вι���
ChessBoardModel::ChessBoardModel(int height, int width) :
	m_nHeight(height), m_nWidth(width) {
}

void ChessBoardModel::initBoard() {       
	for (int i = 0; i < 7; i++) {
		for (int j = 0; j < 9; j++) {
			//m_aPieces[i][j];
		}
	}

}


void ChessBoardModel::initBoard(ChessPiecesModel** pieces) {
	for (int i = 0; i < 7; i++) {
		for (int j = 0; j < 9; j++) {
			//m_aPieces[i][j] = pieces[i][j];
		}
	}
		
}

//��������
ChessBoardModel::ChessBoardModel(const ChessBoardModel& p) {
	m_nHeight = p.m_nHeight;
	m_nWidth = p.m_nWidth;
	//������������
	//for (int i = 0; i < 7; i++) {
	//	for (int j = 0; j < 9; j++) {
	//		//m_aPieces[i][j] = p.m_aPieces[i][j];
	//	}
	//}

};

//��������
ChessBoardModel::~ChessBoardModel() {
};
		 
