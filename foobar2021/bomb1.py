# cook your code here
def solution(x, y):
    # Your code here
    x = int(x)
    y = int(y)
    
    m = 1 
    f = 1 
    
    m_queue = []
    f_queue = []
    
    m_queue.append(m)
    f_queue.append(f)
    
    level = 0
    nicl = 1 
    ninl = 0
    
    while len(m_queue) != 0:
        m = m_queue.pop(0)
        f = f_queue.pop(0)
        
        if m == x and f == y:
            return level
            
        if m + f <= y:
            m_queue.append(m)
            f_queue.append(m + f)
            ninl += 1 
            
        
        if m + f <= x:
            m_queue.append(m + f)
            f_queue.append(f)
            ninl += 1 
            
        
        
        nicl -= 1 
        
        if nicl == 0:
            nicl = ninl
            ninl = 0
            level += 1 
            
            
    
    return 'impossible'



print(solution('2', '1'))
print(solution('4', '7'))
print(solution('2', '4'))
print(solution('100000000000000000000000000000000000000000000000000', '100000000000000000000000000000000000000000000000000'))