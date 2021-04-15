#!/usr/bin/python3
"""
Rain
"""
def rain(walls):
	"""
	walls
	"""
	var1 = 0
	leng = len(walls)

	if leng == 0:
		return 0

	for i in range(1, leng - 1):
		left = walls[i]
		for j in range(i):
			left = max(left, walls[j])

		right = walls[i]

		for j in range(i + 1, leng):
			right = max(right, walls[j])
		
		var1 = var1 + (min(left, right) - walls[i])

	return var1;
