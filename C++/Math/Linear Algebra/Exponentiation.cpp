#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

clock_t start, stop;
double duration;


// Top-Down
ll myPow1(int a, int b)
{
    if (b==0) return 1;
    
    ll half = myPow1(a, b/2);
    
    // prevent error when b is odd number,
    return half * half * (b%2==0 ? 1: a);
}

// Bottom-Up
ll myPow2(int a, int b)
{
    ll ret = 1, elem = a;
    
    for(int i=0; (1<<i) <= b; ++i)
    {
        // If the ith bit is on
        if(b>>i & 1)
            ret *= elem;
        
        elem *= elem;
    }
    return ret;
}

void myPow1_time()
{
    start = clock();
    
    cout << "result: "<< myPow1(2, 50) <<"\n";
    
    stop = clock();
    
    duration = (double)(stop - start) / CLOCKS_PER_SEC;
    
    printf("myPow1: %f seconds\n", duration);
}

void myPow2_time()
{
    start = clock();
    
    cout << "result: "<< myPow2(2, 50) <<"\n";
    
    stop = clock();
    
    duration = (double)(stop - start) / CLOCKS_PER_SEC;
    
    printf("myPow2: %f seconds\n", duration);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cout.tie(0);
    
    myPow1_time();   // myPow1: 0.000024 seconds

    cout <<"=======\n";

    myPow2_time();   // myPow2: 0.000001 seconds

    return 0;
   
}

/*
 myPow2
 ======
 50 = 0b110010
 a^50 = a^32 * a^16 * a^1
      = a^(2^5) * a^(2^4) * a^(2^1)
      = a^(1<<5) * a^(1<<4) * a^(1<<1)
 ====
 result: 1125899906842624
 myPow1: 0.000019 seconds
 =======
 result: 1125899906842624
 myPow2: 0.000002 seconds
 */

