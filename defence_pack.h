#ifndef _DEFENCE_PACK_H
#define _DEFENCE_PACK_H

/*    this class is the group of packs that belong to the 'defence' group    */

#include "Dpack.h"
#include "sizes.h"
#include <cstdlib>
#include <ctime>

class DefencePack
{
public:
    DefencePack(const int theSize, const int theLen); //c'tor
    DefencePack();                                     //c'tor
    DefencePack(const DefencePack &rhs);                //copy c'tor
    ~DefencePack();                                     //d'tor
    bool setDefenceSize(const int theSize);  //sets number of packs in defence to theSize
    bool setPackLen(const int theLen);  //set's one pack's length to theLen
    DPack &getPack(const int i) const;  //returns pack reference to pack at index i
    void print() const;                 //prints packs to standrand output stream
    void fillWithRandom() const;        //fills all packs in defence group with random {0,1} values
    int getDefenceSize() const;         //returns number of packs in defence group
    int getPackLen() const;         //returns pack length 
    int strongestPack() const;      //returns power of strongest pack in group
    void orginizeByPower();         //packs are reordered according to power value
    void updatePacks();     //half of the packs(the ones with the higher power value) are paired with a random pack from group. then two indexs are randomly chosen and all values between two indexs are swaped respectively
private:
    int defenceSize;    //number of packs in defence
    int packLen;        //length of packs
    DPack **packs;      //group of packs

    bool isEven(int n);
    void swapPacks(const int i, const int j); //swaps spaces of two packs. used by 'orginizeByPower' function
};


#endif
