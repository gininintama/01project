#include <stdio.h>
#pragma once
#include <graphics.h>
#include <iostream>
#include <iomanip>
#include <string>
#include <math.h>
#include <conio.h>
#include <mmsystem.h>
#pragma comment(lib,"winmm.lib")


#define RED_ 0
#define BUL_ 1
#define LO_ 125 		/*修改棋盘坐标*/
#define WO_ 150			/*修改棋盘坐标*/
#define PIG 70		/*头像尺寸*/
#define PIG_X 80	/*头像距离X*/
#define PIG_Y 20	/*头像距离Y*/

using namespace std;
int tab[9][7];
int board[9][7];
bool who = 1;	/*红蓝方标记*/

void time_c(int swp);	/*时钟*/

class click
{
public:
	int x_f, y_f; /*第一次点击坐标*/
	int x_s, y_s; /*第二次点击坐标*/
	bool flag = 0;/*0为第一次，1为第二次*/

	/*第一次点击坐标处理*/
	void conut_xy_1(int x, int y)
	{
		if (x < LO_ || x>80 * 9 + LO_ || y < WO_ || y>80 * 7 + WO_)
		{
			flag = 0;
			return;
		}
		x_f = (x - LO_) / 80;
		y_f = (y - WO_) / 80;
		if (tab[x_f][y_f] <= 100)	/*不合法则flag = 0*/
		{
			flag = 0;
			return;
		}
		if (isWho())				/*判断当前红蓝方，不合法则flag = 0*/
		{
			flag = 0;
			printf("wuxiao\n");		/*无效*/
			return;
		}
		flag = 1;
		setlinecolor(GREEN);
		setlinestyle(PS_SOLID, 3);
		circle(x_f * 80 + 35 + LO_, y_f * 80 + 35 + WO_, 32);		/*第一次点击为选中画圆*/
		printf("1[%d][%d]\n", x_f, y_f);
	}

	void conut_xy_2(int x, int y)
	{
		if (x < LO_ || x>80 * 9 + LO_ || y < WO_ || y>80 * 7 + WO_)
		{
			flag = 0;
			return;
		}
		x_s = (x - LO_) / 80;
		y_s = (y - WO_) / 80;
		if (tab[x_f][y_f] % 100 == 1)
		{
			printf("mouse[%d][%d]\n", x_f, y_f);
		}	
		else if(board[x_s][y_s] <= 70)
		{
			flag = 0;
			return;
		}
		
		flag = 0;
		printf("2[%d][%d]\n", x_s, y_s);	
		isWin();
		move();
		
	}

	void move() {
		int temp;
		if ((tab[x_f][y_f] % 100) == 6 || (tab[x_f][y_f] % 100) == 7)
		{
			if (tab[x_s][y_s]>100&&abs(tab[x_s][y_s] - tab[x_f][y_f]) < 10)
			{
				return ;
			}
			if ((y_f - 1) >= 0 && tab[x_f][y_f-1] == 70 && y_s < y_f &&x_f == x_s)
			{
				printf("up\n");
				if (tab[x_f][y_f - 1] && tab[x_f][y_f - 2])
				{
					if (tab[x_s][y_s] <= 100)
					{
						tab[x_s][y_s] = tab[x_f][y_f];
						tab[x_f][y_f] = board[x_f][y_f];

					}
					else if ((tab[x_f][y_f] % 100) > (tab[x_s][y_s] % 100))			/*大吃小*/
					{
						tab[x_s][y_s] = tab[x_f][y_f];
						tab[x_f][y_f] = board[x_f][y_f];
					}
					else if ((tab[x_f][y_f] % 100) == (tab[x_s][y_s] % 100))	/*同归于尽*/
					{
						tab[x_s][y_s] = board[x_s][y_s];
						tab[x_f][y_f] = board[x_f][y_f];
					}
					else
					{
						return;
					}
					turn();
					return;
				}
			}
			else if ((y_f + 1) < 7 && tab[x_f][y_f+1] == 70&& y_s> y_f && x_f==x_s)
			{
				printf("down\n");
				if (tab[x_f ][y_f+1] && tab[x_f][y_f+2])
				{
					if (tab[x_s][y_s] <= 100)
					{
						tab[x_s][y_s] = tab[x_f][y_f];
						tab[x_f][y_f] = board[x_f][y_f];

					}
					else if ((tab[x_f][y_f] % 100) > (tab[x_s][y_s] % 100))			/*大吃小*/
					{
						tab[x_s][y_s] = tab[x_f][y_f];
						tab[x_f][y_f] = board[x_f][y_f];
					}
					else if ((tab[x_f][y_f] % 100) == (tab[x_s][y_s] % 100))	/*同归于尽*/
					{
						tab[x_s][y_s] = board[x_s][y_s];
						tab[x_f][y_f] = board[x_f][y_f];
					}
					else
					{
						return;
					}
					turn();
					return;
				}
			}
			else if ((x_f + 1) < 9 && tab[x_f + 1][y_f] == 70 && y_f == y_s)
			{
				printf("right\n");
				if (tab[x_f + 1][y_f]==70 && tab[x_f + 2][y_f]==70 && tab[x_f + 3][y_f]==70)
				{
					if (tab[x_s][y_s] <= 100)
					{
						tab[x_s][y_s] = tab[x_f][y_f];
						tab[x_f][y_f] = board[x_f][y_f];

					}
					else if ((tab[x_f][y_f] % 100) > (tab[x_s][y_s] % 100))			/*大吃小*/
					{
						tab[x_s][y_s] = tab[x_f][y_f];
						tab[x_f][y_f] = board[x_f][y_f];
					}
					else if ((tab[x_f][y_f] % 100) == (tab[x_s][y_s] % 100))	/*同归于尽*/
					{
						tab[x_s][y_s] = board[x_s][y_s];
						tab[x_f][y_f] = board[x_f][y_f];
					}
					else
					{
						return;
					}
					turn();
					return;
				}
			}
			else if ((x_f - 1) >=0 && tab[x_f - 1][y_f] == 70 && y_f == y_s)
			{
				printf("left\n");
				if (tab[x_f - 1][y_f]==70&& tab[x_f - 2][y_f]==70 && tab[x_f - 3][y_f]==70 )
				{
					if (tab[x_s][y_s] <= 100)
					{
						tab[x_s][y_s] = tab[x_f][y_f];
						tab[x_f][y_f] = board[x_f][y_f];
						
					}
					else if ((tab[x_f][y_f] % 100) > (tab[x_s][y_s] % 100))			/*大吃小*/
					{
						tab[x_s][y_s] = tab[x_f][y_f];
						tab[x_f][y_f] = board[x_f][y_f];						
					}
					else if ((tab[x_f][y_f] % 100) == (tab[x_s][y_s] % 100))	/*同归于尽*/
					{
						tab[x_s][y_s] = board[x_s][y_s];
						tab[x_f][y_f] = board[x_f][y_f];
					}
					else
					{
						return;
					}
					turn();
					return;
				}
			}

		}
		if (abs(x_f - x_s) == 1 && y_f == y_s) 
		{
			if (working() == -1)
			{
				return ;
			}
			/*这部为规则部分，暂时还没写
			temp = tab[x_s][y_s];
			tab[x_s][y_s] = tab[x_f][y_f];
			tab[x_f][y_f] = temp;
			/*************************/
		}
		else if (abs(y_f - y_s) == 1 && x_f == x_s) {
			if (working() == -1)
			{
				return ;
			}
		}
		else
		{
			return;
		}
		turn();
	}

