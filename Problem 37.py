import os

os.system("clear")

def is_prime(num:int) -> bool:
    if num < 2:
        return False
    for i in range(2, int(num/2)+1):
        if (num % i) == 0:
            return False
    return True

truncatable_prime_counter = 0
truncatable_primes_sum = 0

for num in range(8, 740000):
    if is_prime(num):
        num_str = str(num)

        truncatable_prime = True
        for i in range(1, len(num_str)):    # cutt from left to right
            cutted_num = num_str[i:]
            if not is_prime(int(cutted_num)):
                truncatable_prime = False
                break
        
        if not truncatable_prime:
            continue

        for i in range(len(num_str)-1, 0, -1):  # cut from right to left
            cutted_num = num_str[0:i]
            if not is_prime(int(cutted_num)):
                truncatable_prime = False
                break

        if not truncatable_prime:
            continue
        else:
            truncatable_prime_counter += 1
            print(truncatable_prime_counter, ": Truncatable prime: ", num)
            truncatable_primes_sum += num
            if truncatable_prime_counter >= 11:
                print("Found all primes...exiting")
                break

print("Truncatable primes sum: ", truncatable_primes_sum)