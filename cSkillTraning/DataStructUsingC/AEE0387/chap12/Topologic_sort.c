/* File name: Topologic_sort.c */

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#define MAX_V 100  /*�̤j�`�I��*/
#define TRUE 1
#define FALSE 0

/*�w�q��Ƶ��c*/
typedef struct node_tag {
	int vertex;
	struct node_tag *link;
} Node;

Node *adjlist[MAX_V+1];  /*�ŧi�۾F��C*/
int visited[MAX_V+1];  /*�O�����I�O�_�w���X*/
int Top_order[MAX_V+1];
int N;
int place;
void build_adjlist();
void show_adjlist();
void topological();
void top_sort(int);
Node *searchlast(Node *);

int main()
{
	int i;
	
	build_adjlist(); /*�H�۾F��C��ܹϧ�*/
	show_adjlist();  /*��ܦ�C�����*/
	topological();     /*�ϧΤ��ܦV�u���j�M�A�H���I1���ҩl���I*/
	puts("\n------Toplogical order sort------");
	for ( i = 0; i < N; i++ )
		printf("V%d ", Top_order[i]);
	getch();
	system("PAUSE");
	return 0;
}

void build_adjlist()
{
	FILE *fptr;
	Node *node, *lastnode;
	int vi, vj;
	fptr = fopen("top_sort.dat", "r");
	if ( fptr == NULL )	{
		perror("top_sort.dat");
		exit(0);
	}
/*Ū���`�I�`��*/
	fscanf(fptr, "%d", &N);
	for ( vi = 1; vi <= N; vi++){
		/*�]�w�}�C�ΦU��C�ҩl��*/
		adjlist[vi] = (Node *)malloc(sizeof(Node));
		adjlist[vi]->vertex = vi;
		adjlist[vi]->link = NULL;
	}
/*Ū���`�I���*/
	while( fscanf(fptr, "%d %d", &vi, &vj) != EOF)	{
		node = (Node *)malloc(sizeof(Node));
		node->vertex = vj;
		node->link = NULL;
		if ( adjlist[vi]->link == NULL)
			adjlist[vi]->link = node;
		else{
			lastnode = searchlast(adjlist[vi]);
			lastnode->link = node;
		}
	}
	fclose(fptr);
}

/*��ܦU�۾F��C�����*/
void show_adjlist()
{
	int v;
	Node *ptr;
	puts("Head    adjacency nodes");
	puts("------------------------------");
	for (v = 1; v <= N; v++){
		printf("V%d ", adjlist[v]->vertex);
		ptr = adjlist[v]->link;
		while ( ptr != NULL ){
			printf("--> V%d ", ptr->vertex);
			ptr = ptr->link;
		}
		printf("\n");
	}
}

/*�ϧΤ��ܦV�u���j�M*/
void topological()
{
	int v;
	for ( v = 1;v <= N; v++)
		visited[v] = FALSE;
	place = N;
	for ( v = 1; v <= N; v++ )
		if ( !visited[v] )
			top_sort(v);
}

void top_sort(int k)
{
	Node *ptr;
	int w;

	visited[k] = TRUE;          /*�]�wv���I���w���X�L*/
	ptr = adjlist[k]->link;     /*���Xv�۾F���I*/
	while ( ptr != NULL ){
		w = ptr->vertex; /* w ��v���ߧY���~�� */ 
		if ( !visited[w] )
			top_sort(w);
		ptr = ptr->link;
	}
	Top_order[--place] = k;
}

/*�j�M��C�̫�`�I���*/
Node *searchlast( Node *linklist )
{
	Node *ptr;
	
	ptr = linklist;
	while ( ptr->link != NULL ) ptr = ptr->link;
	return ptr;
}
