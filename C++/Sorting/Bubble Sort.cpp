#include<bits/stdc++.h>
#define swap(x,y,t) (t=x, x=y, y=t)

using namespace std;

int n = 10;
int temp;

void printList(int list[])
{
    for(int i=0; i<; ++i)
        cout << list[i] << " ";
    cout << "\n";
}

void bubbleSort(int list[])
{
    int i, j;
    
    for(i=n-1; i>0; --i)
    {
        for(j=0; j<i; ++j)
        {
            if(list[j] > list[j+1])
                swap(list[j], list[j+1], temp);
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cout.tie(0);
    
    int list[11] = {94, 68, 73, 60, 4, 17, 76, 11, 13, 30};
    
  
    bubbleSort(list);
    
    printList(list);
    
    return 0;
}
