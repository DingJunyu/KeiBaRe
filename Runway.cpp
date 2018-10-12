#pragma once
#include"stdafx.h"

Runway& Runway::CopyFromHorse(std::string Nam,
	double Spe, double Sta, double Fat, double Wei, double Len) {
	HorseHere.Name = Nam;
	HorseHere.ShortName = HorseHere.Name.substr(0, 2);
	HorseHere.Speed = Spe;
	HorseHere.Status = Sta;
	HorseHere.Fatigue = Fat;
	HorseHere.Weight = Wei;
	Length = Len;
	return *this;
}

Runway& Runway::Inif() {
	CurrentSpeed = 0;
	AlreadyPass = 0;
	FullSpeedTime = 0;
	Acceleration = INIF_ACCELERATION;
	MaxFST = INIF_FST;

	MaxSpeedWhenTired = HorseHere.Speed * (SPEED_DOWN_WITH_FST*
		(HorseHere.Weight / INIF_WEIGHT));

	MaxFST += (double)(HorseHere.Weight - INIF_WEIGHT)*WEIGHT_TO_FST;
	//�d�ʂƍő呬�x�ێ����Ԃ̊֌W
	MaxFST += (double)(HorseHere.Status - STANDARD_STATUS)*STATUS_TO_FST;
	//��Ԃƍő呬�x�ێ����Ԃ̊֌W
	Acceleration -= (double)(HorseHere.Weight - INIF_WEIGHT)
		*WEIGHT_TO_ACC;
	//�d�ʂƉ����x�̊֌W
	Acceleration += (double)(HorseHere.Status - STANDARD_STATUS)
		*STATUS_TO_ACC;
	//��ԂƉ����x�̊֌W
	if (Acceleration <= ACC_MIN)
		Acceleration = ACC_MIN;
	if (MaxFST <= FST_MIN)
		MaxFST = FST_MIN;
	return *this;
}

Runway& Runway::Running() {
	//�ő呬�x�ɂȂ�O�ł���΃X�s�[�h���オ��
	CurrentSpeed += Acceleration;

	if (FullSpeedTime < MaxFST && CurrentSpeed > HorseHere.Speed)
		CurrentSpeed = HorseHere.Speed;

	if (FullSpeedTime >= MaxFST && CurrentSpeed >
		MaxSpeedWhenTired)
		CurrentSpeed = MaxSpeedWhenTired;

	//�ő呬�x�Ɣ�J�̊֌W
	if ((rand() % 100 + 1) <= HorseHere.Fatigue&&CurrentSpeed >=
		HorseHere.Speed - SPEED_MIN)
		CurrentSpeed -= SPEED_DOWN_WITH_FATIGUE;

	++FullSpeedTime;
	AlreadyPass += CurrentSpeed;//�������������L�^
	return *this;
}

int Runway::EndofMatch() {
	if (AlreadyPass >= Length)
		return (int)(AlreadyPass - Length);
	else
		return -1;
}

void Runway::Display() {
	double Blocks;
	Blocks = AlreadyPass / Length*LENGTH_SHOW;
	if (Blocks >= LENGTH_SHOW)
		Blocks = LENGTH_SHOW;//�`���͈͉z���Ȃ�
	for (int i = 0; i <= (int)Blocks; ++i)
		printf("-");
	std::cout << HorseHere.ShortName;

	HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_SCREEN_BUFFER_INFO bInfo;
	GetConsoleScreenBufferInfo(hOut, &bInfo);
	COORD pos;
	pos = bInfo.dwCursorPosition;
	pos.X = LENGTH_SHOW + 3 +3;
	//���̂R�͊����ꕶ���̈ʒu�A���͍̂ŏ��̂R����
	SetConsoleCursorPosition(hOut, pos);

	printf("|%4.1f/%4.0f\n",AlreadyPass, Length);
}

void Runway::ShowWinner(int Winner) {
	std::cout << Winner+1 << "��" <<
		HorseHere.Name << "���D�����܂���" << std::endl;
}