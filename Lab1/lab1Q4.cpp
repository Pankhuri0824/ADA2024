#include <iostream>
#include <algorithm>
#include <string>
#include <set>
#include<vector>
#include <map>
#include <unordered_map>
#include <climits>
 
using namespace std;
 
bool recursion(long long int left,long long int right,vector<long long int>& array,long long int stat,vector<long long int>& temp){
    if((right==left)){
        return (array[left]==stat);
    }

    // use median and split array into 2
    long long int med=(array[left]+array[right])/2; 
    //1 2 3 4 5 -> 3 -> 123 , 45-> we need to divide by med ele ind+1 = something just bigger than that which is upper bound
    auto medd= upper_bound(array.begin() + left, array.begin() + right + 1,med);
    long long int medit =distance(array.begin(), medd);
    long long int lsum=0;
    if (left!=0){
        lsum=temp[medit-1]-temp[left-1];
    }
    else{ lsum=temp[medit-1];}
    long long int rsum=temp[right]-temp[medit-1];
 
    
    if(lsum==stat || rsum==stat || rsum+lsum==stat){
        return true;
    }
    else if(array[left]==array[right]){
        return false;
    }
    else{
        if(stat<=med && lsum>=stat){
            return recursion(left,medit -1, array, stat,temp);
        }
        else if(rsum>=stat){
            bool check= recursion(medit,right, array, stat,temp);
            if(check==true){
                return true;
            }
            else{
                if(lsum>=stat){
                  return recursion(left,medit -1, array, stat,temp);
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
    long long int t;// test cases
    cin>>t;
    for(int test=0;test<t;test++){
        long long int n,q;
        cin>>n>>q; //n=no of pokemons, q=lenth of oak's array
 
        vector<long long int> arr(n);//friendliness stat of n pokemons
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
 
        sort(arr.begin(),arr.end());
 
        vector<long long int> add(n);
        long long int temp=0;
        for(int i=0;i<n;i++){
            temp+=arr[i];
            add[i]=temp;
        }
 
        for(int i=0;i<q;i++){ //q=number of queries
            long long int a;
            cin>>a;
            if(n==1){
                if(a==arr[0]){
                    cout<<"YES"<<endl;
                }
                else{
                    cout<<"NO"<<endl;
                }
            }
            else{
                if(recursion(0,n-1, arr, a,add)){
                cout<<"Yes"<<endl;
                }
                else{
                    cout<<"No"<<endl;
                }
            }
        }
 
    }
    return 0;
 
}