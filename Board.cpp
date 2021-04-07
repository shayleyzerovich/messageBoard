
#include "Board.hpp"
#include <string>
#include <climits>
#include <iostream>

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
        if (minRow > row){ minRow = row; }
        if (maxRow < row){maxRow = row; }
        if (minCol > column) {minCol = column;}
        if (maxCol < column) {maxCol = column;}
        
        for(char i: message)
        {
            /
            board[row][column] = i;
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
       
    string Board::read(unsigned int row, unsigned int column, Direction direction, unsigned int length)
    {
        string message;
        for(unsigned int i=0; i<length; i++){
           // message += this->board[row][column].entry;
           if (board[row][column] != 0)
            {
                message += board[row][column];
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

    
   
    void Board::show()
    {
      
         for (unsigned long i = minRow; i < maxRow + 5; i++)
             {
               cout << i << ": ";
               for (unsigned long j = minCol; j < maxCol + 5; j++)
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
}
