# Exercise 4.1-1
import sys
MaxStartIdx = 0
MaxEndIdx = 0

def FindMaxSubArray(array):
	global MaxStartIdx
	global MaxEndIdx
	MaxSum = -sys.maxint-1
	i = 0
	StartIdx = 0
	EndIdx = 0
	Sum = 0
	for a in array:
		tmpSum = Sum + a
		if tmpSum > MaxSum:
			MaxSum = tmpSum
			MaxStartIdx = StartIdx
			MaxEndIdx = i
		if tmpSum < 0:
			Sum = 0
			StartIdx = i+1
			EndIdx = i+1
		else:
			Sum = tmpSum
			EndIdx = i
		i=i+1
	return MaxSum


def print_subarray(array):
	print("array[{}:{}] = '".format(MaxStartIdx, MaxEndIdx)),
	for a in array[MaxStartIdx:MaxEndIdx+1]:
		print(a),
	print("'")

array = [int(x) for x in sys.argv[1:]]
print 'Input: ', array
ret = FindMaxSubArray(array)
print('Sum = {}, '.format(ret)), 
print_subarray(array)
print ''
