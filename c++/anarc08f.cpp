//sg
#include<iostream>
#include<map>
#include<string>
#include<string.h>
#include<stdlib.h>
#include<stdio.h>
#define MAXL 205
#define INF 1000000000
#define UNDEF -1
using namespace std;
typedef long long ll;
int adj[MAXL][MAXL];
void readDist(string distanceString, string from, string to, map<string, int>& vertextMap) {
    bool toA = false, toB = false;
    if(distanceString[0] == '<') { //toA
        toA = true;
    }
    int l = distanceString.length();
    if(distanceString[l - 1] == '>') { //toB
        toB = true;
    }
    //now extract just the distance
    int i = 2;
    //now extract the distance
    char dist[100];
    int j = 0;
    while(distanceString[i] != '-') {
        dist[j++] = distanceString[i++];
    }
    dist[j] = '\0';
    int distValue = atoi(dist);
    int A = vertextMap[from];
    int B = vertextMap[to];
    if(toB) {
        if(distValue < adj[A][B])
            adj[A][B] = distValue;
    }
    if(toA) {
        if(distValue < adj[B][A])
            adj[B][A] = distValue;
    }
}
void floydWarshall(int n) {
    for(int k = 0; k < n; k++) {
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                adj[i][j] = min(adj[i][j], adj[i][k] + adj[k][j]);
            }
        }
    }
}
int main() {
    int n, c, r;
    string joblist[1100];
    int testCaseNumber = 1;
    while(true) {
        map<string, int> nodeMap;
        memset(adj, INF, sizeof(adj[0][0]) * MAXL * MAXL);
        scanf("%d%d%d", &n, &c, &r);
        for(int i  = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                adj[i][j] = INF;
            }
        }
        for(int i  = 0; i < n; i++) {
            adj[i][i] = 0;
        }

        if(n == 0) {
            return 0;
        }


        for(int i = 0; i <= c; i++) { //read the jobs
            cin >> joblist[i];
        }
        string garage = joblist[0];
        joblist[c + 1] = garage;
        //now read the edges
        string from, to, distanceString;
        int locationNumber = 0;
        for(int i = 1; i <= r; i++) {
            cin >> from;
            if(nodeMap.find(from) == nodeMap.end()) {
                nodeMap[from] = locationNumber++;
            }

            cin >> distanceString;
            cin >> to;
            if(nodeMap.find(to) == nodeMap.end()) {
                nodeMap[to] = locationNumber++;
            }
            bool twoWay = false;
            int fromId, toId;
            readDist(distanceString, from, to, nodeMap);
            //printf("%s (%d) to %s (%d)\n", from.c_str(), nodeMap[from], to.c_str(), nodeMap[to]);
        }
        if(c == 0) {
            printf("%d. 0\n", testCaseNumber++);
            continue;
        }
        floydWarshall(n);
        /*
         for(int i = 0; i < n; i++) {
             for(int j = 0; j < n; j++) {
                 printf("%d ", adj[i][j]);
             }
             printf("\n");
         }
         */
        //now read the joblist to get the distance
        ll totalDist = 0;
        int nextJob, prevJob;
        int gn = nodeMap[garage];
        for(int i = 0; i <= c; i++) {
            prevJob =  nodeMap[joblist[i]];
            nextJob =  nodeMap[joblist[i + 1]];
            //printf("%d -> %d = %d\n", prevJob, nextJob, adj[prevJob][nextJob]);
            totalDist += (adj[prevJob][gn] + adj[gn][nextJob]);
        }
        printf("%d. %lld\n", testCaseNumber++, totalDist);
    }
    return 0;
}

