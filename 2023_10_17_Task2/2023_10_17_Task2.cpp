#include <iostream>
#include <cstdlib>
#include <cstring>
using namespace std;

class Enemy;

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

Hero InputHeroStatus() {
    char name[MAX_NAME]{ "" };
    int hp = 0;

    printf("ヒーロー名を入力\n> ");
    cin >> name;
    Hero hero(&name[0]);

    printf("HPを入力\n> ");
    cin >> hp;
    hero.SetHp(hp);

    hero.Show();

    return hero;
}

Enemy InputEnemyStatus() {
    char name[MAX_NAME]{ "" };
    int hp = 0;

    printf("エネミー名を入力\n> ");
    cin >> name;
    Enemy enemy(&name[0]);

    printf("HPを入力\n> ");
    cin >> hp;
    enemy.SetHp(hp);

    enemy.Show();

    return enemy;
}

void Hero::attack(Enemy* enemy) {
    int deffence = enemy->GetDiffence();
    int damage = 0;
    damage = statusAttack - deffence;
    printf("%sの攻撃！\n%dのダメージを与えた\n", name_array, damage);

    int hp = enemy->GetHp(damage);
    printf("相手の残りHP : %d\n", hp);
}

void Enemy::attack(Hero* hero) {
    int deffence = hero->GetDiffence();
    int damage = 0;
    damage = statusAttack - deffence;
    printf("%sの攻撃！\n%dのダメージを与えた\n", name_array, damage);

    int hp = hero->GetHp(damage);
    printf("相手の残りHP : %d\n", hp);
}

void Hero::heal() {
    int healHp = 0;
    printf("どのくらい回復しますか\n> ");
    cin >> healHp;
    printf("%sの残りHP : %d\n", name_array, GetHp(0, healHp));
}

void Enemy::heal() {
    int healHp = 0;
    printf("どのくらい回復しますか\n> ");
    cin >> healHp;
    printf("%sの残りHP : %d\n", name_array, GetHp(0, healHp));
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