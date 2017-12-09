#include "defence_pack.h"


DefencePack::DefencePack(){}

DefencePack::DefencePack(const int theSize, const int theLen)
:defenceSize(theSize),packLen(theLen), packs(new DPack*[theSize])
{
    
    for (int i=0; i<defenceSize; i++)
        packs[i] = new DPack(packLen);
        
}
DefencePack::DefencePack(const DefencePack &rhs)
:defenceSize(rhs.getDefenceSize()),packLen(rhs.getPackLen()), packs(new DPack*[defenceSize])
{
    for (int i=0; i<defenceSize; i++)
        *packs[i] = rhs.getPack(i);
}

DefencePack::~DefencePack()
{
    for (int i=0; i<defenceSize; i++)
        delete (packs[i]);
    delete(packs);
}

bool DefencePack::setPackLen(const int theLen)
{
    packLen = theLen;
    if (packLen < Sizes::MIN_PACK_LEN || packLen > Sizes::MAX_PACK_LEN)
        return false;
    return true;
}

bool DefencePack::setDefenceSize(const int theSize)
{
    defenceSize = theSize;
    
    if (defenceSize < Sizes::MIN_DEFENCE_SIZE || defenceSize > Sizes::MAX_DEFENCE_SIZE)
        return false;
    
    packs = new DPack*[defenceSize];
    
    for (int i=0; i<defenceSize; i++)
        packs[i] = new DPack(packLen);
    
    return true;
}


void DefencePack::print() const
{
    for (int i=0; i<defenceSize; i++)
        packs[i]->print();

}

void DefencePack::fillWithRandom() const
{
    srand(time(NULL));
    
    for (int i=0; i<defenceSize; i++)
        for(int j=0; j<packLen; j++)
            packs[i]->operator[](j) = rand()%2;
}

DPack &DefencePack::getPack(const int i) const
{
    return *packs[i];
}

int DefencePack:: getDefenceSize() const
{
    return defenceSize;
}

void DefencePack::printPowersOfAllPacks() const
{
    for (int i=0; i<defenceSize; i++)
        cout << "the power of pack " << i << " is " << packs[i]->getPower() << endl;
}

int DefencePack::strongestPack() const
{
    int maxPower = 0;
    int curPower;
    
    for (int i=0; i<defenceSize; i++)
    {
        curPower = packs[i]->getPower();
        if (curPower > maxPower)
            maxPower = curPower;
    }
    return maxPower;
}

void DefencePack::orginizeByPower()
{
    for (int i=defenceSize-1; i>0; i--)
        for (int j=0; j<i; j++)
            if (*packs[j] < *packs[j+1])
                swapPacks(j,j+1);
}

void DefencePack::swapPacks(const int i, const int j)
{
    DPack *temp;
    
    temp = packs[i];
    packs[i] = packs[j];
    packs[j] = temp;
}

void DefencePack::updatePacks()
{
    for (int i=0; i<defenceSize/2; i++)
        (*packs[i])%(*packs[rand()%defenceSize]);
}

int DefencePack::getPackLen() const
{
    return packLen;
}
