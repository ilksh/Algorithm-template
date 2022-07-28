#include<bits/stdc++.h>
using namespace std;

const int MAX_N = 1e4 + 4;

int arr[MAX_N] = {3, 5, 4, 8, 9, 2, 14, 13, 1, 15};
int cnt;

void merge(int *arr, int left, int right)
{
    int mid = (left + right) / 2;
    
    int i,j,k = 0;
    int temp[MAX_N];
    
    i = left;
    j = mid + 1;
    
    while(i<=mid && j<=right){
        cnt++;
        
        if(arr[i]<arr[j]){
            temp[k] = arr[i++];
        }
            
        else{
            temp[k] = arr[j++];
        }
        
        k++;
    }
    
    while(i<=mid){
        cnt++;
        temp[k++] = arr[i++];
    }
    
    while(j<=right){
        cnt++;
        temp[k++] = arr[j++];
    }
    
    for(int i=0; i<k; ++i){ // arr[left...right] = temp[0..k-1]
        cnt++;
        arr[left + i] = temp[i];
    }
}

void mergeSort(int *arr, int left, int right) // arr[left..right] sorting
{
    cnt++;
    
    if(left < right){
        int mid = (left+right) / 2;
        mergeSort(arr, left, mid);      // arr[left..mid] sorting
        mergeSort(arr, mid+1, right);   // arr[mid+1..right] sorting
        merge(arr, left, right);        // ar[left..right] sorting
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int n = 10;
    
    mergeSort(arr, 0, n-1);
    
    for(int i=0;i<n; ++i)
        cout << arr[i] << " ";
    
    cout <<"\n";
    
    cout << "cnt: "<< cnt << "\n";
    
    return 0;
}
