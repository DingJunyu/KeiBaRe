#include"stdafx.h"

void Player::InputBet() {
	int Num, Mount;

	while (1) {
		std::cout << "�q�������n�̔ԍ��Ɠq������z����͂��Ă��������B" << 
			"(�Œ�q������z�F"<< LowestBetMount << ")" << std::endl;
		std::cout << "�������܎����Ă邨��:" << Money << std::endl;
		std::cin >> Num >> Mount;
		rewind(stdin);
		if ((Num > 0 && Num <= HORSE_NUMBER_PER_MATCH) &&
			(Mount >= LowestBetMount && Mount <= Money)) {
			Bet(Num, Mount);//���������e������ƃf�[�^�ɏ�������
			break;
		}
		else
			std::cout << "���������e����͂��Ă��������B" << std::endl;
	}
}


Player& Player::Bet(int Num, int Mount) {
	Choice = Num - 1;//�n�̔ԍ��ƑI�񂾔ԍ��𓝈ꂷ�邽��
	BetNum = Mount;

	return *this;
}

Player& Player::Contrast(int WinNum,double Odds) {
	if (Choice == WinNum) {
		Money += int(BetNum * (Odds + 1));//���ꍇ�͔z�����ɂ��܋������
		std::cout << "�����܂����B" << BetNum * (Odds + 1) <<
			"�𓾂܂���" << std::endl;
	}
	else {
		Money -= BetNum;
		std::cout << "�����܂����B" << BetNum <<
			"���Ȃ����܂���" << std::endl;
	}
	std::cout << "�c�邨��:" << Money << std::endl;
	getchar();
	return *this;
}

bool GameOver() {
	int Ans;
	std::cout << "GAME OVER" << std::endl;
	std::cout << "���������܂���?(Y:0)" << std::endl;
	std::cin >> Ans;
	rewind(stdin);
	if(Ans!=0)
		exit(1);
	return true;
}

Player& Player::StartGame() {
	int Choose;
	std::cout << "�Q�[���̓�Փx��I��ł�������" << std::endl;
	std::cout << "1.Easy" << std::endl;
	std::cout << "2.Normal" << std::endl;
	std::cout << "3.Hard" << std::endl;
	std::cin >> Choose;
	rewind(stdin);
	while (Choose < 1 || Choose>3) {
		std::cout << "�������ԍ�����͂��Ă�������" << std::endl;
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
	std::cout << "�v���[���[�I�񂾔n��" << Choice + 1
		<< "�Ԃł�" << std::endl;
}