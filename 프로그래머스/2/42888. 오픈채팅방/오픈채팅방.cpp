
#include <bits/stdc++.h>

using namespace std;

vector<string> solution(vector<string> record) {
    vector<string> answer;

    vector<pair<string, string> > actionIdVec; // {action, uid}
    unordered_map<string, string> uidNameMap; // {uid: name}
    int N = record.size();
    for (int i=0; i<N; i++) {
        vector<string> splitVec;
        stringstream ss(record[i]);
        string temp;
        while (ss >> temp) {
            splitVec.push_back(temp);
        }
        pair pp = make_pair(splitVec[0], splitVec[1]);
        actionIdVec.push_back(pp);           
        if (splitVec[0] != "Leave") {
            uidNameMap[splitVec[1]] = splitVec[2];
        }
    }

    for (int i=0; i<N; i++) {
        string result = "";
        result += uidNameMap[actionIdVec[i].second];
        if (actionIdVec[i].first == "Enter") { result +=  "님이 들어왔습니다."; }
        else if (actionIdVec[i].first == "Leave") { result += "님이 나갔습니다."; }
        else if (actionIdVec[i].first == "Change") { continue; }
        answer.push_back(result);
    }
    
    return answer;
}