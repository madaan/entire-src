#sg
def maxValSeq(a):
    m = [0] * len(a)
    m[0] = 0
    start = 0
    startO = 0
    endO = 0
    sumP = 0
    for i in range(0, len(a)):
        if(a[i] + m[i] >= m[i]):
            m[i + 1] = a[i] + m[i]
        else:
            if(m[i] > sumP):
                startO = start
                endO = i - 1
                sumP = m[i]
            start = i + 1
            m[i] = 0

    print startO, endO


if __name__ == '__main__':
    
    a = [2, 1, 3, 4, 5, -6, 7, 1, -8]
    maxValSeq(a)
