 #include "Gobang_init.h"

void Gobang_computer()
{
	srand((unsigned int) time(NULL));
	Gobang_p = rand() % Gobang_n+1;
	Gobang_q = rand() % Gobang_n+1;
	while(Gobang_qp[Gobang_p][Gobang_q])
	{
		Gobang_p = rand() % Gobang_n+1;
		Gobang_q = rand() % Gobang_n+1;
	}
	Gobang_TheFirstStep[Gobang_k]++;
}

void Gobang_computermaster1()
{
	int cm1time = 0, temp1, temp2, temp, ifGoOn = 0, OnlyToRand = 0, arrp, arrq, enough = 0;
	for(int i = Gobang_laststepp - 1 ; i <= Gobang_laststepp+1 ; i++)
	{
		for(int j = Gobang_laststepq - 1 ; j <= Gobang_laststepq+1 ; j++)
		{
			cm1time++;
			if(cm1time == 5)  continue;
			if(Gobang_qp[i][j] == Gobang_d+1)
			{
				switch(cm1time)
				{
					case 1:
					{
						while(Gobang_p == Gobang_LastManStepp[Gobang_k] && Gobang_q == Gobang_LastManStepq[Gobang_k])
						{
							if(enough > 1000) break;
							srand((unsigned) time(NULL));
							temp = rand()% 7 - 3;
							temp1 = Gobang_laststepp + temp;
							temp2 = Gobang_laststepq + temp;
							if(Gobang_qp[temp1][temp2] || temp1 < 1 || temp2 < 1 || temp1 > Gobang_n || temp2 > Gobang_n)
							{
								enough++;
								continue;
							}
							arrp = (Gobang_laststepp + temp1)/2;
							arrq = (Gobang_laststepq + temp2)/2;
							if(Gobang_qp[arrp][arrq] == Gobang_k+1 || Gobang_qp[arrp+1][arrq+1] == Gobang_k+1 || Gobang_qp[arrp-1][arrq-1] == Gobang_k+1)
							{
								enough++;
								continue;
							}
							else
							{
								Gobang_p = temp1;
								Gobang_q = temp2;
								ifGoOn = 1;
							}
						}
					}
					break;
					case 9:
					{
						while(Gobang_p == Gobang_LastManStepp[Gobang_k] && Gobang_q == Gobang_LastManStepq[Gobang_k])
						{
							if(enough > 1000) break;
							srand((unsigned) time(NULL));
							temp = rand()% 7 - 3;
							temp1 = Gobang_laststepp + temp;
							temp2 = Gobang_laststepq + temp;
							if(Gobang_qp[temp1][temp2] || temp1 < 1 || temp2 < 1 || temp1 > Gobang_n || temp2 > Gobang_n)
							{
								enough++;
								continue;
							}
							arrp = (Gobang_laststepp + temp1)/2;
							arrq = (Gobang_laststepq + temp2)/2;
							if(Gobang_qp[arrp][arrq] == Gobang_k+1 || Gobang_qp[arrp+1][arrq+1] == Gobang_k+1 || Gobang_qp[arrp-1][arrq-1] == Gobang_k+1)
							{
								enough++;
								continue;
							}
							else
							{
								Gobang_p = temp1;
								Gobang_q = temp2;
								ifGoOn = 1;
							}
						}
					}
					break;
					case 2:
					{
						while(Gobang_p == Gobang_LastManStepp[Gobang_k] && Gobang_q == Gobang_LastManStepq[Gobang_k])
						{
							if(enough > 1000) break;
							srand((unsigned) time(NULL));
							temp = rand()% 7 - 3;
							temp1 = Gobang_laststepp + temp;
							temp2 = Gobang_laststepq;
							if(Gobang_qp[temp1][temp2] || temp1 < 1 || temp2 < 1 || temp1 > Gobang_n || temp2 > Gobang_n)
							{
								enough++;
								continue;
							}
							arrp = (Gobang_laststepp + temp1)/2;
							arrq = (Gobang_laststepq + temp2)/2;
							if(Gobang_qp[arrp][arrq] == Gobang_k+1 || Gobang_qp[arrp+1][arrq] == Gobang_k+1 || Gobang_qp[arrp-1][arrq] == Gobang_k+1)
							{
								enough++;
								continue;
							}
							else
							{
								Gobang_p = temp1;
								Gobang_q = temp2;
								ifGoOn = 1;
							}
						}
					}
					break;
					case 8:
					{
						while(Gobang_p == Gobang_LastManStepp[Gobang_k] && Gobang_q == Gobang_LastManStepq[Gobang_k])
						{
							if(enough > 1000) break;
							srand((unsigned) time(NULL));
							temp = rand()% 7 - 3;
							temp1 = Gobang_laststepp + temp;
							temp2 = Gobang_laststepq;
							if(Gobang_qp[temp1][temp2] || temp1 < 1 || temp2 < 1 || temp1 > Gobang_n || temp2 > Gobang_n)
							{
								enough++;
								continue;
							}
							arrp = (Gobang_laststepp + temp1)/2;
							arrq = (Gobang_laststepq + temp2)/2;
							if(Gobang_qp[arrp][arrq] == Gobang_k+1 || Gobang_qp[arrp+1][arrq] == Gobang_k+1 || Gobang_qp[arrp-1][arrq] == Gobang_k+1)
							{
								enough++;
								continue;
							}
							else
							{
								Gobang_p = temp1;
								Gobang_q = temp2;
								ifGoOn = 1;
							}
						}
					}
					break;
					case 3:
					{
						while(Gobang_p == Gobang_LastManStepp[Gobang_k] && Gobang_q == Gobang_LastManStepq[Gobang_k])
						{
							if(enough > 1000) break;
							srand((unsigned) time(NULL));
							temp = rand()% 7 - 3;
							temp1 = Gobang_laststepp + temp;
							temp2 = Gobang_laststepq - temp;
							if(Gobang_qp[temp1][temp2] || temp1 < 1 || temp2 < 1 || temp1 > Gobang_n || temp2 > Gobang_n)
							{
								enough++;
								continue;
							}
							arrp = (Gobang_laststepp + temp1)/2;
							arrq = (Gobang_laststepq + temp2)/2;
							if(Gobang_qp[arrp][arrq] == Gobang_k+1 || Gobang_qp[arrp+1][arrq-1] == Gobang_k+1 || Gobang_qp[arrp-1][arrq+1] == Gobang_k+1)
							{
								enough++;
								continue;
							}
							else
							{
								Gobang_p = temp1;
								Gobang_q = temp2;
								ifGoOn = 1;
							}
						}
					}
					break;
					case 7:
					{
						while(Gobang_p == Gobang_LastManStepp[Gobang_k] && Gobang_q == Gobang_LastManStepq[Gobang_k])
						{
							if(enough > 1000) break;
							srand((unsigned) time(NULL));
							temp = rand()% 7 - 3;
							temp1 = Gobang_laststepp + temp;
							temp2 = Gobang_laststepq - temp;
							if(Gobang_qp[temp1][temp2] || temp1 < 1 || temp2 < 1 || temp1 > Gobang_n || temp2 > Gobang_n)
							{
								enough++;
								continue;
							}
							arrp = (Gobang_laststepp + temp1)/2;
							arrq = (Gobang_laststepq + temp2)/2;
							if(Gobang_qp[arrp][arrq] == Gobang_k+1 || Gobang_qp[arrp+1][arrq-1] == Gobang_k+1 || Gobang_qp[arrp-1][arrq+1] == Gobang_k+1)
							{
								enough++;
								continue;
							}
							else
							{
								Gobang_p = temp1;
								Gobang_q = temp2;
								ifGoOn = 1;
							}
						}
					}
					break;
					case 4:
					{
						while(Gobang_p == Gobang_LastManStepp[Gobang_k] && Gobang_q == Gobang_LastManStepq[Gobang_k])
						{
							if(enough > 1000) break;
							srand((unsigned) time(NULL));
							temp = rand()% 7 - 3;
							temp1 = Gobang_laststepp;
							temp2 = Gobang_laststepq + temp;
							if(Gobang_qp[temp1][temp2] || temp1 < 1 || temp2 < 1 || temp1 > Gobang_n || temp2 > Gobang_n)
							{
								enough++;
								continue;
							}
							arrp = (Gobang_laststepp + temp1)/2;
							arrq = (Gobang_laststepq + temp2)/2;
							if(Gobang_qp[arrp][arrq] == Gobang_k+1 || Gobang_qp[arrp][arrq-1] == Gobang_k+1 || Gobang_qp[arrp][arrq+1] == Gobang_k+1)
							{
								enough++;
								continue;
							}
							else
							{
								Gobang_p = temp1;
								Gobang_q = temp2;
								ifGoOn = 1;
							}
						}
					}
					break;
					case 6:
					{
						while(Gobang_p == Gobang_LastManStepp[Gobang_k] && Gobang_q == Gobang_LastManStepq[Gobang_k])
						{
							if(enough > 1000) break;
							srand((unsigned) time(NULL));
							temp = rand()% 7 - 3;
							temp1 = Gobang_laststepp;
							temp2 = Gobang_laststepq + temp;
							if(Gobang_qp[temp1][temp2] || temp1 < 1 || temp2 < 1 || temp1 > Gobang_n || temp2 > Gobang_n)
							{
								enough++;
								continue;
							}
							arrp = (Gobang_laststepp + temp1)/2;
							arrq = (Gobang_laststepq + temp2)/2;
							if(Gobang_qp[arrp][arrq] == Gobang_k+1 || Gobang_qp[arrp][arrq-1] == Gobang_k+1 || Gobang_qp[arrp][arrq+1] == Gobang_k+1)
							{
								enough++;
								continue;
							}
							else
							{
								Gobang_p = temp1;
								Gobang_q = temp2;
								ifGoOn = 1;
							}
						}
					}
					break;
				}
			}
		}
	}
	if(!ifGoOn)
	{
		OnlyToRand = 0;
		for(int i = Gobang_laststepp-1 ; i <= Gobang_laststepp+1 ; i++)
		{
			for(int j = Gobang_laststepq-1 ; j <= Gobang_laststepq+1 ; j++)
			{
				if(!Gobang_qp[i][j])
				{
					OnlyToRand++;
				}
			}
		}
		if(!OnlyToRand)  return  Gobang_computer();
		else
		{
			while(Gobang_LastManStepp[Gobang_k] == Gobang_p && Gobang_LastManStepq[Gobang_k] == Gobang_q)
			{
				srand((unsigned) time(NULL));
				temp1 = Gobang_laststepp + rand()%3 - 1;
				temp2 = Gobang_laststepq + rand()%3 - 1;
				if(Gobang_qp[temp1][temp2] || temp1 < 1 || temp2 < 1 || temp1 > Gobang_n || temp2 > Gobang_n)
				{
					continue;
				}
				else
				{
					Gobang_p = temp1;
					Gobang_q = temp2;
				}
			}
		}
	}
}

