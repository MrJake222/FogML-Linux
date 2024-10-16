#!/usr/bin/env python3

import numpy as np

def gen(T, N=64):
	# T: array of 3 numbers
	#    period count in XYZ axes
	# N: no of samples
	N = 64
	# convert to column ndarray 3x1
	T = np.array(T).reshape(-1, 1)

	X = np.linspace(0, 1, N) * 2*np.pi
	Y = np.sin(X * T)
	
	return X, Y
	
	
def prn(Y):
	for i in range(len(Y[0])):
		print(f"{Y[0][i]:10.7f} {Y[1][i]:10.7f} {Y[2][i]:10.7f}")


if __name__ == "__main__":
	import matplotlib.pyplot as plt
	import sys

	if len(sys.argv) < 4:
		print(f"Usage: {sys.argv[0]} <x periods> <y periods> <z periods> [plot]")
		exit(1)
		
	T = [int(x) for x in sys.argv[1:4]]	
	X, Y = gen(T)
	prn(Y)

	if len(sys.argv) == 5:
		for y, label, color in zip(Y, "xyz", ("C1", "C2", "C3")):
			plt.plot(X, y, label=label, color=color)
		plt.legend()
		plt.show()
