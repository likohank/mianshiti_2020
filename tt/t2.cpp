#include <iostream>
using namespace std;

int main()
{
    int a= -1;
    int b= 0;

    int c = (a-b)>>31?b:a;
    cout<<c;


    return 0;
}
