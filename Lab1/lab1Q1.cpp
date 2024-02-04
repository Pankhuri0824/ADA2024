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
        // cout<<index<<endl;
        if (index==n) {//idk but works??  
            if(subarr.size()!=0){
                int sum =0;
                for(int j=0; j<n; j++){
                    sum += subarr[j];
                // cout<<subarr[j]<<" ";
                }
                // cout<<" "<<endl;
                if(sum % d == 0){
                    // cout<<"true"<<endl;
                    return true;
                }
                else{
                    return false;
                }
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
            else{
                // cout<<"false"<<endl;
                return false;
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

        if(n==1 || n==0){
            cout<<"NO"<<endl;
        }
        if(n==2){
            bool c=true;
            if(nums[0]%d!=0) c=false;
            else if(nums[1]%d!=0) c=false;

            if(c) cout<<"YES"<<endl;
            else cout<<"NO"<<endl;
        }
        else{

            bool check=true;
            for(int i=0;i<n;i++){
                int remind=i; //remove index NOT REMIND
                vector<int> checker=nums;
                checker.erase(checker.begin()+remind);
                check = check||recursion(checker,0,subnums,n-1,d);
                if(check==false) break;
            }
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