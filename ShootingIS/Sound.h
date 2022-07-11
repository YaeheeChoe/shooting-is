#pragma once
#include <fmod.hpp>
#include "fmod_errors.h"
#pragma comment (lib, "fmodex_vc.lib")
using namespace FMOD;

bool IsBGPlaying = false;
bool IsEffectPlaying = false;

System*	pSystem;
Sound* pSound[3];  // 음악파일을 담을 변수
Channel* pChannel[3];  // 동시에 재생될 음악 최대 개수

/* 상헌이*/
void Sound_Init()
{
}

void Sound_PlayIngameBGM() //인게임 BGM을 작성하는  함수입니다.
{
	// 사운드 시스템을 생성
	System_Create(&pSystem);
	// 사운드 시스템 기본 세팅
	pSystem->init(3, FMOD_INIT_NORMAL, NULL);

	//음악 파일 생성
	pSystem->createSound("ingame.mp3", FMOD_LOOP_NORMAL | FMOD_HARDWARE, NULL, &pSound[0]);

	// Channel[0] 가동중
	pChannel[0]->isPlaying(&IsBGPlaying);

	// Channel[0]의 주솟값에서 BGM재생
	pSystem->playSound(FMOD_CHANNEL_REUSE, pSound[0], false, &pChannel[0]);

	// 실행시 ingame.mp3를 재생합니다.
}

void Sound_PlayShootEffect() // 총 쏠때 효과음을 재생하는 함수입니다.
{
	// 사운드 시스템을 생성
	System_Create(&pSystem);
	// 사운드 시스템 기본 세팅
	pSystem->init(3, FMOD_INIT_NORMAL, NULL);
	
	//음악 파일 생성
	pSystem->createSound("shoot.mp3", FMOD_LOOP_OFF | FMOD_HARDWARE, NULL, &pSound[1]);

	// Channel[1] 가동중
	pChannel[1]->isPlaying(&IsEffectPlaying);

	// Channel[1]의 주솟값에서 BGM재생
	pSystem->playSound(FMOD_CHANNEL_REUSE, pSound[1], false, &pChannel[1]);

	// 실행시 shoot.mp3를 재생합니다.
}
void Sound_PlayDethEffect() // 플레이어의 사망 시 효과음을 재생하는 함수입니다.
{
	// 사운드 시스템을 생성
	System_Create(&pSystem);
	// 사운드 시스템 기본 세팅
	pSystem->init(3, FMOD_INIT_NORMAL, NULL);

	//음악 파일 생성
	pSystem->createSound("death.mp3", FMOD_LOOP_OFF | FMOD_HARDWARE, NULL, &pSound[2]);

	// Channel[0]과 Channel[1]의 BGM 정지
	pChannel[0]->stop();
	pChannel[1]->stop();

	// Channel[0]의 주솟값에서 BGM재생
	pSystem->playSound(FMOD_CHANNEL_REUSE, pSound[2], false, &pChannel[0]);
	// 실행시 death.mp3를 재생합니다.
}
/* 상헌이*/