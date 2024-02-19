#ifndef MAXMIN_H
#define MAXMIN_H

#include <iostream>
#include <iomanip>
#include <sstream>
#include <cstdlib>
#include <time.h>
#include <fstream>

namespace gameTheoryAndOperationsResearch {
    class _gameTheoryAndOperationsResearch_maxmin
    {
        public:
            double max_min(double**, int, int);
            double min_max(double**, int, int);
    };
}

#endif // MAXMIN_H
