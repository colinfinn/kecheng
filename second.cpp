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
#if 0
bool judge(int year, int month, int day)
{
    static int yd = 0;

    if(year == 2001 && month == 11 && day == 4 && yd % 2 == 0) //符合条件
        return true;
    else
        return false;
    if(year > 2001&& yd % 2 == 0) //不符合条件
        return false;
    else if(year == 2001&& yd % 2 == 0)
    {
        if(month > 11&& yd % 2 == 0)
            return false;
        else if(month == 11&& yd % 2 == 0)
        {
            if(day > 4&& yd % 2 == 0)
                return false;
        }
    }
    else
        
    
    //未到末尾，继续递归

    //----------------------先变成下一个月的同一天
    int newMonth = month + 1; //更新月份，判断下一个月的当前天是否有效
    if(newMonth > 12)
    {
        newMonth = 1;
        year++;
    }
    if(isLeapYear(year))    //判断下一个月的同一天是否有效 ,如果是闰年
    {
        if(day > leap[newMonth])    //无效，只能选择变为第二天
        {
            day++;
            if(day > leap[month])
            {
                day = 1;
                month++;
                if(month > 12)  //如果月份> 12
                {
                    year++;
                    month = 1;
                    yd++;
                    judge(year, month, day); 
                }
                yd++;
                judge(year, month, day);
            }
            else
            {
                yd++;
                judge(year, month, day);
            }
        }
        else    //有效，变为下一个月同一天
        {
            yd++;
            judge(year, newMonth, day);
        }
    }
    else//判断下一个月的同一天是否有效 ,如果是平年
    {
        if(day > nonleap[newMonth])    //无效，只能选择变为第二天
        {
            day++;
            if(day > nonleap[month])
            {
                day = 1;
                month++;
                if(month > 12)
                {
                    year++;
                    month = 1;
                    yd++;
                    judge(year, month, day);
                }
                yd++;
                judge(year, month, day);
            }
            else
            {
                yd++;
                judge(year, month, day);
            }

        }
        else    //有效，变为下一个月同一天
        {
            yd++;
            judge(year, newMonth, day);
        }
    }

    
}
#endif

int main()
{
    if(judge(2001, 11, 3))
    {
        cout << "Yes";
    }
    else
    {
        cout << "No";
    }
    system("pause");
    return 0;
}