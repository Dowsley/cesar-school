senhas_input = input("Digite as senhas separadas por vírgulas: ").split(",")
senhas_output = "As senhas fortes são: "

for senha in senhas_input:
	print("Analisando senha:",senha)
	req1=False
	req2=False
	req3=False
	req4=False
	req5=False
	req6=False
	
	if len(senha)>=6 and req5==False:
		req5=True
	if len(senha)<=12 and req6==False:
		req6=True
	
	for char in senha:
		if char.isalpha()==True and char.islower()==True and req1==False:
			req1=True
		if char.isdigit()==True and req2==False:
			req2=True
		if char.isalpha()==True and char.isupper()==True and req3==False:
			req3=True
		if (char=="$" or char=="#" or char=="@") and req4==False:
			req4=True
	
	if req1==True and req2==True and req3==True and req4==True and req5==True and req6==True:
		if senhas_input.index(senha)==len(senhas_input)-1:
			senhas_output+=senha
		else:
			senhas_output += senha +","
print(senhas_output)