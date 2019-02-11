//
//  main.c
//  HW_3_Lemeshaev_Stanislav
//
//  Created by Станислав Лемешаев on 06/02/2019.
//  Copyright © 2019 Станислав Лемешаев. All rights reserved.
//
//3. Реализовать бинарный алгоритм поиска в виде функции, которой передается отсортированный массив. Функция возвращает индекс найденного элемента или -1, если элемент не найден.
//4. *Подсчитать количество операций для каждой из сортировок и сравнить его с асимптотической сложностью алгоритма.

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// print array
void printArray(int *array, int length) {
    int i;
    for (i = 0; i < length; i++) {
        printf("a[%i] = %2i ", i, array[i]);
    }
    printf("\n");
}

// filling an array with random numbers
void randomInit(int *array, int length) {
    srand(time(NULL));
    int i;
    for (i = 0; i < length; i++) {
        array[i] = -30 + rand() % 61; // [-30; 30]
    }
}

// function bubble sort (increase)
void bubbleSort(int *array, int length) {
    int count = 0; // number of operations
    int i, j;
    int tmp;
    for (i = 1; i < length; i++) {
        for (j = 1; j < length; j++) {
            count++;
            if (array[j] < array[j-1]) {
                tmp = array[j];
                array[j] = array[j-1];
                array[j-1] = tmp;
            }
        }
    }
    printf("Count of operations bubbleSort: %d\n", count);
}

// function bubble sort (New) (increase)
void bubbleSortNew(int *array, int length) {
    int i, tmp;
    char flag;
    int count = 0; // number of operations
    do {
        flag = 0;
        for (i = 1; i < length; i++) {
            count++;
            if (array[i] < array[i-1]) {
                tmp = array[i];
                array[i] = array[i-1];
                array[i-1] = tmp;
                flag = 1;
            }
        }
    } while (flag);
    printf("Count of operations bubbleSortNew: %d\n", count);
}

// Shaker sort function
void shakerSort(int *array, int length)
{
    int left = 0, right = length - 1; // левая и правая границы сортируемой области массива
    int flag = 1;  // флаг наличия перемещений
    // Выполнение цикла пока левая граница не сомкнётся с правой
    // или пока в массиве имеются перемещения
    int rightCount = 0;
    int leftCount = 0;
    while ((left < right) && flag > 0)
    {
        flag = 0;
        int i;
        for (i = left; i < right; i++)  // двигаемся слева направо
        {
            rightCount++;
            if (array[i] > array[i + 1]) // если следующий элемент меньше текущего,
            {             // меняем их местами
                int t = array[i];
                array[i] = array[i + 1];
                array[i + 1] = t;
                flag = 1;      // перемещения в этом цикле были
            }
        }
        right--; // сдвигаем правую границу на предыдущий элемент
        for (i = right; i > left; i--)  //двигаемся справа налево
        {
            leftCount++;
            if (array[i - 1] > array[i]) // если предыдущий элемент больше текущего,
            {            // меняем их местами
                int t = array[i];
                array[i] = array[i - 1];
                array[i - 1] = t;
                flag = 1;    // перемещения в этом цикле были
            }
        }
        left++; // сдвигаем левую границу на следующий элемент
    }
    printf("Count of operations Shaker sort: %d\n", rightCount + leftCount);
}

// Binary search
int binarySearch(int *array, int length, int key) {
    int left = 0; // задаем левую и правую границы поиска
    int right = length - 1;
    bubbleSortNew(array, length); // отсортировываем массив
    while (left <= right) // пока левая граница не "перескочит" правую
    {
        int mid = (left + right) / 2; // ищем середину отрезка
        if (key == array[mid]) {  // если ключевое поле равно искомому
            return mid;     // возвращаем требуемый элемент,
            break;          // выходим из цикла
        }
        if (key < array[mid]) // если искомое ключевое поле меньше найденной середины
            right = mid - 1;  // смещаем правую границу, продолжим поиск в левой части
        else                  // иначе
            left = mid + 1;   // смещаем левую границу, продолжим поиск в правой части
    }
    return -1; // найденный индекс элемента равен -1 (элемент не найден)
}

// main function
int main() {
    const int SIZE = 10;
    int A[SIZE];
    //  1. Попробовать оптимизировать пузырьковую сортировку.
    //  Сравнить количество операций сравнения оптимизированной и не оптимизированной программы.
    //  Написать функции сортировки, которые возвращают количество операций.
    printf("Array before sort:\n");
    randomInit(A, SIZE);
    printArray(A, SIZE);

    printf("\nArray after sort:\n");
    bubbleSort(A, SIZE);
    printArray(A, SIZE);
    
    printf("\nArray after sort:\n");
    bubbleSortNew(A, SIZE);
    printArray(A, SIZE);
    
    //2. *Реализовать шейкерную сортировку.
    printf("\nArray after sort:\n");
    shakerSort(A, SIZE);
    printArray(A, SIZE);
    
    //3. Реализовать бинарный алгоритм поиска в виде функции, которой передается отсортированный массив. Функция возвращает индекс найденного элемента или -1, если элемент не найден.
    printf("\nWhat item do you want to find? ");
    int item;
    scanf("%d", &item);
    printf("Такой элемент находится под номером: %d ", binarySearch(A, SIZE, item));
    printf("\n");
    return 0;
}
