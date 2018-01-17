#include <iostream>
#include <stdio.h>
#include <stack>
using namespace std;
class node {
public:
	node* l;
	node* r;
	int id;
	node(int i = 0) { id = i; l = r = NULL; }
};
int main() {
	int len;
	cin >> len;
	node** arr = new node*[len + 1];
	for (int i = 0; i <= len; i++)
		arr[i] = new node();
	node* head = new node(0);
	node* ini = new node(1);
	head->r = ini;
	ini->l = head;
	arr[1] = ini;
	int id, pos;
	node* t;
	for (int i = 2; i <= len; i++) {
		t = new node(i);
		arr[i] = t;
		cin >> id >> pos;
		if (pos == 0) {
			t->r = arr[id];
			t->l = arr[id]->l;
		}
		else {
			t->l = arr[id];
			t->r = arr[id]->r;
		}
		if (t->l)
			t->l->r = t;
		if (t->r)
			t->r->l = t;
	}
	cin >> len;
	while (len--) {
		cin >> id;
		arr[id]->id = 0;
	}
	t = head;
	while ((t = t->r) != NULL)
		if (t->id)
			cout << t->id << " ";
	return 0;
}


