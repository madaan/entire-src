#sg
cache = [-1] * 50
denominations = [1, 5, 10, 4] 
for d in denominations:
    cache[d] = 1
def makeChange(number):
    
    print 'entered makeChange(%d)' % (number)
    temp = 0
    if(number <= 0):
        return 0
    if(cache[number] != -1):
        return cache[number]
    if(cache[number - denominations[0]] != -1):
        temp = cache[number - denominations[0]] + 1
    else:
        cache[number - denominations[0]] = makeChange(number - denominations[0])
        temp = cache[number  - denominations[0]] + 1

    for coin in denominations[1:]:
        
        if(number - coin < 0):
            break
        if(cache[number - coin] != -1):
            res = cache[number - coin] + 1
        else:
            res = makeChange(number - coin) + 1
            cache[number - coin] = res - 1

        if(res < temp):
            temp = res
    
    print 'makeChange(%d) = %d' % ( number, temp)
    return temp
import sys

if __name__ == '__main__':
    print makeChange(int(sys.argv[1]))
    print cache
