#include "Chinese_chess_init.h"

int Chinese_chess_main();
int Chinese_chess_menu(); //���˵�
void Chinese_chess_clean();  //��ʼ������
void Chinese_chess_newgame();  //����Ϸ
void Chinese_chess_win(int t);  //ʤ���ж�  t:����1 ����2
int Chinese_chess_player1();  //player1����
int Chinese_chess_player2();  //...
void Chinese_chess_PvE();
void Chinese_chess_PvP();
void Chinese_chess_EvE();
void Chinese_chess_E();  //��������
int Chinese_chess_move_rule1();  //���player1�����ƶ��Ƿ�Υ��
int Chinese_chess_move_rule2();  //���player2�����ƶ��Ƿ�Υ��
void Chinese_chess_print();  //��ӡ����
void Chinese_chess_flash();  //���Ӷ���

int Chinese_chess_flag;  //flag:��Ϸ�Ƿ����
int Chinese_chess_p, Chinese_chess_q, Chinese_chess_choice;  //n:���̴�С
int Chinese_chess_p_to, Chinese_chess_q_to;  //����Ҫ�ƶ�����λ��
char Chinese_chess_winer1[9], Chinese_chess_winer2[9];  //��ս˫������

struct qpstatus {
	int player;  //pleyer=0����;pleyer=1/2һ������
	char* piece;  //��ʲô��
}Chinese_chess_qp[12][11];  //����Ϊ10*9

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
	printf("***************�й�����****************\n\n��ѡ��ģʽ\n1.PvE\n2.PvP\n3.EvE\n\n");
	scanf("%d", &Chinese_chess_choice);
	if (Chinese_chess_choice == 1)
	{
		sprintf(Chinese_chess_winer1, "���");
		sprintf(Chinese_chess_winer2, "����");
		printf("ûд��\n");
		return main();
	}
	else if (Chinese_chess_choice == 2)
	{
		sprintf(Chinese_chess_winer1, "���1");
		sprintf(Chinese_chess_winer2, "���2");
		Chinese_chess_PvP();
		return main();
	}
	else if (Chinese_chess_choice == 3)
	{
		sprintf(Chinese_chess_winer1, "����1");
		sprintf(Chinese_chess_winer2, "����2");
		printf("ûд��\n");
		return main();
	}
	else
	{
		printf("������������\n");
		return main();
	}
}

void Chinese_chess_clean()
{
	Chinese_chess_flag = 0;
	for (int i = 0 ; i < 12 ; i++)   //���� 
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
	printf("%s��ѡ��Ҫ�ƶ������ӣ��� �У�", Chinese_chess_winer1);
	scanf("%d%d", &Chinese_chess_p, &Chinese_chess_q);
	Chinese_chess_print();
	setColor(3, 0);
	if (Chinese_chess_qp[Chinese_chess_p][Chinese_chess_q].player == 0)
	{
		printf("�˴�û������\n");
		return Chinese_chess_player1();
	}
	else if (Chinese_chess_qp[Chinese_chess_p][Chinese_chess_q].player == 2)
	{
		printf("�˴������ǶԷ���\n");
		return Chinese_chess_player1();
	}
	else if (Chinese_chess_p < 1 || Chinese_chess_p > 10 || Chinese_chess_q < 1 || Chinese_chess_q > 9)
	{
		printf("�������̷�Χ\n");
		return Chinese_chess_player1();
	}
	else
	{
		printf("��ѡ�����Ҫ�ƶ�����λ��\n");
		scanf("%d%d", &Chinese_chess_p_to, &Chinese_chess_q_to);
		if(Chinese_chess_move_rule1() == 0)
	{
			printf("�����ƶ������Ϲ���,������ѡ��\n");
			return Chinese_chess_player1();
		 } 
	}
}

