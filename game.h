#define ROW 3//宏定义变量变常量
#define COL 3
#include<stdio.h>
#include<time.h>
#include<stdlib.h>
void initboard(char board[ROW][COL]);//声明
void display(char board[ROW][COL]);//声明
void playermove(char board[ROW][COL]);//声明
void computermove(char board[ROW][COL]);//声明
//返回游戏的四种状态
//玩家赢*
//电脑赢@
//平局Q
//继续C
char iswin(char board[ROW][COL]);//声明