void Gobang_computermaster2()
{
	int defendtime[5], defendGobang_flag = 0;
	int IfTheLongest = 0, LongestI = 0;
	for(int i = 0 ; i <= 4 ; i++)
	{
		defendtime[i] = -1;
	}
	for(int i = Gobang_LastManStepp[Gobang_k], j = Gobang_LastManStepq[Gobang_k], Gobang_defendGobang_flag = 1; Gobang_qp[i][j] == Gobang_k+1 ; i--, j--)
	{
		defendtime[Gobang_defendGobang_flag]++;
		if((i - 1) == 0 || (j - 1) == 0 || Gobang_qp[i-1][j-1] == Gobang_d+1)
		{
			defendtime[Gobang_defendGobang_flag]--;
			break;
		}
	}
	for(int i = Gobang_LastManStepp[Gobang_k], j = Gobang_LastManStepq[Gobang_k], Gobang_defendGobang_flag = 2; Gobang_qp[i][j] == Gobang_k+1 ; i--)
	{
		defendtime[Gobang_defendGobang_flag]++;
		if((i - 1) == 0 || Gobang_qp[i-1][j] == Gobang_d+1)
		{
			defendtime[Gobang_defendGobang_flag]--;
			break;
		}
	}
	for(int i = Gobang_LastManStepp[Gobang_k], j = Gobang_LastManStepq[Gobang_k], Gobang_defendGobang_flag = 3; Gobang_qp[i][j] == Gobang_k+1 ; i--, j++)
	{
		defendtime[Gobang_defendGobang_flag]++;
		if((i - 1) == 0 || (j + 1) == 0 || Gobang_qp[i-1][j+1] == Gobang_d+1)
		{
			defendtime[Gobang_defendGobang_flag]--;
			break;
		}
	}
	for(int i = Gobang_LastManStepp[Gobang_k], j = Gobang_LastManStepq[Gobang_k], Gobang_defendGobang_flag = 4; Gobang_qp[i][j] == Gobang_k+1 ; j--)
	{
		defendtime[Gobang_defendGobang_flag]++;
		if((j - 1) == 0 || Gobang_qp[i][j-1] == Gobang_d+1)
		{
			defendtime[Gobang_defendGobang_flag]--;
			break;
		}
	}
	for(int i = Gobang_LastManStepp[Gobang_k], j = Gobang_LastManStepq[Gobang_k], Gobang_defendGobang_flag = 4; Gobang_qp[i][j] == Gobang_k+1 ; j++)
	{
		defendtime[Gobang_defendGobang_flag]++;
		if((j + 1) == 0 || Gobang_qp[i][j+1] == Gobang_d+1)
		{
			defendtime[Gobang_defendGobang_flag]--;
			break;
		}
	}
	for(int i = Gobang_LastManStepp[Gobang_k], j = Gobang_LastManStepq[Gobang_k], Gobang_defendGobang_flag = 3; Gobang_qp[i][j] == Gobang_k+1 ; i++, j--)
	{
		defendtime[Gobang_defendGobang_flag]++;
		if((i + 1) == 0 || (j - 1) == 0 || Gobang_qp[i+1][j-1] == Gobang_d+1)
		{
			defendtime[Gobang_defendGobang_flag]--;
			break;
		}
	}
	for(int i = Gobang_LastManStepp[Gobang_k], j = Gobang_LastManStepq[Gobang_k], Gobang_defendGobang_flag = 2; Gobang_qp[i][j] == Gobang_k+1 ; i++)
	{
		defendtime[Gobang_defendGobang_flag]++;
		if((i + 1) == 0 || Gobang_qp[i+1][j] == Gobang_d+1)
		{
			defendtime[Gobang_defendGobang_flag]--;
			break;
		}
	}
	for(int i = Gobang_LastManStepp[Gobang_k], j = Gobang_LastManStepq[Gobang_k], Gobang_defendGobang_flag = 1; Gobang_qp[i][j] == Gobang_k+1 ; i++, j++)
	{
		defendtime[Gobang_defendGobang_flag]++;
		if((i + 1) == 0 || (j + 1) == 0 || Gobang_qp[i+1][j+1] == Gobang_d+1)
		{
			defendtime[Gobang_defendGobang_flag]--;
			break;
		}
	}
	for(int i = 1 ; i <= 4 ; i++)
	{
		if(defendtime[i] == Gobang_d+1)
		{
			Gobang_ifentercm6[Gobang_k] = 1;
		}
		if(defendtime[i] < 3)
		{
			defendtime[i] = 0;
		}
		if(IfTheLongest < defendtime[i])
		{
			IfTheLongest = defendtime[i];
			LongestI = i;
		}
	}
	switch(LongestI)
	{
		case 0:
		{
			break;
		}
		case 1:
		{
			srand((unsigned) time(NULL));
			if(rand()%2)
			{
				for(int i = Gobang_LastManStepp[Gobang_k], j = Gobang_LastManStepq[Gobang_k] ; Gobang_qp[i][j] == Gobang_k+1 ; i--, j--)
				{
					if((i - 1) == 0 || (j - 1) == 0 || Gobang_qp[i-1][j-1] == Gobang_d+1)
					{
						for(int i = Gobang_LastManStepp[Gobang_k], j = Gobang_LastManStepq[Gobang_k] ; Gobang_qp[i][j] == Gobang_k+1 ; i++, j++)
						{
							Gobang_p = i+1;
							Gobang_q = j+1;
						}
					}
					else
					{
						Gobang_p = i-1;
						Gobang_q = j-1;
					}
				}
			}
			else
			{
				for(int i = Gobang_LastManStepp[Gobang_k], j = Gobang_LastManStepq[Gobang_k] ; Gobang_qp[i][j] == Gobang_k+1 ; i++, j++)
				{
					Gobang_p = i+1;
					Gobang_q = j+1;
				}
			}
		}
		break;
		case 2:
		{
			srand((unsigned) time(NULL));
			if(rand()%2)
			{
				for(int i = Gobang_LastManStepp[Gobang_k], j = Gobang_LastManStepq[Gobang_k] ; Gobang_qp[i][j] == Gobang_k+1 ; i--)
				{
					if((i - 1) == 0 || Gobang_qp[i-1][j] == Gobang_d+1)
					{
						for(int i = Gobang_LastManStepp[Gobang_k], j = Gobang_LastManStepq[Gobang_k] ; Gobang_qp[i][j] == Gobang_k+1 ; i++)
						{
							Gobang_p = i+1;
							Gobang_q = j;
						}
					}
					else
					{
						Gobang_p = i-1;
						Gobang_q = j;
					}
				}
			}
			else
			{
				for(int i = Gobang_LastManStepp[Gobang_k], j = Gobang_LastManStepq[Gobang_k] ; Gobang_qp[i][j] == Gobang_k+1 ; i++)
				{
					Gobang_p = i+1;
					Gobang_q = j;
				}
			}
		}
		break;
		case 3:
		{
			srand((unsigned) time(NULL));
			if(rand()%2)
			{
				for(int i = Gobang_LastManStepp[Gobang_k], j = Gobang_LastManStepq[Gobang_k] ; Gobang_qp[i][j] == Gobang_k+1 ; i--, j++)
				{
					if((i - 1) == 0 || (j + 1) == 0 || Gobang_qp[i-1][j+1] == Gobang_d+1)
					{
						for(int i = Gobang_LastManStepp[Gobang_k], j = Gobang_LastManStepq[Gobang_k] ; Gobang_qp[i][j] == Gobang_k+1 ; i++, j--)
						{
							Gobang_p = i+1;
							Gobang_q = j-1;
						}
					}
					else
					{
						Gobang_p = i-1;
						Gobang_q = j+1;
					}
				}
			}
			else
			{
				for(int i = Gobang_LastManStepp[Gobang_k], j = Gobang_LastManStepq[Gobang_k] ; Gobang_qp[i][j] == Gobang_k+1 ; i++, j++)
				{
					Gobang_p = i+1;
					Gobang_q = j-1;
				}
			}
		}
		break;
		case 4:
		{
			srand((unsigned) time(NULL));
			if(rand()%2)
			{
				for(int i = Gobang_LastManStepp[Gobang_k], j = Gobang_LastManStepq[Gobang_k] ; Gobang_qp[i][j] == Gobang_k+1 ; j--)
				{
					if((j - 1) == 0 || Gobang_qp[i][j-1] == Gobang_d+1)
					{
						for(int i = Gobang_LastManStepp[Gobang_k], j = Gobang_LastManStepq[Gobang_k] ; Gobang_qp[i][j] == Gobang_k+1 ; j++)
						{
							Gobang_p = i;
							Gobang_q = j+1;
						}
					}
					else
					{
						Gobang_p = i;
						Gobang_q = j-1;
					}
				}
			}
			else
			{
				for(int i = Gobang_LastManStepp[Gobang_k], j = Gobang_LastManStepq[Gobang_k] ; Gobang_qp[i][j] == Gobang_k+1 ; i++, j++)
				{
					Gobang_p = i;
					Gobang_q = j+1;
				}
			}
		}
		break;
	}
}

