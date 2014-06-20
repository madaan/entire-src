//sg
#include<iostream>
#include<map>
#include<string>
#include<string.h>
#include<stdlib.h>
#include<stdio.h>
#define MAXL 105
#define INF 1000000000
#define UNDEF -1
using namespace std;
typedef long long ll;
int adj[MAXL][MAXL];
int dist[MAXL][MAXL];

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
    int i = 0;
    while(distanceString[i] == '<' || distanceString[i] == '-') {
        i++;
    }
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
        adj[A][B] = distValue;
    }
    if(toA) {
        adj[B][A] = distValue;
    }
}

void floydWarshall(int n) {
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            for(int k = 0; k < n; k++) {
                if(adj[i][j] > adj[i][k] + adj[k][j]) {
                    adj[i][j] = adj[i][k] + adj[k][j];
                }
            }
        }
    }
}

int main() {
    int n, c, r;
   string joblist[1100];
    while(true) {
        map<string, int> nodeMap;
        memset(adj, INF, sizeof(adj[0][0]) * MAXL * MAXL);
        scanf("%d%d%d", &n, &c, &r);
        for(int i  = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                adj[i][j] = INF;
            }
        }
        if(n == 0) {
            return 0;
        }
        string garage;
        cin >> garage; 
        
        for(int i = 0; i < c; i++) { //read the jobs
            cin >> joblist[i];
        }

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
        int start = nodeMap[garage];
        int firstJob = nodeMap[joblist[0]];
        totalDist += adj[start][firstJob];
        int prevJob = firstJob;
        int nextJob = 0;
        for(int i = 1; i <= c - 1; i++) {
            nextJob =  nodeMap[joblist[i]];
            totalDist += adj[prevJob][nextJob];
            prevJob = nextJob;
        }
        totalDist += adj[prevJob][start];
        printf("%lld\n", totalDist);
    }
    return 0;
}
    





