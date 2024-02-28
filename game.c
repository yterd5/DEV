#define _CRT_SECURE_NO_WARNINGS 1
#include"game.h"
void initboard(char board[ROW][COL]) {
	int i, j;
	for (i = 0; i < ROW; i++) {
		for (j = 0; j < COL; j++) {
			board[i][j] = ' ';//进行空白初始化
		}
	}
}
void display(char board[ROW][COL])//打印棋盘
{
	int i, j;
	for (i = 0; i < ROW; i++) {
		
		for (j = 0; j < COL; j++) {
			printf(" %c ", board[i][j]);//打印数据行
			if (j < COL - 1) {//中间分割行
				printf("|");
			}
		}
		printf("\n");
		if (i<ROW-1) {//横向分割行//自己的想法while（i）借于一次之后i恒为真，一般不用
			//判断或放在开头（i>0）
			for (j = 0; j < COL; j++) {//因为下次循环j依然会被初始化
				printf("---");
				if (j < COL - 1) {
					printf("|");
				}
			}
		}
		printf("\n");
	}
}
void playermove(char board[ROW][COL])
{
	int x = 0, y = 0;
	printf("玩家先手\n");
	printf("请输入落子坐标:\n");
	while (1) {
		scanf("%d,%d", &x, &y);
		//先判断x，y坐标的合法性
		if (x >= 1 && x <= ROW && y >= 1 && y <= COL) {
			if (board[x - 1][y - 1] == ' ') {
				board[x - 1][y - 1] = '*';
				break;
			}
			else {
				printf("该坐标被占用\n");
				continue;
			}
		}
		else {
			printf("落子错误,请重新输入:");
		}
	}
}
void computermove(char board[ROW][COL])
{
	int x = 0, y = 0;
	printf("电脑后手\n");
	while (1) {
		x = rand() % ROW;
		y = rand() % COL;
		//判断位置是否占用//x与y一定具有合法性，取模3致使它始终处于0—2的范围
		if (board[x][y] == ' ') {
			printf("电脑落子坐标:%d,%d\n", x + 1, y + 1);
			board[x][y] = '@';
			break;
		}
	}
}
int isfull(char board[ROW][COL])
{
	int i, j;
	for (i = 0; i < ROW; i++) {
		for (j = 0; j < COL; j++) {
			if (board[i][j] == ' ') {//判断有效性
				return 0;
			}
		}
	}
	return 1;//循环结束仍没有返回证明没有空余
}
char iswin(char board[ROW][COL])
{
	int i;
	for (i = 0; i < ROW; i++) {
		if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] != ' ') {//横判断
			return board[i][0];
		}
		
	}
	for (i = 0; i < COL; i++) {
		if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[0][i] != ' ') {//竖判断
			return board[0][i];
		}
	}
	if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] != ' ') {//顺斜判断\
		return board[0][0];
	}
	if (board[2][0] == board[1][1] && board[1][1] == board[0][2] && board[2][0] != ' ') {//逆斜判断/
		return board[2][0];
	}
	if (1 == isfull(board)) {//判断是否平局
		return 'Q';
	}
	return 'C';//全部否则继续
}