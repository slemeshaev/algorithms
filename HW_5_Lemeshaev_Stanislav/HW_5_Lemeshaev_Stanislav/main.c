//
//  main.c
//  HW_5_Lemeshaev_Stanislav
//
//  Created by Станислав Лемешаев on 19/02/2019.
//  Copyright © 2019 Станислав Лемешаев. All rights reserved.
//

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <math.h>

void solution00();
void solution01();
void solution02();
void solution03();
void solution04();

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

#define T char

// тип указателя на ноду
typedef struct tagNode * pNode;

// тип ноды
typedef struct tagNode
{
    T value;
    pNode next;
} Node;

// тип структуры стека
typedef struct tagStack
{
    pNode head;
    int size;
    int maxSize;
} Stack;

// рабочий стек
Stack stack00;

// добавить элемент в стек
void push(Stack *stack, T value)
{
    if (stack->size == stack->maxSize)
    {
        printf("Стек заполнен, необходимо увеличить размер стека.\n");
        return;
    }
    pNode tmp = (pNode)malloc(sizeof(Node));
    // Задание 2: Добавить в программу «реализация стека на основе односвязного списка» проверку на выделение памяти.
    //    Если память не выделяется, то выводится соответствующее сообщение.
    //    Постарайтесь создать ситуацию, когда память не будет выделяться (добавлением большого количества данных). Не удалось, полагаю это из-за ограничения в 2ГБ на приложение для Windows 10.
    if (tmp == NULL) // если выделение памяти не выполнилось
    {
        printf("Выделение памяти для нового элемента не удалось.\n");
        return;
    }
    tmp->value = value;
    tmp->next = stack->head;
    stack->head = tmp;
    stack->size++;
}

// вытаскивание последнего элемента из стека с возвратом значения
void pop(Stack *stack, T* value)
{
    if (stack->size == 0)
    {
        printf("Стек пуст, необходимо добавить элементы.\n");
        return;
    }
    pNode next = NULL;
    *value = stack->head->value;
    next = stack->head;
    stack->head = stack->head->next;
    free(next);
    stack->size--;
}

// возврат значения последнего элемента без удаления элемента
void peekStack(Stack *stack, T* value)
{
    if (stack->size == 0)
    {
        printf("Стек пуст, необходимо добавить элементы.\n");
        return;
    }
    *value = stack->head->value;
}

void printStack(Stack *stack)
{
    pNode current = stack->head;
    while (current != NULL)
    {
        printf("%i", current->value);
        current = current->next;
    }
}

void initStack(Stack *stack)
{
    stack->maxSize = 100;
    stack->size = 0;
    stack->head = NULL;
}

void convertToBinRec(Stack *stack, long n)
{
    if (n <= 0)
        return;
    push(stack, n % 2);
    convertToBinRec(stack, n / 2);
}

void printBin(Stack *stack)
{
    while (stack->size > 0)
    {
        T value;
        pop(stack, &value);
        printf("%i", value);
    }
}

// Задание 1: Реализовать перевод из десятичной в двоичную систему счисления с использованием стека.
void solution00()
{
    descriptionTask("Реализовать перевод из десятичной в двоичную систему счисления с использованием стека.\n");
    // Ввод данных
    initStack(&stack00);
    
    int number;
    printf("Введите число для перевода в двоичную систему: ");
    scanf("%d", &number);
    
    // Решение
    printf("Результат: \n");
    convertToBinRec(&stack00, number);
    printBin(&stack00);
    
    endTask();
}

int isNumber(char *str)
{
    int i = 0;
    while (str[i] != '\0')
        if (!isdigit(str[i++]))
            return 0;
    return 1;
}

int indexOf(char *str, char elem)
{
    int i = 0;
    while (str[i] != '\0')
    {
        if (str[i] == elem)
            return i;
        i++;
    }
    return -1;
}

// рабочий стек
Stack stack01;

