#include<bits/stdc++.h>
using namespace std;

const int MAX_N = 1e4 + 4;

int arr[MAX_N] = {3, 5, 4, 8, 9, 2, 14, 13, 1, 15};
int cnt;

int partition(int *arr, int left, int right)
{
    int l = left+1;
    int r = right;
    int p = left;
    
    while(true){
        while(arr[l] < arr[p]){
            l++;
            cnt++;
        }
        
        while(arr[r] > arr[p]){
            r--;
            cnt++;
        }
        
        if(l > r) break;
        
        // l<=r
        swap(arr[l],arr[r]);
        l++; r--;
        cnt++;
    }
    
    cnt++;
    swap(arr[p], arr[r]);
    
    return r;
}

// arr[left..right] sorting
void quickSort(int *arr, int left, int right)
{
    if(left<right){
        cnt++;
        int pivot = partition(arr, left, right);
        quickSort(arr, left, pivot-1);
        quickSort(arr, pivot+1, right);
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int n = 10;
    quickSort(arr, 0, n-1);
    
    for(int i=0; i<n; ++i)
        cout << arr[i] << " ";
    
    cout << "\n";
    
    cout << "cnt: "<< cnt <<"\n";
    
    return 0;
}
