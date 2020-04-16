def maximo(x,y,z):
    if x>=y:
        if x>z:
            return x
        else:
            return z
    if y>=x:
        if y>z:
            return y
        else:
            return z
