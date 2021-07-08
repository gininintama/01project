#include "PlayerModel.h"
/**
 * @brief 玩家model类
 * @member m_sName:     昵称
 * @member m_sProfileImg:    头像路径（相对路径，所有图片放在项目目录下pig文件夹中)
 * @member m_nCmap:   玩家阵营
 * @member m_nLeftCheckers:     剩余棋子数量
*/


//设置玩家昵称
void PlayerModel::setName(string name) {
	m_sName = name;
}

//设置头像路径
void PlayerModel::setProfile(string progile) {
	m_sProfileImg = progile;
}

//获取玩家昵称
string PlayerModel::getName() {
	return m_sName;
}

//获取头像的文件路径
string  PlayerModel::getProfile() {
	return m_sProfileImg;
}

//获取玩家阵营
int PlayerModel::getCmap() {
	return m_nCmap;
}

//获取剩余棋子个数
int PlayerModel::getLeftCheckers() {
	return m_nLeftCheckers;
}

////设置玩家昵称和图像相对路径
//PlayerModel creatPlayer(string name, string profile, PlayerModel P) {
//	return P;
//}

//默认构造函数
PlayerModel::PlayerModel() {

}

//有参构造函数
PlayerModel::PlayerModel(string name, string progile, int cmap, int leftCheckers) :
	m_sName(name), m_sProfileImg(progile),
	m_nCmap(cmap), m_nLeftCheckers(leftCheckers) {
}

//拷贝构造
PlayerModel::PlayerModel(const PlayerModel& p) {
	m_sName = p.m_sName;
	m_sProfileImg = p.m_sProfileImg;
	m_nCmap = p.m_nCmap;
	m_nLeftCheckers = p.m_nLeftCheckers;
}

//析构函数
PlayerModel::~PlayerModel() {
}