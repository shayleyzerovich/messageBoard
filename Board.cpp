#include <iostream>
#include "Board.hpp"
using namespace std;

namespace ariel
{
   
    void Board::post(unsigned int row, unsigned int column, Direction direction, string const & data )
    {
        unsigned int length = 0;
        // resize board
        this->minRow = min(this->minRow, row);
        this->maxRow = max(this->maxRow, row);
        this->minCol = min(this->minCol, column);
        this->maxCol = max(this->maxCol, column);
        
        for(char letter: message)
        {
            this->board[row][column].entry = letter;
            if(direction == Direction::Horizontal){
                column++;
            }
            else // vertical
            {
                row++; 
            }
            length++;
        }
        if(direction == Direction::Horizontal){
            // update board size
                maxCol+=length;
            }
            else
            {
                maxRow+=length;
            }
    }
       
    string Board::read(unsigned int row, unsigned int column, Direction direction, unsigned int length )
    {
        string message;
        for(unsigned int i=0; i<length; i++){
            message += this->board[row][column].entry;
            if(direction == Direction::Horizontal){
                column++;
            }
            else  // if vertical
            {
                row++; 
            }        
        }
        return message;
    }

    }
   
    void Board::show()
    {
      for (unsigned int row = this->minRow; row <= this->maxRow; row++) 
        {
            for (unsigned int col = this->minCol; col <= this->maxCol; col++) 
            {
                cout << this->board[row][col].entry;
            }
            cout << endl;
        }  
    }
}
