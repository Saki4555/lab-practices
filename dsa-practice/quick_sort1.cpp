#include<bits/stdc++.h>
using namespace std;

int partion(int arr[], int low, int high){
    int pivot=arr[low];
    int start=low, end=high;
    while (start<end)
    {
        
    while (arr[start]<=pivot) start++;

    while (arr[end]>pivot) end--;

    if(start<end) 
        swap(arr[start], arr[end]);
    }
    swap(arr[low], arr[end]);

    return end;
    
}

void quickSort(int arr[], int low, int high){
    if(low<high){
        int pi = partion(arr, low, high);
        quickSort(arr, low, pi-1);
        quickSort(arr, pi+1, high);
    }
}

void printArray(int arr[], int n){
    for(int i=0; i<n; ++i){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
int main(){
    //int arr[]={7,6,10,5,9,2,1,15,7};
    //int n=sizeof(arr)/sizeof(arr[0]);
    int n;
    cin>>n;
    int arr[n];
    for(int i=0; i<n; ++i){
        cin>>arr[i];
    }
    quickSort(arr,0, n-1);
    printArray(arr,n);

    return 0;
}