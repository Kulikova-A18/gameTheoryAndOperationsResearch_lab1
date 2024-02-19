#include <iostream>
#include <iomanip>
#include <sstream>
#include <cstdlib>
#include <time.h>
#include <fstream>

#include "game.h"
#include "maxmin.h"
#include "print.h"
#include "simplex.h"

#define N 4
#define M 5

namespace gameTheoryAndOperationsResearch {



    gameTheoryAndOperationsResearch::_gameTheoryAndOperationsResearch_game      class_game_main;
    gameTheoryAndOperationsResearch::_gameTheoryAndOperationsResearch_maxmin    class_maxmin_main;
    gameTheoryAndOperationsResearch::_gameTheoryAndOperationsResearch_print     class_print_main;
    gameTheoryAndOperationsResearch::_gameTheoryAndOperationsResearch_simplex   class_simplex_main;

    int _main(int argc, char* argv[])
    {
        std::ofstream fout("gameTheoryAndOperationsResearch_v4.txt");

        double **a = new double *[N];
        for (int i = 0; i < N; i++)
            a[i] = new double[M];

        /*
         *  16   3   14  4   8
         *  0    6   17  0   12
         *  10   3   4   16  2
         *  2    3   9   11  19
         */

        a[0][0] = 16;   a[0][1] = 3;    a[0][2] = 14;    a[0][3] = 4;    a[0][4] = 8;
        a[1][0] = 0;    a[1][1] = 6;    a[1][2] = 17;    a[1][3] = 0;    a[1][4] = 12;
        a[2][0] = 10;   a[2][1] = 3;    a[2][2] = 4;     a[2][3] = 16;   a[2][4] = 2;
        a[3][0] = 2;    a[3][1] = 10;   a[3][2] = 9;     a[3][3] = 11;   a[3][4] = 19;


        fout << "Kulikova Alyona - v4\n";
        fout << "Matrix game:\n";

        class_print_main.print_matrix(fout, a, N, M);

        fout << "\ndata min_max:  " << class_maxmin_main.min_max(a, N, M) << "\n";
        fout << "\ndata max_min:  " << class_maxmin_main.max_min(a, N, M) << "\n";

        double *p = new double[N];
        double *q = new double[M];
        double F1, F2;

        class_game_main.game(a, N, M, F1, F2, p, q, fout);

        fout << "\ndata F1:   " << F1 << "\n";
        fout << "\ndata F2:   " << F2 << "\n";

        class_print_main.print_vector(fout, (char *)"P", p, N);
        class_print_main.print_vector(fout, (char *)"Q", q, M);

        system("pause");
        return 0;
    }

}

int main(int argc, char* argv[])
{
    gameTheoryAndOperationsResearch::_main(argc, argv);
    return 0;
}
