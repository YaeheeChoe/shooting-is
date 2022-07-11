#pragma once
#include <fmod.hpp>
#include "fmod_errors.h"
#pragma comment (lib, "fmodex_vc.lib")
using namespace FMOD;

bool IsBGPlaying = false;
bool IsEffectPlaying = false;

System*	pSystem;
Sound* pSound[3];  // ���������� ���� ����
Channel* pChannel[3];  // ���ÿ� ����� ���� �ִ� ����

/* ������*/
void Sound_Init()
{
}

void Sound_PlayIngameBGM() //�ΰ��� BGM�� �ۼ��ϴ�  �Լ��Դϴ�.
{
	// ���� �ý����� ����
	System_Create(&pSystem);
	// ���� �ý��� �⺻ ����
	pSystem->init(3, FMOD_INIT_NORMAL, NULL);

	//���� ���� ����
	pSystem->createSound("ingame.mp3", FMOD_LOOP_NORMAL | FMOD_HARDWARE, NULL, &pSound[0]);

	// Channel[0] ������
	pChannel[0]->isPlaying(&IsBGPlaying);

	// Channel[0]�� �ּڰ����� BGM���
	pSystem->playSound(FMOD_CHANNEL_REUSE, pSound[0], false, &pChannel[0]);

	// ����� ingame.mp3�� ����մϴ�.
}

void Sound_PlayShootEffect() // �� �� ȿ������ ����ϴ� �Լ��Դϴ�.
{
	// ���� �ý����� ����
	System_Create(&pSystem);
	// ���� �ý��� �⺻ ����
	pSystem->init(3, FMOD_INIT_NORMAL, NULL);
	
	//���� ���� ����
	pSystem->createSound("shoot.mp3", FMOD_LOOP_OFF | FMOD_HARDWARE, NULL, &pSound[1]);

	// Channel[1] ������
	pChannel[1]->isPlaying(&IsEffectPlaying);

	// Channel[1]�� �ּڰ����� BGM���
	pSystem->playSound(FMOD_CHANNEL_REUSE, pSound[1], false, &pChannel[1]);

	// ����� shoot.mp3�� ����մϴ�.
}
void Sound_PlayDethEffect() // �÷��̾��� ��� �� ȿ������ ����ϴ� �Լ��Դϴ�.
{
	// ���� �ý����� ����
	System_Create(&pSystem);
	// ���� �ý��� �⺻ ����
	pSystem->init(3, FMOD_INIT_NORMAL, NULL);

	//���� ���� ����
	pSystem->createSound("death.mp3", FMOD_LOOP_OFF | FMOD_HARDWARE, NULL, &pSound[2]);

	// Channel[0]�� Channel[1]�� BGM ����
	pChannel[0]->stop();
	pChannel[1]->stop();

	// Channel[0]�� �ּڰ����� BGM���
	pSystem->playSound(FMOD_CHANNEL_REUSE, pSound[2], false, &pChannel[0]);
	// ����� death.mp3�� ����մϴ�.
}
/* ������*/