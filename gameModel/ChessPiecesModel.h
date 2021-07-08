#pragma once
#include "CheckerModel.h"
/**
 * @brief 棋盘格子model类
 * @member m_nHeight:     格子高度
 * @member m_nWidth:      格子宽度
 * @member m_bOccupied:   是否包含棋子
 * @member m_cChekerKind:     包含棋子的对象
 * @member m_nLandForm:   格子表示的地形：陆地、河、陷阱、兽穴
*/
class CheckerModel;  //棋子模型的对象声明

class ChessPiecesModel
{
private:
	int m_nHeight;
	int m_nWidth;
	
public:
	bool m_bOccupied;
	CheckerModel Cheker;
	int m_nLandForm;
	void setHeight(int height);
	void setWidth(int width);
	int  getHeight();
	int  getWidth();

	ChessPiecesModel();

	ChessPiecesModel(int height, int width, bool occupied, CheckerModel chekerKind, int landForm);

	ChessPiecesModel(const ChessPiecesModel& p);

	~ChessPiecesModel();
	
};