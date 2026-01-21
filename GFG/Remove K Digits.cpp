    #include<bits/stdc++.h>
    using namespace std;

    string removeKdig(string str , int k ) {
        
        vector<int> arr;
        for(int i= 0; i< str.size() ;i++){
            arr.push_back((int)str[i]);
        }
        int n =arr.size();
        stack<int> st;
        for(int i = 0;i < n;i++){
            
            int num = arr[i];
            
            while(!st.empty() && st.top() > num  && k > 0  ){
                st.pop();
                k--;
            }
            st.push(num);
        }
        while( !st.empty() && k > 0  ){
            k--;
            st.pop();
        }   
        string ans = "";
        while(!st.empty()){
            ans += (char) st.top();
            st.pop();
        }
        reverse(ans.begin() , ans.end() );
        return ans ;
    }
    int main(){
        string str;
        cin>> str;
        int k ;
        cin>>k;
        
        cout<<removeKdig(str,k);
        return 0;
    }