# primera parte
def sum_3 (a, b, c):
    return a + b + c

sum_3(10, 20, 30)

# segunda parte
class coche:
    puertas = 0
    def add_puerta(puertas):
        coche.puertas += 1
        return coche.puertas

miCoche = coche()
miCoche.add_puerta()
print(miCoche.puertas)