void Gobang_computermaster3()
{
	int blankp[10], blankq[10], threaten[10];
	int realblankp[10], realblankq[10];
	int m = 0, cm3Gobang_flag = 0;
	for(int i = 0 ; i < 10 ; i++)
	{
		threaten[i] = 0;
		blankp[i] = 0;
		blankq[i] = 0;
	}
	for(int i = Gobang_LastManStepp[Gobang_k], j = Gobang_LastManStepq[Gobang_k] ; i > Gobang_LastManStepp[Gobang_k]-4 && i > 0 && j > 0; i--, j--)
	{
		if(Gobang_qp[i][j] == 0)
		{
			blankp[1] = i;
			blankq[1] = j;
		}
		else if(Gobang_qp[i][j] == Gobang_k+1)
		{
			threaten[1]++;
		}
	}
	for(int i = Gobang_LastManStepp[Gobang_k], j = Gobang_LastManStepq[Gobang_k] ; i > Gobang_LastManStepp[Gobang_k]-4 && i > 0 ; i--)
	{
		if(Gobang_qp[i][j] == 0)
		{
			blankp[2] = i;
			blankq[2] = j;
		}
		else if(Gobang_qp[i][j] == Gobang_k+1)
		{
			threaten[2]++;
		}
	}
	for(int i = Gobang_LastManStepp[Gobang_k], j = Gobang_LastManStepq[Gobang_k] ; i > Gobang_LastManStepp[Gobang_k]-4 && i > 0 && j <= Gobang_n ; i--, j++)
	{
		if(Gobang_qp[i][j] == 0)
		{
			blankp[3] = i;
			blankq[3] = j;
		}
		else if(Gobang_qp[i][j] == Gobang_k+1)
		{
			threaten[3]++;
		}
	}
	for(int i = Gobang_LastManStepp[Gobang_k], j = Gobang_LastManStepq[Gobang_k] ; j > Gobang_LastManStepq[Gobang_k]-4 && j > 0 ; j--)
	{
		if(Gobang_qp[i][j] == 0)
		{
			blankp[4] = i;
			blankq[4] = j;
		}
		else if(Gobang_qp[i][j] == Gobang_k+1)
		{
			threaten[4]++;
		}
	}
	for(int i = Gobang_LastManStepp[Gobang_k], j = Gobang_LastManStepq[Gobang_k] ; j < Gobang_LastManStepp[Gobang_k]+4 && j <= Gobang_n; j++)
	{
		if(Gobang_qp[i][j] == 0)
		{
			blankp[6] = i;
			blankq[6] = j;
		}
		else if(Gobang_qp[i][j] == Gobang_k+1)
		{
			threaten[6]++;
		}
	}
	for(int i = Gobang_LastManStepp[Gobang_k], j = Gobang_LastManStepq[Gobang_k] ; i < Gobang_LastManStepp[Gobang_k]+4 && i < Gobang_n && j > 0 ; i++, j--)
	{
		if(Gobang_qp[i][j] == 0)
		{
			blankp[7] = i;
			blankq[7] = j;
		}
		else if(Gobang_qp[i][j] == Gobang_k+1)
		{
			threaten[7]++;
		}
	}
	for(int i = Gobang_LastManStepp[Gobang_k], j = Gobang_LastManStepq[Gobang_k] ; i < Gobang_LastManStepp[Gobang_k]+4 && i <= Gobang_n; i++)
	{
		if(Gobang_qp[i][j] == 0)
		{
			blankp[8] = i;
			blankq[8] = j;
		}
		else if(Gobang_qp[i][j] == Gobang_k+1)
		{
			threaten[8]++;
		}
	}
	for(int i = Gobang_LastManStepp[Gobang_k], j = Gobang_LastManStepq[Gobang_k] ; i < Gobang_LastManStepp[Gobang_k]+4 && i <= Gobang_n && j <= Gobang_n; i++, j++)
	{
		if(Gobang_qp[i][j] == 0)
		{
			blankp[9] = i;
			blankq[9] = j;
		}
		else if(Gobang_qp[i][j] == Gobang_k+1)
		{
			threaten[9]++;
		}
	}
	for(int i = 1 ; i <= 9 ; i++)
	{
		if(threaten[i] == 3 && blankp[i] != 0)
		{
			realblankp[m] = blankp[i];
			realblankq[m] = blankq[i];
			m++;
		}
	}
	for(int i = 0 ; i < m ; i++)
	{
		if(realblankp[i] != realblankp[0] || realblankq[i] != realblankq[0])
		{
			cm3Gobang_flag = 1;
			break;
		}
	}
	if(!cm3Gobang_flag && m)
	{
		Gobang_p = realblankp[0];
		Gobang_q = realblankq[0];
	}
}

