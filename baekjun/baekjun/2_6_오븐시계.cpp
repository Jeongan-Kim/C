#include <iostream>

int main()
{
	int A, B, C;
	std::cin >> A >> B;
	std::cin >> C;

	int H = (B + C) / 60;
	int M = (B + C) % 60;

	if (B + C >= 60)
	{
		if (A + H > 23)
			std::cout << (A + H) - 24 << " " << M;
		else
			std::cout << A + H << " " << M;
	}
	else if (B + C < 60)
	{
		if (A + H > 23)
			std::cout << (A + H) - 24 << " " << B + C;
		else
			std::cout << A + H << " " << B + C;
	}

	return 0;
}