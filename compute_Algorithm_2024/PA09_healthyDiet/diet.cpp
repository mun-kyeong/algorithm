#include <iostream> 
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;


struct Health {
    int isVisited[51] = {0};    //[1,0,0,0,1]
    int nowHealth[4] = {0};     //[100,70,90,100]
    int cost = 0;

    bool operator < (const Health &a) const {
        if(cost == a.cost) {
            int sum1 = 0;
            int sum2 = 0;
            for(int i = 0; i < 4; i++) {
                sum1 += nowHealth[i];
                sum2 += a.nowHealth[i];
            }
            if(sum1 == sum2) {
                for(int i = 0; i < 4; i++) {
                    if(nowHealth[i] == a.nowHealth[i]) continue;
                    return nowHealth[i] > a.nowHealth[i];
                }
            }
            else return sum1 < sum2;
        }
        else if(cost != a.cost) return cost < a.cost;
    }
};

int n;
vector<vector<int> > HealthList;
queue<Health> HealthQue; // <list , depth>
Health minHealth;

void isValid(int index, Health front) {
    Health tempHealth = front;
    int cnt = 0;
    for(int i = 0; i < 4; i++) {
        if(front.nowHealth[i] - HealthList[index][i]<= 0) cnt++;
        tempHealth.nowHealth[i] = front.nowHealth[i] - HealthList[index][i];
    }
    tempHealth.cost = front.cost + HealthList[index][4];
    tempHealth.isVisited[index] = 1;

    if(cnt == 4) {
        if(tempHealth < minHealth) minHealth = tempHealth;
        // cout<<" / cost : "<<minHealth.cost<<endl;
    }
    else {
        HealthQue.push(tempHealth);
    }
    return;
}

void findHealth() {
    if(HealthQue.empty()) return;
    Health front = HealthQue.front(); //front : [1,0,0,0,1]
    HealthQue.pop();
    int startIdx =0;
    for(int i=n-1; i>=0; i--) {
        if(front.isVisited[i] == 1) {
            startIdx = i;
            break;
        }
    }
    for(int i = startIdx; i < n; i++) {
       if(front.isVisited[i] == 1 || minHealth.cost < front.cost + HealthList[i][4] ) continue;
       isValid(i, front);
    }
    findHealth();

}

void init() {
    cin >> n;
    Health initHealth;
    for (int i = 0; i < 4; i++) {
        int ss;
        cin >> ss;
        initHealth.nowHealth[i] = ss;
    }
    HealthQue.push(initHealth);
    minHealth.cost = 1000000;
    for(int i = 0; i < n; i++) {
        int num;
        vector<int> vec;
        for(int k=0; k<5; k++) {
            cin>>num;
            vec.push_back(num);
        }
        HealthList.push_back(vec);
    }
}

int main() {
    init();
    findHealth();
    // cout<<"final cost : ";
    for(int i = 0; i < n; i++) {
        if(minHealth.isVisited[i] == 1) cout<<i+1<<" ";
    }
    if(minHealth.cost == 1000000) cout<<0;
}

