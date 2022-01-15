sum:int = 0

for i in range(1000):
	if not i % 3:
		sum += i
	elif not i % 5:
		sum += i

print(sum)