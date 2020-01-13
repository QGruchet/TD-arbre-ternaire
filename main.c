#include <stdlib.h>
#include <stdio.h>
#include "arbre_ter.h"

int main(){

	ATR a = creer_feuille(10,16);
	inserer_val(a, 9);
	inserer_val(a, 13);
	inserer_val(a, 23);
	afficher_arbre(a);
	printf("La hauteur de l'arbre ternaire est : %d\n", hauteur(a));
	printf("La valeur max est : %d\n", valeur_max(a));
	printf("Il y a %d valeurs dans l'arbre\n", nombre_valeur(a));


	return 0;
}