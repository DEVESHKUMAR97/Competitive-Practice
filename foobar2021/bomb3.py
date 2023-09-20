# cook your code here
dp = {}

def solve(x, y, depth):
    if x == 1 and y == 1:
        return depth
    
    if x < 1 or y < 1:
        return -1
    
    opt1 = -1
    opt2 = -1
    if x - y >= 1:
        opt1 = solve(x - y, y, depth + 1)
        
    if y - x >= 1:
        opt2 = solve(x, y - x, depth + 1)
        
    
    if opt1 != -1 and opt2 != -1:
        dp[str(x)+'#'+str(y)] = min(opt1, opt2)
    elif opt1 != -1:
        dp[str(x)+'#'+str(y)] = opt1
    elif opt2 != -1:
        dp[str(x)+'#'+str(y)] = opt2
    else:
        dp[str(x)+'#'+str(y)] = opt1
        
    return dp[str(x)+'#'+str(y)]
    
    
    
        
    
    
        
def solution(x, y):
    # Your code here
    x = int(x)
    y = int(y)

    ans = 0
    while x != 1 && y != 1:
        if x == y:
            ans = -1
            break

        minn = min(x, y)
        maxx = max(x, y)

        ans += maxx // minn
        x = minn 
        y = maxx % minn

    if ans != -1:
        return str(ans)
        
    return 'impossible'
    
print(solution('2', '1'))
print(solution('4', '7'))
print(solution('2', '4'))
print(solution('10000000000000000', '100000000000000000000000000000000000000000000000000'))