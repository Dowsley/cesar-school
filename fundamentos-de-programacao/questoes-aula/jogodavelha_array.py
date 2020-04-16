#João Dowsley e Renan Didier Rizzatto

jogadas = 0

print('Este programa foi desenvolvido a partir da colaboração entre João Felipe Costa Dowsley e Renan Didier Rizzatto')

print('Coloque as posições separadas por espaço')

def check(index, simbolo):
    c = 0
    for i in matriz[index]:
        if i == simbolo:
            c = c + 1
    if c == 3:
        print(f'O {simbolo} ganhou')
        return c
    
    c = 0
    n = 0
    while n < 3:
        if matriz[n][index] == simbolo:
            c = c + 1
        n = n + 1
    
    if c == 3:
        print(f'O {simbolo} ganhou!')
        return c

    if matriz[1][1] != ' ':
        if matriz[0][0] == matriz[1][1] == matriz[2][2]:
            print(f'O {simbolo} ganhou!')
            c = 3
            return c
        if matriz[0][2] == matriz[1][1] == matriz[2][0]:
            print(f'O {simbolo} ganhou!')
            c = 3
            return c

matriz = [[' ',' ',' '],[' ',' ',' '],[' ',' ',' ']]

print(matriz[0])
print(matriz[1])
print(matriz[2])

while True:
    
    while True:
        x = input('x - Digite a posição: ')
        pos = x.split()
        if (int(pos[0]) < 3 and int(pos[0]) > -1) and (int(pos[1]) < 3 and int(pos[1]) > -1):
            if matriz[int(pos[0])][int(pos[1])] == ' ':
                matriz[int(pos[0])][int(pos[1])] = 'X'
                break
            else:
                print('Posição inválida, tente novamente')
        else: 
            print("Posição inválida, tente novamente")

    print(matriz[0])
    print(matriz[1])
    print(matriz[2])

    if check(0,'X') == 3:
        break
    if check(1,'X') == 3:
        break
    if check(1,'X') == 3:
        break
    
    jogadas += 1
    if jogadas >= 9:
        print('Deu velha! KKK')
        break
        

    while True:
        o = input('o - Digite a posição: ')
        pos = o.split()
        if (int(pos[0]) < 3 and int(pos[0]) > -1) and (int(pos[1]) < 3 and int(pos[1]) > -1):
            if matriz[int(pos[0])][int(pos[1])] == ' ':
                matriz[int(pos[0])][int(pos[1])] = 'O'
                break
            else:
                print('Posição inválida, tente novamente')
        else:
            print("Posiçao invalida, tente novamente")

    print(matriz[0])
    print(matriz[1])
    print(matriz[2])

    if check(0,'O') == 3:
        break
    if check(1,'O') == 3:
        break
    if check(2,'O') ==3:
        break
    
    jogadas += 1
    if jogadas >= 9:
        print('Deu velha! KKK')
        break
        
