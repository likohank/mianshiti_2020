#include <iostream>
using namespace std;

int main()
{
    cout << "long long" << sizeof(long long) << endl;
    cout << "long" << sizeof(long) << endl;
    cout << "int" << sizeof(signed int) << endl;

    int n1 = 8998211;
    int n2 = 299;
    long long  n3 = n1 * n2;
    cout << n3 << endl;


    return 0;
}
