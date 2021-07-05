actualTerm = 2
previousTerm = 1

sum = 0

while(actualTerm <= 4000000):
	if not actualTerm % 2:
		sum += actualTerm
	tmp = actualTerm
	actualTerm = previousTerm + tmp
	previousTerm = tmp

print(sum)