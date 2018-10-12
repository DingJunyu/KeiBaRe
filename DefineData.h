#pragma once

//�n�̐���TRACK��
#define NAME_NUMBER 32
#define HORSE_NUMBER_PER_MATCH 16

//TRACK�̒���
#define TRACK_LONG 3000
#define TRACK_MEDIUM 1500
#define TRACK_SHORT 500

//�n��Ԋ֘A
#define CHAN_SPEED 1
#define CHAN_WEIGHT 50
#define CHAN_STATUS 10
#define CHAN_LEVEL 5
#define STATUS_PER_LEVEL 2
#define SPEED_PER_LEVEL 1
#define WEIGHT_CHAN_PER_LEVEL 10
#define INIF_MAXLEVEL 25
#define FATIGUE_PER_MATCH 5
#define FATIGUE_PER_REST 5
#define STATUS_UP_LOSE 1
#define STATUS_DOWN_WIN 5
#define STATUS_PER_REST 1
#define ODDS_PER_WIN 0.15
#define ODDS_PER_LOSE 0.05
#define ODDS_PER_MATCH 0.02
#define ODDS_PER_REST 0.01	

//�������f�[�^
#define INIF_SPEED 12
#define INIF_WEIGHT 250
#define INIF_STATUS 60
#define INIF_FATIGUE 10

//�������f�[�^
#define STANDARD_STATUS 60
#define WEIGHT_TO_FST 0.25
#define WEIGHT_TO_ACC 0.02
#define STATUS_TO_FST 0.1
#define STATUS_TO_ACC 0.03
#define SPEED_DOWN_WITH_FATIGUE 2//��J�l�����܂�ƃX�s�[�h�������_�����Ƃ�
#define SPEED_DOWN_WITH_FST 0.6
#define SPEED_MIN 8//��Ԓx�����x�Ƒ��x�̍�
#define LENGTH_SHOW 61//Track�̒���
#define INIF_ACCELERATION 2
#define INIF_FST 120//�S���ő厞��
#define ACC_MIN 1//�ŏ������x
#define FST_MIN 5

//�I����������
#define SPEED 1
#define STATUS 2
#define FATIGUE 3
#define WEIGHT 4
#define ODDS 5

#define FRAME_WAIT 20

//��Փx�֘A
#define DIFFICULTY_DIFFICULT 2000
#define DIFFICULTY_NORMAL 4000
#define DIFFICULTY_EASY 10000
#define LOWEST_BET_MOUNT_EASY 200
#define LOWEST_BET_MOUNT_NORMAL 400
#define LOWEST_BET_MOUNT_HARD 800