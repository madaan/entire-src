//sg
#include<iostream>
#include<stdio.h>
#include<list>
using namespace std;
int main()
{
    int m, n, temp;
    int  chefSpeciality[1000][2];
    int noOfTeams;
    int chefTool1, chefTool2;
    int  taken[200];
    list<int> * tools, *team;
    int ans[50][100], cases;
    int  NI[50];
#ifdef TEST
    freopen("TEST", "r", stdin);
#endif
    cin >> cases;

    for (int t = 0; t < cases; t++) {
        cin >> m >> n;
        NI[t] = n;
        tools = new list<int>[m];
#ifdef DEBUG
        cout << "NO PROBLEM HERE";
#endif

//first row

        for (int i = 0; i < n; i++) {
            cin >> chefSpeciality[i][0];
            (chefSpeciality[i][0])--;
            tools[chefSpeciality[i][0]].push_back(i);
        }
//second row,also use it to set ans =0
        for (int i = 0; i < n; i++) {
            cin >> chefSpeciality[i][1];
            (chefSpeciality[i][1])--;
            tools[chefSpeciality[i][1]].push_back(i);
            ans[t][i] = 0;
        }
#ifdef DEBUG
        cout << "OK";
#endif
        noOfTeams = tools[0].size();
        for (int i = 1; i < m; i++) {
            if ((tools[i].size()) < noOfTeams) {
                noOfTeams = tools[i].size();
            }
        }
        team = new list<int>[noOfTeams];
//for all teams
        for (int i = 0; i < noOfTeams; i++) {
//for each tool
            for (int j = 0; j < m; j++) {
                taken[j] = 0;
            }
            for (int j = 0; j < m; j++) {
                if (!taken[j]) {
//now try to first pick up a chef
//who specializes in tools not yet picked
                    list<int>::iterator iTor;
                    for (iTor = tools[j].begin(); iTor != tools[j].end(); iTor++) {
                        temp = *iTor;
                        chefTool1 = chefSpeciality[temp][0];
                        chefTool2 = chefSpeciality[temp][1];
                        if ((taken[chefTool1] == 1) || (taken[chefTool2] == 1)) {
                            continue;  //try another chef
                        } else { //ok add chef to the team and mark the tools as taken
//add it to ith team
                            team[i].push_back(temp);
                            ans[t][temp] = i + 1; // team number of chef
//remove it from all teams
                            tools[chefTool1].remove(temp);
                            tools[chefTool2].remove(temp);
                            taken[chefTool1] = 1;
                            taken[chefTool2] = 1;
                            break;
                        }
                    }
                    if (iTor == tools[j].end()) { //you have reached the end but haven't found any tool satisfying the criteria,add any tool
                        temp = tools[j].back();
                        chefTool1 = chefSpeciality[temp][0];
                        chefTool2 = chefSpeciality[temp][1];
//add it to ith team
                        team[i].push_back(temp);
                        ans[t][temp] = i + 1; // team number of chef
//remove it from all teams
                        tools[chefTool1].remove(temp);
                        tools[chefTool2].remove(temp);
                        taken[chefTool1] = 1;
                        taken[chefTool2] = 1;
                    }
                }
            }
        }
        /* TEST CASE ENDS */
        /*next test case*/
    }
    for (int i = 0; i < cases; i++) {
        for (int j = 0; j < NI[i]; j++) {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
