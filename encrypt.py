import sys

key = sys.argv[1]
inputPath = sys.argv[2]
outputPath = sys.argv[3]

fileInput = open(inputPath, "rt")
fileOutput = open(outputPath, "wb")

inputString = fileInput.read()
lengthString = len(inputString)
lengthKey = len(key)
valuesVector = []

for i in range(0, lengthString):
    x = ord(inputString[i])
    for j in range(0, lengthKey):
        x = x ^ ord(key[j])
    valuesVector.append(x)

binarryVector = bytearray(valuesVector)
fileOutput.write(binarryVector)

fileInput.close()
fileOutput.close()