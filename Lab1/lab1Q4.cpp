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
        return (array[left]==stat);
    }

    // use median and split array into 2
    int med=(array[left]+array[right])/2;
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
        if(stat<=med && lsum>=stat){
            return recursion(left,ind -1, array, stat);
        }
        else if(rsum>=stat){
            bool check= recursion(ind,right, array, stat);
            if(check==true){
                return true;
            }
            else{
                if(lsum>=stat){
                  return recursion(left,ind -1, array, stat);
                }
                else{
                    return false;
                }
            }
        }
        else{
            return false;
        }
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