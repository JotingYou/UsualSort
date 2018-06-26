//
//  main.c
//  常见排序法
//
//  Created by JotingYou on 2018/4/12.
//  Copyright © 2018年 JotingYou. All rights reserved.
//

#include <stdio.h>
#include "SortFunc.h"
#include "FindMethod.h"
#define N 15
///打印数组
void printArray(Element*,int);
int main(int argc, const char * argv[]) {
    // Array init
    Element array[N] = {{100},{3},{4},{2},{1},{7},{0},{9},{3},{2},{10},{32},{1},{0},{3}};
    
    puts("Original Array:");
    printArray(array, N);
    
    //Sort function:
    bubbleSort(array, N);
    
    puts("After Sort:");
    printArray(array, N);
    
    //Search function:
    Element aim = {1};
    printf("local = %d\n",bineSearch(array, aim, 0, N-1));
    
    return 0;
}
void printArray(Element *array,int n){
    printf("Array = [");
    for (int i=0; i<n; i++) {
        printf(" %d ",array[i].key);
    }
    printf("]\n");
}
