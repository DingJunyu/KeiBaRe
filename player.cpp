#include"stdafx.h"

void Player::InputBet() {
	int Num, Mount;

	while (1) {
		std::cout << "賭けたい馬の番号と賭ける金額を入力してください。" << 
			"(最低賭ける金額："<< LowestBetMount << ")" << std::endl;
		std::cout << "ただいま持ってるお金:" << Money << std::endl;
		std::cin >> Num >> Mount;
		rewind(stdin);
		if ((Num > 0 && Num <= HORSE_NUMBER_PER_MATCH) &&
			(Mount >= LowestBetMount && Mount <= Money)) {
			Bet(Num, Mount);//正しい内容を入れるとデータに書き込む
			break;
		}
		else
			std::cout << "正しい内容を入力してください。" << std::endl;
	}
}


Player& Player::Bet(int Num, int Mount) {
	Choice = Num - 1;//馬の番号と選んだ番号を統一するため
	BetNum = Mount;

	return *this;
}

Player& Player::Contrast(int WinNum,double Odds) {
	if (Choice == WinNum) {
		Money += int(BetNum * (Odds + 1));//勝場合は配当率による賞金を取る
		std::cout << "勝ちました。" << BetNum * (Odds + 1) <<
			"を得ました" << std::endl;
	}
	else {
		Money -= BetNum;
		std::cout << "負けました。" << BetNum <<
			"がなくしました" << std::endl;
	}
	std::cout << "残るお金:" << Money << std::endl;
	getchar();
	return *this;
}

bool GameOver() {
	int Ans;
	std::cout << "GAME OVER" << std::endl;
	std::cout << "もう一回やりますか?(Y:0)" << std::endl;
	std::cin >> Ans;
	rewind(stdin);
	if(Ans!=0)
		exit(1);
	return true;
}

Player& Player::StartGame() {
	int Choose;
	std::cout << "ゲームの難易度を選んでください" << std::endl;
	std::cout << "1.Easy" << std::endl;
	std::cout << "2.Normal" << std::endl;
	std::cout << "3.Hard" << std::endl;
	std::cin >> Choose;
	rewind(stdin);
	while (Choose < 1 || Choose>3) {
		std::cout << "正しい番号を入力してください" << std::endl;
		std::cin >> Choose;
		rewind(stdin);
	}
	switch (Choose) {
	case 1:Money = DIFFICULTY_EASY;
		LowestBetMount=LOWEST_BET_MOUNT_EASY; break;
	case 2:Money = DIFFICULTY_NORMAL; 
		LowestBetMount=LOWEST_BET_MOUNT_NORMAL; break;
	case 3:Money = DIFFICULTY_DIFFICULT; 
		LowestBetMount= LOWEST_BET_MOUNT_HARD; break;
	}
	return *this;
}

bool Player::GameOverCheck() {
	if (Money < LowestBetMount)
		return GameOver();
	return false;
}

void Player::ShowChoice() {
	std::cout << "プレーヤー選んだ馬は" << Choice + 1
		<< "番です" << std::endl;
}