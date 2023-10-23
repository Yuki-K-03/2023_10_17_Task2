#include <iostream>
#include <cstdlib>
#include <cstring>
using namespace std;


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
    while () {

    }
}