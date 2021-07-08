#include "head.h"


int main()
{
	IMAGE bk; //����ͼƬ��Ϣ	
	Init();
	LoadBk(&bk);
	BGM();
	InitPlayer(1);
	InitPlayer(0);
	Inithd();
	BeginGame();


	closegraph();
	return 0;
}

void BGM()
{	
	mciSendString("open ./music/Blow_Me_A_Kiss.mp3 alias KISS",0,0,0);
	mciSendString("play KISS repeat", 0, 0, 0);

}	  /*��������*/

void closeBGM()	/*�ر�����*/
{
	mciSendString("close KISS", 0, 0, 0);
}

void time_c(int swp)		/*1Ϊ���ã��ڽ�����Ȩʱ���ã�0Ϊ����ʱ��*/
{
	static int clock = 40000000;	/*�����Լ��ļ������*/
	static int sec = 30;			/*��*/
	char str[30];
	clock++;						/*ÿ����һ�ξ�+1���˹�����*/
	if(swp)
		clock = 0;
	if (clock > 50000000)			/*���ۼӵ�5000000Ϊһ��*/
	{
		clock = 0;
		sec--;
		sprintf_s(str, "ʣ��ʱ�䣺%d", sec);
		if (sec < 0)
		{	
			sec = -2;
			sprintf_s(str, "ʱ�䣺  ����",NULL);
		}
		setfillcolor(LIGHTMAGENTA);
		solidrectangle(300, 40, 420, 60);
		settextstyle(20, 0, "����");
		setbkmode(TRANSPARENT);
		outtextxy(300, 40, str);

	}
	if (swp)
	{
		sec = 30;
		clock = 40000000;
	}
}

void Inithd()
{
	HWND title = GetHWnd();
	SetWindowText(title, "������1.0V");
}

void Init()
{
	//HWND title = GetHWnd();
	initgraph(960,720,SHOWCONSOLE);
	setbkcolor(WHITE);
	cleardevice();
	//SetWindowText(title,"������1.0V");
	InitNum();	
}
void InitNum()
{
	for (int i = 0; i < 9 ; i ++)
	{
		for (int j = 0; j < 7 ; j ++) {
			tab[i][j]=100;
			board[i][j] = 100;
		}
	}
	
	//�췽
	tab[2][6] =101 ;
	tab[1][1] =102 ;
	tab[1][5] =103 ;
	tab[2][2] =104 ;
	tab[2][4] =105 ;
	tab[0][0] =106 ;
	tab[0][6] =107 ;
	tab[2][0] =108 ;
	tab[0][3] =91 ;	//91�췽��Ѩ
	tab[0][2] =90 ;	//90�췽����
	tab[0][4] =90 ;	
	tab[1][3] =90 ;
	
	tab[3][1] =70 ;	//100Ϊ����
	tab[3][2] =70 ;	//100Ϊ����
	tab[3][4] =70 ;
	tab[3][5] =70 ;	//100Ϊ����
	tab[4][1] =70 ;	//100Ϊ����
	tab[4][2] =70 ;	//100Ϊ����
	tab[4][4] =70 ;
	tab[4][5] =70 ;	//70Ϊ����
	tab[5][1] =70 ;	//70Ϊ����
	tab[5][2] =70 ;	//70Ϊ����
	tab[5][4] =70 ;
	tab[5][5] =70 ;	//70Ϊ����

	//����
	tab[6][0] =201 ;
	tab[7][5] =202 ;
	tab[7][1] =203 ;
	tab[6][4] =204 ;
	tab[6][2] =205 ;
	tab[8][6] =206 ;
	tab[8][0] =207 ;
	tab[6][6] =208 ;
	tab[8][3] =81 ;	//������Ѩ
	tab[8][2] =80 ;	//��������
	tab[8][4] =80 ;	
	tab[7][3] =80 ;

	board[3][1] = 70;	//100Ϊ����
	board[3][2] = 70;	//100Ϊ����
	board[3][4] = 70;
	board[3][5] = 70;	//100Ϊ����
	board[4][1] = 70;	//100Ϊ����
	board[4][2] = 70;	//100Ϊ����
	board[4][4] = 70;
	board[4][5] = 70;	//70Ϊ����
	board[5][1] = 70;	//70Ϊ����
	board[5][2] = 70;	//70Ϊ����
	board[5][4] = 70;
	board[5][5] = 70;	//70Ϊ����

	board[0][3] = 91;	//111�췽��Ѩ
	board[0][2] = 90;	//110�췽����
	board[0][4] = 90;
	board[1][3] = 90;

	board[8][3] = 81;	//������Ѩ
	board[8][2] = 80;	//��������
	board[8][4] = 80;
	board[7][3] = 80;

	ShowNum();
}

