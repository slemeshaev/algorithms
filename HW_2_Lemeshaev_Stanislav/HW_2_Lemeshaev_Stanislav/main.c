//
//  main.c
//  HW_2_Lemeshaev_Stanislav
//
//  Created by Станислав Лемешаев on 02/02/2019.
//  Copyright © 2019 Станислав Лемешаев. All rights reserved.
//
//2. Реализовать функцию возведения числа a в степень b:
//a. без рекурсии;
//b. рекурсивно;
//c. *рекурсивно, используя свойство четности степени.
//
//3. Исполнитель Калькулятор преобразует целое число, записанное на экране. У исполнителя две команды, каждой команде присвоен номер:
//Прибавь 1
//Умножь на 2
//Первая команда увеличивает число на экране на 1, вторая увеличивает это число в 2 раза. Сколько существует программ, которые число 3 преобразуют в число 20?
//а) с использованием массива;
//б) с использованием рекурсии.

#include <stdio.h>
int DecToBin(int n);
int cycleDegree(int a, int b);
int recDegree(int a, int b);

int main(int argc, const char * argv[]) {
//    printf("Enter your number: ");
//    int m;
//    scanf("%d", &m);
//    printf("Your binary number is %d\n", DecToBin(m));
    printf("Enter your number and degree: ");
    int x, y;
    scanf("%d%d", &x, &y);
    printf("%d to degree %d is %d\n", x, y, cycleDegree(x, y));
    printf("%d to degree %d is %d\n", x, y, recDegree(x, y));
    return 0;
}

// 1. Реализовать функцию перевода из десятичной системы в двоичную, используя рекурсию.
int DecToBin(int dec) {
    if (dec < 2)
        return dec;
    else
        return DecToBin(dec / 2) * 10 + dec % 2;
}

// 2. Реализовать функцию возведения числа a в степень b:

// c. *рекурсивно, используя свойство четности степени.

// a. без рекурсии;
int cycleDegree(int a, int b) {
    int res = 1;
    while (b > 0) {
        res = res * a;
        b--;
    }
    return res;
}

// b. рекурсивно;
int recDegree(int a, int b) {
    if (b == 0) {
        return 1;
    }
    if (b == 1) {
        return a;
    }
    else {
        return a * recDegree(a, b - 1);
    }
}
