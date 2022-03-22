#include "Notebook.hpp"



    void Notebook::write(unsigned int page, unsigned int row, unsigned int col, Direction dir, string str){
        cout<<"aaaaaaa"<<endl;
    }
    string Notebook::read(unsigned int page, unsigned int row, unsigned int col, Direction dir, unsigned int numChar){
        return "bbbbbbb";
    }
    void Notebook::erase(unsigned int page, unsigned int row, unsigned int col, Direction dir, unsigned int numChar){
                cout<<"cccccccc"<<endl;

    }
    void Notebook::show(unsigned int page){
        cout<<"ddddddd"<<endl;
    }



    void setPage(unsigned int page);
    void setRow(unsigned int row);
    void setCol(unsigned int col);
    void setNumChar(unsigned int numChar);

    unsigned int getPage();
    unsigned int getRow();
    unsigned int getCol();
    unsigned int getNumChar();
