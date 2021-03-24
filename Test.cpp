#include <stdlib.h>
#include <ctime>
#include "doctest.h"
#include "Board.hpp"
using namespace ariel;

#include <string>
using namespace std;

// All Postions are Valid..
TEST_CASE("Random Valid Posting- Should Not Throw Errors...")
{
    Board board;
    CHECK_NOTHROW(board.post(0, 0, Direction::Horizontal, "nadav"));
    CHECK_NOTHROW(board.post(1, 0, Direction::Vertical, "suissa! "));
    CHECK_NOTHROW(board.post(2, 0, Direction::Vertical, "loves"));
    CHECK_NOTHROW(board.post(3, 0, Direction::Horizontal, "to"));
    CHECK_NOTHROW(board.post(4, 0, Direction::Vertical, "code "));
}

TEST_CASE("Randon Valid Post & Read - General Good Case")
{

    Board board;

    CHECK(board.read(5, 5, Direction::Horizontal, 1)=="_"); // No Post Before so this should obviously be Empty
    CHECK_NOTHROW(board.post(5, 5, Direction::Horizontal, "test")); // First Post
    CHECK(board.read(5, 5, Direction::Horizontal, 4)=="test"); // This test should also indicate that it reads a single word successfully
    CHECK(board.read(5, 6, Direction::Vertical, 1)=="e");
    CHECK(board.read(5, 7, Direction::Vertical, 1)=="s");
    CHECK(board.read(5, 9, Direction::Horizontal, 1)=="_");
    CHECK(board.read(5, 9, Direction::Horizontal, 2)=="__"); // If one read cell is equal to "_" then two should be "__", and so on
}

TEST_CASE("Empty String Test - Input and Output")
{
    Board board;
    // No Post Occured So EveryRead Should Be Empty ("_" As Seen in Demo)
    CHECK(board.read(0, 0, Direction::Horizontal, 0) == "_");
    CHECK(board.read(0, 0, Direction::Vertical, 0) == "_");
    CHECK(board.read(7452, 2323, Direction::Horizontal, 0) == "_"); // Random Place on Board
    CHECK(board.read(20142, 14785, Direction::Vertical, 0) == "_"); // Random Place on Board
}
TEST_CASE("More Than one Word Check")
{
    // More Than one word Written - Check post,read and validity.
    Board board;
    // Should not throw error when posting 2 words as 1 ad
    CHECK_NOTHROW(board.post(0, 0, Direction::Horizontal, "nadav suissa"));  // My Name - 2 Words
    CHECK_NOTHROW(board.post(1, 0, Direction::Vertical, "erel segal")); // Lecturer Name- 2 Words
    // Check that reads correctly
    CHECK(board.read(0, 0, Direction::Horizontal, 12) == "nadav suissa");
    CHECK(board.read(0, 0, Direction::Horizontal, 13) == "nadav suissa_");
    CHECK(board.read(0, 0, Direction::Horizontal, 11) == "nadav suiss");
    CHECK(board.read(1, 0, Direction::Vertical, 10) == "erel segal");
    CHECK(board.read(0, 0, Direction::Vertical, 10) == "nerel sega");  
    CHECK(board.read(1, 0, Direction::Vertical, 11) == "erel segal_");

}