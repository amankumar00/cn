#include <bits/stdc++.h>
using namespace std;

vector<int> removeDups(int *a, int s)
{
    vector<int> v;
    unordered_map<int, bool> mp;
    for (int i = 0; i < s; i++)
    {
        if (mp.count(a[i]) > 0)
        {
            continue;
        }
        mp[a[i]] = true;
        v.push_back(a[i]);
    }

    return v;
}
int highestFrequency(int arr[], int n)
{
    map<int, int> mp;
    for (int i = 0; i < n; i++)
    {
        mp[arr[i]]++;
    }
    // int max =0;

    pair<int,int> max={0,0};
    for (auto i = mp.begin(); i != mp.end(); i++)
    {
        // if(i->second>max.second){
        //     max.first = i->first;
        //     max.second = i->second;
        // }
        cout<<i->first<<" "<<i->second<<endl;
    }

    return max.first;
}

int main()
{
    int s;
    cin >> s;
    int *a = new int[s];
    for (int i = 0; i < s; i++)
    {
        cin >> a[i];
    }
    // vector<int> v = removeDups(a, s);
    // for (int i = 0; i < v.size(); i++)
    // {
    //     cout << v[i] << " ";
    // }


    cout<<highestFrequency(a,s);
    return 0;
}