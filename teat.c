#define _CRT_SECURE_NO_WARNINGS 1
#include"game.h"
void game()
{
	int ret = 0;
	char board[ROW][COL] = { 0 };
	initboard(board);
	display(board);
	while (1) {
		//�������
		playermove(board);
		display(board);
		//�ж���Ӯ����
		ret = iswin(board);//����һ���ж�������ֵ
		if (ret != 'C') {//����ֵ���ǡ�������������
			break;
		}
		//���Ժ���
		computermove(board);
		display(board);
		//�ж���Ӯ����
		ret = iswin(board);//����һ���ж�������ֵ
		if (ret != 'C') {//����ֵ���ǡ�������������
			break;
		}
	}
	if (ret == '*') {
		printf("���Ӯ\n");
	}
	else if (ret == '@') {
		printf("����Ӯ\n");
	}
	else {
		printf("ƽ��\n");
	}
}
void menu()
{
	printf("********************\n");
	printf("***1.play  0.exit***\n");//��ӡ��ʼ����
	printf("********************\n");
}
void teat()//��ʼ����
{
	int n = 0;
	srand((unsigned int)time(NULL));//ʱ����������ֵ
	do {//����ִ��һ��
		
		menu();
		printf("����������:");
		scanf("%d", &n);
		switch (n)//�жϽ���
		{
		case 1:
			printf("������\n");
			game();//������Ϸ
			break;
		case 0:
			printf("����\n");
			break;
	    default:
			printf("ѡ�����\n");
		}
	} while (n);//nΪ�������ִ��
}
int main()
{
	teat();
	return 0;
}