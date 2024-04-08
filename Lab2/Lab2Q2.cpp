#include <iostream>
#include <algorithm>
#include <string>
#include <set>
#include<vector>
#include <map>
 
using namespace std;

int main(){
    int q;
    cin>>q;
    vector<vector<int>> v;// result ors storing ds

    vector<int> row(1024,0);
    row[0]=1; //initially 0 is there bc 0 ways to rEACH 0
    v.push_back(row);


    for(int t=0;t<q;t++){
        int mode;
        int num;
        cin>>mode>>num;

        int n= v.size()-1;
        // cout<<"size: "<<n<<endl;
        if(mode==1){
            
            vector<int> row ;
            row.assign(v[n].begin(), v[n].end());

            for(int i=0;i<1024;i++){
                if(v[n][i]>0){
                    int res = i | num ;
                    row[res]=(row[res] + v[n][i])% 1000000007;
                }
            }

            v.push_back(row);
            
        }

        else if(mode==2){

            cout<<v[n][num]<<endl;
        }

    }

    
}