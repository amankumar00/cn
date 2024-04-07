
#include <iostream>
#include <vector>
#include<bits/stdc++.h>
using namespace std;
class Runner
{
    int t;
    vector<vector<int>> arrs;
    vector<int> ns, ks;

public:
    void takeInput()
    {
        cin >> t;
        for (int i = 0; i < t; i++)
        {
            int n, k;
            cin >> n >> k;

            vector<int> arr(n);
            for(int i = 0; i < n; i++) 
            {
                cin >> arr[i];
            }

            ns.push_back(n);
            ks.push_back(k);
            arrs.push_back(arr);
        }
    }

    void execute()
    {
        vector<vector<int>> arrsCopy = arrs;
        vector<int> nsCopy = ns;
        vector<int> ksCopy = ks;
        for (int i = 0; i < t; i++)
        {
            vector<int> result = kthSmallLarge(arrsCopy[i], nsCopy[i], ksCopy[i]);
        }
    }

    void executeAndPrintOutput()
    {
        for (int i = 0; i < t; i++)
        {
            vector<int> result = kthSmallLarge(arrs[i], ns[i], ks[i]);
            cout << result[0] << ' ' << result[1] << '\n';
        }
    }
};

int main()
{   
    Runner runner;
    runner.takeInput();
    runner.executeAndPrintOutput();
    return 0;
}

vector<int> kthSmallLarge(vector<int> &arr, int n, int k)
{
	vector<int> v;
	sort(arr.begin() , arr.end());
	v.push_back(arr[k]);
	v.push_back(arr[n-k]);
	return v;
}