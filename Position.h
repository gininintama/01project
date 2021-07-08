#pragma once
/**
 * @brief 坐标类
 * @member m_nX:     当前的棋盘位置x坐标,表示棋盘格子区域的整数，0-
 * @member m_nY:     当前的棋盘位置y坐标
 * @
*/

class Position {
private:
	int m_nX;
	int m_nY;
public:
	Position(int x = 0, int y = 0); //默认初始位置为（0,0)
	Position(const Position & pos); //拷贝构造函数
	~Position();
	void setX(int x);  //设置x坐标
	void setY(int y);  //设置y坐标
	int getX();  //获取x坐标
	int getY();  //获取y坐标
};