#pragma once
#include "../Position.h"
#include "../gameModel/ChessPiecesModel.h"
class CheckerModel;
class Position;
class ChessPiecesModel;
//extern ChessBoard;  //�����࣬�����˴洢ȫ�ֵ�ͼ��Ϣ�Ķ�ά����m_aPieces[7][9]
/**
 * @brief controller��:  ��Ϸ�����߼����ֵ�ʵ��
*/

/**
 * @brief Pos:  ��ʾ����λ�õĽṹ��
*/

/**
 * @brief readyEat : �ж������Ƿ���Գ�
 * @prama sourcePos: ������ʼλ�ã�x,y) 
 * @prama desPos:    ����Ŀ��λ�ã�x,y)
 * @reutrn bool:     true�����Գԣ� false�������Գ�
*/
bool readyEat(Position curPos, Position desPos);


/**
 * @brief readyMove : �ж����ӿ����ƶ���λ��
 * @prama curPiece:     ���ӵ�ǰ���ӣ�x,y)
 * @prama desPiece:     ����Ŀ�ĸ��ӣ�x,y)
 * @prama checkerType:�������ͣ�ȷ�����ӵ��ƶ���ʽ�����ɸ���
 * @prama len:        �����ƶ��ľ��볤�ȣ�ȷ���ƶ�·����û���ϰ�
 * @return Pos* ��    ����һ���ṹ��ָ�룬ָ������ƶ���λ������
*/
Position* readyMove(Position curPos);
    // Ŀ�ĵ�û������ || �ез����� readyEat  true
    //if Board[desPos.x][] == land  && len = 1  �ƶ�
    //                     == ����   && ��  len = 1 �ƶ�
    //                     == ����    && ʨ�� �� len = ��������  && �з���������ͼ��
    //                     == ��Ѩ   && ��Ӫ   �з� ��Ϸ���� 
    //                     == ����   �������
    //    �µĲο�˼·
    //reayMove ֻ�������Ӷ�Ӧ�Ŀ��Եĵص㣬
    //             �����Ƿ������ӵ���Ϊ�����жϣ�����Ŀ�ĵؽ����ж�
    //    �����������ͣ�������Ӧ���жϺ���������ö�����ͼ�common.h
    //        �����Ͽ��Է�Ϊ���ࣺ
    //           ��ͨ���ӣ���½�����ƶ�һ�񣩣� �����ӵ��Σ��� ʨ������Ծ��
    /*switch (checker.m_nType)
    {
    case:  ...  //������Ӧ���ӵ��ƶ��ж�
    case:  ...
    default:
        break;
    }*/
int Move(Position curPos, Position desPos);
/*
    ��(x,y)���ƶ���(toX,toY)��
        toX��toY�ĺϷ��ж�(���ܳ��߽磬�����ƶ���������Ѩ)
        ��������� ����eat�ж��Ƿ��ܳ�
            ������ܳ� �޷��ƶ�
            ������Գ� �Է��������-1 �ƶ��ɹ�
        ����ƶ�����Ѩ ��Ϸ����
        ���û������ �ƶ��ɹ�

    ����ֵ��
        0�������ƶ�
        1���ƶ�ʧ��
        2�����˶Է����һ������
        3����Ϸ����
*/
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
// �ж��ƶ��ĺϷ��ԣ������ƶ�������з�����
// �����������ͼ����һ�����������������Ӻӵ��ε��ػ淽��
// �ο�˼·��
//      if desPos in readyMovePos
//               then move to desPos
//      else failure move
//      if desPos isOccupied
//                then eat
/*
int Move(ChessPiecesModel curPiece, ChessPiecesModel desPiece);



//���Ӷ�����λ�õ��ж�
//�Ƿ������̱߽� ���߽�ָ��������Χ��һȦ���̸��ӵ�λ��
//�ڱ߽磺 true  ���ڱ߽�false
bool atBoundary(CheckerModel checker);

//�Ƿ��ںӱߣ��ںӱ�Ϊture ���ӱ�ָ���ǿ����ӵ����ܸ��ӵ�λ��
bool byRiver(CheckerModel checker);

//�Ƿ��ں���ں��ﷵ��true
bool inRiver(CheckerModel checker);

//�ܷ���������,�������������򷵻�true
//�������Ϊ�������ںӱߣ�ˮ·���޶Է����󣬰����޸�ǿ���������
//�ο�˼·��
// �ӵ�ǰ����λ�ó��������Ӷ԰����򣬱���·���ϵĸ���:
//                 ����ں����жԷ�������ڣ��򷵻�false
//                 ����԰��д���ʨ�Ӵ��ڣ��򷵻�false
//                 ���򣬿������������������Ϊ������true
bool canJump(CheckerModel checker);
*/