// Задание 3: Написать программу, которая определяет, является ли введенная скобочная последовательность правильной. Примеры правильных скобочных выражений: (), ([])(), {}(), ([{}]), неправильных — )(, ())({), (, ])}), ([(]) для скобок [,(,{.
//                Например: (2 + (2 * 2)) или[2 / {5 * (4 + 7)}]
void solution01()
{
    descriptionTask("Написать программу, которая определяет, является ли введенная скобочная последовательность правильной. Примеры правильных скобочных выражений: (), ([])(), {}(), ([{}]), неправильных — )(, ())({), (, ])}), ([(]) для скобок [,(,{.\n\tНапример: (2 + (2 * 2)) или[2 / {5 * (4 + 7)}]\n");
    // Ввод данных
    char buffer[100] = "[ 2 / { 5 * ( 4 + 7 ) } ] ( )";
    printf("Тестовая последовательность: ");
    for (int i = 0; i < strlen(buffer); i++)
    {
        printf("%c", buffer[i]);
    }
    printf("\n");
    //gets_s(&buffer);
    int res = 0;
    
    initStack(&stack01);
    
    for (int i = 0; i < strlen(buffer); i++)
    {
        char elem[100];
        int j = 0;
        while (buffer[i] != ' ' && buffer[i] != '\0')
        {
            elem[j++] = buffer[i++];
        }
        elem[j] = '\0';
        T value;
        
        switch (elem[0])
        {
            case '[':
                push(&stack01, elem[0]);
                res++;
                break;
            case ']':
                pop(&stack01, &value);
                if (value == '[')
                    res--;
                break;
            case '{':
                push(&stack01, elem[0]);
                res++;
                break;
            case '}':
                pop(&stack01, &value);
                if (value == '{')
                    res--;
                break;
            case '(':
                push(&stack01, elem[0]);
                res++;
                break;
            case ')':
                pop(&stack01, &value);
                if (value == '(')
                    res--;
                break;
                
            default:
                break;
        }
    }
    
    // Решение
    printf("Результат: \n");
    
    printf(res > 0 ? "Некоррекная последовательность\n" : "Корректная последовательность\n");
    endTask();
}

// тип структуры листа
typedef struct tagList
{
    pNode head;
    int size;
    int maxSize;
} List;

typedef List * pList;

void addElementAfter(pList lst, pNode elemAfter, pNode elem)
{
    pNode current = lst->head;
    while (current != NULL)
    {
        if (current == elemAfter)
        {
            elem->next = current->next;
            current->next = elem;
            lst->size++;
            return;
        }
        current = current->next;
    }
}

void addElementBefore(pList lst, pNode elemBefore, pNode elem)
{
    pNode current = lst->head;
    
    if (elemBefore == current)
    {
        elem->next = current;
        lst->head = elem;
        lst->size++;
        return;
    }
    
    while (current && current->next != elemBefore)
        current = current->next;
    
    if (current)
    {
        addElementAfter(lst, current, elem);
    }
}

void addElement(pList lst, T value)
{
    if (lst->size == lst->maxSize)
    {
        printf("Лист заполнен, необходимо увеличить размер листа.\n");
        return;
    }
    pNode tmp = (pNode)malloc(sizeof(Node));
    // Задание 2: Добавить в программу «реализация стека на основе односвязного списка» проверку на выделение памяти.
    //    Если память не выделяется, то выводится соответствующее сообщение.
    //    Постарайтесь создать ситуацию, когда память не будет выделяться (добавлением большого количества данных). Не удалось, полагаю это из-за ограничения в 2ГБ на приложение для Windows 10.
    if (tmp == NULL) // если выделение памяти не выполнилось
    {
        printf("Выделение памяти для нового элемента не удалось.\n");
        return;
    }
    tmp->value = value;
    tmp->next = lst->head;
    lst->head = tmp;
    lst->size++;
}

void deleteElement(pList lst, pNode elem)
{
    pNode current = lst->head;
    while (current && current->next != elem)
        current = current->next;
    if (current)
    {
        current->next = elem->next;
        elem->next = NULL;
        free(elem);
        lst->size--;
    }
}

void initList(pList lst)
{
    lst->maxSize = 100;
    lst->size = 0;
    lst->head = NULL;
}

// копирование от начала до конца поэлементно(для повторения порядка следования)
void copyList(pList lst, pList newList)
{
    initList(newList);
    pNode copyNode = (pNode)malloc(sizeof(Node));
    if (copyNode == NULL) // если выделение памяти не выполнилось
    {
        printf("Выделение памяти для нового элемента не удалось.\n");
    }
    pNode current = lst->head;
    copyNode->value = current->value;
    copyNode->next = NULL;
    newList->head = copyNode;
    newList->size++;
    current = current->next;
    
    while (current)
    {
        pNode tmp = (pNode)malloc(sizeof(Node));
        // Задание 2: Добавить в программу «реализация стека на основе односвязного списка» проверку на выделение памяти.
        //    Если память не выделяется, то выводится соответствующее сообщение.
        //    Постарайтесь создать ситуацию, когда память не будет выделяться (добавлением большого количества данных). Не удалось, полагаю это из-за ограничения в 2ГБ на приложение для Windows 10.
        if (tmp == NULL) // если выделение памяти не выполнилось
        {
            printf("Выделение памяти для нового элемента не удалось.\n");
        }
        tmp->value = current->value;
        tmp->next = NULL;
        copyNode->next = tmp;
        copyNode = tmp;
        newList->size++;
        current = current->next;
    }
}

