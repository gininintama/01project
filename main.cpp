#include <graphics.h>
#include <conio.h>
#include <easyx.h>
#include"gameView/gameView.h"
#include<stdio.h>
#include "gameModel/ChessBoardModel.h"
//全局的棋盘类实例
//含有当前棋盘的棋盘信息的地图数组 ChessPiecesModel m_aPieces[7][9];
// 数组内容说明： 包含了7*9个棋盘格子，可以通过棋盘格子的接口获取棋盘格子的信息
// 使用时声明 extern ChessBoardModel board;即可，或包含该头文件
ChessBoardModel board;

int main()
{
	initGame();
	playGame();
	getchar();//阻塞窗口
	closegraph();//关闭窗口
	return 0;

}