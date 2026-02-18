#include<bits/stdc++.h>
using namespace std;
vector<int> arr;

struct Node{
    int maxxFreq;
    map<int,int> mp;

    Node(){

    }
};
vector<Node*> seg;
Node* merge(Node* a , Node *b){
    int ans = 0;
    for( auto it : b.mp ){
        a.mp[it.first] += it.second; 
    }
    for(auto it : a.mp ){
        ans= max( ans , it.second);
    }
    a.maxxFreq = ans ;

    return a;
}
Node* make_merge(int a ){
    Node* node = new Node();
    node.maxxFreq = 1 ;
    map<int,int> mpp;
    mpp[a]++;
    node.mp = mp;
}

void build( int si ,int low ,int high){

    if( low == high){
        seg[si] =  make_merge( arr[low]);
        return ;
    }
    int mid = (low + high )/ 2 ;

    build( si *2 + 1 , low , mid ) ;
    build( si * 2 +2 , mid + 1 , high );

    seg[si] = merge( seg[si* 2 + 1] , seg[si*2 + 2 ]);
}
Node* query(int si , int low ,int high , int l , int r ){

    if( r < low || high < r ){
        return nullptr;
    }

    if( l <= low &&  high <= r ){
        return seg[si];
    }

    int mid = ( low + high ) / 2 ;
     
    Node* left = qury( si* 2 + 1 , low , mid , l ,r );
    Node* right = qury( si*  2 + 2 , mid + 1, high , l ,r );
    return make_merge( left , right );
}
int main(){
    int n ;
    cin>>n;
    arr.resize( n );

    for(int i = 0 ;i < n ; i+=1 )
        cin>>arr[i];

    int q;
    cin>>q;
    while(q--){
        int l , r ;
        cin>>l >>r ;
        Node* node = query(0 , 0, n-1 , l, r );
        cout<<node.first<<endl;
    }
    return 0;
}

/*
#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100005;

int arr[MAXN];
int freq[MAXN];
int countFreq[MAXN];

int block;
int currentMaxFreq = 0;

struct Query {
    int l, r, idx;
};

bool cmp(Query a, Query b) {
    if (a.l / block != b.l / block)
        return a.l < b.l;
    return a.r < b.r;
}

void add(int pos) {
    int val = arr[pos];

    countFreq[freq[val]]--;
    freq[val]++;
    countFreq[freq[val]]++;

    currentMaxFreq = max(currentMaxFreq, freq[val]);
}

void remove_(int pos) {
    int val = arr[pos];

    countFreq[freq[val]]--;
    if(freq[val] == currentMaxFreq && countFreq[freq[val]] == 0)
        currentMaxFreq--;

    freq[val]--;
    countFreq[freq[val]]++;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, q;
    cin >> n;

    for(int i = 0; i < n; i++)
        cin >> arr[i];

    cin >> q;

    block = sqrt(n);

    vector<Query> queries(q);

    for(int i = 0; i < q; i++) {
        cin >> queries[i].l >> queries[i].r;
        queries[i].idx = i;
    }

    sort(queries.begin(), queries.end(), cmp);

    vector<int> answer(q);

    int curL = 0, curR = -1;

    for(auto &qr : queries) {

        while(curR < qr.r) add(++curR);
        while(curR > qr.r) remove_(curR--);

        while(curL < qr.l) remove_(curL++);
        while(curL > qr.l) add(--curL);

        answer[qr.idx] = currentMaxFreq;
    }

    for(int i = 0; i < q; i++)
        cout << answer[i] << "\n";

    return 0;
}
*/