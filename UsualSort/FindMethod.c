//
//  FindMethod.c
//  常见排序法
//
//  Created by JotingYou on 2018/4/12.
//  Copyright © 2018年 JotingYou. All rights reserved.
//

#include "FindMethod.h"

#define COMPARE(x,y) (((x) < (y)) ? -1 : ((x) == (y) ? 0 : 1))
void swapChar(char *x,char *y){
    char temp = *x;
    *x = *y;
    *y = temp;
}
int bineSearch(Element *list,Element aim,int left,int right){
    int middle;
    while (left <= right) {
        middle = (left + right)/2;
        switch (COMPARE(list[middle].key, aim.key)) {
            case -1:
                return bineSearch(list, aim, middle + 1, right);
            case 0:
                return middle;
            case 1:
                return bineSearch(list, aim, left, middle - 1);
            default:
                break;
        }
    }
    return -1;
}
void perm(char *list,int begin,int n){
    if (begin == n) {
        printf("%s\n",list);
        
    }else{
        for (int j=begin; j<=n; j++) {
            swapChar(list+begin, list+j);
            perm(list, begin+1, n);
            swapChar(list+begin, list+j);
        }
    }
}
