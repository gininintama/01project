#pragma once

class CheckerModel;
class ChessPiecesModel;
class ChessBoardModel;
class PlayerModel;
int clickConunt(int x, int y, int* i, int* j);			/*�������ת������*/

/**
 * @brief draw:       �������ӣ����ݻ��ƶ�������Խ������Ƴ���Ӧ�Ķ���
 *
 * @prama T:          TΪҪ���Ƶ�Ŀ�����
 */



class drawView
{
public:
	void draw(CheckerModel& checker, int x, int y);			/*��ʾָ��һ�����ӣ�x��y������������[x][y]��λ��*/
	void draw(ChessPiecesModel& pieces, int x, int y);		/*��ʾָ��һ�����̿飬x��y������������[x][y]��λ��*/
	void draw(ChessBoardModel& board);						/*����*/
	void draw(PlayerModel& player);						/*��ʾ���ͷ�������*/
	void initPieces();								/*��ʼ������*/
	void initChess();								/*��ʼ������*/

};
/*draw()�����ƶ�����ʾͼƬ���������
ChessPiecesModel��
private:
	int m_nHeight;
	int m_nWidth;

public:
	bool m_bOccupied;
	int m_nChekerKind;
	int m_nLandForm;

	bool setHeight(int height);
	bool setWidth(int width);
	int  getHeight();
	int  getWidth();
	1.������ֻ���ʼ��
draw������һ�λ�һ������/���ӣ�

ChessBoardModel �е�������ô����

readyMove�������صĽṹ��
����һ���ṹ��ָ�룬ָ������ƶ���λ������
Pos* readyMove(Pos curPos, const int& len, const int& checkerType);
���ص�Pos*ֻ��1�����꣬ʵ���Ͽ���0~4�������

*/
