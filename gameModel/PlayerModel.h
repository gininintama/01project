#pragma once
#include <string>
/**
 * @brief ���model��
 * @member m_sName:     �ǳ�
 * @member m_sProfileImg:    ͷ��·�������·��������ͼƬ������ĿĿ¼��pig�ļ�����)
 * @member m_nCmap:   �����Ӫ
 * @member m_nLeftCheckers:     ʣ����������
*/
using namespace std;

class PlayerModel
{
private:
	string m_sName;
	string m_sProfileImg;
	int m_nCmap;
	//int m_nLeftCheckers;		/*����*/

public:
	int m_nLeftCheckers;
	void setName(string name);
	void setProfile(string progile);
	string getName();
	string  getProfile();
	int getCmap();
	int getLeftCheckers();
	PlayerModel();
	PlayerModel(string name, string progile, int cmap, int leftCheckers);
	PlayerModel(const PlayerModel& p);
	~PlayerModel();
    //void creatPlayer(string name, string profile);

};