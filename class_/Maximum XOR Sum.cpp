// 2. Maximum XOR Sum of a “Good” Subsequence
// You are given an array A of N integers (1-based indexing). You need to find the maximum possible XOR sum of any good subsequence of the array.
// What is a “Good” Subsequence?
// A subsequence S is called good if it satisfies this condition: For every element taken from position i in the original array, the element at the mirrored position N - i + 1 must also be taken.

// Notes:
// You may choose to exclude or include any index but inclusion must be symmetric. If i == N - i + 1 (middle element in odd-length array), it can be chosen independently

// Input Format:
// N
// A1 A2 A3 ... AN
// Where:
// N → number of elements
// Ai → array elements

// Output Format:
// Maximum XOR sum of a good subsequence

// Sample Input:
// 4
// 1 2 3 4

// Sample Output:
// 4

// Explanation:
// Index:  1  2  3  4
// Value:  1  2  3  4
// Mirror: 4  3  2  1

// Possible mirrored pairs:
// (1,4) → values (1,4) → XOR = 1 ⊕ 4 = 5
// (2,3) → values (2,3) → XOR = 2 ⊕ 3 = 1
// We can choose any subset of mirrored pairs.

// Trying combinations:
// Pick only (1,4) → XOR = 5
// Pick only (2,3) → XOR = 1
// Maximum XOR = 5
// But note:
// Including both pairs cancels some bits, so best choice is only (1,4) → result 5.


#include<bits/stdc++.h>
using namespace std;

void solve(){
    int n ;
    cin>>n;
    vector<int>arr(n);
    for(int i = 0 ;i < n ;i++){
        cin>>arr[i];
    }

    vector<int> mirror( n );
    int i= 0 , j = n-1;
    while( i < j )
    {
        mirror.push_back( arr[i]^ arr[j] );
        i++;
        j--;
    }
    int ans;
    if(i==j){
        ans = arr[i];
        mirror.push_back(arr[i]);
    }
    else ans = 0 ;
    for(int a :  mirror) {
        ans = max( ans , a ) ;
    }
    cout<<ans;

}
int main(){
    solve();
    return  0 ;
}