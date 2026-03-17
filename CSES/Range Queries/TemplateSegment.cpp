#include<bits/stdc++.h>
using namespace std;

int n , q ;

struct Node{
    int sum ; 
    
    Node(){
        sum = 0 ;
    }
    Node(int a ){
        sum = a ;
    }

    
};

Node merge( Node a , Node b ){
    Node c;
    c.sum =  a.sum + b.sum;
    return c;
}
struct SegmentTree{
    int sz ;
    vector<Node> seg;

    void init( int n ){
        sz = n ;
        seg.resize( sz * 4 + 5 , Node() );
    }


    void build( int si , int low , int high , vector<int>& arr ){
        
        if( low == high ) {
            seg[si].sum = arr[low];
            return ;
        }
        int mid = ( low + high ) / 2 ;
        build(si*2+1, low , mid , arr ) ;
        build(si*2+2 , mid + 1 , high  , arr ) ;

        seg[si] = merge( seg[si*2+1] , seg[si*2+2] );
    }

    Node query(int si , int low , int high , int l , int r ){

        if( r < low || high < l ){
            return Node() ;
        }

        if( l <= low && high <= r ){
            return seg[si];
        }
        int mid = ( low + high ) / 2 ;
        
        Node left = query( si*2+1 , low , mid , l, r );
        Node right = query( si*2+2 , mid + 1 , high , l ,r  );

        return merge(left , right);
    }
    int getSum( int l , int r ){
        return query( 1 , 0 ,sz -1 , l ,r ).sum;
    }

    void updateOnPoint( int si , int low , int high , int pos , int val ){

        if( low == high ){
            // arr[low] = val;
            seg[si].sum = val ;
            return ;
        }
        int mid = ( low + high ) / 2 ;
        if( pos <= mid )    
            updateOnPoint( si *2 + 1 , low , mid , pos , val );
        else   
            updateOnPoint(si* 2 + 2 , mid + 1 ,high , pos ,val );
        seg[si] = merge( seg[si*2+1] , seg[si*2+2 ] );
    }
    void pointUpdate( int index , int value ){

        updateOnPoint( 0 , 0, sz -1 , index , value );  

    }
};
int main(){ 

    cin>>n>>q;
    vector<int> arr( n );
    for( int i=0;i < n ;i +=1 ) 
        cin>>arr[i];
    
    SegmentTree st;
    st.init( n );
    st.build( 1 , 0, n-1 , arr) ;
    cout<<st.getSum( 0 , 4 )<<endl;   
    arr[2] = 5 ;
    st.pointUpdate( 2 , 5  );
    cout<<st.getSum( 0 , 4 );   
    return 0;
}