#include "../chess/init.h"

int main()
{
	int choice;
	Sleep(1000);
	system("cls");
	system("color 07");
	printf("����ɶ�壿\n\n1.������\n2.�й�����\n\n");
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
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);//��ȡ��ǰ���ھ��
	SetConsoleTextAttribute(handle, ForeColor + BackGroundColor * 0x10);//������ɫ
}