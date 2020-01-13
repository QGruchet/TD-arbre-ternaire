struct ternaire{
	int val1;
	int val2;
	struct ternaire *fg, *fm, *fd;
};

typedef struct ternaire ternaire;
typedef ternaire* ATR;

ATR creer_arbre_vide();
int est_vide(ATR a);
ATR creer_feuille(int valeur1, int valeur2);
void afficher_arbre(ATR a);
ATR inserer_val(ATR a, int valeur);
int hauteur(ATR a);
int valeur_max(ATR a);
int nombre_valeur(ATR a);