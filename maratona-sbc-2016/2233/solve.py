r = int(input(), 16)
g = int(input(), 16)
b = int(input(), 16)
G = (r//g) ** 2
if g > r:
    G = 0
B = G * ((g//b) ** 2)
print(hex(1 + G + B).split('x')[-1])