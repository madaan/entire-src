import math
def cosine_similarity(vec1,vec2):
    sum11, sum12, sum22 = 0, 0, 0
    for i in range(len(vec1)):
        x = vec1[i]; y = vec2[i]
        sum11 += x*x
        sum22 += y*y
        sum12 += x*y
    return sum12/math.sqrt(sum11*sum22)


myWords = {'in' : [0.01, -0.07, 0.09, -0.02], 'and' : [0.2, 0.3, 0.5, 0.6], 'to' : [0.87, 0.98, 0.54, 0.4]}
from collections import defaultdict
res = defaultdict(list)
for word1 in myWords:
    for word2 in myWords:
        if(word1 != word2):
            res[word1].append(cosine_similarity(myWords[word1], myWords[word2]))

for word in res:
    print word, res[word]
