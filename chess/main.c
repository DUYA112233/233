#include "../chess/init.h"

int main()
{
	int choice;
	Sleep(1000);
	system("cls");
	system("color 07");
	printf("想玩啥棋？\n\n1.五子棋\n2.中国象棋\n\n");
	scanf("%d", &choice);
	if (choice == 1)
	{
		Gobang_main();
	}
	if (choice == 2)
	{
		Chinese_chess_main();
	}
}

void setColor(unsigned short ForeColor, unsigned short BackGroundColor)
{
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);//获取当前窗口句柄
	SetConsoleTextAttribute(handle, ForeColor + BackGroundColor * 0x10);//设置颜色
}