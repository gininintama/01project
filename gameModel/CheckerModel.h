#pragma once
#include "../Position.h"
/**
 * @brief ����model��
 * @member m_nCamp: ������Ӫ
 * @member m_nType: ��������
 * @member m_nStrength: ����ս����
 * @member m_pPos: ָ�������������ָ�룬�������ʾ�����������е�λ��
*/
class Position;  //������ǰ������

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
	void setCurPos(int x, int y);  //�������ӵ�ǰ������
	CheckerModel();
	explicit CheckerModel(int Camp, int Type, int Strength);
	CheckerModel(const CheckerModel& p);
};