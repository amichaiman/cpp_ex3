#include "Dpack.h"


DPack::DPack(const int theSize)
:Pack(theSize),power(0)
{}

DPack::~DPack(){}

DPack::DPack(const DPack &rhs)
:Pack(rhs), power(rhs.getPower())
{}

int DPack::getPower() const 
{
    return power;
}
void DPack::setPower(const int thePower)
{
    power = thePower;    
}

bool DPack::operator>(const DPack &rhs)
{
    return power > rhs.getPower();
}

bool DPack::operator<(const DPack &rhs)
{
    return power < rhs.getPower();
}
void DPack::operator%(DPack &rhs)
{
    int firstCut = rand()%getSize();    //firstCut gets random index between packs range
    int secondCut = rand()%getSize();   //secondCut gets random index between packs range
    int temp;   //used for swap
    
    while (firstCut == secondCut)   //make sure indexs are different
        secondCut = rand()%getSize();
    
    if (secondCut < firstCut) //make sure fistCut is the smaller index
    {
        temp = firstCut;
        firstCut = secondCut;
        secondCut = temp;
    }
    
    for (int i=firstCut; i<=secondCut; i++)
    {
        temp = operator[](i);
        operator[](i) = rhs[i];
        rhs[i] = temp;
    }
}
