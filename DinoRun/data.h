// ��������
#define GAME_VERSION "������ v0.1 | 202327005 �赿��" 

// Ű
#define KEY_UP 0x26
#define KEY_DOWN 0x28
#define KEY_SPACE 0x20
#define KEY_Y 0x59
#define KEY_N 0x4E

#define INPUT_SENSITIVITY 100 // �Է� ����

//����
enum {
    BLACK,
    DARK_BLUE,
    DARK_GREEN,
    DARK_SKYBLUE,
    DARK_RED,
    DARK_VOILET,
    DAKR_YELLOW,
    GRAY,
    DARK_GRAY,
    BLUE,
    GREEN,
    CYAN,
    RED,
    VIOLET,
    YELLOW,
    WHITE,
    DEFAULT_BACKGROUND = 0,
    DEFAULT_TEXT = 7,
};

//��ũ��
#define SCREEN_MIN_LENGTH 2
#define SCREEN_MAX_LENGTH 90
#define SCREEN_WIDTH 87
#define WAIT_TICK 1000 / 30