#include<bits/stdc++.h>
using namespace std;
int n, m;
int f[100005][50], a[100005];

int log2(int x){
	int ans;
	while((x >>= 1))ans++;
	return ans;
}

void ST(){
	for(int i = 1;i <= n;i++){
		f[i][0] = a[i];
	}
	int k = log2(n) + 1;
	for(int j = 1;j <= k;j++){
		for(int i = 1;i <= n - (1 << j) + 1;i++){
			f[i][j] = max(f[i][j - 1], f[i + (1 << (j - 1))][j - 1]);
		}
	}
}

signed main(){
	ios::sync_with_stdio(0);
	cin >> n >> m;
	for(int i = 1;i <= n;i++){
		cin >> a[i];
	}
	ST();
	for(int i = 1;i <= m;i++){
		int l, r;
		cin >> l >> r;
		int k = log2(r - l + 1);
		cout << max(f[l][k], f[r - (1 << k) + 1][k]) << endl;
	}
//	cout << log2(922058895);
	return 0;
} 
