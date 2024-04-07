#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> v; // static allocation
    //  vector<int> *vp = new vector<int>();   //dynamic allocation

    v.push_back(10);
    v.push_back(20);
    v.push_back(30);

    v[1] = 100;
    v[3] = 1002;
    v[4] = 1234;
    v.push_back(23);
    v.push_back(234);
    cout << v[0] << endl;
    cout << v[1] << endl;
    cout << v[2] << endl;
    cout << v[3] << endl;
    cout << v[4] << endl;
    cout << v[5] << endl;
    cout << v[6] << endl;
    return 0;
}