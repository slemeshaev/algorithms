//
//  main.c
//  HW_8_Lemeshaev_Stanislav
//
//  Created by Станислав Лемешаев on 24/02/2019.
//  Copyright © 2019 Станислав Лемешаев. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <time.h>
#include <math.h>

void solution00(void);
void solution01(void);
void solution02(void);
void solution03(void);
void solution04(void);
void solution05(void);
void solution06(void);
void solution07(void);
void menu();

int main(int argc, char* argv[])
{
    setlocale(LC_ALL, "Rus");
    int select = 0;
    
    do
    {
        menu();
        scanf("%i", &select);
        switch (select)
        {
            case 1:
                solution00();
                break;
            case 2:
                solution01();
                break;
            case 3:
                solution02();
                break;
            case 4:
                solution03();
                break;
            case 5:
                solution04();
                break;
            case 6:
                solution05();
                break;
            case 7:
                solution06();
                break;
            case 8:
                solution07();
                break;
            case 0:
                printf("Программа закончила свое выполнение.\n");
                break;
            default:
                printf("Некорректный символ, введите значения из списка меню.\n");
        }
    } while (select != 0);
    system("pause");
    return 0;
}

void menu()
{
    printf("Меню выбора решения задания:\n\n");
    
    printf("1. Решение задачи 1\n");
    printf("2. Решение задачи 2\n");
    printf("3. Решение задачи 3\n");
    printf("4. Решение задачи 4\n");
    printf("5. Решение задачи 5\n");
    printf("6. Решение задачи 6\n");
    printf("7. Решение задачи 7\n");
    printf("8. Решение задачи 8\n");
    printf("0. Завершение выполнения программы\n");
}

void descriptionTask(char *task)
{
    printf("\n##########################################\n");
    printf("\nУсловие задачи:\n");
    printf(task);
}

void endTask()
{
    printf("\n##########################################\n\n");
}

// 100, 10000, 1000000
const int MAX_ELEMENTS = 10000;
const int MIN_VALUE = -1000;
const int MAX_VALUE = 1000;

void swap(int * p, int * q)
{
    int buf;
    buf = *p;
    *p = *q;
    *q = buf;
}

// Пирамидальная сортировка
int heapSort(int * a, int n)
{
    int i, m, t = n - 1, k;
    m = n / 2; // середина массива
    for (i = m; i >= 1; i--)
    {
        if (a[i - 1] < a[2 * i - 1]) // условие сравнения, которое соответствует пирам.    сортировке
            swap(&a[i - 1], &a[2 * i - 1]);
        if (2 * i < n && a[i - 1] < a[2 * i]) // если n-нечетное
            swap(&a[i - 1], &a[2 * i]);
    }
    k = 2 * m;
    swap(&a[0], &a[t]);
    t--;
    while (t > 0)
    {
        m = t / 2; // теперь на последнем месте стоит максимальный элемент, его больше не трогаем
        // и проходимся по коротким ветвям
        for (i = m; i >= 1; i--)
        {
            if (a[i - 1] < a[2 * i - 1])
                swap(&a[i - 1], &a[2 * i - 1]);
            if (2 * i < n && a[i - 1] < a[2 * i])
                swap(&a[i - 1], &a[2 * i]);
        }
        k += 2 * m;
        swap(&a[0], &a[t]);
        t--;
    }
    if (n > 0 && a[0] > a[1]) // самое последнее сравнение: нулевого с первым элементом
        swap(&a[0], &a[1]);
    k++;
    return k;
}

// Сортировка подсчетом
void countingSort(int *array, int n, int minValue, int maxValue)
{
    int k = maxValue - minValue + 1;
    int *countArr = (int *)malloc(k * sizeof(int));
    int i, j;
    for (i = 0; i < k; i++)
        countArr[i] = 0;
    
    for (i = 0; i < n; i++)
        countArr[array[i] - minValue]++;
    
    int b = 0;
    for (j = 0; j < k; j++)
    {
        int countRep = countArr[j];
        if (countRep > 0)
        {
            for (i = 0; i < countRep; i++)
            {
                array[b++] = j + minValue;
            }
        }
    }
    
    free(countArr);
}

// Быстрая сортировка
void quickSort(int *array, int first, int last, int *k)
{
    int i = first, j = last, x = array[(first + last) / 2];
    do
    {
        while (array[i] < x)
        {
            i++;
            *k = *k + 1;
        }
        while (array[j] > x)
        {
            j--;
            *k = *k + 1;
        }
        *k = *k + 1;
        if (i <= j)
        {
            *k = *k + 1;
            if (array[i] > array[j])
                swap(&array[i], &array[j]);
            i++;
            j--;
        }
        *k = *k + 1;
    } while (i <= j);
    *k = *k + 1;
    if (i < last)
        quickSort(array, i, last, k);
    *k = *k + 1;
    if (first < j)
        quickSort(array, first, j, k);
}

