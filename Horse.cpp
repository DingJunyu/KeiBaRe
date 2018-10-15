#include"stdafx.h"

Horse& Horse::Initiaize(std::string GivenName) {//馬のデータを初期化
	//define値通り渡す
	Speed = INIF_SPEED;
	Weight = INIF_WEIGHT;
	Status = INIF_STATUS;
	MaxLevel = INIF_MAXLEVEL;
	Level = INIF_LEVEL;
	Fatigue = INIF_FATIGUE;
	Odds = INIF_ODDS;

	Name = GivenName;//渡された文字列を保存
	/*初期データ全部ランダムに変わる*/
	Speed += Random(CHAN_SPEED);
	Weight += Random(CHAN_WEIGHT);
	Status += Random(CHAN_STATUS);
	MaxLevel += Random(CHAN_LEVEL);

	return *this;
}

Horse& Horse::LevelUp() {
	++Level;
	Speed += SPEED_PER_LEVEL;//スピードは上がる
	Weight += Random(WEIGHT_CHAN_PER_LEVEL);
	//重量はランダムに変わる(下がることがある)
	Status += STATUS_PER_LEVEL;//テンションは上がる
	return *this;
}

Horse& Horse::Record(bool Win) {
	if (Win) {//勝場合
		++Winned;
		Status -= STATUS_DOWN_WIN;//テンションが下がる
		if (Status < STATUS_MIN)//最小値を超えないよう
			Status = STATUS_MIN;
		Odds -= ODDS_PER_WIN;//配当率が下がる
		if (Odds < ODDS_MIN)//最小値を超えないよう
			Odds = ODDS_MIN;
	}
	else {//負けた場合
		Status += STATUS_UP_LOSE;//テンションが上がる
		if (Status > STATUS_MAX)//最大値を超えないよう
			Status = STATUS_MAX;
		Odds += ODDS_PER_LOSE;//配当率が上がる
	}
	++Played;
	if (Played > Level * 5 && Level <= MaxLevel)//５回毎にレーベルが上がる
		LevelUp();
	return *this;
}

double& Horse::Query(int Num) {//トラックにデータを渡す用
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
	int RandomMark;//正数と負数の判定
	RandomMark = rand() % 2;
	if (RandomMark == 1)//正数を返す
		return (double)(((rand() % (Range*100)))/100);
	else//負数を返す
		return 0 - (double)(((rand() % (Range * 100))) / 100);
}

void Horse::Display() {
	std::cout << Name << " 体重:"
		<< Weight << "Kg テンション:"
		<< Status - INIF_STATUS << "% "
		<< "配当率:" << Odds;

	HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_SCREEN_BUFFER_INFO bInfo;
	GetConsoleScreenBufferInfo(hOut, &bInfo);
	COORD pos;
	pos = bInfo.dwCursorPosition;
	pos.X = LENGTH_SHOW + 3 + 3;
	//中の３は漢字一文字の位置、後ろのは最初の３文字
	SetConsoleCursorPosition(hOut, pos);

	std::cout << "|0" << std::endl;
}

Horse& Horse::rest(bool Played) {
	if (!Played) {
		Fatigue += FATIGUE_PER_MATCH;
		Odds += ODDS_PER_MATCH;//試合ことによって配当率が変わる
	}
	else {
		Fatigue -= FATIGUE_PER_REST;
		Odds += ODDS_PER_REST;//休んだ馬の配当率が上がる
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