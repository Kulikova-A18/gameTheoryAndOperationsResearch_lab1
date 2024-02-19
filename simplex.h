#ifndef SIMPLEX_H
#define SIMPLEX_H

#include <iostream>
#include <iomanip>
#include <sstream>
#include <cstdlib>
#include <time.h>
#include <fstream>

namespace gameTheoryAndOperationsResearch {
    class _gameTheoryAndOperationsResearch_simplex
    {
        public:
            void _simplex(int, int, double*, double**, double*, double*, double&, std::ostream&);
    };
}

#endif // SIMPLEX_H
