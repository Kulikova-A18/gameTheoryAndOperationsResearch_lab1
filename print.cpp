#include "print.h"

namespace gameTheoryAndOperationsResearch {
    void _gameTheoryAndOperationsResearch_print::print_matrix(std::ostream& out, double **pMatr, int n, int m)
    {
        //out.width(4);
        out.precision(2);
        out << std::fixed;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                out.width(7);
                out << pMatr[i][j];
            }
            out << std::endl;
        }
    }

    void _gameTheoryAndOperationsResearch_print::print_table(std::ostream& out, double **Sim, int n, int m, int *Bas, int *Svob)
    {
        out << "\nsimplex table:\n";
        out.precision(3);
        out << std::fixed;

        for (int i = -1; i < m+1; i++)
        {
            for (int j = -1; j < n+1; j++)
            {
                if (j==-1) {
                    out.width(2);
                } else {
                    out.width(8);
                }
                // Печать заголовка
                if (i == -1) {
                    if (j == -1) {
                        out << ' '; // Пусто
                    } else {
                        if (j==0) {
                          out << "Si0";
                        } else {
                            std::ostringstream outstr;  // Для записи данных в строку
                            outstr << "x" << Svob[j-1]+1; // Заголовок столбца (своб. переменные)
                            out << outstr.str();

                        }
                    }
                }
                else {
                    // Первый столбец
                    if (j == -1) {
                        if (i!=m) {
                            std::ostringstream outstr;  // Для записи данных в строку
                            outstr << "x" << Bas[i]+1; // Заголовок столбца (своб. переменные)
                            out << outstr.str();
                        } else {
                            out << "F";
                        }
                    }
                    else {
                        out << Sim[i][j]; // Данные таблицы
                    }
                }
            }
            out << std::endl;
        }
    }

    void _gameTheoryAndOperationsResearch_print::print_vector(std::ostream& out, char * str, double *p, int n)
    {
        out.precision(3);
        out << std::fixed;
        out << str << ": ";
        for (int i = 0; i < n; i++) {
            out << p[i] << " ";
        }
        out << std::endl;
    }
}
