#include<bits/stdc++.h>
using namespace std;

int lastIndex(int input[], int size, int x) {
    if(size==0) return -1;
    int small_index = lastIndex(input, size-1, x);
    if(input[size]==x) return size;
    if(small_index==-1)
        { if(input[0]==x)return 0;
            else return -1;
        }
    else 
        {return small_index;}
    
}

int main(){
    int n;
    cin >> n;
  
    int *input = new int[n];
    
    for(int i = 0; i < n; i++) {
        cin >> input[i];
    }
    
    int x;
    
    cin >> x;
    
    cout << lastIndex(input, n, x) << endl;

}

