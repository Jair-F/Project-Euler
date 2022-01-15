import os

os.system("clear")

# money is the amount of money in which the constallations should be created
# @param max_money is to eliminate duplicates - cant use bigger money than the previous recursion
def constellations(money:int, max_money:int = None) -> int:
    if max_money == None:
        max_money = money
    coin_options = [1,2,5,10,20,50,100,200]
    num_of_constellations = 0
    for coin in coin_options:
        if coin > max_money:
            continue
        if money - coin > 0:
            num_of_constellations += constellations(money - coin, coin)
        elif money - coin == 0:
            num_of_constellations += 1
    return num_of_constellations

print(constellations(200))