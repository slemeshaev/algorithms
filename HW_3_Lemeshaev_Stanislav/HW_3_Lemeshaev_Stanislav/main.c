//
//  main.c
//  HW_3_Lemeshaev_Stanislav
//
//  Created by Станислав Лемешаев on 06/02/2019.
//  Copyright © 2019 Станислав Лемешаев. All rights reserved.
//
//1. Попробовать оптимизировать пузырьковую сортировку. Сравнить количество операций сравнения оптимизированной и не оптимизированной программы. Написать функции сортировки, которые возвращают количество операций.
//2. *Реализовать шейкерную сортировку.
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
void bubbleSort(int *a, size_t size) {
    int count = 0; // number of operations
    size_t i, j;
    int tmp;
    for (i = 1; i < size; i++) {
        for (j = 1; j < size; j++) {
            count++;
            if (a[j] < a[j-1]) {
                tmp = a[j];
                a[j] = a[j-1];
                a[j-1] = tmp;
            }
        }
    }
    printf("Count of operations bubbleSort: %d\n", count);
}

// function bubble sort (New) (increase)
void bubbleSortNew(int *a, size_t size) {
    size_t i;
    int tmp;
    char flag;
    int count = 0; // number of operations
    do {
        flag = 0;
        for (i = 1; i < size; i++) {
            count++;
            if (a[i] < a[i-1]) {
                tmp = a[i];
                a[i] = a[i-1];
                a[i-1] = tmp;
                flag = 1;
            }
        }
    } while (flag);
    printf("Count of operations bubbleSortNew: %d\n", count);
}

// main function
int main() {
    const int SIZE = 10;
    int A[SIZE];
    
    printf("Array before sort:\n");
    randomInit(A, SIZE);
    printArray(A, SIZE);

    printf("\nArray after sort:\n");
    bubbleSort(A, SIZE);
    printArray(A, SIZE);
    
    printf("\nArray after sort:\n");
    bubbleSortNew(A, SIZE);
    printArray(A, SIZE);
    
    printf("\n");
    return 0;
}
