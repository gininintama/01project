#pragma once
#include "CheckerModel.h"
/**
 * @brief ���̸���model��
 * @member m_nHeight:     ���Ӹ߶�
 * @member m_nWidth:      ���ӿ��
 * @member m_bOccupied:   �Ƿ��������
 * @member m_cChekerKind:     �������ӵĶ���
 * @member m_nLandForm:   ���ӱ�ʾ�ĵ��Σ�½�ء��ӡ����塢��Ѩ
*/
class CheckerModel;  //����ģ�͵Ķ�������

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