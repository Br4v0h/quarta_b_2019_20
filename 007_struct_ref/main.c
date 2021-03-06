/* Codice 007 */

/* Un punto del piano cartesiano */

/* Le struct (con passaggio per riferimento) */

/* Compilazione, link ed esecuzione:

$ gcc -c main.c -o main.o
$ gcc main.o -o main
$ ./main

*/

#include <stdio.h>

/* definizione di un nuovo tipo:
 *
 * un punto del piano cartesiano
 */
struct punto {
    double x;
    double y;
};

/* creazione di un sinonimo per 'struct punto' */
typedef struct punto Punto;

/* prototipi di funzioni che lavorano con variabili di tipo Punto */
void punto_print(Punto *P);
void punto_setX(Punto *P, double newX);
void punto_setY(Punto *P, double newY);
void punto_move(Punto *P, double dx, double dy);

int main()
{
    /* Creazione di un punto */
    Punto P = { 0, 0 };
    /* e' equivalente ad assegnare singolarmente:
     * P.x = 0;
     * P.y = 0;
     */
    
    /* stampa le coordinate del punto */
    punto_print(&P);

    /* modifica le coordinate del punto e ristampa */
    punto_setX(&P, 3.2);
    punto_setY(&P, 2.7);
    punto_print(&P);

    /* sposta il punto di un'unita' sull'asse x e due sull'asse y */
    punto_move(&P, 1., 2.);
    punto_print(&P);

    return 0;
}

void punto_print(Punto *P)
{
    printf("(%.1f, %.1f)\n", P->x, P->y);
}

void punto_setX(Punto *P, double newX)
{
    P->x = newX;
}

void punto_setY(Punto *P, double newY)
{
    P->y = newY;
}

void punto_move(Punto *P, double dx, double dy)
{
    P->x += dx;
    P->y += dy;
}