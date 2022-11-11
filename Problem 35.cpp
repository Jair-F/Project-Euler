#include <iostream>
#include <list>
//#include <algorithm>

bool is_prime(uint32_t _num)
{
    // if (_num < 2)
    //     return false;

    for (uint32_t i = 2; i < _num / 2 + 1; ++i)
    {
        if (_num % i == 0)
            return false;
    }
    return true;
}

bool is_13579(uint32_t _num)
{
    do
    {
        uint8_t digit = 0;
        if (_num / 10 > 0)
        {
            digit = _num % ((_num / 10) * 10);
        }
        else
        {
            digit = _num;
            //_num = 0;
        }
        _num /= 10;

        switch (digit)
        {
        case 1:
            break;
        case 3:
            break;
        case 5:
            break;
        case 7:
            break;
        case 9:
            break;

        default:
            return false;
            break;
        }

    } while (_num > 0);

    return true;
}

int main()
{
    uint16_t circular_primes = 0; // counter
    for (uint32_t i = 1; i < 1'000'000; i++)
    {
        if (!is_13579(i))
            continue;

        if (is_prime(i))
        {
            std::list<uint8_t> num_digits;
            bool circular_prime = true;

            uint32_t tmp = i;
            do
            {
                uint8_t digit = 0;
                if (tmp / 10 > 0)
                {
                    digit = tmp % ((tmp / 10) * 10);
                    num_digits.emplace_back(digit);
                }
                else
                {
                    num_digits.emplace_back(tmp);
                }

                tmp /= 10;

            } while (tmp > 0);

            num_digits.reverse();
            auto r = num_digits.begin();
            while (r != num_digits.end())
                ++r;

            auto iterator = num_digits.begin();
            ++iterator; // 1 number doesnt need to check - the actual number is a prime...
            for (uint16_t a = 0; a < num_digits.size() - 1; ++a)
            {
                uint32_t num_to_check = 0;
                for (uint16_t b = 0; b < num_digits.size(); ++b)
                {
                    num_to_check *= 10;
                    num_to_check += *iterator;

                    ++iterator;
                    if (iterator == num_digits.end())
                        iterator = num_digits.begin();
                }

                // shift the iterator - so we get a different number next time - normally we end at the same position we started
                ++iterator;
                if (iterator == num_digits.end())
                    iterator = num_digits.begin();

                if (!is_prime(num_to_check))
                {
                    circular_prime = false;
                    break;
                }
            }

            if (circular_prime)
            {
                ++circular_primes;
                std::cout << i << ' ';
            }
        }
    }

    std::cout << "\nnum of circular primes below 1'000'000: " << circular_primes << '\n';
    return 0;
}
