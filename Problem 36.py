
def is_palindomic(number:str) -> bool:
    for i in range(int(len(number)/2)):
        if not number[i] == number[len(number) - 1 - i]:
            return False
    return True

sum = 0

for i in range(1000000):
    num_bin = str(bin(i))
    num_bin = num_bin[2:]   # remove the leading 0b
    if is_palindomic(num_bin) and is_palindomic(str(i)):
        print(i, '->', num_bin)
        sum += i
    
print("Sum: ", sum)