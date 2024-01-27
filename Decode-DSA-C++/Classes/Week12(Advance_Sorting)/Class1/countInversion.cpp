#include<bits/stdc++.h>
using namespace std;

int c = 0;

int inversion(vector<int> &a, vector<int> &b) {
	int cnt = 0;
	int i = 0;
	int j = 0;
	while (i < a.size() && j < b.size()) {
		if (a[i] > b[j]) {
			cnt += a.size() - i;
			j++;
		}
		else {
			i++;
		}
	}
	return cnt;
}

void merge(vector<int> &a, vector<int> &b, vector<int> &res) {
	int i = 0;
	int j = 0;
	int k = 0;
	while (i < a.size() && j < b.size()) {
		if (a[i] <= b[j]) {
			res[k++] = a[i++];
		}
		else {
			res[k++] = b[j++];
		}
	}
	if (i == a.size()) {
		while (j < b.size()) {
			res[k++] = b[j++];
		}
	}
	if (j == b.size()) {
		while (i < a.size()) {
			res[k++] = a[i++];
		}
	}

}

void mergeSort(vector<int> &v) {
	int n = v.size();
	if (n == 1) return;

	int n1 = n / 2;
	int n2 = n - n1;
	vector<int> a(n1);
	vector<int> b(n2);

	//copying
	for (int i = 0; i < n1; i++) {
		a[i] = v[i];
	}
	for (int i = 0; i < n2; i++) {
		b[i] = v[i + n1];
	}

	//Magic
	mergeSort(a);
	mergeSort(b);

	//Count the inversion
	c += inversion(a, b);

	//Merge
	merge(a, b, v);
	a.clear();
	b.clear();

}


int main() {

#ifndef ONLINE_JUDGE
	freopen("inputf.in", "r", stdin);
	freopen("outputf.in", "w", stdout);
#endif
	vector<int> v = {5, 1, 8, 2, 3};
	for (int i = 0; i < v.size(); i++) {
		cout << v[i] << " ";
	}
	cout << endl;
	mergeSort(v);
	cout << c;
}
