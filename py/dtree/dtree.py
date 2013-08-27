#sg


def is_number(s):
    try:
        float(s)
        return True
    except ValueError:
        return False

def init():
    
    f = open("data.csv", "r")
    numAttr = len(f.readline().split(","))
    f.close()
    attrList = [[] for i in range(numAttr)] #list of attributes
    
    f = open("data.csv", "r")
    
    
    for line in f:
        attrvals = line.split(",")
        for i in range(numAttr):
            attrList[i].append(attrvals[i])
    
    y = attrList[len(attrList) - 1]



def entropyIfSplitDiscrete(attribute, y):
   
    count0 = {}
    count1 = {}

    #count the number of attributes
    for values in attribute:
        count[values]++

    numVals = len(count.keys())

    


    
    





