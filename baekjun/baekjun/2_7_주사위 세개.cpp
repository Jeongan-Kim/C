#include <iostream>

int case2(int a, int b, int c)
{
	if (a == b && a != c)
		return a;
	else if (a == c && a != b)
		return a;
	else if (c == b && a != c)
		return b;
}

int case3(int a, int b, int c)
{
	int Max = a;
	if (b > Max)
	{
		Max = b;
		if (c > Max)
			Max = c;
	}
	else if (c > Max)
		Max = c;

	return Max;
}

int main()
{
	int a, b, c, money = 0;
	std::cin >> a >> b >> c;

	if (a == b && b == c)
		money += 10000 + a * 1000;
	else if ((a == b && a != c) || (a == c && a != b) || (c == b && a != c))
		money += 1000 + case2(a, b, c) * 100;
	else if (a != b && a != c && b != c)
		money += case3(a, b, c) * 100;

	std::cout << money;
	return 0;
}