#include<bits/stdc++.h>
using namespace std;

int partition(int a[], int si, int ei){
    int sel = a[si], count = 0;
    for(int i = si+1 ; i<= ei;i++){                     //si +1 because sel is already at si
        if(a[i] <= sel) count ++;
    }
    int key = si+count;
    swap(a[si],a[key]);
    
    int i = si, j=ei;

    while(i < key && j > key){
        if(a[i]<=a[key])i++; 
        else if(a[j]>a[key]) j--;
        else {swap(a[i++],a[j--]);}
    }
    return key ;
}

void quickSort(int a[], int si, int ei){
    if(si>=ei) return;
    int c = partition(a,si,ei);
    quickSort(a,si,c-1);
    quickSort(a,c+1,ei);
}

int main()
{
    int n;
    cin>>n;
    int *a = new int[n];
    for(int i=0;i<n;i++){
        cin>>a[i];   
    }
    // partition(a,0,n-1);
    quickSort(a,0,n-1);
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";   
    }
    return 0;
}