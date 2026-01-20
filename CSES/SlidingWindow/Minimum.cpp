#include<bits/stdc++.h>
#define ll long long 
using namespace std;

void solve(){
    long long n , k, x ,a ,b ,c ;
    cin>>n>>k;
    cin>>x>>a>>b>>c;
    vector<ll>arr(n);
    arr[0] = x;
    for(int i= 1 ;i < n ;i++)
        arr[i] = ( a * arr[i-1] +b ) % c ;
    
  deque<int> dq;

  for(int i=0;i < k ;i++){
        // 1 4 6 9
        while( !dq.empty() && arr[dq.back()] >= arr[i] ){
            dq.pop_back();
        }
        dq.push_back(i);
  }
  long long ans = arr[dq.front()];
  for(int i=k;i < n; i++){
        
      if(dq.front() <= i-k ){
          dq.pop_front();
      }
        while(!dq.empty() && arr[dq.back()] >= arr[i] )
            dq.pop_back();
        dq.push_back(i);
        ans ^= arr[dq.front()];
  }
  cout<<ans<<endl;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1 ;
    while(t--){
        solve();
    }
    return 0;
}