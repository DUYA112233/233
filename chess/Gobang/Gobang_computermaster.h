#ifndef _GOBANG_COMPUTERMASTER_H_
#define _GOBANG_COMPUTERMASTER_H_

void Gobang_computer();		 //随机下
void Gobang_computermaster1();  //连线进攻
void Gobang_computermaster2();  //多子连续防守
void Gobang_computermaster3();  //2 1中间防守（后外层）
void Gobang_computermaster4();  //四子与无防守三子直接进攻
void Gobang_computermaster5();  //2 1中间进攻
void Gobang_computermaster6();  //2 1中间防守（后内层）
void Gobang_computermaster7();  //3 1防守（后3）
void Gobang_computermaster8();  //多线交点防守
void Gobang_computermaster9();  //多线交点进攻
void Gobang_computermaster10(); //四子一线并间距一格的防守
void Gobang_computermaster11(); //四子连线直接获胜
void Gobang_win_test();         //试探有没有下一步直接获胜的可能

#endif
