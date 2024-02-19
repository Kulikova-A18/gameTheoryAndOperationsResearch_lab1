#ifndef GAME_H
#define GAME_H

#include <iostream>
#include <iomanip>
#include <sstream>
#include <cstdlib>
#include <time.h>
#include <fstream>

namespace gameTheoryAndOperationsResearch {
    class _gameTheoryAndOperationsResearch_game
    {
        public:
            void game(double**, int, int, double&, double&, double*, double*, std::ostream&);
    };
}

#endif // GAME_H
