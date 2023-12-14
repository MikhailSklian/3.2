#include <iostream>
using namespace std;

int main() {
    setlocale(LC_ALL, "Russian");
    const int n = 4;
    const int m = 4;
    int matrixA[n][m];
    int matrixB[n][m];

    // Инициализация генератора случайных чисел


    srand(time(0));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            matrixA[i][j] = rand() % 100; // Generate random number from 0 to 99
        }
    }

    // Вывод матрицы A на экран
    cout << "Сгенерированная матрица A:";
    for (int i = 0; i < n; i++) {
        cout << "\n";
        for (int j = 0; j < m; j++) {
            cout << matrixA[i][j] << " ";
        }
        cout << "";
    }

    // Построение матрицы B
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int maxVal = 0;           
            for (int b =j;  b < m; b++) {
                if (maxVal < matrixA[i][b])
                {
                    maxVal = matrixA[i][b];
                }              
            }
            int step = 1;
            for (int k = i-1; k >= 0; k--) {//цикл вниз 
                for (int c = j+step; c < m; c++)
                {
                    if (maxVal < matrixA[k][c])
                    {
                        maxVal = matrixA[k][c];
                    }
                  
                }
                step++;
            }
            step = 1;
            for (int k = i+1; k<n; k++) {
   
                for (int c = j + step; c < m; c++)
                {
                    if (maxVal < matrixA[k][c])
                    {
                        maxVal = matrixA[k][c];
                    }
                   
                }
                step++;
            }
            matrixB[i][j] = maxVal;
        }
    }
    cout << "\n";
    // Вывод матрицы B на экран
    cout << "Построенная матрица B:";
    for (int i = 0; i < n; i++) {
        cout << "\n";
        for (int j = 0; j < m; j++) {
            cout << matrixB[i][j] << " ";
        }
        cout << "";
    }

    return 0;
}
