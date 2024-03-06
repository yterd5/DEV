#define _CRT_SECURE_NO_WARNINGS 1
#include"game.h"
void game()
{
	int ret = 0;
	char board[ROW][COL] = { 0 };
	initboard(board);
	display(board);
	while (1) {
		//玩家先手
		playermove(board);
		display(board);
		//判断输赢函数
		ret = iswin(board);//返回一个判断跳出的值
		if (ret != 'C') {//返回值不是‘继续’则跳出
			break;
		}
		//电脑后手
		computermove(board);
		display(board);
		//判断输赢函数
		ret = iswin(board);//返回一个判断跳出的值
		if (ret != 'C') {//返回值不是‘继续’则跳出
			break;
		}
	}
	if (ret == '*') {
		printf("玩家赢\n");
	}
	else if (ret == '@') {
		printf("电脑赢\n");
	}
	else {
		printf("平局\n");
	}
}
void menu()
{
	printf("********************\n");
	printf("***1.play  0.exit***\n");//打印开始界面
	printf("********************\n");
}
void teat()//开始函数
{
	int n = 0;
	srand((unsigned int)time(NULL));//时间戳生成随机值
	do {//至少执行一次
		
		menu();
		printf("请输入数字:");
		scanf("%d", &n);
		switch (n)//判断进行
		{
		case 1:
			printf("三子棋\n");
			game();//进入游戏
			break;
		case 0:
			printf("结束\n");
			break;
	    default:
			printf("选择出错\n");
		}
	} while (n);//n为非零继续执行
}
int main()
{
	teat();
	return 0;
}
