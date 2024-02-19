#include "maxmin.h"

namespace gameTheoryAndOperationsResearch {
    double _gameTheoryAndOperationsResearch_maxmin::max_min(double **Matr, int n, int m)
    {
        double min;
        double max = 0;
        for (int i = 0; i < n; i++)
        {
            min = Matr[i][0];
            for (int j = 1; j < m; j++)
                if (min > Matr[i][j])
                    min = Matr[i][j];
            if (max < min)
                max = min;

        }
        return max;

    }

    double _gameTheoryAndOperationsResearch_maxmin::min_max(double **Matr, int n, int m)
    {
        double min = 9e99;
        double max;
        for (int j = 0; j < m; j++)
        {
            max = Matr[0][j];
            for (int i = 1; i < n; i++)
                if (max < Matr[i][j])
                    max = Matr[i][j];
            if (max < min)
                min = max;

        }
        return min;

    }
}
