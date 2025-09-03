#include <iostream>
#include <vector>
#include <queue>
#include <map>


using namespace std;
// #define DEBUG

int n, totalTime=0;
int storage[10001]={0};
int minCost[10001]={0};
map<int,vector<int> > mmap;
map<int, int> cost;
queue<pair<int,int> > q;

void init(){
    cin>>n;
    for(int i=1; i<=n; i++){
        int cost_input,cnt;
        cin>>cost_input>>cnt;
        for(int j=0; j<cnt; j++){
            int x;
            cin>>x;
            mmap[x].push_back(i);
        }
        storage[i] = cnt;
        cost[i] = cost_input;
    }
}

int main() {
    init();
    int cnt = 0;
    for(int i=1; i<=n; i++){
        if(storage[i] == 0){
            //cout<<"i : "<<i<<" cost[i] : "<<cost[i]<<endl;
            q.push(make_pair(i, cost[i]));
            storage[i] = -1;
        }
    }
    while(!q.empty()){
        int number = q.front().first;
        int nowTime = q.front().second;
        //cout<<"number : "<<number<<" nowTime : "<<nowTime<<endl;
        q.pop();
        if(totalTime < nowTime){
            totalTime = nowTime;
        } 

        for(int num : mmap[number]){
            storage[num]--;
            minCost[num] = max(minCost[num], nowTime);
            if(storage[num] == 0){
                // cout<<"nowTime : "<<nowTime<<" cost[num] : "<<cost[num]<<endl;
                q.push(make_pair(num, minCost[num] + cost[num]));
                storage[num] = -1;
            }
        }
    }

    cout<<totalTime<<endl;  
   
}