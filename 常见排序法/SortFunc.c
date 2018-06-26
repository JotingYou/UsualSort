//
//  SortFunc.c
//  常见排序法
//
//  Created by JotingYou on 2018/4/12.
//  Copyright © 2018年 JotingYou. All rights reserved.
//

#include "SortFunc.h"
#include <stdlib.h>
//交换
void swap(Element *x,Element *y){
    Element temp = *x;
    *x = *y;
    *y = temp;
}
#pragma mark -
#pragma mark 选择排序

//循环实现选择排序
void chooseSortByLoop(Element *array,int n){
    int min;
    for (int i = 0; i < n-1; i++) {
        min = i;
        //在后序序列中寻找最小值所在位置
        for (int j = i+1; j<n; j++) {
            if (array[j].key < array[min].key) {
                min = j;
            }
        }
        //将i与最小值交换位置
        swap(array + i, array + min);
    }
}
//递归实现选择排序
void chooseSortByRecursion(Element *array,int begin,int n){
    if (begin < n-1) {
        
        printf("begin = %d\n",begin);
        /***实现一***/
        int min = begin;
        //记录最小值的位置
        for (int i=1+begin; i<n; i++) {
            if (array[min].key > array[i].key) {
                min = i;
            }
        }
        //将最小值与起始位交换
        swap(array+begin, array+min);
        /***end***/
        
        /***实现二***
         
         //将最小值移到第一位
         for (int i=1+begin; i<n; i++) {
         if (array[begin] > array[i]) {
         swap(array+begin, array+i);
         }
         }
         ***end***/
        //递归
        chooseSortByRecursion(array,++begin, n);
    }

}

//选择排序
void chooseSort(Element *array,int n){
    chooseSortByRecursion(array, 0, n);
}
#pragma mark -
#pragma mark 插入排序
/**
 a:数组首地址
 i:已排序数组末尾位置
 */
void insert(Element * restrict a,int i){
    //待插入数
    Element e = a[i+1];
    /**
     将待插入数与已排序数组内的数据进行比较
     找到合适的位置
     */
    while (e.key < a[i].key && i>=0) {
        /**
         如果遇到大的数，则将该数向后移一位
         空出一个位置准备插入
         之后与前一位数进行比较
         */
        a[i+1] = a[i];
        i--;
    }
    /**
     将待插入数插入到当前位置
     前面i--
     所以，当前位置为i+1
     */
    a[i+1] = e;
}
void insertSort(Element * restrict a,int n){
    /**
     从第二个数起依次插入
     */
    for (int j=1; j<n; j++) {
        insert(a, j-1);
    }

}
#pragma mark -
#pragma mark 希尔排序
void shellInsert(Element * restrict a,int dk,int n){
    for (int i = dk+1; i <= n; i++) {
        if (a[i].key < a[i-dk].key) {
            a[0] = a[i];
            int j = i-dk;
            for (j=i-dk; j>0 && a[0].key<a[j].key; j-=dk) {
                a[j+dk] = a[j];
            }
            a[j+dk] = a[0];
        }
    }
}
void shellSort(Element * restrict a,int * restrict delt,int n){
    for (int k=0; k<n; k++) {
        shellInsert(a, delt[k],n);
    }
}
#pragma mark -
#pragma mark 冒泡排序
void bubbleSort(Element * restrict a,int n){
    for (int i=0; i<n; i++) {
        for (int j= i+1; j<n; j++) {
            if (a[i].key > a[j].key) {
                swap(a+i, a+j);
            }
        }
    }
}
#pragma mark -
#pragma mark 快速排序
void quickSort(Element * restrict a,int left,int right){
    // 递归中止条件
    if (left >= right) {
        return;
    }
    int pivot = a[left].key;//分割数
    int i= left,j= right + 1;    
    do {
        //在左侧找到比分割数大的数的位置
        do {i++;} while (a[i].key<pivot);
        //在右侧找到比分割数小的数的位置
        do {j--;} while (a[j].key>pivot);
        if (i<j) {
            swap(a+i, a+j);
        }
    } while (i<j);
    //将分割数移到中间
    swap(a+left, a+j);
    //左边子数组递归
    quickSort(a, left, j-1);
    //右边子数组递归
    quickSort(a, j+1, right);
}
#pragma mark -
#pragma mark 归并排序
void merge(Element * restrict initList,Element * restrict mergeList,int i,int m,int n){
    int j,k,t;
    j = m + 1;
    k = i;
    
    while (i<=m && j<=n) {
        if (initList[i].key <= initList[j].key) {
            mergeList[k++] = initList[i++];
        }else{
            mergeList[k++] = initList[j++];
        }
    }
    if (i>m) {
        for (t=j; t<=n; t++) {
            mergeList[t] = initList[t];
        }
    }else{
        for (t = i; t <= m; t++) {
            mergeList[k+t-i] = initList[t];
        }
    }
}
void mergePass(Element * restrict initList,Element * restrict mergeList,int n,int s){
    int i,j;
    for (i=1; i<=n-2*s+1; i+=2*s) {
        merge(initList, mergeList, i, i+s-1, i+2*s-1);
    }
    if (i+s-1<n) {
        merge(initList,mergeList,i,i+s-1,n);
    }else{
        for (j=i; j<=n; j++) {
            mergeList[j] = initList[j];
        }
    }
}
void mergeSort(Element * restrict a,int n){
    int s=1;
    Element extra[100];
    while (s<n) {
        mergePass(a, extra, n, s);
        s *= 2;
        mergePass(extra, a, n, s);
        s *= 2;
    }
}
int listMerge(Element * restrict a,int * restrict link,int start1,int start2){
    int last1 = start1,last2 = start2,lastResult = 0;
    if (a[last1].key <= a[last2].key) {
        link[lastResult] = last1;lastResult = last1; last1 = link[last1];
    }else{
        link[lastResult] = last2;lastResult = last2; last2 = link[last2];
    }
    if (last1 == 0) {
        link[lastResult] = last2;
    }else{
        link[lastResult] = last1;
    }
    return link[0];
}
int rmergeSort(Element * restrict a,int * restrict link,int left,int right){
    if (left >= right) {
        return left;
    }
    int mid = (left + right)/2;
    return listMerge(a, link, rmergeSort(a, link, left, mid), rmergeSort(a, link, mid+1, right));
}
#pragma mark -
#pragma mark 堆排序
/**
 将根插入到合适的位置
 */
void adjust(Element * restrict a,int root,int n){
    int child = 2 * root;
    int rootKey = a[root].key;
    Element temp = a[root];
    while (child <= n) {
        if (child < n && a[child].key < a[child + 1].key) {
            child++;
        }
        if (rootKey>a[child].key) {
            break;
        }else{
            a[child/2] = a[child];
            child *= 2;
        }
    }
    a[child/2] = temp;
}
void heapSort(Element * restrict a,int n){
    for (int i = n/2; i>0; i--) {
        adjust(a, i, n);
    }
    for (int i = n-1; i>0; i--) {
        swap(a+1, a+i+1);
        adjust(a, 1, i);
    }
}
