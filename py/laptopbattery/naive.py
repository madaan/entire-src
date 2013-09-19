#sg
import sys
data = sys.stdin.readlines()
for line in data:
    l = float(line)
    if(l >= 4):
        print "8"
    else:
        print l*2
    #prediction =  thetas[1] * l + thetas[0]
    #print prediction

