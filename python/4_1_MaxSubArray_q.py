# Chapter 4.1, Find Max SubArray
#test

import sys

# Original code
# Parameter: array
# Return: the largest sum of a subarray
def FindMaxSubArray(oneArray):
    start = 0
    end   = 0
    sum   = 0
    result = -sys.maxint - 1
    for i in oneArray:
        sum += i
        if sum < 0:
            end += 1
            start = end
            sum = 0
        elif sum > result:
            result = sum
            end += 1
    print 'the larges sum is:', result, 'start:', start, 'end:', end
#    return result

a = [11,22,-21,33,44,55, -1, 10]
FindMaxSubArray(a)
