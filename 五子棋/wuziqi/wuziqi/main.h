#include<stdio.h>
#include<graphics.h>	//图形库头文件
#include <conio.h>
#include<mmsystem.h>	//播放音乐头文件
#include<math.h>

#pragma comment(lib, "winmm.lib")	//播放音乐库文件

int flag = 0;	//表示下棋次数
int board[20][20] = { 0 };	//0表示棋盘没有棋子状态

void initGame();
int judge(int a, int b);
void playChess();