/********************************************************************************
* @文件名: three.cpp
* @作者: 向某人
* @日期: 2023-06-08 09:21:45
* @描述: 木棒加工问题
********************************************************************************/
#include <bits/stdc++.h>
using namespace std;
#define LEN 5000
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

//生成测试测试数据
void createFile(int num)
{
    srand(time(NULL));
    ofstream ofs;
    char fileName[20];
    sprintf(fileName, "test%d.txt", num);
    ofs.open(fileName, ios::out);
    for (int i = 0; i < num; i++)
    {
        ofs << (rand() % LEN) << " "<<  (rand() % LEN) << endl;
    }
    ofs.close();
}

wood * loadFile(char fileName[], int len)
{
    wood * res = new wood[len];
    ifstream ifs;
    ifs.open(fileName, ios::in);
    for (int i = 0; i < len; i++)
    {
        ifs >> res[i].length;
        ifs >> res[i].weight;
    }
    ifs.close();
    return res;
    
}




int main()
{
    createFile(LEN);
    char fileName[20];
    sprintf(fileName, "test%d.txt", LEN);
    wood * a = loadFile(fileName, LEN);
    quickSort(a, 0, LEN - 1);
    int *minTime = new int[LEN];
    int *order = new int[LEN];
    for (int i = 0; i < LEN; i++)
    {
        minTime[i] = 1;
    }
    
    for (int i = 0; i < LEN; i++)
    {
        int curTime = 1;
        for (int j = 0; j < i; j++)
        {
            //如果前一个木棒比后一个木棒要重，准备时间+1，
            if(a[j].weight > a[i].weight)
                curTime = max(curTime, minTime[j] + 1);
        }
        minTime[i] = curTime;
    }
    int minReadyTime = 0;
    for (int i = 0; i < LEN; i++)
    {
        if(minTime[i] > minReadyTime)
            minReadyTime = minTime[i];
    }

    cout << "最小准备时间" << minReadyTime << endl;
    
    //求加工顺序
    for (int i = 1; i <= minReadyTime; i++)
    {
        for (int j = 0; j < LEN; j++)
        {
            if(minTime[j] == i)
                printf("(%d, %d)->", a[j].length, a[j].weight);
        }
        
    }
    

    













    system("pause");
    return 0;
}