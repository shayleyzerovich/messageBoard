#include <iostream>
#include "Direction.hpp"
#include <string>
#include <map>


namespace ariel
{
    class Board
    {
        std::map<unsigned int, std::map<unsigned int, char>> board;
        unsigned int minRaw, maxRow, maxCol, minCol;

    public:
          Board() { 
            maxRow = 0;
            minRow = UINT_MAX;  //Maximum value for a variable of type unsigned int (0xffffffff)
            maxCol = 0;
            minCol = UINT_MAX;
        }
        ~Board() {}
      
        void post(unsigned int row, unsigned int col, Direction direction, string const &message);
        string read(unsigned int row, unsigned int col, Direction direction, uint length);
        void show();
        
   
}
