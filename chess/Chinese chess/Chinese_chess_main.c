#include "Chinese_chess_init.h"

int Chinese_chess_main();
int Chinese_chess_menu(); //主菜单
void Chinese_chess_clean();  //初始化棋盘
void Chinese_chess_newgame();  //新游戏
void Chinese_chess_win(int t);  //胜负判定  t:红旗1 黑棋2
int Chinese_chess_player1();  //player1下子
int Chinese_chess_player2();  //...
void Chinese_chess_PvE();
void Chinese_chess_PvP();
void Chinese_chess_EvE();
void Chinese_chess_E();  //电脑下子
int Chinese_chess_move_rule1();  //检查player1棋子移动是否违规
int Chinese_chess_move_rule2();  //检查player2棋子移动是否违规
void Chinese_chess_print();  //打印棋盘
void Chinese_chess_flash();  //棋子动画

int Chinese_chess_flag;  //flag:游戏是否结束
int Chinese_chess_p, Chinese_chess_q, Chinese_chess_choice;  //n:棋盘大小
int Chinese_chess_p_to, Chinese_chess_q_to;  //棋子要移动到的位置
char Chinese_chess_winer1[9], Chinese_chess_winer2[9];  //对战双方名字

struct qpstatus {
	int player;  //pleyer=0无棋;pleyer=1/2一方的棋
	char* piece;  //是什么棋
}Chinese_chess_qp[12][11];  //棋盘为10*9

int Chinese_chess_main()
{
	Chinese_chess_clean();
	Chinese_chess_menu();
	if (Chinese_chess_choice == 1)
	{
		Chinese_chess_PvE();
	}
	if (Chinese_chess_choice == 2)
	{
		Chinese_chess_PvP();
	}
	if (Chinese_chess_choice == 3)
	{
		Chinese_chess_EvE();
	}
}

int Chinese_chess_menu()
{
	setColor(6, 0);
	printf("***************中国象棋****************\n\n请选择模式\n1.PvE\n2.PvP\n3.EvE\n\n");
	scanf("%d", &Chinese_chess_choice);
	if (Chinese_chess_choice == 1)
	{
		sprintf(Chinese_chess_winer1, "玩家");
		sprintf(Chinese_chess_winer2, "电脑");
		printf("没写完\n");
		return main();
	}
	else if (Chinese_chess_choice == 2)
	{
		sprintf(Chinese_chess_winer1, "玩家1");
		sprintf(Chinese_chess_winer2, "玩家2");
		Chinese_chess_PvP();
		return main();
	}
	else if (Chinese_chess_choice == 3)
	{
		sprintf(Chinese_chess_winer1, "电脑1");
		sprintf(Chinese_chess_winer2, "电脑2");
		printf("没写完\n");
		return main();
	}
	else
	{
		printf("输入数字有误\n");
		return main();
	}
}

void Chinese_chess_clean()
{
	Chinese_chess_flag = 0;
	for (int i = 0 ; i < 12 ; i++)   //摆棋 
	{
		for (int j = 0; j < 11; j++)
		{
			Chinese_chess_qp[i][j].player = 0;
			Chinese_chess_qp[i][j].piece = "none";
		}
	}
	Chinese_chess_qp[1][1].piece = Chinese_chess_qp[1][9].piece = "car";
	Chinese_chess_qp[1][2].piece = Chinese_chess_qp[1][8].piece = "horse";
	Chinese_chess_qp[1][3].piece = Chinese_chess_qp[1][7].piece = "elephant";
	Chinese_chess_qp[1][4].piece = Chinese_chess_qp[1][6].piece = "guard";
	Chinese_chess_qp[1][5].piece = "general";
	Chinese_chess_qp[3][2].piece = Chinese_chess_qp[3][8].piece = "connon";
	Chinese_chess_qp[4][1].piece = Chinese_chess_qp[4][3].piece = Chinese_chess_qp[4][5].piece = Chinese_chess_qp[4][7].piece = Chinese_chess_qp[4][9].piece = "soldier";
	for(int i = 1 ; i <= 9 ; i++)
	{
		Chinese_chess_qp[1][i].player = 2;
	}
	for(int i = 1 ; i <= 9 ; i += 2)
	{
		Chinese_chess_qp[4][i].player = 2;
	}
	Chinese_chess_qp[3][2].player = Chinese_chess_qp[3][8].player = 2;
	for(int i = 1 ; i <= 10 ; i++)
	{
		for(int j = 1 ; j <= 9 ; j++)
		{
			Chinese_chess_qp[11-i][j].piece = Chinese_chess_qp[i][j].piece;
			if(Chinese_chess_qp[i][j].player == 2)
			{
				Chinese_chess_qp[11-i][j].player = 1;
			}
		}
	}
}

int Chinese_chess_player1()
{
	setColor(3, 0);
	printf("%s请选择要移动的棋子（行 列）", Chinese_chess_winer1);
	scanf("%d%d", &Chinese_chess_p, &Chinese_chess_q);
	Chinese_chess_print();
	setColor(3, 0);
	if (Chinese_chess_qp[Chinese_chess_p][Chinese_chess_q].player == 0)
	{
		printf("此处没有棋子\n");
		return Chinese_chess_player1();
	}
	else if (Chinese_chess_qp[Chinese_chess_p][Chinese_chess_q].player == 2)
	{
		printf("此处棋子是对方的\n");
		return Chinese_chess_player1();
	}
	else if (Chinese_chess_p < 1 || Chinese_chess_p > 10 || Chinese_chess_q < 1 || Chinese_chess_q > 9)
	{
		printf("超出棋盘范围\n");
		return Chinese_chess_player1();
	}
	else
	{
		printf("请选择此棋要移动到的位置\n");
		scanf("%d%d", &Chinese_chess_p_to, &Chinese_chess_q_to);
		if(Chinese_chess_move_rule1() == 0)
	{
			printf("棋子移动不符合规则,请重新选择\n");
			return Chinese_chess_player1();
		 } 
	}
}

