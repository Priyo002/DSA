#include<bits/stdc++.h>
using namespace std;

void merge(vector<int> &a, vector<int>&b , vector<int> &res) {
	int i = 0;
	int j = 0;
	int k = 0;
	while (i < a.size() && j < b.size()) {
		if (a[i] < b[i]) res[k++] = a[i++]
			                            else res[k++] = b[j++];
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
	int n1 = n / 2 , n2 = n - n1;
	vector<int> a(n1), b(n2);

	for (int i = 0; i < n1; i++) {
		a[i] = v[i];
	}
	for (int i = 0; i < n2; i++) {
		b[i] = v[i + n1];
	}

	mergeSort(a);
	mergeSort(b);

	merge(a, b, v);
}

int main() {

#ifndef ONLINE_JUDGE
	freopen("inputf.in", "r", stdin);
	freopen("outputf.in", "w", stdout);
#endif

	vector<int> v = {5, 6, 8, 10, 1, 2, 4};

	mergeSort(v);
}