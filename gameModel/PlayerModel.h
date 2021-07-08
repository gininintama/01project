#pragma once
#include <string>
/**
 * @brief 玩家model类
 * @member m_sName:     昵称
 * @member m_sProfileImg:    头像路径（相对路径，所有图片放在项目目录下pig文件夹中)
 * @member m_nCmap:   玩家阵营
 * @member m_nLeftCheckers:     剩余棋子数量
*/
using namespace std;

class PlayerModel
{
private:
	string m_sName;
	string m_sProfileImg;
	int m_nCmap;
	//int m_nLeftCheckers;		/*下移*/

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