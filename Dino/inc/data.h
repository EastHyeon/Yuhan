// ��������
#define GAME_VERSION "������ v0.1 | 202327005 �赿��" 
#define WAIT_TICK 1000 / 30
#define SCRREN_MIN_X 2
#define SCREEN_MIN_Y 1
#define SCREEN_MAX_Y 30

//ȭ�� ������ ���� enum
enum GameState{
    EXIT = 0,
    MENU,
    GAME,
    HELP,
};

// Ű
#define KEY_UP 0x26
#define KEY_DOWN 0x28
#define KEY_SPACE 0x20
#define KEY_Y 0x59
#define KEY_N 0x4E
#define INPUT_SENSITIVITY 100 // �Է� ����

//�ؽ�Ʈ �� ��� ���� ������ ���� enum
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
