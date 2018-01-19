#include <cstdio>
#include <iostream>
#include <cmath>
#include <cstring>
#include <string>
using namespace std;
class node {
public:
	char data;
	node* l;
	node* r;
	node(char c = '\0') { data = c; l = r = NULL; }
};
char judge(char* arr, int a, int b) {
	for (int i = a; i <= b; i++)
		if (arr[i] != arr[a])
			return 'F';
	if (arr[a] == '0')
		return 'B';
	return 'I';
}
void func(char* arr, node* rt, int a, int b) {
	rt->data = judge(arr, a, b);
	if (a == b)
		return;
	else {
		int t = (a + b) / 2;
		rt->l = new node();
		rt->r = new node();
		func(arr, rt->l, a, t);
		func(arr, rt->r, t + 1, b);
	}
}
void print(node* t) {
	if (t == NULL)
		return;
	print(t->l);
	print(t->r);
	cout << t->data;
}
int main() {
	int n;
	cin >> n;
	int max = pow(2, n);
	char* arr = new char[max];
	cin >> arr;
	int len;
	node* root = new node();
	func(arr, root, 0, max - 1);
	print(root);
	return 0;
}