void clearList(pList lst)
{
    pNode current = lst->head;
    while (current)
    {
        lst->head = current->next;
        free(current);
        current = NULL;
        current = lst->head;
        lst->size--;
    }
}

void printList(pList lst)
{
    pNode current = lst->head;
    while (current != NULL)
    {
        printf("%i\n", current->value);
        current = current->next;
    }
}

// Задание 4: *Создать функцию, копирующую односвязный список (то есть создает в памяти копию односвязного списка, не удаляя первый список).
void solution02()
{
    descriptionTask("*Создать функцию, копирующую односвязный список (то есть создает в памяти копию односвязного списка, не удаляя первый список).\n");
    // Ввод данных
    List list;
    
    initList(&list);
    addElement(&list, 32);
    addElement(&list, 44);
    addElement(&list, 26);
    addElement(&list, 75);
    addElement(&list, 13);
    
    // Решение
    printf("Результат: \n");
    
    // отображение до очищения
    printList(&list);
    printf("\n");
    
    // копирование
    List copyLst;
    copyList(&list, &copyLst);
    // очистка первого списка
    clearList(&list);
    
    // отображение второго списка с пустым первым
    printList(&copyLst);
    clearList(&copyLst);
    
    printf("\n");
    
    endTask();
}

// тип структуры очередь
typedef struct tagQueue
{
    pNode front;
    pNode back;
    int size;
    int maxSize;
} Queue;

typedef Queue * pQueue;

// возврат значения первого элемента без удаления элемента
void Peek(pQueue queue, T* value)
{
    if (queue->size == 0)
    {
        printf("Очередь пуста, необходимо добавить элементы.\n");
        return;
    }
    *value = queue->front->value;
}

// добавление в конец очереди
void Enqueue(pQueue queue, T value)
{
    if (queue->size == queue->maxSize)
    {
        printf("Очередь заполнена, необходимо увеличить размер очереди.\n");
        return;
    }
    pNode tmp = (pNode)malloc(sizeof(Node));
    // Задание 2: Добавить в программу «реализация стека на основе односвязного списка» проверку на выделение памяти.
    //    Если память не выделяется, то выводится соответствующее сообщение.
    //    Постарайтесь создать ситуацию, когда память не будет выделяться (добавлением большого количества данных). Не удалось, полагаю это из-за ограничения в 2ГБ на приложение для Windows 10.
    if (tmp == NULL) // если выделение памяти не выполнилось
    {
        printf("Выделение памяти для нового элемента не удалось.\n");
        return;
    }
    tmp->value = value;
    if (queue->size == 0)
        queue->front = tmp;
    else
    {
        queue->back->next = tmp;
        tmp->next = NULL;
    }
    queue->back = tmp;
    queue->size++;
}

// возврат значения с удаление элемента из очереди
void Dequeue(pQueue queue, T* value)
{
    if (queue->size == 0)
    {
        printf("Очередь пуста, необходимо добавить элементы.\n");
    }
    pNode first = NULL;
    *value = queue->front->value;
    first = queue->front;
    queue->front = queue->front->next;
    free(first);
    queue->size--;
}

// печать очереди с первого элемента
void printQueue(pQueue queue)
{
    pNode current = queue->front;
    while (current != NULL)
    {
        printf("%i\n", current->value);
        current = current->next;
    }
}

void printCharQueue(pQueue queue)
{
    pNode current = queue->front;
    while (current != NULL)
    {
        printf("%c\n", current->value);
        current = current->next;
    }
}

// инициализация очереди
void initQueue(pQueue queue)
{
    queue->maxSize = 100;
    queue->size = 0;
    queue->front = NULL;
    queue->back = NULL;
}

// очистка очереди
void clearQueue(pQueue queue)
{
    pNode current = queue->front;
    while (current)
    {
        queue->front = current->next;
        free(current);
        current = NULL;
        current = queue->front;
        queue->size--;
    }
}

int checkMinusPlus(Stack *stack, pQueue queue, char elem)
{
    int isExit = 0;
    if (stack->size > 0)
    {
        T prev;
        peekStack(stack, &prev);
        if (prev == '(')
        {
            push(stack, elem);
            isExit = 1;
        }
        else
        {
            pop(stack, &prev);
            Enqueue(queue, prev);
        }
    }
    else
    {
        push(stack, elem);
        isExit = 1;
    }
    return isExit;
}

