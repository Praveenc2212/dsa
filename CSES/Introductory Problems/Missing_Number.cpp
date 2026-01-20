#include<bits/stdc++.h>
using namespace std;

int main(){
    long long n ;
    cin>>n;
    long long sum = 0;
    for(long long i=0;i<n-1;i++) {
        long long a ;
        cin>>a;
        sum+=a;
    }
    long long total = ((long long) n *(long long) (n+1) ) /2;
    cout<<total - sum  << endl ;

    return 0 ;
}