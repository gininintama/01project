#include "PlayerModel.h"
/**
 * @brief ���model��
 * @member m_sName:     �ǳ�
 * @member m_sProfileImg:    ͷ��·�������·��������ͼƬ������ĿĿ¼��pig�ļ�����)
 * @member m_nCmap:   �����Ӫ
 * @member m_nLeftCheckers:     ʣ����������
*/


//��������ǳ�
void PlayerModel::setName(string name) {
	m_sName = name;
}

//����ͷ��·��
void PlayerModel::setProfile(string progile) {
	m_sProfileImg = progile;
}

//��ȡ����ǳ�
string PlayerModel::getName() {
	return m_sName;
}

//��ȡͷ����ļ�·��
string  PlayerModel::getProfile() {
	return m_sProfileImg;
}

//��ȡ�����Ӫ
int PlayerModel::getCmap() {
	return m_nCmap;
}

//��ȡʣ�����Ӹ���
int PlayerModel::getLeftCheckers() {
	return m_nLeftCheckers;
}

////��������ǳƺ�ͼ�����·��
//PlayerModel creatPlayer(string name, string profile, PlayerModel P) {
//	return P;
//}

//Ĭ�Ϲ��캯��
PlayerModel::PlayerModel() {

}

//�вι��캯��
PlayerModel::PlayerModel(string name, string progile, int cmap, int leftCheckers) :
	m_sName(name), m_sProfileImg(progile),
	m_nCmap(cmap), m_nLeftCheckers(leftCheckers) {
}

//��������
PlayerModel::PlayerModel(const PlayerModel& p) {
	m_sName = p.m_sName;
	m_sProfileImg = p.m_sProfileImg;
	m_nCmap = p.m_nCmap;
	m_nLeftCheckers = p.m_nLeftCheckers;
}

//��������
PlayerModel::~PlayerModel() {
}