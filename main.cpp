#include <graphics.h>
#include <conio.h>
#include <easyx.h>
#include"gameView/gameView.h"
#include<stdio.h>
#include "gameModel/ChessBoardModel.h"
//ȫ�ֵ�������ʵ��
//���е�ǰ���̵�������Ϣ�ĵ�ͼ���� ChessPiecesModel m_aPieces[7][9];
// ��������˵���� ������7*9�����̸��ӣ�����ͨ�����̸��ӵĽӿڻ�ȡ���̸��ӵ���Ϣ
// ʹ��ʱ���� extern ChessBoardModel board;���ɣ��������ͷ�ļ�
ChessBoardModel board;

int main()
{
	initGame();
	playGame();
	getchar();//��������
	closegraph();//�رմ���
	return 0;

}