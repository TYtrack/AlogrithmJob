
#include <stdio.h>
#include <iostream>
#define MAX 100
using namespace std;

int JS(int date[], int J[],int n,int k) {
	date[0] = 0;
	J[0] = 0;
	J[1] = 1;
	k = 1;
	int r;
	for (int i = 2; i <= n; i++) {
		r = k;
		while (date[J[r]] > date[i] && date[J[r]] != r)
			r = r - 1;
		if (date[J[r]] <= date[i] && date[i] > r) {
			for (int j = k; j > r ; j--) {
				J[j + 1] = J[j];
			}
			J[r + 1] = i;
			k++;
		}
	}
	return k;
}

void sort(int p[], int date[],int n) {
	for (int i = 1; i <= n; i++) {
		int k = i - 1;
		p[0] = p[i];
		date[0] = date[i];
		while (p[0] > p[k]) {
			p[k + 1] = p[k];
			date[k + 1] = date[k];
			k--;
		}
		p[k + 1] = p[0];
		date[k + 1] = date[0];
	}

}

int main() {
	int date[MAX];
	int J[MAX];
	int p[MAX];
	int num;
	cout << "������ҵ����" << endl;
	cin >> num;

	cout << "����ÿ����ҵȨֵ" << endl;
	for (int i = 1; i <= num; i++) {
		cin >> p[i];
	}

	cout << "�������" << endl;

	cout << "����ÿ����ҵ����" << endl;
	for (int i = 1; i <= num; i++) {
		cin >> date[i];
	}
	cout << "�������" << endl;

	sort(p, date, num);
	
	int work=JS(date, J, num,num);
	cout << work<<endl;
	for (int i = 1; i <= work; i++)
		cout <<"����" <<date[J[i]] << "    Ȩֵ" << p[J[i]] << endl;
	system("pause");
}


