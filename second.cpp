/********************************************************************************
* @文件名: second.cpp
* @作者: 向某人
* @日期: 2023-06-07 20:29:51
* @描述: 项目二，日期游戏
********************************************************************************/
#include <bits/stdc++.h>
using namespace std;
int leap[] = {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
int nonleap[] = {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

//判断是否为闰年
bool isLeapYear(int year)
{
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}
#if 1

int a = 0;
//无论如何，每次判断都只有有两条递归路线,high用来判断轮到哪一个玩家
void judge(int year, int month, int day, int high)
{
    if(year == 2001 && month == 11 && day == 4) //符合条件
    {
        if(high % 2 == 0)//当某个玩家胜利，判断是否为亚当，且胜利路线条数大于1时，亚当可胜利
        {
            a++;
        }
        return;
    }    
    if(year > 2001) //不符合条件
    {    
        
        return;
    }
    else if(year == 2001)
    {
        if(month > 11)
            return;
        else if(month == 11)
        {
            if(day > 4)
                return;
        }
    }

    //----------------------先变成下一个月的同一天
    int newMonth = month + 1; //更新月份，判断下一个月的当前天是否有效
    if(newMonth > 12)
    {
        newMonth = 1;
        year++;
    }
    if(isLeapYear(year))    //判断下一个月的同一天是否有效 ,有效入递归
    {
        if(day < leap[newMonth])    
        {
            judge(year, newMonth, day, high + 1);
        }
    }
    else//判断下一个月的同一天是否有效 ,如果是平年
    {
        if(day < nonleap[newMonth])    //判断下一个月的同一天是否有效 ,有效入递归
        {
            judge(year, newMonth, day, high + 1);
        }
    }


    //------------变第二天-------------------------
    int newDay = day + 1;
    if(isLeapYear(year))    //如果是闰年
    {
        if(newDay > leap[month])
        {
            newDay = 1;
            month++;
        }
        if(month > 12)
        {
            //开始递归
            judge(year + 1, 1, newDay, high + 1);
        }
        judge(year, month, newDay, high + 1);
    }
    else
    {
        if(newDay > nonleap[month])
        {
            newDay = 1;
            month++;
        }
        if(month > 12)
        {
            judge(year + 1, 1, newDay, high + 1);
        }
        judge(year, month, newDay, high + 1);
    }
}
#endif



int main()
{

    judge(2001, 11, 3, -1);
    if(a > 0)
    {
        cout << "YES" << endl;
    }
    else
    {
        cout << "NO" << endl;
    }
    system("pause");
    return 0;
}