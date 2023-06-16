/********************************************************************************
* @文件名: firstProject.cpp
* @作者: 向某人
* @日期: 2023-06-07 12:29:28
* @描述: 设计一个一元稀疏多项式计算器。
********************************************************************************/
#include <bits/stdc++.h>
using namespace std;
//a
typedef struct Node
{
    int coe; //系数
    int exp; //指数
    Node *next;    
}Node;


class polynomial
{
private:
    Node *head;
public:
    polynomial();
    void printList();
    void add(Node *a);
    polynomial operator+(polynomial A);//运算符重载进行计算
    polynomial operator-(polynomial A);
    int calculate(int x);
};
polynomial::polynomial()
{
    //带头结点的单链表
    //初始化
    head = new Node;
    head->next = nullptr;
    head->coe = 0;
    head->exp = 0;
}

void polynomial::printList()    //打印多项式
{
    Node *p = head->next;
    while(p != nullptr)
    {
        if(p->coe >= 0 && p != head->next)
            cout << "+";
        cout << p->coe << "x^" << p->exp;
        p = p->next;
    }

}

void polynomial::add(Node *a) //将多项式节点插入到多项式中
{
    if(head->next == nullptr) //如果没有元素直接插入
    {
        head->next = a;
        return;
    }
    //按指数降序排列
    Node *p = head->next;
    Node *t = head;
    while(p != nullptr)   //如果下一个节点为空，直接将节点插入p末尾
    {
        if(a->exp <= p->exp) //当插入节点的指数小于于或等于p的指数时，将其插入末尾
        {
            t = p;//将当前点保存
            p = p->next;
        }
        else
            break;
    }
    a->next = t->next;
    t->next = a;
}

polynomial addAndSub(Node *first, Node *second, char c)
{
    polynomial result;

    while(first && second)
    {
        if(first->exp > second->exp)
        {
            Node *t = new Node{first->coe, first->exp, nullptr};
            result.add(t);
            first = first->next;
        }
        if(first->exp < second->exp)
        {
            Node *t = new Node{second->coe, second->exp, nullptr};
            result.add(t);
            second = second->next;
        }
        if(first->exp == second->exp)
        {
            if(first->coe + second->coe != 0)
            {
                Node *t = new Node;
                if(c == '+')
                    t->coe = first->coe + second->coe;
                else
                    t->coe = first->coe - second->coe;
                t->exp = first->exp;
                t->next = nullptr;
                if(t->coe != 0)
                    result.add(t);
            }
            first = first->next;
            second = second->next;
        }
    }

    while(first != nullptr)
    {
        Node *t = new Node{first->coe, first->exp, nullptr};
        result.add(t);
        first = first->next;
    }    

    while(second != nullptr)
    {
        Node *t = new Node{second->coe, second->exp, nullptr};
        result.add(t);
        second = second->next;
    }  
    return result;
}


polynomial polynomial::operator+(polynomial A)
{
    Node *first = A.head->next;
    Node *second = this->head->next;
    return addAndSub(first, second, '+');
}


polynomial polynomial::operator-(polynomial A)
{
    Node *first = A.head->next;
    Node *second = this->head->next;
    return addAndSub(first, second, '-');  
}

int polynomial::calculate(int x)
{
    int res = 0;
    Node *p = head->next;
    while(p != nullptr)
    {
        res += p->coe * pow(x, p->exp);
    }
    return res;
}

int main()
{
    stringstream s1("3x^2-5x^2");
    
    int  s2, s3, s4;
    s1 >> s2;
    s1 >> s3;
    // s1 >> s2;
    cout << s3;

    polynomial a, f,i;
    Node b = {5,3,nullptr};
    Node c = {5,8,nullptr};
    Node d = {5,5,nullptr};
    Node e = {5,7,nullptr};
    Node q = {5,2,nullptr};
    Node w = {5,7,nullptr};
    Node o = {5,3,nullptr};
    Node r = {5,4,nullptr};
    a.add(&b);
    a.add(&c);
    a.add(&d);
    a.add(&e);


    f.add(&q);
    f.add(&w);
    f.add(&o);
    f.add(&r);


    i = a - f;
    i.printList();
    
    system("pause");
    return 0;
}