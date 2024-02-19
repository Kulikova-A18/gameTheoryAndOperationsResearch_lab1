#include "simplex.h"

#include "print.h"

#include <memory.h>

namespace gameTheoryAndOperationsResearch {

    gameTheoryAndOperationsResearch::_gameTheoryAndOperationsResearch_print classPrint_simple;

    void _gameTheoryAndOperationsResearch_simplex::_simplex(int n, int m, double *c, double **a2,
                                                            double *b, double *x, double & F, std::ostream & fout) {
        // n- число переменных m - число ограничений
        // с- коэффициенты в целевой функции
        // a2 - матрица коэффициентов в ограничениях
        // b - правые части ограниения
        // x - полученный резултат на выходе
        // F - выход значение показателя качества
        // Решается задача минимизации в ограничениях знак <=
        double **a = new double*[m];
        int * Bas = new int[m]; // Базиные переменные
        int *Svob = new int[n]; // Свободные переменные

        for (int i = 0; i < m; i++)
            a[i] = new double[n + m]; // Матрица ограничений расширенная

        double **Sim = new double*[m + 1]; //  Симплекс таблица
        double **Sim2 = new double*[m + 1]; //  Симплекс таблица

        for (int i = 0; i <= m; i++) {
            Sim[i] = new double[n + 1];
            Sim2[i] = new double[n + 1];
        }

        // Заполняем расширенную матрицу ограничений
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n + m; j++)
            {
                if (j < n) a[i][j] = a2[i][j];
                else
                {
                    if (j - n == i) a[i][j] = 1; // В расширенной таблице ограничений в конце единичная матрица
                    else a[i][j] = 0;
                }
            }
        }

        // Записываем номера свободных и базисных переменных
        int Num = 0;
        for (int i = 0; i < n; i++)
            Svob[i] = Num++;

        for (int i = 0; i < m; i++)
            Bas[i] = Num++;

        // Заполняем симплекс таблицу
        for (int i = 0; i < m; i++) {
            Sim[i][0] = b[i];

            for (int j = 1; j < n + 1; j++)
                Sim[i][j] = a[i][j - 1];
        }

        Sim[m][0] = 0;
        for (int j = 1; j < n + 1; j++)
            Sim[m][j] = -c[j - 1];


        bool flag = true; // Проверка условия завершения цикла
        do
        {
            classPrint_simple.print_table(fout, Sim, n, m, Bas, Svob);

            double min = Sim[0][0];
            int imin = 0;

            for (int i = 1; i < m; i++) {
                if (Sim[i][0] < min)
                {
                    min = Sim[i][0]; imin = i;
                }
            }

            int j1;
            if (min < 0) // Преобразуем таблицу
            {

                for (j1 = 0; j1 < n; j1++) {
                    if (Sim[imin][j1 + 1] < 0)
                        break;
                }

                if (j1 >= n) {
                    flag = false; // Решение найдено
                } else {
                    min = 99e99;// Sim[0][0] / Sim[0][j1 + 1];
                    imin = -1;
                    for (int i = 0; i < m; i++) {
                        double rez = Sim[i][0] / Sim[i][j1 + 1];
                        if (rez < min && rez>0)
                        {
                            min = rez; imin = i;
                        }
                    }
                }
            }
            else
            {
                // Нашли опорное решение

                for (j1 = 0; j1 < n; j1++)
                    if (Sim[m][j1 + 1] > 0)
                        break;

                if (j1 >= n) {
                    flag = false; // Решение найдено
                } else {
                    min = 9e99; imin = -1;
                    for (int i = 0; i < m; i++) {
                        double rez = Sim[i][0] / Sim[i][j1 + 1];
                        if (rez < min && rez>0)
                        {
                            min = rez; imin = i;
                        }
                    }
                }
            }
            // Создаем новую симплекс таблицу
            // Меняем базисную и свободную переменные
            // j1 - свободная переменная imin- базисная переменная
            if (flag)
            {
                int buf = Svob[j1];
                Svob[j1] = Bas[imin];
                Bas[imin] = buf;

                for (int i = 0; i < m + 1; i++) {
                    for (int j = 0; j < n + 1; j++)
                    {
                        if (imin == i && j1 + 1 == j)
                            Sim2[i][j] = 1. / Sim[i][j];
                        else if (i == imin)
                            Sim2[i][j] = Sim[i][j] / Sim[i][j1 + 1];
                        else if (j1 + 1 == j)
                            Sim2[i][j] = -Sim[i][j] / Sim[imin][j1 + 1];
                        else
                            Sim2[i][j] = Sim[i][j] - Sim[i][j1 + 1] * Sim[imin][j] / Sim[imin][j1 + 1];
                    }
                }

                // Копируем матрицу
                for (int i = 0; i < m + 1; i++)
                    memcpy_s(Sim[i], (n + 1) * sizeof(double), Sim2[i], (n + 1) * sizeof(double));
            }


        } while (flag);

        F = Sim[m][0]; // Показатель качества

        for (int i = 0; i < m; i++)
            if (Bas[i] < n)
                x[Bas[i]] = Sim[i][0];

        for (int i = 0; i < n; i++)
            if (Svob[i] < n)
                x[Svob[i]] = 0;

        fout << std::setprecision(3) << "F=" << F << " uv: ";

        for (int i = 0; i < n; i++)
            fout << x[i] << " ";
        fout << std::endl;

        // Освобождение памяти
        for (int i = 0; i < m; i++) delete[] a[i];
        delete[] a;
        delete[] Bas;
        delete[] Svob;
        for (int i = 0; i <= m; i++) {
            delete[] Sim[i];
            delete[] Sim2[i];
        }
        delete[] Sim;
        delete[] Sim2;
    }
}
