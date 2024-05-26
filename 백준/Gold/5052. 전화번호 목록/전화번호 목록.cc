#include <bits/stdc++.h>
using namespace std;

int main() {
	int tc;
	string str;
	cin >> tc;
	while(tc--) {
		int n;
		cin >> n;
		vector<string> book;
		for(int i=0; i<n; i++) {
			cin >> str;
			book.push_back(str);
		}
		
		sort(book.begin(), book.end());
		
		bool flag=false;
		for(int i=0; i<n-1; i++) {
			string a=book.at(i), b=book.at(i+1);

			if(a.size()>=b.size()) continue;
			if(a==b.substr(0, a.size())) {
				cout << "NO" << "\n";
				flag= true;
				break;
			}
		}
		if(!flag) cout <<"YES" << "\n";
	}
	
	return 0;
}