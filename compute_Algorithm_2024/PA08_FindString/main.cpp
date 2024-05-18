#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>

using namespace std;

int n,m;
string pattern;
string text;
int mod = 1000000007;

int RK() {
    // Rabin-Karp algorithm
    long long patternHash = 0;
    long long textHash = 0;
    long long pow = 1;
    int count = 0;
    for(int i=0;i<pattern.size();i++) {
        patternHash = (patternHash*2 + pattern[i])%mod;
        textHash = (textHash*2 + text[i])%mod;
        pow = (pow*2)%mod;
    }
    for(int i=0;i<=text.size()-pattern.size();i++) {
        count++;
        if(patternHash == textHash) {
            bool check = true;
            for(int j=0;j<pattern.size();j++) {
                count++;
                if(pattern[j] != text[i+j]) {
                    check = false;
                    break;
                }
            }
            if(check) return count;
        }
        if(i < text.size()-pattern.size()) {
            textHash = (textHash*2 + text[i+pattern.size()] - text[i]*pow)%mod;
            if(textHash < 0) textHash += mod;
        }
    }
    return -1;
}
int KMP() {
    // Knuth-Morris-Pratt algorithm
    vector<pair<int,int> > table;

   //kmp table
   table.push_back(make_pair(0,0));
   
   for (int i = 1; i < pattern.size(); i++) {
       int j = table[i-1].second;
       while(j > 0 && pattern[i] != pattern[j]) {
           j = table[j-1].second;
       }
       if(pattern[i] == pattern[j]) j++;
       table.push_back(make_pair(i,j));
    }
    
    //kmp algorithm
    int count = 0;
    int i=0;
    int j=0;
    while(i < text.size()) {
        count++;
        if(text[i] == pattern[j]) {
            i++;
            j++;
            if(j == pattern.size()) return count;
        }
        else {
            if(j == 0) i++;
            else j = table[j-1].second;
        }
    }
   
    return -1;
}

int BM() {
    // Boyer-Moore algorithm
    map<char,int> table;
    int count=0;
    for(int i=0;i<text.size();i++) {
        table[text[i]] = -1;
    }
    for(auto aa :  table) {
       for(int j=pattern.size()-1; j>=0; j--) {
           if(pattern[j] == aa.first ) {
               table[aa.first] = j;
               break;
           }
       }
    }   
    int i=pattern.size()-1;
    int j=pattern.size()-1;
    while(i < text.size()) {
        count++;
        if(text[i] == pattern[j]) {
            if(j == 0) return count;
            i--;
            j--;
        }
        else {
            i = i + pattern.size() - min(j,1+table[text[i]]);
            j = pattern.size()-1;
        }
    }
    return -1;
}

string cmp(int rk, int kmp, int bm) {
    string result;
    if(rk == kmp && kmp == bm) {
        result = "0 0 0";
    } else if(rk == kmp) {
        if(rk < bm) result = "0 0 BM";
        else result = "BM 0 0";
    }
    else if(rk == bm) {
        if(rk < kmp) result = "0 0 KMP";
        else result = "KMP 0 0";
    }
    else if(kmp == bm) {
        if(kmp < rk) result = "0 0 RK";
        else result = "RK 0 0";
    }
    else {
        if( rk < kmp && kmp < bm) result = "RK KMP BM";
        else if(rk < bm && bm < kmp) result = "RK BM KMP";
        else if(kmp < rk && rk < bm) result = "KMP RK BM";
        else if(kmp < bm && bm < rk) result = "KMP BM RK";
        else if(bm < rk && rk < kmp) result = "BM RK KMP";
        else result = "BM KMP RK";
    }
    return result;
}

int main() {
    //RK, KMP, BM algorithms
    cin>>n;
    for(int i=0;i<n;i++) {
        string x;
        cin>>x;
        pattern += x;
    }
    cin>>m;
    for(int i=0;i<m;i++) {
        string x;
        cin>>x;
        text += x;  
    }
    // cout<<" -------------------- "<<endl;
    // cout<<RK()<<endl;
    // cout<<KMP()<<endl;
    // cout<<BM()<<endl;
    //  cout<<" -------------------- "<<endl;
    cout<<cmp( RK(), KMP(), BM() )<<endl;
    return 0;

}