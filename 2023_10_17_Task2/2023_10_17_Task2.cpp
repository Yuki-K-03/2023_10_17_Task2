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
    int Get(int i);
    void Set(int i, int value);
    void Show();

private:
    // インデックスのチェック
    void CheckIndex(int i);

private :
    char* name_array;
    int name_size;

private :
    int hp = 10;
    int statusAttack = 10;
    int statusDiffence = 10;
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
        printf("%c\n", name_array[i]);
    }
}

// デストラクタ
Hero::~Hero() {
    delete[] name_array;
}



void Hero::Show() {
    printf("名前：%s\n", name_array);
    printf("体力：%d\n", hp);
    printf("攻撃力：%d, ", statusAttack);
    printf("防御力：%d\n", statusDiffence);
}


class Enemy {
public:
    Enemy(int size);
    ~Enemy();

public:
    int Get(int i);
    void Set(int i, int value);

private:
    // インデックスのチェック
    void CheckIndex(int i);

private:
    int* name_array;
    int name_size;

private:
    int hp;
    int statusAttack;
    int statusDiffence;
};

void InputHeroStatus() {
    char name[MAX_NAME]{""};
    int hp = 0;

    printf("ヒーロー名を入力\n> ");
    cin >> name;
    printf("HPを入力\n> ");
    cin >> hp;

    Hero hero(&name[0]);
    hero.Show();
}

void attack() {

}

void heal() {

}

int main()
{
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