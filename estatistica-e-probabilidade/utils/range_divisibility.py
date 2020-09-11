def is_divisible(num, divs):
	return all([num % div == 0 for div in divs])

# MAIN
start = int(input('Start of range: '))
end = int(input('End of range: '))
divs = list(
	map(
		lambda i: int(i),
		input('Type in the divisors, separated by commas: ').split(',')
	)
)

divisibles = [n for n in range(start, end) if is_divisible(n, divs)]
print(divisibles)