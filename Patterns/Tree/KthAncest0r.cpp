#include<bits/stdc++.h>
using namespace std;
vector<int> parent;
int n ;
int MAX = 16;
vector<vector<int>>table;
void build(){

    table.resize(MAX);
    for(int i =0 ; i < n ;i++){
        table[0][i] = parent[i];
    }

    for(int i =0 ; i < MAX ; i++){
        for(int j = 0 ;j < n ;j++){
            table[i][j] = table[i-1][table[i-1][j]];
        }
    }
}
int query(int a, int k){
    
    for(int i = 0 ; i < MAX ;i++){
            int mask = ( 1 << i );
            if(k & mask ){
                a = table[i][a];
            }
    }
    return a;
}


int main(){
    cin>>n;
    parent.resize(n);
    for(int i = 0 ; i < n ;i++)
        cin>>parent[i];
    
    build();
    return 0;
}