//Сортировка слиянием
void mergeSort(int *array, int l, int r, int *k)
{
    *k = *k + 1;
    if (l == r) return;        // границы сомкнулись
    int m = (l + r) / 2;    // определяем середину последовательности
    // и рекурсивно вызываем функцию сортировки для каждой половины
    mergeSort(array, l, m, k);
    mergeSort(array, m + 1, r, k);
    
    int lp = l;  // начало первого пути
    int rp = m + 1; // начало второго пути
    int i;
    int count = (r - l + 1);
    
    int *tmp = (int *)malloc(count*sizeof(int)); // дополнительный массив
    
    for (i = 0; i < count; i++) // для всех элементов дополнительного массива
    {
        // записываем в формируемую последовательность меньший из элементов двух путей
        // или остаток первого пути если j > r
        *k = *k + 1;
        if ((rp > r) || ((lp <= m) && (array[lp] < array[rp])))
        {
            tmp[i] = array[lp];
            lp++;
        }
        else
        {
            tmp[i] = array[rp];
            rp++;
        }
    }
    
    // переписываем сформированную последовательность в исходный массив
    for (i = 0; i < count; i++)
        array[l + i] = tmp[i];
    
    free(tmp);
}

typedef char * T;
typedef struct tagNode * pNode;

typedef struct tagNode
{
    int key;
    T data;
    pNode next;
} Node;

typedef struct tagList * pList;

typedef struct tagList
{
    pNode first;
    int size;
} List;

void pigeonholeSort(pNode *array, int n, int minValue, int maxValue)
{
    int k = maxValue - minValue + 1;
    pNode *countArr = (pNode *)malloc(k * sizeof(Node));
    int i;
    
    for (i = 0; i < k; i++)
        countArr[i] = NULL;
    
    for (i = 0; i < n; i++)
    {
        pNode node = countArr[array[i]->key - minValue];
        if (node == NULL)
            countArr[array[i]->key - minValue] = array[i];
        else
        {
            while (node->next != NULL)
                node = node->next;
            node->next = array[i];
        }
    }
    
    int    b = 0;
    
    for (i = 0; i < k; i++)
    {
        pNode p = countArr[i];
        while (p != NULL)
        {
            array[b] = p;
            b++;
            p = p->next;
            if(p != NULL)
                array[b]->next = NULL;
        }
    }
    free(countArr);
}

// Полный алгоритм пузырьковой сортировки
int bubbleSort(int *a, int n)
{
    int count = 0;
    int j = 0;
    for (int i = 0; i < n; i++)
    {
        for (j = 0; j < n - 1; j++)
        {
            // простая операция сравнения
            count++;
            if (a[j] > a[j + 1])
            {
                // простая операция перестановки
                count++;
                swap(&a[j], &a[j + 1]);
            }
        }
    }
    return count;
}

/* Шейкер-сортировка */
int shakerSort(int *a, int n)
{
    // границы и подсчет операций
    int left = 0,
    right = n - 1,
    count = 0;
    
    while (left <= right)
    {
        // прямой обход
        for (int i = left; i < right; i++)
        {
            count++;
            if (a[i] > a[i + 1]) {
                count++;
                swap(&a[i], &a[i + 1]);
            }
        }
        right--;
        // обратный обход
        for (int i = right; i > left; i--)
        {
            count++;
            if (a[i - 1] > a[i]) {
                count++;
                swap(&a[i], &a[i - 1]);
            }
        }
        left++;
    }
    return count;
}

// Сортировка Шелла
int shellsSort(int *a, int n)
{
    int i, j, k, count = 0;
    int t;
    for (k = n / 2; k > 0; k /= 2)
        for (i = k; i < n; i++)
        {
            t = a[i];
            for (j = i; j >= k; j -= k)
            {
                count++;
                if (t < a[j - k])
                    a[j] = a[j - k];
                else
                    break;
            }
            a[j] = t;
        }
    return count;
}

void showArray(FILE *fout, char* message, int *array, int N)
{
    fprintf(fout, "%s\n[", message);
    for (int i = 0; i < N; i++)
        fprintf(fout, ((i == 0) ? "%d" : ", %d"), array[i]);
    fprintf(fout, "]\n");
}

void showArrayNode(FILE *fout, char* message, pNode *array, int N)
{
    fprintf(fout, "%s\n[", message);
    for (int i = 0; i < N; i++)
        fprintf(fout, ((i == 0) ? "(%d, %c)" : ", (%d, %c)"), array[i]->key, array[i]->data);
    fprintf(fout, "]\n");
}

