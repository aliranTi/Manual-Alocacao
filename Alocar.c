#include <stdio.h>
#include <stdlib.h>

void * alocar(int t);
void * realocar(void * p, int t);
void * alocar_inicializar(int t,int s);


void * alocar(int t) {
    void * p = malloc(t);
    if (p == NULL) {
        printf("Erro: Memoria insuficiente\n");
        exit(1);
    }
    return p;
}

void * realocar(void * p, int t) {
    p = realloc(p, t);
    if (p == NULL) {
        printf("Erro: Memoria insuficiente\n");
        exit(1);
    }
    return p;
}

void * alocar_inicializar(int t,int s) {
    void * p = calloc(s,t);
    if (p == NULL) {
        printf("Erro: Memoria insuficiente\n");
        exit(1);
    }
    return p;
}



void ** alocar_matriz(int l, int c, int t) {
    void ** p = alocar(l * sizeof(void *));
    for (int i = 0; i < l; i++) {
        p[i] = alocar(c * t);
    }
    return p;
}

int main() {
    int *p;
    p = alocar(sizeof(int));
    *p = 1000;
    printf("%d\n", *p);
    p = realocar(p, 2 * sizeof(int));
    p[1] = 2000;
    int *q = alocar_inicializar(2, sizeof(int));
    *q = 3000;
    q[1] = 4000;

    printf("%d\n", p[0]);
    printf("%d\n", q[0]);
    printf("%d\n", p[1]);
    printf("%d\n", q[1]);
    free(p);
    free(q);
    return 0;
}