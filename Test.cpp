#include "Notebook.hpp"
#include "doctest.h"


ariel::Notebook note;

unsigned int randNum();

unsigned int numPage = randNum();
unsigned int maxRow = randNum();
unsigned int maxCol = randNum();


TEST_CASE("Bad notebook input"){
    note.write(numPage, maxRow, maxCol-4, Direction::Horizontal, "Maccabi");
    note.write(numPage+1, 0, 2, Direction::Horizontal, " Haifa");
    CHECK_THROWS(note.write(numPage, maxRow, maxCol-4, Direction::Horizontal, "Ronaldo"));
    CHECK_THROWS(note.write(numPage, maxRow, maxCol-6, Direction::Horizontal, "Messi"));
    CHECK_THROWS(note.write(numPage+1, 0, 3, Direction::Vertical, "Zinadin Zidan"));
    CHECK_THROWS(note.write(numPage, maxRow, 0, Direction::Vertical, "Patric Viera"));
    note.erase(numPage, maxRow-2, maxCol-3, Direction::Vertical, 5);
    CHECK_THROWS(note.write(numPage, maxRow, maxCol-4, Direction::Horizontal, "Diego Armando Maradona"));
    CHECK_THROWS(note.write(numPage, maxRow-4, maxCol-3, Direction::Horizontal, "Ronaldinio"));
    CHECK_THROWS(note.write(numPage, maxRow-3, maxCol-3, Direction::Vertical, "Gianluigi Buffon"));
    
}

TEST_CASE("Good notebook input"){
    CHECK(note.read(numPage, 5, 7, Direction::Horizontal, 5) == ("_____"));
    note.write(numPage, 8, 6, Direction::Horizontal, "Idan");
    CHECK(note.read(numPage, 8, 6, Direction::Horizontal, 4) == ("Idan"));
    CHECK(note.read(numPage, 5, 8, Direction::Vertical, 5) == ("___a_"));
    note.erase(numPage, maxRow-2, maxCol-3, Direction::Horizontal, 3);
    CHECK(note.read(numPage, maxRow-2, maxCol-5, Direction::Horizontal, 6) == ("__~~~_"));
    note.erase(numPage, 8, 7, Direction::Horizontal, 3);
    CHECK(note.read(numPage, 8, 6, Direction::Horizontal, 6) == ("I~~~__"));
    CHECK(note.read(numPage, 7, 6, Direction::Vertical, 4) == ("_I__"));
    note.write(numPage, maxRow, maxCol-4, Direction::Horizontal, "Maccabi");
    note.write(numPage+1, 0, 2, Direction::Horizontal, " Haifa");
    CHECK(note.read(numPage, maxRow, maxCol-4, Direction::Horizontal, 13) == ("Maccabi Haifa"));
    CHECK(note.read(numPage, maxRow, maxCol-6, Direction::Horizontal, 9) == ("__Maccabi"));
    CHECK(note.read(numPage+1, 0, 3, Direction::Vertical, 7) == ("Haifa__"));
    CHECK(note.read(numPage, maxRow, maxCol-2, Direction::Vertical, 6) == ("__c___"));
    CHECK(note.read(numPage, maxRow, 0, Direction::Vertical, 6) == ("_b____"));
    note.erase(numPage, maxRow-2, maxCol-3, Direction::Vertical, 5);
    CHECK(note.read(numPage, maxRow, maxCol-4, Direction::Horizontal, 13) == ("M~ccabi Haifa"));
    CHECK(note.read(numPage, maxRow-4, maxCol-3, Direction::Horizontal, 8) == ("__~~~~~_"));
}



unsigned int randNum(){
    unsigned int n = (unsigned int) rand()% 100 + 10;
    return n;
}