#include <iostream>
#include <cstdlib>
#include <cstring>
using namespace std;

enum _Attack {
    _AttackPlayer = -1,
    _AttacaEnemy = 1,
};

class Hero {
public :
    Hero(int size);
    ~Hero();

public:
    int Get(int i);
    void Set(int i, int value);

private:
    // インデックスのチェック
    void CheckIndex(int i);

private :
    int* name_array;
    int name_size;

private :
    int hp;
    int statusAttack;
    int statusDiffence;
};

// コンストラクタ
Hero::Hero(int size) {
    name_array = new int[size];
    name_size = size;
}

// デストラクタ
Hero::~Hero() {
    delete[] name_array;
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

void InputStatus() {

}

void attack() {

}

void heal() {

}

int main()
{
    int select = 0;
    while (!0) {
        printf("攻撃 > 1\n回復 > 2");
        cin >> select;

        switch (select)
        {
        default:
            break;
        }
    }
}