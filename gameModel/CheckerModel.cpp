#include"CheckerModel.h"
#include "../Position.h" 

/**
 * @brief 棋子model类
 * @member m_nCamp: 棋子阵营
 * @member m_nType: 棋子类型
 * @member m_nStrength: 棋子战斗力
*/

  
 
void CheckerModel::setCamp(int Camp) {
	m_nCamp = Camp;
}
void CheckerModel::setType(int Typewidth) {
	m_nType = Typewidth;
}
void CheckerModel::setStrength(int Strength) {
	m_nStrength = Strength;
}
int CheckerModel::getCamp() {
	return m_nCamp;
}
int CheckerModel::getType() {
	return m_nType;
}
int CheckerModel::getStrength() {
	return m_nStrength;
}
//设置棋子当前坐标位置
void CheckerModel::setCurPos(int x, int y)
{
	m_cPos.setX(x);
	m_cPos.setY(y);
}

	//默认构造
CheckerModel:: CheckerModel() {
}

CheckerModel::CheckerModel(int Camp, int Type, int Strength):
	m_nCamp(Camp), m_nType(Type), 
	m_nStrength(Strength) {
}

//拷贝构造
CheckerModel::CheckerModel(const CheckerModel& p) {
	m_nCamp = p.m_nCamp;
	m_nType = p.m_nType;
	m_nStrength = p.m_nStrength;
}
