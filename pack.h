#ifndef _PACK_H
#define _PACK_H
/*   this class is a vector of 1 or 0 only   */
#include <iostream>

using namespace std;

class Pack
{
public:
    Pack(const int TheSize); //c'tor
    Pack(const Pack &rhs); //copy c'tor
    ~Pack();                //d'tor
    int getSize() const;        //returns size of pack
    int& operator[](const int index) const; //returns index in bin
    void print() const;     //prints bin to standard input stream
private:
    int size;       //size of pack
    int *bin;       //holds 'size' amount of binary numbers

};


#endif
