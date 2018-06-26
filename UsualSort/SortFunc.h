//
//  SortFunc.h
//  常见排序法
//
//  Created by JotingYou on 2018/4/12.
//  Copyright © 2018年 JotingYou. All rights reserved.
//

#ifndef SortFunc_h
#define SortFunc_h

#include <stdio.h>
#include "Element.h"

/**
 选择排序（p7）
 描述：在当前所有未排序整数中，找到最小一个，放到已排序数组的后一个位置
 平均时间复杂度：O(N^2)
 特点：
 */
void chooseSort(Element*,int);

/**
 直接插入排序（p259）
 描述：将数插入已排序数组中。
 平均时间复杂度：O(N^2)
 特性：
    1）稳定排序。
    2）当表中偏左记录非常少（k<<n）时间复杂度为O(kn)
    3）实现简答。当n<=30时，是最优排序法
 */
void insertSort(Element * restrict,int);

/**
 希尔排序（清华大学出版社《数据结构（C语言版）》p271）
 描述：先将整个待排序序列分成若干个小序列进行插入排序，再对整体进行插入排序
 特性：
 1）不稳定排序。
 2）int dlta[]数组很难确定
 3）对直接插入排序的优化
 */
void shellSort(Element * restrict a,int * restrict dlta,int n);

/**
 冒泡排序（p272）
 描述：
    小数上浮，大数下沉，双重遍历交换
 时间复杂度：O(n^2)
 特性：
    1）稳定排序
    2）本质为交换排序
 */
void bubbleSort(Element * restrict,int);

/**
 快速排序（p261）
 描述：
    1)先选择一个分割数（中位数）；
    2)接着调整所有待排序数，将分割记录放在中间，并使左边小于等于右边；
    3)将左边和右边视作独立的待排序数组，分别进行排序（递归调用快速排序）。
 最差时间复杂度：O(n^2)
 平均时间复杂度：Ω(nlog(n)) //2^n 个叶子的二叉树 树根到叶子的平均路径长度是Ω(nlog(n))
 特性：
 1）不是稳定排序。
 2）平均复杂度为内部排序中最小
 3）是交换排序的一种，由冒泡法改进
 */
void quickSort(Element * restrict,int,int);

/**
 非递归归并排序（p265）
 描述：循环实现把两个有序表归并成一个有序表
 时间复杂度：O(snlog(n))
 空间复杂度：O(sn)
 特性：
 1）稳定排序。
 2）0号位不计
 */
void mergeSort(Element * restrict a,int n);

/**
 递归归并排序（p269）
 描述：递归实现把两个有序表归并成一个有序表
 平均时间复杂度：O(nlog(n))
 特性：
 1）稳定排序。
 */
//void rmergeSort(Element * restrict a,int * restrict link,int left,int right);

/**
 堆排序（p270）
 描述：先将数组排成大根堆，然后依次从根取数。
 平均/最差时间复杂度：O(nlog(n))
 特性：
 1）
 2）辅助空间比归并排序小，但速度要慢一点。
 3)0号位不计
 */
void heapSort(Element * restrict a,int n);

#endif /* SortFunc_h */
