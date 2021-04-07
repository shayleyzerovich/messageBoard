
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
        
        if (direction == Direction::Vertical)
         {
            if (maxRow < row + message.length()){maxRow = row + message.length();}
        
            if (maxCol < column){ colMax = column;}
 
            for (unsigned int i = 0; i < message.length(); i++)
                {
                  board[row][column] = message.at(i);
                  row++;
                 }
          }
        else if (direction == Direction::Horizontal)
         {
             if (maxCol < column + message.length()){maxCol = column + message.length();}
       
             if (maxRow < row){ maxRow = row;}
   
             for (unsigned int i = 0; i < message.length(); i++)
                 {
                   board[row][column] = message.at(i);
                   column++;
                  }
          }
   }
   
    string Board::read(unsigned int row, unsigned int column, Direction direction, unsigned int length)
    {
        string message;
        if (direction == Direction::Vertical)
         {
        for (unsigned int i = 0; i < length; i++)
        {
            if (board[row][column] != 0)
            {
                message += board[row][col];
            }
            else
            {
                message += '_';
            }
            row++;
        }
    }
    else if (direction == Direction::Horizontal)
    {
        for (unsigned int i = 0; i < length; i++)
        {
            if (board[row][column] != 0)
            {
                message += board[row][column];
            }
            else
            {
                message += '_';
            }
            column++;
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
