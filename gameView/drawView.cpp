#include "../gameView/drawView.h"
#include "../gameModel/ChessBoardModel.h"
#include "../gameModel/PlayerModel.h"
#include "../gameModel/ChessPiecesModel.h"
#include"../common.h"
#include <graphics.h>
#include <conio.h>
#include <easyx.h>

#define WO_ 100		/**/
#define LO_ 120		/**/
#define PIECE 80	/*格子尺寸*/
#define FI 5		/*格子距离*/
#define PIG 70		/*头像尺寸*/
#define PIG_X 80	/*头像距离X*/
#define PIG_Y 20	/*头像距离Y*/

void loadmsg(IMAGE& bk, int type, int skin, int camp);	/*导入图片信息*/


void drawView::draw(ChessBoardModel& board)
{

	initgraph(board.getHeight(), board.getWidth(), SHOWCONSOLE);
	setbkcolor(WHITE);
	cleardevice();
	IMAGE bk; //背景图片信息
	loadimage(&bk, _T("./picture/bk3.jpg"), board.getHeight(), board.getWidth());
	putimage(0, 0, &bk);
	setlinecolor(BROWN);
	setlinestyle(PS_SOLID, 2);
	setfillcolor(BROWN);
	fillrectangle(WO_ - FI, LO_ - FI, WO_ + 9 * (PIECE + FI), LO_ + 7 * (PIECE + FI));

	IMAGE musci;
	loadimage(&musci, "./picture/bgm1.jpg", 50, 50);
	putimage(5, 720 - 50 - 5, &musci);
}

void drawView::draw(PlayerModel& player)
{
	IMAGE Profile; //背景图片信息
	string path = player.getProfile();
	char str[40];
	int i;
	for (i = 0; i < path.length(); i++)
		str[i] = path[i];
	str[i] = '\0';
	//printf("%s\n", str);
	if (player.getCmap() == 1) {
		loadimage(&Profile, str, PIG, PIG);
		putimage(PIG_X, PIG_Y, &Profile);
		setlinecolor(RED);
		setlinestyle(PS_DASH, 2);
		rectangle(PIG_X, PIG_Y, PIG_X + PIG, PIG_Y + PIG);
		settextcolor(RED);
		outtextxy(PIG_X, PIG_Y + PIG, "PlayerA");
	}
	else
	{
		loadimage(&Profile, str, PIG, PIG);
		putimage(960 - PIG_X - PIG, PIG_Y, &Profile);
		setlinecolor(BLUE);
		setlinestyle(PS_DASH, 2);
		rectangle(960 - PIG_X, PIG_Y, 960 - PIG_X - PIG, PIG_Y + PIG);
		settextcolor(BLUE);
		outtextxy(960 - PIG_X - PIG, PIG_Y + PIG, "PlayerB");
	}
}

void drawView::draw(ChessPiecesModel& pieces, int y, int x)
{
	IMAGE piece;
	string str;
	int i = 0;
	char path[30];
	printf("%d", pieces.m_nLandForm);
	switch (pieces.m_nLandForm)
	{
	case 0:/*陆地*/
		//strcpy(path,"./picture/glass.jpg");
		str = "./picture/glass.jpg";
		break;
	case 1:/*河*/
		//strcpy(path, "./picture/river.jpg");
		str = "./picture/river.jpg";
		break;
	case 2:/*红陷阱*/
		//strcpy(path, "./picture/l_trap.jpg");
		str = "./picture/l_trap.jpg";
		break;
	case 3:
		str = "./picture/r_trap.jpg";
		break;
	case 4:/*兽穴*/
		//strcpy(path, "./picture/l_cave.jpeg");
		str = "./picture/l_cave.jpeg";
		break;
	case 5:
		str = "./picture/r_cave.jpeg";
		break;
	default:
		return;
		break;
	}
	for (i = 0; i < str.length(); i++)
		path[i] = str[i];
	path[i] = '\0';
	//printf("%s\n", path);
	loadimage(&piece, path, PIECE, PIECE);
	putimage(WO_ + x * (PIECE + FI), LO_ + y * (PIECE + FI), &piece);
}

void drawView::draw(CheckerModel& checker, int y, int x)
{
	IMAGE model;
	int type;		/*棋子类型：暂定 1鼠...........8象*/
	int camp;		/*玩家阵营：暂定 1红2蓝*/
	int skin = 0;	/*默认原始皮肤*/
	char path[30];
	printf("camp:%d,type:%d\n", checker.getCamp(), checker.getType());
	if (checker.getCamp()==0)
	{
		camp = 1;
	}
	else
	{
		camp = 2;
	}
	type = checker.getType();
	sprintf_s(path, "./picture/%d%d%d.jpg", camp, skin, type);
	printf("%s\n", path);
	loadimage(&model, path, PIECE, PIECE);
	putimage(WO_ + x * (PIECE + FI), LO_ + y * (PIECE + FI), &model);

}

