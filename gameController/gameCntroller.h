#pragma once
#include "../Position.h"
#include "../gameModel/ChessPiecesModel.h"
class CheckerModel;
class Position;
class ChessPiecesModel;
//extern ChessBoard;  //棋盘类，包含了存储全局地图信息的二维数组m_aPieces[7][9]
/**
 * @brief controller类:  游戏控制逻辑部分的实现
*/

/**
 * @brief Pos:  表示坐标位置的结构体
*/

/**
 * @brief readyEat : 判断棋子是否可以吃
 * @prama sourcePos: 棋子起始位置（x,y) 
 * @prama desPos:    棋子目的位置（x,y)
 * @reutrn bool:     true：可以吃， false：不可以吃
*/
bool readyEat(Position curPos, Position desPos);


/**
 * @brief readyMove : 判断棋子可以移动的位置
 * @prama curPiece:     棋子当前格子（x,y)
 * @prama desPiece:     棋子目的格子（x,y)
 * @prama checkerType:棋子类型，确定棋子的移动方式，不可更改
 * @prama len:        棋子移动的距离长度，确定移动路径上没有障碍
 * @return Pos* ：    返回一个结构体指针，指向可以移动的位置序列
*/
Position* readyMove(Position curPos);
    // 目的地没有棋子 || 有敌方棋子 readyEat  true
    //if Board[desPos.x][] == land  && len = 1  移动
    //                     == 河流   && 鼠  len = 1 移动
    //                     == 河流    && 狮虎 跳 len = 河流长度  && 敌方老鼠在视图层
    //                     == 兽穴   && 阵营   敌方 游戏结束 
    //                     == 陷阱   交给玩家
    //    新的参考思路
    //reayMove 只返回棋子对应的可以的地点，
    //             不对是否发生吃子等行为进行判断，不对目的地进行判断
    //    根据棋子类型，调用相应的判断函数。棋子枚举类型见common.h
    //        总体上可以分为三类：
    //           普通棋子（在陆地上移动一格）， 鼠（无视地形）， 狮虎（跳跃）
    /*switch (checker.m_nType)
    {
    case:  ...  //调用相应棋子的移动判断
    case:  ...
    default:
        break;
    }*/
int Move(Position curPos, Position desPos);
/*
    从(x,y)处移动到(toX,toY)，
        toX和toY的合法判断(不能超边界，不能移动到己方兽穴)
        如果有棋子 则用eat判断是否能吃
            如果不能吃 无法移动
            如果可以吃 对方玩家棋子-1 移动成功
        如果移动到兽穴 游戏结束
        如果没有棋子 移动成功

    返回值：
        0：正常移动
        1：移动失败
        2：吃了对方玩家一个棋子
        3：游戏结束
*/
/**
 * @brief Move :      移动棋子
 * @prama curPos:     棋子当前位置（x,y)
 * @prama desPos:     棋子目的位置（x,y)
 * @return int ：    
 *                    0：正常移动
 *                    1：移动失败
 *                    2：吃了对方玩家一个棋子
 *                    3：游戏结束
 */
// 判断移动的合法性，并对移动结果进行反馈，
// 这个函数与视图层有一个交互，表现在棋子河地形的重绘方面
// 参考思路：
//      if desPos in readyMovePos
//               then move to desPos
//      else failure move
//      if desPos isOccupied
//                then eat
/*
int Move(ChessPiecesModel curPiece, ChessPiecesModel desPiece);



//增加对棋子位置的判断
//是否在棋盘边界 ：边界指棋盘最外围的一圈棋盘格子的位置
//在边界： true  不在边界false
bool atBoundary(CheckerModel checker);

//是否在河边，在河边为ture ，河边指的是靠近河的四周格子的位置
bool byRiver(CheckerModel checker);

//是否在河里，在河里返回true
bool inRiver(CheckerModel checker);

//能否跳过河流,能跳过河流，则返回true
//如果棋子为虎，且在河边，水路上无对方老鼠，岸边无更强大生物，即可
//参考思路：
// 从当前棋子位置出发，往河对岸方向，遍历路径上的格子:
//                 如果在河中有对方老鼠存在，则返回false
//                 如果对岸有大象、狮子存在，则返回false
//                 否则，可以完成跳过河流从行为，返回true
bool canJump(CheckerModel checker);
*/