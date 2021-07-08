#include "gameView.h"
#include "drawView.h"
#include <string>
#include <iostream>
#include "../common.h"
#include "../gameModel/PlayerModel.h"
#include "../gameModel/ChessPiecesModel.h"
#include "../gameModel/ChessBoardModel.h"
#include "../gameController/gameCntroller.h"
#include <mmsystem.h>
#pragma comment(lib,"winmm.lib")
using namespace std;
#define WO_ 100		/**/
#define LO_ 120		/**/

/* WJ*/
//#define LO_ 125 
//#define WO_ 150 
/* WJ*/

#define PIECE 80 
#define FI 5	 
#define PIG 70	 
#define PIG_X 80 
#define PIG_Y 20 

extern ChessBoardModel board;
bool Flag = 0;//棋权，默认红方先走
bool f1 = 0, f2 = 0;//切换头像
bool click = true;	
Position FirstPos;
Position SecondPos;
PlayerModel PlayerA("cluo", "./picture/PlayerA.jpg", red, 8);	
PlayerModel PlayerB("meixi", "./picture/PlayerB.jpg", blue, 8); 
/**
 * @brief initGame:
 *    初始化游戏：
 *       初始化游戏数据()
 *       接受玩家输入 生成两个玩家Play1.Camp
 *       打印界面
 */
