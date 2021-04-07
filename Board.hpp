
#include <iostream>
#include <string>
#include <map>
#include <limits.h>
#include "Direction.hpp"



namespace ariel
{
    class Board
    {
        map<unsigned int, map<unsigned int, char>> board;
        unsigned int minRaw, maxRow, minCol,maxCol;
        
       

    public:
          Board() { 
            maxRow = 0;
            minRow = UINT_MAX;  
            maxCol = 0;
            minCol = UINT_MAX;
        }
        ~Board() {}
      
        void post(unsigned int row, unsigned int column, Direction direction, string const &message);
        string read(unsigned int row, unsigned int column, Direction direction, uint length);
        void show();
    };   
}
    
