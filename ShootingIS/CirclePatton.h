#pragma once

// ���� �Ѿ� ������ �������ִ� �Լ��� �����Դϴ�.
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

// (posx,posy) ��ġ�� bullȽ����ŭ cooltime������ �ΰ� ������r�� �Ѿ��� �߻��� ���� �����մϴ�.
// �̹� ���ð� ������ ���¿����� false�� ��ȯ�ϰ� �ƹ��� ó���� ���� �ʽ��ϴ�.
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

bool CirclePatton_Update( )// �Ѿ� �߻����� ���¿��� true, �ƴϸ� false ��ȯ.
{
	// satic ������ �� �ѹ��� �ʱ�ȭ�Ǹ�, �޸𸮿� ���������� �ش� ������ ����� �Լ� �ȿ����� ����� �� �ִ� �����Դϴ�.
	static int circle_color = RED;
	float nowtime = Timer_Now();

	if (!isShooting)
		return false;

	
	if ( nowtime - c_shoot_time > c_cool_time)// c_cooltime��ŭ ���� �� �� �Ѿ� �߻�. �߻�Ǵ� �Ѿ��� ���ߵ�
	{
		if (c_bullet_n<=0) // �Ѿ��� c_bullet_nȸ �߻��ϸ� �ٽ� Sleep�մϴ�.
		{
			isShooting = false;
			return false;
		}
		
		// ����� �Ѿ˰� ������ �Ѿ��� �����ư��鼭 �߻�.

		if (circle_color != VIORET)
			circle_color = VIORET;
		else
			circle_color = RED;
		Bullet_CirclePatton(c_posx, c_posy, c_rad, circle_color);
		
		--c_bullet_n;
	}
	return true;
}