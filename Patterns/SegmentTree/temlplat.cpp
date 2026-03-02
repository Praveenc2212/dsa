
#include<bits/stdc++.h>
using namespace std;

#define int long long

struct Node{
    int sum;
    Node(){
        sum = 0;
    }
    Node(int x ){
        sum = x ;
    }
};

Node merge(Node a ,Node b){
        Node c;
        c.sum = a.sum + b.sum;
        return c;
}

struct Segtree{
    vector<Node> sums;
    int sz;

    void init(int n){
        sz = 1;
        while(sz <= n)
            sz *= 2;
        sums.resize(sz * 2);
    }
    
    void build(vector<int> nums){
        build(0,sz,0,nums);
    }

    void build(int lx ,int rx ,int x ,vector<int>& nums){
        if(rx - lx == 1){
            if(lx < nums.size())
                sums[x].sum = nums[lx];
        return ;
        }

        int mi = (rx - lx)/2 + lx;
        build(lx,mi,x*2+1,nums);
        build(mi,rx,x*2+2,nums);

        sums[x] = merge(sums[x*2+1],sums[x*2+2]);
    }

    void set(int idx ,int val){
        set(0,sz,0,idx,val);
    }

    void set(int lx ,int rx ,int x ,int idx ,int val){
        if(rx - lx == 1){
            sums[x].sum = val;
            return ;
        }

        int mi = (rx - lx)/2 + lx;
        if(idx < mi)
            set(lx,mi,x*2+1,idx,val);
        else
            set(mi,rx,x*2+2,idx,val);

        sums[x] = merge(sums[x*2+1],sums[x*2+2]);
    }

    Node getRange(int l ,int r){
        return getRange(0,sz,0,l,r);
    }

    Node getRange(int lx ,int rx ,int x ,int l ,int r){
        if(lx >= r || rx <= l)
            return Node();
        if(lx >= l && rx <= r)
            return sums[x];

        int mi = (rx - lx)/2 + lx;
        return merge(getRange(lx,mi,x*2+1,l,r),getRange(mi,rx,x*2+2,l,r));
    }

};
