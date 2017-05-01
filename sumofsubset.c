#include <stdio.h>
#include <stdlib.h>

int n, w[20], d, count, a[10];

void subset (int sum, int index, int rem_sum) {
	int i;
	a[index]=1;
	if (sum + w[index]==d) {//note
		count++;
		printf("\nSolution %d: ", count);
		for (i=0; i<=index; i++) {//i<=index as index also starts from 0
			if (a[i]==1) {
				printf("%d ", w[i]);
			}
		}
	}
	else if (sum + w[index] + w[index+1]<=d) {//note
		subset(sum+w[index], index+1, rem_sum-w[index]);//rem_sum-w[index]
	}
	if (sum + rem_sum - w[index]>=d && sum + w[index+1]<=d) {//note
		a[index]=0;
		subset(sum, index+1, rem_sum-w[index]);//rem_sum-w[index]
	}
}

int main () {
	int i, sum;
	printf("Enter the number of elements in the set: ");
	scanf("%d", &n);
	printf("Enter the elements of the set: ");
	for (i=0; i<n; i++) {
		scanf("%d", &w[i]);
	}
	printf("Enter the value of d: ");
	scanf("%d", &d);
	for (i=0; i<n; i++) {
		sum+=w[i];
	}
	if (sum<d) //note
		printf("No solution");
	else {
		count=0;
		subset(0, 0, sum);//note
	}
}