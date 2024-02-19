#ifndef PRINT_H
#define PRINT_H

#include <iostream>
#include <iomanip>
#include <sstream>
#include <cstdlib>
#include <time.h>
#include <fstream>

namespace gameTheoryAndOperationsResearch {
    class _gameTheoryAndOperationsResearch_print
    {
        public:
            void print_matrix(std::ostream&, double**, int, int);
            void print_table(std::ostream&, double**, int, int, int*, int*);
            void print_vector(std::ostream&, char*, double*, int );
    };
}

#endif // PRINT_H
