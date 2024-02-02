#include <iostream>
#include <algorithm>
#include <string>
#include <set>
#include<vector>
#include <map>
#include <unordered_map>
#include <climits>
 
using namespace std;
 
int main(){
    int n,b; //number 
    cin>>n>>b;
    vector<int> team(n);
    vector<pair<int,int>> base(b);
    int power,wiz;

    for(int i=0;i<n;i++){
        cin>>team[i];
    }

    for(int i=0;i<b;i++){
        cin>>power>>wiz;
        base[i].first=power;
        base[i].second=wiz;
    }

    sort(base.begin(),base.end());
    int wizcount=0;
    for(int i=0;i<b;i++){
        wizcount+=base[i].second;
        base[i].second=wizcount;
    }

    // for(int i=0;i<b;i++){
    // cout<< base[i].first<< " "<<base[i].second<<endl;
    // }

    for (int i = 0; i < n; i++) {
        auto it = upper_bound(base.begin(), base.end(), make_pair(team[i], INT_MAX));
        if (it != base.begin()) {
            cout << base[(it - base.begin()) - 1].second << endl;
        } else if (it == base.begin()) {
            cout << 0 << endl;
        }
    }
    
    return 0;
 
}