void showAnalitics(FILE *fout, int N, int k, double time)
{
    fprintf(fout, "\nКоличество элементов: %d\nКоличество сравнений: %d\nВремя: %lf\n", N, k, time);
    fprintf(fout, "n^2 = %lf\nn*log(n) = %lf\n\n", pow(N, 2), (N * log(N) / log(exp(1))));
}

int *getArrayFromFile(char *filename, int *N)
{
    FILE *fin = fopen(filename, "r");
    int count = 0;
    int *arr = (int *)malloc(MAX_ELEMENTS * sizeof(int)); // выделяем память
    while (fscanf(fin, "%d", &arr[count]) == 1)
        count++;
    fclose(fin);
    *N = count;
    return arr;
}

int *getArrayFromRand(int N)
{
    int *arr = (int *)malloc(MAX_ELEMENTS * sizeof(int)); // выделяем память
    for (int i = 0; i < N; i++)
        arr[i] = (rand() % (MAX_VALUE - MIN_VALUE + 1)) + MIN_VALUE;
    return arr;
}

// Задание 1: Реализовать сортировку подсчетом.
void solution00()
{
    descriptionTask("Реализовать сортировку подсчетом.\n");
    // Ввод данных
    int N = 0;
    // получение списка из файла
    //char filename[SHRT_MAX];
    //printf("\nВведите файл, из которого будут считаны данные: ");
    //scanf("%s", filename);
    //int *arr = getArrayFromFile(filename, &N);
    
    // рандом генератор
    N = MAX_ELEMENTS;
    int *arr = getArrayFromRand(N);
    
    FILE *fout = fopen("outputCounting.txt", "w");
    showArray(fout, "Исходный массив:", arr, N);
    double t1 = 0, t2 = 0;
    t1 = clock();
    countingSort(arr, N, MIN_VALUE, MAX_VALUE);
    t2 = clock();
    showAnalitics(fout, N, 0, t2 - t1);
    showArray(fout, "Отсортированный массив:", arr, N);
    fclose(fout);
    free(arr);
    endTask();
}

// Задание 2: Реализовать быструю сортировку.
void solution01()
{
    descriptionTask("Реализовать быструю сортировку.\n");
    // Ввод данных
    int N = 0;
    // получение списка из файла
    //char filename[SHRT_MAX];
    //printf("\nВведите файл, из которого будут считаны данные: ");
    //scanf("%s", filename);
    //int *arr = getArrayFromFile(filename, &N);
    
    // рандом генератор
    N = MAX_ELEMENTS;
    int *arr = getArrayFromRand(N);
    
    FILE *fout = fopen("outputQuick.txt", "w");
    showArray(fout, "Исходный массив:", arr, N);
    int k = 0;
    time_t start, end;
    time(&start);
    quickSort(arr, 0, N - 1, &k);
    time(&end);
    showAnalitics(fout, N, k, difftime(end, start));
    showArray(fout, "Отсортированный массив:", arr, N);
    fclose(fout);
    free(arr);
    endTask();
}

// Задание 3: *Реализовать сортировку слиянием.
void solution02()
{
    descriptionTask("*Реализовать сортировку слиянием.\n");
    // Ввод данных
    int N = 0;
    // получение списка из файла
    //char filename[SHRT_MAX];
    //printf("\nВведите файл, из которого будут считаны данные: ");
    //scanf("%s", filename);
    //int *arr = getArrayFromFile(filename, &N);
    
    // рандом генератор
    N = MAX_ELEMENTS;
    int *arr = getArrayFromRand(N);
    
    FILE *fout = fopen("outputMerge.txt", "w");
    showArray(fout, "Исходный массив:", arr, N);
    int k = 0;
    time_t start, end;
    time(&start);
    mergeSort(arr, 0, N-1, &k);
    time(&end);
    showAnalitics(fout, N, k, difftime(end, start));
    showArray(fout, "Отсортированный массив:", arr, N);
    fclose(fout);
    free(arr);
    endTask();
}

