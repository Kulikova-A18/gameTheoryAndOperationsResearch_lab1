#include "game.h"

#include "simplex.h"

namespace gameTheoryAndOperationsResearch {

    gameTheoryAndOperationsResearch::_gameTheoryAndOperationsResearch_simplex classSimplex_game;

    // На входе матрица игры n на m на выходе цена игры и смешанные стратегии
    void _gameTheoryAndOperationsResearch_game::game(double **Matr, int n, int m, double &Price, double &Price2, double *p, double *q, std::ostream & fout)
    {
        // Решаем прямую задачу
        int n1, m1; // Для задачи ЛП
        n1 = n; m1 = m;

        double **a = new double *[m1]; // матрица коэффициентов ограничений в ЗЛП
        double *c = new double[n1]; // Коэф. целевой функции
        double *b = new double[m1]; // Коэф. правых чсате ограничений

        for (int i = 0; i < m1; i++)
            a[i] = new double[n1];

        for (int i = 0; i < n1; i++)
            c[i] = 1;

        for (int i = 0; i < m1; i++)
            b[i] = -1;

        for (int i = 0; i < m1; i++)
            for (int j = 0; j < n1; j++)
                a[i][j] = -Matr[j][i];

        // Печать задачи ЛП

        fout << "(task) player №1:\n";
        fout << "F(U)=";
        fout << std::setprecision(2);

        for (int i = 0; i < n1; i++) {
            fout << c[i] << "u" << (i + 1);
            if (i != n1 - 1)
                fout << " + ";
            else
                fout << " --> min\n";
        }
        for (int j = 0; j < m1; j++)
            for (int i = 0; i < n1; i++)
            {
                fout << a[j][i] << "u" << (i + 1);
                if (i != n1 - 1)
                    fout << " + ";
                else
                    fout << " <=" << b[j] << "\n";
            }

        classSimplex_game._simplex(n1, m1, c, a, b, p, Price, fout);

        // Переход к исходным переменным
        for (int i = 0; i < n; i++)
            p[i] /= Price;

        Price = 1. / Price;

        for (int i = 0; i < m1; i++)
            delete[] a[i];

        delete[] a;
        delete[] b;
        delete[] c;

        // Решение двойственной задачи ЛП
        n1 = m; m1 = n;
        a = new double *[m1];
        c = new double[n1];
        b = new double[m1];

        for (int i = 0; i < m1; i++)
            a[i] = new double[n1];

        for (int i = 0; i < n1; i++)
            c[i] = -1;

        for (int i = 0; i < m1; i++)
            b[i] = 1;

        for (int i = 0; i < m1; i++)
            for (int j = 0; j < n1; j++)
                a[i][j] = Matr[i][j];

        // Печать задачи ЛП

        fout << "(task) player №2:\n";
        fout << "F(V)=";
        fout << std::setprecision(2);

        for (int i = 0; i < n1; i++)
        {
            fout << c[i] << "v" << (i + 1);
            if (i != n1 - 1)
                fout << " + ";
            else
                fout << " --> min\n";
        }
        for (int j = 0; j < m1; j++) {
            for (int i = 0; i < n1; i++)
            {
                fout << a[j][i] << "v" << (i + 1);

                if (i != n1 - 1)
                    fout << " + ";
                else
                    fout << " <=" << b[j] << "\n";
            }
        }

        classSimplex_game._simplex(n1, m1, c, a, b, q, Price2, fout);

        Price2 = -Price2;

        for (int i = 0; i < m; i++)
            q[i] /= Price2;

        Price2 = 1. / Price2;

        for (int i = 0; i < m1; i++)
            delete[] a[i];

        delete[] a;
        delete[] b;
        delete[] c;
    }
}
