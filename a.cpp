#include<bits/stdc++.h>
using namespace std;

int main()
{
    unordered_map<string,int> m;
	m["Integer"]= 1;	
	m["Long"]=2;
	m["Float"] =3;
	m["Double"]=4;
	m["Character"] =5;
	string s;
	cin>>s;
	switch(m[s]){
		
		case 1 : cout<<4;
						break;
		case 2 : cout<<8;
						break;
		case 3 : cout<<4;
						break;
		case 4 : cout<<8;
						break;
		case 5 : cout<<1;
						break;
		default: break;
	}
    return 0;
}