void time_c(int swp)		
{
	static int clock = 40000000;	
	static int sec = 30;		
	char str[30];
	clock++;						
	if (swp)
		clock = 0;
	if (clock > 50000000)			
	{
		clock = 0;
		sec--;
		sprintf_s(str, "time left:%d", sec);
		if (sec < 0)
		{
			sec = -2;
			sprintf_s(str, "warning:", NULL);
		}
		setfillcolor(0x8B7500);
		solidrectangle(420, 40, 540, 60);
		settextcolor(WHITE);
		settextstyle(20, 0, "宋体");
		setbkmode(TRANSPARENT);
		outtextxy(420, 40, str);

	}
	if (swp)
	{
		sec = 30;
		clock = 40000000;
	}
}
void initGame()
{

	drawView DrawInit;//实例化一个初始化游戏的对象
	board.setHeight(960);//设置整个界面高度
	board.setWidth(720);//设置整个界面宽度
	DrawInit.draw(board);//画界面背景和棋盘背景

	//创建红方棋子
	CheckerModel RedRat(red, RAT, 1);

	CheckerModel RedCat(red, CAT, 2);


	CheckerModel RedDog(red, DOG, 3);

	CheckerModel RedWolf(red, WOLF, 4);

	CheckerModel RedLeopard(red, LEOPARD, 5);

	CheckerModel RedTiger(red, TIGER, 6);

	CheckerModel RedLion(red, LION, 7);

	CheckerModel RedElephant(red, ELEPHANT, 8);

	//红方开局棋子位置
	RedRat.setCurPos(6, 2);

	RedCat.setCurPos(1, 1);

	RedWolf.setCurPos(2, 2);

	RedDog.setCurPos(5, 1);

	RedLeopard.setCurPos(4, 2);

	RedTiger.setCurPos(0, 0);

	RedLion.setCurPos(6, 0);

	RedElephant.setCurPos(0, 2);

	//创建蓝方棋子
	CheckerModel BlueRat(blue, RAT, 1);

	CheckerModel BlueCat(blue, CAT, 2);

	CheckerModel BlueWolf(blue, WOLF, 4);

	CheckerModel BlueDog(blue, DOG, 3);

	CheckerModel BlueLeopard(blue, LEOPARD, 5);

	CheckerModel BlueTiger(blue, TIGER, 6);

	CheckerModel BlueLion(blue, LION, 7);

	CheckerModel BlueElephant(blue, ELEPHANT, 8);

	//创建蓝方棋子开局坐标
	BlueRat.setCurPos(0, 6);

	BlueCat.setCurPos(5, 7);

	BlueWolf.setCurPos(4, 6);

	BlueDog.setCurPos(1, 7);

	BlueLeopard.setCurPos(2, 6);

	BlueTiger.setCurPos(6, 8);

	BlueLion.setCurPos(0, 8);

	BlueElephant.setCurPos(6, 6);
	//两层for 根据开局位置 设置二维格子数组中pieces 和动物
	for (int i = 0; i < 7; i++)
	{
		for (int j = 0; j < 9; j++)
		{

			if ((i == 0) && (j == 0))
			{
				board.m_aPieces[i][j].Cheker = RedTiger;
				board.m_aPieces[i][j].m_bOccupied = true;
				board.m_aPieces[i][j].m_nLandForm = LAND;
				cout << "(" << i << "," << j << ")" << board.m_aPieces[i][j].m_nLandForm << endl;
			}

			else if ((i == 1) && (j == 1))
			{
				board.m_aPieces[i][j].Cheker = RedCat;
				board.m_aPieces[i][j].m_bOccupied = true;
				board.m_aPieces[i][j].m_nLandForm = LAND;
				cout << "(" << i << "," << j << ")" << board.m_aPieces[i][j].m_nLandForm << endl;
			}

			else if ((i == 0) && (j == 2))
			{
				board.m_aPieces[i][j].Cheker = RedElephant;
				board.m_aPieces[i][j].m_bOccupied = true;
				board.m_aPieces[i][j].m_nLandForm = LAND;
				cout << "(" << i << "," << j << ")" << board.m_aPieces[i][j].m_nLandForm << endl;
			}

			else if ((i == 2) && (j == 2))
			{
				board.m_aPieces[i][j].Cheker = RedWolf;
				board.m_aPieces[i][j].m_bOccupied = true;
				board.m_aPieces[i][j].m_nLandForm = LAND;
				cout << "(" << i << "," << j << ")" << board.m_aPieces[i][j].m_nLandForm << endl;
			}

			else if ((i == 4) && (j == 2))
			{
				board.m_aPieces[i][j].Cheker = RedLeopard;
				board.m_aPieces[i][j].m_bOccupied = true;
				board.m_aPieces[i][j].m_nLandForm = LAND;
				cout << "(" << i << "," << j << ")" << board.m_aPieces[i][j].m_nLandForm << endl;
			}

			else if ((i == 5) && (j == 1))
			{
				board.m_aPieces[i][j].Cheker = RedDog;
				board.m_aPieces[i][j].m_bOccupied = true;
				board.m_aPieces[i][j].m_nLandForm = LAND;
				cout << "(" << i << "," << j << ")" << board.m_aPieces[i][j].m_nLandForm << endl;
			}

			else if ((i == 6) && (j == 0))
			{
				board.m_aPieces[i][j].Cheker = RedLion;
				board.m_aPieces[i][j].m_bOccupied = true;
				board.m_aPieces[i][j].m_nLandForm = LAND;
				cout << "(" << i << "," << j << ")" << board.m_aPieces[i][j].m_nLandForm << endl;
			}

			else if ((i == 6) && (j == 2))
			{
				board.m_aPieces[i][j].Cheker = RedRat;
				board.m_aPieces[i][j].m_bOccupied = true;
				board.m_aPieces[i][j].m_nLandForm = LAND;
				cout << "(" << i << "," << j << ")" << board.m_aPieces[i][j].m_nLandForm << endl;
			}

			else if ((i == 0) && (j == 6))
			{
				board.m_aPieces[i][j].Cheker = BlueRat;
				board.m_aPieces[i][j].m_bOccupied = true;
				board.m_aPieces[i][j].m_nLandForm = LAND;
				cout << "(" << i << "," << j << ")" << board.m_aPieces[i][j].m_nLandForm << endl;
			}

			else if ((i == 2) && (j == 6))
			{
				board.m_aPieces[i][j].Cheker = BlueLeopard;
				board.m_aPieces[i][j].m_bOccupied = true;
				board.m_aPieces[i][j].m_nLandForm = LAND;
				cout << "(" << i << "," << j << ")" << board.m_aPieces[i][j].m_nLandForm << endl;
			}

			else if ((i == 1) && (j == 7))
			{
				board.m_aPieces[i][j].Cheker = BlueDog;
				board.m_aPieces[i][j].m_bOccupied = true;
				board.m_aPieces[i][j].m_nLandForm = LAND;
				cout << "(" << i << "," << j << ")" << board.m_aPieces[i][j].m_nLandForm << endl;
			}

			else if ((i == 0) && (j == 8))
			{
				board.m_aPieces[i][j].Cheker = BlueLion;
				board.m_aPieces[i][j].m_bOccupied = true;
				board.m_aPieces[i][j].m_nLandForm = LAND;
				cout << "(" << i << "," << j << ")" << board.m_aPieces[i][j].m_nLandForm << endl;
			}

			else if ((i == 4) && (j == 6))
			{
				board.m_aPieces[i][j].Cheker = BlueWolf;
				board.m_aPieces[i][j].m_bOccupied = true;
				board.m_aPieces[i][j].m_nLandForm = LAND;
				cout << "(" << i << "," << j << ")" << board.m_aPieces[i][j].m_nLandForm << endl;
			}

			else if ((i == 5) && (j == 7))
			{
				board.m_aPieces[i][j].Cheker = BlueCat;
				board.m_aPieces[i][j].m_bOccupied = true;
				board.m_aPieces[i][j].m_nLandForm = LAND;
				cout << "(" << i << "," << j << ")" << board.m_aPieces[i][j].m_nLandForm << endl;
			}

			else if ((i == 6) && (j == 6))
			{
				board.m_aPieces[i][j].Cheker = BlueElephant;
				board.m_aPieces[i][j].m_bOccupied = true;
				board.m_aPieces[i][j].m_nLandForm = LAND;
				cout << "(" << i << "," << j << ")" << board.m_aPieces[i][j].m_nLandForm << endl;
			}

			else if ((i == 6) && (j == 8))
			{
				board.m_aPieces[i][j].Cheker = BlueTiger;
				board.m_aPieces[i][j].m_bOccupied = true;
				board.m_aPieces[i][j].m_nLandForm = LAND;
				cout << "(" << i << "," << j << ")" << board.m_aPieces[i][j].m_nLandForm << endl;
			}

			else if ((i == 2) && (j == 0) || (i == 3) && (j == 1) || (i == 4) && (j == 0))
			{
				board.m_aPieces[i][j].Cheker = BlueRat;
				board.m_aPieces[i][j].m_bOccupied = false;
				board.m_aPieces[i][j].m_nLandForm = RED_TRAP;
				cout << "(" << i << "," << j << ")" << board.m_aPieces[i][j].m_nLandForm << endl;
			}

			else if ((i == 3) && (j == 7) || (i == 2) && (j == 8) || (i == 4) && (j == 8))
			{
				board.m_aPieces[i][j].Cheker = BlueRat;
				board.m_aPieces[i][j].m_bOccupied = false;
				board.m_aPieces[i][j].m_nLandForm = BLUE_TRAP;
				cout << "(" << i << "," << j << ")" << board.m_aPieces[i][j].m_nLandForm << endl;
			}

			else if ((i == 3) && (j == 0))
			{
				board.m_aPieces[i][j].Cheker = BlueRat;
				board.m_aPieces[i][j].m_bOccupied = false;
				board.m_aPieces[i][j].m_nLandForm = RED_DEN;
				cout << "(" << i << "," << j << ")" << board.m_aPieces[i][j].m_nLandForm << endl;
			}

			else if ((i == 3) && (j == 8))
			{
				board.m_aPieces[i][j].Cheker = BlueRat;
				board.m_aPieces[i][j].m_bOccupied = false;
				board.m_aPieces[i][j].m_nLandForm = BLUE_DEN;
				cout << "(" << i << "," << j << ")" << board.m_aPieces[i][j].m_nLandForm << endl;
			}
			else if (i >= 1 && i < 3 && j >= 3 && j < 6)
			{
				board.m_aPieces[i][j].Cheker = RedTiger;
				board.m_aPieces[i][j].m_bOccupied = false;
				board.m_aPieces[i][j].m_nLandForm = RIVER;
			}
			else if (i >= 4 && i < 6 && j >= 3 && j < 6)
			{
				board.m_aPieces[i][j].Cheker = RedTiger;
				board.m_aPieces[i][j].m_bOccupied = false;
				board.m_aPieces[i][j].m_nLandForm = RIVER;
			}
			else
			{
				board.m_aPieces[i][j].Cheker = BlueRat;
				board.m_aPieces[i][j].m_bOccupied = false;
				board.m_aPieces[i][j].m_nLandForm = LAND;
			}

		}
		cout << endl;
	}

	DrawInit.draw(PlayerA);//调用draw画出选手A
	DrawInit.draw(PlayerB);//调用draw画出选手B

	DrawInit.initPieces();//画出所有格子
	DrawInit.initChess();//画出所有棋子
}

