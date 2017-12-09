#include "pack.h"
Pack::Pack(const int theSize)
:size(theSize),bin(new int[theSize])
{}

Pack::~Pack()
{
    delete(bin);
}

Pack::Pack(const Pack &rhs)
:size(rhs.getSize()),bin(new int[size])
{
    for (int i=0; i<size; i++)
        bin[i] = rhs[i];
}

int Pack::getSize() const
{
    return size;
}

int& Pack::operator[](const int index) const
{
    return bin[index];
}




void Pack::print() const
{
    for (int i=0; i<size; i++)
        cout << bin[i] << " ";
    cout << endl;
}