void Gobang_computermaster4()
{
	int attacktime[5], attackGobang_flag = 0;
	int IfTheLongest = 0, LongestI = 0;
	for(int i = 0 ; i <= 4 ; i++)
	{
		attacktime[i] = -1;
	}
	for(int i = Gobang_LastManStepp[Gobang_k], j = Gobang_LastManStepq[Gobang_k], attackGobang_flag = 1; Gobang_qp[i][j] == Gobang_d+1 ; i--, j--)
	{
		attacktime[attackGobang_flag]++;
		if((i - 1) == 0 || (j - 1) == 0 || Gobang_qp[i-1][j-1] == Gobang_k+1)
		{
			attacktime[attackGobang_flag]--;
			break;
		}
	}
	for(int i = Gobang_LastManStepp[Gobang_k], j = Gobang_LastManStepq[Gobang_k], attackGobang_flag = 2; Gobang_qp[i][j] == Gobang_d+1 ; i--)
	{
		attacktime[attackGobang_flag]++;
		if((i - 1) == 0|| Gobang_qp[i-1][j] == Gobang_k+1)
		{
			attacktime[attackGobang_flag]--;
			break;
		}
	}
	for(int i = Gobang_LastManStepp[Gobang_k], j = Gobang_LastManStepq[Gobang_k], attackGobang_flag = 3; Gobang_qp[i][j] == Gobang_d+1 ; i--, j++)
	{
		attacktime[attackGobang_flag]++;
		if((i - 1) == 0 || (j + 1) == 0 || Gobang_qp[i-1][j+1] == Gobang_k+1)
		{
			attacktime[attackGobang_flag]--;
			break;
		}
	}
	for(int i = Gobang_LastManStepp[Gobang_k], j = Gobang_LastManStepq[Gobang_k], attackGobang_flag = 4; Gobang_qp[i][j] == Gobang_d+1 ; j--)
	{
		attacktime[attackGobang_flag]++;
		if((j - 1) == 0 || Gobang_qp[i][j-1] == Gobang_k+1)
		{
			attacktime[attackGobang_flag]--;
			break;
		}
	}
	for(int i = Gobang_LastManStepp[Gobang_k], j = Gobang_LastManStepq[Gobang_k], attackGobang_flag = 4; Gobang_qp[i][j] == Gobang_d+1 ; j++)
	{
		attacktime[attackGobang_flag]++;
		if((j + 1) == 0 || Gobang_qp[i][j+1] == Gobang_k+1)
		{
			attacktime[attackGobang_flag]--;
			break;
		}
	}
	for(int i = Gobang_LastManStepp[Gobang_k], j = Gobang_LastManStepq[Gobang_k], attackGobang_flag = 3; Gobang_qp[i][j] == Gobang_d+1 ; i++, j--)
	{
		attacktime[attackGobang_flag]++;
		if((i + 1) == 0 || (j - 1) == 0 || Gobang_qp[i+1][j-1] == Gobang_k+1)
		{
			attacktime[attackGobang_flag]--;
			break;
		}
	}
	for(int i = Gobang_LastManStepp[Gobang_k], j = Gobang_LastManStepq[Gobang_k], attackGobang_flag = 2; Gobang_qp[i][j] == Gobang_d+1 ; i++)
	{
		attacktime[attackGobang_flag]++;
		if((i + 1) == 0 || Gobang_qp[i+1][j] == Gobang_k+1)
		{
			attacktime[attackGobang_flag]--;
			break;
		}
	}
	for(int i = Gobang_LastManStepp[Gobang_k], j = Gobang_LastManStepq[Gobang_k], attackGobang_flag = 1; Gobang_qp[i][j] == Gobang_d+1 ; i++, j++)
	{
		attacktime[attackGobang_flag]++;
		if((i + 1) == 0 || (j + 1) == 0 || Gobang_qp[i+1][j+1] == Gobang_k+1)
		{
			attacktime[attackGobang_flag]--;
			break;
		}
	}
	for(int i = 1 ; i <= 4 ; i++)
	{
		if(attacktime[i] < 3)
		{
			attacktime[i] = 0;
		}
		if(IfTheLongest < attacktime[i])
		{
			IfTheLongest = attacktime[i];
			LongestI = i;
		}
	}
	switch(LongestI)
	{
		case 0:
		{
			break;
		}
		case 1:
		{
			printf("case1\n");
			srand((unsigned) time(NULL));
			if(rand()%2)
			{
				for(int i = Gobang_LastManStepp[Gobang_k], j = Gobang_LastManStepq[Gobang_k] ; Gobang_qp[i][j] == Gobang_d+1 ; i--, j--)
				{
					if((i - 1) == 0 || (j - 1) == 0 || Gobang_qp[i-1][j-1] == Gobang_k+1)
					{
						for(int i = Gobang_LastManStepp[Gobang_k], j = Gobang_LastManStepq[Gobang_k] ; Gobang_qp[i][j] == Gobang_k+1 ; i++, j++)
						{
							Gobang_p = i+1;
							Gobang_q = j+1;
						}
					}
					else
					{
						Gobang_p = i-1;
						Gobang_q = j-1;
					}
				}
			}
			else
			{
				for(int i = Gobang_LastManStepp[Gobang_k], j = Gobang_LastManStepq[Gobang_k] ; Gobang_qp[i][j] == Gobang_d+1 ; i++, j++)
				{
					Gobang_p = i+1;
					Gobang_q = j+1;
				}
			}
		}
		break;
		case 2:
		{
			srand((unsigned) time(NULL));
			if(rand()%2)
			{
				for(int i = Gobang_LastManStepp[Gobang_k], j = Gobang_LastManStepq[Gobang_k] ; Gobang_qp[i][j] == Gobang_d+1 ; i--)
				{
					if((i - 1) == 0 || Gobang_qp[i-1][j] == Gobang_k+1)
					{
						for(int i = Gobang_LastManStepp[Gobang_k], j = Gobang_LastManStepq[Gobang_k] ; Gobang_qp[i][j] == Gobang_d+1 ; i++)
						{
							Gobang_p = i+1;
							Gobang_q = j;
						}
					}
					else
					{
						Gobang_p = i-1;
						Gobang_q = j;
					}
				}
			}
			else
			{
				for(int i = Gobang_LastManStepp[Gobang_k], j = Gobang_LastManStepq[Gobang_k] ; Gobang_qp[i][j] == Gobang_d+1 ; i++)
				{
					Gobang_p = i+1;
					Gobang_q = j;
				}
			}
		}
		break;
		case 3:
		{
			srand((unsigned) time(NULL));
			if(rand()%2)
			{
				for(int i = Gobang_LastManStepp[Gobang_k], j = Gobang_LastManStepq[Gobang_k] ; Gobang_qp[i][j] == Gobang_d+1 ; i--, j++)
				{
					if((i - 1) == 0 || (j + 1) == 0 || Gobang_qp[i-1][j+1] == Gobang_k+1)
					{
						for(int i = Gobang_LastManStepp[Gobang_k], j = Gobang_LastManStepq[Gobang_k] ; Gobang_qp[i][j] == Gobang_d+1 ; i++, j--)
						{
							Gobang_p = i+1;
							Gobang_q = j-1;
						}
					}
					else
					{
						Gobang_p = i-1;
						Gobang_q = j+1;
					}
				}
			}
			else
			{
				for(int i = Gobang_LastManStepp[Gobang_k], j = Gobang_LastManStepq[Gobang_k] ; Gobang_qp[i][j] == Gobang_d+1 ; i++, j++)
				{
					Gobang_p = i+1;
					Gobang_q = j-1;
				}
			}
		}
		break;
		case 4:
		{
			srand((unsigned) time(NULL));
			if(rand()%2)
			{
				for(int i = Gobang_LastManStepp[Gobang_k], j = Gobang_LastManStepq[Gobang_k] ; Gobang_qp[i][j] == Gobang_d+1 ; j--)
				{
					if((j - 1) == 0 || Gobang_qp[i][j-1] == Gobang_k+1)
					{
						for(int i = Gobang_LastManStepp[Gobang_k], j = Gobang_LastManStepq[Gobang_k] ; Gobang_qp[i][j] == Gobang_d+1 ; j++)
						{
							Gobang_p = i;
							Gobang_q = j+1;
						}
					}
					else
					{
						Gobang_p = i;
						Gobang_q = j-1;
					}
				}
			}
			else
			{
				for(int i = Gobang_LastManStepp[Gobang_k], j = Gobang_LastManStepq[Gobang_k] ; Gobang_qp[i][j] == Gobang_d+1 ; i++, j++)
				{
					Gobang_p = i;
					Gobang_q = j+1;
				}
			}
		}
		break;
	}
}

void Gobang_computermaster5()
{
	int blankp[10], blankq[10], threaten[10];
	int realblankp[10], realblankq[10];
	int m = 0, cm5Gobang_flag = 0;
	Gobang_laststepp = Gobang_lastattackp[Gobang_k];
	Gobang_laststepq = Gobang_lastattackq[Gobang_k];
	for(int i = 0 ; i < 10 ; i++)
	{
		threaten[i] = 0;
		blankp[i] = 0;
		blankq[i] = 0;
	}
	for(int i = Gobang_laststepp, j = Gobang_laststepq ; i > Gobang_laststepp-4 && i > 0 && j > 0; i--, j--)
	{
		if(Gobang_qp[i][j] == 0)
		{
			blankp[1] = i;
			blankq[1] = j;
		}
		else if(Gobang_qp[i][j] == Gobang_d+1)
		{
			threaten[1]++;
		}
	}
	for(int i = Gobang_laststepp, j = Gobang_laststepq ; i > Gobang_laststepp-4 && i > 0 ; i--)
	{
		if(Gobang_qp[i][j] == 0)
		{
			blankp[2] = i;
			blankq[2] = j;
		}
		else if(Gobang_qp[i][j] == Gobang_d+1)
		{
			threaten[2]++;
		}
	}
	for(int i = Gobang_laststepp, j = Gobang_laststepq ; i > Gobang_laststepp-4 && i > 0 && j <= Gobang_n ; i--, j++)
	{
		if(Gobang_qp[i][j] == 0)
		{
			blankp[3] = i;
			blankq[3] = j;
		}
		else if(Gobang_qp[i][j] == Gobang_d+1)
		{
			threaten[3]++;
		}
	}
	for(int i = Gobang_laststepp, j = Gobang_laststepq ; j > Gobang_laststepq-4 && j > 0 ; j--)
	{
		if(Gobang_qp[i][j] == 0)
		{
			blankp[4] = i;
			blankq[4] = j;
		}
		else if(Gobang_qp[i][j] == Gobang_d+1)
		{
			threaten[4]++;
		}
	}
	for(int i = Gobang_laststepp, j = Gobang_laststepq ; j < Gobang_laststepq+4 && j <= Gobang_n; j++)
	{
		if(Gobang_qp[i][j] == 0)
		{
			blankp[6] = i;
			blankq[6] = j;
		}
		else if(Gobang_qp[i][j] == Gobang_d+1)
		{
			threaten[6]++;
		}
	}
	for(int i = Gobang_laststepp, j = Gobang_laststepp ; i < Gobang_laststepp+4 && i < Gobang_n && j > 0 ; i++, j--)
	{
		if(Gobang_qp[i][j] == 0)
		{
			blankp[7] = i;
			blankq[7] = j;
		}
		else if(Gobang_qp[i][j] == Gobang_d+1)
		{
			threaten[7]++;
		}
	}
	for(int i = Gobang_laststepp, j = Gobang_laststepq ; i < Gobang_laststepp+4 && i <= Gobang_n; i++)
	{
		if(Gobang_qp[i][j] == 0)
		{
			blankp[8] = i;
			blankq[8] = j;
		}
		else if(Gobang_qp[i][j] == Gobang_d+1)
		{
			threaten[8]++;
		}
	}
	for(int i = Gobang_laststepp, j = Gobang_laststepq ; i < Gobang_laststepp+4 && i <= Gobang_n && j <= Gobang_n; i++, j++)
	{
		if(Gobang_qp[i][j] == 0)
		{
			blankp[9] = i;
			blankq[9] = j;
		}
		else if(Gobang_qp[i][j] == Gobang_d+1)
		{
			threaten[9]++;
		}
	}
	for(int i = 1 ; i <= 9 ; i++)
	{
		if(threaten[i] == 3 && blankp[i] != 0)
		{
			realblankp[m] = blankp[i];
			realblankq[m] = blankq[i];
			m++;
		}
	}
	for(int i = 0 ; i < m ; i++)
	{
		if(realblankp[i] != realblankp[0] || realblankq[i] != realblankq[0])
		{
			cm5Gobang_flag = 1;
			break;
		}
	}
	if(!cm5Gobang_flag && m)
	{
		Gobang_p = realblankp[0];
		Gobang_q = realblankq[0];
	}
}

