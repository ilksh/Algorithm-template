#include<bits/stdc++.h>
using namespace std;

void printList(int list[])
{
    for(int i=0; i<10; ++i)
        cout << list[i] << " ";
    cout << "\n";
}

void insertionSort(int list[])
{
    int i, j;
    
    for(i=1; i<10; ++i){
        int key = list[i];
        
        for(j=i-1; j>=0; --j)
        {
            if(list[j] > key)
                list[j+1] = list[j];
            
            else break;
        }
            
        list[j+1] = key;
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cout.tie(0);
    
    int list[11] = {94, 68, 73, 60, 4, 17, 76, 11, 13, 30};
    
    insertionSort(list);
    
    printList(list);
    
    return 0;
}
