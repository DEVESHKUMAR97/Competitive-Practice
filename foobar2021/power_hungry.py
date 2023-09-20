def multiply_neg(neg):
    sz = len(neg)
    if len(neg) % 2 == 1:
        sz -= 1
    
    res = 1
    for i in range(sz):
        res = res * neg[i]
        
    return res

def solution(xs):
    # Your code here
    pos = []
    neg = []
    zero = []
    
    for i in range(len(xs)):
        if xs[i] == 0:
            zero.append(xs[i])
        elif xs[i] > 0:
            pos.append(xs[i])
        else:
            neg.append(xs[i])
            

    neg.sort()
    
    if len(pos) == 0:
        if len(zero) == 0:
            if len(neg) == 1:
                return str(neg[0])
            else:
                return str(multiply_neg(neg))
        else:
            if len(neg) == 1:
                return str(0)
            else:
                return str(multiply_neg(neg))
    else:
        res = multiply_neg(neg)
        
        for i in range(len(pos)):
            res = res * pos[i]
        return str(res)
 
 
 
    
print(solution([2, 0, 2, 2, 0]))

print(solution([-2, -3, 4, -5]))

