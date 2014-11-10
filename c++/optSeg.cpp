//sg
#include<iostream>
using namespace std;
int partitionCache[1000][10];
int bestPartition(int partitionIndex, int clusterNumber) {
    int maxScore = 0;
    for(int i = 0; i < partitionIndex; i++) {
        int temp = bestPartition(i, clusterNumber - 1) + sumScore(i + 1, partitionIndex);
        if(temp > maxScore) {
            maxScore = temp;
            maxI = i;
        }
    }
    std :: cout << maxI << endl;
}
int sumScore(int start, int end) {
    end
}
int main()
{
    int arr[] = {3, 1, 5, 6, 4, 7};
