import serial
import numpy
import matplotlib.pyplot as plt

s = serial.Serial('com4', 9600) # podesite odgovarajuci COM port
k = 0
niz = []
suma = 0;
while (k < 30):
    if s.inWaiting() > 0:
        m = s.readline()
        try:
            r = float(m)
            print (r)
            niz.append(r)
            suma = suma + r;
            k = k + 1
            if(
        except:
            pass
avg = suma / k
print(avg)
print(min(niz))
print(max(niz))
suma2 = 0
for(elem in niz):
    suma2 = suma2 + (elem-avg)*(elem-avg)
besel = Math.sqrt((suma2)/(k-1))
plt.hist(niz)
plt.title("Histogram")
plt.xlabel("kapacitivnost")
plt.ylabel("frekvencija")
plt.show()
