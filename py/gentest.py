import random
totalPoints = 1000
maxX = 300
for i in range(1, totalPoints):
    x1 = int(random.randint(1, maxX))
    x2 = x1
    if(random.randint(1, 100) < 80):
        x1 = -x1
    if(random.randint(1, 100) < 50):
        x2 = -x2

    print "%d %d" % (x1, x2)


