#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <algorithm>
#include <set>
#include <map>
#include <string>
using namespace std;

vector<pair<long long,long long>> adj1[100005], adj2[100005];
long long int dis[100005];
long long int n,m;

void dikstra(bool isForward) {
    priority_queue<pair<long long, long long>, vector<pair<long long, long long>>, greater<pair<long long, long long>>> pq;
    if (isForward) {
        pq.push(make_pair(0, 1));
    } else {
        for (long long i = 1; i <= n; i++)
            pq.push(make_pair(dis[i], i));
    }
    while (!pq.empty()) {
        auto [d, node] = pq.top();
        pq.pop();
        if (dis[node] < d){
            continue;
        }
        if (isForward) {
            for (auto v : adj1[node]) {
                if (dis[v.first] > dis[node] + v.second) {
                    dis[v.first] = dis[node] + v.second;
                    pq.push(make_pair(dis[v.first], v.first));
                }
            }
        } else {
            for (auto v : adj2[node]) {
                if (dis[v.first] > dis[node] + v.second) {
                    dis[v.first] = dis[node] + v.second;
                    pq.push(make_pair(dis[v.first], v.first));
                }
            }
        }
    }
}

int main(){
    cin>>n>>m;
    for(int i=0;i<m;i++){
        long long int a,b,c;
        cin>>a>>b>>c;
        adj1[a].push_back(make_pair(b,c));
        adj2[b].push_back(make_pair(a,c));
    }
    for(int i=1; i<=n; i++){
        dis[i]=1e17;
    }
    dis[1]=0;
    dikstra(true);
    dikstra(false);
    for(int i=2; i<=n; i++){
        if(dis[i]==1e17){dis[i]=-1;}
    }
    for(int i=2; i<=n; i++){
        cout<<dis[i]<<" ";
    }
    cout<<endl;
    return 0;
 
}