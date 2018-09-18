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
int cardinalP[8][2] = { { 0,1 },{ 0,-1 },{ -1,0 },{ 1,0 },{ 1,1 },{ 1,-1 },{ -1,1 },{ -1,-1 } };



long long POW(long long a, long long b) { if (b == 0) return 1;	if (b == 1) return a;	return a * POW(a, b - 1); }
long long POW(long long a, long long b, long long re) { if (b == 0) return 1;	if (b == 1) return a;	return (a * POW(a, b - 1, re)) % re; }
long long gcd(long long a, long long b) { if (a == 0) return b;	if (a > b) return gcd(b, a);	return gcd(b%a, a); }

string s;
int idx;
string go() {
	char v = s[idx];
	idx++;
	if (v == 'b' || v == 'w') {
		string temp = "";
		temp += v;
		return temp;
	}

	string ul = go();
	string ur = go();
	string dl = go();
	string dr = go();
	return "x" + dl + dr + ul + ur;
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
		cin >> s;
		idx = 0;
		cout << go() << '\n';
	}


	return 0;
}

