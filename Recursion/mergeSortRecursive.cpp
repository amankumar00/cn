#include<bits/stdc++.h>
using namespace std;

void merge(int a[], int si, int ei){
    int mid = (ei+si)/2;
    int * temp = new int [ei-si+1];
    int i=si,j=(mid+1),k=0;
    while((i<=mid)&&(j<=ei)){
        if(a[i]<=a[j]){
            temp[k] = a[i];
            i++;
            k++;
        }
        else{
            temp[k] = a[j];
            j++;
            k++;
        }
    }
    while(i<=mid){
        temp[k] = a[i];
        i++;
        k++;
    }
    while(j<=ei){
        temp[k] = a[j];
        j++;
        k++;
    }
    int m=0;
    while(m<k){
        a[si+m] = temp[m];
        m++;
    }
    delete[] temp;
}

void mergeSort(int a[],int si, int ei){
     if(si>=ei){
        return;
     }   
    int mid = (si+ei)/2;
    mergeSort(a,si,mid);
    mergeSort(a,mid+1,ei);
    merge(a,si,ei);
    
}

int main()
{
    int n;
    cin>>n;
    int * a = new int[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    mergeSort(a,0,n-1);

    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";   
    }
    return 0;
}