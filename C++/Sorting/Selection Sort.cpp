#include<bits/stdc++.h>
#define swap(x,y,t) (t=x, x=y, y=t)

using namespace std;

int temp;

void printList(int list[])
{
    for(int i=0; i<10; ++i)
        cout << list[i] << " ";
    cout << "\n";
}

void selectionSort(int list[])
{
    for(int i=0; i<10-1; ++i){
        int least_idx= i;
        
        for(int j=i+1; j<10; ++j){
            if(list[j] < list[least_idx])
                least_idx = j;
        }
        
        if(i==least_idx) continue;
        
        swap(list[i], list[least_idx], temp);
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cout.tie(0);

    int list[11] = {94, 68, 73, 60, 4, 17, 76, 11, 13, 30};
    
    selectionSort(list);
    
    printList(list);
   
    return 0;
}
