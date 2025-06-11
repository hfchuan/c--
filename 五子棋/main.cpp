
#include<iostream>
#include <conio.h>
#include <graphics.h>
using namespace std;

int main()
{
    int gd=DETECT,gm;
    initgraph(&gd,&gm,(char*)"");
    circle(200,200,100);
    getch();
    return 0;
}