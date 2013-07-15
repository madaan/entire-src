//sg
#include <algorithm>
#include <stdio.h>
#include <queue>
typedef long long LL;
typedef std::priority_queue<LL, std::vector<LL>, std::greater<LL> > MinHeap;
typedef std::priority_queue<LL> MaxHeap;
#define NPrev (N - 1)
int main()
{
    MinHeap minH;
    MaxHeap maxH;
    enum OP {ADD = 1, SUB}; 
    int cases, //total cases 
        op, //current operation
        N; // total number of elements now
    LL arg;
    N = 0;
    scanf("%d", &cases);
    while(cases--) {
        scanf("%d", &op);
        if(op == ADD) { //add an element
            scanf("%lld", &arg);
            N++;
            //printf("%d %d\n", N/3, NPrev/3);
            if(N/3 == 0) {
                maxH.push(arg);
                continue;
            }else if(N/3 == 1 && NPrev/3 == 0) { //first time we can have an element in the minHeap
                if(arg > maxH.top()) {
                    minH.push(arg);
                } else {
                    minH.push(maxH.top());
                    maxH.pop();
                    maxH.push(arg);
                }
            }else if(N/3 == NPrev/3) { //someone has to move
                /*printf("Someone needs to move\n");
                printf("Adding : %lld\n", arg);*/
                if(arg > minH.top()) {
                    //printf("Removing : %lld\n", minH.top());
                    maxH.push(minH.top());
                    minH.pop();
                    minH.push(arg);
                } else {
                    maxH.push(arg);
                }

            } else { // N/3 > NPrev / 3, since N has only increased
                    maxH.push(arg);
                    minH.push(maxH.top());
                    maxH.pop();
                }
        
        } else { //time to show
            if(N/3 == 0) {
                printf("No reviews yet\n");
            } else {
                printf("%lld\n", minH.top());
            }
        }
    }
    return 0;
}
