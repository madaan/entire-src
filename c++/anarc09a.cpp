//sg
#include <stack>
#include <string.h>
#include <stdio.h>
#include <iostream>
#include <string>

int process(char *str)
{
    std::stack<char> st;
    std::string unbal;
    int unbalanced = 0, i;
    int l = strlen(str);
    for(i = 0; str[i]; i++) {
        if(str[i] == '{') { //push this
            st.push(str[i]);
        } else { //str[i] == '}'
            if(st.empty() || st.top() == '}') { //push this
                unbalanced++;
                st.push('{');
                }
            else {
    //printf("%s, %d", unbal.c_str(), ops);
                st.pop();
            }
        }
    }
    
    return (st.size()  /2 ) + unbalanced;
}




int main()
{
    char ip[2100];
    int case_number = 1;
    while(1) {
        scanf("%s", ip);
        if(ip[0] == '-') {
            break;
        }
        printf("%d. %d\n", case_number++, process(ip));
        //process(ip);
    }
    return 0;
}
