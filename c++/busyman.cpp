//sg
#include <stdio.h>
#include <algorithm>
#include <vector>
struct activity
{
    public:
    int start, end;
    activity(int s, int e) {
        start = s;
        end = e;
    }
};

bool comp (activity a1, activity a2) {
    return a1.end < a2.end;
}

int main()
{
    int t, num_acts, start, end;
    std::vector<activity> actlist;
    scanf("%d", &t);
    while(t--) {
        scanf("%d", &num_acts);
        for(int i = 0; i < num_acts; i++) {
            scanf("%d%d", &start, &end);
            actlist.push_back(activity(start, end));
        }
        std::sort(actlist.begin(), actlist.end(), comp);
        int max_taken = 1;
        activity last_taken = *(actlist.begin());
        for(std::vector<activity>::iterator it = actlist.begin() + 1; it != actlist.end(); ++it) {
            //printf("%d %d\n", (*it).start, (*it).end);
            if((*it).start >= last_taken.end) {
                max_taken++;
                last_taken = *it;
            }
        }
        printf("%d\n", max_taken);
        actlist.clear();

    }

    return 0;
}
