#ifndef _ATTACK_PACK_H
#define _ATTACK_PACK_H

#include <fstream>
#include "sizes.h"
#include "pack.h"
#include <iostream>

using namespace std;


class AttackPack
{
public:
    AttackPack();
    AttackPack(const int theSize);
    AttackPack(const AttackPack &rhs);
    ~AttackPack();
    void setPackLen(const int theLen);
    bool setPacks(ifstream &f);
    Pack& getPack(const int i) const;
    void print() const;
    int getAttackSize() const;
    int getPackLen() const ;
private:
    int packLen;
    int attackSize;
    Pack **packs;
    bool isEven(const int n);
    bool isBinary(const int value);
};


#endif
