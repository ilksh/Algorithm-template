#include<bits/stdc++.h>

using namespace std;

int C[3][3];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int A[3][3] = {{1,2,3},
                   {4,5,6},
                   {7,8,9}};
    
    int B[3][3] = {{4,5,8},
                   {1,2,3},
                   {6,7,9}};

    for(int i=0; i<3; ++i) for(int j=0; j<3; ++j)
    {
        for(int k=0; k<3; ++k)
            C[i][j] += A[i][k] * B[k][j];
    }

    for(int i=0; i<3; ++i)
    {
        for(int j=0; j<3; ++j)
            cout << C[i][j] << " ";
        
        cout << '\n';
    }
}
