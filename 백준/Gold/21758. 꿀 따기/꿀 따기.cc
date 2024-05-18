#include <bits/stdc++.h>

using namespace std;

int n;
long long v[100001], sum[100001];

int main(){
	cin >> n;
	for(int i=1; i<=n; i++){
        cin >> v[i];
        sum[i]=v[i]+sum[i-1];
	}
	long long ans=0;
	for(int i=2; i<n; i++){ // i)
        ans=max(ans, sum[n]-v[1]-v[i]+sum[n]-sum[i]);
	}
	for(int i=2; i<n; i++){ // ii)
        ans=max(ans, sum[n]-v[n]-v[i]+sum[i-1]);
	}
	for(int i=2; i<n; i++){ // iii)
        ans=max(ans, sum[i]-v[1]+sum[n]-sum[i-1]-v[n]);
	}
	cout << ans << "\n";
	return 0;
}