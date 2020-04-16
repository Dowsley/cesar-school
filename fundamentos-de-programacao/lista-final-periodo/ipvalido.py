def ip_check(nomearq):
	with open(nomearq, 'r') as arq:
		validos = []
		invalidos = []

		for linha in arq: 
			ip = linha.replace('\n', '').split('.')
			
			for i in range(len(ip)):
				ip[i] = int(ip[i])

			if  max(ip) >= 255 or ip[0] == 0 or len(ip) > 4:
				invalidos.append(str(ip))

			else:
				validos.append(str(ip))

	with open('relatorio.txt', 'w') as arq:
		arq.write('[Endereços válidos:]\n')
		for end in validos:
			arq.write(end + '\n')

		arq.write('[Endereços inválidos:]\n')
		for end in invalidos:
			arq.write(end + '\n')

ip_check('IPs.txt')