/********************************************************************************
* @文件名: five.cpp
* @作者: 向某人
* @日期: 2023-06-08 19:28:53
* @描述: 算符优先法求解表达式
********************************************************************************/
#include <bits/stdc++.h>
using namespace std;
//3 + 2 - 5 * 8
stack<char> num; //存放操作数
stack<char> op;//存放运算符

//判断优先级,a优先级高于b则返回true
bool judge(char a, char b)
{
    if (a == '*' || a == '/')
    {
        if (b == '+' || b == '-')
        {
            return true;
        }
        else
            return false;
    }
    else
        return false;
}

int getResult(int a, int b, char c)
{
    switch (c)
        {
            case '+': return a + b; break;
            case '-': return b - a; break;
            case '*': return a * b; break;
            case '/': return b / a; break;
        }
}

//将中缀表达式转换为逆波兰式
int transform(string a)
{
    for (int i = 0; i < a.length(); i++)
    {
        if(a[i] >= '0' && a[i] <= '9')
        {
            int t = 0;
            int j = i;
            while(a[j] >= '0' && a[j] <= '9')
            {
                t *= 10;
                t += a[j] - '0';
                j++;
            }
            num.push(t);    //将操作数入栈
            i = j - 1;
        }
        else if(a[i] == '(') //直接入栈
        {
            op.push(a[i]);
        }
        else if(a[i] == ')') 
        {
            while(op.top() != '(')
            {
                int a = num.top();
                num.pop();
                int b = num.top();
                num.pop();
                num.push(getResult(a, b, op.top()));
                op.pop();
            }
            op.pop();   //将'('弹出
        }
        else if(a[i] != '+' && a[i] != '-' && a[i] != '*' && a[i] != '/')    //如果是运算符
            continue;
        else
        {
            if(!op.empty() && op.top() == '(')
            {
                op.push(a[i]);
            }
            else
            {
                //当运算符低于栈顶时，需要将op弹出再入栈
                while(!op.empty() && judge(op.top(), a[i]))
                {

                    int a = num.top();
                    num.pop();
                    int b = num.top();
                    num.pop();
                    num.push(getResult(a, b, op.top()));
                    op.pop();
                }
                //正常优先级
                op.push(a[i]);
            }
        }
    }

    while(!op.empty())
    {
        int a = num.top();
        num.pop();
        int b = num.top();
        num.pop();
        num.push(getResult(a, b, op.top()));
        op.pop();
    }
    return num.top();
}


int main()
{
    
    cout << transform("(3/2) *(5 + 5)");

    system("pause");
    return 0;
}