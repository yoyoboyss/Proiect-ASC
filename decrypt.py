import sys

inputPath = sys.argv[1]
key = sys.argv[2]
outputPath = sys.argv[3]

fileInput = open(inputPath, "rb")
fileOutput = open(outputPath, "w")

inputString = fileInput.read()
lengthString = len(inputString)
lengthKey = len(key)
decryptedString = ""

for i in range(0, lengthString):
    x = inputString[i]
    for j in range(0, lengthKey):
        x = x ^ ord(key[j])
    decryptedString = decryptedString + chr(x)

fileOutput.write(decryptedString)
