#include <iostream>

int main()
{
	int H, M;
	std::cin >> H >> M;

	if (M - 45 >= 0)
		std::cout << H << " " << M - 45;
	else if (M - 45 < 0)
	{
		if (H > 0)
			std::cout << H - 1 << " " << (60 - 45) + M;
		else if(H == 0)
			std::cout << 23 << " " << (60 - 45) + M;
	}

	return 0;
}