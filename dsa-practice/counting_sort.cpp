#include<bits/stdc++.h>
using namespace std;

void countingSort(int arr[], int n){
    int mx = *max_element(arr, arr+n);
    vector<int> counts(mx+1, 0);
    vector<int> output(mx+1, 0);

    for(int i=0; i<n; ++i){
        counts[arr[i]]++;
    }

    for(int i=1; i<=mx; ++i){
        counts[i]+=counts[i-1];
    }

    for(int i=n-1; i>=0; --i){
        output[counts[arr[i]]-1] = arr[i];
        counts[arr[i]]--;
    }

    for(int i=0; i<n; ++i){
        arr[i] = output[i];
    }
}

void printArray(int arr[], int n){
    for(int i=0; i<n; ++i){
        cout<<arr[i]<<" ";
    }
}
int main(){
    int arr[] = {4, 2, 2, 8, 3, 3, 1};
    int n = sizeof(arr)/ sizeof(arr[0]);
    countingSort(arr, n);
    printArray(arr, n);
    return 0;
}