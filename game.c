#define _CRT_SECURE_NO_WARNINGS 1
#include"game.h"
void initboard(char board[ROW][COL]) {
	int i, j;
	for (i = 0; i < ROW; i++) {
		for (j = 0; j < COL; j++) {
			board[i][j] = ' ';//���пհ׳�ʼ��
		}
	}
}
void display(char board[ROW][COL])//��ӡ����
{
	int i, j;
	for (i = 0; i < ROW; i++) {
		
		for (j = 0; j < COL; j++) {
			printf(" %c ", board[i][j]);//��ӡ������
			if (j < COL - 1) {//�м�ָ���
				printf("|");
			}
		}
		printf("\n");
		if (i<ROW-1) {//����ָ���//�Լ����뷨while��i������һ��֮��i��Ϊ�棬һ�㲻��
			//�жϻ���ڿ�ͷ��i>0��
			for (j = 0; j < COL; j++) {//��Ϊ�´�ѭ��j��Ȼ�ᱻ��ʼ��
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
	printf("�������\n");
	printf("��������������:\n");
	while (1) {
		scanf("%d,%d", &x, &y);
		//���ж�x��y����ĺϷ���
		if (x >= 1 && x <= ROW && y >= 1 && y <= COL) {
			if (board[x - 1][y - 1] == ' ') {
				board[x - 1][y - 1] = '*';
				break;
			}
			else {
				printf("�����걻ռ��\n");
				continue;
			}
		}
		else {
			printf("���Ӵ���,����������:");
		}
	}
}
void computermove(char board[ROW][COL])
{
	int x = 0, y = 0;
	printf("���Ժ���\n");
	while (1) {
		x = rand() % ROW;
		y = rand() % COL;
		//�ж�λ���Ƿ�ռ��//x��yһ�����кϷ��ԣ�ȡģ3��ʹ��ʼ�մ���0��2�ķ�Χ
		if (board[x][y] == ' ') {
			printf("������������:%d,%d\n", x + 1, y + 1);
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
			if (board[i][j] == ' ') {//�ж���Ч��
				return 0;
			}
		}
	}
	return 1;//ѭ��������û�з���֤��û�п���
}
char iswin(char board[ROW][COL])
{
	int i;
	for (i = 0; i < ROW; i++) {
		if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] != ' ') {//���ж�
			return board[i][0];
		}
		
	}
	for (i = 0; i < COL; i++) {
		if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[0][i] != ' ') {//���ж�
			return board[0][i];
		}
	}
	if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] != ' ') {//˳б�ж�\
		return board[0][0];
	}
	if (board[2][0] == board[1][1] && board[1][1] == board[0][2] && board[2][0] != ' ') {//��б�ж�/
		return board[2][0];
	}
	if (1 == isfull(board)) {//�ж��Ƿ�ƽ��
		return 'Q';
	}
	return 'C';//ȫ���������
}