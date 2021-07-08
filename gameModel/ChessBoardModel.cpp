#include "ChessBoardModel.h"
 
/**
 * @brief 棋盘model类
 * @member m_nHeight: 棋盘高度
 * @member m_nWidth: 棋盘宽度
 * @member m_aPieces[h][w]: 棋盘数组，表示地图
*/	 
/**
ChessBoardModel::ChessBoardModel() {
	for (int y = 0; y < 7; y++)
		for (int x = 0; x < 9; x++)
		{
			setfillcolor(YELLOW);
			solidrectangle(x * 70 + 40, y * 70 + 60, x * 70 + 105, y * 70 + 125);
		}   //棋盘格子 70*70   7*9
}*/

//设置棋盘高度
void  ChessBoardModel:: setHeight(int height) {
	m_nHeight = height;
}
//设置棋盘宽度
void  ChessBoardModel:: setWidth(int width) {
	m_nWidth = width;
};
//获取棋盘高度
int  ChessBoardModel::getHeight() {
	return m_nHeight;
};
//获取棋盘宽度
int   ChessBoardModel:: getWidth() {
	return m_nWidth;
};

//有参构造
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

//拷贝构造
ChessBoardModel::ChessBoardModel(const ChessBoardModel& p) {
	m_nHeight = p.m_nHeight;
	m_nWidth = p.m_nWidth;
	//拷贝棋盘数据
	//for (int i = 0; i < 7; i++) {
	//	for (int j = 0; j < 9; j++) {
	//		//m_aPieces[i][j] = p.m_aPieces[i][j];
	//	}
	//}

};

//析构函数
ChessBoardModel::~ChessBoardModel() {
};
		 
