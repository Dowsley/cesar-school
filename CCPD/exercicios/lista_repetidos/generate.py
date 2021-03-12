from random import seed
from random import randint
seed(42)
with open('in.txt', 'w') as out:
    for _ in range(50000):
        value = randint(1, 2001)
        out.write(f"{value}\r\n")