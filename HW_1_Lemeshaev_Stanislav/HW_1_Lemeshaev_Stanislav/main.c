//
//  main.c
//  HW_1_Lemeshaev_Stanislav
//
//  Created by Станислав Лемешаев on 01/02/2019.
//  Copyright © 2019 Станислав Лемешаев. All rights reserved.
//

#include <stdio.h>
#include <math.h>
#include <stdbool.h>

void menu();

void solution1();
void solution2();
void solution3();
void solution4();
void solution5();
void solution6();
void solution7();
void solution8();
void solution9();
void solution10();
void solution11();

int main() {
    int sel = 0;
    do {
        printf("\n\nList tasks");
        menu();
        printf("\nEnter task number: ");
        scanf("%i", &sel);
        switch (sel) {
            case 1:
                solution1();
                break;
            case 2:
                solution2();
                break;
            case 3:
                solution3();
                break;
            case 4:
                solution4();
                break;
            case 5:
                solution5();
                break;
            case 6:
                solution6();
                break;
            case 7:
                solution7();
                break;
            case 8:
                solution8();
                break;
            case 9:
                solution9();
                break;
            case 10:
                solution10();
                break;
            case 11:
                solution11();
                break;
            case 0:
                printf("Bye-bye\n");
                break;
            default:
                printf("Wrong selected\n");
        }
    } while (sel != 0);
    
    return 0;
}

void menu(){
    printf("\nTask_1\n");
    printf("Task_2\n");
    printf("Task_3\n");
    printf("Task_4\n");
    printf("Task_5\n");
    printf("Task_6\n");
    printf("Task_7\n");
    printf("Task_8\n");
    printf("Task_9\n");
    printf("Task_10\n");
    printf("Task_11\n");
    printf("\n0 - exit\n");
}

// Решение задачи 1.
void solution1(){
    printf("\n1. Ввести вес и рост человека. Рассчитать и вывести индекс массы тела по формуле I = m /(h * h); где m - масса тела в килограммах, h - рост в метрах.");
    printf("\nSolution task 1\n");
    
    printf("Enter a height: ");
    int height;
    scanf("%i", &height);
    
    printf("Enter a weight: ");
    int weight;
    scanf("%i", &weight);
    
    double I = weight / (pow(height, 2));
    
    printf("\nBody mass index %g\n", I);
}

// Решение задачи 2.
void solution2(){
    printf("\n2. Найти максимальное из четырех чисел. Массивы не использовать.\n");
    
    printf("\nSolution task 2\n");
    
    printf("Enter 4 numbers to find the maximum: ");
    int a, b, c, d;
    scanf("%d%d%d%d", &a, &b, &c, &d);
    if ((a > b) && (a > c) && (a > d)){
        printf("Max number is %d", a);
    }
    else if ((b > c) && (b > d)) {
        printf("Max number is %d", b);
    }
    else if (c > d) {
        printf("Max number is %d", c);
    }
    else {
        printf("Max number is %d", d);
    }
}

// Решение задачи 3.
void solution3(){
    printf("\n3. Написать программу обмена значениями двух целочисленных переменных. (без использования третьей переменной)\n");
    
    printf("\nSolution task 3\n");
    
    printf("Enter 2 numbers to exchange: ");
    int a, b;
    scanf("%d%d", &a, &b);
    printf("\nInitial values: %d %d", a, b);
    a = a ^ b;
    b = b ^ a;
    a = a ^ b;
    printf("\nСhanged values: %d %d", a, b);
}

// Решение задачи 4.
void solution4(){
    printf("\n4. Написать программу нахождения корней заданного квадратного уравнения\n");
    
    printf("\nSolution task 4\n");
    
    printf("Enter the coefficients of the quadratic equation a, b, c: ");
    double a, b, c;
    scanf("%lg%lg%lg", &a, &b, &c);
    
    double d = pow(b, 2) + 4 * a * c;
    
    if (d > 0) {
        double x1 = (-b + sqrt(d)) / (2 * a);
        double x2 = (-b - sqrt(d)) / (2 * a);
        printf("x1 = %lg, x2 = %lg", x1, x2);
    }
    else if (d == 0) {
        double x = -b / (2 * a);
        printf("x = %lg", x);
    }
    else {
        printf("There is no root equation.");
    }
}

