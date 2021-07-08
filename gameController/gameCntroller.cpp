#include<iostream>
#include"gameCntroller.h"
#include"../common.h"
#include"../gameModel/ChessPiecesModel.h"
#include"../gameModel/ChessBoardModel.h"
#include"../gameModel/CheckerModel.h"
using namespace std;
extern ChessBoardModel board;

/**
 * @brief readyEat : �ж������Ƿ���Գ�
 * @prama curPos :��ǰ����λ�ã�x,y)
 * @prama desPos :Ŀ������λ�ã�x,y)
 * @reutrn bool:     true�����Գԣ� false�������Գ�
*/
bool readyEat(Position curPos, Position desPos){
    ChessPiecesModel curPieces = board.m_aPieces[curPos.getX()][curPos.getY()];
    ChessPiecesModel desPieces = board.m_aPieces[desPos.getX()][desPos.getY()];
    int mycamp;//othercamp��ʾ��������
    if (curPieces.Cheker.getCamp() == red)
        mycamp = RED_TRAP;
    else
        mycamp = BLUE_TRAP;
    //�Է������ڼ���������Գ�
    if (desPieces.m_nLandForm == mycamp)
        return true;
    else {
        //��������ս������
        if (curPieces.Cheker.getStrength() > desPieces.Cheker.getStrength()) {
            //�����޷�������
            if (curPieces.Cheker.getType() == ELEPHANT && desPieces.Cheker.getType() == RAT)
                return false;
            else
                //�������Գԣ��������뿼�����赲���ӳԶ԰������ӣ������޷��ƶ��������
                return true;
        }
        //˫������ս����һ�¿��Գ�
        else if (curPieces.Cheker.getStrength() == desPieces.Cheker.getStrength())
            return true;
        //�Է�����ս�����߲��ܳ�
        else {
            //���󵥶����ۣ��ں��ﲻ�ܳ԰���
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
 * @brief readyMove : �ж����ӿ����ƶ���λ��
 * @prama curPos:     ���ӵ�ǰλ�ã�x,y)
 * @return Position* ��    ����һ���ṹ��ָ�룬ָ������ƶ���λ������
*/
Position* readyMove(Position curPos) {
    ChessPiecesModel curPieces = board.m_aPieces[curPos.getX()][curPos.getY()];
    ChessPiecesModel tempPieces[4];//tempPieces������ѡ�������������ĸ�����
    Position desPos[4];//desPos�������������ĸ����ӵ�����
    Position* resultPos=new Position[4];//resultPos���淵�ص��ĸ�����
    //�������������ĸ����ӵ�����
    desPos[0].setX(curPos.getX() - 1); desPos[0].setY(curPos.getY());
    desPos[1].setX(curPos.getX() + 1); desPos[1].setY(curPos.getY());
    desPos[2].setX(curPos.getX()); desPos[2].setY(curPos.getY() - 1);
    desPos[3].setX(curPos.getX()); desPos[3].setY(curPos.getY() + 1);
    //���ĸ������Ӧ�������ϵ��ĸ����ӽ���tempPieces�ݴ�
    for (int i = 0; i < 4; i++) {
        tempPieces[i] = board.m_aPieces[desPos[i].getX()][desPos[i].getY()];
    }
    int mycamp;//mycamp��ʾ�ҷ���Ѩ
    if (curPieces.Cheker.getCamp() == red)
        mycamp = RED_DEN;
    else
        mycamp = BLUE_DEN;
    //��������ۣ���ʨ��������
    //��
    if (curPieces.Cheker.getType() == RAT) {
        for (int i = 0; i < 4; i++) {
            //�ж��Ƿ񳬱߽�
            if (desPos[i].getX() < 0 || desPos[i].getY() < 0)
            {
                Position invaluePos = { -1,-1 };
                resultPos[i] = invaluePos;
                continue;
            }
            else {
                //Ŀ�������������
                if (tempPieces[i].m_bOccupied == true) {
                    //����Ϊ�ҷ���Ӫ���޷��ƶ�
                    if (tempPieces[i].Cheker.getCamp() == curPieces.Cheker.getCamp()) {
                        Position invaluePos = { -1,-1 };
                        resultPos[i] = invaluePos;
                        continue;
                    }
                    //����Ϊ�Է���Ӫ
                    else
                    {
                        //�ܳԣ����ص�ǰĿ�ĸ��ӵ�����
                        if (readyEat(curPos, desPos[i]) == true)
                            resultPos[i] = desPos[i];
                        //���ܳԣ�ֱ�ӷ���
                        continue;
                    }
                }
                //Ŀ�������������
                else {
                    //���ҷ���Ѩ�����ص�ǰĿ�ĸ��ӵ�����
                    if (tempPieces[i].m_nLandForm != mycamp)
                    {
                        resultPos[i] = desPos[i];
                    }//�ƶ����ҷ���Ѩ���޷��ƶ�
                    else{
                        Position invaluePos = { -1,-1 };
                        resultPos[i] = invaluePos;
                    }
                    continue;
                }
            }
        }
    }
    //ʨ��
    else if (curPieces.Cheker.getType() == TIGER || curPieces.Cheker.getType() == LION) {
        for (int i = 0; i < 4; i++) {
            //�ж��Ƿ񳬱߽�
            if (desPos[i].getX() < 0 || desPos[i].getY() < 0) {
                Position invaluePos = { -1,-1 };
                resultPos[i] = invaluePos;
                continue;
            }
            else {
                //�ƶ����ҷ���Ѩ���޷��ƶ�
                if (tempPieces[i].m_nLandForm == mycamp) {
                    Position invaluePos = { -1,-1 };
                    resultPos[i] = invaluePos;
                    continue;
                }
                //���ҷ���Ѩ
                //�ø����ں��˵��ʨ�����˺ӱ�
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
                        //û�����󣬿�������
                        if (j == 2)
                        {
                            //�޸�Ŀ�ĸ��ӵ��Ӷ԰�
                            desPos[i].setX(desPos[i].getX() - 2);
                            tempPieces[i] = board.m_aPieces[desPos[i].getX()][desPos[i].getY()];
                        }
                        //�������޷����ӣ�����һ����Ч����
                        else
                            flag = 1;
                        break;
                    case 1:
                        for (j = 0; j < 2; j++)
                        {
                            if (board.m_aPieces[desPos[i].getX() + j][desPos[i].getY()].m_bOccupied == true)
                                break;
                        }
                        //û�����󣬿�������
                        if (j == 2)
                        {
                            //�޸�Ŀ�ĸ��ӵ��Ӷ԰�
                            desPos[i].setX(desPos[i].getX() + 2);
                            tempPieces[i] = board.m_aPieces[desPos[i].getX()][desPos[i].getY()];
                        }
                        //�������޷����ӣ�����һ����Ч����
                        else
                            flag = 1;
                        break;
                    case 2://2��Ӧ��ǰ���ӵ������ӣ�ֻ��������
                        //�ж����ĺӵ�����������
                        for (j = 0; j < 3; j++)
                        {
                            if (board.m_aPieces[desPos[i].getX()][desPos[i].getY() - j].m_bOccupied == true)
                                break;
                        }
                        //û�����󣬿�������
                        if (j == 3)
                        {
                            //�޸�Ŀ�ĸ��ӵ��Ӷ԰�
                            desPos[i].setY(desPos[i].getY() - 3);
                            tempPieces[i] = board.m_aPieces[desPos[i].getX()][desPos[i].getY()];
                        }
                        //�������޷����ӣ�����һ����Ч����
                        else
                            flag = 1;
                        break;
                    case 3://3��Ӧ��ǰ���ӵ��Ҳ���ӣ�ֻ��������
                        //�ж��Ҳ�ĺӵ�����������
                        for (j = 0; j < 3; j++)
                        {
                            if (board.m_aPieces[desPos[i].getX()][desPos[i].getY() + j].m_bOccupied == true)
                                break;
                        }
                        //û�����󣬿�������
                        if (j == 3)
                        {
                            //�޸�Ŀ�ĸ��ӵ��Ӷ԰�
                            desPos[i].setY(desPos[i].getY() + 3);
                            tempPieces[i] = board.m_aPieces[desPos[i].getX()][desPos[i].getY()];
                        }
                        //�������޷����ӣ�����һ����Ч����
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
                //Ŀ�������������
                if (tempPieces[i].m_bOccupied == true) {
                    //�����ҷ����ӣ��޷��ƶ�
                    if (tempPieces[i].Cheker.getCamp() == curPieces.Cheker.getCamp()) {
                        Position invaluePos = { -1,-1 };
                        resultPos[i] = invaluePos;
                        continue;
                    }
                    //�����Է�����
                    else
                    {
                        //�ܳԣ����ƶ������ص�ǰĿ�ĸ��ӵ�����
                        if (readyEat(curPos, desPos[i]) == true)
                            resultPos[i] = desPos[i];
                        //���ܳԣ��޷��ƶ�
                        else{
                            Position invaluePos = { -1,-1 };
                            resultPos[i] = invaluePos;
                        }
                        continue;
                    }
                }
                //Ŀ������������ӣ����ƶ������ص�ǰĿ�ĸ��ӵ�����
                else {
                    resultPos[i] = desPos[i];
                    continue;
                }
            }
        }
    }
    else {
        //��������
        for (int i = 0; i < 4; i++) {
            //�ж��Ƿ񳬱߽�
            if (desPos[i].getX() < 0 || desPos[i].getY() < 0) {
                Position invaluePos = { -1,-1 };
                resultPos[i] = invaluePos;
                continue;
            }
            else {
                //Ŀ�ĸ����ں���޷��ƶ�
                if (tempPieces[i].m_nLandForm == RIVER)
                {
                    Position invaluePos = { -1,-1 };
                    resultPos[i] = invaluePos;
                    continue;
                }
                //Ŀ�ĸ��Ӳ��ں���
                else {
                    //�ƶ����ҷ���Ѩ���޷��ƶ�
                    if (tempPieces[i].m_nLandForm == mycamp)
                    {
                        Position invaluePos = { -1,-1 };
                        resultPos[i] = invaluePos;
                        continue;
                    }
                    //����Ѩ���ж��Ƿ������ӣ�������
                    if (tempPieces[i].m_bOccupied == true) {
                        //�����ҷ����ӣ��޷��ƶ�
                        if (tempPieces[i].Cheker.getCamp() == curPieces.Cheker.getCamp())
                        {
                            Position invaluePos = { -1,-1 };
                            resultPos[i] = invaluePos;
                            continue;
                        }
                        //�����Է�����
                        else
                        {
                            //�ܳԣ����ƶ������ص�ǰĿ�ĸ��ӵ�����
                            if (readyEat(curPos, desPos[i]) == true)
                                resultPos[i] = desPos[i];
                            //���ܳԣ��޷��ƶ�
                            else {
                                Position invaluePos = { -1,-1 };
                                resultPos[i] = invaluePos;
                            }
                            continue;
                        }
                    }
                    //Ŀ������������ӣ����ƶ������ص�ǰĿ�ĸ��ӵ�����
                    else {
                        resultPos[i] = desPos[i];
                        continue;
                    }
                }
            }
        }
    }
    //�������տ��ƶ�����������
    return resultPos;
    delete[] resultPos;
}
/**
 * @brief Move :      �ƶ�����
 * @prama curPos:     ���ӵ�ǰλ�ã�x,y)
 * @prama desPos:     ����Ŀ��λ�ã�x,y)
 * @return int ��
 *                    0�������ƶ�
 *                    1���ƶ�ʧ��
 *                    2�����˶Է����һ������
 *                    3����Ϸ����
 */
int Move(Position curPos, Position desPos) {
    ChessPiecesModel curPieces = board.m_aPieces[curPos.getX()][curPos.getY()];
    ChessPiecesModel desPieces = board.m_aPieces[desPos.getX()][desPos.getY()];
    int othercamp;//othercamp��ʾ�Է���Ѩ
    if (curPieces.Cheker.getCamp() == red)
        othercamp = BLUE_DEN;
    else
        othercamp = RED_DEN;
    //resultPosָ��readyMove���ص���������
    Position* resultPos = readyMove(curPos);
    int i;
    for(i=0;i<4;i++)
    {
        //Ŀ�ĸ������ڿ��ƶ�����
        if (desPos.getX() == resultPos[i].getX() && desPos.getY() == resultPos[i].getY())
        {
            //Ŀ�ĸ���Ϊ�Է���Ѩ����Ϸ����
            if (desPieces.m_nLandForm == othercamp)
                return 3;
            else {
                //Ŀ�ĸ����������ӣ����˶Է����һ������
                if (desPieces.m_bOccupied == true)
                    return 2;
                //Ŀ�ĸ����������ӣ������ƶ�
                else
                    return 0;
            }
        }
    }
    //Ŀ����Ӳ����ڿ��ƶ����ӣ��ƶ�ʧ��
    if(i==4)
        return 1;
}

