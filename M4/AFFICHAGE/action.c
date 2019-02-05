#include "donnees.h"
#include "action.h"

void color(int t,int f) //Couleur dans la console
{
        HANDLE H=GetStdHandle(STD_OUTPUT_HANDLE);
            SetConsoleTextAttribute(H,f*16+t);
}

void affichage(Element *actual)
{
    int H = 0;
    int M = 0;
    int S = 0;

    	S = actual->time;
        M = S/60;
        S = S%60;
        H = M/60;
        M = M%60;

    	//Si le bpm est dans l'interval moyen d'un adulte
    	if (actual->bpm >= 60 && actual->bpm <= 80)
        {
        	printf("|%8s  >%5d:%2d:%-5d || %5d bpm    ||\n",actual->date, H,M,S, actual->bpm);
        }

        //Si le bpm n'est pas dans l'interval moyen d'un adulte
        else
        {

        	color(12,0);
        	printf("|%8s  >%5d:%2d:%-5d || %5d bpm    ||\n",actual->date, H,M,S, actual->bpm);
        	color(15,0);
        }
}

int affichage_full(List *liste)
{
    Element *actual = NULL;
    actual = liste->first;

    printf("*********************************************\n");
    //Tant qu'on est pas arriver en fin de liste on la parcours
    while(actual->next != NULL)
    {
    	affichage(actual);
        actual = actual->next;
    }
    printf("*********************************************\n");

return 0;
}

//Donne le nombre de lignes
int nbr_ligne(List *liste)
{
	Element *actual = NULL;
	int i = 0;

	actual = liste->first;
	//Tant qu'on arrive pas en fin de liste on ajoute une ligne.
	while (actual->next != NULL)
	{
		actual = actual->next;
		i++;
	}

//Renvoie le nombre de lignes
return i;
}

int moyenne(List *liste)
{
	int moyenne = 0, i = 0;
	int dH = 0,dM = 0, dS = 0;
	int fH = 0,fM = 0, fS = 0;
	int tpDebut = 0, tpFin = 0;

	Element *actual = NULL;

	//Demande l'intervalle dans lequelle on doit faire la moyenne
	printf("Intervalle debut (Sous la forme d'un temp HH:MM:SS): ");scanf("%d:%d:%d", &dH,&dM,&dS);
	printf("Intervalle fin (Sous la forme d'un temp HH:MM:SS): ");scanf("%d:%d:%d", &fH,&fM,&fS);

    tpDebut = dH*60*60 + dM*60 + dS;
    tpFin = fH*60*60 + fM*60 + fS;

	actual = liste->first;

	while (actual->next != NULL)
	{
		//Si on est dans l'interval on ajoute les bpm a la moyenne
		if (actual->time >= tpDebut && actual->time <= tpFin)
		{
            moyenne += actual->bpm;
            i += 1;
		}
		actual = actual->next;
	}
//On oublie pas de diviser par le nombre d'elements de la liste
return moyenne/i;
}

int recherche(List *liste)
{
	int tpDebut = 0, tpFin = 0, find = 0;
    int dH = 0,dM = 0, dS = 0;
	int fH = 0,fM = 0, fS = 0;
	Element *actual = NULL;

	//Recherche dans un intervalle
	printf("Intervalle debut (Sous la forme d'un temp HH:MM:SS): ");scanf("%d:%d:%d", &dH,&dM,&dS);
	printf("Intervalle fin (Sous la forme d'un temp HH:MM:SS): ");scanf("%d:%d:%d", &fH,&fM,&fS);

    tpDebut = dH*60*60 + dM*60 + dS;
    tpFin = fH*60*60 + fM*60 + fS;

	actual = liste->first;

    printf("*********************************************\n");
	while (actual->next != NULL)
	{
		if (actual->time >= tpDebut && actual->time <= tpFin)
		{
            affichage(actual);
		}
		actual = actual->next;
	}
	printf("*********************************************\n");

	if (find == 0)
	{
		printf("\nAucune donnees dans l'intervalle.\n");
	}

return 0;
}

//Tri decroissant du temps (Sachant qu'il est deja trier de maniere croissante)
int tri_Dtemps(List *liste)
{
	Element *actual = NULL;
	actual = liste->first;

	//On se place en fin de liste
	while (actual->next != NULL)
	{
		actual = actual->next;
	}
    printf("*********************************************\n");
	//On l'affiche a l'envers (donc de maniere decroissante)
	while (actual->previous != NULL)
	{
		affichage(actual);
		actual = actual->previous;
	}
	printf("*********************************************\n");

return 0;
}

//Tri croissant pouls
int tri_Cpouls(List *liste)
{
	Element *actual = NULL;
	Element *next = NULL;
	int tmp_bpm = 0,tmp_time = 0;
	int i = 0;

	actual = liste->first;
	next = actual->next;

	//Tri a bulle (le seul qui fonctionne avec une liste)
	for (i = 0; i < nbr_ligne(liste); i++)
	{
		while (actual->next != NULL)
		{
			if (next->bpm <= actual->bpm)
			{
				//On swap les valeurs
				tmp_bpm = actual->bpm;
				tmp_time = actual->time;

				actual->bpm = next->bpm;
				actual->time = next->time;

				next->bpm = tmp_bpm;
				next->time = tmp_time;
			}
			actual = actual->next;
			next = actual->next;

		}
		//On passe à l'element suivant
		actual = liste->first;
		next = actual->next;
	}
return 0;
}

