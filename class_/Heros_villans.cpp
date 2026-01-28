/*
3. Heroes vs Villains – Minimum Villains to Remove
You are given:

A list of villains, each with a certain health . A list of heroes, each with a certain health.

Battle Rules
Heroes fight in order
Villains are fought from the front of the queue only
Hero i fights Villain i

A hero wins if:
hero_health > villain_health and then hero_health -= villain_health
If a hero’s health is ≤ villain’s health, the hero is defeated and the battle stops.

Allowed Operation
You are allowed to remove some villains from the front of the villain list before the battle starts.

Determine the minimum number of villains to remove from the front so that all remaining villains are defeated by the heroes. If it is impossible, output -1.

Input Format:
N
H1 H2 H3 ... HN
M
V1 V2 V3 ... VM
Where:
N → number of heroes
Hi → health of each hero
M → number of villains
Vi → health of each villain

Output Format:
Minimum number of villains to remove

Sample Input:
3 
10 5 7 
4
3 8 2 4

Sample Output:
1

Explanation:
Remove 3 (first villain).
Remaining villains:	
[8, 2, 4]
Battle simulation:
Hero 1 (10) vs 8 → wins, remaining = 2
Hero 2 (5)  vs 2 → wins, remaining = 3
Hero 3 (7)  vs 4 → wins, remaining = 3
All villains defeated, Minimum removals = 1
*/
#include<bits/stdc++.h>
using namespace std;
bool check(int del , vector<int>arr1 , vector<int>arr2) {

    int n1 = arr1.size() , n2 = arr2.size();
    int i = 0 , j = del  , f = 1;
    if( n1 <  n2 - del  ) {
        return false;
    }
    int points = 0 ;
    while( i < n1 && j < n2  ){
        
        if( arr1[i] > arr2[j] ){
            i++;
            // points = points  +arr1[i] - arr2[j];
            j++;
        }
        else{
            return false;
        }
    }
    return j >= n2  ;
}
int main(){

    int n1, n2 ;
    cin>>n1;
    vector<int>hero(n1);
    for(int i = 0 ;i < n1 ; i+=1) {
        cin>>hero[i];
    }
    cin>>n2;
    vector<int>villans(n2);
    for(int i = 0 ;i < n2 ; i+=1) {
        cin>>villans[i];
    }
    int low = 0 , high = n2 ;
    int ans = n2 ;
    while( low <= high ) {
        int mid = low + (high - low ) / 2 ;
        if(check( mid , hero , villans )){
            ans = mid ;
            high = mid - 1 ;
        }
        else{
            low = mid + 1 ;
        }
    }
    cout<<ans;
    return  0 ;
}


// You are given two arrays:

// heroes, where heroes[i] represents the health of the iᵗʰ hero

// villains, where villains[j] represents the health of the jᵗʰ villain

// Battle Rules

// Heroes fight in order, starting from index 0.

// Villains are faced in order, starting from the front of the list.

// After removing some villains, Hero i fights Villain i.

// A hero defeats a villain only if:



// hero_health > villain_health

// After winning, the hero’s remaining health becomes:

// hero_health -= villain_health

// 5 . If a hero’s health is less than or equal to the villain’s health, the hero is defeated and the battle stops immediately.