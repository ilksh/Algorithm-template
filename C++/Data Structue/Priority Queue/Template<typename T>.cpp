#include <iostream>

using namespace std;

int add1(int a, int b)
{
    return a+b;
}

template<typename T>
T add2(T a, T b)
{
   return a + b;
}

int main()
{
   int a= 1, b = 2;
   double a2 = 3.123, b2 = 4.123123;

   cout << add1(a, b) << '\n';
   cout << add2(a2, b2) << '\n';
}

