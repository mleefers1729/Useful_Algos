'''
This is used to generate random snowflakes for the snowflake search algo in the repo. It outputs a text file with one snowflake per line of the file.
You will need to update the code for the algo to match your filepath here as well. This should take less than 1 sec to generate a 100,000 line file.
'''

import random

numFlakes = 100000
numRods = 6
flakes = []
for i in range(numFlakes):
	flake = []
	for y in range(numRods):
		flake.append(random.randint(0,10000000))
	flakes.append(flake)

with open('YourFilePathHere/SnowflakeInput.txt','w') as f:
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


