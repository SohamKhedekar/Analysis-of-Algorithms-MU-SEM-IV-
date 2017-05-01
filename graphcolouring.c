#include <stdio.h>
#include <stdlib.h>

int g[10][10], colours[10], n, edges, m;

void col_val (int k) {
	int a, b, j;
	while(1){//note
		a=colours[k]+1;
		b=m+1;
		colours[k]=a%b;//colour has been assigned. now check for adjacent colours
		for(j=1; j<=n; j++){//j<=n as we have to check for n nodes
			if (g[k][j] && colours[k]==colours[j])
				break;//so it will now go to next itertion, hence another colour
		}
		if (j==n+1)
			return;//new colour has been chosen as no other node had this
	}
}

void grcol (int k) {
	col_val(k);
	if(colours[k]==0)//colours done
		return;
	if(k==n)//nodes done
		return;
	else
		grcol(k+1);
}

void display () {
	int i;
	printf("Colour of each vertice is: \n");
	for(i=1; i<=n; i++) {
		printf("V%d: %d\n", i, colours[i]);
	}
}

int main () {
	int i, v1, v2, j;
	for (i=0; i<10; i++) {
		for (j=0; j<10; j++) {
			g[i][j]=0;
			colours[i]=0;
		}
	}
	printf("Enter the number of nodes: ");
	scanf("%d", &n);
	printf("Enter the number of edges: ");
	scanf("%d", &edges);
	printf("Enter the number of colours: ");
	scanf("%d", &m);
	printf("Enter the edges: ");
	for (i=0; i<edges; i++) {
		scanf("%d%d", &v1, &v2);
		g[v1][v2]=g[v2][v1]=1; 
	}
	grcol(1);
	display();
	return 0;
}