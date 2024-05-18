#include <iostream>
#include <string.h>
#include <algorithm>
#include <vector>

using namespace std;

int find_max(int a, int b){
    if(a < b) return b;
    return a;
}

int isSame(string &word) {
    int cnt=0;
    for(int i=0; i<word.length()/2; i++){
        if(word[i] == word[word.length()-1-i]) cnt++;
        else break;
    }
    return cnt;
}

int main() {
    int n;
    cin>>n;
    string word;
    vector<int> answer;
    for(int kk=0; kk<n; kk++) {
        cin>>word;
        int len = word.length();
        vector<int> prev, now;
        if(word[0] != word[len-1]) {
            answer.push_back(0);
            continue;
        }
        int cut = isSame(word), ismax=0;;
        for(int i=0+cut; i<=word.length()-cut; i++) prev.push_back(0);
        for(int i=1+cut; i<=word.length()-cut; i++){
            now.clear();
            now.push_back(0);
            for(int k=1+cut; k<=word.length()-cut; k++){
                if(word[len-i] == word[k-1]) now.push_back(prev[k-cut-1]+1);
                else now.push_back(0);
            }
            if(ismax<now[now.size()-1]) ismax = now[now.size()-1];
            prev.swap(now);
        }
        int ismax2 = *max_element(prev.begin(), prev.end());
        answer.push_back(find_max(ismax2, ismax)+cut*2);
    }
    for(int i : answer) cout<<i<<endl;
}

