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

//将中缀表达式转换为逆波兰式
void transform(string a)
{
    stack<char> temp;
    stack<int> tempNum;

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
            tempNum.push(t);
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
                temp.push(op.top());
                op.pop();
            }
            op.pop();   //将'('弹出
        }
        else    //如果是运算符
        {
            if(!op.empty() && op.top() == '(')
            {
                op.push(a[i]);
            }
            else
            {
                //当运算符低于栈顶时，需要将op弹出再入栈
                while(!op.empty() && judge(a[i], op.top()))
                {
                    temp.push(op.top());
                    op.pop();
                }
                //正常优先级
                op.push(a[i]);
            }
        }
    }

    while(!op.empty())
    {
        temp.push(op.top());
        op.pop();
    }
    while(!temp.empty())
    {
        op.push(temp.top());
        temp.pop();
    }

    while (!tempNum.empty())
    {
        num.push(tempNum.top());
        tempNum.pop();
    }
}


//通过逆波兰式计算运算结果
int calculate()
{
    while(!op.empty())
    {
        int a = num.top();
        num.pop();
        int b = num.top();
        num.pop();
        switch (op.top())
        {
            case '+': num.push(a + b); break;
            case '-': num.push(a - b); break;
            case '*': num.push(a * b); break;
            case '/': num.push(a / b); break;
        }
        op.pop();
    }
    return num.top();
}




int main()
{
    
    transform("3+2*4");
    cout << calculate();
    

    system("pause");
    return 0;
}