// Задание 4: **Реализовать алгоритм сортировки со списком.
void solution03()
{
    descriptionTask("**Реализовать алгоритм сортировки со списком.\n");
    // Ввод данных
    int N = 0;
    // получение списка из файла
    //char filename[SHRT_MAX];
    //printf("\nВведите файл, из которого будут считаны данные: ");
    //scanf("%s", filename);
    //int *arr = getArrayFromFile(filename, &N);
    
    // рандом генератор
    N = MAX_ELEMENTS;
    int *arr = getArrayFromRand(N);
    
    int i;
    pNode *arrNodes = (pNode *)malloc(N * sizeof(Node));
    for (i = 0; i < N; i++)
    {
        pNode node = (pNode)malloc(sizeof(Node));
        node->key = arr[i];
        T randData = (char *)malloc(sizeof(char));
        *randData = (char)(rand() % 255);
        node->data = randData;
        node->next = NULL;
        arrNodes[i] = node;
    }
    
    FILE *fout = fopen("outputPigeOnHole.txt", "w");
    showArrayNode(fout, "Исходный массив:", arrNodes, N);
    int k = 0;
    time_t start, end;
    time(&start);
    pigeonholeSort(arrNodes, N, MIN_VALUE, MAX_VALUE);
    time(&end);
    showAnalitics(fout, N, k, difftime(end, start));
    showArrayNode(fout, "Отсортированный массив:", arrNodes, N);
    fclose(fout);
    for (i = 0; i < N; i++)
    {
        free(arrNodes[i]->data);
        free(arrNodes[i]);
    }
    free(arrNodes);
    free(arr);
    endTask();
}

// Задание 5: Реализовать сортировку Пузырьком
void solution04()
{
    descriptionTask("*Реализовать сортировку Пузырьком.\n");
    // Ввод данных
    int N = 0;
    // получение списка из файла
    //char filename[SHRT_MAX];
    //printf("\nВведите файл, из которого будут считаны данные: ");
    //scanf("%s", filename);
    //int *arr = getArrayFromFile(filename, &N);
    
    // рандом генератор
    N = MAX_ELEMENTS;
    int *arr = getArrayFromRand(N);
    
    FILE *fout = fopen("outputBubble.txt", "w");
    showArray(fout, "Исходный массив:", arr, N);
    time_t start, end;
    time(&start);
    int res = bubbleSort(arr, N);
    time(&end);
    showAnalitics(fout, N, res, difftime(end, start));
    showArray(fout, "Отсортированный массив:", arr, N);
    fclose(fout);
    free(arr);
    endTask();
}

// Задание 6: Реализовать сортировку Шейкерную
void solution05()
{
    descriptionTask("*Реализовать сортировку Шейкерную.\n");
    // Ввод данных
    int N = 0;
    // получение списка из файла
    //char filename[SHRT_MAX];
    //printf("\nВведите файл, из которого будут считаны данные: ");
    //scanf("%s", filename);
    //int *arr = getArrayFromFile(filename, &N);
    
    // рандом генератор
    N = MAX_ELEMENTS;
    int *arr = getArrayFromRand(N);
    
    FILE *fout = fopen("outputShaker.txt", "w");
    showArray(fout, "Исходный массив:", arr, N);
    time_t start, end;
    time(&start);
    int res = shakerSort(arr, N);
    time(&end);
    showAnalitics(fout, N, res, difftime(end, start));
    showArray(fout, "Отсортированный массив:", arr, N);
    fclose(fout);
    free(arr);
    endTask();
}

// Задание 7: Реализовать сортировку Шелла
void solution06()
{
    descriptionTask("*Реализовать сортировку Шелла.\n");
    // Ввод данных
    int N = 0;
    // получение списка из файла
    //char filename[SHRT_MAX];
    //printf("\nВведите файл, из которого будут считаны данные: ");
    //scanf("%s", filename);
    //int *arr = getArrayFromFile(filename, &N);
    
    // рандом генератор
    N = MAX_ELEMENTS;
    int *arr = getArrayFromRand(N);
    
    FILE *fout = fopen("outputShells.txt", "w");
    showArray(fout, "Исходный массив:", arr, N);
    time_t start, end;
    time(&start);
    int res = shellsSort(arr, N);
    time(&end);
    showAnalitics(fout, N, res, difftime(end, start));
    showArray(fout, "Отсортированный массив:", arr, N);
    fclose(fout);
    free(arr);
    endTask();
}

// Задание 8: Реализовать Пирамидальная сортировка
void solution07()
{
    descriptionTask("*Реализовать Пирамидальная сортировка\n");
    // Ввод данных
    int N = 0;
    // получение списка из файла
    //char filename[SHRT_MAX];
    //printf("\nВведите файл, из которого будут считаны данные: ");
    //scanf("%s", filename);
    //int *arr = getArrayFromFile(filename, &N);
    
    // рандом генератор
    N = MAX_ELEMENTS;
    int *arr = getArrayFromRand(N);
    
    FILE *fout = fopen("outputHeap.txt", "w");
    showArray(fout, "Исходный массив:", arr, N);
    time_t start, end;
    time(&start);
    int res = heapSort(arr, N);
    time(&end);
    showAnalitics(fout, N, res, difftime(end, start));
    showArray(fout, "Отсортированный массив:", arr, N);
    fclose(fout);
    free(arr);
    endTask();
}
