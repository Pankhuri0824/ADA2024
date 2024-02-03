#include <iostream>
#include <algorithm>
#include <string>
#include <set>
#include <vector>
#include <map>
#include <unordered_map>
#include <climits>

using namespace std;

bool recursion(vector<int> &arr, int index, vector<int> &subarr, int n, int d){
    if (index==n) {//idk but works?? 
        int sum =0;
        for(int j=0; j<n; j++){
            sum += subarr[j];
        }

        if(sum % d == 0){
            return true;
        }
        else{
            return false;
        }
    }
    else{
        subarr.push_back(arr[index]); //pick
        if(recursion(arr, index + 1, subarr, n, d)){
            return true; // true from recursion hence truw for all
        }
        subarr.pop_back(); 

        if(recursion(arr, index + 1, subarr, n, d)){ //not pick
            return true; 
        }
    }

    return false; //no cond met
}

int main()
{
    int t; // test cases
    cin >> t;
    for (int test = 0; test < t; test++)
    {
        int n,d;
        cin>>n>>d;
        vector<int> nums(n);
        vector<int> subnums;
        int total = 0;

        for (int i = 0; i < n; i++){
            cin>>nums[i];
            total+=nums[i];
        }

        if(n==1){
            cout<<"NO"<<endl;
        }
        else{
            bool check = recursion(nums,0,subnums,n,d);
            if(check){
                cout<<"YES"<<endl;
            }
            else{
                cout<<"NO"<<endl;
            }
        }

    }
    return 0;
}
