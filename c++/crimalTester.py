from random import randint
ncases = randint(1, 100)
seed(None)
print ncases
for i in range(1, ncases):
    nnums = randint(1, 100) 
    print nnums
    for j in range(1, nnums):
        print randint(1, 10000)

