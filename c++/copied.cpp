#include <cstdio>
#include <cmath>
 
typedef long long ll_t;
 
static inline bool
ok(ll_t n, int b)
{
	static int num[64];
	int len = 0;
	while (n) {
		num[len++] = n % b;
		n /= b;
	}
	for (int i = 0, j = len - 1; i < j; i++, j--)
		if (num[i] != num[j])
			return false;
	return true;
}
 
static inline ll_t
get(ll_t n)
{
	switch (n) {
	case 1:
		return 2;
	case 2:
		return 3;
	case 3:
		return 2;
	case 4:
		return 3;
	case 5:
		return 2;
	case 6:
		return 5;
	default:
		int s = sqrt(n) + 1e-8, c = 0;
		for (int i = 2; i <= s; i++) {
			if (ok(n, i))
				return i;
			if (n % i == 0) {
				int t = n / i - 1;
				if (t != i)
					c = t;
			}
		}
		if (c)
			return c;
		return n - 1;
	}
}
 
int
main()
{
	int n;
	scanf("%d", &n);
	while (n--) {
		ll_t x;
		scanf("%lld", &x);
		printf("%lld\n", get(x));
	}
	return 0;
}
 
