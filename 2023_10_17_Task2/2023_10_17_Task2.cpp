#include <iostream>
#include <cstdlib>
#include <cstring>
using namespace std;


const int MAX_NAME = 16;

class Hero {
public :
    Hero(char *pName);
    ~Hero();

public:
    int GetStatus(char *name, int hp, int attack, int deffence) {
        name = name_array;
        hp = StatusHp;
        attack = statusAttack;
        deffence = statusDiffence;
    };
    void SetHp(int hp) { StatusHp = hp; };
    void Show();

private :
    char* name_array;
    int name_size;

private :
    int StatusHp = 0;
    int statusAttack = 40;
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

// デストラクタ
Hero::~Hero() {
    delete[] name_array;
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
    int GetStatus(char* name, int hp, int attack, int deffence) {
        name = name_array;
        hp = StatusHp;
        attack = statusAttack;
        deffence = statusDiffence;
    };
    void SetHp(int hp) { StatusHp = hp; };
    void Show();

private:
    char* name_array;
    int name_size;

private:
    int StatusHp = 0;
    int statusAttack = 20;
    int statusDiffence = 40;
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

// デストラクタ
Enemy::~Enemy() {
    delete[] name_array;
}

void Enemy::Show() {
    printf("名前：%s\n", name_array);
    printf("体力：%d\n", StatusHp);
    printf("攻撃力：%d, ", statusAttack);
    printf("防御力：%d\n", statusDiffence);
}

void InputHeroStatus() {
    char name[MAX_NAME]{""};
    int hp = 0;

    printf("ヒーロー名を入力\n> ");
    cin >> name;
    Hero hero(&name[0]);

    printf("HPを入力\n> ");
    cin >> hp;
    hero.SetHp(hp);

    hero.Show();
}

void InputEnemyStatus() {
    char name[MAX_NAME]{ "" };
    int hp = 0;

    printf("エネミー名を入力\n> ");
    cin >> name;
    Enemy enemy(&name[0]);

    printf("HPを入力\n> ");
    cin >> hp;
    enemy.SetHp(hp);

    enemy.Show();
}

void attack(Hero *hero) {

}

void attack(Enemy *enemy) {

}

void heal() {

}

int main()
{
    InputHeroStatus();
    InputEnemyStatus();
    
    /*int select = 0;
    while (!0) {
        printf("攻撃 > 1\n回復 > 2");
        cin >> select;

        switch (select)
        {
        case 1:
            attack();
            break;
        default:
            break;
        }
    }*/
}