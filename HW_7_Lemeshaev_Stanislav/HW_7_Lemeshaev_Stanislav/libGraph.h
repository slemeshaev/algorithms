//
//  libGraph.h
//  HW_7_Lemeshaev_Stanislav
//
//  Created by Станислав Лемешаев on 24/02/2019.
//  Copyright © 2019 Станислав Лемешаев. All rights reserved.
//

#ifndef libGraph_h
#define libGraph_h
typedef unsigned int u_int;

typedef struct tagNode * pNode;

typedef struct tagNode
{
    u_int weight;
    pNode next;
} Node;

typedef struct tagList
{
    pNode head;
    int size;
    int maxSize;
} List;

typedef List * pList;


typedef u_int bool;
#define true 1
#define false 0

typedef struct tagQueueNode * pQueueNode;

typedef struct tagQueueNode
{
    int num;
    pQueueNode next;
} QueueNode;

typedef struct tagQueue
{
    pQueueNode front;
    pQueueNode back;
    int size;
    int maxSize;
} Queue;

typedef Queue * pQueue;

typedef struct tagStack
{
    pQueueNode head;
    int size;
    int maxSize;
} Stack;

typedef Stack * pStack;

int **readMatrixFromFile(char *filename, int *V, int *E);
void printGraph(int **graph, int vertexs);
void freeGraph(int **graph, int vertexs);

void initQueue(pQueue queue);
void initStack(pStack stack);

void BFS(pQueue queue, pQueue queueUsed, int numNode, int **graph, int vertexs);
void DFS(pStack stack, pQueue queueUsed, int numNode, int **graph, int vertexs);

#endif /* libGraph_h */
