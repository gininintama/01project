#pragma once
#include "ChessPiecesModel.h"
/**
 * @brief 棋盘model类
 * @member m_nHeight: 棋盘高度
 * @member m_nWidth: 棋盘宽度
 * @member m_aPieces[h][w]: 棋盘数组，表示地图  {0} 
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
	void initBoard();  //初始化棋盘默认数据，及对棋盘对应格子的数据进行初始化
	void initBoard(ChessPiecesModel** pieces);  //初始化棋盘数据[][]

	ChessBoardModel(const ChessBoardModel& p);

}; 