#include <stdio.h>
struct node {
 unsigned dist[20]; // Distance from the source node
 unsigned from[20]; // Predecessor node
} rt[10];
int main() {
 int costmat[20][20];
 int nodes, i, j, k, count = 0;
 printf("\nEnter the number of nodes: ");
 scanf("%d", &nodes);
 // Enter the cost matrix
 printf("\nEnter the cost matrix:\n");
 for (i = 0; i < nodes; i++) {
 for (j = 0; j < nodes; j++) {
 scanf("%d", &costmat[i][j]);
 costmat[i][i] = 0; // Distance to self is zero
 rt[i].dist[j] = costmat[i][j]; // Initialise the distance equal to cost matrix
 rt[i].from[j] = j; // Initialize predecessor
 }
 }
 do {
 count = 0;
 for (i = 0; i < nodes; i++) { // We choose arbitrary vertex k and we calculate the direct distance

 for (j = 0; j < nodes; j++) {
 for (k = 0; k < nodes; k++) {
 if (rt[i].dist[j] > costmat[i][k] + rt[k].dist[j]) {
 // We calculate them in minimum distance
 rt[i].dist[j] = costmat[i][k] + rt[k].dist[j];
 rt[i].from[j] = k;
 count++;
 }
 }
 }
 }
 } while (count != 0);
 for (i = 0; i < nodes; i++) {
 printf("\n\nFor router %d\n", i + 1);
 for (j = 0; j < nodes; j++) {
 printf("\t\nNode %d via %d Distance %d", j + 1, rt[i].from[j] + 1, rt[i].dist[j]);
 }
 }
 printf("\n\n");
 return 0;
}
