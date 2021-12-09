#include<iostream>
using namespace std;
int b = 0;
int main()
{
    int a = 10;
    auto f = [&] {
        a = 20;
        b = 100;
    };
    
    f();
    cout << a << endl;
    cout << b << endl;
}