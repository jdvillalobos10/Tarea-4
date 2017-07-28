PuntoNemo.pdf: mejor.txt Plots.py
	python Plots.py

mejor.txt: a.out
	./a.out

a.out: GeographicPoint.c
	cc GeographicPoint.c -lm
