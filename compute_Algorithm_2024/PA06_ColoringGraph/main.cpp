#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int n,m,ans=0, vertex=0,stop =0, a=0,numSum=0;
vector<vector<int> > vec;
vector<int> check;
stack<pair<int,int> > stk;

void init() {
	cin>>n>>m;
	int num;
	for(int i=0; i<n; i++){
		vector<int> vv;
		for(int j=0; j<n; j++){
			cin>>num;
			vv.push_back(num);
		}
		vec.push_back(vv);
	}
	check.resize(n+1, 0);
}

bool isVaild(pair<int,int> p){
	int k=0;
	int i = p.second;
	bool flag = true;
	while (i > k && flag){
		if(vec[i][k] == 1 && check[k] == p.first )
			flag = false;
		k++;
	}
	if(p.second == n-1 && flag) {
		check[p.second] = p.first;
		bool isAll = true;
		int isAllArr[8]={0};
		for(int i=0; i<n; i++) {
			isAllArr[check[i]] = 1;
		}
		for(int i=0; i<m; i++) {
			if(isAllArr[i] == 0) isAll = false;
		}
		if(isAll) ans++;
		return false;
	}
	return flag;
}

void DFS(){
	vertex++;
	if(stk.empty()) return;
	pair<int,int> pp = stk.top();
	if (isVaild(pp)){
		stk.pop();
		check[pp.second] = pp.first;
		int index = pp.second +1;
		for(int i=m-1; i>=0; i--) 	
			stk.push(make_pair(i, index));
	}
	else stk.pop();
		
	DFS();
}

int main() {
	init();
	for(int i=m-1; i>=0; i--) {
		pair<int,int> start = make_pair(i,0);
		stk.push(start);
	}
	check[0] = 0;
	DFS();
	if(ans == 0) cout<<"no"<<endl;
	else cout<<ans<<"\n"<<(vertex-1)<<endl;
}
