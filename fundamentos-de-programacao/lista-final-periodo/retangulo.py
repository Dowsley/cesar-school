def retangulo (linhas, colunas):
	if linhas > 20:
		linhas = 20
	if linhas <= 1:
		linhas = 2
	if colunas > 20: 
		colunas = 20
	if colunas <= 1:
		colunas = 2

		
	if colunas != 2:
		print('+', end = '')
		for i in range(colunas-2):
			print('-', end = '')
			
			if i == colunas-3:
				print('+')
	else:
		print('++')
	
	espaço = ''
	for i in range(colunas-2):
		espaço += ' '
	espaço = ('|{}|'.format(espaço))
	for i in range(linhas-2):
		print(espaço)

	if colunas != 2:
		print('+', end = '')
		for i in range(colunas-2):
			print('-', end = '')
			
			if i == colunas-3:
				print('+')
	else:
		print('++')

x = int(input('Linhas: '))
y = int(input('Colunas: '))
retangulo(x, y)