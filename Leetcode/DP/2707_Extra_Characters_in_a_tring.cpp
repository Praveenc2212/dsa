/*
2707. Extra Characters in a String
You are given a 0-indexed string s and a dictionary of words dictionary. You have to break s into one or more non-overlapping substrings such that each substring is present in dictionary. There may be some extra characters in s which are not present in any of the substrings.

Return the minimum number of extra characters left over if you break up s optimally.
Example 1:

Input: s = "leetscode", dictionary = ["leet","code","leetcode"]
Output: 1
Explanation: We can break s in two substrings: "leet" from index 0 to 3 and "code" from index 5 to 8. There is only 1 unused character (at index 4), so we return 1.

Example 2:

Input: s = "sayhelloworld", dictionary = ["hello","world"]
Output: 3
Explanation: We can break s in two substrings: "hello" from index 3 to 7 and "world" from index 8 to 12. The characters at indices 0, 1, 2 are not used in any substring and thus are considered as extra characters. Hence, we return 3.
*/

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