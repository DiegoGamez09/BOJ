#include <cstdio>
#include <algorithm>

using namespace std;

size_t match[1'000'001] = { 1'000'000 }, n, ma, dp[1'000'000], arr[1'000'000];

int main() {
	scanf("%zu", &n);
	for (size_t i = 0; i < n; i++) {
		scanf("%zu", arr + i);
		match[arr[i]] = i;
	}
	size_t tmp;
	for (size_t i = 0; i < n; i++) {
		dp[i] = match[arr[i] - 1] < i ? dp[match[arr[i] - 1]] + 1 : 1;
		ma = max(ma, dp[i]);
	}
	printf("%zu", n - ma);
}