void Gobang_computermaster6()
{
	int blankp[5], blankq[5], threaten[5];
	int realblankp[5], realblankq[5];
	int m = 0, cm6Gobang_flag = 0;
	for(int i = 0 ; i < 5 ; i++)
	{
		threaten[i] = 0;
		blankp[i] = 0;
		blankq[i] = 0;
	}
	for(int i = Gobang_LastManStepp[Gobang_k] + 2, j = Gobang_LastManStepq[Gobang_k] + 2 ; i > Gobang_LastManStepp[Gobang_k]-3 && i > 0 && j > 0; i--, j--)
	{
		if(Gobang_qp[i][j] == 0)
		{
			blankp[1] = i;
			blankq[1] = j;
		}
		else if(Gobang_qp[i][j] == Gobang_k+1)
		{
			threaten[1]++;
		}
	}
	for(int i = Gobang_LastManStepp[Gobang_k] + 2, j = Gobang_LastManStepq[Gobang_k] ; i > Gobang_LastManStepp[Gobang_k]-3 && i > 0 ; i--)
	{
		if(Gobang_qp[i][j] == 0)
		{
			blankp[2] = i;
			blankq[2] = j;
		}
		else if(Gobang_qp[i][j] == Gobang_k+1)
		{
			threaten[2]++;
		}
	}
	for(int i = Gobang_LastManStepp[Gobang_k] + 2 , j = Gobang_LastManStepq[Gobang_k] -2 ; i > Gobang_LastManStepp[Gobang_k]-3 && i > 0 && j <= Gobang_n ; i--, j++)
	{
		if(Gobang_qp[i][j] == 0)
		{
			blankp[3] = i;
			blankq[3] = j;
		}
		else if(Gobang_qp[i][j] == Gobang_k+1)
		{
			threaten[3]++;
		}
	}
	for(int i = Gobang_LastManStepp[Gobang_k], j = Gobang_LastManStepq[Gobang_k] + 2 ; j > Gobang_LastManStepq[Gobang_k]-3 && j > 0 ; j--)
	{
		if(Gobang_qp[i][j] == 0)
		{
			blankp[4] = i;
			blankq[4] = j;
		}
		else if(Gobang_qp[i][j] == Gobang_k+1)
		{
			threaten[4]++;
		}
	}
	for(int i = 1 ; i <= 4 ; i++)
	{
		if(threaten[i] == 3 && blankp[i] != 0)
		{
			realblankp[m] = blankp[i];
			realblankq[m] = blankq[i];
			m++;
		}
	}
	for(int i = 0 ; i < m ; i++)
	{
		if(realblankp[i] != realblankp[0] || realblankq[i] != realblankq[0])
		{
			cm6Gobang_flag = 1;
			break;
		}
	}
	if(!cm6Gobang_flag && m)
	{
		Gobang_p = realblankp[0];
		Gobang_q = realblankq[0];
	}
}

void Gobang_computermaster7()
{
	int blankp[5], blankq[5], threaten[5];
	int realblankp[5], realblankq[5];
	int m = 0, cm6Gobang_flag = 0;
	for(int i = 0 ; i < 5 ; i++)
	{
		threaten[i] = 0;
		blankp[i] = 0;
		blankq[i] = 0;
	}
	for(int i = Gobang_LastManStepp[Gobang_k] + 2, j = Gobang_LastManStepq[Gobang_k] + 2 ; i > Gobang_LastManStepp[Gobang_k]-3 && i > 0 && j > 0; i--, j--)
	{
		if(Gobang_qp[i][j] == 0)
		{
			blankp[1] = i;
			blankq[1] = j;
		}
		else if(Gobang_qp[i][j] == Gobang_k+1)
		{
			threaten[1]++;
		}
	}
	for(int i = Gobang_LastManStepp[Gobang_k] + 2, j = Gobang_LastManStepq[Gobang_k] ; i > Gobang_LastManStepp[Gobang_k]-3 && i > 0 ; i--)
	{
		if(Gobang_qp[i][j] == 0)
		{
			blankp[2] = i;
			blankq[2] = j;
		}
		else if(Gobang_qp[i][j] == Gobang_k+1)
		{
			threaten[2]++;
		}
	}
	for(int i = Gobang_LastManStepp[Gobang_k] + 2 , j = Gobang_LastManStepq[Gobang_k] -2 ; i > Gobang_LastManStepp[Gobang_k]-3 && i > 0 && j <= Gobang_n ; i--, j++)
	{
		if(Gobang_qp[i][j] == 0)
		{
			blankp[3] = i;
			blankq[3] = j;
		}
		else if(Gobang_qp[i][j] == Gobang_k+1)
		{
			threaten[3]++;
		}
	}
	for(int i = Gobang_LastManStepp[Gobang_k], j = Gobang_LastManStepq[Gobang_k] + 2 ; j > Gobang_LastManStepq[Gobang_k]-3 && j > 0 ; j--)
	{
		if(Gobang_qp[i][j] == 0)
		{
			blankp[4] = i;
			blankq[4] = j;
		}
		else if(Gobang_qp[i][j] == Gobang_k+1)
		{
			threaten[4]++;
		}
	}
	for(int i = 1 ; i <= 4 ; i++)
	{
		if(threaten[i] == 4 && blankp[i] != 0)
		{
			realblankp[m] = blankp[i];
			realblankq[m] = blankq[i];
			m++;
		}
	}
	for(int i = 0 ; i < m ; i++)
	{
		if(realblankp[i] != realblankp[0] || realblankq[i] != realblankq[0])
		{
			cm6Gobang_flag = 1;
			break;
		}
	}
	if(!cm6Gobang_flag && m)
	{
		Gobang_p = realblankp[0];
		Gobang_q = realblankq[0];
	}
}

