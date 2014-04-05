#First Python script
#Find if there exist two numbers in an array whose sum equals 10

from array import *

oneArray = [1,2,3,4,5,9]
bitResult = 0
bitMask = 0x1
result = False
for i in oneArray:
#	print(i)
    if bitResult & (bitMask << i):
        print("find one")
        result = True
        break
    else:
        bitResult |= bitMask<<(10-i)
if(result):
    print("YES")
else:
    print("NO")