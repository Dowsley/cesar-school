with open('a.csv', 'r', encoding = 'UTF8') as a:
	l = []
	for linha in a:
		l.append(linha.replace('\n', '').split(','))
print(l)