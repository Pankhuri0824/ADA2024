#include <iostream>
#include <algorithm>
#include <string>
#include <set>
#include<vector>
#include <map>
#include <unordered_map>
#include <climits>
 
using namespace std;

void recursion1(int left,int right,vector<int>& array,set<int>& s1){
    if(left==right){
        return;
    }

    int med=(array[left]+array[right])/2;

    int lsum=0;
    int rsum=0;
    int ind=left;

    for(int j=left;j<=right;j++){
        if(array[j]<=med){
            lsum+=(array[j]);
            ind++;
        }
        else{
            rsum+=(array[j]);
        }
    }

    s1.insert(lsum);
    s1.insert(rsum);
    s1.insert(lsum+rsum);

    if(array[left]==array[right]){
        return;
    }
    recursion1(left,ind-1,array,s1);
    recursion1(ind,right,array,s1);
}
 
int main(){
    long long int t;// test cases
    cin>>t;
    for(int test=0;test<t;test++){
        int n,q;
        cin>>n>>q; //n=no of pokemons, q=lenth of oak's array
 
        vector<int> arr(n);//friendliness stat of n pokemons
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
 
        sort(arr.begin(),arr.end());
        set<int> possible;
        recursion1(0,n-1,arr,possible);

 
        for(int i=0;i<q;i++){ //q=number of queries
            int a;
            cin>>a;
            if(possible.find(a)!=possible.end()){
                cout<<"Yes"<<endl;
            }
            else{
                cout<<"No"<<endl;
            }
        }
 
    }
    return 0;
 
}