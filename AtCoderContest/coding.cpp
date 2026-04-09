#include<bits/stdc++.h>
using namespace std;

int main(){
    int n = 3;
    n--;
    for( int x = 0 ;x  2 * n ;x++){
        for( int y = 0 ;y <= 2 * n ; y++){
            cout<<max( abs( x- (n ) ), abs( y - ( n)) ) + 1 ;
        }
        cout<<endl;
    }
}