void Gobang_computermaster8()
{
	int threatenp[9999], threatenq[9999];
	int a = 0;
	for(int i = 0 ; i < 9999 ; i++)
	{
		threatenp[i] = 0;
		threatenq[i] = 0;
	}
	for(int i = 1 ; i <= Gobang_n ; i++)
	{
		for(int j = 1 ; j <= Gobang_n ; j++)
		{
			if(Gobang_qp[i][j] == 0)
			{
				if(Gobang_qp[i-1][j-1] == Gobang_k+1 && Gobang_qp[i-2][j-2] == Gobang_k+1 && Gobang_qp[i-3][j-3] != Gobang_d+1 && Gobang_qp[i+1][j+1] != Gobang_d+1)
				{
					threatenp[a] = i;
					threatenq[a] = j;
					a++;
				}
				if(Gobang_qp[i-1][j-1] == Gobang_k+1 && Gobang_qp[i+1][j+1] == Gobang_k+1 && Gobang_qp[i-2][j-2] != Gobang_d+1 && Gobang_qp[i+2][j+2] != Gobang_d+1)
				{
					threatenp[a] = i;
					threatenq[a] = j;
					a++;
				}
				if(Gobang_qp[i+1][j+1] == Gobang_k+1 && Gobang_qp[i+2][j+2] == Gobang_k+1 && Gobang_qp[i-1][j-1] != Gobang_d+1 && Gobang_qp[i+3][j+3] != Gobang_d+1)
				{
					threatenp[a] = i;
					threatenq[a] = j;
					a++;
				}
				if(Gobang_qp[i-1][j] == Gobang_k+1 && Gobang_qp[i-2][j] == Gobang_k+1 && Gobang_qp[i-3][j] != Gobang_d+1 && Gobang_qp[i+1][j] != Gobang_d+1)
				{
					threatenp[a] = i;
					threatenq[a] = j;
					a++;
				}
				if(Gobang_qp[i-1][j] == Gobang_k+1 && Gobang_qp[i+1][j] == Gobang_k+1 && Gobang_qp[i-2][j] != Gobang_d+1 && Gobang_qp[i+2][j] != Gobang_d+1)
				{
					threatenp[a] = i;
					threatenq[a] = j;
					a++;
				}
				if(Gobang_qp[i+1][j] == Gobang_k+1 && Gobang_qp[i+2][j] == Gobang_k+1 && Gobang_qp[i-1][j] != Gobang_d+1 && Gobang_qp[i+3][j] != Gobang_d+1)
				{
					threatenp[a] = i;
					threatenq[a] = j;
					a++;
				}
				if(Gobang_qp[i-1][j+1] == Gobang_k+1 && Gobang_qp[i-2][j+2] == Gobang_k+1 && Gobang_qp[i-3][j+3] != Gobang_d+1 && Gobang_qp[i+1][j-1] != Gobang_d+1)
				{
					threatenp[a] = i;
					threatenq[a] = j;
					a++;
				}
				if(Gobang_qp[i-1][j+1] == Gobang_k+1 && Gobang_qp[i+1][j-1] == Gobang_k+1 && Gobang_qp[i-2][j+2] != Gobang_d+1 && Gobang_qp[i+2][j-2] != Gobang_d+1)
				{
					threatenp[a] = i;
					threatenq[a] = j;
					a++;
				}
				if(Gobang_qp[i+1][j-1] == Gobang_k+1 && Gobang_qp[i+2][j-2] == Gobang_k+1 && Gobang_qp[i+3][j-3] != Gobang_d+1 && Gobang_qp[i-1][j+1] != Gobang_d+1)
				{
					threatenp[a] = i;
					threatenq[a] = j;
					a++;
				}
				if(Gobang_qp[i][j-1] == Gobang_k+1 && Gobang_qp[i][j-2] == Gobang_k+1 && Gobang_qp[i][j-3] != Gobang_d+1 && Gobang_qp[i][j+1] != Gobang_d+1)
				{
					threatenp[a] = i;
					threatenq[a] = j;
					a++;
				}
				if(Gobang_qp[i][j-1] == Gobang_k+1 && Gobang_qp[i][j+1] == Gobang_k+1 && Gobang_qp[i][j-2] != Gobang_d+1 && Gobang_qp[i][j+2] != Gobang_d+1)
				{
					threatenp[a] = i;
					threatenq[a] = j;
					a++;
				}
				if(Gobang_qp[i][j+1] == Gobang_k+1 && Gobang_qp[i][j+2] == Gobang_k+1 && Gobang_qp[i][j-1] != Gobang_d+1 && Gobang_qp[i][j+3] != Gobang_d+1)
				{
					threatenp[a] = i;
					threatenq[a] = j;
					a++;
				}
			}
		}
	}
	for(int i = 0 ; i < a ; i++)
	{
		for(int j = i+1 ; j <= a ; j++)
		{
			if(threatenp[i] == threatenp[j] && threatenq[i] == threatenq[j] && threatenp[i] != 0 && threatenq[i] != 0 && Gobang_qp[threatenp[i]][threatenq[i]] == 0)
			{
				Gobang_p = threatenp[i];
				Gobang_q = threatenq[i];
			}
		}
	}
}

void Gobang_computermaster9()
{
	int threatenp[9999], threatenq[9999];
	int a = 0;
	for(int i = 0 ; i < 9999 ; i++)
	{
		threatenp[i] = 0;
		threatenq[i] = 0;
	}
	for(int i = 1 ; i <= Gobang_n ; i++)
	{
		for(int j = 1 ; j <= Gobang_n ; j++)
		{
			if(Gobang_qp[i][j] == 0)
			{
				if(Gobang_qp[i-1][j-1] == Gobang_d+1 && Gobang_qp[i-2][j-2] == Gobang_d+1 && Gobang_qp[i-3][j-3] != 1 && Gobang_qp[i+1][j+1] != 1)
				{
					threatenp[a] = i;
					threatenq[a] = j;
					a++;
				}
				if(Gobang_qp[i-1][j-1] == Gobang_d+1 && Gobang_qp[i+1][j+1] == Gobang_d+1 && Gobang_qp[i-2][j-2] != 1 && Gobang_qp[i+2][j+2] != 1)
				{
					threatenp[a] = i;
					threatenq[a] = j;
					a++;
				}
				if(Gobang_qp[i+1][j+1] == Gobang_d+1 && Gobang_qp[i+2][j+2] == Gobang_d+1 && Gobang_qp[i-1][j-1] != 1 && Gobang_qp[i+3][j+3] != 1)
				{
					threatenp[a] = i;
					threatenq[a] = j;
					a++;
				}
				if(Gobang_qp[i-1][j] == Gobang_d+1 && Gobang_qp[i-2][j] == Gobang_d+1 && Gobang_qp[i-3][j] != 1 && Gobang_qp[i+1][j] != 1)
				{
					threatenp[a] = i;
					threatenq[a] = j;
					a++;
				}
				if(Gobang_qp[i-1][j] == Gobang_d+1 && Gobang_qp[i+1][j] == Gobang_d+1 && Gobang_qp[i-2][j] != 1 && Gobang_qp[i+2][j] != 1)
				{
					threatenp[a] = i;
					threatenq[a] = j;
					a++;
				}
				if(Gobang_qp[i+1][j] == Gobang_d+1 && Gobang_qp[i+2][j] == Gobang_d+1 && Gobang_qp[i-1][j] != 1 && Gobang_qp[i+3][j] != 1)
				{
					threatenp[a] = i;
					threatenq[a] = j;
					a++;
				}
				if(Gobang_qp[i-1][j+1] == Gobang_d+1 && Gobang_qp[i-2][j+2] == Gobang_d+1 && Gobang_qp[i-3][j+3] != 1 && Gobang_qp[i+1][j-1] != 1)
				{
					threatenp[a] = i;
					threatenq[a] = j;
					a++;
				}
				if(Gobang_qp[i-1][j+1] == Gobang_d+1 && Gobang_qp[i+1][j-1] == Gobang_d+1 && Gobang_qp[i-2][j+2] != 1 && Gobang_qp[i+2][j-2] != 1)
				{
					threatenp[a] = i;
					threatenq[a] = j;
					a++;
				}
				if(Gobang_qp[i+1][j-1] == Gobang_d+1 && Gobang_qp[i+2][j-2] == Gobang_d+1 && Gobang_qp[i+3][j-3] != 1 && Gobang_qp[i-1][j+1] != 1)
				{
					threatenp[a] = i;
					threatenq[a] = j;
					a++;
				}
				if(Gobang_qp[i][j-1] == Gobang_d+1 && Gobang_qp[i][j-2] == Gobang_d+1 && Gobang_qp[i][j-3] != 1 && Gobang_qp[i][j+1] != 1)
				{
					threatenp[a] = i;
					threatenq[a] = j;
					a++;
				}
				if(Gobang_qp[i][j-1] == Gobang_d+1 && Gobang_qp[i][j+1] == Gobang_d+1 && Gobang_qp[i][j-2] != 1 && Gobang_qp[i][j+2] != 1)
				{
					threatenp[a] = i;
					threatenq[a] = j;
					a++;
				}
				if(Gobang_qp[i][j+1] == Gobang_d+1 && Gobang_qp[i][j+2] == Gobang_d+1 && Gobang_qp[i][j-1] != 1 && Gobang_qp[i][j+3] != 1)
				{
					threatenp[a] = i;
					threatenq[a] = j;
					a++;
				}
			}
		}
	}
	for(int i = 0 ; i < a ; i++)
	{
		for(int j = i+1 ; j <= a ; j++)
		{
			if(threatenp[i] == threatenp[j] && threatenq[i] == threatenq[j])
			{
				Gobang_p = threatenp[i];
				Gobang_q = threatenq[i];
			}
		}
	}
}

