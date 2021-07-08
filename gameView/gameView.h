#pragma once
#include<graphics.h>
#include<conio.h>
#include<string>
//#include"../gameModel/PlayerModel.h"
//#include"../gameModel/CheckerModel.h"
//#include"../gameModel/ChessBoardModel.h"
//#include"../gameModel/ChessPiecesModel.h"
//#include"../gameModel/PlayerModel.h"
//#include"../common.h"
//#include"../gameController/gameCntroller.h"
/**
 * @brief initGame:
 *    初始化游戏：
 *       初始化游戏数据()
 *       接受玩家输入 生成两个玩家Play1.Camp
 *       打印界面
 */
void initGame();

/*
    

    // 阵营
    bool N = true;
    循环{
        N=!N;

    }
    游戏结束 打印积分
*/

/**
 * @brief playGame:
 *    游戏逻辑部分：         
 *       等待N阵营玩家选择棋子
 *       循环{
 *           判断这个棋子是否属于该玩家
 *           如果是：
 *               调用移动判断
 *               接受移动判断的返回值 并展示可以移动的位置
 *           如果玩家点击了可移动位置：
 *               棋子移动()
 *               根据移动后的返回值 进入对应的界面打印
 *               跳出本阵营的操作
 *           如果玩家点击了自己的其他棋子 continue;
 *       }
 */
void playGame();


/**
 * @brief gameOver:  
 *       游戏结束：
 *           显示对局结果。
 */
void gameOver();
void time_c(int swp);