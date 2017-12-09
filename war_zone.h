#ifndef _WAR_ZONE_H
#define _WAR_ZONE_H

#include "pack.h"
#include "Dpack.h"
#include "attack_pack.h"
#include "defence_pack.h"

#include <iostream>     //just for debugging
using namespace std;       //just for debugging

class WarZone
{
public:
    WarZone(); //c'tor
    ~WarZone(); //d'tor
    WarZone(const WarZone &rhs); //copy c'tor
    int checkPower(const Pack &offence, const DPack &defence) const; //returns number of matching values between the two packs
    void findMaxPower(const AttackPack &attackPack, DPack &p); //finds wich of the packs in the attack group has most matching values with given defence pack
    void checkDefencePower(const AttackPack &attackPack, DefencePack &defencePack); //checks each one of the packs in the defence group against all packs in attack group, and sets their power accordingly
private:
    
};
#endif
