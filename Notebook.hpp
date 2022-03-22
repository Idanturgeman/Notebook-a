#pragma once
#include<iostream>
#include<string>
#include "Direction.hpp"
#include<stdexcept>


using namespace std;
using ariel::Direction;
using namespace ariel;
namespace ariel{

class Notebook
{
private:
    unsigned int _page;
    unsigned int _row;
    unsigned int _column;
    unsigned int _numChar;

public:

    void setPage(unsigned int page);
    void setRow(unsigned int row);
    void setCol(unsigned int col);
    void setNumChar(unsigned int numChar);

    unsigned int getPage();
    unsigned int getRow();
    unsigned int getCol();
    unsigned int getNumChar();

    void write(unsigned int page, unsigned int row, unsigned int col, Direction dir, string str);
    string read(unsigned int page, unsigned int row, unsigned int col, Direction dir, unsigned int numChar);
    void erase(unsigned int page, unsigned int row, unsigned int col, Direction dir, unsigned int numChar);
    void show(unsigned int page);
/*
    Notebook();
    ~Notebook();
    */
};
/*
Notebook::Notebook()
{
}

Notebook::~Notebook()
{
}
*/
}