

s = 'bababababababababa'


s = 'aBCDefabchijaBCD'.lower()

def find_distance_of_all_substring(s,  length):
    
    for  i in range(len(s - length)):
        distances_of_current_substr = []
        substr = s[i:i+length]
        j = s.find(s, i+length)
        while j != -1:
            distances_of_current_substr.append(j-i)



res = find_distance_of_all_substring(s, 4)
print(res)