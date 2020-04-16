def salva_aluno(notas):
	maior_nota = max(notas)
	c = 1
	for n in notas:
		nova = (n*10)/maior_nota
		print('{}\t{}\t{}'.format(c, n, nova))

while True:
	l = []
	x = input('Nota: ')
	if x == '':
		break
	else:
		float(x).append(l)

salva_aluno([3.0, 4.0, 5.0, 6.0, 3.0])