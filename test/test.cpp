/*************************************************************************
	> File Name: test.cpp
	> Author: 
	> Mail: 
	> Created Time: 2016年09月10日 星期六 15时59分44秒
 ************************************************************************/

#include<iostream>
#include<stdlib.h>
#include<string.h>
using namespace std;

struct foo{
    char a;
    int b;
};

int main()
{
    foo *f1 = new foo();
    foo *f2 = new foo();
    memset(f1,0,sizeof(foo));
    f1->a = 'a';
    f1->b = 1024;
    strcpy( (char *)f2 , (char *)f1 );
    std::cout << f2->a << "," << f2->b <<std::endl;
}