int Chinese_chess_player2()
{
	setColor(3, 0);
	printf("%s��ѡ��Ҫ�ƶ������ӣ��� �У�", Chinese_chess_winer2);
	scanf("%d%d", &Chinese_chess_p, &Chinese_chess_q);
	if (Chinese_chess_qp[Chinese_chess_p][Chinese_chess_q].player == 0)
	{
		printf("�˴�û������\n");
		return Chinese_chess_player2();
	}
	else if (Chinese_chess_qp[Chinese_chess_p][Chinese_chess_q].player == 1)
	{
		printf("�˴������ǶԷ���\n");
		return Chinese_chess_player2();
	}
	else if (Chinese_chess_p < 1 || Chinese_chess_p > 10 || Chinese_chess_q < 1 || Chinese_chess_q > 9)
	{
		printf("�������̷�Χ\n");
		return Chinese_chess_player2();
	}
	else
	{
		printf("��ѡ�����Ҫ�ƶ�����λ��\n");
		scanf("%d%d", &Chinese_chess_p_to, &Chinese_chess_q_to);
		if(Chinese_chess_move_rule2() == 0)
		{
			printf("�����ƶ������Ϲ���,������ѡ��\n");
			return Chinese_chess_player2();
		 } 
	}
}

int Chinese_chess_move_rule1()
{
	int obstacle = 0;  //ͳ�Ƴ�������Ŀ���֮����ϰ�������
	if (Chinese_chess_p_to < 1 && Chinese_chess_p_to > 10 && Chinese_chess_q_to < 1 && Chinese_chess_q_to > 9)  //�߳�����
	{
		return 0;
	}
	if (Chinese_chess_qp[Chinese_chess_p_to][Chinese_chess_q_to].player == 1)  //Ŀ�ĵ����Լ�������
	{
		return 0;
	}
	if (Chinese_chess_qp[Chinese_chess_p][Chinese_chess_q].piece == "soldier")  //С���ƶ�����
	{
		if (Chinese_chess_p > 5) //δ�����Ӻ���
		{
			if (Chinese_chess_p_to == Chinese_chess_p - 1 && Chinese_chess_q_to == Chinese_chess_q)  //ֻ׼��ǰ��һ��
			{
				return 1;
			}
			else
			{
				return 0;
			}
		}
		else  //����
		{
			if ((Chinese_chess_p_to == Chinese_chess_p - 1 && Chinese_chess_q_to == Chinese_chess_q) || (Chinese_chess_p_to == Chinese_chess_p && Chinese_chess_q_to == Chinese_chess_q + 1) || (Chinese_chess_p_to == Chinese_chess_p && Chinese_chess_q_to == Chinese_chess_q - 1))  //ֻ׼��ǰ��������
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
		if (Chinese_chess_p != Chinese_chess_p_to && Chinese_chess_q != Chinese_chess_q_to)  //û����ֱ��
		{
			return 0;
		}
		if (Chinese_chess_p == Chinese_chess_p_to)  //������
		{
			if (Chinese_chess_q_to > Chinese_chess_q)  //������ 
			{
				for (int i = Chinese_chess_q + 1; i < Chinese_chess_q_to; i++)  //ͳ��·�����ϰ�������
				{
					if (Chinese_chess_qp[Chinese_chess_p][i].player)
					{
						obstacle++;
					}
				}
			}
			else                                   //������ 
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
		if (Chinese_chess_q == Chinese_chess_q_to)  //������
		{
			if (Chinese_chess_p_to > Chinese_chess_p)  //������ 
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
				for (int i = Chinese_chess_p - 1; i > Chinese_chess_p_to; i--)  //������ 
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
		if (Chinese_chess_p != Chinese_chess_p_to && Chinese_chess_q != Chinese_chess_q_to)  //û����ֱ��
		{
			return 0;
		}
		if (Chinese_chess_p == Chinese_chess_p_to)  //������
		{
			if (Chinese_chess_q_to > Chinese_chess_q)  //������ 
			{
				for (int i = Chinese_chess_q + 1; i < Chinese_chess_q_to; i++)  //ͳ��·�����ϰ�������
				{
					if (Chinese_chess_qp[Chinese_chess_p][i].player)
					{
						obstacle++;
					}
				}
			}
			else                                   //������ 
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
		if (Chinese_chess_q == Chinese_chess_q_to)  //������
		{
			if (Chinese_chess_p_to > Chinese_chess_p)  //������ 
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
				for (int i = Chinese_chess_p - 1; i > Chinese_chess_p_to; i--)  //������ 
				{
					if (Chinese_chess_qp[i][Chinese_chess_q].player)
					{
						obstacle++;
					}
				}
			}
		}
		if (obstacle != 0)  //�ϰ���������Ϊ0
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
		if ((Chinese_chess_p_to == Chinese_chess_p - 2 && Chinese_chess_q_to == Chinese_chess_q + 1) || (Chinese_chess_p_to == Chinese_chess_p - 2 && Chinese_chess_q_to == Chinese_chess_q - 1))  //��������������
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
		else if ((Chinese_chess_p_to == Chinese_chess_p - 1 && Chinese_chess_q_to == Chinese_chess_q + 2) || (Chinese_chess_p_to == Chinese_chess_p + 1 && Chinese_chess_q_to == Chinese_chess_q + 2))  //�����Ϻ�������
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
		else if ((Chinese_chess_p_to == Chinese_chess_p + 2 && Chinese_chess_q_to == Chinese_chess_q + 1) || (Chinese_chess_p_to == Chinese_chess_p + 2 && Chinese_chess_q_to == Chinese_chess_q - 1))  //��������������
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
		else if ((Chinese_chess_p_to == Chinese_chess_p - 1 && Chinese_chess_q_to == Chinese_chess_q - 2) || (Chinese_chess_p_to == Chinese_chess_p + 1 && Chinese_chess_q_to == Chinese_chess_q - 2))  //�����Ϻ�������
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
		if (Chinese_chess_p_to <= 5)  //��׼����
		{
			return 0;
		}
		if (Chinese_chess_p_to == Chinese_chess_p - 2 && Chinese_chess_q_to == Chinese_chess_q + 2)  //����
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
		if (Chinese_chess_p_to == Chinese_chess_p + 2 && Chinese_chess_q_to == Chinese_chess_q + 2)  //����
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
		if (Chinese_chess_p_to == Chinese_chess_p + 2 && Chinese_chess_q_to == Chinese_chess_q - 2)  //����
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
		if (Chinese_chess_p_to == Chinese_chess_p - 2 && Chinese_chess_q_to == Chinese_chess_q - 2)  //����
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
		if (Chinese_chess_p_to < 8 || Chinese_chess_q_to < 4 || Chinese_chess_q_to > 6)  //��׼�߳���
		{
			return 0;
		}
		if (Chinese_chess_p_to == Chinese_chess_p - 1 && Chinese_chess_q_to == Chinese_chess_q + 1)       //����
		{
			return 1;
		}
		else if (Chinese_chess_p_to == Chinese_chess_p + 1 && Chinese_chess_q_to == Chinese_chess_q + 1)  //����
		{
			return 1;
		}
		else if (Chinese_chess_p_to == Chinese_chess_p + 1 && Chinese_chess_q_to == Chinese_chess_q - 1)  //����
		{
			return 1;
		}
		else if (Chinese_chess_p_to == Chinese_chess_p - 1 && Chinese_chess_q_to == Chinese_chess_q - 1)  //����
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
		if ((Chinese_chess_p_to >= 8 && Chinese_chess_q_to >= 4 && Chinese_chess_q_to <= 6))  //���߳���
		{
			if (Chinese_chess_p_to == Chinese_chess_p && Chinese_chess_q_to == Chinese_chess_q + 1)       //��
			{
				return 1;
			}
			else if (Chinese_chess_p_to == Chinese_chess_p + 1 && Chinese_chess_q_to == Chinese_chess_q)  //��
			{
				return 1;
			}
			else if (Chinese_chess_p_to == Chinese_chess_p && Chinese_chess_q_to == Chinese_chess_q - 1)  //��
			{
				return 1;
			}
			else if (Chinese_chess_p_to == Chinese_chess_p - 1 && Chinese_chess_q_to == Chinese_chess_q)  //��
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
	int obstacle = 0;  //ͳ�Ƴ�������Ŀ���֮����ϰ�������
	if (Chinese_chess_p_to < 1 || Chinese_chess_p_to > 10 || Chinese_chess_q_to < 1 || Chinese_chess_q_to > 9)  //�߳�����
	{
		return 0;
	}
	if (Chinese_chess_qp[Chinese_chess_p_to][Chinese_chess_q_to].player == 2)  //Ŀ�ĵ����Լ�������
	{
		return 0;
	}
	if (Chinese_chess_qp[Chinese_chess_p][Chinese_chess_q].piece == "soldier")  //С���ƶ�����
	{
		if (Chinese_chess_p <= 5) //δ�����Ӻ���
		{
			if (Chinese_chess_p_to == Chinese_chess_p + 1 && Chinese_chess_q_to == Chinese_chess_q)  //ֻ׼��ǰ��һ��
			{
				return 1;
			}
			else
			{
				return 0;
			}
		}
		else  //����
		{
			if ((Chinese_chess_p_to == Chinese_chess_p + 1 && Chinese_chess_q_to == Chinese_chess_q) || (Chinese_chess_p_to == Chinese_chess_p && Chinese_chess_q_to == Chinese_chess_q + 1) || (Chinese_chess_p_to == Chinese_chess_p && Chinese_chess_q_to == Chinese_chess_q - 1))  //ֻ׼��ǰ��������
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
		if (Chinese_chess_p != Chinese_chess_p_to && Chinese_chess_q != Chinese_chess_q_to)  //û����ֱ��
		{
			return 0;
		}
		if (Chinese_chess_p == Chinese_chess_p_to)  //������
		{
			if (Chinese_chess_q_to > Chinese_chess_q)  //������ 
			{
				for (int i = Chinese_chess_q + 1; i < Chinese_chess_q_to; i++)  //ͳ��·�����ϰ�������
				{
					if (Chinese_chess_qp[Chinese_chess_p][i].player)
					{
						obstacle++;
					}
				}
			}
			else                                   //������ 
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
		if (Chinese_chess_q == Chinese_chess_q_to)  //������
		{
			if (Chinese_chess_p_to > Chinese_chess_p)  //������ 
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
				for (int i = Chinese_chess_p - 1; i > Chinese_chess_p_to; i--)  //������ 
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
		if (Chinese_chess_p != Chinese_chess_p_to && Chinese_chess_q != Chinese_chess_q_to)  //û����ֱ��
		{
			return 0;
		}
		if (Chinese_chess_p == Chinese_chess_p_to)  //������
		{
			if(Chinese_chess_q_to > Chinese_chess_q)  //������ 
			{
				for (int i = Chinese_chess_q + 1; i < Chinese_chess_q_to; i++)  //ͳ��·�����ϰ�������
				{
					if (Chinese_chess_qp[Chinese_chess_p][i].player)
					{
						obstacle++;
					}
				}
			}
			else                                   //������ 
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
		if (Chinese_chess_q == Chinese_chess_q_to)  //������
		{
			if(Chinese_chess_p_to > Chinese_chess_p)  //������ 
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
				for (int i = Chinese_chess_p - 1; i > Chinese_chess_p_to; i--)  //������ 
				{
					if (Chinese_chess_qp[i][Chinese_chess_q].player)
					{
						obstacle++;
					}
				}
			}
		}
		if (obstacle != 0)  //�ϰ���������Ϊ0
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
		if ((Chinese_chess_p_to == Chinese_chess_p - 2 && Chinese_chess_q_to == Chinese_chess_q + 1) || (Chinese_chess_p_to == Chinese_chess_p - 2 && Chinese_chess_q_to == Chinese_chess_q - 1))  //��������������
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
		else if ((Chinese_chess_p_to == Chinese_chess_p - 1 && Chinese_chess_q_to == Chinese_chess_q + 2) || (Chinese_chess_p_to == Chinese_chess_p + 1 && Chinese_chess_q_to == Chinese_chess_q + 2))  //�����Ϻ�������
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
		else if ((Chinese_chess_p_to == Chinese_chess_p + 2 && Chinese_chess_q_to == Chinese_chess_q + 1) || (Chinese_chess_p_to == Chinese_chess_p + 2 && Chinese_chess_q_to == Chinese_chess_q - 1))  //��������������
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
		else if ((Chinese_chess_p_to == Chinese_chess_p - 1 && Chinese_chess_q_to == Chinese_chess_q - 2) || (Chinese_chess_p_to == Chinese_chess_p + 1 && Chinese_chess_q_to == Chinese_chess_q - 2))  //�����Ϻ�������
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
		if (Chinese_chess_p_to > 5)  //��׼����
		{
			return 0;
		}
		if (Chinese_chess_p_to == Chinese_chess_p - 2 && Chinese_chess_q_to == Chinese_chess_q + 2)  //����
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
		if (Chinese_chess_p_to == Chinese_chess_p + 2 && Chinese_chess_q_to == Chinese_chess_q + 2)  //����
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
		if (Chinese_chess_p_to == Chinese_chess_p + 2 && Chinese_chess_q_to == Chinese_chess_q - 2)  //����
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
		if (Chinese_chess_p_to == Chinese_chess_p - 2 && Chinese_chess_q_to == Chinese_chess_q - 2)  //����
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
		if (Chinese_chess_p_to > 3 || Chinese_chess_q_to < 4 || Chinese_chess_q_to > 6)  //��׼�߳���
		{
			return 0;
		}
		if (Chinese_chess_p_to == Chinese_chess_p - 1 && Chinese_chess_q_to == Chinese_chess_q + 1)       //����
		{
			return 1;
		}
		else if (Chinese_chess_p_to == Chinese_chess_p + 1 && Chinese_chess_q_to == Chinese_chess_q + 1)  //����
		{
			return 1;
		}
		else if (Chinese_chess_p_to == Chinese_chess_p + 1 && Chinese_chess_q_to == Chinese_chess_q - 1)  //����
		{
			return 1;
		}
		else if (Chinese_chess_p_to == Chinese_chess_p - 1 && Chinese_chess_q_to == Chinese_chess_q - 1)  //����
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
		if ((Chinese_chess_p_to <= 3 && Chinese_chess_q_to >= 4 && Chinese_chess_q_to <= 6))  //���߳���
		{
			if (Chinese_chess_p_to == Chinese_chess_p && Chinese_chess_q_to == Chinese_chess_q + 1)       //��
			{
				return 1;
			}
			else if (Chinese_chess_p_to == Chinese_chess_p + 1 && Chinese_chess_q_to == Chinese_chess_q)  //��
			{
				return 1;
			}
			else if (Chinese_chess_p_to == Chinese_chess_p && Chinese_chess_q_to == Chinese_chess_q - 1)  //��
			{
				return 1;
			}
			else if (Chinese_chess_p_to == Chinese_chess_p - 1 && Chinese_chess_q_to == Chinese_chess_q)  //��
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
			printf("%s��ʤ\n", Chinese_chess_winer1);
			return Chinese_chess_newgame();
		}
		Chinese_chess_player2();
		Chinese_chess_flash();
		Chinese_chess_win(1);
		if (Chinese_chess_flag)
		{
			setColor(2, 0);
			printf("%s��ʤ\n", Chinese_chess_winer2);
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
			printf("            ����          ����           \n\n");
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
						printf("��  "); 
					}
					else if(Chinese_chess_qp[i][j].piece == "connon")
					{
						printf("��  "); 
					}
					else if(Chinese_chess_qp[i][j].piece == "car")
					{
						printf("܇  "); 
					}
					else if(Chinese_chess_qp[i][j].piece == "horse")
					{
						printf("�R  "); 
					} 
					else if(Chinese_chess_qp[i][j].piece == "elephant")
					{
						printf("��  "); 
					}
					else if(Chinese_chess_qp[i][j].piece == "guard")
					{
						printf("ʿ  "); 
					}
					else if(Chinese_chess_qp[i][j].piece == "general")
					{
						printf("˧  "); 
					}
				}
				else
				{
					setColor(6, 0);
					if(Chinese_chess_qp[i][j].piece == "soldier")
					{
						printf("��  "); 
					}
					else if(Chinese_chess_qp[i][j].piece == "connon")
					{
						printf("��  "); 
					}
					else if(Chinese_chess_qp[i][j].piece == "car")
					{
						printf("܇  "); 
					}
					else if(Chinese_chess_qp[i][j].piece == "horse")
					{
						printf("�R  "); 
					} 
					else if(Chinese_chess_qp[i][j].piece == "elephant")
					{
						printf("��  "); 
					}
					else if(Chinese_chess_qp[i][j].piece == "guard")
					{
						printf("ʿ  "); 
					}
					else if(Chinese_chess_qp[i][j].piece == "general")
					{
						printf("��  "); 
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
	printf("����һ�Ѳ���\n1.ȷ��\n2.��\n");
	scanf("%d", &more);
	if (more < 1 || more > 2)
	{
		printf("�������\n");
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

void Chinese_chess_win(int t)  //���ҵз��Ľ��Ƿ��� 
{
	Chinese_chess_flag = 1;
	for(int i = 1 ; i <= 10 ; i++)
	{
		for(int j = 1 ; j <= 9 ; j++)
		{
			if(Chinese_chess_qp[i][j].piece == "general")   //�ҵ��з��Ľ�������flag���˳� 
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
	if (Chinese_chess_p_to > Chinese_chess_p && abs(Chinese_chess_p_to - Chinese_chess_p) >= abs(Chinese_chess_q_to - Chinese_chess_q))  //��
	{
		int j = Chinese_chess_q;
		for (int i = Chinese_chess_p + 1; i <= Chinese_chess_p_to; i++)
		{
			last_i = i-1;
			last_j = j;
			if (Chinese_chess_q_to > Chinese_chess_q)									   //��
			{
				if (abs(Chinese_chess_q_to - last_j) == abs(Chinese_chess_p_to - last_i))  //����¡���ʣ��������
				{ 
					j++;                                                                  //�¡���һ����
				}
			}
			else if (Chinese_chess_q_to < Chinese_chess_q)								   //��
			{
				if (abs(Chinese_chess_q_to - last_j) == abs(Chinese_chess_p_to - last_i))  //����¡���ʣ��������
				{
					j--;                                                                  //�¡���һ����
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
				if (Chinese_chess_q_to > Chinese_chess_q)									   //��
				{
					if (abs(Chinese_chess_q_to - last_j) == abs(Chinese_chess_p_to - last_i))  //����¡���ʣ��������
					{
						j++;                                                                  //�¡���һ����
					}
				}
				else if (Chinese_chess_q_to < Chinese_chess_q)								   //��
				{
					if (abs(Chinese_chess_q_to - last_j) == abs(Chinese_chess_p_to - last_i))  //����¡���ʣ��������
					{
						j--;                                                                  //�¡���һ����
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
	else if (Chinese_chess_p_to < Chinese_chess_p && abs(Chinese_chess_p_to - Chinese_chess_p) >= abs(Chinese_chess_q_to - Chinese_chess_q))  //��
	{
		int j = Chinese_chess_q;
		for (int i = Chinese_chess_p - 1; i >= Chinese_chess_p_to; i--)
		{
			last_i = i+1;
			last_j = j;
			if (Chinese_chess_q_to > Chinese_chess_q)									   //��
			{
				if (abs(Chinese_chess_q_to - last_j) == abs(Chinese_chess_p_to - last_i))  //����¡���ʣ��������
				{
					j++;                                                                  //�¡���һ����
				}
			}
			else if (Chinese_chess_q_to < Chinese_chess_q)								   //��
			{
				if (abs(Chinese_chess_q_to - last_j) == abs(Chinese_chess_p_to - last_i))  //����¡���ʣ��������
				{
					j--;                                                                  //�¡���һ����
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
				if (Chinese_chess_q_to > Chinese_chess_q)									   //��
				{
					if (abs(Chinese_chess_q_to - last_j) == abs(Chinese_chess_p_to - last_i))  //����¡���ʣ��������
					{
						j++;                                                                  //�¡���һ����
					}
				}
				else if (Chinese_chess_q_to < Chinese_chess_q)								   //��
				{
					if (abs(Chinese_chess_q_to - last_j) == abs(Chinese_chess_p_to - last_i))  //����¡���ʣ��������
					{
						j--;                                                                  //�¡���һ����
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
	else if (Chinese_chess_q_to > Chinese_chess_q && abs(Chinese_chess_p_to - Chinese_chess_p) < abs(Chinese_chess_q_to - Chinese_chess_q))  //��
	{
		int j = Chinese_chess_p;
		for (int i = Chinese_chess_q + 1; i <= Chinese_chess_q_to; i++)
		{
			last_i = i-1;
			last_j = j;
			if (Chinese_chess_p_to > Chinese_chess_p)									   //��
			{
				if (abs(Chinese_chess_q_to - last_i) == abs(Chinese_chess_p_to - last_j))  //����¡���ʣ��������
				{
					j++;                                                                  //�¡���һ����
				}
			}
			else if (Chinese_chess_p_to < Chinese_chess_p)								   //��
			{
				if (abs(Chinese_chess_q_to - last_i) == abs(Chinese_chess_p_to - last_j))  //����¡���ʣ��������
				{
					j--;                                                                  //�ϡ���һ����
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
				if (Chinese_chess_p_to > Chinese_chess_p)									   //��
				{
					if (abs(Chinese_chess_q_to - last_i) == abs(Chinese_chess_p_to - last_j))  //����¡���ʣ��������
					{
						j++;                                                                  //�¡���һ����
					}
				}
				else if (Chinese_chess_p_to < Chinese_chess_p)								   //��
				{
					if (abs(Chinese_chess_q_to - last_i) == abs(Chinese_chess_p_to - last_j))  //����¡���ʣ��������
					{
						j--;                                                                  //�ϡ���һ����
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
	else if (Chinese_chess_q_to < Chinese_chess_q && abs(Chinese_chess_p_to - Chinese_chess_p) < abs(Chinese_chess_q_to - Chinese_chess_q))  //��
	{
		int j = Chinese_chess_p;
		for (int i = Chinese_chess_q - 1; i >= Chinese_chess_q_to; i--)
		{
			last_i = i+1;
			last_j = j;
			if (Chinese_chess_p_to > Chinese_chess_p)									   //��
			{
				if (abs(Chinese_chess_q_to - last_i) == abs(Chinese_chess_p_to - last_j))  //����¡���ʣ��������
				{
					j++;                                                                  //�¡���һ����
				}
			}
			else if (Chinese_chess_p_to < Chinese_chess_p)								   //��
			{
				if (abs(Chinese_chess_q_to - last_i) == abs(Chinese_chess_p_to - last_j))  //����¡���ʣ��������
				{
					j--;                                                                  //�ϡ���һ����
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
				if (Chinese_chess_p_to > Chinese_chess_p)									   //��
				{
					if (abs(Chinese_chess_q_to - last_i) == abs(Chinese_chess_p_to - last_j))  //����¡���ʣ��������
					{
						j++;                                                                  //�¡���һ����
					}
				}
				else if (Chinese_chess_p_to < Chinese_chess_p)								   //��
				{
					if (abs(Chinese_chess_q_to - last_i) == abs(Chinese_chess_p_to - last_j))  //����¡���ʣ��������
					{
						j--;                                                                  //�ϡ���һ����
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
