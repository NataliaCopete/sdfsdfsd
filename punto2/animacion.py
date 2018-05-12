import numpy as np
import matplotlib.pyplot as plt
import matplotlib.animation as animation
import os


datos=np.loadtxt("datos.txt")
x=np.linspace(0,100,250)
#for i in range(5):
 # plt.plot(x,datos[:,i], label=str(i))
 # plt.legend()

#plt.figure()
imagenes=[]
for i in range(2000):
 #figura=plt.figure()
 plt.plot(x,datos[i*250:((i+1)*250)])
 #figura.canvas.draw()
 plt.savefig("blabla.png")
 img=plt.imread("blabla.png")
 #os.remove("blabla.png")
 #data = np.fromstring(figura.canvas.tostring_rgb(), dtype=np.uint8, sep='')
 #data = data.reshape(figura.canvas.get_width_height()[::-1] + (3,))
 plt.imshow(img,animated=True) 
 imagenes.append(img1)
 print(i)
 

# Now we can save it to a numpy array.


ani=animation.ArtistAnimation(fig,imagenes)
ani.save("grafica.mp4")
