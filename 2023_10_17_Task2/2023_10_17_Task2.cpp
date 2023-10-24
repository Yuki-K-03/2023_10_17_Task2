#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstdlib>
#include <cstring>
using namespace std;

class Enemy; // 前方宣言

const int MAX_NAME = 16;

class Hero {
public :
    Hero(char *pName);
    ~Hero();

public:
    int GetDiffence() {
        return statusDiffence;
    };
    int GetHp(int damage = 0, int healHp = 0) {
        StatusHp -= damage;
        StatusHp += healHp;
        return StatusHp;
    }
    void SetHp(int hp) { StatusHp = hp; };
    void Show();

public :
    Hero(char* pName, int hp);
    int getHp() {
        return StatusHp;
    }
    void setHp(int hp) {
        StatusHp = hp;
    }

public :
    void attack(Enemy* enemy);
    void heal();

private :
    char* name_array;
    int name_size;

private :
    int StatusHp = 0;
    int statusAttack = 75;
    int statusDiffence = 20;
};

// コンストラクタ
Hero::Hero(char *pName) {
    int size = 0;
    for (int i = 0; pName[i] != '\0'; i++) {
        size++;
    }
    size++;
    name_array = new char[size];
    name_size = size;
    for (int i = 0; i < size; i++) {
        name_array[i] = pName[i];
    }
}

Hero::Hero(char* pName, int hp) {
    name_size = strlen(pName) + 1;
    name_array = new char[name_size];
    strcpy(name_array, pName);

    StatusHp = hp;
    statusAttack = 75;
    statusDiffence = 20;
}

// デストラクタ
Hero::~Hero() {
    if (name_array != NULL) {
        delete[] name_array;
        name_array = NULL;
    }
}

void Hero::Show() {
    printf("名前：%s\n", name_array);
    printf("体力：%d\n", StatusHp);
    printf("攻撃力：%d, ", statusAttack);
    printf("防御力：%d\n", statusDiffence);
}


class Enemy {
public:
    Enemy(char* pName);
    ~Enemy();

public:
    int GetDiffence() {
        return statusDiffence;
    };
    int GetHp(int damage = 0, int healHp = 0) {
        StatusHp -= damage;
        StatusHp += healHp;
        return StatusHp;
    }
    void SetHp(int hp) { StatusHp = hp; };
    void Show();

public:
    Enemy(char* pName, int hp);
    int getHp() {
        return StatusHp;
    }
    void setHp(int hp) {
        StatusHp = hp;
    }

public:
    void attack(Hero* hero);
    void heal();

private:
    char* name_array;
    int name_size;

private:
    int StatusHp = 0;
    int statusAttack = 50;
    int statusDiffence = 30;
};

// コンストラクタ
Enemy::Enemy(char* pName) {
    int size = 0;
    for (int i = 0; pName[i] != '\0'; i++) {
        size++;
    }
    size++;
    name_array = new char[size];
    name_size = size;
    for (int i = 0; i < size; i++) {
        name_array[i] = pName[i];
    }
}

Enemy::Enemy(char* pName, int hp) {
    name_size = strlen(pName) + 1;
    name_array = new char[name_size];
    strcpy(name_array, pName);

    StatusHp = hp;
    statusAttack = 75;
    statusDiffence = 20;
}

// デストラクタ
Enemy::~Enemy() {
    if (name_array != NULL) {
        delete[] name_array;
        name_array = NULL;
    }
}

void Enemy::Show() {
    printf("名前：%s\n", name_array);
    printf("体力：%d\n", StatusHp);
    printf("攻撃力：%d, ", statusAttack);
    printf("防御力：%d\n", statusDiffence);
}

Hero InputHeroStatus() {
    char name[MAX_NAME]{ "" };
    int hp = 0;

    printf("ヒーロー名を入力\n> ");
    cin >> name;

    printf("HPを入力\n> ");
    cin >> hp;

    Hero hero(&name[0], hp);
    hero.Show();

    return hero;
}

Enemy InputEnemyStatus() {
    char name[MAX_NAME]{ "" };
    int hp = 0;

    printf("エネミー名を入力\n> ");
    cin >> name;

    printf("HPを入力\n> ");
    cin >> hp;

    Enemy enemy(&name[0], hp);

    enemy.Show();

    return enemy;
}

void Hero::attack(Enemy* enemy) {
    int deffence = enemy->GetDiffence();
    int damage = 0;
    damage = statusAttack - deffence;
    printf("%sの攻撃！\n%dのダメージを与えた\n", name_array, damage);

    int hp = enemy->getHp();
    enemy->setHp(hp - damage);
    printf("相手の残りHP : %d\n", enemy->getHp());
}

void Enemy::attack(Hero* hero) {
    int deffence = hero->GetDiffence();
    int damage = 0;
    damage = statusAttack - deffence;
    printf("%sの攻撃！\n%dのダメージを与えた\n", name_array, damage);

    int hp = hero->getHp();
    hero->setHp(hp - damage);
    printf("相手の残りHP : %d\n", hero->getHp());
}

void Hero::heal() {
    int healHp = 0;
    printf("どのくらい回復しますか\n> ");
    cin >> healHp;

    StatusHp += healHp;
    printf("%sの残りHP : %d\n", name_array, StatusHp);
}

void Enemy::heal() {
    int healHp = 0;
    printf("どのくらい回復しますか\n> ");
    cin >> healHp;

    StatusHp += healHp;
    printf("%sの残りHP : %d\n", name_array, StatusHp);
}

int main()
{
    bool turn = false;
    Hero hero = InputHeroStatus();
    Enemy enemy = InputEnemyStatus();
    
    int select = 0;
    while (!0) {

        turn = true;
        while (turn) {
            printf("ヒーロー >> 攻撃 : 1, 回復 : 2, ステータス確認 : 3\n> ");
            cin >> select;
            switch (select)
            {
            case 1:
                hero.attack(&enemy);
                turn = false;
                break;
            case 2:
                hero.heal();
                turn = false;
                break;
            case 3:
                hero.Show();
                break;
            default:
                break;
            }
        }
        printf("\n----------ターンチェンジ----------\n\n");
        if (enemy.GetHp() <= 0) { break; }

        turn = true;

        while (turn) {
            printf("エネミー >> 攻撃 : 1, 回復 : 2, ステータス確認 : 3\n> ");
            cin >> select;
            switch (select)
            {
            case 1:
                enemy.attack(&hero);
                turn = false;
                break;
            case 2:
                enemy.heal();
                turn = false;
                break;
            case 3:
                enemy.Show();
                break;
            default:
                break;
            }
        }
        printf("\n----------ターンチェンジ----------\n\n");
        if (hero.GetHp() <= 0) { break; }
    }
}