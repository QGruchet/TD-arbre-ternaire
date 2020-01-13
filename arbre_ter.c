#include "arbre_ter.h"
#include <stdlib.h>
#include <stdio.h>

#define max(a, b)  ((a) < (b) ? (b) : (a)) 

int max3(int a, int b, int c)
{
	return max(max(a,b),c);
}

int max4(int a, int b, int c, int d)
{
	return max(max3(a, b, c), d);
}

ATR creer_arbre_vide()
{
	return NULL;
}


int est_vide(ATR a)
{
	return a == NULL;
}

ATR creer_feuille(int valeur1, int valeur2)
{
	ATR a = malloc(sizeof(ternaire));
	a->val1 = valeur1;
	a->val2 = valeur2;
	a->fg = NULL;
	a->fm = NULL;
	a->fd = NULL;
	return a;
}

void afficher_arbre(ATR a)
{
	if(!est_vide(a))
	{
		afficher_arbre(a->fg);
		printf("%d\n", a->val1);
		afficher_arbre(a->fm);
		printf("%d\n", a->val2);
		afficher_arbre(a->fd);
	}
}

ATR inserer_val(ATR a, int valeur)
{
	if(est_vide(a))
	{
		return creer_feuille(valeur, 0);
	}
	if(valeur <= a->val1)
	{
		a->fg = inserer_val(a->fg, valeur);
	}
	if(valeur > a->val2)
	{
		a->fd = inserer_val(a->fd, valeur);
	}
	if(valeur < a->val2 && valeur > a->val1)
	{
		a->fm = inserer_val(a->fm, valeur);
	}
	return a;
}

int hauteur(ATR a)
{
	if(est_vide(a))
	{
		return -1;
	}
	if(est_vide(a->fg) && est_vide(a->fm) && est_vide(a->fd))
	{
		return 0;
	}
	return 1 + max3(hauteur(a->fg), hauteur(a->fd), hauteur(a->fm));
}


int valeur_max(ATR a)
{
	int max_valeur = 0;
	int maximum1 = max(a->val1, a->val2);
	if(est_vide(a->fg) && est_vide(a->fm) && est_vide(a->fd))
	{
		return maximum1;
	}
	if(!est_vide(a->fg) && !est_vide(a->fm) && !est_vide(a->fd))
	{
		int maximum2 = valeur_max(a->fg);
		int maximum3 = valeur_max(a->fm);
		int maximum4 = valeur_max(a->fd);
		max_valeur = max4(maximum1, maximum2, maximum3, maximum4);
	}	
	else
	{
		if(!est_vide(a->fd))
		{
			int maximum2 = valeur_max(a->fd);
			max_valeur = (maximum2, maximum1);
		}
		if(!est_vide(a->fg))
		{
			int maximum3 = valeur_max(a->fg);
			max_valeur = (maximum3, maximum1);
		}
		if(!est_vide(a->fm))
		{
			int maximum4 = valeur_max(a->fm);
			max_valeur = (maximum4, maximum1);
		}

	}
	return max_valeur;
}

int nombre_valeur(ATR a)
{
	if(est_vide(a))
	{
		return 0;
	}
	return 2 + nombre_valeur(a->fd) + nombre_valeur(a->fm) + nombre_valeur(a->fg);
}
