class Solution {
public:
    int n ;
    set<string>words;
    int dp[52];
    int fun( int i , string str) {
        if(i < 0 ) return 0;
        int ans = 1e9 ;
        if(dp[i] != -1 ) return dp[i];     
        for(int j = 0;j <= i  ; j+=1 ) {
            int len = i-j+1;
            string current = str.substr(j , len ) ;
            if( words.find(current) != words.end() ) {
                ans = min(ans , fun( j -1 , str ) );
            }
            else
                ans = min(ans , fun( j -1 , str ) + len  );
        }
        return dp[i]= ans;
    }
    int minExtraChar(string s, vector<string>& dictionary) {
        n =s.size();
        for(string str : dictionary) words.insert(str);
        memset(dp,-1 ,sizeof(dp));
        int res = fun(n-1 , s );
        return  res ;

    }
};