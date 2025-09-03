#include <iostream>
#include <vector>
#include <queue>
#include <map>

using namespace std;

int n, m;
vector<int> node[1001];
queue<int> q;
int degree[1001];
int result[1001];

void topologicalSort() {
    int cnt = 1;

    for(int i=1; i<n+1; i++){
        if(degree[i] == 0){
            q.push(i);
            result[i] = 1;
        } 
    }

    while(!q.empty()) {
   
        int cur = q.front();
        q.pop();
        for(int i=0; i<node[cur].size(); i++) {
            int next = node[cur][i];
            degree[next]--;
            if(degree[next] == 0) {
                q.push(next);
                result[next] = result[cur] + 1;
            }
        }

    }
 


}

int main() {

    cin >> n >> m;

    for(int i=0; i<m; i++) {
        int u, v;
        cin >> u >> v;
        node[u].push_back(v);
        degree[v]++;
    }

    topologicalSort();
    for (int i = 1; i < n+1; i++) {
        cout << result[i] << " ";
    }
}