	/*交换棋权*/
	void turn()
	{		
		if (who) {
			setlinecolor(BLUE);
			setfillcolor(BLUE);
			fillcircle(980 / 2, PIG_Y+30, 30);
		}
		else
		{
			setlinecolor(RED);
			setfillcolor(RED);
			fillcircle(980/2, PIG_Y+30 , 30);
		}
		who = !who;
		time_c(1);
	}

	bool isWho()	/*根据数值判断是哪方的棋子*/
	{
		if (who) 
		{
			if (tab[x_f][y_f] > 100 && tab[x_f][y_f] < 120)
			{
				return 0;
			}			
		}
		else 
		{
			if (tab[x_f][y_f] > 200 && tab[x_f][y_f] < 220)
			{
				return 0;
			}
		}
		return 1;
	}

	int working()			/*走棋规则*/
	{
		if (tab[x_s][y_s]<=100)
		{
			tab[x_s][y_s] = tab[x_f][y_f];
			tab[x_f][y_f] = board[x_f][y_f];
			return 1;
		}
		if (abs(tab[x_s][y_s] - tab[x_f][y_f]) < 10)		/*判断是否为同类*/
		{
			return -1;
		}
		

		if ((tab[x_f][y_f] % 100) == 1 && (tab[x_s][y_s] % 100) == 8&& board[x_f][y_f]!=70)/*鼠吃大象,判断老鼠是否在河中*/
		{
			tab[x_s][y_s] = tab[x_f][y_f];
			tab[x_f][y_f] = board[x_f][y_f];
			return 1;
		}
		if((tab[x_f][y_f] % 100) ==8 && (tab[x_s][y_s] % 100) == 1)		/*象不能吃鼠*/
		{
			return -1;
		}
		if ((tab[x_f][y_f] % 100) > (tab[x_s][y_s] % 100))			/*大吃小*/
		{
			tab[x_s][y_s] = tab[x_f][y_f];
			tab[x_f][y_f] = board[x_f][y_f];
			return 1;
		}
		else if (board[x_s][y_s]==90&&who == 1)
		{
			printf("red trap\n");
			tab[x_s][y_s] = tab[x_f][y_f];
			tab[x_f][y_f] = board[x_f][y_f];
			return 1;
		}
		else if (board[x_s][y_s] == 80 && who == 0)
		{
			printf("blue trap\n");
			tab[x_s][y_s] = tab[x_f][y_f];
			tab[x_f][y_f] = board[x_f][y_f];
			return 1;
		}
		else if ((tab[x_f][y_f] % 100) == (tab[x_s][y_s] % 100))	/*同归于尽*/
		{
			tab[x_s][y_s] = board[x_s][y_s];
			tab[x_f][y_f] = board[x_f][y_f];
			return 1;
		}
		else
		{
			printf("quexiao \n");
			return -1;
		}
	}

	int isWin()		/*判断是否胜利*/
	{
		if (who == 1 && tab[x_s][y_s] == 81)
		{
			printf("red win\n");
			HWND temp = GetHWnd();
			MessageBox(temp, "RED win!!", "END",MB_OKCANCEL);
		}
		if (who == 0 && tab[x_s][y_s] == 91)
		{
			printf("blue win\n");
			HWND temp = GetHWnd();
			MessageBox(temp, "BLUE win!!", "END", MB_OKCANCEL);
		}

		return 0;
	}
private:
	
};

void BGM();
void closeBGM();
void Inithd();
void InitNum();
void ShowNum();
void Init(); 
void LoadBk(IMAGE *bk);
void LoadChess(int x, int y, int no);
void PrintChess();
void BeginGame();
void InitPlayer(int player);	/*初始化音乐*/


