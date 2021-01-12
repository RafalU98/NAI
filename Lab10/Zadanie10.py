import numpy 

def sigma(x):
    return 1 / (1+ numpy.exp(-x))

def sigma_pochodna(x):
    return x * ( 1 - x)

wejscie = numpy.array([[0,0,1],
                       [1,1,1],
                       [1,0,1],
                       [0,1,1]])

#wagi = numpy.random.random((3, 1)) 
wagi =  numpy.array([[0.012],
                     [0.121],
                     [0.124]])

print('Wagi na starcie: ')
print(wagi)   

wyjscie = numpy.array([[0,1,1,0]]).T

for i in range(1):
    test = sigma(numpy.dot(wejscie, wagi))
    
# liczbe przejsc podajemy w nawiasach
for i in range(100000):
    #przy kazdej iteracji liczy wyjscie treningowe
    wyjscie_trening = sigma(numpy.dot(wejscie, wagi))         
    
    # wylicza roznice miedzy wyjsciem docelowym i treningiem i robi korekte 
    error = wyjscie - wyjscie_trening                         
    korekta = error * sigma_pochodna(wyjscie_trening)
    
    # wylicza nowe wagi zgodnie z korektą
    wagi += numpy.dot(wejscie.T, korekta)
    
print('Wagi po treninungu')
print(wagi)   

print('------------------------')
    
print('Wyniki przed treningiem: ')
print(test)

print('Wyniki po treningu: ')
print(wyjscie_trening)

print('Wyniki docelowe: ')
print(wyjscie)

print('------------------------')
print('Błąd: ')
print(wyjscie - wyjscie_trening)

