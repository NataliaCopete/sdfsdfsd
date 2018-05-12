import numpy as np
import matplotlib.pyplot as plt

datos=np.loadtxt("datos.txt")
x=datos[0:10000,1]
y=datos[0:10000,0]
z=datos[0:10000,2]

plt.plot(x,y)
plt.savefig("grafica.png")
plt.clf()
plt.plot(y,z)
plt.savefig("grafica1.png")
