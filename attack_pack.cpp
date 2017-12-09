#include "attack_pack.h"


AttackPack::AttackPack()
:packLen(0)
{}

AttackPack::AttackPack(const int theSize)
:packLen(theSize)
{}

AttackPack::~AttackPack()
{
    for (int i=0; i<attackSize; i++)
        delete (packs[i]);
    delete(packs);
}

AttackPack::AttackPack(const AttackPack &rhs)
:packLen(rhs.getPackLen()),attackSize(rhs.getAttackSize()),packs(new Pack*[attackSize])
{
    for (int i=0; i<attackSize; i++)
        *packs[i] = rhs.getPack(i);
}

int AttackPack::getPackLen() const
{
    return packLen;
}
void AttackPack::setPackLen(const int theLen)
{
    packLen = theLen;
}
bool AttackPack::setPacks(ifstream &f)
{
    if (!f.is_open())   //if file doesn't exist
        return false;
    
    char cur;
    
    f >> attackSize;
    f.get(cur);
    //if statement checks wether attack size is valid
    if (attackSize < Sizes::MIN_ATTACK_SIZE || attackSize > Sizes::MAX_ATTACK_SIZE)
        return false;
    
    packs = new Pack*[attackSize];
    
    for (int i=0; i<attackSize; i++)    //allocate memory for packs
        packs[i] = new Pack(packLen);
    
    for (int i=0; i<attackSize; i++)
    {
        for (int j=0; j<packLen*2; j++) //each row in file contains packLen*2 chars
        {
            f.get(cur);
            if (j==packLen*2-1) //last char at row must be '\n'
            {
                if (cur != '\n')
                    return false;
            }
            else if (!isEven(j))    //chars in odd spots must be ' '
            {
                if (cur != ' ')
                    return false;
            }
            else
            {
                if (!isBinary(cur-'0')) //chars in even spots must be numbers {0,1}
                    return false;
                packs[i]->operator[](j/2) = cur-'0';
            }
        }
    }
    return true;
}

bool AttackPack::isEven(const int n)
{
    return n%2==0 ? true : false; 
}


void AttackPack::print() const
{
    for (int i=0; i<attackSize; i++)
        packs[i]->print();
}

bool AttackPack::isBinary(const int value)
{
    if (value == 0 || value == 1)
        return true;
    return false;
}


Pack& AttackPack::getPack(const int i) const
{
    return *packs[i];
}

int AttackPack::getAttackSize() const
{
    return attackSize;
}


