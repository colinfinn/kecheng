/********************************************************************************
* @文件名: three.cpp
* @作者: 向某人
* @日期: 2023-06-08 09:21:45
* @描述: 木棒加工问题
********************************************************************************/
#include <bits/stdc++.h>
using namespace std;

typedef struct 
{
    int length;
    int weight;
}wood;


//比较函数，确定快速排序的排序规则
bool cmp(wood a,wood b)
{
    if(a.length == b.length)
        return a.weight >= b.weight;
    else if(a.length > b.length)
        return true;
    else
        return false;
    
}

//根据长度对木棒进行排序
void quickSort(wood *num, int begin, int end)
{
    if(begin > end)
        return;
    wood base = num[begin];
    int i = begin;
    int j = end;
    while(i != j)
    {
        //大于
        while(cmp(num[j], base) && j > i)//右边开始找比基数小的木棒
            j--;
        while(cmp(base, num[i]) && j > i)//左边开始找比基数小的木棒
            i++; 
        if(j > i)
        {
            wood t = num[i];
            num[i] = num[j];
            num[j] = t;
        }   
    }
    num[begin] = num[i];
    num[i] = base;
    quickSort(num, begin, i - 1);
    quickSort(num, i + 1, end);
}

//最长递增子序列
int LIS(wood *w, int len)
{
    int *dp = new int[len];
    for (int i = 0; i < len; i++)
    {
        dp[i] = 1;
    }
    int result = 1;
    for (int i = 0; i < len; i++)   //计算dp[i]
    {
        for (int j = 0; j < i; j++)
        {

            if(w[j].weight > w[i].weight)
                dp[i] = max(dp[j] + 1, dp[i]);
        }
        result = max(dp[i], result);
    }
    return result;
}


int main()
{
    wood *a = new wood[6]{
        {4, 9},
        {5, 2},
        {2, 1},
        {2,3},
        {3, 5},
        {1, 4}
    };
    quickSort(a, 0, 5);
    for (int i = 0; i < 6; i++)
    {
        printf("wood: len= %d, weight=%d.\n", a[i].length, a[i].weight);
    }

    //cout << LIS(a, 5);

    system("pause");
    return 0;
}