void drawView::initPieces()
{
	IMAGE glass;
	IMAGE river;
	IMAGE trap;
	IMAGE cave;
	char path_glass[30] = "./picture/glass.jpg";
	char path_river[30] = "./picture/river.jpg";
	char path_trap[30] = "./picture/l_trap.jpg";
	char path_cave[30] = "./picture/l_cave.jpeg";
	loadimage(&glass, path_glass, PIECE, PIECE);
	loadimage(&river, path_river, PIECE, PIECE);
	loadimage(&trap, path_trap, PIECE, PIECE);
	loadimage(&cave, path_cave, PIECE, PIECE);

	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 7; j++)
		{
			putimage(WO_ + i * (PIECE + FI), LO_ + j * (PIECE + FI), &glass);
		}
	}

	for (int i = 3; i < 6; i++)
	{
		for (int j = 1; j < 6; j++)
		{
			if (j == 3)
				continue;
			putimage(WO_ + i * (PIECE + FI), LO_ + j * (PIECE + FI), &river);
		}

	}
	putimage(WO_ + 0 * (PIECE + FI), LO_ + 3 * (PIECE + FI), &cave);
	putimage(WO_ + 8 * (PIECE + FI), LO_ + 3 * (PIECE + FI), &cave);

	putimage(WO_ + 0 * (PIECE + FI), LO_ + 2 * (PIECE + FI), &trap);
	putimage(WO_ + 0 * (PIECE + FI), LO_ + 4 * (PIECE + FI), &trap);
	putimage(WO_ + 1 * (PIECE + FI), LO_ + 3 * (PIECE + FI), &trap);
	putimage(WO_ + 7 * (PIECE + FI), LO_ + 3 * (PIECE + FI), &trap);
	putimage(WO_ + 8 * (PIECE + FI), LO_ + 2 * (PIECE + FI), &trap);
	putimage(WO_ + 8 * (PIECE + FI), LO_ + 4 * (PIECE + FI), &trap);
}

void drawView::initChess()
{
	IMAGE piece;
	/**/
	loadmsg(piece, 1, 0, 1);
	putimage(WO_ + 2 * (PIECE + FI), LO_ + 6 * (PIECE + FI), &piece);
	loadmsg(piece, 1, 0, 2);
	putimage(WO_ + 1 * (PIECE + FI), LO_ + 1 * (PIECE + FI), &piece);
	loadmsg(piece, 1, 0, 3);
	putimage(WO_ + 1 * (PIECE + FI), LO_ + FI * (PIECE + FI), &piece);
	loadmsg(piece, 1, 0, 4);
	putimage(WO_ + 2 * (PIECE + FI), LO_ + 2 * (PIECE + FI), &piece);
	loadmsg(piece, 1, 0, 5);
	putimage(WO_ + 2 * (PIECE + FI), LO_ + 4 * (PIECE + FI), &piece);
	loadmsg(piece, 1, 0, 6);
	putimage(WO_ + 0 * (PIECE + FI), LO_ + 0 * (PIECE + FI), &piece);
	loadmsg(piece, 1, 0, 7);
	putimage(WO_ + 0 * (PIECE + FI), LO_ + 6 * (PIECE + FI), &piece);
	loadmsg(piece, 1, 0, 8);
	putimage(WO_ + 2 * (PIECE + FI), LO_ + 0 * (PIECE + FI), &piece);

	/**/
	loadmsg(piece, 2, 0, 1);
	putimage(WO_ + 6 * (PIECE + FI), LO_ + 0 * (PIECE + FI), &piece);
	loadmsg(piece, 2, 0, 2);
	putimage(WO_ + 7 * (PIECE + FI), LO_ + FI * (PIECE + FI), &piece);
	loadmsg(piece, 2, 0, 3);
	putimage(WO_ + 7 * (PIECE + FI), LO_ + 1 * (PIECE + FI), &piece);
	loadmsg(piece, 2, 0, 4);
	putimage(WO_ + 6 * (PIECE + FI), LO_ + 4 * (PIECE + FI), &piece);
	loadmsg(piece, 2, 0, 5);
	putimage(WO_ + 6 * (PIECE + FI), LO_ + 2 * (PIECE + FI), &piece);
	loadmsg(piece, 2, 0, 6);
	putimage(WO_ + 8 * (PIECE + FI), LO_ + 6 * (PIECE + FI), &piece);
	loadmsg(piece, 2, 0, 7);
	putimage(WO_ + 8 * (PIECE + FI), LO_ + 0 * (PIECE + FI), &piece);
	loadmsg(piece, 2, 0, 8);
	putimage(WO_ + 6 * (PIECE + FI), LO_ + 6 * (PIECE + FI), &piece);

}

void loadmsg(IMAGE& model, int camp, int skin, int type)
{
	char path[30];
	sprintf_s(path, "./picture/%d%d%d.jpg", camp, skin, type);
	printf("%s\n", path);
	loadimage(&model, path, PIECE, PIECE);
}


/*返回-1	则说明x,y不在棋盘范围内
  返回1		则代表计算成功*/
int clickConunt(int x, int y, int* i, int* j)
{
	if (x < WO_ || x>WO_ + 9 * PIECE)
	{
		//printf("x not in board\n");
		return -1;
	}
	if (y< LO_ || y>LO_ + 7 * PIECE)
	{
		//printf("y not in board\n");
		return -1;
	}


	*i = (x - WO_) / PIECE;
	*j = (y - LO_) / PIECE;
	return 1;
}
