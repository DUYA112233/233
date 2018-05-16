#include "Gobang_init.h"

int Gobang_main();  //五子棋主程序
void Gobang_menu();  //主菜单
void Gobang_size();  //棋盘大小
void Gobang_clean();  //清空棋盘
void Gobang_newgame();  //新游戏
void Gobang_win(int t);  //胜负判定  t:黑旗1 白棋2
void Gobang_player1();  //player1下子
void Gobang_player2();  //...
void Gobang_PvE();
void Gobang_PvP();
void Gobang_EvE();
void Gobang_E();  //电脑下子
void Gobang_print();  //打印棋盘

int Gobang_qp[21][21];
int Gobang_flag, Gobang_TheFirstStep[2];  //Gobang_flag:游戏是否结束.  Gobang_TheFirstStep:第一步是否下完
int Gobang_n, Gobang_p, Gobang_q, Gobang_choice, Gobang_laststepp, Gobang_laststepq;  //n:棋盘大小
char Gobang_winer1[9], Gobang_winer2[9];  //对战双方名字
int Gobang_LastManStepp[2], Gobang_LastManStepq[2];  //上一步人类落子
int Gobang_lastattackp[2], Gobang_lastattackq[2];  //上一步电脑进攻落子
int Gobang_ifentercm6[2];  //用于判断是否需要进入Gobang_computermaster6
int Gobang_k, Gobang_d;  //k:攻方 Gobang_d:防方
int Gobang_exit233[99];  //算的太久就下一个函数
int Gobang_win_test_flag = 0;  //测试有没有机会一步获胜

int Gobang_main()
{
	Gobang_menu();
	Gobang_size();
	Gobang_clean();
	if(Gobang_choice == 1)
	{
		Gobang_PvE();
	}
	else if(Gobang_choice == 2)
	{
		Gobang_PvP();
	}
	else
	{
		Gobang_EvE();
	}
	Gobang_newgame();
}

