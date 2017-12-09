#ifndef _DPACK_H
#define _DPACK_H
#include "pack.h"
#include <cstdlib>
#include <ctime>

/*   this class is for packs used by defence group.
     DPack differs from Pack by having a power field as well*/
class DPack : public Pack
{
public:
    DPack(const int theSize);   //c'tor
    ~DPack();                   //d'tor
    DPack(const DPack &rhs);    //copy c'tor
    int getPower() const;       //return power 
    void setPower(const int thePower);  //sets power
    bool operator>(const DPack &rhs);   //returns true if power is bigger than rhs's power. false otherwise
    bool operator<(const DPack &rhs); //returns true if pwoer is smaller than rhs's power. false otherwise
    void operator%(DPack &rhs); //swaps all values within two random indexs between rhs, and "this" 
private:
    int power;  //number wich represents packs strength 
};

#endif
