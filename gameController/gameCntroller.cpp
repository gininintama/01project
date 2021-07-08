#include<iostream>
#include"gameCntroller.h"
#include"../common.h"
#include"../gameModel/ChessPiecesModel.h"
#include"../gameModel/ChessBoardModel.h"
#include"../gameModel/CheckerModel.h"
using namespace std;
extern ChessBoardModel board;

/**
 * @brief readyEat : 判断棋子是否可以吃
 * @prama curPos :当前棋子位置（x,y)
 * @prama desPos :目标棋子位置（x,y)
 * @reutrn bool:     true：可以吃， false：不可以吃
*/
bool readyEat(Position curPos, Position desPos){
    ChessPiecesModel curPieces = board.m_aPieces[curPos.getX()][curPos.getY()];
    ChessPiecesModel desPieces = board.m_aPieces[desPos.getX()][desPos.getY()];
    int mycamp;//othercamp表示己方陷阱
    if (curPieces.Cheker.getCamp() == red)
        mycamp = RED_TRAP;
    else
        mycamp = BLUE_TRAP;
    //对方棋子在己方陷阱可以吃
    if (desPieces.m_nLandForm == mycamp)
        return true;
    else {
        //己方棋子战斗力高
        if (curPieces.Cheker.getStrength() > desPieces.Cheker.getStrength()) {
            //大象无法吃老鼠
            if (curPieces.Cheker.getType() == ELEPHANT && desPieces.Cheker.getType() == RAT)
                return false;
            else
                //其他可以吃（这里无须考虑鼠阻挡过河吃对岸的棋子，属于无法移动的情况）
                return true;
        }
        //双方棋子战斗力一致可以吃
        else if (curPieces.Cheker.getStrength() == desPieces.Cheker.getStrength())
            return true;
        //对方棋子战斗力高不能吃
        else {
            //老鼠单独讨论，在河里不能吃岸上
            if (curPieces.Cheker.getType() == RAT && desPieces.Cheker.getType() == ELEPHANT)
            {
                if (curPieces.m_nLandForm != RIVER)
                    return true;
                else
                    return false;
            }
            else
                return false;
        }
    }
}
/**
 * @brief readyMove : 判断棋子可以移动的位置
 * @prama curPos:     棋子当前位置（x,y)
 * @return Position* ：    返回一个结构体指针，指向可以移动的位置序列
*/
Position* readyMove(Position curPos) {
    ChessPiecesModel curPieces = board.m_aPieces[curPos.getX()][curPos.getY()];
    ChessPiecesModel tempPieces[4];//tempPieces保存所选棋子上下左右四个格子
    Position desPos[4];//desPos保存上下左右四个格子的坐标
    Position* resultPos=new Position[4];//resultPos保存返回的四个坐标
    //计算上下左右四个格子的坐标
    desPos[0].setX(curPos.getX() - 1); desPos[0].setY(curPos.getY());
    desPos[1].setX(curPos.getX() + 1); desPos[1].setY(curPos.getY());
    desPos[2].setX(curPos.getX()); desPos[2].setY(curPos.getY() - 1);
    desPos[3].setX(curPos.getX()); desPos[3].setY(curPos.getY() + 1);
    //把四个坐标对应的棋盘上的四个格子交给tempPieces暂存
    for (int i = 0; i < 4; i++) {
        tempPieces[i] = board.m_aPieces[desPos[i].getX()][desPos[i].getY()];
    }
    int mycamp;//mycamp表示我方兽穴
    if (curPieces.Cheker.getCamp() == red)
        mycamp = RED_DEN;
    else
        mycamp = BLUE_DEN;
    //分情况讨论：鼠、狮虎、其他
    //鼠
    if (curPieces.Cheker.getType() == RAT) {
        for (int i = 0; i < 4; i++) {
            //判断是否超边界
            if (desPos[i].getX() < 0 || desPos[i].getY() < 0)
            {
                Position invaluePos = { -1,-1 };
                resultPos[i] = invaluePos;
                continue;
            }
            else {
                //目标格子上有棋子
                if (tempPieces[i].m_bOccupied == true) {
                    //棋子为我方阵营，无法移动
                    if (tempPieces[i].Cheker.getCamp() == curPieces.Cheker.getCamp()) {
                        Position invaluePos = { -1,-1 };
                        resultPos[i] = invaluePos;
                        continue;
                    }
                    //棋子为对方阵营
                    else
                    {
                        //能吃，返回当前目的格子的坐标
                        if (readyEat(curPos, desPos[i]) == true)
                            resultPos[i] = desPos[i];
                        //不能吃，直接返回
                        continue;
                    }
                }
                //目标格子上无棋子
                else {
                    //非我方兽穴，返回当前目的格子的坐标
                    if (tempPieces[i].m_nLandForm != mycamp)
                    {
                        resultPos[i] = desPos[i];
                    }//移动到我方兽穴，无法移动
                    else{
                        Position invaluePos = { -1,-1 };
                        resultPos[i] = invaluePos;
                    }
                    continue;
                }
            }
        }
    }
    //狮虎
    else if (curPieces.Cheker.getType() == TIGER || curPieces.Cheker.getType() == LION) {
        for (int i = 0; i < 4; i++) {
            //判断是否超边界
            if (desPos[i].getX() < 0 || desPos[i].getY() < 0) {
                Position invaluePos = { -1,-1 };
                resultPos[i] = invaluePos;
                continue;
            }
            else {
                //移动到我方兽穴，无法移动
                if (tempPieces[i].m_nLandForm == mycamp) {
                    Position invaluePos = { -1,-1 };
                    resultPos[i] = invaluePos;
                    continue;
                }
                //非我方兽穴
                //该格子在河里，说明狮虎到了河边
                if (tempPieces[i].m_nLandForm == RIVER)
                {
                    int flag = 0; int j = 0;
                    switch (i)
                    {
                    case 0:
                        for (j = 0; j < 2; j++)
                        {
                            if (board.m_aPieces[desPos[i].getX() - j][desPos[i].getY()].m_bOccupied == true)
                                break;
                        }
                        //没有老鼠，可以跳河
                        if (j == 2)
                        {
                            //修改目的格子到河对岸
                            desPos[i].setX(desPos[i].getX() - 2);
                            tempPieces[i] = board.m_aPieces[desPos[i].getX()][desPos[i].getY()];
                        }
                        //有老鼠，无法跳河，返回一个无效坐标
                        else
                            flag = 1;
                        break;
                    case 1:
                        for (j = 0; j < 2; j++)
                        {
                            if (board.m_aPieces[desPos[i].getX() + j][desPos[i].getY()].m_bOccupied == true)
                                break;
                        }
                        //没有老鼠，可以跳河
                        if (j == 2)
                        {
                            //修改目的格子到河对岸
                            desPos[i].setX(desPos[i].getX() + 2);
                            tempPieces[i] = board.m_aPieces[desPos[i].getX()][desPos[i].getY()];
                        }
                        //有老鼠，无法跳河，返回一个无效坐标
                        else
                            flag = 1;
                        break;
                    case 2://2对应当前棋子的左侧格子，只能往左跳
                        //判断左侧的河道中有无老鼠
                        for (j = 0; j < 3; j++)
                        {
                            if (board.m_aPieces[desPos[i].getX()][desPos[i].getY() - j].m_bOccupied == true)
                                break;
                        }
                        //没有老鼠，可以跳河
                        if (j == 3)
                        {
                            //修改目的格子到河对岸
                            desPos[i].setY(desPos[i].getY() - 3);
                            tempPieces[i] = board.m_aPieces[desPos[i].getX()][desPos[i].getY()];
                        }
                        //有老鼠，无法跳河，返回一个无效坐标
                        else
                            flag = 1;
                        break;
                    case 3://3对应当前棋子的右侧格子，只能往右跳
                        //判断右侧的河道中有无老鼠
                        for (j = 0; j < 3; j++)
                        {
                            if (board.m_aPieces[desPos[i].getX()][desPos[i].getY() + j].m_bOccupied == true)
                                break;
                        }
                        //没有老鼠，可以跳河
                        if (j == 3)
                        {
                            //修改目的格子到河对岸
                            desPos[i].setY(desPos[i].getY() + 3);
                            tempPieces[i] = board.m_aPieces[desPos[i].getX()][desPos[i].getY()];
                        }
                        //有老鼠，无法跳河，返回一个无效坐标
                        else
                            flag = 1;
                        break;
                    }
                    if (flag) {
                        Position invaluePos = { -1,-1 };
                        resultPos[i] = invaluePos;
                        continue;
                    }

                }
                //目标格子上有棋子
                if (tempPieces[i].m_bOccupied == true) {
                    //遇到我方棋子，无法移动
                    if (tempPieces[i].Cheker.getCamp() == curPieces.Cheker.getCamp()) {
                        Position invaluePos = { -1,-1 };
                        resultPos[i] = invaluePos;
                        continue;
                    }
                    //遇到对方棋子
                    else
                    {
                        //能吃，可移动，返回当前目的格子的坐标
                        if (readyEat(curPos, desPos[i]) == true)
                            resultPos[i] = desPos[i];
                        //不能吃，无法移动
                        else{
                            Position invaluePos = { -1,-1 };
                            resultPos[i] = invaluePos;
                        }
                        continue;
                    }
                }
                //目标格子上无棋子，可移动，返回当前目的格子的坐标
                else {
                    resultPos[i] = desPos[i];
                    continue;
                }
            }
        }
    }
    else {
        //其他动物
        for (int i = 0; i < 4; i++) {
            //判断是否超边界
            if (desPos[i].getX() < 0 || desPos[i].getY() < 0) {
                Position invaluePos = { -1,-1 };
                resultPos[i] = invaluePos;
                continue;
            }
            else {
                //目的格子在河里，无法移动
                if (tempPieces[i].m_nLandForm == RIVER)
                {
                    Position invaluePos = { -1,-1 };
                    resultPos[i] = invaluePos;
                    continue;
                }
                //目的格子不在河里
                else {
                    //移动到我方兽穴，无法移动
                    if (tempPieces[i].m_nLandForm == mycamp)
                    {
                        Position invaluePos = { -1,-1 };
                        resultPos[i] = invaluePos;
                        continue;
                    }
                    //非兽穴，判断是否有棋子，有棋子
                    if (tempPieces[i].m_bOccupied == true) {
                        //遇到我方棋子，无法移动
                        if (tempPieces[i].Cheker.getCamp() == curPieces.Cheker.getCamp())
                        {
                            Position invaluePos = { -1,-1 };
                            resultPos[i] = invaluePos;
                            continue;
                        }
                        //遇到对方棋子
                        else
                        {
                            //能吃，可移动，返回当前目的格子的坐标
                            if (readyEat(curPos, desPos[i]) == true)
                                resultPos[i] = desPos[i];
                            //不能吃，无法移动
                            else {
                                Position invaluePos = { -1,-1 };
                                resultPos[i] = invaluePos;
                            }
                            continue;
                        }
                    }
                    //目标格子上无棋子，可移动，返回当前目的格子的坐标
                    else {
                        resultPos[i] = desPos[i];
                        continue;
                    }
                }
            }
        }
    }
    //返回最终可移动的坐标数组
    return resultPos;
    delete[] resultPos;
}
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
int Move(Position curPos, Position desPos) {
    ChessPiecesModel curPieces = board.m_aPieces[curPos.getX()][curPos.getY()];
    ChessPiecesModel desPieces = board.m_aPieces[desPos.getX()][desPos.getY()];
    int othercamp;//othercamp表示对方兽穴
    if (curPieces.Cheker.getCamp() == red)
        othercamp = BLUE_DEN;
    else
        othercamp = RED_DEN;
    //resultPos指向readyMove返回的坐标数组
    Position* resultPos = readyMove(curPos);
    int i;
    for(i=0;i<4;i++)
    {
        //目的格子属于可移动格子
        if (desPos.getX() == resultPos[i].getX() && desPos.getY() == resultPos[i].getY())
        {
            //目的格子为对方兽穴，游戏结束
            if (desPieces.m_nLandForm == othercamp)
                return 3;
            else {
                //目的格子上有棋子，吃了对方玩家一个棋子
                if (desPieces.m_bOccupied == true)
                    return 2;
                //目的格子上无棋子，正常移动
                else
                    return 0;
            }
        }
    }
    //目标格子不属于可移动格子，移动失败
    if(i==4)
        return 1;
}