void Gobang_E()
{
	for(int i = 0 ; i < 99 ; i++)
	{
		Gobang_exit233[i] = 0;
	}
	if(!Gobang_TheFirstStep[Gobang_k])
	{
		Gobang_computer();
		Gobang_lastattackp[Gobang_k] = Gobang_p;
		Gobang_lastattackq[Gobang_k] = Gobang_q;
	}
	else
	{
		Gobang_computermaster11();
		while((Gobang_qp[Gobang_p][Gobang_q] || Gobang_p < 1 || Gobang_q < 1 || Gobang_p > Gobang_n || Gobang_q > Gobang_n) || (Gobang_p == Gobang_LastManStepp[Gobang_k] && Gobang_q == Gobang_LastManStepq[Gobang_k]))
		{
			if(Gobang_exit233[8] > 10000)
			{
				break;
			}
			Gobang_computermaster8();
			Gobang_exit233[8]++;
		}
		while((Gobang_qp[Gobang_p][Gobang_q] || Gobang_p < 1 || Gobang_q < 1 || Gobang_p > Gobang_n || Gobang_q > Gobang_n) || (Gobang_p == Gobang_LastManStepp[Gobang_k] && Gobang_q == Gobang_LastManStepq[Gobang_k]))
		{
			if(Gobang_exit233[10] > 10000)
			{
				break;
			}
			Gobang_computermaster10();
			Gobang_exit233[10]++;
		}
		while((Gobang_qp[Gobang_p][Gobang_q] || Gobang_p < 1 || Gobang_q < 1 || Gobang_p > Gobang_n || Gobang_q > Gobang_n) || (Gobang_p == Gobang_LastManStepp[Gobang_k] && Gobang_q == Gobang_LastManStepq[Gobang_k]))
		{
			if(Gobang_exit233[7] > 10000)
			{
				break;
			}
			Gobang_computermaster7();
			Gobang_exit233[7]++;
		}
		while((Gobang_qp[Gobang_p][Gobang_q] || Gobang_p < 1 || Gobang_q < 1 || Gobang_p > Gobang_n || Gobang_q > Gobang_n) || (Gobang_p == Gobang_LastManStepp[Gobang_k] && Gobang_q == Gobang_LastManStepq[Gobang_k]))
		{
			if(Gobang_exit233[6] > 10000)
			{
				break;
			}
			Gobang_computermaster6();
			Gobang_exit233[6]++;
		}
		while((Gobang_qp[Gobang_p][Gobang_q] || Gobang_p < 1 || Gobang_q < 1 || Gobang_p > Gobang_n || Gobang_q > Gobang_n) || (Gobang_p == Gobang_LastManStepp[Gobang_k] && Gobang_q == Gobang_LastManStepq[Gobang_k]))
		{
			if(Gobang_exit233[3] > 10000 || Gobang_ifentercm6[Gobang_k])
			{
				break;
			}
			Gobang_computermaster3();
			Gobang_exit233[3]++;
		}
		while((Gobang_qp[Gobang_p][Gobang_q] || Gobang_p < 1 || Gobang_q < 1 || Gobang_p > Gobang_n || Gobang_q > Gobang_n) || (Gobang_p == Gobang_LastManStepp[Gobang_k] && Gobang_q == Gobang_LastManStepq[Gobang_k]))
		{
			if(Gobang_exit233[2] > 10000)
			{
				break;
			}
			Gobang_computermaster2();
			Gobang_exit233[2]++;
		}
		while((Gobang_qp[Gobang_p][Gobang_q] || Gobang_p < 1 || Gobang_q < 1 || Gobang_p > Gobang_n || Gobang_q > Gobang_n) || (Gobang_p == Gobang_LastManStepp[Gobang_k] && Gobang_q == Gobang_LastManStepq[Gobang_k]))
		{
			if(Gobang_exit233[9] > 10000)
			{
				break;
			}
			Gobang_computermaster9();
			if(Gobang_LastManStepp[Gobang_k] != Gobang_p || Gobang_LastManStepq[Gobang_k] != Gobang_q)
			{
				Gobang_lastattackp[Gobang_k] = Gobang_p;
				Gobang_lastattackq[Gobang_k] = Gobang_q;
			}
			Gobang_exit233[9]++;
		}
		while((Gobang_qp[Gobang_p][Gobang_q] || Gobang_p < 1 || Gobang_q < 1 || Gobang_p > Gobang_n || Gobang_q > Gobang_n) || (Gobang_p == Gobang_LastManStepp[Gobang_k] && Gobang_q == Gobang_LastManStepq[Gobang_k]))
		{
			if(Gobang_exit233[5] > 10000)
			{
				break;
			}
			Gobang_computermaster5();
			if(Gobang_LastManStepp[Gobang_k] != Gobang_p || Gobang_LastManStepq[Gobang_k] != Gobang_q)
			{
				Gobang_lastattackp[Gobang_k] = Gobang_p;
				Gobang_lastattackq[Gobang_k] = Gobang_q;
			}
			Gobang_exit233[5]++;
		}
		while((Gobang_qp[Gobang_p][Gobang_q] || Gobang_p < 1 || Gobang_q < 1 || Gobang_p > Gobang_n || Gobang_q > Gobang_n) || (Gobang_p == Gobang_LastManStepp[Gobang_k] && Gobang_q == Gobang_LastManStepq[Gobang_k]))
		{
			if(Gobang_exit233[4] > 10000)
			{
				break;
			}
			Gobang_computermaster4();
			if(Gobang_LastManStepp[Gobang_k] != Gobang_p || Gobang_LastManStepq[Gobang_k] != Gobang_q)
			{
				Gobang_lastattackp[Gobang_k] = Gobang_p;
				Gobang_lastattackq[Gobang_k] = Gobang_q;
			}
			Gobang_exit233[4]++;
		}
		Gobang_computermaster1();  //已内置死循环跳出
		while((Gobang_qp[Gobang_p][Gobang_q] || Gobang_p < 1 || Gobang_q < 1 || Gobang_p > Gobang_n || Gobang_q > Gobang_n) || (Gobang_p == Gobang_LastManStepp[Gobang_k] && Gobang_q == Gobang_LastManStepq[Gobang_k]))
		{
			Gobang_computer();
		}
	}
	if(Gobang_choice == 1)
	{
		Gobang_qp[Gobang_p][Gobang_q] = Gobang_k+2;
	}
	else
	{
		Gobang_qp[Gobang_p][Gobang_q] = Gobang_k+1;
	}
	Gobang_laststepp = Gobang_p;
	Gobang_laststepq = Gobang_q;
	Gobang_print();
}

