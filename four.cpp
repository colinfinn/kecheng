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

//判断下一个状态是否合理
bool judge(int cur, int target)
{
    //农夫要过河，所以下一个状态不能和当前状态相同
    if((bool)(cur & 8) == (bool)(target & 8)) 
        return false;
    //由于农夫过河要带走狼或者白菜或者羊，必须保证不能同时带走超过一个
    int count = 0;
    if((bool)(cur & 4) != (bool)(target & 4))
        count++;
    if((bool)(cur & 2) != (bool)(target & 2))
        count++;
    if((bool)(cur & 1) != (bool)(target & 1))
        count++;
    //只能带走一个
    if(count > 1)
        return false;
    //农夫,狼，白菜，羊，8,4,2,1 &
    //当狼和羊在同一岸且农夫在另一岸，不成立
    if((bool)(target & 4) == (bool)(target & 1) && (bool)(target & 4) != (bool)(target & 8))
        return false;
    //当羊和白菜在同一岸且农夫在另一岸，不成立
    if((bool)(target & 2) == (bool)(target & 1) && (bool)(target & 2) != (bool)(target & 8))
        return false;
    return true;

}


int main()
{
    memset(route, -1, sizeof(route));   //初始化元素都为-1
    queue<int> moveTo;  //初始化队列，记录路径
    //将初始状态入队
    moveTo.push(0);
    route[0] = 0;//第一种状态访问
    while(!moveTo.empty() && route[15] == -1)
    {
        int cur = moveTo.front();   //取队头
        moveTo.pop();   //出队
        //printStatus(cur);
        int index;
        //从剩下的状态中进行查找,寻找符合的状态进行入队
        for (int i = 0; i < 16; i++)
        {
            if(route[i] == -1)  //该节点未访问过,选取符合条件的进行入队
            {
                if(!judge(cur, i))
                    continue;
                else
                {
                    route[i] = cur; 
                    moveTo.push(i);
                }
                    
            }
        }
    }
    int i = 15, count = 1;
    int path[16] = {0};
    path[0] = 15;
    while(route[i] != 0)
    {
        path[count++] = route[i];
        i = route[i];
    }
    count++;
    for (int i = 0; i < count / 2; i++)
    {
        int t = path[i];
        path[i] = path[count - i - 1];
        path[count - i - 1] = t;
    }
    //打印结果
    for (int i = 0; i < count; i++)
    {
        printStatus(path[i]);
    }
    
    

    system("pause");
    return 0;
}