#include<bits/stdc++.h>

using namespace std;

int a[10];
int b[10][10];

void f1(int* p)
{
    for(int i=0; i<10; ++i) {
        cout << (p+i) << '\n';
    }
    cout << '\n';
}

void f2(int (*p)[10])
{
    for(int i=0; i<10;++i)
    {
        // *(*(p+i)+j) = p[i][j]
        for(int j=0;j <10; ++j)
            cout << *(*(p+i)+j)<<" ";
        cout <<"\n";
    }
   
}

int main()
{
    for(int i=0; i<10; ++i) a[i] = i;

    for(int i=0; i<10; ++i)
        for(int j=0; j<10; ++j){
        b[i][j] = i*10 + j + 10;
    }
    
    for(int i=0; i<10; ++i)
    {
        for(int j=0; j<10; ++j)
            cout << b[i][j]<<" ";
        cout <<"\n";
    }
    cout <<"====\n";
    
    f2(b);

    return 0;
}

/*
 10 11 12 13 14 15 16 17 18 19
 20 21 22 23 24 25 26 27 28 29
 30 31 32 33 34 35 36 37 38 39
 40 41 42 43 44 45 46 47 48 49
 50 51 52 53 54 55 56 57 58 59
 60 61 62 63 64 65 66 67 68 69
 70 71 72 73 74 75 76 77 78 79
 80 81 82 83 84 85 86 87 88 89
 90 91 92 93 94 95 96 97 98 99
 100 101 102 103 104 105 106 107 108 109
 ====
 10 11 12 13 14 15 16 17 18 19
 20 21 22 23 24 25 26 27 28 29
 30 31 32 33 34 35 36 37 38 39
 40 41 42 43 44 45 46 47 48 49
 50 51 52 53 54 55 56 57 58 59
 60 61 62 63 64 65 66 67 68 69
 70 71 72 73 74 75 76 77 78 79
 80 81 82 83 84 85 86 87 88 89
 90 91 92 93 94 95 96 97 98 99
 100 101 102 103 104 105 106 107 108 109

 */
