#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;
void quicksort(int* arr, int a, int b) {
	if (a >= b)
		return;
	int f = 1;
	for (int i = a; f && i < b; i++)
		if (arr[i] > arr[i + 1])
			f = 0;
	if (f)
		return;
	srand(time(NULL));
	int std = rand() % (b - a) + a;
	int i = a, j = b, s = arr[std], t = arr[std];
	arr[std] = arr[a];
	arr[a] = t;
	while (i < j) {
		while (i < j && arr[j] >= s)
			j--;
		arr[i] = arr[j];
		while (i < j && arr[i] <= s)
			i++;
		arr[j] = arr[i];
	}
	arr[i] = s;
	quicksort(arr, a, i - 1);
	quicksort(arr, i + 1, b);
}
int main() {
	int len;
	cin >> len;
	int* arr = new int[len + 1];
	for (int i = 1; i <= len; i++)
		cin >> arr[i];
	quicksort(arr, 1,len);
	for (int i = 1; i <= len; i++)
		cout << arr[i] << " ";
	return 0;
}