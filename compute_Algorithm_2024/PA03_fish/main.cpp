#include <bits/stdc++.h>

using namespace std;
int num,n;

bool cmpFun(const vector<int> &arr){
    int i=0;
    for(int a: arr)if(a!=i++) return false;
    return true;
}

void changeFun(vector<int> &arr,int startIdx, map<int, int> &notSame ,bool isStart){
    int endIdx = notSame[-startIdx];
    if(!isStart)swap(startIdx, endIdx);    
    if(endIdx == startIdx || (startIdx+endIdx)%2==0) {
        arr[(startIdx+endIdx)/2] = -arr[(startIdx+endIdx)/2];
    }
    int len = (endIdx-startIdx+1)/2;
    for(int i=0; i<len; i++){
        int first = -arr[startIdx];
        int second = -arr[endIdx];
        arr[startIdx] = second;
        arr[endIdx] = first;
        startIdx++;
        endIdx--;
    }
    return;
}

bool checkFish(vector<int> &arr){
    map<int, int> notSame;
    vector<int> index;
    for(int i=1; i<=num; i++){
        if(i !=arr[i]){
            notSame.insert(make_pair(arr[i], i));
            index.push_back(i);
        }
    }
    int indexEnd = index.size()-1;
    if( notSame.find(-index[0]) != notSame.end()){
        changeFun(arr,index[0], notSame,true);
        if(cmpFun(arr)) return true;
        return false;
    }
    else if(notSame.find(-index[indexEnd]) != notSame.end()){
        changeFun(arr,index[indexEnd], notSame, false);
        if(cmpFun(arr)) return true;
        return false;
    }
    return false;
}

int main(){
    cin>>num;
    for(int i=0; i<5; i++){
        vector<int>arr;
        arr.push_back(0);
        for(int k=0; k<num; k++){
            cin>>n;
            arr.push_back(n);
        }
        if(checkFish(arr)) {
            cout<<"one"<<endl;
            continue;
        }
        if(checkFish(arr)){
            cout<<"two"<<endl;
            continue;
        }
        cout<<"over"<<endl;
    }
}