

class Number:
    def __init__(self, product:str, multiplicant:str, multiplier:str):
        self.product = product
        self.multiplicant = multiplicant
        self.multiplier = multiplier

def is_pandigital(num:Number) -> bool:
    number = str(num.product) + str(num.multiplicant) + str(num.multiplier)
    number_occoured = [0, 0, 0, 0, 0, 0, 0, 0, 0]    # contains elements at positions from 0-8(1-9) each position saves, how often the related number occoured in the number

    for digit in number:
        number_occoured[int(digit)-1] += 1
    
    for num in number_occoured:
        if num != 1:    # every digit(from 1-9) has to be in the number exactly 1 time
            return False
    return True
    
# 98765432
upper_limit = 987654
pandigital_numbers = []

for check_product in range(1, upper_limit+1):
    for multiplicant in range(1, check_product+1):
        if check_product % multiplicant == 0:   # Check if we can dived the number without a "rest"
            num = Number(check_product, multiplicant, int(check_product/multiplicant))   # if we can divide the number - the multiplier is simply:
            if is_pandigital(num):
                #print(check_product, ' ', num.multiplier, ' ', num.multiplicant)
                pandigital_numbers.append(check_product)

pandigital_numbers = list(set(pandigital_numbers)) # make every element unique

for number in pandigital_numbers:
    print(number)
    pass

print()
print("Num of pandigital numbers: " + str(len(pandigital_numbers)))

sum = 0
for num in pandigital_numbers:
    sum += num
print("Sum: ", sum)
