#include <cstdio>
#include <iostream>
#include <cmath>
#include <cstring>
#include <string>
using namespace std;

int p = 0;
char* s1 = new char[8];
char* s2 = new char[8];
char* r = new char[8];
void func(int a, int b, int c, int d) {
	if (a > b || p >= 8)
		return;
	r[p++] = s2[d];
	int l;
	for (l = a; s1[l] != s2[d]; l++);
	func(a, l - 1, c, c + l - 1 - a);
	func(l + 1, b, d + l - b, d - 1);
}
int main() {
	cin >> s1 >> s2;
	int l;
	for (l = 0; s1[l] != '\0'; l++);
	l--;
	func(0, l, 0, l);
	for (int i = 0; i < p; i++)
		cout << r[i];
	return 0;
}
