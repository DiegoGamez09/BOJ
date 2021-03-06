#include <cstdio>
#include <algorithm>

using namespace std;

int parent[1000001], depth[1000001], n, m;

int find(int n) {
	int &p = parent[n];
	if (p == n) return n;
	else return p = find(p);
}

void uni(int p, int q) {
	p = find(p);
	q = find(q);
	if (p == q) return;
	else if (depth[p] > depth[q]) parent[q] = p;
	else if (depth[p] != depth[q]) parent[p] = q;
	else parent[q] = p, depth[p]++;
}

int main() {
	int a, b, c;
	scanf("%d%d", &n, &m);
	for (int i = 0; i <= n; i++) parent[i] = i;
	fill_n(depth, n + 1, 1);

	while (m--) {
		scanf("%d%d%d", &a, &b, &c);
		if (!a) uni(b, c);
		else {
			b = find(b);
			c = find(c);
			puts(b == c ? "YES" : "NO");
		}
	}
}