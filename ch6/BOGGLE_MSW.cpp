#ifndef ONLINE_JUDGE
#define _CRT_SECURE_NO_WARNINGS
#endif // !ONLINE_JUDGE
#include <stdio.h>
#include <iostream>
#include <vector>
#include <string>
#include <list>
#include <stack>
#include <algorithm>
#include <math.h>
#include <bitset>
#include <set>
#include <map>
#include <queue>
#include <ratio>
#include <iomanip> // for setprecision
#include <functional> // for greater less
#include <sstream>
#define ull unsigned long long
#define ll long long
#define ld long double
using namespace std;
const int intMAX = 2147483647;
const ll llMAX = 9223372036854775807;
const vector< pair< ll, ll > > cardinalP = { { 0,1 },{ 0,-1 },{ -1,0 },{ 1,0 }, {1,1}, {1,-1}, {-1,1}, {-1,-1} };
long long POW(long long a, long long b) { if (b == 0) return 1;	if (b == 1) return a;	return a * POW(a, b - 1); }
long long POW(long long a, long long b, long long re) { if (b == 0) return 1;	if (b == 1) return a;	return (a * POW(a, b - 1, re)) % re; }
long long gcd(long long a, long long b) { if (a == 0) return b;	if (a > b) return gcd(b, a);	return gcd(b%a, a); }



vector<vector<char>> table(7, vector<char>(7));
vector<vector<vector<int>>> memo;

bool go(int row, int col, string word, int idx) {

	
	if (table[row][col] != word[idx]) {
		return false;
	}
	int &ret = memo[row][col][idx];
	
	if (ret != -1) {
		return ret;
	}

	ret = false;
	if (word.size() - 1 == idx) {
		ret = true;
		return ret;
	}
	for (int i = 0; i < 8; i++) {
		if (go(row + cardinalP[i].first, col + cardinalP[i].second, word, idx + 1)) {
			ret = true;
		}
	}

	return ret;

}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
#endif // !ONLINE_JUDGE
	cin.tie(0); ios_base::sync_with_stdio(0);
	// write your code below
	// 

	int tc; cin >> tc;
	while (tc--) {		
		for (int i = 0; i < 5; i++) {
			cin.get();
			for (int j = 0; j < 5; j++) {
				table[i + 1][j + 1] = cin.get();
			}
		}
		int n; cin >> n;
		for (int i = 0; i < n; i++) {
			string q; cin >> q;
			memo.assign(7, vector<vector<int>>(7, vector<int>(10, -1)));
			int ret = false;
			for (int j = 0; j < 5; j++) {
				for (int k = 0; k < 5; k++) {
					if (go(j + 1, k + 1, q, 0)) {
						ret = true;
					}
				}
			}
			if (ret) {
				cout << q << ' ' << "YES\n";
			}
			else {
				cout << q << ' ' << "NO\n";
			}
		}

	}


	return 0;
}

