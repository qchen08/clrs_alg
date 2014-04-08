# Exercise 4.1-1

MaxStartIdx = 0
MaxEndIdx = 0
array = [-2, 1, -3, 4, -1, 2, 1, -10, 4, 1]

def FindMaxSubArray(array):
	global MaxStartIdx
	global MaxEndIdx
	MaxSum = 0
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

ret = FindMaxSubArray(array)
print('Sum = {}'.format(ret))
print_subarray(array)

