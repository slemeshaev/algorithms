//
//  main.c
//  HW_4_Lemeshaev_Stanislav
//
//  Created by Станислав Лемешаев on 11/02/2019.
//  Copyright © 2019 Станислав Лемешаев. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// возможные варианты ходов коня
int ktmov1[8] = { -2, -1, 1, 2, 2, 1, -1, -2 };
int ktmov2[8] = { 1, 2, 2, 1, -1, -2, -2, -1 };
int ikon = 0, jkon = 0, nomerHoda = 1;

void solution1();
void solution2();
void solution3();

void searchSolution(int N, int M, int board[][M], int row[N*M], int col[N*M]);
//int checkBoard();
int checkKnight(int x, int y);
void printBoard(int N, int M, int board[][M]);
void menu();

int main(int argc, const char* ardv[])
{
    int sel = 0;
    do
    {
        menu();
        scanf("%i", &sel);
        switch (sel)
        {
            case 1:solution1();break;
            case 2:solution2();break;
            case 3:solution3();break;
            case 0:printf("Bye-bye"); break;
            default:printf("Wrong selected\n");
        }
    } while (sel != 0);
    return 0;
}

void menu()
{
    printf("\n");
    printf("1 - task1. Количество маршрутов.\n");
    printf("2 - task2. Максимальная длина подпоследовательности.\n");
    printf("3 - task3. Обход конем шахматной доски NxM.\n");
    
    printf("0 - exit\n");
}

void solution1(){
    int N;
    printf("Введите количество строк в карте \n");
    scanf("%i",&N);
    
    int M;
    printf("Введите количество столбцов в карте \n");
    scanf("%i",&M);
    
    
    int a[N][M];
    
    printf("Заполнение массива данными (Для препятствий 0, без препятствия 1)\n");
    srand(time(NULL));
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < M; j++)
            a[i][j] = rand() % 2;
    }
    a[0][0] = 1;
    
    printf("Ваша карта:\n");
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            printf("%i ", a[i][j]);
        }
        printf("\n");
    }
    
    //заполняем левую границу
    for(int i = 1; i < N; i++){
        if(a[i][0] != 0){
            a[i][0] = a[i-1][0];
        }
    }
    
    //заполняем верхнюю границу
    for(int j = 1; j < M; j++){
        if(a[0][j] != 0){
            a[0][j] = a[0][j-1];
        }
    }
    
    //Заполняем оставшуюся часть карты, значение в i,j элементе соответствует количеству маршрутов по которым можно в этот элемент попасть
    for(int i = 1; i < N; i++){
        for(int j = 1; j < M; j++){
            if(a[i][j] != 0)
                a[i][j] = a[i-1][j] + a[i][j-1];
        }
    }
    
    printf("\nЭлемент(i,j) соответствует количеству маршрутов, по которым можно в этот элемент попасть.\nВаша карта количества маршрутов a(i,j):\n");
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            printf("%i ", a[i][j]);
        }
        printf("\n");
    }
}

void solution2(){
    int N = 1;
    int M = 1;
    int sl = 300; // условная максимальная длина строки
    char S1[sl], S2[sl];
    
    printf("Введите первую строку \n");
    scanf("%s", S1);
    
    
    printf("Введите вторую строку \n");
    scanf("%s", S2);
    
    //определяем длину строк
    for(int i = 0; S1[i] != '\0'; i++){
        N++;
    }
    
    for(int i = 0; S2[i] != '\0'; i++){
        M++;
    }
    
    int a[N][M];
    //заполняем левую границу
    for(int i = 0; i < N; i++){
        a[i][0] = 0;
    }
    
    //заполняем верхнюю границу
    for(int j = 1; j < M; j++){
        a[0][j] = 0;
    }
    
    //Заполняем оставшуюся часть массива
    for(int i = 1;i < N; i++){
        for(int j = 1; j < M; j++){
            if (S1[i-1] == S2[j-1])
                a[i][j] = a[i-1][j-1] + 1;
            else
                a[i][j] = a[i-1][j] > a[i][j-1] ? a[i-1][j] : a[i][j-1];
        }
    }
    
    printf("Заполненный массив:\n");
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            printf("%i ", a[i][j]);
        }
        printf("\n");
    }
    printf("Получившийся ответ: %i\n", a[N-1][M-1]);
}

void solution3(){
    int N = 8;
    int M = 8;

    
    int board[N][M];
    int row[N*M], col[N*M];
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            board[i][j] = 0;
        }
    }
    
    searchSolution(N, M, board, row, col);
    
    // в методе searchSolution при успешном исходе стоит выход из програмы через exit(0);
    // значит если добрались сюда. значит маршрута не нашлось.
    printf("не нашлось маршрута для коня!");
    
}

void searchSolution(int N, int M, int board[][M], int row[N*M], int col[N*M]){
    int a, b, e;
    
    board[ikon][jkon] = nomerHoda;
    row[nomerHoda-1] = ikon;
    col[nomerHoda-1] = jkon;
    nomerHoda++;
    
    // пробегаем по всем возможным вариантам хода
    for ( a = 0 ; a <= 7 ; a++ ) {
        
        if (nomerHoda > (N*M)) {
            printBoard(N,M,board); exit(0);
        }
        
        // определяем колонку и строку для следующего хода
        b = ikon + ktmov1[a];
        e = jkon + ktmov2[a];
        
        // проверяем, что после выполенения хода конь остается на шахматной доске
        if ( b < 0 || b > N-1 || e < 0 || e > M-1 )
            continue;
        
        // проверяем, были ли мы уже в этой клетке
        if ( board[b][e] > 0)
            continue;
        ikon = b; jkon = e;
        searchSolution(N,M,board,row, col);
    }
    
    // вышли из цикла - значит перебрали все возможные ходы. а значит надо убирать последнего коня
    nomerHoda-- ;
    
    // убираем коня с занимаемой позиции
    board[row[nomerHoda - 1]][col[nomerHoda - 1]] = 0;
    
    nomerHoda--;  // пробуем сделать следующий ход
    ikon = row[nomerHoda];
    jkon = col[nomerHoda];
    nomerHoda++;
}

void printBoard(int N, int M, int board[][M]){
    printf("Пройденная доска:\n");
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            printf("%i ", board[i][j]);
        }
        printf("\n");
    }
}

