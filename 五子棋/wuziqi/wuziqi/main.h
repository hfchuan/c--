#include<stdio.h>
#include<graphics.h>	//ͼ�ο�ͷ�ļ�
#include <conio.h>
#include<mmsystem.h>	//��������ͷ�ļ�
#include<math.h>

#pragma comment(lib, "winmm.lib")	//�������ֿ��ļ�

int flag = 0;	//��ʾ�������
int board[20][20] = { 0 };	//0��ʾ����û������״̬

void initGame();
int judge(int a, int b);
void playChess();