# Chapter 4.1, Find Max SubArray
#ttttttest

import sys

# Original code
# Parameter: array
# Print: the largest sum and range
# Be careful: range record staff
def FindMaxSubArray(oneArray):
    start = 0
    end   = 0
    sum   = 0
    index = -1;
    result = -sys.maxint - 1
    resultStart = 0
    resultEnd = 0
    for i in oneArray:
        index += 1
        sum += i
        if sum > result:
            result = sum
            end = index
            resultStart = start
            resultEnd = end
        elif sum < 0:
            end = index + 1
            start = end
            sum = 0
#       print 'index=', index, result, sum, start, end, resultStart, resultEnd
    print 'the larges sum is:', result, 'start:', resultStart, 'end:', resultEnd
#    return result


# Main function
#a = [-2, -12, -3, -44, -11, -52, -18, -10, -64, -41, -1]
a = [int(x) for x in sys.argv[1:]]
FindMaxSubArray(a)

# Exercise 4.1-1
# If all the elementes in the array are negative values, then the algorithm will return the one with minimum abs value.

# Exercise 4.1-2
