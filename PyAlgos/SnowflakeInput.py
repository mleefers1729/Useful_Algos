'''
This is used to generate random snowflakes for the snowflake search algo in the repo. It outputs a text file with one snowflake per line of the file.
You will need to update the code for the algo to match your filepath here as well. This should take less than 1 sec to generate a 100,000 line file.
'''

def createInput(rods,numFlakes,outPutFile):
	import random
	flakes = []
	for i in range(numFlakes):
		flake = []
		for y in range(rods):
			flake.append(random.randint(0,10000000))
		flakes.append(flake)

	with open(outPutFile + '.txt','w') as f:
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

def code(flake,size):
	return sum(flake)%size

def move_right(flake_1,flake_2,start):
	for i in range(len(flake_1)):
		if flake_1[i] != flake_2[start+i % 6]:
			return 0
		return 1

def move_left(flake_1,flake_2,start):
	for i in range(len(flake_1)):
		flake_2_idx = start - i
		if flake_2_idx < 0:
			flake_2_idx = flake_2_idx + 6
		if flake_1[i] != flake_2[flake_2_idx]:
			return 0
		return 1

def areIdentical(flake_1,flake_2):
	for i in range((len(flake_1))):
		if move_right(flake_1,flake_2,i):
			return 1
		if move_left(flake_1,flake_2,i):
			return 1
		return 0


