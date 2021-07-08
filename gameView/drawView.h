#pragma once

class CheckerModel;
class ChessPiecesModel;
class ChessBoardModel;
class PlayerModel;
int clickConunt(int x, int y, int* i, int* j);			/*计算鼠标转换数组*/

/**
 * @brief draw:       绘制棋子，根据绘制对象的属性进，绘制出相应的对象
 *
 * @prama T:          T为要绘制的目标对象
 */



class drawView
{
public:
	void draw(CheckerModel& checker, int x, int y);			/*显示指定一个棋子，x和y代表所在数组[x][y]的位置*/
	void draw(ChessPiecesModel& pieces, int x, int y);		/*显示指定一个棋盘块，x和y代表所在数组[x][y]的位置*/
	void draw(ChessBoardModel& board);						/*背景*/
	void draw(PlayerModel& player);						/*显示玩家头像和名称*/
	void initPieces();								/*初始化棋盘*/
	void initChess();								/*初始化棋子*/

};
/*draw()棋子移动后显示图片无坐标参数
ChessPiecesModel类
private:
	int m_nHeight;
	int m_nWidth;

public:
	bool m_bOccupied;
	int m_nChekerKind;
	int m_nLandForm;

	bool setHeight(int height);
	bool setWidth(int width);
	int  getHeight();
	int  getWidth();
	1.格子类只需初始化
draw（）调一次画一个格子/棋子？

ChessBoardModel 中的数组怎么访问

readyMove（）返回的结构体
返回一个结构体指针，指向可以移动的位置序列
Pos* readyMove(Pos curPos, const int& len, const int& checkerType);
返回的Pos*只有1对坐标，实际上可能0~4个坐标对

*/
