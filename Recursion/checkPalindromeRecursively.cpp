#include<bits/stdc++.h>
using namespace std;
bool isPalindrome(int a[], int n){
    if(n==0||n==1){return true;}

    if(a[0]!=a[n-1]){return false;}

    bool small_answer = isPalindrome(a+1,n-2);
    return small_answer;
}
int main()
{
    int n;
    cin>>n;
    int a[n];
    for (int i=0;i<n;i++){
        cin>>a[i];
    }
    cout<<(isPalindrome(a,n)?"true":"false");
    return 0;
}