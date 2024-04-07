#include <bits/stdc++.h>
using namespace std;

int stringToNumber(char input[]) {
    // Write your code here
    if(input[0]=='\0'){
        return 0;
    }
    if(input[0]=='0'){
        stringToNumber(input +1);
    }

    
    int small_sum = (input[0]-'0');
    int pow = 1;
    for(int i=1;input[i]!='\0';i++){
        pow*=10;
    }
    // cout<< small_sum<<endl;
    return pow*small_sum +  stringToNumber(input+1); 
    // cout<<(input[0]-'0')<<endl;
}




int main() {
    char input[50];
    cin >> input;
    cout << stringToNumber(input) << endl;

    // cout<<input[0]-'0';
}
