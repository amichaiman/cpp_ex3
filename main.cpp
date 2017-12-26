#include <iostream>
#include <fstream>

#include "pack.h"
#include "defence_pack.h"
#include "attack_pack.h"
#include "war_zone.h"
#include "sizes.h"

using namespace std;


int main( int argv,char **argc)
{
    AttackPack ap;          //attack packs
    DefencePack dp;         //defence packs
    WarZone war;            //where interactions between packs take place
    ifstream config;        //config.dat file
    ifstream offence;       //offence.dat file
    int packLen;            //one pack's length as given in 'config.dat'
    int defenceSize;        //number of packs in defence as given in 'config.dat'
    int timeCycles;         //number of cycles as given in 'config.dat'
    
    if (argv < 3)           //if not enough arguments given by user
    {
        cout << "ERROR: Invalid input.";
        exit(1);
    }
    
    config.open(argc[1]);       //open file config.dat
    
    if (!config.is_open())  //if file does not exist
    {
        cout << "ERROR: Invalid input.";
        exit(1);
    }
    
    config >> packLen;
    config >> defenceSize;
    config >> timeCycles;
    
    
    //if statement sets defence's number of packs and pack length
    //if one or more of the arguments given in 'config.dat' is invalid, program terminates
    if (!dp.setPackLen(packLen) || !dp.setDefenceSize(defenceSize) || timeCycles < Sizes::MIN_CYCLES || timeCycles > Sizes::MAX_CYCLES)
    {
        cout << "ERROR: Invalid input.";
        exit(1);
    }
    
    offence.open(argc[2]); //open file 'offence.dat'
    
    ap.setPackLen(packLen);
    
    //if statement extracts information from 'offence.dat'. 
    //if data in 'offence.dat' isn't as required program terminates
    if (!ap.setPacks(offence)) 
    {
        cout << "ERROR: Invalid input.";
        exit(1);
    }
    
    dp.fillWithRandom();    //defence initializes with random {0,1}^packLen values

    war.checkDefencePower(ap,dp);   //each of the defence packs in dp is checked against all other packs in ap and sets its power accordingly
    
    int i;
    for(i=0; i<timeCycles && dp.strongestPack() != packLen; i++)
    {
        dp.orginizeByPower();   //packs are reorders according to power value       
        dp.updatePacks();        
        war.checkDefencePower(ap,dp);
    }
    cout << i << endl; //number of cycles
    dp.orginizeByPower();   
    dp.print();
    return 0;
}
