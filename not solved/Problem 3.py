
# https://www.gut-erklaert.de/mathematik/primfaktorzerlegung-primfaktoren.html

def isPrime(number:int) -> bool:
	for i in range(2, number):
		if not number % i:
			return False
	return True



for i in range(600851475143, 2, -1):
	if isPrime(i):
		print(i)
		break