void Gobang_computermaster10()
{
	int i, j;
	int c10[10];  //用以判断九个方向是否需要防守
	int c20[10];  //判断是否有可以下子的地方
	for(i = 1 ; i < 10 ; i++)
	{
		c10[i] = 0;
		c20[i] = 0;
	}
	for(i = 0, j = 0 ; i >= -6 ; i -= 2, j -= 2)
	{
		if(Gobang_qp[Gobang_LastManStepp[Gobang_k]+i][Gobang_LastManStepq[Gobang_k]+j] == Gobang_k+1)
		{
			c10[1]++;
		}
		if(Gobang_qp[Gobang_LastManStepp[Gobang_k]+i+1][Gobang_LastManStepq[Gobang_k]+j+1] && i < 0)
		{
			c20[1]++;
		}
	}
	for(i = 0, j = 0 ; i >= -6 ; i -= 2)
	{
		if(Gobang_qp[Gobang_LastManStepp[Gobang_k]+i][Gobang_LastManStepq[Gobang_k]+j] == Gobang_k+1)
		{
			c10[2]++;
		}
		if(Gobang_qp[Gobang_LastManStepp[Gobang_k]+i+1][Gobang_LastManStepq[Gobang_k]+j] && i < 0)
		{
			c20[2]++;
		}
	}
	for(i = 0, j = 0 ; i >= -6 ; i -= 2, j += 2)
	{
		if(Gobang_qp[Gobang_LastManStepp[Gobang_k]+i][Gobang_LastManStepq[Gobang_k]+j] == Gobang_k+1)
		{
			c10[3]++;
		}
		if(Gobang_qp[Gobang_LastManStepp[Gobang_k]+i+1][Gobang_LastManStepq[Gobang_k]+j-1] && i < 0)
		{
			c20[3]++;
		}
	}
	for(i = 0, j = 0 ; j >= -6 ; j -= 2)
	{
		if(Gobang_qp[Gobang_LastManStepp[Gobang_k]+i][Gobang_LastManStepq[Gobang_k]+j] == Gobang_k+1)
		{
			c10[4]++;
		}
		if(Gobang_qp[Gobang_LastManStepp[Gobang_k]+i][Gobang_LastManStepq[Gobang_k]+j+1] && j < 0)
		{
			c20[4]++;
		}
	}
	for(i = 0, j = 0 ; j <= 6 ; j += 2)
	{
		if(Gobang_qp[Gobang_LastManStepp[Gobang_k]+i][Gobang_LastManStepq[Gobang_k]+j] == Gobang_k+1)
		{
			c10[6]++;
		}
		if(Gobang_qp[Gobang_LastManStepp[Gobang_k]+i][Gobang_LastManStepq[Gobang_k]+j+1] && j > 0)
		{
			c20[6]++;
		}
	}
	for(i = 0, j = 0 ; i <= 6 ; i += 2, j -= 2)
	{
		if(Gobang_qp[Gobang_LastManStepp[Gobang_k]+i][Gobang_LastManStepq[Gobang_k]+j] == Gobang_k+1)
		{
			c10[7]++;
		}
		if(Gobang_qp[Gobang_LastManStepp[Gobang_k]+i-1][Gobang_LastManStepq[Gobang_k]+j+1] && i > 0)
		{
			c20[7]++;
		}
	}
	for(i = 0, j = 0 ; i <= 6 ; i += 2)
	{
		if(Gobang_qp[Gobang_LastManStepp[Gobang_k]+i][Gobang_LastManStepq[Gobang_k]+j] == Gobang_k+1)
		{
			c10[8]++;
		}
		if(Gobang_qp[Gobang_LastManStepp[Gobang_k]+i-1][Gobang_LastManStepq[Gobang_k]+j] && i > 0)
		{
			c20[8]++;
		}
	}
	for(i = 0, j = 0 ; i <= 6 ; i += 2, j += 2)
	{
		if(Gobang_qp[Gobang_LastManStepp[Gobang_k]+i][Gobang_LastManStepq[Gobang_k]+j] == Gobang_k+1)
		{
			c10[9]++;
		}
		if(Gobang_qp[Gobang_LastManStepp[Gobang_k]+i-1][Gobang_LastManStepq[Gobang_k]+j-1] && i > 0)
		{
			c20[9]++;
		}
	}
	for(i = 1 ; i < 5 ; i++)
	{
		if(c20[i]+c20[10-i] >= c10[i]+c10[10-i]-2)
		{
			c10[i] = c10[10-i] = 0;
		}
	}
	for(i = 1, j = 9 ; i < 5 ; i++, j--)
	{
		if(c10[i] + c10[j] >= 5)
		{
			switch(i)
			{
				case 1:
				{
					srand((unsigned int) time(NULL));
					if(rand()%2 && c20[i] < c10[i]-1 && Gobang_LastManStepp[Gobang_k] != 1 && Gobang_LastManStepq[Gobang_k] != 1)
					{
						Gobang_p = Gobang_LastManStepp[Gobang_k] - (rand() % c10[i])*2+1;
						Gobang_q = Gobang_LastManStepq[Gobang_k] - (rand() % c10[i])*2+1;
						while(Gobang_qp[Gobang_p-1][Gobang_q-1] != 1 || Gobang_p > Gobang_LastManStepp[Gobang_k]+1)
						{
							Gobang_p = Gobang_LastManStepp[Gobang_k] - (rand() % c10[i])*2+1;
							Gobang_q = Gobang_LastManStepq[Gobang_k] - (rand() % c10[i])*2+1;
						}
					}
					else
					{
						Gobang_p = Gobang_LastManStepp[Gobang_k] + (rand() % c10[j])*2-1;
						Gobang_q = Gobang_LastManStepq[Gobang_k] + (rand() % c10[j])*2-1;
						while(Gobang_qp[Gobang_p+1][Gobang_q+1] != 1 || Gobang_p < Gobang_LastManStepp[Gobang_k]-1)
						{
							Gobang_p = Gobang_LastManStepp[Gobang_k] + (rand() % c10[j])*2-1;
							Gobang_q = Gobang_LastManStepq[Gobang_k] + (rand() % c10[j])*2-1;
						}
					}
				}
				break;
				case 2:
				{
					srand((unsigned int) time(NULL));
					if(rand()%2 && c20[i] < c10[i] && Gobang_LastManStepp[Gobang_k] != 1)
					{
						Gobang_p = Gobang_LastManStepp[Gobang_k] - (rand() % c10[i])*2+1;
						Gobang_q = Gobang_LastManStepq[Gobang_k];
						while(Gobang_qp[Gobang_p-1][Gobang_q] != 1 || Gobang_p > Gobang_LastManStepp[Gobang_k]+1)
						{
							Gobang_p = Gobang_LastManStepp[Gobang_k] - (rand() % c10[i])*2+1;
							Gobang_q = Gobang_LastManStepq[Gobang_k];
						}
					}
					else
					{
						Gobang_p = Gobang_LastManStepp[Gobang_k] + (rand() % c10[j])*2-1;
						Gobang_q = Gobang_LastManStepq[Gobang_k];
						while(Gobang_qp[Gobang_p+1][Gobang_q] != 1 || Gobang_p < Gobang_LastManStepp[Gobang_k]-1)
						{
							Gobang_p = Gobang_LastManStepp[Gobang_k] + (rand() % c10[j])*2-1;
							Gobang_q = Gobang_LastManStepq[Gobang_k];
						}
					}
				}
				break;
				case 3:
				{
					srand((unsigned int) time(NULL));
					if(rand()%2 && c20[i] < c10[i] && Gobang_LastManStepp[Gobang_k] != 1 && Gobang_LastManStepp[Gobang_k] != Gobang_n)
					{
						Gobang_p = Gobang_LastManStepp[Gobang_k] - (rand() % c10[i])*2+1;
						Gobang_q = Gobang_LastManStepq[Gobang_k] + (rand() % c10[i])*2-1;
						while(Gobang_qp[Gobang_p-1][Gobang_q+1] != 1 || Gobang_p > Gobang_LastManStepp[Gobang_k]+1)
						{
							Gobang_p = Gobang_LastManStepp[Gobang_k] - (rand() % c10[i])*2+1;
							Gobang_q = Gobang_LastManStepq[Gobang_k] + (rand() % c10[i])*2-1;
						}
					}
					else
					{
						Gobang_p = Gobang_LastManStepp[Gobang_k] + (rand() % c10[j])*2-1;
						Gobang_q = Gobang_LastManStepq[Gobang_k] - (rand() % c10[j])*2+1;
						while(Gobang_qp[Gobang_p+1][Gobang_q-1] != 1 || Gobang_p < Gobang_LastManStepp[Gobang_k]-1)
						{
							Gobang_p = Gobang_LastManStepp[Gobang_k] + (rand() % c10[j])*2-1;
							Gobang_q = Gobang_LastManStepq[Gobang_k] - (rand() % c10[j])*2+1;
						}
					}
				}
				break;
				case 4:
				{
					srand((unsigned int) time(NULL));
					if(rand()%2 && c20[i] < c10[i] && Gobang_LastManStepq[Gobang_k] != 1)
					{
						Gobang_p = Gobang_LastManStepp[Gobang_k];
						Gobang_q = Gobang_LastManStepq[Gobang_k] - (rand() % c10[i])*2+1;
						while(Gobang_qp[Gobang_p][Gobang_q-1] != 1 || Gobang_q > Gobang_LastManStepp[Gobang_k]+1)
						{
							Gobang_p = Gobang_LastManStepp[Gobang_k];
							Gobang_q = Gobang_LastManStepq[Gobang_k] - (rand() % c10[i])*2+1;
						}
					}
					else
					{
						Gobang_p = Gobang_LastManStepp[Gobang_k];
						Gobang_q = Gobang_LastManStepq[Gobang_k] + (rand() % c10[j])*2-1;
						while(Gobang_qp[Gobang_p][Gobang_q+1] != 1 || Gobang_q < Gobang_LastManStepp[Gobang_k]-1)
						{
							Gobang_p = Gobang_LastManStepp[Gobang_k];
							Gobang_q = Gobang_LastManStepq[Gobang_k] + (rand() % c10[j])*2-1;
						}
					}
				}
			}
		}
	}
}

