#include "iostream"
#include "stdlib.h"
#define MAX 333

#define K 5
using namespace std;
typedef struct Node {
	int i;
	int quan;
	struct Node *next;
}Node;


int main() {
	int weight[12][12];
	Node* L[12];
	int s;
	int path[K];
	for (s = 0; s < 12; s++)
		for (int j = 0; j < 12; j++)
			weight[s][j] = MAX;
	weight[0][1] = 9; weight[0][2] = 7; weight[0][3] = 3; weight[0][4] = 2;
	weight[1][5] = 4; weight[1][6] = 2; weight[1][7] = 1; weight[2][5] = 2; weight[2][6] = 7; weight[3][7] = 11; weight[4][6] = 11; weight[4][7] = 8;
	weight[5][8] = 6; weight[5][9] = 5; weight[6][8] = 4; weight[6][9] = 3; weight[7][9] = 5; weight[7][10] = 6;
	weight[8][11] = 4; weight[9][11] = 2; weight[10][11] = 5;

	for (int i = 0; i < 12; i++)
		L[i] = (Node *)malloc(sizeof(Node));

	Node *q ,*p;
	for (int i = 0; i < 12; i++)
	{
		q = L[i];
		for (int j = 0; j < 12; j++)
			if (weight[i][j] > 0 && weight[i][j] < MAX)
			{
				p = (Node *)malloc(sizeof(Node));
				p->i = j;
				p->quan = weight[i][j];
				q->next = p;
				q = p;
			}
		q->next = NULL;
	}

	int i, j, maxlen, temp, v[12], d[12];
	for (i = 0; i < 12; i++)
		v[i] = 0;
	for (i = 10; i >= 0; i--)
	{
		for (maxlen = MAX, j = i + 1; j <12; j++)
			if (weight[i][j] > 0 && weight[i][j] + v[j] < maxlen)
			{
				maxlen = weight[i][j] + v[j];
				temp = j;
			}
		v[i] = maxlen;
		d[i] = temp;
	}
	path[0] = 0;
	path[K - 1] = 11;
	for (i = 1; i <= K - 2; i++)
		path[i] = d[path[i - 1]];

	for (i = 0; i < K; i++)
		printf("%d ", path[i] + 1);
	printf("\n");

	system("pause");
	return 0;}
