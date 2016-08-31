#include <stdio.h>
#include <math.h>

#define INF 1e4		// Infinito 
#define EPS 1e-10	// Epsilon (grau de precisão do cálculo) 
#define e   0.2		// Excentricidade orbital
#define M   0.5		// Anomalia média

// Equação de Kepler 
double kepler(double E) {
	return E - e * sin(E) - M;
}

// Método da bissecção. Dado um intervalo [a, b], verifica-se se o ponto médio
// 'c' deste intervalo é raíz da equação de kepler, ou seja, satisfaz a condição
// de que f(c) é aproximadamente zero (|f(c)| < EPS). Caso o ponto médio não seja
// raíz, verifica-se qual dos dois subintervalos resultantes da bissecção contém
// a raíz (f(a)f(c) < 0 ou f(c)f(b) < 0) e inicia-se o processo novamente em busca
// da raíz sobre o novo intervalo.
double bisection(double a, double b) {
	double c = (a + b) / 2;
	if(fabs(kepler(c)) < EPS) {
		return c;
	}

	if(kepler(a) * kepler(c) < 0) {
		return bisection(a, c);
	} else {
		return bisection(c, b);
	} 
}

int main(void) {
	printf("Kepler's equation root: x = %.10lf\n", bisection(-INF, INF));
	return 0;
}