void Gobang_computermaster11()
{
	int i, j;
	for (i = 1; i <= Gobang_n + 1 ; i++)
	{
		if (i == Gobang_n + 1)
		{
			Gobang_p = Gobang_LastManStepp[Gobang_k];
			Gobang_q = Gobang_LastManStepq[Gobang_k];
			break;
		}
		for (j = 1; j <= Gobang_n ; j++)
		{
			if (Gobang_qp[i][j])
			{
				continue;
			}
			Gobang_p = i;
			Gobang_q = j;
			Gobang_win_test();
			if (Gobang_win_test_flag)
			{
				break;
			}
		}
		if (Gobang_win_test_flag)
		{
			Gobang_win_test_flag = 0;
			break;
		}
	}
}

void Gobang_win_test()
{
	int time = 0;
	int t = Gobang_k+1;
	for (int i = Gobang_p - 1; i <= Gobang_p + 1; i++)
	{
		for (int j = Gobang_q - 1; j <= Gobang_q + 1; j++)
		{
			time++;
			if (Gobang_win_test_flag)  break;
			if (time == 5)
			{
				continue;
			}
			if (Gobang_qp[i][j] == t)
			{
				switch (time)
				{
				case 1:
				{
					if ((Gobang_qp[Gobang_p - 4][Gobang_q - 4] == t && Gobang_qp[Gobang_p - 3][Gobang_q - 3] == t && Gobang_qp[Gobang_p - 2][Gobang_q - 2] == t) || (Gobang_qp[Gobang_p - 3][Gobang_q - 3] == t && Gobang_qp[Gobang_p - 2][Gobang_q - 2] == t && Gobang_qp[Gobang_p + 1][Gobang_q + 1] == t) || (Gobang_qp[Gobang_p - 2][Gobang_q - 2] == t && Gobang_qp[Gobang_p + 1][Gobang_q + 1] == t && Gobang_qp[Gobang_p + 2][Gobang_q + 2] == t) || (Gobang_qp[Gobang_p + 1][Gobang_q + 1] == t && Gobang_qp[Gobang_p + 2][Gobang_q + 2] == t && Gobang_qp[Gobang_p + 3][Gobang_q + 3] == t))
					{
						Gobang_win_test_flag = 1;
					}
				}
				break;
				case 2:
				{
					if ((Gobang_qp[Gobang_p - 4][Gobang_q] == t && Gobang_qp[Gobang_p - 3][Gobang_q] == t && Gobang_qp[Gobang_p - 2][Gobang_q] == t) || (Gobang_qp[Gobang_p - 3][Gobang_q] == t && Gobang_qp[Gobang_p - 2][Gobang_q] == t && Gobang_qp[Gobang_p + 1][Gobang_q] == t) || (Gobang_qp[Gobang_p - 2][Gobang_q] == t && Gobang_qp[Gobang_p + 1][Gobang_q] == t && Gobang_qp[Gobang_p + 2][Gobang_q] == t) || (Gobang_qp[Gobang_p + 1][Gobang_q] == t && Gobang_qp[Gobang_p + 2][Gobang_q] == t && Gobang_qp[Gobang_p + 3][Gobang_q] == t))
					{
						Gobang_win_test_flag = 1;
					}
				}
				break;
				case 3:
				{
					if ((Gobang_qp[Gobang_p - 4][Gobang_q + 4] == t && Gobang_qp[Gobang_p - 3][Gobang_q + 3] == t && Gobang_qp[Gobang_p - 2][Gobang_q + 2] == t) || (Gobang_qp[Gobang_p - 3][Gobang_q + 3] == t && Gobang_qp[Gobang_p - 2][Gobang_q + 2] == t && Gobang_qp[Gobang_p + 1][Gobang_q - 1] == t) || (Gobang_qp[Gobang_p - 2][Gobang_q + 2] == t && Gobang_qp[Gobang_p + 1][Gobang_q - 1] == t && Gobang_qp[Gobang_p + 2][Gobang_q - 2] == t) || (Gobang_qp[Gobang_p + 1][Gobang_q - 1] == t && Gobang_qp[Gobang_p + 2][Gobang_q - 2] == t && Gobang_qp[Gobang_p + 3][Gobang_q - 3] == t))
					{
						Gobang_win_test_flag = 1;
					}
				}
				break;
				case 4:
				{
					if ((Gobang_qp[Gobang_p][Gobang_q - 4] == t && Gobang_qp[Gobang_p][Gobang_q - 3] == t && Gobang_qp[Gobang_p][Gobang_q - 2] == t) || (Gobang_qp[Gobang_p][Gobang_q - 3] == t && Gobang_qp[Gobang_p][Gobang_q - 2] == t && Gobang_qp[Gobang_p][Gobang_q + 1] == t) || (Gobang_qp[Gobang_p][Gobang_q - 2] == t && Gobang_qp[Gobang_p][Gobang_q + 1] == t && Gobang_qp[Gobang_p][Gobang_q + 2] == t) || (Gobang_qp[Gobang_p][Gobang_q + 1] == t && Gobang_qp[Gobang_p][Gobang_q + 2] == t && Gobang_qp[Gobang_p][Gobang_q + 3] == t))
					{
						Gobang_win_test_flag = 1;
					}
				}
				break;
				case 6:
				{
					if ((Gobang_qp[Gobang_p][Gobang_q - 3] == t && Gobang_qp[Gobang_p][Gobang_q - 2] == t && Gobang_qp[Gobang_p][Gobang_q - 1] == t) || (Gobang_qp[Gobang_p][Gobang_q - 2] == t && Gobang_qp[Gobang_p][Gobang_q - 1] == t && Gobang_qp[Gobang_p][Gobang_q + 2] == t) || (Gobang_qp[Gobang_p][Gobang_q - 1] == t && Gobang_qp[Gobang_p][Gobang_q + 2] == t && Gobang_qp[Gobang_p][Gobang_q + 3] == t) || (Gobang_qp[Gobang_p][Gobang_q + 2] == t && Gobang_qp[Gobang_p][Gobang_q + 3] == t && Gobang_qp[Gobang_p][Gobang_q + 4] == t))
					{
						Gobang_win_test_flag = 1;
					}
				}
				break;
				case 7:
				{
					if ((Gobang_qp[Gobang_p - 3][Gobang_q + 3] == t && Gobang_qp[Gobang_p - 2][Gobang_q + 2] == t && Gobang_qp[Gobang_p - 1][Gobang_q + 1] == t) || (Gobang_qp[Gobang_p - 2][Gobang_q + 2] == t && Gobang_qp[Gobang_p - 1][Gobang_q + 1] == t && Gobang_qp[Gobang_p + 2][Gobang_q - 2] == t) || (Gobang_qp[Gobang_p - 1][Gobang_q + 1] == t && Gobang_qp[Gobang_p + 2][Gobang_q - 2] == t && Gobang_qp[Gobang_p + 3][Gobang_q - 3] == t) || (Gobang_qp[Gobang_p + 2][Gobang_q - 2] == t && Gobang_qp[Gobang_p + 3][Gobang_q - 3] == t && Gobang_qp[Gobang_p + 4][Gobang_q - 4] == t))
					{
						Gobang_win_test_flag = 1;
					}
				}
				break;
				case 8:
				{
					if ((Gobang_qp[Gobang_p - 3][Gobang_q] == t && Gobang_qp[Gobang_p - 2][Gobang_q] == t && Gobang_qp[Gobang_p - 1][Gobang_q] == t) || (Gobang_qp[Gobang_p - 2][Gobang_q] == t && Gobang_qp[Gobang_p - 1][Gobang_q] == t && Gobang_qp[Gobang_p + 2][Gobang_q] == t) || (Gobang_qp[Gobang_p - 1][Gobang_q] == t && Gobang_qp[Gobang_p + 2][Gobang_q] == t && Gobang_qp[Gobang_p + 3][Gobang_q] == t) || (Gobang_qp[Gobang_p + 2][Gobang_q] == t && Gobang_qp[Gobang_p + 3][Gobang_q] == t && Gobang_qp[Gobang_p + 4][Gobang_q] == t))
					{
						Gobang_win_test_flag = 1;
					}
				}
				break;
				case 9:
				{
					if ((Gobang_qp[Gobang_p - 3][Gobang_q - 3] == t && Gobang_qp[Gobang_p - 2][Gobang_q - 2] == t && Gobang_qp[Gobang_p - 1][Gobang_q - 1] == t) || (Gobang_qp[Gobang_p - 2][Gobang_q - 2] == t && Gobang_qp[Gobang_p - 1][Gobang_q - 1] == t && Gobang_qp[Gobang_p + 2][Gobang_q + 2] == t) || (Gobang_qp[Gobang_p - 1][Gobang_q - 1] == t && Gobang_qp[Gobang_p + 2][Gobang_q + 2] == t && Gobang_qp[Gobang_p + 3][Gobang_q + 3] == t) || (Gobang_qp[Gobang_p + 2][Gobang_q + 2] == t && Gobang_qp[Gobang_p + 3][Gobang_q + 3] == t && Gobang_qp[Gobang_p + 4][Gobang_q + 4] == t))
					{
						Gobang_win_test_flag = 1;
					}
				}
				break;
				}
			}
		}
	}
}

