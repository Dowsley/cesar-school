#Questao 2
a=input(("Telefonou para a vítima? "))
b=input(("Esteve no local do crime? "))
c=input(("Mora perto da vítima? "))
d=input(("Devia para a vítima? "))
e=input(("Já trabalhou com a vítima? "))
x=0
if a=="sim" or a=="Sim":
    x=x+1
if b=="sim" or b=="Sim":
    x=x+1
if c=="sim" or c=="Sim":
    x=x+1
if d=="sim" or d=="Sim":
    x=x+1
if e=="sim" or e=="Sim":
    x=x+1

if x==0 or x==1:
    print("Inocente")
if x==2:
    print("Suspeito")
if x==3 or x==4:
    print("Cúmplice")
if x==5:
    print("Assassino")
