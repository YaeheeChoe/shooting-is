#pragma once

// 원형 총알 패턴을 관리해주는 함수의 집합입니다.
#include "Bullet.h"
#include "Timer.h"
#include "Sound.h"

#define PLAY_TIME 20.0

bool isShooting = false;
float c_shoot_time = 0.0;
float c_cool_time = 0.0;
int c_bullet_n = 0;

float c_posx = 0;
float c_posy = 0;
int c_rad;

// (posx,posy) 위치에 bull횟수만큼 cooltime간격을 두고 반지름r로 총알을 발사할 것을 지시합니다.
// 이미 지시가 내려진 상태에서는 false를 반환하고 아무런 처리도 하지 않습니다.
bool CirclePatton_Shoot(float posx, float posy, int bull = 3, float cooltime = 1.0, int r = 3)
{
	Sound_PlayShootEffect();
	if (isShooting)
		return false;
	isShooting = true;
	c_posx = posx;
	c_posy = posy;
	c_bullet_n = bull;
	c_cool_time = cooltime;
	c_rad = r;
	c_shoot_time = Timer_Now();
	return true;
}

bool CirclePatton_Update( )// 총알 발사중인 상태에서 true, 아니면 false 반환.
{
	// satic 변수는 단 한번만 초기화되며, 메모리에 상주하지만 해당 변수가 선언된 함수 안에서만 사용할 수 있는 변수입니다.
	static int circle_color = RED;
	float nowtime = Timer_Now();

	if (!isShooting)
		return false;

	
	if ( nowtime - c_shoot_time > c_cool_time)// c_cooltime만큼 텀을 준 후 총알 발사. 발사되는 총알은 연발됨
	{
		if (c_bullet_n<=0) // 총알을 c_bullet_n회 발사하면 다시 Sleep합니다.
		{
			isShooting = false;
			return false;
		}
		
		// 보라색 총알과 빨간색 총알을 번갈아가면서 발사.

		if (circle_color != VIORET)
			circle_color = VIORET;
		else
			circle_color = RED;
		Bullet_CirclePatton(c_posx, c_posy, c_rad, circle_color);
		
		--c_bullet_n;
	}
	return true;
}