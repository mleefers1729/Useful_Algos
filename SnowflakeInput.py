import random
import string

numFlakes = 50000
numRods = 6
flakes = []
for i in range(numFlakes):
	flake = []
	for y in range(numRods):
		flake.append(random.randint(0,10000000))
	flakes.append(flake)

with open('C:/Users/mitchell leefers/Documents/MyFiles/SnowflakeInput.txt','w') as f:
	for flk in flakes:
		line = ''
		for val in flk:
			if flk.index(val) != 5:
				line = line + str(val) + ','
			else:
				line = line + str(val)
		f.write(line)
		f.write('\n')
f.close()


