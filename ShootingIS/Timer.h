// �ð��� �������ִ� �Լ��� �����Դϴ�.
#pragma once
#include <time.h>

time_t startTime = 0;
void Timer_Start()
{
	startTime = clock();
}
float Timer_Now() // Ÿ�̸Ӱ� �ʱ�ȭ�� �ð����� �帥 �ð��� �ʴ����� ��ȯ�մϴ�.
{
	return (float)((clock() - startTime) / (float)(CLOCKS_PER_SEC));
}