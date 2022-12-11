from SnowflakeInput import *

flakes = createInput(6,10000,"testing")[0]
hashTable = [[]]*len(flakes)

for flake in flakes:
    hash = code(flake,len(flake))
    hashTable[hash].append(flake)
findIdentical(hashTable)