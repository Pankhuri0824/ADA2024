// #include <iostream>
// #include <algorithm>
// #include <string>
// #include <set>
// #include<vector>
// #include <map>
// #include <queue>
// #include <climits>

// using namespace std;

// // dijkstra standard code by referring sources 
// vector<int> dijkstra(vector<vector<pair<int, int>>>& graph, int root) {
//     int n = graph.size();
//     vector<int> dis(n, -1); // Initialize distances as -1
//     priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> queue;

//     dis[root] = 0;
//     queue.push({0, root});

//     while (!queue.empty()) {
//         int d = queue.top().first;
//         int u = queue.top().second;
//         queue.pop();

//         if (d > dis[u]) continue;

//         for (auto& edge : graph[u]) {
//             int v = edge.first;
//             int w = edge.second;
//             if (dis[u] + w < dis[v] || dis[v] == -1) { // Check if updating or initializing
//                 dis[v] = dis[u] + w;
//                 queue.push({dis[v], v});
//             }
//         }
//     }

//     return dis;
// }

// int dijkstra_with_end(vector<vector<pair<int, int>>>& graph, int root, int end) {
//     int n = graph.size();
//     vector<int> dis(n, -1); // Initialize distances as -1
//     priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> queue;

//     dis[root] = 0;
//     queue.push({0, root});

//     while (!queue.empty()) {
//         int d = queue.top().first;
//         int u = queue.top().second;
//         queue.pop();

//         if (u == end) return dis[u]; // If we reach the end node, return its distance

//         if (d > dis[u]) continue;

//         for (auto& edge : graph[u]) {
//             int v = edge.first;
//             int w = edge.second;
//             if (dis[u] + w < dis[v] || dis[v] == -1) { // Check if updating or initializing
//                 dis[v] = dis[u] + w;
//                 queue.push({dis[v], v});
//             }
//         }
//     }

//     return -1; // If end node is not reachable from the root
// }


// int main(){
//     int v,e; // v=n=rooms , e=m=paths
//     cin>>v>>e;

//     vector<vector<pair<int, int>>> graph(v);
//     vector<vector<pair<int, int>>> revgraph(v);


//     for(int tc=0;tc<e;tc++){ //take all weighted edges make graph and reverse graph
//         int v1,v2,dis;
//         cin>>v1>>v2>>dis;

//         graph[v1-1].push_back({v2-1, dis}); // -1 for zero index FOR GRAPH
//         revgraph[v2-1].push_back({v1-1, dis}); //  FOR REVERSE GRAPH
//     }

//     vector<int> sheldon= dijkstra(graph, 0);
    
//     vector<int> leonard;

//     for (int i = 0; i < v; ++i) {
//        leonard.push_back(dijkstra_with_end(revgraph,i,0));
//     }

//     //print both leonard and sheldon
//     for(int i=0;i<v;i++){
//         cout<<"S: "<<sheldon[i]<<" L: "<<leonard[i]<<" "<<endl;
//     }


//     return 0;


// }

#include <iostream>
#include <algorithm>
#include <string>
#include <set>
#include<vector>
#include <map>
#include <queue>
#include <climits>

using namespace std;

// dijkstra standard code by referring sources 
vector<int> dijkstra(vector<vector<pair<int, int>>>& graph, int root) {
    int n = graph.size();
    vector<int> dis(n, -1); // Initialize distances as -1
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> queue;

    dis[root] = 0;
    queue.push({0, root});

    while (!queue.empty()) {
        int d = queue.top().first;
        int u = queue.top().second;
        queue.pop();

        if (d > dis[u]) continue;

        for (auto& edge : graph[u]) {
            int v = edge.first;
            int w = edge.second;
            if (dis[u] + w < dis[v] || dis[v] == -1) { // Check if updating or initializing
                dis[v] = dis[u] + w;
                queue.push({dis[v], v});
            }
        }
    }

    return dis;
}


int main(){
    int v,e; // v=n=rooms , e=m=paths
    cin>>v>>e;

    vector<vector<pair<int, int>>> graph(v);

    for(int tc=0;tc<e;tc++){ //take all weighted edges
        int v1,v2,dis;
        cin>>v1>>v2>>dis;

        graph[v1-1].push_back({v2-1, dis}); // -1 for zero index
    }

    vector<vector<int>> ans(v);
    for(int i=0;i<v;i++){
        ans[i] = dijkstra(graph, i);
    }

    // //print ans vector
    // for(int i=0;i<v;i++){
    //     for(int j=0;j<v;j++){
    //         cout<<ans[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }


    //printing ans
    for(int i=1;i<v;i++){
        int a=INT_MAX;
        for(int j=0;j<ans[i].size();j++){
            int comp=-1;
            if(ans[i][j]>-1 && ans[0][j]>-1)comp=ans[i][j]+ans[0][j];
            // cout<<"Comp:" <<comp<<" ";
            if(a>-1 && comp>-1) a=min(a,comp);
        }
        if(a!=INT_MAX) cout<< a<<" ";
        else cout<<-1<<" ";
        // cout<<endl;
    
    }



    

}

