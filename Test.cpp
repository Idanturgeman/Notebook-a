#include "Notebook.hpp"
#include "doctest.h"


ariel::Notebook note;

//For the tests examples we assuming that every page is 91x81

TEST_CASE("Bad notebook code"){
    note.write(100, 90, 76, Direction::Horizontal, "Maccabi");
    note.write(101, 0, 2, Direction::Horizontal, " Haifa");
    CHECK_THROWS(note.write(100, 90, 76, Direction::Horizontal, "Ronaldo"));
    CHECK_THROWS(note.write(100, 90, 74, Direction::Horizontal, "Messi"));
    CHECK_THROWS(note.write(101, 0, 3, Direction::Vertical, "Zinadin Zidan"));
    CHECK_THROWS(note.write(100, 90, 0, Direction::Vertical, "Patric Viera"));
    note.erase(100, 88, 77, Direction::Vertical, 5);
    CHECK_THROWS(note.write(100, 90, 76, Direction::Horizontal, "Diego Armando Maradona"));
    CHECK_THROWS(note.write(100, 86, 77, Direction::Horizontal, "Ronaldinio"));
    CHECK_THROWS(note.write(100, 87, 83, Direction::Vertical, "Gianluigi Buffon"));
    
}

TEST_CASE("Good notebook code"){
    CHECK(note.read(100, 5, 7, Direction::Horizontal, 5) == ("_____"));
    note.write(100, 8, 6, Direction::Horizontal, "Idan");
    CHECK(note.read(100, 8, 6, Direction::Horizontal, 4) == ("Idan"));
    CHECK(note.read(100, 5, 8, Direction::Vertical, 5) == ("___a_"));
    note.erase(100, 88, 77, Direction::Horizontal, 3);
    CHECK(note.read(100, 88, 75, Direction::Horizontal, 6) == ("__~~~_"));
    note.erase(100, 8, 7, Direction::Horizontal, 3);
    CHECK(note.read(100, 8, 6, Direction::Horizontal, 6) == ("I~~~__"));
    CHECK(note.read(100, 7, 6, Direction::Vertical, 4) == ("_I__"));
    note.write(100, 90, 76, Direction::Horizontal, "Maccabi");
    note.write(101, 0, 2, Direction::Horizontal, " Haifa");
    CHECK(note.read(100, 90, 76, Direction::Horizontal, 13) == ("Maccabi Haifa"));
    CHECK(note.read(100, 90, 74, Direction::Horizontal, 9) == ("__Maccabi"));
    CHECK(note.read(101, 0, 3, Direction::Vertical, 7) == ("Haifa__"));
    CHECK(note.read(100, 88, 78, Direction::Vertical, 6) == ("__c___"));
    CHECK(note.read(100, 90, 0, Direction::Vertical, 6) == ("_b____"));
    note.erase(100, 88, 77, Direction::Vertical, 5);
    CHECK(note.read(100, 90, 76, Direction::Horizontal, 13) == ("M~ccabi Haifa"));
    CHECK(note.read(100, 86, 77, Direction::Horizontal, 8) == ("__~~~~~_"));
    CHECK(note.read(100, 87, 83, Direction::Vertical, 8) == ("_~~~~~__"));
}