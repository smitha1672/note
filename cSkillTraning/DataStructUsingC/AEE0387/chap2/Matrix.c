/*	File name: Matrix.c
	Version 4.0, June, 2017
	Description : 矩陣相乘實作
	將兩矩陣行列相乘之和放入第三個矩陣 */

#include <stdio.h>
#define N 5  /*N x N 矩陣*/
void outputMatrix(int [][N]); /*顯示矩陣內容函數*/

int main()
{
	int A[N][N] = {
		1, 2, 3, 4, 5, 
		1, 2, 3, 4, 5, 
		1, 2, 3, 4, 5, 
		1, 2, 3, 4, 5, 
		1, 2, 3, 4, 5
	};
	int B[N][N] = {
		5, 4, 3, 2, 1, 
		5, 4, 3, 2, 1, 
		5, 4, 3, 2, 1, 
		5, 4, 3, 2, 1, 
		5, 4, 3, 2, 1
	};
	int C[N][N], i, j, k, sum;

	/*	將A矩陣每一列元素與B矩陣每一列元素
		相乘之和放入C矩陣之中 */
	for ( i = 0; i < N; i++ )
		for ( j = 0; j < N; j++ ){
			sum = 0;
			for ( k = 0; k < N; k++ )
				sum = sum + A[i][k] * B[k][j];
			C[i][j] = sum;
		}

	/*列出三矩陣內容*/
	printf("\nContent of Matrix A :\n\n");
	outputMatrix(A);
	printf("\nContent of Matrix B :\n\n");
	outputMatrix(B);
	printf("\nContent of Matrix C :\n\n");
	outputMatrix(C);
	printf("\n");
	return 0;
}

void outputMatrix(int m[N][N] )
{
	int i, j;

	for ( i = 0; i < N; i++ ){
		for ( j = 0; j < N; j++ )
			printf("%5d", m[i][j]);
		printf("\n");
	}
}