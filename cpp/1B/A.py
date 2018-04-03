from collections import Counter
import sys.stdin

words = [
   "ZERO",
   "ONE",
   "TWO",
   "THREE",
   "FOUR",
   "FIVE",
   "SIX",
   "SEVEN",
   "EIGHT",
   "NINE"
]
ref = [0,6,7,5,4,8,3,2,9,1]

def contains(container, contained):
	return all(container[x] >= contained[x] for x in contained)


def solve(s, n=0):
	if len(s)==0:
		return ""
	if n>9:
		return None
	w = Counter(words[ref[n]])
	if contains(s,w):
		res = solve(s-w, n)
		if res==None:
			return solve(s,n+1)
		return str(n)+res
	else:
		return solve(s,n+1)

n = input()
for i in range(1,n+1,1):
	stri = sys.stdin.readline()
	print "Case #"+i+": "+solve(stri)