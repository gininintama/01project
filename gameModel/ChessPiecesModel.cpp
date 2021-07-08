#include "ChessPiecesModel.h"
/**
 * @brief ���̸���model��
 * @member m_nHeight:     ���Ӹ߶�
 * @member m_nWidth:      ���ӿ��
 * @member m_bOccupied:   �Ƿ��������
 * @member m_cCheker:     �������ӵĶ���
 * @member m_nLandForm:   ���ӱ�ʾ�ĵ��Σ�½�ء��ӡ����塢��Ѩ
*/


//�������Ӹ߶�
void ChessPiecesModel::setHeight(const int height) {
	m_nHeight = height;
}

//�������ӿ��
void ChessPiecesModel::setWidth(const int width) {
	m_nWidth = width;
}

//��ȡ���Ӹ߶�
int  ChessPiecesModel::getHeight() {
	return m_nHeight;
}

//��ȡ���ӿ��
int  ChessPiecesModel::getWidth() {
	return m_nWidth;
}

//Ĭ�Ϲ���
ChessPiecesModel::ChessPiecesModel() {
}

//�вι���
ChessPiecesModel::ChessPiecesModel(int height, int width, bool occupied, CheckerModel cheker, int landForm) :
	m_nHeight(height), m_nWidth(width), 
	m_bOccupied(occupied), Cheker(cheker), m_nLandForm(landForm) {
}

//��������
ChessPiecesModel::ChessPiecesModel(const ChessPiecesModel& p) {
	m_nHeight = p.m_nHeight;
	m_nWidth = p.m_nWidth;
	m_bOccupied = p.m_bOccupied;
	m_nLandForm = p.m_nLandForm;
	Cheker = p.Cheker;
}

//��������
ChessPiecesModel::~ChessPiecesModel() {

}