def in_range_p(num):
	if num < 0:
		return 0
	elif num > 10:
		return 0
	else:
		return 1

def has_pair_p(mask, num):
	target = 10 - num
	if mask & (0x1 << target):
		return 1
	else:
		return 0

def add_to_mask(mask, num):
	return mask | (0x1 << num)

words = [1, 2, 3, 8, 11]
mask = 0
for w in words:
	if in_range_p(w):
		mask = add_to_mask(mask, w)
		if has_pair_p(mask, w):
			print "find a pair: ", w, " + ", 10-w
print("EOP")