//Tri decroissant pouls (meme principe que le tri croissant)
int tri_Dpouls(List *liste)
{
	Element *actual = NULL;
	Element *next = NULL;
	int tmp_bpm = 0,tmp_time = 0;
	int i = 0;

	actual = liste->first;
	next = actual->next;

	for (i = 0; i < nbr_ligne(liste); i++)
	{
		while (actual->next != NULL)
		{
			if (next->bpm >= actual->bpm)
			{
				tmp_bpm = actual->bpm;
				tmp_time = actual->time;

				actual->bpm = next->bpm;
				actual->time = next->time;

				next->bpm = tmp_bpm;
				next->time = tmp_time;
			}
			actual = actual->next;
			next = actual->next;

		}
		actual = liste->first;
		next = actual->next;
	}
return 0;
}

//Recherche du poul max
int number_max(List *liste)
{
	int max = 0;
	Element *actual = NULL;

	actual = liste->first;

	//On parcours toute la liste
	while (actual->next != NULL)
	{
		if (max <= actual->bpm)
		{
			//A chaque fois qu'on trouve un element plus grand on l'enregistre
			max = actual->bpm;
		}
		actual = actual->next;
	}

return max;
}

//Recherche du poul min (meme principe que max)
int number_min(List *liste)
{
	int min = 0;
	Element *actual = NULL;

	actual = liste->first;
	min = actual->bpm;

	while (actual->next != NULL)
	{
		if (min >= actual->bpm)
		{
			min = actual->bpm;

		}
		actual = actual->next;
	}

return min;
}

void aberrante(List *liste)
{
	Element *actual = NULL;
	int n = 0, i = 0;
	int variance = 0;
	int ecart = 0;
	int aberant = 0;
	int choix = 0;

	actual = liste->first;

	//Moyenne
    while (actual->next != NULL)
	{
		n += actual->bpm;
		i += 1;
		actual = actual->next;
	}

	n = n/i;
	actual = liste->first;

    //Variance
	while (actual->next != NULL)
	{
		variance += pow((actual->bpm - n),2);
		actual = actual->next;
	}

    //Puis ecart type
	variance /= nbr_ligne(liste);
	ecart = sqrt(variance);

	actual = liste->first;
	printf("*********************************************\n");

	//Affichage de la liste sans les valeurs aberantes
	while (actual->next != NULL)
    {
        if (actual->bpm <= (n + ecart) && actual->bpm >= (n - ecart))
        {
            affichage(actual);
        }
        else
        {
            aberant += 1;
        }
        actual = actual->next;
    }
    printf("*********************************************\n");

    printf ("Valeur aberante(s) suprimer : "); color(12,0); printf ("%d\n",aberant); color(15,0);
}

void refresh(List *liste)
{
    //On libere le nom de la liste (le contenue n'est pas suprimer)
	free(liste);
	//On recharge la liste
	liste = stackfile();

	//On affiche qu'on a réussi (Si erreurs alors le stackfile echoue et quitte le programme)
	color(10,0);
	printf("Successful !\n");
	color(15,0);
}

//Un tres joli logo de l'exia (Fait pas un denomer Arthur
void logo_exia()
{
    printf("          ``.....----:::///++oooosssyyyhs        :sdNMMNmy+`   -NNNNNNNNNNNNNN`  `+hmNMMNmds:   oNNd\n\
         :hhhhhhhhhhhhhhhhhhhhhhhhhhhhhhy      /NMMNysoymMMMo  -MMMyyyyyyyyyyy  +MMMdsoooymMN+  -++/\n\
         :hhhhhhhhhhhhhhhhhhhhhhhhhhhhhhh     /MMM+      :NMMs -MMM.           :MMM-       -`   oNNd\n\
         -hhhhhhhhhhhhhhhhhhhhhhhhhhhhhhh`    dMMh        -+++ -MMM.           +MMN`            sMMm\n\
         -hhhhhhhhhhhhhhhyyyyyshhhhhhhhhh.    mMMs             -MMM:........`  `mMMmo/:.`       sMMm\n\
         `----....````         yhhhhhhhhh-    NMMo             -MMMMMMMMMMMM+   `odMMMMMMMNh+`  sMMm\n\
                               ohhhhhhhhh:    mMMo             -MMM+////////.      `.:/+oyNMMm. sMMm\n\
----....                       /hhhhhhhhh/    dMMy        `... -MMM.                       dMMy sMMm\n\
::::::::`                      -hhhhhhhhh+    oMMN-      `dMMd -MMM.            `.         dMMy sMMm\n\
::::::::`                      `hhhhhhhhho     yMMMy/::/sNMMd` -MMM+////////// oNMdo/:::/omMMm. sMMm\n\
::::::::`                       yhhhhhhhhs      -smMMMMMMNh:   -MMMMMMMMMMMMMM`.odNMMMMMMMNh/   sMMm\n\
::::::::`                       ohhhhhhhhs         `-::-.      `..............     `--::-`      `...\n\
-:::::::.                       /hhhhhhhhy                                                          \n\
.:::::::.                       -hhhhhhhhs                  -shyyyh+`  .ds     od-  -h`   +hyyyyhy: \n\
-:::::::.                        ++/:-.`                   +m-    `sm`  `hd. `yd.   -s`  `+`     -N+\n\
.:::::::.                `````````                        `M/       ms    +N/ms     :M.           dy\n\
.:::::::.`----:::::::::::::::::::.                        -Mhsssssssyo     oMh      :M.  `+yysssssNy\n\
.:::::::.`:::::::::::::::::::::::-                        `M+             sm:hh`    :M.  dh       dy\n\
`...`````.:::::::::::::::::::::::-                         +N:     `/`  .dh`  sm-   :M.  dh      -My\n\
         `------:::::-----------.`                          -shyyyhy/  -mo     /m/  :m.  `shyyyyyods\n\
                                                                                                    ");
}