void Gobang_PvE()
{
	setColor(3, 0);
	while(1)
	{
		Gobang_player1();
		Gobang_win(1);
		if (Gobang_flag)
		{
			break;
		}
		Gobang_LastManStepp[Gobang_k] = Gobang_p;
		Gobang_LastManStepq[Gobang_k] = Gobang_q;
		Gobang_E();
		Gobang_win(2);
		if (Gobang_flag)
		{
			break;
		}
	}
}

void Gobang_PvP()
{
	setColor(3, 0);
	while(1)
	{
		Gobang_player1();
		Gobang_win(1);
		if (Gobang_flag)
		{
			break;
		}
		Gobang_player2();
		Gobang_win(2);
		if (Gobang_flag)
		{
			break;
		}
	}
}

void Gobang_EvE()
{
	setColor(3, 0);
	while(1)
	{
		Gobang_E();
		Gobang_win(Gobang_k+1);
		if (Gobang_flag)
		{
			break;
		}
		if(Gobang_k == 0)
		{
			Gobang_k = 1;
			Gobang_d = 0;
		}
		else
		{
			Gobang_k = 0;
			Gobang_d = 1;
		}
		Gobang_LastManStepp[Gobang_k] = Gobang_p;
		Gobang_LastManStepq[Gobang_k] = Gobang_q;
		Sleep(500);
	}
}

void Gobang_menu()
{
	system("color 06");
	printf("***************五子棋****************\n\n请选择模式\n1.PvE\n2.PvP\n3.EvE\n\n");
	scanf("%d", &Gobang_choice);
	if(Gobang_choice == 1)
	{
		sprintf(Gobang_winer1, "玩家");
		sprintf(Gobang_winer2, "电脑");
	}
	else if(Gobang_choice == 2)
	{
		sprintf(Gobang_winer1, "玩家1");
		sprintf(Gobang_winer2, "玩家2");
	}
	else if(Gobang_choice == 3)
	{
		sprintf(Gobang_winer1, "电脑1");
		sprintf(Gobang_winer2, "电脑2");
	}
	else
	{
		printf("输入数字有误\n");
		return Gobang_menu();
	}
}

void Gobang_clean()
{
	Gobang_flag = 0;
	Gobang_k = 0;
	Gobang_d = 1;
	for(int i = 0 ; i < Gobang_n+2 ; i++)
	{
		for(int j = 0 ; j < Gobang_n+2 ; j++)
			Gobang_qp[i][j] = 0;
	}
}

void Gobang_size()
{
	printf("请输入棋盘大小(8~19)：\n");
	scanf("%d", &Gobang_n);
	if(Gobang_n<8 || Gobang_n>19)
	{
		printf("输入数字有误\n");
		return Gobang_size();
	}
}

void Gobang_newgame()
{
	Gobang_flag = 0;
	Gobang_TheFirstStep[0] = Gobang_TheFirstStep[1] = 0;
	int more;
	Gobang_print();
	printf("再来一把不？\n1.确定\n2.拒绝\n");
	scanf("%d", &more);
	if(more < 1 || more > 2)
	{
		printf("输入错误\n");
		return Gobang_newgame();
	}
	else
	{
		if(more-2)
		{
			system("cls");
			return main();
		}
	}
}

