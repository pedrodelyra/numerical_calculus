#include <stdio.h>
#include <math.h>

#define MAX_K 250	// Número máximo de iterações a serem executadas
#define EPS 1e-15	// Precisão

int main(void) {
	int n;
	scanf("%d", &n);

	double A[n + 1][n + 1], b[n + 1], x[n + 1][MAX_K];
	for(int i = 1; i <= n; ++i) {
		for(int j = 1; j <= n; ++j) {
			scanf("%lf", &A[i][j]);
		}
		scanf("%lf", &b[i]);
	}

	// Atribuição de valores iniciais arbitrários para o vetor solução
	for(int i = 1; i <= n; ++i) x[i][0] = 1;	

	int k;
	for(k = 1; k < MAX_K; ++k) {
		double max_error = 0;
		for(int i = 1; i <= n; ++i) {
			double current_row_sum = 0;
			for(int j = 1; j <= n; ++j) {
				if(i == j) continue;

				current_row_sum += A[i][j] * x[j][k - 1];
			}

			x[i][k] = (b[i] - current_row_sum) / A[i][i];
			max_error = fmax(max_error, fabs(x[i][k] - x[i][k - 1]) / fabs(x[i][k - 1]));
		}

		if(max_error < EPS) break;
	}

	for(int i = 1; i <= n; ++i) printf("x%d = %.20lf\n", i, x[i][k]);

	return 0;
}
