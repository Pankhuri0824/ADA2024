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

int countedges(vector<vector<int>> &graph,int v,int row){
    int count=0;
    for(int i=0;i<v;i++){
        if(graph[row][i]==1){
            count++;
        }
    }
    return count;
}

int main(){
    int v,e; //n and m in Q
    cin>>v>>e;

    //constructing the adjacency matrix
    vector<vector<int>> graph(v,vector<int>(v,0));

    for(int i=0;i<e;i++){
        int a,b;
        cin>>a>>b;
        graph[a-1][b-1]=1; //at index 0 you have 1 , at 1 you have 2 and so on
        graph[b-1][a-1]=1;
    }

    // for(int i=0;i<v;i++){ //printing adjacency matrix
    //     for(int j=0;j<v;j++){
    //         cout<<graph[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }

    vector<int> dp(v,-1);

    for(int i=0;i<v;i++){
        if(i==0){//checking for edge 1
            dp[i]=1*(countedges(graph,v,i));
        }

        else{
            int val=-1;
            for(int j=0;j<v;j++){
                if(graph[i][j]==1){ //if smaller edge exists , endpointedges*numberofnodes
                    int vertices=(dp[j]/countedges(graph,v,j)) + 1; // last beauty/endpointedges = vertcies
                    val=max(val,( (vertices)*countedges(graph,v,i)) );
                }
            }
            
            if(val==-1) dp[i]=1*(countedges(graph,v,i));//checking for connected componenets
            else dp[i]=val;
            
        }
    }

    int ans=-1;
    for(int i=0;i<v;i++){
        ans=max(ans,dp[i]);
    }
    cout<<ans<<" ";


    return 0;
}