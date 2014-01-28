#sg
#Viterbi Top k decoder
from math import log

MAX_LEN = 1000
MAX = 1000
states = [0, 1]
state_name = ['H ', 'L ']
emission = [{'a' : 0.2, 'c' : 0.3, 'g' : 0.3, 't' : 0.2}, {'a' : 0.3, 'c' :  0.2, 'g' :  0.2, 't' : 0.3}]
prob  = [[0.5, 0.5], [0.4, 0.6]]
a = [[MAX] * MAX_LEN for i in range(0, MAX_LEN)]
picked = [[0] * MAX_LEN for i in range(0, MAX_LEN)]

def viterbi(observation):
    BASE = 2
    a[0][0] = 1 + -log(emission[0][observation[0]], BASE)
    a[0][1] = 1 + -log(emission[1][observation[0]], BASE)

    for i in range(1, len(observation)):
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
    for i in range(len(observation) - 1, 0, -1):
        print i
        hook = picked[i][hook]
        state_string.append(state_name[hook])
    state_string.reverse()
    print ''.join(state_string)


num_states = 2

def viterbi_topk(observation, k):
    BASE = 2
    a = [[[0 for col in range (0, k)] for row in range(0, num_states)] for blades in range(0, len(observation))]
    picked = [[[0 for col in range (0, k)] for row in range(0, num_states)] for blades in range(0, len(observation))]
    
    for i in range(0, k):
        a[0][0][i] = 1 + -log(emission[0][observation[0]], BASE)
        a[0][1][i] = 1 + -log(emission[1][observation[0]], BASE)

    temp = [] #records all the |S| values for a node
    for i in range(1, len(observation)):
        for s_curr in states:
            for s_prev in states:
                for kk in range(0, k):
                    temp.append((a[i - 1][s_prev][kk] + (-log(prob[s_prev][s_curr], BASE)), s_prev))
            #now temp has all the possible updates, just get top 2
            if i < k:
                temp = list(set(temp))
            if len(temp) < k :
                difference = k - len(temp)
                for d in range(0, difference):
                    temp.append(temp[len(temp) - 1])
            #print i, temp
            temp = sorted(temp, key = lambda x: x[0])
            a[i][s_curr] = [tt[0] for tt in temp[0:k]]
            emission_cost = -log(emission[s_curr][observation[i]], BASE)
            for j in range(0, k):
                a[i][s_curr][j] += emission_cost
                picked[i][s_curr][j] = temp[j][1]
            temp = []

            #print 'time : %d state : %s value : %f' % (i, state_name[s_curr], a[i][s_curr])


    final = []
    last_stack = len(observation) - 1
    #create a ranking for blades at the last
    for st in states:
        for i in range(0, k):
            final.append((a[last_stack][st][i], st, i))
    final = sorted(final, key = lambda x : x[0])
    
    
    print 'Top ', k, 'paths : '
    for rank in range(0, k):
        hook = final[rank][1] #which state to latch to
        sub_hook = final[rank][2] #which element
        state_string = []
        state_string.append(state_name[hook])
        for i in range(len(observation) - 1, 0, -1):
            hook = picked[i][hook][rank]
            state_string.append(state_name[hook])
        state_string.reverse()
        print ''.join(state_string)
    
    '''
    if a[len(observation) - 1][1] < a[len(observation) - 1][0] : 
        hook = 1
    else:
        hook = 0

    state_string = [state_name[hook]]
    for i in range(len(observation) - 1, 0, -1):
        print i
        hook = picked[i][hook]
        state_string.append(state_name[hook])
    state_string.reverse()
    print ''.join(state_string)
    '''




if __name__ == '__main__':
    viterbi_topk('ggcactgaa', 129)