void playGame()
{
	drawView show;
	bool music = true;
	while (true)
	{
		if (MouseHit())
		{
			MOUSEMSG msg = GetMouseMsg();
			switch (msg.uMsg)
			{
			case WM_LBUTTONDOWN:
			case WM_RBUTTONDOWN:
			{
				cout << "mouse pos" << "(" << msg.y << "," << msg.x <<")" << endl;
				//判断鼠标是不是在棋盘中
				if (((msg.x >= WO_) && (msg.x <= 865)) && ((msg.y >= LO_) && (msg.y <= 715))) 
				{
					cout << "good mouse pos" << endl;
					
					if (click)//初始为1
					{
						FirstPos.setX(int((msg.y - LO_) / (80+FI)));
						FirstPos.setY(int((msg.x - WO_) / (80 + FI)));
						click = !click;
						//cout << "first点击应数组下标" << int((msg.y - LO_) / 80) << "," << int((msg.x - WO_) / 80) << "click=" << click << endl;
					}
					else
					{
						SecondPos.setX(int((msg.y - LO_) / (80 + FI)));
						SecondPos.setY(int((msg.x - WO_) / (80 + FI)));
						click = !click;
						//cout << "second点击应数组下标" << int((msg.y - LO_) / 80) << "," << int((msg.x - WO_) / 80) << "click=" << click << endl;
					}

					//选中红方棋子
					if (board.m_aPieces[FirstPos.getX()][FirstPos.getY()].m_bOccupied && !board.m_aPieces[FirstPos.getX()][FirstPos.getY()].Cheker.getCamp())
					{
						
						cout << "camp chosed " << board.m_aPieces[FirstPos.getX()][FirstPos.getY()].Cheker.getCamp() << endl;
						if (!Flag)//轮到红方走棋
						{
							if (!click)//第一次点击
							{
								setlinecolor(RED);
								setlinestyle(PS_SOLID, 3);
								circle(FirstPos.getY() * (80 + FI) + PIECE / 2 + WO_, FirstPos.getX() * (80 + FI) + PIECE / 2 + LO_, 32); //填充选中区域
							}
							else//第二次点击
							{
								//获取第二次鼠标位置和数组下标，调用move，根据返回值对应情况刷新显示
								SecondPos.setX(int((msg.y - LO_) / 80));
								SecondPos.setY(int((msg.x - WO_) / 80));
								int GetMoveResult = Move(FirstPos, SecondPos);
								cout << "red return value=" << GetMoveResult << endl;
								HWND temp = GetHWnd();
								switch (GetMoveResult)
								{
								case 0:
									board.m_aPieces[FirstPos.getX()][FirstPos.getY()].m_bOccupied = false;
									board.m_aPieces[SecondPos.getX()][SecondPos.getY()].m_bOccupied = true;
									board.m_aPieces[SecondPos.getX()][SecondPos.getY()].Cheker = board.m_aPieces[FirstPos.getX()][FirstPos.getY()].Cheker;
									board.m_aPieces[SecondPos.getX()][SecondPos.getY()].Cheker.setCurPos(SecondPos.getX(), SecondPos.getY());
									show.draw(board.m_aPieces[FirstPos.getX()][FirstPos.getY()], FirstPos.getX(), FirstPos.getY());
									show.draw(board.m_aPieces[SecondPos.getX()][SecondPos.getY()].Cheker, SecondPos.getX(), SecondPos.getY());
									Flag = 1;
									time_c(1);
									break;

								case 1: //移动失败
									//将第一次选中位置重新显示，因为要刷掉标记；
									cout << "failed animal type" << board.m_aPieces[FirstPos.getY()][FirstPos.getX()].Cheker.getType() << endl;
									MessageBox(temp, "can't move here!", "WARNING", MB_OKCANCEL);
									show.draw(board.m_aPieces[FirstPos.getX()][FirstPos.getY()].Cheker, FirstPos.getX(), FirstPos.getY());
									Flag = 0;
									break;

								case 2:
									board.m_aPieces[FirstPos.getX()][FirstPos.getY()].m_bOccupied = false;
									board.m_aPieces[SecondPos.getX()][SecondPos.getY()].m_bOccupied = true;
									board.m_aPieces[SecondPos.getX()][SecondPos.getY()].Cheker = board.m_aPieces[FirstPos.getX()][FirstPos.getY()].Cheker;
									board.m_aPieces[SecondPos.getX()][SecondPos.getY()].Cheker.setCurPos(SecondPos.getX(), SecondPos.getY());
									show.draw(board.m_aPieces[FirstPos.getX()][FirstPos.getY()], FirstPos.getX(), FirstPos.getY());
									show.draw(board.m_aPieces[SecondPos.getX()][SecondPos.getY()].Cheker, SecondPos.getX(), SecondPos.getY());
									PlayerB.m_nLeftCheckers--;
									gameOver();
									Flag = 1;
									time_c(1);
									break;

								case 3: //游戏结束
									board.m_aPieces[SecondPos.getX()][SecondPos.getY()].m_bOccupied = true;
									gameOver();
									break;

								default:
									break;
								}
							}
						}
						else//轮到蓝方走棋
						{
							HWND temp = GetHWnd();
							MessageBox(temp, "please select another camp!", "WARNING", MB_OKCANCEL);
							click = true;
							break;
						}
					}
					//选中蓝方棋子
					else if (board.m_aPieces[FirstPos.getX()][FirstPos.getY()].m_bOccupied && board.m_aPieces[FirstPos.getX()][FirstPos.getY()].Cheker.getCamp()) {
						cout << "camp chosed " << board.m_aPieces[FirstPos.getX()][FirstPos.getY()].Cheker.getCamp() << endl;
						if (Flag)//轮到蓝方走棋
						{
							if(!click)//第一次点击
							{
								setlinecolor(BLUE);
								setlinestyle(PS_SOLID, 3);
								circle(FirstPos.getY()* (80 + FI) + PIECE / 2 + WO_, FirstPos.getX()* (80 + FI) + PIECE / 2 + LO_, 32);
							}
							else//第二次点击
							{
								//获取第二次鼠标位置和数组下标，调用move，根据返回值对应情况刷新显示
								SecondPos.setX(int((msg.y - LO_) / 80));
								SecondPos.setY(int((msg.x - WO_) / 80));

								int GetMoveResult = Move(FirstPos, SecondPos);
								cout << "case: blue " << GetMoveResult << endl;
								HWND temp = GetHWnd();
								switch (GetMoveResult)
								{
								case 0:// 移动到没有棋子的位置
									board.m_aPieces[FirstPos.getX()][FirstPos.getY()].m_bOccupied = false;
									board.m_aPieces[SecondPos.getX()][SecondPos.getY()].m_bOccupied = true;
									board.m_aPieces[SecondPos.getX()][SecondPos.getY()].Cheker = board.m_aPieces[FirstPos.getX()][FirstPos.getY()].Cheker;
									board.m_aPieces[SecondPos.getX()][SecondPos.getY()].Cheker.setCurPos(SecondPos.getX(), SecondPos.getY());
									show.draw(board.m_aPieces[FirstPos.getX()][FirstPos.getY()], FirstPos.getX(), FirstPos.getY());
									show.draw(board.m_aPieces[SecondPos.getX()][SecondPos.getY()].Cheker, SecondPos.getX(), SecondPos.getY());
									Flag = 0;
									time_c(1);
									break;

								case 1: //移动失败
									//将第一次选中位置重新显示，因为要刷掉标记；
									cout << "failed animal type" << board.m_aPieces[FirstPos.getY()][FirstPos.getX()].Cheker.getType() << endl;
									MessageBox(temp, "can't move here!", "WARNING", MB_OKCANCEL);
									show.draw(board.m_aPieces[FirstPos.getX()][FirstPos.getY()].Cheker, FirstPos.getX(), FirstPos.getY());
									Flag = 1;
									break;

								case 2: //吃掉对方一子
									board.m_aPieces[FirstPos.getX()][FirstPos.getY()].m_bOccupied = false;
									board.m_aPieces[SecondPos.getX()][SecondPos.getY()].m_bOccupied = true;
									board.m_aPieces[SecondPos.getX()][SecondPos.getY()].Cheker = board.m_aPieces[FirstPos.getX()][FirstPos.getY()].Cheker;
									board.m_aPieces[SecondPos.getX()][SecondPos.getY()].Cheker.setCurPos(SecondPos.getX(), SecondPos.getY());
									show.draw(board.m_aPieces[FirstPos.getX()][FirstPos.getY()], FirstPos.getX(), FirstPos.getY());
									show.draw(board.m_aPieces[SecondPos.getX()][SecondPos.getY()].Cheker, SecondPos.getX(), SecondPos.getY());
									PlayerA.m_nLeftCheckers--; 
									gameOver();
									Flag = 0;
									time_c(1);
									break;

								case 3: //游戏结束
									board.m_aPieces[SecondPos.getX()][SecondPos.getY()].m_bOccupied = true;
									gameOver();
									break;

								default:
									break;
								}
							}
						}
						else//轮到红方走棋
						{
							HWND temp = GetHWnd();
						    MessageBox(temp, "please select another camp!", "WARNING", MB_OKCANCEL);
							click = true;
							break;
						}
					}
					//选中没有棋子的地方
					else {
						HWND temp = GetHWnd();
						MessageBox(temp, "please select an animal first!", "WARNING", MB_OKCANCEL);
						click = true;
						break;
					}
				}
				else
				{
				//播放音乐功能
					if (msg.x > 5 && msg.y > 720 - 50 - 5 && msg.y < 720 - 5 && msg.x < 5 + 50)
					{
						if (music)
							mciSendString("close KISS", 0, 0, 0);
						else	
						{
							mciSendString("open ./music/Blow_Me_A_Kiss.mp3 alias KISS", 0, 0, 0);
							mciSendString("play KISS repeat", 0, 0, 0);
						}
						music = !music;
					}
				//切换头像功能
					else if ((msg.x > 80 && msg.y > 20 && msg.y < 20 + 70 && msg.x < 80 + 70))
					{
						IMAGE Profile;
						if (!f1)
							loadimage(&Profile, "./picture/PlayerB.jpg", PIG, PIG);
						else
							loadimage(&Profile, "./picture/PlayerA.jpg", PIG, PIG);
						putimage(80, 20, &Profile);
						f1 = !f1;
					}
					else if (msg.x > 960 - 80 - 70 && msg.y > 20 && msg.y < 20 + 70 && msg.x < 960 - 80)
					{
						IMAGE Profile;
						if(!f2)
							loadimage(&Profile, "./picture/PlayerA.jpg", PIG, PIG);
						else
							loadimage(&Profile, "./picture/PlayerB.jpg", PIG, PIG);
						putimage(960 - PIG_X - PIG, PIG_Y, &Profile);
						f2 = !f2;
					}
					cout << "mousehit is  not in board" << endl;
				}
				break;
			default:
				break;
			}
			}
		}
		time_c(0);
	}
}

	void gameOver()
	{
		
		if (board.m_aPieces[3][0].m_bOccupied||PlayerA.m_nLeftCheckers==0) //判断红方巢穴是否被占或者红方剩余棋子==0
		{
			printf("blue win\n");
			HWND temp = GetHWnd();
			MessageBox(temp, "BLUE win!!", "END", MB_OKCANCEL);
		}else if (board.m_aPieces[3][8].m_bOccupied||PlayerB.m_nLeftCheckers==0)//判断蓝方巢穴是否被占
		{
			printf("red win\n");
			HWND temp = GetHWnd();
			MessageBox(temp, "RED win!!", "END",MB_OKCANCEL);
		}
		return;
		
	}
