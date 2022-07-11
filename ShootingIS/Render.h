#pragma once
#include <stdio.h>
#include <windows.h>

#define delta_time 0.001 //ȭ���� ���� �׷��ִ� �ð�
#define SCREEN_WIDTH 100 // ȭ�� ����ũ��
#define SCREEN_HEIGHT 50 // ȭ�� ����ũ��

// ���� ����.
enum
{
	BLACK,
	DARK_BLUE,
	DARK_GREEN,
	DARK_SKYBLUE,
	DARK_RED,
	DARK_VOLET,
	DARK_YELLOW,
	GRAY,
	DARK_GRAY,
	BLUE,
	GREEN,
	SKYBLUE,
	RED,
	VIORET,
	YELLOW,
	WHITE
};
void SetColor(int color_number)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color_number);
}

void gotoxy(int x, int y) // Ŀ���� ������ ��ġ�� �̵��մϴ�.
{
	COORD Pos = { x - 1, y - 1 };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}
void print(int x, int y, char *str, int color) // x,y��ǥ�� str�� color������ �ѷ��ݴϴ�.
{
	SetColor(color);
	gotoxy(x, y);
	printf("%s",str);
}
bool InWindow(int x, int y )// �ش� ��ǥ�� ȭ�� �ȿ� �ִ��� �Ǻ��մϴ�.
{
	if (x >= SCREEN_WIDTH)
		return false;
	if (y >= SCREEN_HEIGHT)
		return false;
	if (x <  0)
		return false;
	if (y <  0)
		return false;
	return true;
}
void RemoveCursor() // �ܼ�â�� Ŀ���� �Ⱥ��̰� �����մϴ�.
{
	CONSOLE_CURSOR_INFO cursorInfo = { 0, };
	cursorInfo.dwSize = 1;
	cursorInfo.bVisible = FALSE;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursorInfo);
}
void Render_Init() // ���� ���۽� ù��°�� ����Ǵ� �Լ�
{
	system("mode con:cols=100 lines=50"); // �ܼ�â�� ũ�⸦ ������ ȭ��ũ�⿡ ���� �������ݴϴ�.
	RemoveCursor();//Ŀ���� �����ݴϴ�.
}


void Render(int retime) //ȭ������ �׷��ִ� �Լ�
{
	Sleep(retime); //delta_time ��ŭ�� �ð� ������ �ΰ� ȭ���� ���� �׷��ݴϴ�.
	system("cls");
}