#include<bits/stdc++.h>
using namespace std;

string str;

bool fun( int index , int find  ){

    if(  find == 2 ){
        return true;
    }

    
    if( index + 1 < n ){

        if( find != 1 &&   str[index]=='A' && str[index+ 1] == "B" ){
            if(fun(index + 2 ,  1  )){
                return true;
            }
        }
        if( find != 2 &&  str[index] == "B" && str[indx+ 1 ]== "A" )  {
            if(fun(index+2  , 2 )){
                return true;
            }
        }
    }
    return false;
}
int main(){

    cin>>str;

    int res = fun( 0 ); 

    return 0;
}