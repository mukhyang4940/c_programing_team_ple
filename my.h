#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include <conio.h>

void map_low(void);
void map_mid(void);
void map_high(void);

void secret_low();
void secret_mid();
void secret_high(int high[24][50]);

void move_low();
void move_mid();
void move_high();

void hint_interrupt_low();
void hint_interrupt_mid();
void hint_interrupt_high();

void guide();
void score();
int menu();
void gotoxy(int x, int y);

int xlow[8];
int ylow[8];

int xmid[10];
int ymid[10];

int xhigh[16];
int yhigh[16];

int x, y; //x��ǥ
int X, Y; //����Ʈ �� ��ġ.
int point;
int move_number;
int tempi, tempj;

int receive[24][50];//�迭�� ��ǥ�� �޴� �迭
int get[24][50];