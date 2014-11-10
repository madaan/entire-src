//sg
#include <stdio.h>
#include <ctype.h>
#include <cstring>
#include <string>
#include <vector>
#include <stdlib.h>
#include <algorithm>
using namespace std;
#define debug
int main(int ac, char *argv[])
{
//   char str[] = "C0D3C43F";
    // char str[] = "06454";
    char str[1200];
    while(scanf("%s", str) != EOF) {
        int record[2000][3];
        int rc = 0, temp;
        int i = 0, ti, tti, j;
        i = ti = tti = 0;
        while(str[i]) {
            if(isalpha(str[i])) { //find distance to atmost 1 more char
                record[rc][0] = i;
                ti = i  + 1;
                while(str[ti] && isdigit(str[ti])) {
                    ti++;
                }
                //ti is now a non digit
                record[rc][1] = ti - 1;
                record[rc][2] = record[rc][1] - record[rc][0] + 1;
                rc++;
                i = i + 1; //now check from the digit
            } else if(isdigit(str[i])) { //starting from here, find distance such that there is atmost 1 char in bw
                ti = i + 1;
                record[rc][0] = i;
                //read all the digits
                while(str[ti] && isdigit(str[ti])) {
                    ti++;
                }
                //now we have something which is not a char or the string has terminated
                //check for term
                if(!str[ti]) {
                    record[rc][1] = ti - 1;
                    record[rc][2] = record[rc][1] - record[rc][0] + 1;
                    rc++;
                    break;
                }
                tti = ti; //the char in between
                //skipping the char
                ti++;
                while(str[i] && isdigit(str[ti])) {
                    ti++;
                }
                //ti now points to a non digit
                if(ti == tti + 1) {//no digit was found, our run ends at the non char
                    record[rc][1] = tti;
                    rc++;
                } else {
                    record[rc][1] = ti - 1;
                }
                record[rc][2] = record[rc][1] - record[rc][0] + 1;
                i = tti;
                rc++;
            }
        }

        vector<int> numbers;
        string p(str), ts;
        char *tp = NULL;
        i = 0;

        while(i < rc) {
            ts = p.substr(record[i][0], record[i][2]);
            if(ts.size() == 0) {
                i++;
                continue;
            }
#ifdef debu

            printf("%4d %4d %4d %s\n", record[i][0], record[i][1], record[i][2], ts.c_str());
#endif
            j = 0;
            tp = new char[ts.size() + 1];
            if(tp == NULL) {
                return 0;
            }
            std::copy(ts.begin(), ts.end(), tp);
            tp[ts.size()] = '\0'; // don't forget the terminating 0
            while(tp[j] && !isalpha(tp[j])) {
                j++;
            }
            if(tp[j] && isalpha(tp[j])) {
                tp[j] = '9';
            }
            numbers.push_back(atoi(tp));
            i++;
            delete tp;
        }
        printf("%d\n", *max_element(numbers.begin(), numbers.end()));
        numbers.clear();
    }
    return 0;
}

