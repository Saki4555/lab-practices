#include<bits/stdc++.h>
using namespace std;

void merge(char arr[], int p, int q, int r){

    int n1 = q-p+1, n2 = r-q;

    int L[n1], M[n2];

    for(int i=0; i<n1; ++i){
        L[i] = arr[p+i];
    }

    for(int i=0; i<n2; ++i){
        M[i] = arr[q+1+i];
    }

    int i=0, j=0, k=p;

    while (i<n1 && j<n2)
    {
        if(L[i]<=M[j]){
            arr[k]=L[i];
            i++;
        }
        else{
            arr[k]=M[j];
            j++;
        }

        k++;
    }
    
    while (i<n1)
    {
        arr[k]=L[i];
        i++;
        k++;
    }

     while (j<n2)
    {
        arr[k]=M[j];
        j++;
        k++;
    }
    
}

void mergeSort(char arr[], int l, int r){
    if(l<r){
        int m = l+(r-l)/2;
        mergeSort(arr, l, m);
        mergeSort(arr, m+1, r);

        merge(arr, l, m, r);
    }
}

void printArray(char arr[], int n){
    for(int i=0; i<n; ++i){
        cout<<arr[i];
    }
    cout<<endl;
}

int main(){
    //int arr[] = {6,5,12,10,9,1};
    //int n = sizeof(arr)/sizeof(arr[0]);
    int n;
    cin>>n;
    char arr[n];
    for(int i=0; i<n; ++i){
        cin>>arr[i];
    }
    mergeSort(arr, 0, n-1);
    printArray(arr,n);

    return 0;
}