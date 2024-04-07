#include <bits/stdc++.h>
using namespace std;

void replacePi(char input[]) {
	if(input[0]=='\0') return;
    string s;
    s= input;
    int ind = 0;
    ind = s.find("pi");
    if(ind!=-1){
    string s1 = s.substr(0,ind);
    string s2 = s.substr(ind+2);
    s = s1 + "3.14" + s2;
    for(int i = 0;i<s.size();i++){
        input[i] = s[i];
        }

    replacePi(input+ind+4);
    }
    else{
        replacePi(input+1);
    }
}




int main() {
    char input[10000];
    cin.getline(input, 10000);
    replacePi(input);
    cout << input << endl;
}