void Gobang_player1()
{
	printf("%s请下下一步（行 列）", Gobang_winer1);
	scanf("%d%d", &Gobang_p, &Gobang_q);
	if(Gobang_qp[Gobang_p][Gobang_q])
	{
		printf("此处已有棋子\n");
		return Gobang_player1();
	}
	else if(Gobang_p>Gobang_n || Gobang_q>Gobang_n)
	{
		printf("超出棋盘范围\n");
		return Gobang_player1();
	}
	else
	{
		Gobang_qp[Gobang_p][Gobang_q] = 1;
		Gobang_print();
	}
}

void Gobang_player2()
{
	printf("%s请下下一步（行 列）", Gobang_winer2);
	scanf("%d%d", &Gobang_p, &Gobang_q);
	if(Gobang_qp[Gobang_p][Gobang_q])
	{
		printf("此处已有棋子\n");
		return Gobang_player2();
	}
	else if(Gobang_p>Gobang_n || Gobang_q>Gobang_n)
	{
		printf("超出棋盘范围\n");
		return Gobang_player2();
	}
	else
	{
		Gobang_qp[Gobang_p][Gobang_q] = 2;
		Gobang_print();
	}
}

void Gobang_print()
{
	system("cls");
	printf("电脑%d：%d %d\n", Gobang_k+1, Gobang_p, Gobang_q);
	for(int i = 0 ; i <= Gobang_n ; i++)
	{
		setColor(3, 0);
		printf("%02d  ", i);
	}
	printf("\n\n");
	for(int i = 1 ; i <= Gobang_n ; i++)
	{
		for(int j = 0 ; j <= Gobang_n ; j++)
		{
			if(j == 0)
			{
				setColor(3, 0);
				printf("%02d  ", i);
			}
			else
			{
				if(Gobang_qp[i][j] == 0)
				{
					printf("    ");
				}
				else if(Gobang_qp[i][j] == 1)
				{
					setColor(12, 0);
					printf("x   ");
				}
				else
				{
					setColor(6, 0);
					printf("o   ");
				}
			}
		}
		printf("\n\n");
	}
}

