#include"CheckerModel.h"
#include "../Position.h" 

/**
 * @brief ����model��
 * @member m_nCamp: ������Ӫ
 * @member m_nType: ��������
 * @member m_nStrength: ����ս����
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
//�������ӵ�ǰ����λ��
void CheckerModel::setCurPos(int x, int y)
{
	m_cPos.setX(x);
	m_cPos.setY(y);
}

	//Ĭ�Ϲ���
CheckerModel:: CheckerModel() {
}

CheckerModel::CheckerModel(int Camp, int Type, int Strength):
	m_nCamp(Camp), m_nType(Type), 
	m_nStrength(Strength) {
}

//��������
CheckerModel::CheckerModel(const CheckerModel& p) {
	m_nCamp = p.m_nCamp;
	m_nType = p.m_nType;
	m_nStrength = p.m_nStrength;
}
