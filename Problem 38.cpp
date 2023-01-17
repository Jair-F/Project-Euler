#include <iostream>
#include <string>
#include <cstring>

/**
 * @return true if _num is concatenated from 1 to 9
 */
bool is_pandigital(unsigned long long _num)
{
	if (_num < 100000000 || _num > 999999999)
		return false;

	bool used_num[10] = {false, false, false, false, false, false, false, false, false, false};
	while (_num > 0)
	{
		uint8_t digit = _num % 10;
		used_num[digit] = true;
		_num = _num / 10;
	}

	bool ret = true;
	for (uint8_t i = 1; i < 10; ++i)
	{
		if (used_num[i] == false)
			ret = false;
	}

	return ret;
}

int main()
{
	unsigned int largest_pandigital_num = 0;

	for (unsigned int i = 1; i <= 10000; ++i)
	{
		std::string concated_num;
		concated_num = std::to_string(i);

		for (unsigned int n = 2; n <= i && concated_num.length() < 9; ++n)
		{
			concated_num += std::to_string(i * n);

			if (concated_num.length() == 9 && is_pandigital(atoi(concated_num.c_str())))
			{
				std::cout << i << ": " << concated_num << '\n';
				largest_pandigital_num = atoi(concated_num.c_str()); // the last concated num we get is the biggest
				break;
			}
		}
	}

	std::cout << "\n\nlargest 1-9 pandigital num: " << largest_pandigital_num << '\n';

	return 0;
}