/*��ӡ����*/
void ShowNum()
{
	for (int i = 0; i < 7; i++)
	{
		for (int j = 0; j < 9; j++) {
			printf("%d\t", tab[j][i]);
		}
		printf("\n");
	}
	printf("\n");
}

void LoadBk(IMAGE *bk)
{
	loadimage(bk, "./img/bk3.jpg", 960, 720);
	putimage(0, 0, bk);
	setfillcolor(RED);
	fillcircle(980 / 2, PIG_Y + 30, 30);

	IMAGE musci;
	loadimage(&musci, "./img/bgm1.jpg", 50, 50);
	putimage(5, 720 - 50 - 5, &musci);
}

void LoadChess(int x, int y,int no)
{
	IMAGE img;
	char str[40];
	sprintf_s(str, "./img/%d.jpg", no);
	//cout << str << endl;
	loadimage(&img, str, 70, 70);
	putimage(x, y, &img);

}

/*��ʾȫ������*/
void PrintChess()
{
	for (int i = LO_,a=0; i < 9*80+ LO_; i+=80,a++)
	{
		for (int j = WO_,b=0; j < 7 * 80+ WO_; j += 80,b++) {
			LoadChess(i, j, tab[a][b]);		
			//LoadChess(i, j, board[a][b]);
			if (tab[a][b] > 100 && tab[a][b] < 110)			/*����ɫ��*/
			{
				setlinecolor(RED);
				setlinestyle(PS_SOLID, 3);
				rectangle(i, j, i + 70, j + 70);

			}
			else if (tab[a][b] > 200 && tab[a][b] < 210)
			{
				setlinecolor(BLUE);
				setlinestyle(PS_SOLID, 3);
				rectangle(i, j, i + 70, j + 70);
			}
			else
			{
				setlinecolor(BROWN);
				setlinestyle(PS_SOLID, 1);
				rectangle(i, j, i + 70, j + 70);
			}

			
		}
	}

	ShowNum();
}

void BeginGame()
{
	click mouse;
	bool music=true;
	PrintChess();
	while (1) {

		if (MouseHit())
		{
			MOUSEMSG msg = GetMouseMsg();			
			switch (msg.uMsg)
			{
			case WM_LBUTTONDOWN:
			case WM_RBUTTONDOWN:
				//printf("right (%d,%d)\n", msg.x, msg.y);
				if (msg.x > 5 && msg.y > 720 - 50 - 5 && msg.y < 720 - 5 && msg.x < 5 + 50)		/*����ͼ��λ��*/
				{
					if(music)						/*musicΪ�Ƿ񲥷�����*/
						closeBGM();
					else
						BGM();
					music = !music;
				}

				if (mouse.flag == 0) {
					mouse.conut_xy_1(msg.x, msg.y);					
				}
				else 
				{
					mouse.conut_xy_2(msg.x, msg.y);					
					PrintChess();
				}
				break;
			}
			
			

		}
		
		time_c(0);
	}

}

void InitPlayer(int player)
{
	IMAGE Profile;
	int i;	
	char p1[30] = "./pig/p1.jpg";
	char p2[30] = "./pig/p2.jpg";
	if (player == 1) {
		loadimage(&Profile, p1, PIG, PIG);
		putimage(PIG_X, PIG_Y, &Profile);
		setlinecolor(RED);
		setlinestyle(PS_DASH, 2);
		rectangle(PIG_X, PIG_Y, PIG_X + PIG, PIG_Y + PIG);
		settextcolor(RED);
		settextstyle(20,0,"����");
		setbkmode(TRANSPARENT);
		outtextxy(PIG_X, PIG_Y + PIG, "WJ");
	}
	else
	{
		loadimage(&Profile, p2, PIG, PIG);
		putimage(960 - PIG_X - PIG, PIG_Y, &Profile);
		setlinecolor(BLUE);
		setlinestyle(PS_DASH, 2);
		rectangle(960 - PIG_X, PIG_Y, 960 - PIG_X - PIG, PIG_Y + PIG);
		settextcolor(BLUE);
		settextstyle(20, 0, "����");
		setbkmode(TRANSPARENT);
		outtextxy(960 - PIG_X - PIG, PIG_Y + PIG, "�������");
	}
}

