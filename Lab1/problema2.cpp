#include <cstdio>
#include <cstring>

char prop[1001][256];

struct word {
	int id, len;
};

void swap(word &a, word &b) {
	word aux = a;
	a = b;
	b = aux;
}

int comp(int id1, int id2) {
	for (int i = 0; prop[id1][i]; i++) {
		if (prop[id1][i] < prop[id2][i])
			return -1;
		else if (prop[id1][i] > prop[id2][i])
			return 1;
	}
	return 0;
}

int partition(word *v, int l, int r) {
	word x = v[r];
	int i = l - 1;
	for (int j = l; j < r; j++) {
		if (v[j].len > x.len || v[j].len == x.len && comp(v[j].id, x.id) > 0) {
			i++;
			swap(v[i], v[j]);
		}
	}
	swap(v[i + 1], v[r]);
	return i + 1;
}

void qsortwords(word *v, int l,int r) {
	if (l < r) {
		int k = partition(v, l, r);
		qsortwords(v, l, k - 1);
		qsortwords(v, k + 1, r);
	}
}

int main() {
	int n = 0;
	word v[1001];
	while (scanf("%255s",prop[n]) != EOF) {
		v[n].len = strlen(prop[n]);
		v[n].id = n;
		n++;
	}

	qsortwords(v, 0, n - 1);

	for (int i = 0; i < n; i++) {
		printf("%s\n", prop[v[i].id]);
	}
	return 0;
}