int Chinese_chess_player2()
{
	setColor(3, 0);
	printf("%s请选择要移动的棋子（行 列）", Chinese_chess_winer2);
	scanf("%d%d", &Chinese_chess_p, &Chinese_chess_q);
	if (Chinese_chess_qp[Chinese_chess_p][Chinese_chess_q].player == 0)
	{
		printf("此处没有棋子\n");
		return Chinese_chess_player2();
	}
	else if (Chinese_chess_qp[Chinese_chess_p][Chinese_chess_q].player == 1)
	{
		printf("此处棋子是对方的\n");
		return Chinese_chess_player2();
	}
	else if (Chinese_chess_p < 1 || Chinese_chess_p > 10 || Chinese_chess_q < 1 || Chinese_chess_q > 9)
	{
		printf("超出棋盘范围\n");
		return Chinese_chess_player2();
	}
	else
	{
		printf("请选择此棋要移动到的位置\n");
		scanf("%d%d", &Chinese_chess_p_to, &Chinese_chess_q_to);
		if(Chinese_chess_move_rule2() == 0)
		{
			printf("棋子移动不符合规则,请重新选择\n");
			return Chinese_chess_player2();
		 } 
	}
}

int Chinese_chess_move_rule1()
{
	int obstacle = 0;  //统计出发点与目标点之间的障碍物数量
	if (Chinese_chess_p_to < 1 && Chinese_chess_p_to > 10 && Chinese_chess_q_to < 1 && Chinese_chess_q_to > 9)  //走出棋盘
	{
		return 0;
	}
	if (Chinese_chess_qp[Chinese_chess_p_to][Chinese_chess_q_to].player == 1)  //目的地有自己的棋子
	{
		return 0;
	}
	if (Chinese_chess_qp[Chinese_chess_p][Chinese_chess_q].piece == "soldier")  //小兵移动规则
	{
		if (Chinese_chess_p > 5) //未过楚河汉界
		{
			if (Chinese_chess_p_to == Chinese_chess_p - 1 && Chinese_chess_q_to == Chinese_chess_q)  //只准往前走一步
			{
				return 1;
			}
			else
			{
				return 0;
			}
		}
		else  //过界
		{
			if ((Chinese_chess_p_to == Chinese_chess_p - 1 && Chinese_chess_q_to == Chinese_chess_q) || (Chinese_chess_p_to == Chinese_chess_p && Chinese_chess_q_to == Chinese_chess_q + 1) || (Chinese_chess_p_to == Chinese_chess_p && Chinese_chess_q_to == Chinese_chess_q - 1))  //只准往前、左、右走
			{
				return 1;
			}
			else
			{
				return 0;
			}
		}
	}
	else if(Chinese_chess_qp[Chinese_chess_p][Chinese_chess_q].piece == "connon")
	{																										
		if (Chinese_chess_p != Chinese_chess_p_to && Chinese_chess_q != Chinese_chess_q_to)  //没有走直线
		{
			return 0;
		}
		if (Chinese_chess_p == Chinese_chess_p_to)  //横向走
		{
			if (Chinese_chess_q_to > Chinese_chess_q)  //往右走 
			{
				for (int i = Chinese_chess_q + 1; i < Chinese_chess_q_to; i++)  //统计路径上障碍物数量
				{
					if (Chinese_chess_qp[Chinese_chess_p][i].player)
					{
						obstacle++;
					}
				}
			}
			else                                   //往左走 
			{
				for (int i = Chinese_chess_q - 1; i > Chinese_chess_q_to; i--)
				{
					if (Chinese_chess_qp[Chinese_chess_p][i].player)
					{
						obstacle++;
					}
				}
			}
		}
		if (Chinese_chess_q == Chinese_chess_q_to)  //纵向走
		{
			if (Chinese_chess_p_to > Chinese_chess_p)  //往下走 
			{
				for (int i = Chinese_chess_p + 1; i < Chinese_chess_p_to; i++)
				{
					if (Chinese_chess_qp[i][Chinese_chess_q].player)
					{
						obstacle++;
					}
				}
			}
			else
			{
				for (int i = Chinese_chess_p - 1; i > Chinese_chess_p_to; i--)  //往上走 
				{
					if (Chinese_chess_qp[i][Chinese_chess_q].player)
					{
						obstacle++;
					}
				}
			}
		}
		if (obstacle == 0)
		{
			if (Chinese_chess_qp[Chinese_chess_p_to][Chinese_chess_q_to].player == 0)
			{
				return 1;
			}
			else
			{
				return 0;
			}
		}
		else if (obstacle == 1)
		{
			if (Chinese_chess_qp[Chinese_chess_p_to][Chinese_chess_q_to].player)
			{
				return 1;
			}
			else
			{
				return 0;
			}
		}
		else
		{
			return 0;
		}
	}
	else if (Chinese_chess_qp[Chinese_chess_p][Chinese_chess_q].piece == "car")
	{
		if (Chinese_chess_p != Chinese_chess_p_to && Chinese_chess_q != Chinese_chess_q_to)  //没有走直线
		{
			return 0;
		}
		if (Chinese_chess_p == Chinese_chess_p_to)  //横向走
		{
			if (Chinese_chess_q_to > Chinese_chess_q)  //往右走 
			{
				for (int i = Chinese_chess_q + 1; i < Chinese_chess_q_to; i++)  //统计路径上障碍物数量
				{
					if (Chinese_chess_qp[Chinese_chess_p][i].player)
					{
						obstacle++;
					}
				}
			}
			else                                   //往左走 
			{
				for (int i = Chinese_chess_q - 1; i > Chinese_chess_q_to; i--)
				{
					if (Chinese_chess_qp[Chinese_chess_p][i].player)
					{
						obstacle++;
					}
				}
			}
		}
		if (Chinese_chess_q == Chinese_chess_q_to)  //纵向走
		{
			if (Chinese_chess_p_to > Chinese_chess_p)  //往下走 
			{
				for (int i = Chinese_chess_p + 1; i < Chinese_chess_p_to; i++)
				{
					if (Chinese_chess_qp[i][Chinese_chess_q].player)
					{
						obstacle++;
					}
				}
			}
			else
			{
				for (int i = Chinese_chess_p - 1; i > Chinese_chess_p_to; i--)  //往上走 
				{
					if (Chinese_chess_qp[i][Chinese_chess_q].player)
					{
						obstacle++;
					}
				}
			}
		}
		if (obstacle != 0)  //障碍物数量不为0
		{
			return 0;
		}
		else
		{
			return 1;
		}
	}
	else if (Chinese_chess_qp[Chinese_chess_p][Chinese_chess_q].piece == "horse")
	{
		if ((Chinese_chess_p_to == Chinese_chess_p - 2 && Chinese_chess_q_to == Chinese_chess_q + 1) || (Chinese_chess_p_to == Chinese_chess_p - 2 && Chinese_chess_q_to == Chinese_chess_q - 1))  //上上右与上上左
		{
			if (Chinese_chess_qp[Chinese_chess_p - 1][Chinese_chess_q].player)
			{
				return 0;
			}
			else
			{
				return 1;
			}
		}
		else if ((Chinese_chess_p_to == Chinese_chess_p - 1 && Chinese_chess_q_to == Chinese_chess_q + 2) || (Chinese_chess_p_to == Chinese_chess_p + 1 && Chinese_chess_q_to == Chinese_chess_q + 2))  //右右上和右右下
		{
			if (Chinese_chess_qp[Chinese_chess_p][Chinese_chess_q + 1].player)
			{
				return 0;
			}
			else
			{
				return 1;
			}
		}
		else if ((Chinese_chess_p_to == Chinese_chess_p + 2 && Chinese_chess_q_to == Chinese_chess_q + 1) || (Chinese_chess_p_to == Chinese_chess_p + 2 && Chinese_chess_q_to == Chinese_chess_q - 1))  //下下右与下下左
		{
			if (Chinese_chess_qp[Chinese_chess_p + 1][Chinese_chess_q].player)
			{
				return 0;
			}
			else
			{
				return 1;
			}
		}
		else if ((Chinese_chess_p_to == Chinese_chess_p - 1 && Chinese_chess_q_to == Chinese_chess_q - 2) || (Chinese_chess_p_to == Chinese_chess_p + 1 && Chinese_chess_q_to == Chinese_chess_q - 2))  //左左上和左左下
		{
			if (Chinese_chess_qp[Chinese_chess_p][Chinese_chess_q - 1].player)
			{
				return 0;
			}
			else
			{
				return 1;
			}
		}
		else
		{
			return 0;
		}
	}
	else if (Chinese_chess_qp[Chinese_chess_p][Chinese_chess_q].piece == "elephant")
	{
		if (Chinese_chess_p_to <= 5)  //不准过界
		{
			return 0;
		}
		if (Chinese_chess_p_to == Chinese_chess_p - 2 && Chinese_chess_q_to == Chinese_chess_q + 2)  //右上
		{
			if (Chinese_chess_qp[Chinese_chess_p - 1][Chinese_chess_q + 1].player)
			{
				return 0;
			}
			else
			{
				return 1;
			}
		}
		if (Chinese_chess_p_to == Chinese_chess_p + 2 && Chinese_chess_q_to == Chinese_chess_q + 2)  //右下
		{
			if (Chinese_chess_qp[Chinese_chess_p + 1][Chinese_chess_q + 1].player)
			{
				return 0;
			}
			else
			{
				return 1;
			}
		}
		if (Chinese_chess_p_to == Chinese_chess_p + 2 && Chinese_chess_q_to == Chinese_chess_q - 2)  //左下
		{
			if (Chinese_chess_qp[Chinese_chess_p + 1][Chinese_chess_q - 1].player)
			{
				return 0;
			}
			else
			{
				return 1;
			}
		}
		if (Chinese_chess_p_to == Chinese_chess_p - 2 && Chinese_chess_q_to == Chinese_chess_q - 2)  //左上
		{
			if (Chinese_chess_qp[Chinese_chess_p - 1][Chinese_chess_q - 1].player)
			{
				return 0;
			}
			else
			{
				return 1;
			}
		}
		else
		{
			return 0;
		}
	}
	else if (Chinese_chess_qp[Chinese_chess_p][Chinese_chess_q].piece == "guard")
	{
		if (Chinese_chess_p_to < 8 || Chinese_chess_q_to < 4 || Chinese_chess_q_to > 6)  //不准走出宫
		{
			return 0;
		}
		if (Chinese_chess_p_to == Chinese_chess_p - 1 && Chinese_chess_q_to == Chinese_chess_q + 1)       //右上
		{
			return 1;
		}
		else if (Chinese_chess_p_to == Chinese_chess_p + 1 && Chinese_chess_q_to == Chinese_chess_q + 1)  //右下
		{
			return 1;
		}
		else if (Chinese_chess_p_to == Chinese_chess_p + 1 && Chinese_chess_q_to == Chinese_chess_q - 1)  //左下
		{
			return 1;
		}
		else if (Chinese_chess_p_to == Chinese_chess_p - 1 && Chinese_chess_q_to == Chinese_chess_q - 1)  //左上
		{
			return 1;
		}
		else
		{
			return 0;
		}
	}
	else if (Chinese_chess_qp[Chinese_chess_p][Chinese_chess_q].piece == "general")
	{
		if ((Chinese_chess_p_to >= 8 && Chinese_chess_q_to >= 4 && Chinese_chess_q_to <= 6))  //不走出宫
		{
			if (Chinese_chess_p_to == Chinese_chess_p && Chinese_chess_q_to == Chinese_chess_q + 1)       //右
			{
				return 1;
			}
			else if (Chinese_chess_p_to == Chinese_chess_p + 1 && Chinese_chess_q_to == Chinese_chess_q)  //下
			{
				return 1;
			}
			else if (Chinese_chess_p_to == Chinese_chess_p && Chinese_chess_q_to == Chinese_chess_q - 1)  //左
			{
				return 1;
			}
			else if (Chinese_chess_p_to == Chinese_chess_p - 1 && Chinese_chess_q_to == Chinese_chess_q)  //上
			{
				return 1;
			}
			else
			{
				return 0;
			}
		}
		else
		{
			if (Chinese_chess_qp[Chinese_chess_p_to][Chinese_chess_q_to].piece == "general" && Chinese_chess_qp[Chinese_chess_p_to][Chinese_chess_q_to].player == 2 && Chinese_chess_q_to == Chinese_chess_q)
			{
				for (int i = Chinese_chess_p - 1; i > Chinese_chess_p_to + 1; i--)
				{
					if (Chinese_chess_qp[i][Chinese_chess_q].player)
					{
						return 0;
					}
				}
				return 1;
			}
			else
			{
				return 0;
			}
		}
	}
}

