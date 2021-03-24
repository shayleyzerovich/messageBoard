#include <string>
#include "Direction.hpp"

using namespace std;

namespace ariel
{
    class Board
    {
        unsigned int rows;
        unsigned int cols;

    public:
        static void post(unsigned int row, unsigned int column, Direction direction, string const & data);           // Function Based off Demo given by Erel(Arguments...)
        static string read(unsigned int row, unsigned int column, Direction direction, unsigned int length); // Function Based off Demo given by Erel(Arguments...)
        void show();
    };
}