void Gobang_win(int t)
{
	int time = 0;
	for(int i = Gobang_p - 1 ; i <= Gobang_p+1 ; i++)
	{
		for(int j = Gobang_q - 1 ; j <= Gobang_q+1 ; j++)
		{
			time++;
			if(Gobang_flag)  break;
			if(time == 5)
			{
				continue;
			}
			if(Gobang_qp[i][j] == t)
			{
				switch(time)
				{
					case 1:
					{
						if((Gobang_qp[Gobang_p-4][Gobang_q-4]==t && Gobang_qp[Gobang_p-3][Gobang_q-3]==t && Gobang_qp[Gobang_p-2][Gobang_q-2]==t) || (Gobang_qp[Gobang_p-3][Gobang_q-3]==t && Gobang_qp[Gobang_p-2][Gobang_q-2]==t && Gobang_qp[Gobang_p+1][Gobang_q+1]==t) || (Gobang_qp[Gobang_p-2][Gobang_q-2]==t && Gobang_qp[Gobang_p+1][Gobang_q+1]==t && Gobang_qp[Gobang_p+2][Gobang_q+2]==t) || (Gobang_qp[Gobang_p+1][Gobang_q+1]==t && Gobang_qp[Gobang_p+2][Gobang_q+2]==t && Gobang_qp[Gobang_p+3][Gobang_q+3]==t))
						{
							if(t == Gobang_k+1)
							{
								printf("%s获胜\n", Gobang_winer1);
								Gobang_flag++;
								break;
							}
							else if(t == Gobang_d+1)
							{
								printf("%s获胜\n", Gobang_winer2);
								Gobang_flag++;
								break;
							}
						}
					}
					break;
					case 2:
					{
						if((Gobang_qp[Gobang_p-4][Gobang_q]==t && Gobang_qp[Gobang_p-3][Gobang_q]==t && Gobang_qp[Gobang_p-2][Gobang_q]==t) || (Gobang_qp[Gobang_p-3][Gobang_q]==t && Gobang_qp[Gobang_p-2][Gobang_q]==t && Gobang_qp[Gobang_p+1][Gobang_q]==t) || (Gobang_qp[Gobang_p-2][Gobang_q]==t && Gobang_qp[Gobang_p+1][Gobang_q]==t && Gobang_qp[Gobang_p+2][Gobang_q]==t) || (Gobang_qp[Gobang_p+1][Gobang_q]==t && Gobang_qp[Gobang_p+2][Gobang_q]==t && Gobang_qp[Gobang_p+3][Gobang_q]==t))
						{
							if(t == Gobang_k+1)
							{
								printf("%s获胜\n", Gobang_winer1);
								Gobang_flag++;
								break;
							}
							else if(t == Gobang_d+1)
							{
								printf("%s获胜\n", Gobang_winer2);
								Gobang_flag++;
								break;
							}
						}
					}
					break;
					case 3:
					{
						if((Gobang_qp[Gobang_p-4][Gobang_q+4]==t && Gobang_qp[Gobang_p-3][Gobang_q+3]==t && Gobang_qp[Gobang_p-2][Gobang_q+2]==t) || (Gobang_qp[Gobang_p-3][Gobang_q+3]==t && Gobang_qp[Gobang_p-2][Gobang_q+2]==t && Gobang_qp[Gobang_p+1][Gobang_q-1]==t) || (Gobang_qp[Gobang_p-2][Gobang_q+2]==t && Gobang_qp[Gobang_p+1][Gobang_q-1]==t && Gobang_qp[Gobang_p+2][Gobang_q-2]==t) || (Gobang_qp[Gobang_p+1][Gobang_q-1]==t && Gobang_qp[Gobang_p+2][Gobang_q-2]==t && Gobang_qp[Gobang_p+3][Gobang_q-3]==t))
						{
							if(t == Gobang_k+1)
							{
								printf("%s获胜\n", Gobang_winer1);
								Gobang_flag++;
								break;
							}
							else if(t == Gobang_d+1)
							{
								printf("%s获胜\n", Gobang_winer2);
								Gobang_flag++;
								break;
							}
						}
					}
					break;
					case 4:
					{
						if((Gobang_qp[Gobang_p][Gobang_q-4]==t && Gobang_qp[Gobang_p][Gobang_q-3]==t && Gobang_qp[Gobang_p][Gobang_q-2]==t) || (Gobang_qp[Gobang_p][Gobang_q-3]==t && Gobang_qp[Gobang_p][Gobang_q-2]==t && Gobang_qp[Gobang_p][Gobang_q+1]==t) || (Gobang_qp[Gobang_p][Gobang_q-2]==t && Gobang_qp[Gobang_p][Gobang_q+1]==t && Gobang_qp[Gobang_p][Gobang_q+2]==t) || (Gobang_qp[Gobang_p][Gobang_q+1]==t && Gobang_qp[Gobang_p][Gobang_q+2]==t && Gobang_qp[Gobang_p][Gobang_q+3]==t))
						{
							if(t == Gobang_k+1)
							{
								printf("%s获胜\n", Gobang_winer1);
								Gobang_flag++;
								break;
							}
							else if(t == Gobang_d+1)
							{
								printf("%s获胜\n", Gobang_winer2);
								Gobang_flag++;
								break;
							}
						}
					}
					break;
					case 6:
					{
						if((Gobang_qp[Gobang_p][Gobang_q-3]==t && Gobang_qp[Gobang_p][Gobang_q-2]==t && Gobang_qp[Gobang_p][Gobang_q-1]==t) || (Gobang_qp[Gobang_p][Gobang_q-2]==t && Gobang_qp[Gobang_p][Gobang_q-1]==t && Gobang_qp[Gobang_p][Gobang_q+2]==t) || (Gobang_qp[Gobang_p][Gobang_q-1]==t && Gobang_qp[Gobang_p][Gobang_q+2]==t && Gobang_qp[Gobang_p][Gobang_q+3]==t) || (Gobang_qp[Gobang_p][Gobang_q+2]==t && Gobang_qp[Gobang_p][Gobang_q+3]==t && Gobang_qp[Gobang_p][Gobang_q+4]==t))
						{
							if(t == Gobang_k+1)
							{
								printf("%s获胜\n", Gobang_winer1);
								Gobang_flag++;
								break;
							}
							else if(t == Gobang_d+1)
							{
								printf("%s获胜\n", Gobang_winer2);
								Gobang_flag++;
								break;
							}
						}
					}
					break;
					case 7:
					{
						if((Gobang_qp[Gobang_p-3][Gobang_q+3]==t && Gobang_qp[Gobang_p-2][Gobang_q+2]==t && Gobang_qp[Gobang_p-1][Gobang_q+1]==t) || (Gobang_qp[Gobang_p-2][Gobang_q+2]==t && Gobang_qp[Gobang_p-1][Gobang_q+1]==t && Gobang_qp[Gobang_p+2][Gobang_q-2]==t) || (Gobang_qp[Gobang_p-1][Gobang_q+1]==t && Gobang_qp[Gobang_p+2][Gobang_q-2]==t && Gobang_qp[Gobang_p+3][Gobang_q-3]==t) || (Gobang_qp[Gobang_p+2][Gobang_q-2]==t && Gobang_qp[Gobang_p+3][Gobang_q-3]==t && Gobang_qp[Gobang_p+4][Gobang_q-4]==t))
						{
							if(t == Gobang_k+1)
							{
								printf("%s获胜\n", Gobang_winer1);
								Gobang_flag++;
								break;
							}
							else if(t == Gobang_d+1)
							{
								printf("%s获胜\n", Gobang_winer2);
								Gobang_flag++;
								break;
							}
						}
					}
					break;
					case 8:
					{
						if((Gobang_qp[Gobang_p-3][Gobang_q]==t && Gobang_qp[Gobang_p-2][Gobang_q]==t && Gobang_qp[Gobang_p-1][Gobang_q]==t) || (Gobang_qp[Gobang_p-2][Gobang_q]==t && Gobang_qp[Gobang_p-1][Gobang_q]==t && Gobang_qp[Gobang_p+2][Gobang_q]==t) || (Gobang_qp[Gobang_p-1][Gobang_q]==t && Gobang_qp[Gobang_p+2][Gobang_q]==t && Gobang_qp[Gobang_p+3][Gobang_q]==t) || (Gobang_qp[Gobang_p+2][Gobang_q]==t && Gobang_qp[Gobang_p+3][Gobang_q]==t && Gobang_qp[Gobang_p+4][Gobang_q]==t))
						{
							if(t == Gobang_k+1)
							{
								printf("%s获胜\n", Gobang_winer1);
								Gobang_flag++;
								break;
							}
							else if(t == Gobang_d+1)
							{
								printf("%s获胜\n", Gobang_winer2);
								Gobang_flag++;
								break;
							}
						}
					}
					break;
					case 9:
					{
						if((Gobang_qp[Gobang_p-3][Gobang_q-3]==t && Gobang_qp[Gobang_p-2][Gobang_q-2]==t && Gobang_qp[Gobang_p-1][Gobang_q-1]==t) || (Gobang_qp[Gobang_p-2][Gobang_q-2]==t && Gobang_qp[Gobang_p-1][Gobang_q-1]==t && Gobang_qp[Gobang_p+2][Gobang_q+2]==t) || (Gobang_qp[Gobang_p-1][Gobang_q-1]==t && Gobang_qp[Gobang_p+2][Gobang_q+2]==t && Gobang_qp[Gobang_p+3][Gobang_q+3]==t) || (Gobang_qp[Gobang_p+2][Gobang_q+2]==t && Gobang_qp[Gobang_p+3][Gobang_q+3]==t && Gobang_qp[Gobang_p+4][Gobang_q+4]==t))
						{
							if(t == Gobang_k+1)
							{
								printf("%s获胜\n", Gobang_winer1);
								Gobang_flag++;
								break;
							}
							else if(t == Gobang_d+1)
							{
								printf("%s获胜\n", Gobang_winer2);
								Gobang_flag++;
								break;
							}
						}
					}
					break;
				}
			}
		}
	}
}
