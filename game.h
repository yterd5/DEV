#define ROW 3//�궨������䳣��
#define COL 3
#include<stdio.h>
#include<time.h>
#include<stdlib.h>
void initboard(char board[ROW][COL]);//����
void display(char board[ROW][COL]);//����
void playermove(char board[ROW][COL]);//����
void computermove(char board[ROW][COL]);//����
//������Ϸ������״̬
//���Ӯ*
//����Ӯ@
//ƽ��Q
//����C
char iswin(char board[ROW][COL]);//����