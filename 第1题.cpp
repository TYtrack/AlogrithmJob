
#include<stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;

int A[11];
int LINK[11];

void InsertSort(int A[], int Link[], int low, int high, int&p) {
	int i, k, small = low, max = low;
	int b;
	for (i = low; i <= high; i++) {
		if (A[small] >= A[i])
			small = i;
		if (A[max] <= A[i])
			max = i;
	}
	p = small;
	for (i = low; i <= high; i++) {
		b = max;
		for (int j = low; j <= high; j++) {
			if (A[i] < A[j] && A[j]<A[b])
				b = j;
		}
		Link[i] = b;
	}
	Link[max] = 0;
}


void merge(int q, int r, int &p) {
	int i, j, k;
	i = q;
	j = r;
	k = 0;
	while (i != 0 && j != 0) {
		if (A[i] <= A[j]){
			LINK[k] = i;
			k = i;
			i = LINK[i];

		}
		else {
			LINK[k] = j;
			k = j;
			j = LINK[j];
		}
	}
	if (i == 0)
		LINK[k] = j;
	else 
		LINK[k] = i;
	p = LINK[0];
}
void mergesort(int low,int  high,int &p) {
	if (high - low + 1<3){
		InsertSort(A,LINK, low, high, p);
	}
	else {
		int mid = (low + high) / 2;
		int q, r;
		mergesort(low, mid, q);
		mergesort(mid + 1, high, r);
		merge(q, r, p);
	}
}



int main() {
	A[1] = 1;
	A[2] = 3;
	A[3] = 6;
	A[4] = 4;
	A[5] = 8;
	A[6] = 7;
	A[7] = 10;
	A[8] = 9;
	A[9] = 5;
	A[10] = 2;
	cout << A[1];
	for (int i = 0; i <= 10; i++)
		LINK[i] = 0;
	int p;
	mergesort(1, 10, p);
	cout << "\n   ";
	for (int i = 1; i <= 10; i++) {
		cout << A[i] << "  ";
	}
	cout << "\n";
	cout << "p:" << p<<"\n";
	for (int i = 0; i <= 10; i++) {
		cout <<LINK[i] << "  ";
	}
	system("pause");
}
