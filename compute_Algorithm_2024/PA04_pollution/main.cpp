#include <bits/stdc++.h>

using namespace std;

struct Tree {
    int start;
    int end;
    int length;
	bool operator< (const Tree &a) const {
        if(length == a.length) return end < a.end;
		return length < a.length;
	}
};

vector<set<Tree> > arr(21);
set<Tree> stroage;
int checkArr[21]={0};
#define push_tuple(a,b,c) stroage.insert(make_tuple(a,b,c));


int main() {
    int n,c1, c2;
    vector<int> answer;
    cin>>n>>c1>>c2;
    for(int i=0; i<n-1; i++) {
        int start, end, length;
        cin>>start>>end>>length;
        Tree tree1 = {start, end,length};
        Tree tree2 = {end, start, length};
        arr[start].insert(tree1);
        arr[end].insert(tree2);
        if(start == c1 || start == c2) { stroage.insert(tree1);}
        if(end == c1 || end==c2) { stroage.insert(tree2);}
    }
    checkArr[c1] = 1;
    checkArr[c2] = 1;

    for(auto it = stroage.begin(); it!= stroage.end(); it++){
        if(checkArr[it->end] == 0) {
            int idx = it->end;
            for(auto i = arr[idx].begin(); i!=arr[idx].end(); i++) {
                if(checkArr[i->end] != 0) continue;
                Tree tree = {idx, i->end, i->length + it->length};
                stroage.insert(tree);
            }
            answer.push_back(idx);
            checkArr[it->end] = 1;
        }
    }
    for(int i : answer) {
        cout<<i<<endl;
    }
}