int Chinese_chess_move_rule2()
{
	int obstacle = 0;  //统计出发点与目标点之间的障碍物数量
	if (Chinese_chess_p_to < 1 || Chinese_chess_p_to > 10 || Chinese_chess_q_to < 1 || Chinese_chess_q_to > 9)  //走出棋盘
	{
		return 0;
	}
	if (Chinese_chess_qp[Chinese_chess_p_to][Chinese_chess_q_to].player == 2)  //目的地有自己的棋子
	{
		return 0;
	}
	if (Chinese_chess_qp[Chinese_chess_p][Chinese_chess_q].piece == "soldier")  //小兵移动规则
	{
		if (Chinese_chess_p <= 5) //未过楚河汉界
		{
			if (Chinese_chess_p_to == Chinese_chess_p + 1 && Chinese_chess_q_to == Chinese_chess_q)  //只准往前走一步
			{
				return 1;
			}
			else
			{
				return 0;
			}
		}
		else  //过界
		{
			if ((Chinese_chess_p_to == Chinese_chess_p + 1 && Chinese_chess_q_to == Chinese_chess_q) || (Chinese_chess_p_to == Chinese_chess_p && Chinese_chess_q_to == Chinese_chess_q + 1) || (Chinese_chess_p_to == Chinese_chess_p && Chinese_chess_q_to == Chinese_chess_q - 1))  //只准往前、左、右走
			{
				return 1;
			}
			else
			{
				return 0;
			}
		}
	}
	else if (Chinese_chess_qp[Chinese_chess_p][Chinese_chess_q].piece == "connon")
	{
		if (Chinese_chess_p != Chinese_chess_p_to && Chinese_chess_q != Chinese_chess_q_to)  //没有走直线
		{
			return 0;
		}
		if (Chinese_chess_p == Chinese_chess_p_to)  //横向走
		{
			if (Chinese_chess_q_to > Chinese_chess_q)  //往右走 
			{
				for (int i = Chinese_chess_q + 1; i < Chinese_chess_q_to; i++)  //统计路径上障碍物数量
				{
					if (Chinese_chess_qp[Chinese_chess_p][i].player)
					{
						obstacle++;
					}
				}
			}
			else                                   //往左走 
			{
				for (int i = Chinese_chess_q - 1; i > Chinese_chess_q_to; i--)
				{
					if (Chinese_chess_qp[Chinese_chess_p][i].player)
					{
						obstacle++;
					}
				}
			}
		}
		if (Chinese_chess_q == Chinese_chess_q_to)  //纵向走
		{
			if (Chinese_chess_p_to > Chinese_chess_p)  //往下走 
			{
				for (int i = Chinese_chess_p + 1; i < Chinese_chess_p_to; i++)
				{
					if (Chinese_chess_qp[i][Chinese_chess_q].player)
					{
						obstacle++;
					}
				}
			}
			else
			{
				for (int i = Chinese_chess_p - 1; i > Chinese_chess_p_to; i--)  //往上走 
				{
					if (Chinese_chess_qp[i][Chinese_chess_q].player)
					{
						obstacle++;
					}
				}
			}
		}
		if (obstacle == 0)
		{
			if (Chinese_chess_qp[Chinese_chess_p_to][Chinese_chess_q_to].player == 0)
			{
				return 1;
			}
			else
			{
				return 0;
			}
		}
		else if (obstacle == 1)
		{
			if (Chinese_chess_qp[Chinese_chess_p_to][Chinese_chess_q_to].player)
			{
				return 1;
			}
			else
			{
				return 0;
			}
		}
		else
		{
			return 0;
		}
	}
	else if (Chinese_chess_qp[Chinese_chess_p][Chinese_chess_q].piece == "car")
	{
		if (Chinese_chess_p != Chinese_chess_p_to && Chinese_chess_q != Chinese_chess_q_to)  //没有走直线
		{
			return 0;
		}
		if (Chinese_chess_p == Chinese_chess_p_to)  //横向走
		{
			if(Chinese_chess_q_to > Chinese_chess_q)  //往右走 
			{
				for (int i = Chinese_chess_q + 1; i < Chinese_chess_q_to; i++)  //统计路径上障碍物数量
				{
					if (Chinese_chess_qp[Chinese_chess_p][i].player)
					{
						obstacle++;
					}
				}
			}
			else                                   //往左走 
			{
				for (int i = Chinese_chess_q - 1; i > Chinese_chess_q_to; i--)
				{
					if (Chinese_chess_qp[Chinese_chess_p][i].player)
					{
						obstacle++;
					}
				}
			}
		}
		if (Chinese_chess_q == Chinese_chess_q_to)  //纵向走
		{
			if(Chinese_chess_p_to > Chinese_chess_p)  //往下走 
			{
				for (int i = Chinese_chess_p + 1; i < Chinese_chess_p_to; i++)
				{
					if (Chinese_chess_qp[i][Chinese_chess_q].player)
					{
						obstacle++;
					}
				}
			}
			else
			{
				for (int i = Chinese_chess_p - 1; i > Chinese_chess_p_to; i--)  //往上走 
				{
					if (Chinese_chess_qp[i][Chinese_chess_q].player)
					{
						obstacle++;
					}
				}
			}
		}
		if (obstacle != 0)  //障碍物数量不为0
		{
			return 0;
		}
		else
		{
			return 1;
		}
	}
	else if (Chinese_chess_qp[Chinese_chess_p][Chinese_chess_q].piece == "horse")
	{
		if ((Chinese_chess_p_to == Chinese_chess_p - 2 && Chinese_chess_q_to == Chinese_chess_q + 1) || (Chinese_chess_p_to == Chinese_chess_p - 2 && Chinese_chess_q_to == Chinese_chess_q - 1))  //上上右与上上左
		{
			if (Chinese_chess_qp[Chinese_chess_p - 1][Chinese_chess_q].player)
			{
				return 0;
			}
			else
			{
				return 1;
			}
		}
		else if ((Chinese_chess_p_to == Chinese_chess_p - 1 && Chinese_chess_q_to == Chinese_chess_q + 2) || (Chinese_chess_p_to == Chinese_chess_p + 1 && Chinese_chess_q_to == Chinese_chess_q + 2))  //右右上和右右下
		{
			if (Chinese_chess_qp[Chinese_chess_p][Chinese_chess_q + 1].player)
			{
				return 0;
			}
			else
			{
				return 1;
			}
		}
		else if ((Chinese_chess_p_to == Chinese_chess_p + 2 && Chinese_chess_q_to == Chinese_chess_q + 1) || (Chinese_chess_p_to == Chinese_chess_p + 2 && Chinese_chess_q_to == Chinese_chess_q - 1))  //下下右与下下左
		{
			if (Chinese_chess_qp[Chinese_chess_p + 1][Chinese_chess_q].player)
			{
				return 0;
			}
			else
			{
				return 1;
			}
		}
		else if ((Chinese_chess_p_to == Chinese_chess_p - 1 && Chinese_chess_q_to == Chinese_chess_q - 2) || (Chinese_chess_p_to == Chinese_chess_p + 1 && Chinese_chess_q_to == Chinese_chess_q - 2))  //左左上和左左下
		{
			if (Chinese_chess_qp[Chinese_chess_p][Chinese_chess_q - 1].player)
			{
				return 0;
			}
			else
			{
				return 1;
			}
		}
		else
		{
			return 0;
		}
	}
	else if (Chinese_chess_qp[Chinese_chess_p][Chinese_chess_q].piece == "elephant")
	{
		if (Chinese_chess_p_to > 5)  //不准过界
		{
			return 0;
		}
		if (Chinese_chess_p_to == Chinese_chess_p - 2 && Chinese_chess_q_to == Chinese_chess_q + 2)  //右上
		{
			if (Chinese_chess_qp[Chinese_chess_p - 1][Chinese_chess_q + 1].player)
			{
				return 0;
			}
			else
			{
				return 1;
			}
		}
		if (Chinese_chess_p_to == Chinese_chess_p + 2 && Chinese_chess_q_to == Chinese_chess_q + 2)  //右下
		{
			if (Chinese_chess_qp[Chinese_chess_p + 1][Chinese_chess_q + 1].player)
			{
				return 0;
			}
			else
			{
				return 1;
			}
		}
		if (Chinese_chess_p_to == Chinese_chess_p + 2 && Chinese_chess_q_to == Chinese_chess_q - 2)  //左下
		{
			if (Chinese_chess_qp[Chinese_chess_p + 1][Chinese_chess_q - 1].player)
			{
				return 0;
			}
			else
			{
				return 1;
			}
		}
		if (Chinese_chess_p_to == Chinese_chess_p - 2 && Chinese_chess_q_to == Chinese_chess_q - 2)  //左上
		{
			if (Chinese_chess_qp[Chinese_chess_p - 1][Chinese_chess_q - 1].player)
			{
				return 0;
			}
			else
			{
				return 1;
			}
		}
		else
		{
			return 0;
		}
	}
	else if (Chinese_chess_qp[Chinese_chess_p][Chinese_chess_q].piece == "guard")
	{
		if (Chinese_chess_p_to > 3 || Chinese_chess_q_to < 4 || Chinese_chess_q_to > 6)  //不准走出宫
		{
			return 0;
		}
		if (Chinese_chess_p_to == Chinese_chess_p - 1 && Chinese_chess_q_to == Chinese_chess_q + 1)       //右上
		{
			return 1;
		}
		else if (Chinese_chess_p_to == Chinese_chess_p + 1 && Chinese_chess_q_to == Chinese_chess_q + 1)  //右下
		{
			return 1;
		}
		else if (Chinese_chess_p_to == Chinese_chess_p + 1 && Chinese_chess_q_to == Chinese_chess_q - 1)  //左下
		{
			return 1;
		}
		else if (Chinese_chess_p_to == Chinese_chess_p - 1 && Chinese_chess_q_to == Chinese_chess_q - 1)  //左上
		{
			return 1;
		}
		else
		{
			return 0;
		}
	}
	else if (Chinese_chess_qp[Chinese_chess_p][Chinese_chess_q].piece == "general")
	{
		if ((Chinese_chess_p_to <= 3 && Chinese_chess_q_to >= 4 && Chinese_chess_q_to <= 6))  //不走出宫
		{
			if (Chinese_chess_p_to == Chinese_chess_p && Chinese_chess_q_to == Chinese_chess_q + 1)       //右
			{
				return 1;
			}
			else if (Chinese_chess_p_to == Chinese_chess_p + 1 && Chinese_chess_q_to == Chinese_chess_q)  //下
			{
				return 1;
			}
			else if (Chinese_chess_p_to == Chinese_chess_p && Chinese_chess_q_to == Chinese_chess_q - 1)  //左
			{
				return 1;
			}
			else if (Chinese_chess_p_to == Chinese_chess_p - 1 && Chinese_chess_q_to == Chinese_chess_q)  //上
			{
				return 1;
			}
			else
			{
				return 0;
			}
		}
		else
		{
			if (Chinese_chess_qp[Chinese_chess_p_to][Chinese_chess_q_to].piece == "general" && Chinese_chess_qp[Chinese_chess_p_to][Chinese_chess_q_to].player == 1 && Chinese_chess_q_to == Chinese_chess_q)
			{
				for (int i = Chinese_chess_p + 1 ; i < Chinese_chess_p_to - 1; i++)
				{
					if (Chinese_chess_qp[i][Chinese_chess_q].player)
					{
						return 0;
					}
				}
				return 1;
			}
			else
			{
				return 0;
			}
		}
	}
}

