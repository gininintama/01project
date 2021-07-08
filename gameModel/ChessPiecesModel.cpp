#include "ChessPiecesModel.h"
/**
 * @brief 棋盘格子model类
 * @member m_nHeight:     格子高度
 * @member m_nWidth:      格子宽度
 * @member m_bOccupied:   是否包含棋子
 * @member m_cCheker:     包含棋子的对象
 * @member m_nLandForm:   格子表示的地形：陆地、河、陷阱、兽穴
*/


//设置棋子高度
void ChessPiecesModel::setHeight(const int height) {
	m_nHeight = height;
}

//设置棋子宽度
void ChessPiecesModel::setWidth(const int width) {
	m_nWidth = width;
}

//获取棋子高度
int  ChessPiecesModel::getHeight() {
	return m_nHeight;
}

//获取棋子宽度
int  ChessPiecesModel::getWidth() {
	return m_nWidth;
}

//默认构造
ChessPiecesModel::ChessPiecesModel() {
}

//有参构造
ChessPiecesModel::ChessPiecesModel(int height, int width, bool occupied, CheckerModel cheker, int landForm) :
	m_nHeight(height), m_nWidth(width), 
	m_bOccupied(occupied), Cheker(cheker), m_nLandForm(landForm) {
}

//拷贝构造
ChessPiecesModel::ChessPiecesModel(const ChessPiecesModel& p) {
	m_nHeight = p.m_nHeight;
	m_nWidth = p.m_nWidth;
	m_bOccupied = p.m_bOccupied;
	m_nLandForm = p.m_nLandForm;
	Cheker = p.Cheker;
}

//析构函数
ChessPiecesModel::~ChessPiecesModel() {

}