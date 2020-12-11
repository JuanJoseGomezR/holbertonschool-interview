#!/user/bin/python3


def canUnlockAll(boxes):
	keys = [0]
	for key in keys:
		for idx in boxes[key]:
			if (idx not in keys and idx != key and idx < len(boxes) and idx != 0):
				keys.append(idx)
	if len(keys) == len(boxes):
		return True
	return False

