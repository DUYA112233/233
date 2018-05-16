#ifndef _GOBANGINIT_H_
#define _GOBANGINIT_H_

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include "Gobang_computermaster.h"

extern int Gobang_qp[21][21];
extern int Gobang_flag, Gobang_TheFirstStep[2];
extern int Gobang_n, Gobang_p, Gobang_q, Gobang_choice, Gobang_laststepp, Gobang_laststepq;
extern char Gobang_winer1[9], Gobang_winer2[9];
extern int Gobang_LastManStepp[2], Gobang_LastManStepq[2];
extern int Gobang_lastattackp[2], Gobang_lastattackq[2];
extern int Gobang_ifentercm6[2];
extern int Gobang_k, Gobang_d;
extern int Gobang_exit233[99];
extern int Gobang_win_test_flag;
void setColor(unsigned short ForeColor, unsigned short BackGroundColor);

#endif