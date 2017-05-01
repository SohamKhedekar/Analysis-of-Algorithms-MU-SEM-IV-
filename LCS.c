#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void displcs (char d[20][20], char a[], int i, int j) {//take m, n as i, j respectively
	if (i==0 || j==0)
		return;
	else if (d[i][j]=='/') {
		displcs(d, a, i-1, j-1);
		printf("%c", a[i-1]);
	}
	else if (d[i][j]=='<') 
		displcs(d, a, i-1, j);
	else 
		displcs(d, a, i, j-1);
}

void computelcs (char a[], char b[]) {
	int i, m, n, c[20][20], j;
	char d[20][20];
	m=strlen(a);
	n=strlen(b);
	for (i=0; i<=m; i++)//i<=m
		c[i][0]=0;
	for (i=0; i<=n; i++)//i<=n
		c[0][i]=0;
	for (i=1; i<=m; i++) {//note i=1, i<=m
		for (j=1; j<=n; j++) {//note j=1, j<=n
			if (a[i-1]==b[j-1]) {//note i-1, j-1
				c[i][j]=c[i-1][j-1]+1;
				d[i][j]='/';
			}
			else if (c[i-1][j]>=c[i][j-1]) {
				c[i][j]=c[i-1][j];
				d[i][j]='<';
			}
			else {
				c[i][j]=c[i][j-1];
				d[i][j]='^';
			}
		}
	}
	for (i=0; i<=m; i++) {//i<=m
		for (j=0; j<=n; j++) {//j<=n
			printf("%d ", c[i][j]);
		}
		printf("\n");
	}
	printf("The longest common subsequence is: ");
	displcs(d, a, m, n);//pass m and n
	printf("\n");
}

int main () {
	char a[20], b[20];
	printf("Enter the first string: ");
	scanf("%s", a);
	printf("Enter the second string: ");
	scanf("%s", b);
	printf("\n\n");
	computelcs(a, b);
	return 0;
}