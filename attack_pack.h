#ifndef _ATTACK_PACK_H
#define _ATTACK_PACK_H

/*    this class is the group of packs that belong to the 'attack' group    */

#include <fstream>

#include "sizes.h"
#include "pack.h"


class AttackPack
{
public:
    AttackPack();   //c'tor
    AttackPack(const int theSize);  //c'tor
    AttackPack(const AttackPack &rhs);  //copy c'tor
    ~AttackPack();                      //d'tor
    void setPackLen(const int theLen);  //sets packs 'packLen' to theLen
    bool setPacks(ifstream &f);         //extracts pack information from 'f' file. returns true if information was as ecpected. false otherwise.
    Pack& getPack(const int i) const;   //returns pack at spot i in group
    void print() const;                 //prints group to standard output
    int getAttackSize() const;          //returns 'attackSize'
    int getPackLen() const ;            //returns 'packLen'
private:
    int packLen;            // length of eack pack in attack group
    int attackSize;         // number of packs in group
    Pack **packs;           // the packs
    bool isEven(const int n);       //returns true if n is even. false otherwise.
    bool isBinary(const int value); //returns true if value is 0,1. false otherwise
};


#endif
