#include "war_zone.h"

WarZone::WarZone(){}
WarZone::~WarZone(){}
WarZone::WarZone(const WarZone &rhs){}

int WarZone::checkPower(const Pack &offence, const DPack &defence) const
{
    int power = 0;
    
    for (int i=0; i<offence.getSize();i++)
        if (offence[i] == defence[i])
            power++;
    return power;
}

void WarZone::findMaxPower(const AttackPack &attackPack, DPack &p)
{
    int cur_power;
    int max_power = 0;
    
    for (int i=0; i<attackPack.getAttackSize(); i++)
    {
        cur_power = checkPower(attackPack.getPack(i),p);
        if (cur_power > max_power)
            max_power = cur_power;
    }
    p.setPower(max_power);
}

void WarZone::checkDefencePower(const AttackPack &attackPack, DefencePack &defencePack)
{
    for(int i=0; i<defencePack.getDefenceSize(); i++)
        findMaxPower(attackPack,defencePack.getPack(i));
}