#include<iostream>
using namespace std;


int findInd(int input[], int size,int x,int output[], int ind){
    if(size == 0) return 0;

    if(input[0]==x){
        output[0] = ind;
        cout<<ind;
        return 1+ findInd(input+1, size-1, x, output+1, ind+1);
    }
    else{
        return findInd(input+1,size-1,x,output, ind+1);
    }
}

int allIndexes(int input[], int size, int x, int output[]) {
    int ans = findInd(input,size,x,output,0);
    return ans;
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
    
    int *output = new int[n];
    
    int size = allIndexes(input, n, x, output);
    for(int i = 0; i < size; i++) {
        cout << output[i] << " ";
    }
    
    delete [] input;
    
    delete [] output;
    

}


