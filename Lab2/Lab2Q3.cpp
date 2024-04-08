#include <iostream>
#include <algorithm>
#include <string>
#include <set>
#include<vector>
#include <map>
 
using namespace std;

//beauty of graph : number of verticles in face X number of hands(edges) of endpoint
//vertice value number must increase as you move forward4
//only one connected component


int main(){
    int v,e; //n and m in Q
    cin>>v>>e;

    //constructing the adjacency matrix
    vector<vector<int>> graph(v);

    for(int i=0;i<e;i++){
        int a,b;
        cin>>a>>b;
        graph[a-1].push_back(b);
        graph[b-1].push_back(a);
    }

    // for(int i=0;i<graph.size();i++){ //printing adjacency list
    //     for(int j=0;j<graph[i].size();j++){
    //         cout<<graph[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }

    vector<int> dp(v,-1);

    for(int i=0;i<v;i++){
        if(i==0){//checking for edge 1
            dp[i]=1*graph[i].size();
        }

        else{
            int val=-1;
            for(int j=0;j<graph[i].size();j++){ //check all edges of i
                if(graph[i][j]< (i+1) ){//edge being considered has smaller value than i
                    int node= graph[i][j]-1;
                    int vertcies = ( dp[node]/graph[node].size() ) + 1; // last beauty/endpointedges = vertcies
                    int curr=  (vertcies)*graph[i].size() ; 
                    val= max(val,curr);
                }
            }
            if(val==-1) dp[i]=1*(graph[i].size());//checking for connected componenets
            else dp[i]=val;
            
        }
    }

    int ans=-1;
    for(int i=0;i<v;i++){
        ans=max(ans,dp[i]);
    }
    cout<<ans;


    return 0;
}