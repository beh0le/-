#include <iostream>
#include <ctime>
#include<locale>

int main()
{
    setlocale(LC_ALL, "Russian");
    srand(time(NULL));
    int mass1[10][10];
    int max = -1;
    int min;
    int n = 10;

    // Заполнение и вывод массива mass1
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            mass1[i][j] = rand() % 100;
            std::cout << mass1[i][j] << " ";
        }
        std::cout << std::endl;
    }

    std::cout << "*********************************************" << std::endl;

    // Нахождение максимального элемента
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (mass1[i][j] > max)
            {
                max = mass1[i][j];
            }
        }
    }

    std::cout << "max number = " << max << std::endl;
    std::cout << "*********************************************" << std::endl;
    std::cout << "Сортировка пузирьковым методом" << std::endl;

    // Сортировка всего массива mass1 (пузырьковая сортировка)
    for (int i = 0; i < n * n - 1; i++)
    {
        for (int j = 0; j < n * n - 1 - i; j++)
        {
            if (mass1[j / n][j % n] > mass1[(j + 1) / n][(j + 1) % n])
            {
                int temp = mass1[j / n][j % n];
                mass1[j / n][j % n] = mass1[(j + 1) / n][(j + 1) % n];
                mass1[(j + 1) / n][(j + 1) % n] = temp;
            }
        }
    }

    // Вывод отсортированного массива mass1
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            std::cout << mass1[i][j] << " ";
        }
        std::cout << std::endl;
    }
    std::cout << "*****************************************************" << std::endl;
    std::cout << "Выборочная сортировка" << std::endl;
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            min = mass1[i][j];
            for (int k = j; k < 10; k++)
            {
                if (min > mass1[i][k])
                {
                    int temp = mass1[i][k];
                    min = mass1[i][k];

                }
          }
            mass1[i][j] = min;
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            std::cout << mass1[i][j] << " ";
        }
        std::cout << std::endl;
    }
    std::cin >>min;
    return 0;
}
