// #include <iostream>
// #include <algorithm>
// #include <string>
// #include <set>
// #include<vector>
// #include <map>
// #include <unordered_map>
// #include <climits>
 
// using namespace std;

// vector<int> slicing(vector<int>& arr,int X, int Y)
// {
 
//     // Starting and Ending iterators
//     auto start = arr.begin() + X;
//     auto end = arr.begin() + Y + 1;
 
//     // To store the sliced vector
//     vector<int> result(Y - X + 1);
 
//     // Copy vector using copy function()
//     copy(start, end, result.begin());
 
//     // Return the final sliced vector
//     return result;
// }


// bool recursion(int len,vector<int>& array,int stat){
//     //median by max and min (traverse array once)
//     if(len==1){
//         if(array[0]==stat){
//             return true;
//         }
//         else{
//             return false;
//         }
//     }

//     // use median and split array into 2
//     int med=(array[0]+array[len-1])/2;
//     int lsum=0;
//     int rsum=0;
//     int ind=-1; //of median for slicing
//     for(int j=0;j<len;j++){
//         if(array[j]<=med){
//             lsum+=array[j];
//             ind++;
//         }
//         else{
//             rsum+=array[j];
//         }
//     }

//     if(lsum==stat || rsum==stat || rsum+lsum==stat){
//         return true;
//     }
//     else if(array[0]==array[len-1]){
//         return false;
//     }
//     else{
//         return recursion(ind+1, slicing(array, 0, ind+1).data(), stat) || 
//         recursion(len-ind-1, slicing(array,ind+1,len).data(), stat);
//     }

// }
 
// int main(){
//     int t;// test cases
//     cin>>t;
//     for(int test=0;test<t;test++){
//         int n,q;
//         cin>>n>>q; //n=no of pokemons, q=lenth of oak's array

//         vector<int> arr(n);//friendliness stat of n pokemons
//         for(int i=0;i<n;i++){
//             cin>>arr[i];
//         }

//         sort(arr.begin(),arr.end());

//         for(int i=0;i<q;i++){ //q=number of queries
//             int a;
//             cin>>a;
//             bool ans=recursion(n, arr.data(), a);
//             if(ans==true){
//                 cout<<"Yes"<<endl;
//             }
//             else{
//                 cout<<"No"<<endl;
//             }
//         }

//     }
//     return 0;
 
// }



#include <iostream>
#include <algorithm>
#include <string>
#include <set>
#include<vector>
#include <map>
#include <unordered_map>
#include <climits>
 
using namespace std;

bool recursion(int len,vector<int>& array,int stat){
    //median by max and min (traverse array once)
    if(len==1){
        if(array[0]==stat){
            return true;
        }
        else{
            return false;
        }
    }
  

    int mini=INT_MAX;
    int maxi=INT_MIN;
    for(int k=0;k<len;k++){
        maxi=max(maxi,array[k]);
        mini=min(mini,array[k]);
    }

    // use median and split array into 2
    int med=(maxi+mini)/2;
    vector<int> left;
    vector<int> right;
    int lsum=0;
    int rsum=0;
    for(int j=0;j<len;j++){
        if(array[j]<=med){
            left.push_back(array[j]);
            lsum+=array[j];
        }
        else{
            right.push_back(array[j]);
            rsum+=array[j];
        }
    }

    if(lsum==stat || rsum==stat || rsum+lsum==stat){
        return true;
    }
     else if(array[0]==array[len-1]){
        return false;
    }
    else{
        return recursion(left.size(), left, stat) || recursion(right.size(), right, stat);
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

        for(int i=0;i<q;i++){ //q=number of queries
            int a;
            cin>>a;
            bool ans=recursion(n, arr, a);
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
