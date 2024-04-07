#include<bits/stdc++.h>
using namespace std;
int searchX(int a[], int n, int x){
    if(n==0){
        return -1;
    }
    if(a[0]==x) return 0;
    int small_index = searchX(a+1,n-1,x);
    if (small_index==-1) {
        return -1;
    }
    else {return small_index +1;}
    }
int main()
{
    int n,x;
    cin>>n>>x;
    int a[100];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    cout<<searchX(a,n,x);   
    return 0;
}