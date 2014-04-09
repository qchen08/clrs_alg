# Chapter 4.1, Find Max SubArray
#ttttttest

import sys
#import pudb; pu.db

# Result Object
class Result:
     def __init__(self, summ=0, start=0, end=0):
         self.sum = summ
         self.start = start
         self.end = end

# Exercise 4.1-1
# If all the elementes in the array are negative values, then the algorithm will return the one with minimum abs value.

# Exercise 4.1-2
# Brute force version, use two for-loops, time complexity: O(n^2)
def BruteForce(oneArray):
    sum = 0
    indexStart = -1
    indexEnd = -1
    result = -sys.maxint - 1
    resultStart = 0
    resultEnd = 0
    for i in oneArray:
        sum = i
        indexStart += 1
        indexEnd = indexStart
        if sum > result:
            result = sum
            resultEnd =indexEnd
            resultStart = indexStart
        for j in oneArray[indexStart+1:]:
            indexEnd += 1
            sum += j
            if sum > result:
                result = sum
                resultEnd =indexEnd
                resultStart = indexStart
    return Result(result, resultStart, resultEnd)
    
    
# Exercise 4.1-3
# Recursive version
# helper function, find the max subarray that accrosses the mid element
def FindAcrossMid(oneArray, left, mid, right):
    leftRes = -sys.maxint - 1
    leftIndex = mid+1
    leftEnd = 0
    sum = 0
    for i in reversed(oneArray[left:mid+1]):
        sum += i
        leftIndex -= 1
        if sum > leftRes:
            leftRes = sum
            leftEnd = leftIndex
    rightRes = -sys.maxint - 1
    rightIndex = mid-1
    rightEnd = 0
    sum = 0
    for i in oneArray[mid:right+1]:
        sum += i
        rightIndex += 1
        if sum > rightRes:
            rightRes = sum
            rightEnd = rightIndex
    if (leftRes+rightRes - oneArray[mid] > leftRes) and (leftRes+rightRes-oneArray[mid] > rightRes):
        return Result(leftRes+rightRes-oneArray[mid], leftEnd, rightEnd)
    elif (leftRes > leftRes+rightRes-oneArray[mid]) and (leftRes > rightRes):
        return Result(leftRes, leftEnd, mid)
    else:
        return Result(rightRes, mid, rightEnd)
    
def RecursvieFindMaxSubArray(oneArray, left, high):
    if left == high:
        return Result(oneArray[left], left, high)
    mid = (left + high) / 2
    leftRes = RecursvieFindMaxSubArray(oneArray, 0, mid)
    rightRes = RecursvieFindMaxSubArray(oneArray, mid+1, high)
    midRes = FindAcrossMid(oneArray, left, mid, high)
    if (leftRes.sum > rightRes.sum) and (leftRes.sum > midRes.sum):
        return leftRes
    elif (rightRes.sum > leftRes.sum) and (rightRes.sum > midRes.sum):
        return rightRes
    else:
        return midRes

# Exercise 4.1-4
# Add one condition check in the end, if the largest sum is a negative value, then 
# return an empty array with sum = 0.

# Exercise 4.1-5
# Nonrecursive, linear
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
    return Result(result, resultStart, resultEnd)

    
# Main function
#a = [-2, -12, -3, -44, -11, -52, -18, -10, -64, -41, -1]
a = [int(x) for x in sys.argv[1:]]
linearRes = FindMaxSubArray(a)
bruteForceRes = BruteForce(a)
RecurRes = RecursvieFindMaxSubArray(a, 0, len(a)-1)
print 'Linear: sum=', linearRes.sum, 'start=', linearRes.start, 'end=', linearRes.end
print 'BruteForce: sum=', bruteForceRes.sum, 'start=', bruteForceRes.start, 'end=', bruteForceRes.end
print 'Recursive: sum=', RecurRes.sum, 'start=', RecurRes.start, 'end=', RecurRes.end
print ''