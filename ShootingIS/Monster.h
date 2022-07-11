#pragma once

#include "Render.h"
#include "CirclePatton.h"


#define ORDERPOS_MAX 3
// 총알을 뿌려주는 몬스터 ( & & )

struct Pos
{
	float x;
	float y;
};

Pos monsPos = { SCREEN_WIDTH / 2 ,SCREEN_HEIGHT / 3 }; // 몬스터의 좌표값을 저장합니다.
float mob_speed = 120 * delta_time;//몬스터의 이동속도입니다. 1초에 몇칸을 움직일지를 저장합니다.
int monsterSize = 7; // 몬스터의 가로크기입니다.

Pos orderPoses [ORDERPOS_MAX]= {{ 7 ,SCREEN_HEIGHT / 3 },{ SCREEN_WIDTH -7 ,SCREEN_HEIGHT / 3 } ,{ SCREEN_WIDTH / 2 ,SCREEN_HEIGHT / 4 } };
int orderInd = 0;

void Monster_InWindow()// 몬스터 좌표가 화면 밖으로 벗어나지않게 처리해줍니다.
{
	float haf = monsterSize / 2;
	if (monsPos.x >= SCREEN_WIDTH - haf)
		monsPos.x = SCREEN_WIDTH - 1 - haf;
	if (monsPos.y >= SCREEN_HEIGHT - haf)
		monsPos.y = SCREEN_HEIGHT - 1 - haf;
	if (monsPos.x <  haf)
		monsPos.x = haf - 1;
	if (monsPos.y <  haf)
		monsPos.y = haf - 1;
}
void Monster_SetPosition(int x, int y) // 지정 좌표에 몬스터를 세팅.
{
	monsPos.x = x;
	monsPos.y = y;

	Monster_InWindow();
	print(monsPos.x, monsPos.y, "( & & )", WHITE);
}
void Monster_Init() // 몬스터의 초기화를 해주는 함수입니다.
{
	Monster_SetPosition(50, 10);
}

bool Monster_OrderToMove(Pos destPos) //Update에서 호출시 지정 위치로 부드럽게 이동합니다. 이동종료시 false를 반환합니다.
{
	static Pos destinationPos = { 0,-9913 };
	static Pos startPos = { 0, -923};
	static float dt = 0.0;
	static float len;
	static float lenx;
	static float leny;

	if ((int)destinationPos.x != (int)destPos.x || (int)destinationPos.y != (int)destPos.y) // 새로운 목적지가 들어오면 dt = 0
	{
		dt = 0.0;
		destinationPos = destPos;
		startPos = monsPos;
		len = sqrt((destPos.x - monsPos.x) * (destPos.x - monsPos.x) + (destPos.y - monsPos.y)*(destPos.y - monsPos.y));
		lenx = (destPos.x - monsPos.x);
		leny = (destPos.y - monsPos.y);
	}

	dt += mob_speed / len;
	if (dt > 1.0)
	{
		monsPos = destPos;
		dt = 0.0;
		return false;
	}
	monsPos.x = startPos.x + lenx * dt;
	monsPos.y = startPos.y +  leny * dt;
	
	return true;
}
void Monster_Update() // 몬스터를 업데이트하는 함수입니다.
{
	if (!Monster_OrderToMove(orderPoses[orderInd]))// 목적지에 몬스터가 다다르면 이동을 종료합니다
	{
		CirclePatton_Shoot(monsPos.x, monsPos.y, 1, 0.5, 8);
		++orderInd;
		if (orderInd >= ORDERPOS_MAX)
			orderInd = 0;
	}
	CirclePatton_Shoot(monsPos.x, monsPos.y, 3, 0.5, 2);
	Monster_SetPosition(monsPos.x, monsPos.y);	
}