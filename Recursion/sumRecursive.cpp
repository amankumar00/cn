#include<iostream>
using namespace std;

int sumN(int n){
    if(n == 0) return 0;
    int small_sum = (n%10);

    return  10 * sumN(n/10)+  small_sum;
}

int main()
{
    int n;
    cin>>n;
    cout<<sumN(n);
    return 0;
}