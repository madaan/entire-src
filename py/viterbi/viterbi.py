#sg
from math import log

MAX_LEN = 1000
MAX = 1000
states = [0, 1]
state_name = ['h', 'l']
emission = [{'a' : 0.2, 'c' : 0.3, 'g' : 0.3, 't' : 0.2}, {'a' : 0.3, 'c' :  0.2, 'g' :  0.2, 't' : 0.3}]
prob  = [[0.5, 0.5], [0.4, 0.6]]
a = [[MAX] * MAX_LEN for i in range(0, MAX_LEN)]
picked = [[0] * MAX_LEN for i in range(0, MAX_LEN)]

def viterbi(observation):
    BASE = 2
    a[1][0] = 2.73
    a[1][1] = 3.32
    for i in range(2, len(observation)):
        for k_curr in states:
            for k_prev in states:
                possible_update = a[i - 1][k_prev] + (-log(prob[k_prev][k_curr], BASE))
                if possible_update <= a[i][k_curr] :
                    picked[i][k_curr] = k_prev
                    a[i][k_curr] = possible_update
            a[i][k_curr] += ( -log(emission[k_curr][observation[i]], BASE))
            print 'time : %d state : %s value : %f' % (i, state_name[k_curr], a[i][k_curr])

    if a[len(observation) - 1][1] < a[len(observation) - 1][0] : 
        hook = 1
    else:
        hook = 0

    state_string = [state_name[hook]]
    for i in range(len(observation) - 2, 0, -1):
        print i
        hook = picked[i][hook]
        state_string.append(state_name[hook])
    state_string.reverse()
    print ''.join(state_string)



if __name__ == '__main__':
    viterbi(' ggcactgaa')
