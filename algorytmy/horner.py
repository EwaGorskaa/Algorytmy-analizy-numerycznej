def Horner(stopien, a, punkt):
    for i in range(1, stopien + 1):
        w = a[0]
        w = w * stopien + a[i]
    return w

def HornerU(stopien, a, punkt):
    for i in range(0,stopien):
        for k in range(1, stopien - i + 1):
            a[k] = a[k-1] * punkt + a[k]

    for i in range(n, -1):
        for j in range(1, stopien - i + 1):
            a[i] *= j

    print(f"wartosci pochodnych wielomianu w punkcie {punkt} wynosza: ")

    for i in range(stopien - 1, -1):
        print(f"{i} pochodna = {a[i]}", end = "\n")


        
a = []
n = int(input("podaj stopien wielomianu: "))

for i in range(n, -1):
    el = int(input(f"podaj wspolczynnik przy {i} potedze: "))
    a.append(el)

c = int(input("podaj punkt w ktorym bedzie liczona wartosc wielomianu: "))

wynik = Horner(n, a, c)

print("wartosc wielomianu w punkcie p wynosi: ", wynik)

HornerU(n,a,c)

      