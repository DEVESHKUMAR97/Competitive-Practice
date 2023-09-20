# Below is Pythone code for input/output 
ONLINE_JUDGE = not __debug__
if not ONLINE_JUDGE:
	import sys 
	# For getting input from input.txt file 
	sys.stdin = open('input.txt', 'r') 

	# Printing the Output to output.txt file 
	sys.stdout = open('output.txt', 'w') 

def gcdd(a, b):
	if(b == 0):
		return a
	return gcdd(b, a % b)

def minn(a, b):
	if(a <=  b):
		return a
	return b

def lcmm(a, b):
	return  (a * b) // gcdd(a, b) 

for t in range(int(input())):
	n, k = input().split(" ")
	n = int(n)
	k = int(k)
	A = input().split(" ")
	ans = 10**37
	# print(ans)
	for item in A:
		item = int(item)
		ans = minn(ans, lcmm(item, k))

	if ans > 10**18:
		print(-1)
	else:
		print(int(ans))


# def strToNum(s):
# 	i = 0
# 	ans = 0
# 	while i < len(s):
# 		ans = ans * 26 + (ord(s[i]) - 96)
# 		i += 1

# 	final_ans = ""
# 	while ans:
# 		final_ans += str(ans % 1000)
# 		ans //= 1000
# 	return final_ans

# def numToStr(n):
# 	str = ""
# 	n = int(n)
# 	while n:
# 		str += chr(97 + (n-1)%26)
# 		n =(n -1) // 26
# 	return str[::-1]

# while 1:
# 	try:
# 		n = input()
# 		if n == "*":
# 			break
# 		try:
# 			n = int(n)
# 			print(numToStr(n), n)
# 		except:
# 			print(n, strToNum(n))
# 	except:
# 		break


# Problem link : https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=709&page=show_problem&problem=365


