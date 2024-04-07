#include<bits/stdc++.h>
using namespace std;

int main()
{

    string s;
    cin>>s;
    int count =0;
    map<char, int> mp;
    for(int i=0;i<s.length();i++){
        if(s[i]>='A'&&s[i]<='Z'){
            if(!mp[s[i]]){
                mp[s[i]]++;
            }
        }
        else if(s[i]>='a'&&s[i]<='z'){
            if(!(mp[s[i]-32])){
                    count++;
            }
        }
    }
    cout<<count;
    return 0;
}