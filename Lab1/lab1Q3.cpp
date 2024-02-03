#include <iostream>
#include <algorithm>
#include <string>
#include <set>
#include<vector>
#include <map>
#include <unordered_map>
#include <climits>
 
using namespace std;
 //static_cast<char>('a' + 1)

int recursion(int n,string s,char c){

    //base
    if(n==1){
        if(s[0]==c) return 0;
        else return 1;
    }

    int ind=n/2;

    int ops=0;
    int ops2=0;

    string one=s.substr(0,ind);;
    string two=s.substr(ind,ind);

    for(int i=0;i<ind;i++){
        if(c!=s[i]){
            ops++;
        }
    }
    for(int i=ind;i<n;i++){
        if(c!=s[i]){
            ops2++;
        }
    }

    int oneans=ops2+recursion(n/2,one,(c + 1));
    int twoans=ops+recursion(n/2,two,(c + 1));

    return min(oneans,twoans);

}


int main(){
    int t;// test cases
    cin>>t;
    for(int test=0;test<t;test++){
        int n;
        cin>>n; //lenth of string & n=2^k k>=0
        string s;
        cin>>s; //req string
        int a=recursion(n,s,'a');
        cout<<a<<endl;
    }

    return 0;
 
}