void Chinese_chess_PvE()
{

}

void Chinese_chess_PvP()
{
	setColor(3, 0);
	Chinese_chess_print();
	while(1)
	{
		Chinese_chess_player1();
		Chinese_chess_flash();
		Chinese_chess_win(2);
		if (Chinese_chess_flag)
		{
			setColor(2, 0);
			printf("%s获胜\n", Chinese_chess_winer1);
			return Chinese_chess_newgame();
		}
		Chinese_chess_player2();
		Chinese_chess_flash();
		Chinese_chess_win(1);
		if (Chinese_chess_flag)
		{
			setColor(2, 0);
			printf("%s获胜\n", Chinese_chess_winer2);
			return Chinese_chess_newgame();
		}
	}
}

void Chinese_chess_EvE()
{

}

void Chinese_chess_print()
{
	system("cls");
	for(int i = 0 ; i < 10 ; i++)
	{
		setColor(3, 0);
		if (i == 0)
		{
			printf("   ");
		}
		else
		{
			printf(" %d  ", i);
		}	
	}
	printf("\n\n");
	for(int i = 1 ; i <= 10 ; i++)
	{
		if (i == 6)
		{
			setColor(3, 0);
			printf("            楚河          汉界           \n\n");
		}
		for(int j = 0 ; j <= 9 ; j++)
		{
			if(j == 0)
			{
				setColor(3, 0);
				printf("%02d  ", i);
			}
			else
			{
				if(Chinese_chess_qp[i][j].player == 0)
				{
					printf("    ");
				}
				else if(Chinese_chess_qp[i][j].player == 1)
				{
					setColor(12, 0);
					if(Chinese_chess_qp[i][j].piece == "soldier")
					{
						printf("兵  "); 
					}
					else if(Chinese_chess_qp[i][j].piece == "connon")
					{
						printf("炮  "); 
					}
					else if(Chinese_chess_qp[i][j].piece == "car")
					{
						printf("車  "); 
					}
					else if(Chinese_chess_qp[i][j].piece == "horse")
					{
						printf("馬  "); 
					} 
					else if(Chinese_chess_qp[i][j].piece == "elephant")
					{
						printf("象  "); 
					}
					else if(Chinese_chess_qp[i][j].piece == "guard")
					{
						printf("士  "); 
					}
					else if(Chinese_chess_qp[i][j].piece == "general")
					{
						printf("帅  "); 
					}
				}
				else
				{
					setColor(6, 0);
					if(Chinese_chess_qp[i][j].piece == "soldier")
					{
						printf("卒  "); 
					}
					else if(Chinese_chess_qp[i][j].piece == "connon")
					{
						printf("炮  "); 
					}
					else if(Chinese_chess_qp[i][j].piece == "car")
					{
						printf("車  "); 
					}
					else if(Chinese_chess_qp[i][j].piece == "horse")
					{
						printf("馬  "); 
					} 
					else if(Chinese_chess_qp[i][j].piece == "elephant")
					{
						printf("相  "); 
					}
					else if(Chinese_chess_qp[i][j].piece == "guard")
					{
						printf("士  "); 
					}
					else if(Chinese_chess_qp[i][j].piece == "general")
					{
						printf("将  "); 
					}
				}
			}
		}
		printf("\n\n");
	}
}

