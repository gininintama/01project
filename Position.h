#pragma once
/**
 * @brief ������
 * @member m_nX:     ��ǰ������λ��x����,��ʾ���̸��������������0-
 * @member m_nY:     ��ǰ������λ��y����
 * @
*/

class Position {
private:
	int m_nX;
	int m_nY;
public:
	Position(int x = 0, int y = 0); //Ĭ�ϳ�ʼλ��Ϊ��0,0)
	Position(const Position & pos); //�������캯��
	~Position();
	void setX(int x);  //����x����
	void setY(int y);  //����y����
	int getX();  //��ȡx����
	int getY();  //��ȡy����
};