import os

os.system("clear")

def is_pandigital(number:str) -> bool:
    used_numbers = { 1:0, 2:0, 3:0, 4:0, 5:0, 6:0, 7:0, 8:0, 9:0 }

    for i in number:
        i = int(i)
        if i > 0 and i <= 9:
            used_numbers[i] += 1
    
    for i in range(1, 9 + 1):
        if used_numbers[i] != 1:
            return False
    return True

sum_of_pandigital_nums = 0

for num in range(1234, 9999+1): # the product has to be a four digit value
    for multiplicand in range(1, int(num/2) + 1):
        if num % multiplicand == 0: # if num is divideable
            multiplier = int(num / multiplicand)
            whole_number = str(multiplier) + str(multiplicand) + str(num)
            if len(whole_number) > 9:
                continue
            if is_pandigital(whole_number):
                print(multiplier, '*', multiplicand, '=', num , '->', whole_number)
                sum_of_pandigital_nums += num
                break

print(sum_of_pandigital_nums)