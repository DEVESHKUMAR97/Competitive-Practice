def solution(str):


    mp = {}

    s1 = 'code'
    ans1 = '100100101010100110100010'

    idx = 0
    for i in range(len(s1)): 
        if('A' <= s1[i] and s1[i] <= 'Z'):
            mp["BC"] = ans1[idx: idx + 6]
            idx += 6
        

        if ' ' == s1[i]: 
            mp["space"] = ans1[idx: idx + 6]
            idx += 6
        else:
            mp[s1[i].lower()] = ans1[idx: idx + 6]
            idx += 6
            
        
    

    s1 = "Braille"
    ans1 = "000001110000111010100000010100111000111000100010"

    idx = 0
    for i in range(len(s1)): 
        if('A' <= s1[i] and s1[i] <= 'Z'):
            mp["BC"] = ans1[idx: idx + 6]
            idx += 6
        

        if ' ' == s1[i]: 
            mp["space"] = ans1[idx: idx + 6]
            idx += 6
        else:
            mp[s1[i].lower()] = ans1[idx: idx + 6]
            idx += 6		


    s1 = "The quick brown fox jumps over the lazy dog"
    ans1 = "000001011110110010100010000000111110101001010100100100101000000000110000111010101010010111101110000000110100101010101101000000010110101001101100111100011100000000101010111001100010111010000000011110110010100010000000111000100000101011101111000000100110101010110110"


    idx = 0
    for i in range(len(s1)): 
        if('A' <= s1[i] and s1[i] <= 'Z'):
            mp["BC"] = ans1[idx: idx + 6]
            idx += 6
        

        if ' ' == s1[i]: 
            mp["space"] = ans1[idx: idx + 6]
            idx += 6
        else:
            mp[s1[i].lower()] = ans1[idx: idx + 6]
            idx += 6
            
            
    # print(mp)

    ans = ""

    s1 = str
    for i in range(len(s1)): 
	    if('A' <= s1[i] and s1[i] <= 'Z'):
	        ans += mp["BC"]
	    if ' ' == s1[i]: 
	        ans += mp["space"]
	    else:
	        ans += mp[s1[i].lower()]
    	
    return ans




print(solution("code") == "100100101010100110100010")