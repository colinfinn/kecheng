/********************************************************************************
* @文件名: four.cpp
* @作者: 向某人
* @日期: 2023-06-08 17:35:05
* @描述: 农夫过河问题
********************************************************************************/
#include <bits/stdc++.h>
using namespace std;

//农夫，狼，白菜， 羊，
//0表示在河的南岸， 1表示在河的北岸

//定义数组，用以记录某种状态是否已经被访问过了
int route[16];//从0000到1111的16种状态，已访问过赋值为1，否则为-1
string name[] = {"农夫", "狼", "白菜", "羊"};

//农夫，判断状态0b1000,与运算8
//狼，判断状态0b0100,与运算4
//白菜，判断状态0b0010,与运算2
//羊，判断状态0b0001,与运算1

//打印当前状态
void printStatus(int num)
{
    cout << "----------------------\n";
    cout << "________北岸_______\n";
    //输出在北岸的
    for (int i = 0; i < 4; i++)
    {
        if(num & (1 << (3 - i)))
            cout << name[i] << " ";
    }
    cout << endl;
    cout << endl;
    cout << endl;
    cout << endl;
    for (int i = 0; i < 4; i++)
    {
        if(!(num & (1 << (3 - i))))
            cout << name[i] << " ";
    }
    cout << endl;
    cout << "________南岸_______\n";
    cout << "----------------------\n";
}


int main()
{
    memset(route, -1, sizeof(route));   //初始化元素都为-1
    queue<int> moveTo;  //初始化队列，记录
    //将初始状态入队
    moveTo.push(0);
    route[0] = 1;//第一种状态访问
    while(!moveTo.empty())
    {
        int cur = moveTo.front();   //取队头
        moveTo.pop();
        int index;
        //从剩下的状态中进行查找,寻找符合的状态进行入队
        for (int i = 0; i < 16; i++)
        {
            if(route[i] == -1)  //该节点未访问过,选取符合条件的进行入队
            {
                //农夫,狼，白菜，羊，8,4,2,1 &
                //当狼和羊在同一岸且农夫在另一岸，不成立
                if((bool)(i & 4) == (bool)(i & 8) && (bool)(i & 4) != (bool)(i & 8))
                    continue;
                //当羊和白菜在同一岸且农夫在另一岸，不成立
                if((bool)(i & 2) == (bool)(i & 1) && (bool)(i & 2) != (bool)(i & 8))
                    continue;
                //符合条件
                index = i;
                break;
            }
        }
        

    }


   
    
    system("pause");
    return 0;
}