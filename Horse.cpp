#include"stdafx.h"

Horse& Horse::Initiaize(std::string GivenName) {//�n�̃f�[�^��������
	//define�l�ʂ�n��
	Speed = INIF_SPEED;
	Weight = INIF_WEIGHT;
	Status = INIF_STATUS;
	MaxLevel = INIF_MAXLEVEL;
	Level = INIF_LEVEL;
	Fatigue = INIF_FATIGUE;
	Odds = INIF_ODDS;

	Name = GivenName;//�n���ꂽ�������ۑ�
	/*�����f�[�^�S�������_���ɕς��*/
	Speed += Random(CHAN_SPEED);
	Weight += Random(CHAN_WEIGHT);
	Status += Random(CHAN_STATUS);
	MaxLevel += Random(CHAN_LEVEL);

	return *this;
}

Horse& Horse::LevelUp() {
	++Level;
	Speed += SPEED_PER_LEVEL;//�X�s�[�h�͏オ��
	Weight += Random(WEIGHT_CHAN_PER_LEVEL);
	//�d�ʂ̓����_���ɕς��(�����邱�Ƃ�����)
	Status += STATUS_PER_LEVEL;//�e���V�����͏オ��
	return *this;
}

Horse& Horse::Record(bool Win) {
	if (Win) {//���ꍇ
		++Winned;
		Status -= STATUS_DOWN_WIN;//�e���V������������
		if (Status < STATUS_MIN)//�ŏ��l�𒴂��Ȃ��悤
			Status = STATUS_MIN;
		Odds -= ODDS_PER_WIN;//�z������������
		if (Odds < ODDS_MIN)//�ŏ��l�𒴂��Ȃ��悤
			Odds = ODDS_MIN;
	}
	else {//�������ꍇ
		Status += STATUS_UP_LOSE;//�e���V�������オ��
		if (Status > STATUS_MAX)//�ő�l�𒴂��Ȃ��悤
			Status = STATUS_MAX;
		Odds += ODDS_PER_LOSE;//�z�������オ��
	}
	++Played;
	if (Played > Level * 5 && Level <= MaxLevel)//�T�񖈂Ƀ��[�x�����オ��
		LevelUp();
	return *this;
}

double& Horse::Query(int Num) {//�g���b�N�Ƀf�[�^��n���p
	switch (Num)
	{
	case SPEED:return Speed;
	case STATUS:return Status;
	case FATIGUE:return Fatigue;
	case WEIGHT:return Weight;
	case ODDS:return Odds;
	};
}

double Random(int Range) {
	int RandomMark;//�����ƕ����̔���
	RandomMark = rand() % 2;
	if (RandomMark == 1)//������Ԃ�
		return (double)(((rand() % (Range*100)))/100);
	else//������Ԃ�
		return 0 - (double)(((rand() % (Range * 100))) / 100);
}

void Horse::Display() {
	std::cout << Name << " �̏d:"
		<< Weight << "Kg �e���V����:"
		<< Status - INIF_STATUS << "% "
		<< "�z����:" << Odds;

	HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_SCREEN_BUFFER_INFO bInfo;
	GetConsoleScreenBufferInfo(hOut, &bInfo);
	COORD pos;
	pos = bInfo.dwCursorPosition;
	pos.X = LENGTH_SHOW + 3 + 3;
	//���̂R�͊����ꕶ���̈ʒu�A���͍̂ŏ��̂R����
	SetConsoleCursorPosition(hOut, pos);

	std::cout << "|0" << std::endl;
}

Horse& Horse::rest(bool Played) {
	if (!Played) {
		Fatigue += FATIGUE_PER_MATCH;
		Odds += ODDS_PER_MATCH;//�������Ƃɂ���Ĕz�������ς��
	}
	else {
		Fatigue -= FATIGUE_PER_REST;
		Odds += ODDS_PER_REST;//�x�񂾔n�̔z�������オ��
	}
	if (Fatigue < FATIGUE_MIN)
		Fatigue = FATIGUE_MIN;
	if (Fatigue > FATIGUE_MAX)
		Fatigue = FATIGUE_MAX;
	return *this;
}

std::string Horse::BackName() {
	return Name;
}