int checkMultiplyDivide(Stack *stack, pQueue queue, char elem)
{
    int isExit = 0;
    if (stack->size > 0)
    {
        T prev;
        peekStack(stack, &prev);
        if (indexOf("(+-", prev))
        {
            push(stack, elem);
            isExit = 1;
        }
        else
        {
            pop(stack, &prev);
            Enqueue(queue, prev);
        }
    }
    else
    {
        push(stack, elem);
        isExit = 1;
    }
    return isExit;
}

int checkLeftBracket(Stack *stack, pQueue queue, char elem)
{
    push(stack, elem);
    return 1;
}

int checkRightBracket(Stack *stack, pQueue queue)
{
    int isExit = 0;
    if (stack->size > 0)
    {
        T prev;
        pop(stack, &prev);
        if (prev != '(')
            Enqueue(queue, prev);
        else
            isExit = 1;
    }
    else
    {
        printf("Некорректная последовательность\n");
        isExit = -1;
    }
    return isExit;
}

// Задание 5:  **Реализовать алгоритм перевода из инфиксной записи арифметического выражения в постфиксную.
void solution03()
{
    descriptionTask(" **Реализовать алгоритм перевода из инфиксной записи арифметического выражения в постфиксную.\n");
    // Ввод данных
    
    int res = 0;
    
    Queue queue;
    initQueue(&queue);
    
    Stack stack02;
    initStack(&stack02);
    // Ввод данных
    char buffer[100] = "( 8 + 2 * 5 ) / ( 1 + 3 * 2 - 4 )"; //"(1+2)*4"
    printf("Тестовая последовательность: ");
    for (int i = 0; i < strlen(buffer); i++)
    {
        printf("%c", buffer[i]);
    }
    printf("\n");
    
    // Решение
    printf("Результат: \n");
    
    int isExit = 0;
    
    for (int i = 0; i < strlen(buffer); i++)
    {
        if (isExit == -1)
            break;
        
        isExit = 0;
        
        char elem[100];
        int j = 0;
        while (buffer[i] != ' ' && buffer[i] != '\0')
        {
            elem[j++] = buffer[i++];
        }
        elem[j] = '\0';
        
        if (isNumber(elem))
        {
            Enqueue(&queue, *elem);
        }
        else
        {
            while (!isExit)
            {
                switch (elem[0])
                {
                    case '+':
                        isExit = checkMinusPlus(&stack02, &queue, elem[0]);
                        break;
                    case '-':
                        isExit = checkMinusPlus(&stack02, &queue, elem[0]);
                        break;
                    case '*':
                        isExit = checkMultiplyDivide(&stack02, &queue, elem[0]);
                        break;
                    case '/':
                        isExit = checkMultiplyDivide(&stack02, &queue, elem[0]);
                        break;
                    case '(':
                        isExit = checkLeftBracket(&stack02, &queue, elem[0]);
                        break;
                    case ')':
                        isExit = checkRightBracket(&stack02, &queue);
                        break;
                    default:
                        break;
                }
            }
        }
        
        if (buffer[i] == '\0')
        {
            if (stack02.size > 0)
            {
                T prev;
                pop(&stack02, &prev);
                if (prev == '(')
                {
                    res = -1;
                    printf("Некорректная последовательность\n");
                    break;
                }
                Enqueue(&queue, prev);
            }
        }
    }
    
    printCharQueue(&queue);
    
    endTask();
}

// Задание 6: *Реализовать очередь.
void solution04()
{
    descriptionTask(" *Реализовать очередь.\n");
    // Ввод данных
    Queue queue;
    initQueue(&queue);
    
    // Решение
    printf("Результат: \n");
    Enqueue(&queue, 1);
    Enqueue(&queue, 2);
    Enqueue(&queue, 3);
    Enqueue(&queue, 4);
    Enqueue(&queue, 5);
    Enqueue(&queue, 6);
    Enqueue(&queue, 7);
    
    T value;
    
    printQueue(&queue);
    printf("\n");
    // вытаскивания первого элемента
    Dequeue(&queue, &value);
    printQueue(&queue);
    printf("\n");
    
    // вытаскивания еще одного первого элемента
    Dequeue(&queue, &value);
    printQueue(&queue);
    printf("\n");
    
    // просмотр еще одного первого элемента
    
    Peek(&queue, &value);
    printQueue(&queue);
    printf("\n");
    
    clearQueue(&queue);
    
    endTask();
}