// Решение задачи 5.
void solution5(){
    printf("\n5. С клавиатуры вводится номер месяца. Требуется определить, к какому времени года он относится\n");
    
    printf("\nSolution task 5\n");
    
    printf("Еnter month number: ");
    int n;
    scanf("%d", &n);
    switch (n) {
        case 12: case 1: case 2:
            printf("Winter");
            break;
        case 3: case 4: case 5:
            printf("Spring");
            break;
        case 6: case 7: case 8:
            printf("Summer");
            break;
        case 9: case 10: case 11:
            printf("Autumn");
            break;
        default:
            printf("There is no such month numbern");
    }
}

// Решение задачи 6.
void solution6(){
    printf("\n6. Ввести возраст человека (от 1 до 150 лет) и вывести его вместе с последующим словом год, года или лет.\n");
    
    printf("\nSolution task 6\n");
    
    printf("Сколько вам лет? ");
    int n;
    scanf("%d", &n);
    
    int dec = n % 10;
    
    switch (dec) {
        case 1:
            printf("Вам %d год.", n);
            break;
        case 2: case 3: case 4:
            printf("Вам %d года.", n);
            break;
        case 0: case 5: case 6: case 7: case 8: case 9:
            printf("Вам %d лет.", n);
            break;
        default:
            printf("Error");
    }
    
}

// Решение задачи 7.
void solution7(){
    printf("\n7. С клавиатуры вводятся числовые координаты двух полей шахматной доски (x1, y1, x2, y2). Требуется определить, относятся ли поля к одному цвету или нет\n");
    
    printf("\nSolution task 7\n");
    
    printf("Enter the coordinates of the first point: ");
    int x1, y1;
    scanf("%d%d", &x1, &y1);
    
    printf("Enter the coordinates of the second point: ");
    int x2, y2;
    scanf("%d%d", &x2, &y2);
    
    if ((x1 + x2) % 2 == (y1 + y2) % 2) {
        printf("Color is same!");
    }
    else {
        printf("Color is different!");
    }
    
}

// Решение задачи 8.
void solution8(){
    printf("\n8. Ввести a и b и вывести квадраты и кубы чисел от a до b.\n");
    
    printf("\nSolution task 8\n");
    
    printf("Enter two numbers a and b: ");
    int a, b;
    scanf("%d%d", &a, &b);
    
    printf("Square table:\n");
    for (int i = a; i <= b; ++i) {
        printf("%d = %d\n", i, i * i);
    }
    
    printf("\nCube table:\n");
    for (int i = a; i <= b; ++i) {
        printf("%d = %d\n", i, i * i * i);
    }
    
}

// Решение задачи 9.
void solution9(){
    printf("\n9. Даны целые положительные числа N и K. Используя только операции сложения и вычитания, найти частное от деления нацело N на K, а также остаток от этого деления.\n");
    
    printf("\nSolution task 9\n");
    
    printf("Enter two positive numbers n and k: ");
    int n, k;
    scanf("%d%d", &n, &k);
    
    int res = 0;
    while (n >= k) {
        n = n - k;
        res++;
        if (n == 0)
            break;
    }
    
    printf("Div: %d\n", res);
    printf("Mod: %d\n", n);
    
}

// Решение задачи 10.
void solution10(){
    printf("\n10. Дано целое число (N > 0). С помощью операций деления нацело и взятия остатка от деления определить, имеются ли в записи числа N нечетные цифры. Если имеются, то вывести True, если нет — вывести False.\n");
    
    printf("\nSolution task 10\n");
    
    printf("Enter a number: ");
    int n;
    scanf("%d", &n);
    
    bool flag = 0;
    
    while (n > 0) {
        if ((n % 10) % 2 != 0) {
            flag = 1; break;
        }
        n = n / 10;
    }
    
    if (flag == 1) {
        printf("True");
    }
    else {
        printf("False");
    }
}

// Решение задачи 11.
void solution11(){
    printf("\n11. С клавиатуры вводятся числа, пока не будет введен 0. Подсчитать среднее арифметическое всех положительных четных чисел, оканчивающихся на 8.\n");
    
    printf("\nSolution task 11\n");
    
    int n;       // элемент последовательности
    double sum = 0; // сумма элементов последовательности
    int k = 0;   // количество элементов последовательности
    printf("Для остановки ввода последовательности элементов, введите 0\n");
    while (1) {
        printf("Enter a number: ");
        scanf("%d", &n);
        sum = sum + n;
        if (n == 0)
            break;
        k++;
    }
    printf("Avarage = %lg", sum / k);
    
}

// 12. Написать функцию нахождения максимального из трех чисел.
double maxNumber(int a, int b, int c) {
    if ((a > b) && (a > c)) {
        return a;
    }
    else if (b > c) {
        return b;
    }
    else {
        return c;
    }
}
