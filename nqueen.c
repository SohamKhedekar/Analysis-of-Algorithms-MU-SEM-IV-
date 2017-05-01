#include <stdio.h>
#include <stdlib.h>

int board[20], count=0;//each index is the row number and value is column number

int place (int row, int column) {
	int i;
	for (i=1; i<row; i++) {
		if (board[i]==column)
			return 0;
		else if (abs(board[i]-column)==abs(i-row))
			return 0;
	}
	return 1;
}

void printBoard (int n) {
	int i, j;
	count++;
	printf("The solution %d: \n", count);
	for (i=1; i<=n; i++) {
		printf("\t%d", i);
	}
	for (i=1; i<=n; i++) {
		printf("\n\n%d", i);
		for (j=1; j<=n; j++) {
			if (board[i]==j)
				printf("\tQ");
			else
				printf("\t-");
		}
	}
	printf("\n");
	/**
	These are used in non-gcc compilers. Solutions can be printed one by one.
	printf("\n\nPress any key to continue..");
	getch();
	**/
}

void queen (int row, int n) {//pass row and n
	int column;
	for (column=1; column<=n; column++) {
		if (place(row, column)) {//pass row and column to place
			board[row]=column;
			if (row==n) {
				printf("\n%d\n", row);
				printBoard(n);
			}	
			else //falls inside first if
				queen(row+1, n);
		}	
	}
}

int main () {
	int n;
	printf("Enter the number of queen's: ");
	scanf("%d", &n);
	queen(1, n);
	return 0;
}