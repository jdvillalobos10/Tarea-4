import numpy as np
import matplotlib.pyplot as plt

mapa=np.genfromtxt("map_data.txt")
coordenadas=np.genfromtxt("mejor.txt")

radio=coordenadas[:,2].argmax()
x=coordenadas[:,0].argmax()
y=coordenadas[:,1].argmax()

fig, ax=plt.subplots()
circulo1=plt.Circle((x,y),radio,color="r")
ax.add_artist(circulo1)
ax.add_artist(plt.imshow(mapa,cmap="winter"))
ax.set_title("Punto Nemo de la tierra")
ax.set_xlabel("Longitud")
ax.set_ylabel("Latitud")
plt.savefig("PuntoNemo.pdf")
plt.close()
