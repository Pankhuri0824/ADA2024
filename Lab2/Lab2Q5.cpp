#include <iostream>
#include <algorithm>
#include <string>
#include <set>
#include<vector>
#include <map>
 
using namespace std;


void dfs(vector<vector<int>>& graph, int root, vector<int>& visited , vector<int>& start, vector<int>& end, int& time){
    visited[root]=1;
    start[root]=time;
    time++;
    for(auto& edge: graph[root]){
        if(visited[edge]==0){
            dfs(graph, edge, visited, start, end, time);
        }
    }
    end[root]=time;
    time++;
    // ans[root]=1;
}

void neg_dfs(vector<vector<int>>& graph, int root, vector<int>& ans){
    ans[root]=-1;
    for(auto& ver: graph[root]){
        if(ans[ver]!=-1){
            neg_dfs(graph,ver,ans);
        }
    }
    
}

//find out the back edges and self edges
void dfs_check(vector<vector<int>>& graph, int root, vector<int>& visited, vector<int>& ans, vector<int>& start, vector<int>& end){
    visited[root]=1;
    for(auto ver: graph[root]){
       if((start[ver]<start[root] && end[root]<end[ver]) || ver==root){//cycle or self edge
            neg_dfs(graph, ver, ans);
       }
       else if(visited[ver]==0){
           dfs_check(graph, ver, visited, ans, start, end);
       }
    }
}


void dfs_path(vector<vector<int>>& graph, int root,  vector<int>& ans){
    for(auto ver: graph[root]){
        if(ans[ver]==0){
            ans[ver]=1;
            dfs_path(graph, ver, ans);
        }
        else if(ans[ver]==1){
            ans[ver]=2;
            dfs_path(graph, ver, ans);
        }
    }
}


int main(){
    int t;
    cin>>t;
    for(int q=0;q<t;q++){//inside test case 
        int v,e; // v=n=rooms , e=m=paths
        cin>>v>>e;

        vector<vector<int>> graph(v);
        vector<int> visited(v,0);
        vector<int> start(v,0);
        vector<int> end(v,0);

        vector<int> ans(v,0);
        ans[0]=1;


        for(int tc=0;tc<e;tc++){
            int v1,v2;
            cin>>v1>>v2;
            graph[v1-1].push_back(v2-1);
        }

        //call dfs and print the strat and end times for each node
        int time=0;
        dfs(graph, 0, visited, start, end, time);
          
        visited.assign(v,0);
        dfs_check(graph, 0, visited, ans, start, end);

        dfs_path(graph, 0, ans);

        // for(int i=0;i<v;i++){
        //     cout<<"Node: "<<i+1<<" Start: "<<start[i]<<" End: "<<end[i]<<endl;
        // }

        //print ans array
        for(int i=0;i<v;i++){
            cout<<ans[i]<<" ";
        }

    }

}

// one for start and end
// one for cycles and self cycles
// one path