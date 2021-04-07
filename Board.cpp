#include <iostream>
#include "Board.hpp"
using namespace std;

namespace ariel
{
   
    void Board::post(unsigned int row, unsigned int column, Direction direction, string const & message )
    {
        unsigned int length = 0;
         if (message.empty())
            {
               return;
            }
        // resize board
        this->minRow = min(this->minRow, row);
        this->maxRow = max(this->maxRow, row);
        this->minCol = min(this->minCol, column);
        this->maxCol = max(this->maxCol, column);
        
        for(char letter: message)
        {
            //this->board[row][column].entry = letter;
            board[row][col] = message.at(letter);
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
           // message += this->board[row][column].entry;
           if (board[row][col] != 0)
            {
                message += board[row][col];
            }
            else
            {
                message += '_';
            }
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
      
         for (unsigned long i = rowMin; i < rowMax + 5; i++)
             {
               cout << i << ": ";
               for (unsigned long j = colMin; j < colMax + 5; j++)
                    {
                     if (board[i][j] != 0)
                          {
                           cout << board.at(i).at(j);
                          }
                     else
                          {
                           cout << '_';         
                          }
                  }
        cout << endl;
    }
}
