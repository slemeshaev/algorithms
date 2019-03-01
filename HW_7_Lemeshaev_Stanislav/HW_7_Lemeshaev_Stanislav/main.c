//
//  main.c
//  HW_7_Lemeshaev_Stanislav
//
//  Created by Станислав Лемешаев on 24/02/2019.
//  Copyright © 2019 Станислав Лемешаев. All rights reserved.
//
//  1. Написать функции, которые считывают матрицу смежности из файла и выводят ее на экран.
//  2. Написать рекурсивную функцию обхода графа в глубину.
//  3. Написать функцию обхода графа в ширину.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <math.h>

#include "libGraph.h"

void solution00(void);
void solution01(void);
void solution02(void);
void menu(void);

int main(int argc, char* argv[])
{
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
    printf("0. Завершение выполнения программы\n");
}

void descriptionTask(char *task)
{
    printf("\n##########################################\n");
    printf("\nУсловие задачи:\n");
    printf("%s", task);
}

void endTask()
{
    printf("\n##########################################\n\n");
}

// Задание 1: Написать функции, которые считывают матрицу смежности из файла и выводят ее на экран.
void solution00()
{
    descriptionTask("Написать функции, которые считывают матрицу смежности из файла и выводят ее на экран.\n");
    // Ввод данных
    char filename[255];
    
    printf("\nВведите файл, из которого будут считаны данные: ");
    scanf("%s", filename);
    
    int V = 0; // число вершин
    int E = 0; // число ребер
    
    int **graph = readMatrixFromFile(filename, &V, &E);
    printGraph(graph, V);
    freeGraph(graph, V);
    endTask();
}

// Задание 2: Написать функцию обхода графа в ширину.
void solution01()
{
    descriptionTask("Написать функцию обхода графа в ширину.\n");
    // Ввод данных
    char filename[255];
    
    printf("\nВведите файл, из которого будут считаны данные: ");
    scanf("%s", filename);
    
    int V = 0; // число вершин
    int E = 0; // число ребер
    
    int startVertex = 0;
    
    int **graph = readMatrixFromFile(filename, &V, &E);
    printGraph(graph, V);
    
    pQueue queue = (pQueue)malloc(sizeof(Queue));
    initQueue(queue);
    pQueue queueUsed = (pQueue)malloc(sizeof(Queue));
    initQueue(queueUsed);
    
    BFS(queue, queueUsed, startVertex, graph, V);
    
    free(queue);
    freeGraph(graph, V);
    endTask();
}

// Задание 3: Написать рекурсивную функцию обхода графа в глубину.
void solution02()
{
    descriptionTask("Написать рекурсивную функцию обхода графа в глубину.\n");
    // Ввод данных
    char filename[255];
    
    printf("\nВведите файл, из которого будут считаны данные: ");
    scanf("%s", filename);
    
    int V = 0; // число вершин
    int E = 0; // число ребер
    
    int startVertex = 0;
    
    int **graph = readMatrixFromFile(filename, &V, &E);
    printGraph(graph, V);
    
    pStack stack = (pStack)malloc(sizeof(Stack));
    initStack(stack);
    pQueue queueUsed = (pQueue)malloc(sizeof(Queue));
    initQueue(queueUsed);
    
    DFS(stack, queueUsed, startVertex, graph, V);
    
    free(stack);
    freeGraph(graph, V);
    endTask();
}
