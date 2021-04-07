#include <iostream>
#include <string>
#include <map>
#include <limits.h>
#include "Direction.hpp"



namespace ariel
{
    class Board
    {
        std::map<unsigned int, std::map<unsigned int, char>> board;
        unsigned int minRow, maxRow, minCol,maxCol;
        
       

    public:
          Board() { 
            maxRow = 0;
            minRow = UINT_MAX;  
            maxCol = 0;
            minCol = UINT_MAX;
        }
        ~Board() {}
      
        void post(unsigned int row, unsigned int column, Direction direction, std::string const &message);
        std::string read(unsigned int row, unsigned int column, Direction direction, unsigned int length);

        void show();
    };   
}
