#!/usr/bin/env python3

import gen

import random
random.seed(43)

# program the period sequence
Tseq = []

# learning
for _ in range(16): Tseq.append([1, 2, 3])
# ok work
for _ in range(8):  Tseq.append([1, 2, 3])
# fault
for _ in range(8):  Tseq.append([2, 3, 4])

for T in Tseq:
	for i in range(len(T)):
		T[i] += random.random() * 0.2
	_, Y = gen.gen(T)
	gen.prn(Y)
	
