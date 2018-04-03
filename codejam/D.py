import math
def solve(k,c):
	s=[]
	for i in xrange(0,k):
		print (c-i%c-1)%c
solve (7,3)