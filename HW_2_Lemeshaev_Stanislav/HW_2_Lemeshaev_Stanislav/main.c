//
//  main.c
//  HW_2_Lemeshaev_Stanislav
//
//  Created by Станислав Лемешаев on 02/02/2019.
//  Copyright © 2019 Станислав Лемешаев. All rights reserved.

#include <stdio.h>
int convertDecToBin(int n);
int cyclePower(int a, int b);
int recPower(int a, int b);
int quickPower(int a, int b);
int quickPowerRec(int a, int b);

int main(int argc, const char * argv[]) {
    // 1. Реализация первой задачи
    printf("Enter your number: ");
    int m;
    scanf("%d", &m);
    printf("Your binary number is %d\n", convertDecToBin(m));
    
    // 2. Реализация второй задачи
    printf("Enter your number and power: ");
    int x, y;
    scanf("%d%d", &x, &y);
    // a. без рекурсии;
    printf("%d to degree %d is %d\n", x, y, cyclePower(x, y));
    // b. рекурсивно;
    printf("%d to degree %d is %d\n", x, y, recPower(x, y));
    // используя свойство четности степени
    printf("%d to degree %d is %d\n", x, y, quickPower(x, y));
    // c. *рекурсивно, используя свойство четности степени
    printf("%d to degree %d is %d\n", x, y, quickPowerRec(x, y));
    return 0;
}

// 1. Реализовать функцию перевода из десятичной системы в двоичную, используя рекурсию.
int convertDecToBin(int dec) {
    if (dec < 2)
        return dec;
    else
        return convertDecToBin(dec / 2) * 10 + dec % 2;
}

// 2. Реализовать функцию возведения числа a в степень b:

// a. без рекурсии;
int cyclePower(int a, int b) {
    int res = 1;
    while (b > 0) {
        res = res * a;
        b--;
    }
    return res;
}

// b. рекурсивно;
int recPower(int a, int b) {
    if (b == 0) {
        return 1;
    }
    if (b == 1) {
        return a;
    }
    else {
        return a * recPower(a, b - 1);
    }
}

// используя свойство четности степени
int quickPower(int a, int b) {
    int n = 1;
    while (b) {
        if (b % 2) {
            b--;
            n *= a;
        }
        else {
            a *= a;
            b /= 2;
        }
    }
    return n;
}

// c. *рекурсивно, используя свойство четности степени.
int quickPowerRec(int a, int b) {
    if (b == 0)
        return 1;
    if (b == 1)
        return a;
    if (b % 2 != 0) {
        return a * quickPowerRec(a, b - 1);
    }
    else {
        return quickPowerRec(a * a, b / 2);
    }
}
