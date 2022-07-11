// 시간을 측정해주는 함수의 집합입니다.
#pragma once
#include <time.h>

time_t startTime = 0;
void Timer_Start()
{
	startTime = clock();
}
float Timer_Now() // 타이머가 초기화된 시간부터 흐른 시간을 초단위로 반환합니다.
{
	return (float)((clock() - startTime) / (float)(CLOCKS_PER_SEC));
}