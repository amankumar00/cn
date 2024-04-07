#include<iostream>
using namespace std;

int find(int a[], int si, int ei, int t){
    if(si>ei) return -1;
    int mid = (si+ei)/2;
    if(a[mid]==t) return mid;
    if(t>a[mid]){
        find(a,mid+1,ei,t);
    }
    else find(a,si,mid-1,t);
}  

int main()
{
    int n,t;
    cin>>n>>t;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    int si = 0, ei = n;
    cout<<find(a,si,ei,t);
    return 0;
}