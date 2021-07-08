#pragma once
#include "../Position.h"
/**
 * @brief 棋子model类
 * @member m_nCamp: 棋子阵营
 * @member m_nType: 棋子类型
 * @member m_nStrength: 棋子战斗力
 * @member m_pPos: 指向棋子坐标类的指针，该坐标表示棋子在棋盘中的位置
*/
class Position;  //坐标类前置声明

class CheckerModel
{
private:
	int m_nCamp;
	int m_nType;
	int m_nStrength;
	Position m_cPos;
public:
	void setCamp(int Camp);
	void setType(int Typewidth);
	void setStrength(int Strength);
	int getCamp();
	int getType();
	int getStrength();
	void setCurPos(int x, int y);  //设置棋子当前的坐标
	CheckerModel();
	explicit CheckerModel(int Camp, int Type, int Strength);
	CheckerModel(const CheckerModel& p);
};