void Chinese_chess_newgame()
{
	int more;
	setColor(3, 0);
	printf("再来一把不？\n1.确定\n2.滚\n");
	scanf("%d", &more);
	if (more < 1 || more > 2)
	{
		printf("输入错误\n");
		return Chinese_chess_newgame();
	}
	else
	{
		if (more - 2)
		{
			system("cls");
			return main();
		}
		else
		{
			exit(0);
		}
	}
}

void Chinese_chess_win(int t)  //查找敌方的将是否还在 
{
	Chinese_chess_flag = 1;
	for(int i = 1 ; i <= 10 ; i++)
	{
		for(int j = 1 ; j <= 9 ; j++)
		{
			if(Chinese_chess_qp[i][j].piece == "general")   //找到敌方的将就置零flag并退出 
			{
				if(Chinese_chess_qp[i][j].player == t)
				{
					Chinese_chess_flag = 0;
					break;
				}
			}
			if(Chinese_chess_flag == 0)
			{
				break;
			}
		}
	}
}

void Chinese_chess_flash()
{
	int last_i, last_j;
	if (Chinese_chess_p_to > Chinese_chess_p && abs(Chinese_chess_p_to - Chinese_chess_p) >= abs(Chinese_chess_q_to - Chinese_chess_q))  //下
	{
		int j = Chinese_chess_q;
		for (int i = Chinese_chess_p + 1; i <= Chinese_chess_p_to; i++)
		{
			last_i = i-1;
			last_j = j;
			if (Chinese_chess_q_to > Chinese_chess_q)									   //右
			{
				if (abs(Chinese_chess_q_to - last_j) == abs(Chinese_chess_p_to - last_i))  //如果下、右剩余格数相等
				{ 
					j++;                                                                  //下、右一起走
				}
			}
			else if (Chinese_chess_q_to < Chinese_chess_q)								   //左
			{
				if (abs(Chinese_chess_q_to - last_j) == abs(Chinese_chess_p_to - last_i))  //如果下、右剩余格数相等
				{
					j--;                                                                  //下、左一起走
				}
			}
			if (Chinese_chess_qp[i][j].player == 0 || (i == Chinese_chess_p_to && j == Chinese_chess_q_to))
			{
				Chinese_chess_qp[i][j] = Chinese_chess_qp[last_i][last_j];
				Chinese_chess_qp[last_i][last_j].piece = "none";
				Chinese_chess_qp[last_i][last_j].player = 0;
				Chinese_chess_print();
				if (i != Chinese_chess_p_to || j != Chinese_chess_q_to)
				{
					Sleep(300);
				}
			}
			else
			{
				i++;
				if (Chinese_chess_q_to > Chinese_chess_q)									   //右
				{
					if (abs(Chinese_chess_q_to - last_j) == abs(Chinese_chess_p_to - last_i))  //如果下、右剩余格数相等
					{
						j++;                                                                  //下、右一起走
					}
				}
				else if (Chinese_chess_q_to < Chinese_chess_q)								   //左
				{
					if (abs(Chinese_chess_q_to - last_j) == abs(Chinese_chess_p_to - last_i))  //如果下、右剩余格数相等
					{
						j--;                                                                  //下、左一起走
					}
				}
				Chinese_chess_qp[i][j] = Chinese_chess_qp[last_i][last_j];
				Chinese_chess_qp[last_i][last_j].piece = "none";
				Chinese_chess_qp[last_i][last_j].player = 0;
				Chinese_chess_print();
				if (i != Chinese_chess_p_to || j != Chinese_chess_q_to)
				{
					Sleep(300);
				}
			}
		}
	}
	else if (Chinese_chess_p_to < Chinese_chess_p && abs(Chinese_chess_p_to - Chinese_chess_p) >= abs(Chinese_chess_q_to - Chinese_chess_q))  //上
	{
		int j = Chinese_chess_q;
		for (int i = Chinese_chess_p - 1; i >= Chinese_chess_p_to; i--)
		{
			last_i = i+1;
			last_j = j;
			if (Chinese_chess_q_to > Chinese_chess_q)									   //右
			{
				if (abs(Chinese_chess_q_to - last_j) == abs(Chinese_chess_p_to - last_i))  //如果下、右剩余格数相等
				{
					j++;                                                                  //下、右一起走
				}
			}
			else if (Chinese_chess_q_to < Chinese_chess_q)								   //左
			{
				if (abs(Chinese_chess_q_to - last_j) == abs(Chinese_chess_p_to - last_i))  //如果下、右剩余格数相等
				{
					j--;                                                                  //下、左一起走
				}
			}
			if (Chinese_chess_qp[i][j].player == 0 || (i == Chinese_chess_p_to && j == Chinese_chess_q_to))
			{
				Chinese_chess_qp[i][j] = Chinese_chess_qp[last_i][last_j];
				Chinese_chess_qp[last_i][last_j].piece = "none";
				Chinese_chess_qp[last_i][last_j].player = 0;
				Chinese_chess_print();
				if (i != Chinese_chess_p_to || j != Chinese_chess_q_to)
				{
					Sleep(300);
				}
			}
			else
			{
				i--;
				if (Chinese_chess_q_to > Chinese_chess_q)									   //右
				{
					if (abs(Chinese_chess_q_to - last_j) == abs(Chinese_chess_p_to - last_i))  //如果下、右剩余格数相等
					{
						j++;                                                                  //下、右一起走
					}
				}
				else if (Chinese_chess_q_to < Chinese_chess_q)								   //左
				{
					if (abs(Chinese_chess_q_to - last_j) == abs(Chinese_chess_p_to - last_i))  //如果下、右剩余格数相等
					{
						j--;                                                                  //下、左一起走
					}
				}
				Chinese_chess_qp[i][j] = Chinese_chess_qp[last_i][last_j];
				Chinese_chess_qp[last_i][last_j].piece = "none";
				Chinese_chess_qp[last_i][last_j].player = 0;
				Chinese_chess_print();
				if (i != Chinese_chess_p_to || j != Chinese_chess_q_to)
				{
					Sleep(300);
				}
			}
		}
	}
	else if (Chinese_chess_q_to > Chinese_chess_q && abs(Chinese_chess_p_to - Chinese_chess_p) < abs(Chinese_chess_q_to - Chinese_chess_q))  //右
	{
		int j = Chinese_chess_p;
		for (int i = Chinese_chess_q + 1; i <= Chinese_chess_q_to; i++)
		{
			last_i = i-1;
			last_j = j;
			if (Chinese_chess_p_to > Chinese_chess_p)									   //下
			{
				if (abs(Chinese_chess_q_to - last_i) == abs(Chinese_chess_p_to - last_j))  //如果下、右剩余格数相等
				{
					j++;                                                                  //下、右一起走
				}
			}
			else if (Chinese_chess_p_to < Chinese_chess_p)								   //左
			{
				if (abs(Chinese_chess_q_to - last_i) == abs(Chinese_chess_p_to - last_j))  //如果下、右剩余格数相等
				{
					j--;                                                                  //上、右一起走
				}
			}
			if (Chinese_chess_qp[j][i].player == 0 || (j == Chinese_chess_p_to && i == Chinese_chess_q_to))
			{
				Chinese_chess_qp[j][i] = Chinese_chess_qp[last_j][last_i];
				Chinese_chess_qp[last_j][last_i].piece = "none";
				Chinese_chess_qp[last_j][last_i].player = 0;
				Chinese_chess_print();
				if (j != Chinese_chess_p_to || i != Chinese_chess_q_to)
				{
					Sleep(300);
				}
			}
			else
			{
				i++;
				if (Chinese_chess_p_to > Chinese_chess_p)									   //下
				{
					if (abs(Chinese_chess_q_to - last_i) == abs(Chinese_chess_p_to - last_j))  //如果下、右剩余格数相等
					{
						j++;                                                                  //下、右一起走
					}
				}
				else if (Chinese_chess_p_to < Chinese_chess_p)								   //左
				{
					if (abs(Chinese_chess_q_to - last_i) == abs(Chinese_chess_p_to - last_j))  //如果下、右剩余格数相等
					{
						j--;                                                                  //上、右一起走
					}
				}
				Chinese_chess_qp[j][i] = Chinese_chess_qp[last_j][last_i];
				Chinese_chess_qp[last_j][last_i].piece = "none";
				Chinese_chess_qp[last_j][last_i].player = 0;
				Chinese_chess_print();
				if (j != Chinese_chess_p_to || i != Chinese_chess_q_to)
				{
					Sleep(300);
				}
			}
		}
	}
	else if (Chinese_chess_q_to < Chinese_chess_q && abs(Chinese_chess_p_to - Chinese_chess_p) < abs(Chinese_chess_q_to - Chinese_chess_q))  //左
	{
		int j = Chinese_chess_p;
		for (int i = Chinese_chess_q - 1; i >= Chinese_chess_q_to; i--)
		{
			last_i = i+1;
			last_j = j;
			if (Chinese_chess_p_to > Chinese_chess_p)									   //下
			{
				if (abs(Chinese_chess_q_to - last_i) == abs(Chinese_chess_p_to - last_j))  //如果下、右剩余格数相等
				{
					j++;                                                                  //下、左一起走
				}
			}
			else if (Chinese_chess_p_to < Chinese_chess_p)								   //左
			{
				if (abs(Chinese_chess_q_to - last_i) == abs(Chinese_chess_p_to - last_j))  //如果下、右剩余格数相等
				{
					j--;                                                                  //上、左一起走
				}
			}
			if (Chinese_chess_qp[j][i].player == 0 || (j == Chinese_chess_p_to && i == Chinese_chess_q_to))
			{
				Chinese_chess_qp[j][i] = Chinese_chess_qp[last_j][last_i];
				Chinese_chess_qp[last_j][last_i].piece = "none";
				Chinese_chess_qp[last_j][last_i].player = 0;
				Chinese_chess_print();
				if (j != Chinese_chess_p_to || i != Chinese_chess_q_to)
				{
					Sleep(300);
				}
			}
			else
			{
				i--;
				if (Chinese_chess_p_to > Chinese_chess_p)									   //下
				{
					if (abs(Chinese_chess_q_to - last_i) == abs(Chinese_chess_p_to - last_j))  //如果下、右剩余格数相等
					{
						j++;                                                                  //下、左一起走
					}
				}
				else if (Chinese_chess_p_to < Chinese_chess_p)								   //左
				{
					if (abs(Chinese_chess_q_to - last_i) == abs(Chinese_chess_p_to - last_j))  //如果下、右剩余格数相等
					{
						j--;                                                                  //上、左一起走
					}
				}
				Chinese_chess_qp[j][i] = Chinese_chess_qp[last_j][last_i];
				Chinese_chess_qp[last_j][last_i].piece = "none";
				Chinese_chess_qp[last_j][last_i].player = 0;
				Chinese_chess_print();
				if (j != Chinese_chess_p_to || i != Chinese_chess_q_to)
				{
					Sleep(300);
				}
			}
		}
	}
}

void Chinese_chess_E()
{

}
