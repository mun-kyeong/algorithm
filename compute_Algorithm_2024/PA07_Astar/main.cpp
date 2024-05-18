#include <iostream>	
#include <vector>
#include <tuple>
#include <utility>
#include <queue>

using namespace std;

int n, m,aaa=0;

vector< pair<int, int> > zero;
vector< pair<int, int> > idx;
vector< pair<pair<int,int>, pair<int,int> > > wall;
priority_queue< pair<int, int> > que;
queue< pair<int, int> > que2;
int check[200][200] = {0};
 

int menhattan(pair<int, int> a, pair<int, int> b) {
	return abs(a.first - b.first) + abs(a.second - b.second);
}

int uqlid(pair<int, int> a, pair<int, int> b) {
	return (a.first - b.first) * (a.first - b.first) + (a.second - b.second) * (a.second - b.second);
}

struct cmp{
bool operator()(pair<int, int>&a, pair<int, int>&b) {
	int aMen = menhattan(a, idx[0]);
	int bMen = menhattan(b, idx[0]);
	int aUql = uqlid(a, idx[1]);
	int bUql = uqlid(b, idx[1]);
	if(aMen+aUql == bMen+bUql) {
		if(aMen == bMen) {
			return aUql < bUql;
		}
		else return aMen < bMen;
	}
	else return aMen+aUql < bMen+bUql;
	}
};

void init()	{
	cin>>n>>m;
	int cnt, a, b,c,d;
	cin>>cnt;
	for(int i=0; i<cnt; i++)	{
		cin>>a>>b>>c;
		zero.push_back( make_pair( b, c ) );
	}
	string word;
	for(int i=0; i<2; i++){
		cin>>word>>a>>b;
		idx.push_back( make_pair( a,b ) );
		if(i==0)check[a][b] = 1;
	}
	cin>>word>>cnt;
	for (int i = 0; i < cnt; i++)	{
		cin>>a>>b>>c>>d;
		wall.push_back( make_pair( make_pair( a,b ), make_pair( c,d )) );
		for(int k=a; k<=c; k++) {
			for(int j=b; j<=d; j++) {
				check[k][j] = 1;
			}
		}
	}
}

bool isValid(pair<int, int> a) {
	if(check[a.first][a.second] == 1) return false;
	if(a.first < 0 || a.first >= n) return false;
	if(a.second < 0 || a.second >= m) return false;
	return true;
}

void Astar() {
	while(true) {
		if(que.empty())	{
			// cout<<"fail"<<endl;
			break;
		}
		pair<int, int> cur = que.top();
		que.pop();
		// cout<<cur.first<<" "<<cur.second<<endl;
		if(cur.first == idx[1].first && cur.second == idx[1].second) {
			cout<<( menhattan(cur,idx[0]) + uqlid(cur, idx[1])) * 3 <<endl;
			break;
		}
		if(isValid( make_pair( cur.first + 1, cur.second ) ) ) {
			check[ cur.first + 1 ][ cur.second ] = 1;
			que.push( make_pair( cur.first + 1, cur.second ) );
		}
		if(isValid( make_pair( cur.first - 1, cur.second ) ) ) {
			check[ cur.first - 1 ][ cur.second ] = 1;
			que.push( make_pair( cur.first - 1, cur.second ) );
		}
		if(isValid( make_pair( cur.first, cur.second + 1 ) ) ) {
			check[ cur.first ][ cur.second + 1 ] = 1;
			que.push( make_pair( cur.first, cur.second + 1 ) );
		}
		if(isValid( make_pair( cur.first, cur.second - 1 ) ) ) {
			check[ cur.first ][ cur.second - 1 ] = 1;
			que.push( make_pair( cur.first, cur.second - 1 ) );
		}
		aaa++;
	}
}


int main() {
	init();
	que.push( make_pair( idx[0].first, idx[0].second ) );
	check[ idx[0].first ][ idx[0].second ] = 1;
	Astar();
}
