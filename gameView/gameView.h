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
 *    ��ʼ����Ϸ��
 *       ��ʼ����Ϸ����()
 *       ����������� �����������Play1.Camp
 *       ��ӡ����
 */
void initGame();

/*
    

    // ��Ӫ
    bool N = true;
    ѭ��{
        N=!N;

    }
    ��Ϸ���� ��ӡ����
*/

/**
 * @brief playGame:
 *    ��Ϸ�߼����֣�         
 *       �ȴ�N��Ӫ���ѡ������
 *       ѭ��{
 *           �ж���������Ƿ����ڸ����
 *           ����ǣ�
 *               �����ƶ��ж�
 *               �����ƶ��жϵķ���ֵ ��չʾ�����ƶ���λ��
 *           �����ҵ���˿��ƶ�λ�ã�
 *               �����ƶ�()
 *               �����ƶ���ķ���ֵ �����Ӧ�Ľ����ӡ
 *               ��������Ӫ�Ĳ���
 *           �����ҵ�����Լ����������� continue;
 *       }
 */
void playGame();


/**
 * @brief gameOver:  
 *       ��Ϸ������
 *           ��ʾ�Ծֽ����
 */
void gameOver();
void time_c(int swp);