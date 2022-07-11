#pragma once
#include <stdio.h>
#include <windows.h>

#define delta_time 0.001 //화면을 새로 그려주는 시간
#define SCREEN_WIDTH 100 // 화면 가로크기
#define SCREEN_HEIGHT 50 // 화면 세로크기

// 색상값 정의.
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

void gotoxy(int x, int y) // 커서를 지정된 위치로 이동합니다.
{
	COORD Pos = { x - 1, y - 1 };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}
void print(int x, int y, char *str, int color) // x,y좌표에 str을 color색으로 뿌려줍니다.
{
	SetColor(color);
	gotoxy(x, y);
	printf("%s",str);
}
bool InWindow(int x, int y )// 해당 좌표가 화면 안에 있는지 판별합니다.
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
void RemoveCursor() // 콘솔창의 커서를 안보이게 설정합니다.
{
	CONSOLE_CURSOR_INFO cursorInfo = { 0, };
	cursorInfo.dwSize = 1;
	cursorInfo.bVisible = FALSE;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursorInfo);
}
void Render_Init() // 게임 시작시 첫번째로 실행되는 함수
{
	system("mode con:cols=100 lines=50"); // 콘솔창의 크기를 지정한 화면크기에 맞춰 변경해줍니다.
	RemoveCursor();//커서를 지워줍니다.
}


void Render(int retime) //화면을을 그려주는 함수
{
	Sleep(retime); //delta_time 만큼의 시간 간격을 두고 화면을 새로 그려줍니다.
	system("cls");
}