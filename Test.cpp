#include <stdlib.h>
#include <ctime>
#include "doctest.h"
#include "Board.hpp"
using namespace ariel;

#include <string>
using namespace std;
Board board;


TEST_CASE("empty board - before posting")
{
    CHECK(board.read(0, 0, Direction::Horizontal, 0) == "");
    CHECK(board.read(2, 1, Direction::Horizontal, 0) == "");
    CHECK(board.read(0, 0, Direction::Horizontal, 1) == string("_"));
    CHECK(board.read(0, 0, Direction::Vertical, 1) == string("_"));
    CHECK(board.read(1, 1, Direction::Horizontal, 2) == string("__"));
    CHECK(board.read(1, 1, Direction::Vertical, 2) == string("__"));
    CHECK(board.read(32, 55, Direction::Horizontal, 3) == string("___"));
    CHECK(board.read(32, 55, Direction::Vertical, 3) == string("___"));
    CHECK(board.read(12, 40, Direction::Horizontal, 6) == string("______"));
    CHECK(board.read(12, 40, Direction::Vertical, 6) == string("______"));
    CHECK(board.read(50, 60, Direction::Horizontal, 9) == string("_________"));
    CHECK(board.read(50, 60, Direction::Vertical, 9) == string("_________"));
}

TEST_CASE("board post")
{
    CHECK_NOTHROW(board.post(0, 0, Direction::Horizontal, "Test"));
    CHECK_NOTHROW(board.post(0, 6, Direction::Horizontal, "hey! "));
    CHECK_NOTHROW(board.post(1, 0, Direction::Horizontal, "yes"));
    CHECK_NOTHROW(board.post(3, 2, Direction::Horizontal, "code"));
    CHECK_NOTHROW(board.post(4, 1, Direction::Horizontal, "Message"));
    CHECK_NOTHROW(board.post(5, 0, Direction::Horizontal, "no"));
    CHECK_NOTHROW(board.post(6, 3, Direction::Horizontal, "test"));
    CHECK_NOTHROW(board.post(7, 0, Direction::Horizontal, "shay"));
    CHECK_NOTHROW(board.post(8, 7, Direction::Horizontal, "Good"));
    CHECK_NOTHROW(board.post(1, 5, Direction::Horizontal, "shallom"));
    CHECK_NOTHROW(board.post(6, 9, Direction::Horizontal, "salut"));
    CHECK_NOTHROW(board.post(8, 4, Direction::Horizontal, "wow"));
    CHECK_NOTHROW(board.post(15, 2, Direction::Horizontal, "Good"));
    CHECK_NOTHROW(board.post(16, 15, Direction::Horizontal, "Job")); 
  
    CHECK_NOTHROW(board.post(9, 8, Direction::Vertical, "bye"));
    CHECK_NOTHROW(board.post(10, 5, Direction::Vertical, "Welcome"));
    CHECK_NOTHROW(board.post(2, 0, Direction::Vertical, "Hi"));
    CHECK_NOTHROW(board.post(9, 3, Direction::Vertical, "Luck"));
    CHECK_NOTHROW(board.post(5, 12, Direction::Vertical, "q"));
    CHECK_NOTHROW(board.post(17, 4, Direction::Vertical, "Cpp"));
    CHECK_NOTHROW(board.post(15, 14, Direction::Vertical, "YES"));
    CHECK_NOTHROW(board.post(16, 14, Direction::Vertical, "no"));
    CHECK_NOTHROW(board.post(11, 12, Direction::Vertical, "Every"));
    CHECK_NOTHROW(board.post(20, 2, Direction::Vertical, "W"));
  
}


TEST_CASE("read- after the posts")
{
    CHECK(board.read(15, 2, Direction::Horizontal, 5) == string("Good_"));
    CHECK(board.read(1, 5, Direction::Horizontal, 7) == string("shallom"));
    CHECK(board.read(8, 4, Direction::Horizontal, 8) == string("wow___G"));
    CHECK(board.read(8, 4, Direction::Horizontal, 10) == string("wow___Good"));
    CHECK(board.read(0, 0, Direction::Horizontal, 4) == string("Test"));
    CHECK(board.read(6, 9, Direction::Horizontal, 7) == string("salut__"));
  
     CHECK(board.read(4, 1, Direction::Horizontal, 3) == string("Mes"));
    CHECK(board.read(7, 0, Direction::Horizontal, 7) == string("shay___"));
    CHECK(board.read(0, 0, Direction::Horizontal, 10) == string("test_hey! "));
    CHECK(board.read(2, 3, Direction::Horizontal, 10) == string("___"));
    CHECK(board.read(3, 2, Direction::Horizontal, 6) == string("code__"));
    CHECK(board.read(5, 0, Direction::Horizontal, 5) == string("no___"));

}

TEST_CASE("Special symbols")
{
    CHECK_NOTHROW(board.post(12, 20, Direction::Horizontal, "?&"));
    CHECK(board.read(12, 20, Direction::Horizontal, 2) == "?&");
    CHECK_NOTHROW(board.post(13, 19, Direction::Horizontal, "&"));
    CHECK(board.read(13, 19, Direction::Horizontal, 1) == "&");
    CHECK_NOTHROW(board.post(8, 17, Direction::Vertical, "@"));
    CHECK(board.read(8, 17, Direction::Vertical, 1) == "@");
    CHECK_NOTHROW(board.post(0, 16, Direction::Vertical, "123*"));
    CHECK(board.read(0, 16, Direction::Vertical, 4) == "123*");
}



