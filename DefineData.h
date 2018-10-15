#pragma once

//�n�̐���TRACK��
#define NAME_NUMBER 32
#define HORSE_NUMBER_PER_MATCH 16

//TRACK�̒���
#define TRACK_LONG 3000
#define TRACK_MEDIUM 1500
#define TRACK_SHORT 500

//�n��Ԋ֘A
//�����l
#define INIF_SPEED 12
#define INIF_WEIGHT 250
#define INIF_STATUS 60
#define INIF_FATIGUE 10//������J�l
#define INIF_MAXLEVEL 25
#define INIF_ODDS 1
#define INIF_LEVEL 1
//������
#define CHAN_SPEED 1 //���x
#define CHAN_WEIGHT 50 //�d��
#define CHAN_STATUS 10 //�e���V����
#define CHAN_LEVEL 5 //�ő僌�[�x��

//���[�x���A�b�v�ɂ��X�e�[�^�X�̕ϓ�
#define STATUS_PER_LEVEL 2//�e���V����
#define SPEED_PER_LEVEL 1//���x
#define WEIGHT_CHAN_PER_LEVEL 10//�d��

//��J�l�֌W
#define FATIGUE_PER_MATCH 10//�Q���ɂ�鉺����
#define FATIGUE_PER_REST 15//�Q�����Ȃ��ɂ��オ��
#define FATIGUE_MAX 100//�ő�l
#define FATIGUE_MIN 0//�ŏ��l

//�e���V�����֌W
#define STANDARD_STATUS 60//�W���l
#define STATUS_UP_LOSE 2//���s���̕ω�
#define STATUS_DOWN_WIN 8//�������̕ω�
#define STATUS_PER_REST 1//�Q�����Ȃ���
#define STATUS_MAX 130//�ő�l
#define STATUS_MIN 0//�ŏ��l

//�z����
#define ODDS_PER_WIN 0.25
#define ODDS_PER_LOSE 0.05
#define ODDS_PER_MATCH 0.02
#define ODDS_PER_REST 0.01	
#define ODDS_MIN 0.1

//Runway�̏����l
#define INIF_ACCELERATION 2
#define INIF_FST 120//�S���ő厞��

//�������f�[�^
#define WEIGHT_TO_FST 0.25
#define WEIGHT_TO_ACC 0.05
#define STATUS_TO_FST 0.2
#define STATUS_TO_ACC 0.03
#define SPEED_DOWN_WITH_FATIGUE 3//��J�l�����܂�ƃX�s�[�h�������_�����Ƃ�
#define SPEED_DOWN_WITH_FST 0.6
#define SPEED_MIN 8//��Ԓx�����x�Ƒ��x�̍�
#define ACC_MIN 1//�ŏ������x
#define FST_MIN 60//�ŏ��S���ő厞��

//�I����������
#define SPEED 1
#define STATUS 2
#define FATIGUE 3
#define WEIGHT 4
#define ODDS 5

//�A�o�֌W
#define FRAME_WAIT 20
#define LENGTH_SHOW 61//Track�̒���

//��Փx�֘A
#define DIFFICULTY_DIFFICULT 2000
#define DIFFICULTY_NORMAL 4000
#define DIFFICULTY_EASY 10000
#define LOWEST_BET_MOUNT_EASY 200
#define LOWEST_BET_MOUNT_NORMAL 400
#define LOWEST_BET_MOUNT_HARD 800