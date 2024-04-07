#include<bits/stdc++.h>
using namespace std;

void solve(int n){

    // base case
    if(n==1){
        cout<<1;
        return;
    }
    cout<<n;
    solve(n-1);
    
}

int main()
{
    char c;
    cin>>c;
    cout<<typeid(c-'0').name();
    return 0;
}