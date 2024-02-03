#include <iostream>
#include <algorithm>
#include <string>
#include <set>
#include<vector>
#include <map>
#include <unordered_map>
#include <climits>
 
using namespace std;

bool recursion(int left,int right,vector<int>& array,int stat){
    //median by max and min (traverse array once)
    if((right==left)){
        if(array[left]==stat){
            return true;
        }
        else{
            return false;
        }
    }
  
    int mini=INT_MAX;
    int maxi=INT_MIN;
    for(int k=left;k<=right;k++){
        maxi=max(maxi,array[k]);
        mini=min(mini,array[k]);
    }

    // use median and split array into 2
    int med=(maxi+mini)/2;
    int lsum=0;
    int rsum=0;
    int ind=left;
    for(int j=left;j<=right;j++){
        if(array[j]<=med){
            lsum+=array[j];
            ind++;
        }
        else{
            rsum+=array[j];
        }
    }

    if(lsum==stat || rsum==stat || rsum+lsum==stat){
        return true;
    }
    else if(array[left]==array[right]){
        return false;
    }
    else{
        return recursion(left,ind -1, array, stat) || recursion(ind,right, array, stat);
    }

}
 
int main(){
    int t;// test cases
    cin>>t;
    for(int test=0;test<t;test++){
        int n,q;
        cin>>n>>q; //n=no of pokemons, q=lenth of oak's array

        vector<int> arr(n);//friendliness stat of n pokemons
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }

        sort(arr.begin(),arr.end());

        for(int i=0;i<q;i++){ //q=number of queries
            int a;
            cin>>a;
            bool ans=recursion(0,n-1, arr, a);
            if(ans==true){
                cout<<"Yes"<<endl;
            }
            else{
                cout<<"No"<<endl;
            }
        }

    }
    return 0;
 
}