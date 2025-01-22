#include <iostream>
using namespace std;

int N;

int sol(int n)
{
	if (n <= 1)
		return 0;

	int s1 = sol(n / 3) + n % 3 + 1;
	int s2 = sol(n / 2) + n % 2 + 1;
	return (s1 < s2) ? s1 : s2;
}

int main()
{
	scanf("%d", &N);
	printf("%d", sol(N));

	return 0;
}