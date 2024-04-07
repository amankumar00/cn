#include<bits/stdc++.h>
using namespace std;

int main()
{
    unordered_map<string, int> mp;
    pair<string, int> p("abc",1);
    mp.insert(p);
    mp["def"] =2;

    cout<<mp["def"]<<endl;
    cout<<mp.at("abc")<<endl;
    //mp.count used to check if a key is present or not
    cout<<mp.count("ghi");
    return 0;
}