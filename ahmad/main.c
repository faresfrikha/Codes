#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>
#include <string.h>
#define MAX 256

/***********LES STRUCTURES************/
typedef struct date
{
    int annee;
    int mois;
    int jour;
}date;

typedef struct matiere_premiere
{
    int ref;//reference
    char cat[20];//categorie
    char no[20];//nom
    char f[20];//fournisseur
    float qt;//quantite
    float pa;//prix d'achat
    date de;//date d'entree
    date ds;//date de sortie
}st1;

typedef struct produit_en_cours_de_fabrication
{
    int ref;// reference
    char cat[20];//categorie
    char no[20];//nom
    float qt;//quantite
    date de;//date d'entree
    date ds;//date de sortie
}st2;

typedef struct produit_fini
{
    int ref;//reference
    char cat[20];//categorie
    char no[20];//nom
    float qt;//quantite
    float p;//prix
    date de;//date d'entree
    date ds;//date de sortie
}st3;

typedef struct marchandise
{
    int ref;//reference
    char cat[20];//categorie
    char no[20];//nom
    float qt;//quantite
    float p;//prix de vente
    float pa;//prix d'achat
    date de;//date d'entree
    date ds;//date de sortie
    char f[20];//fournisseur

}st4;

typedef struct client
{
    int ref;//reference du client
    int tel;//telephone
    char ad[20];//addresse
    char no[20];//nom de la societe
    char p[20];//produit acheté
    float qt;//quantite achetee
    float pa;//prix d'achat
    date da;//date d'achat

}st5;

typedef struct commande
{
    char no[20];//nom du client
    char p[20];//produit commande
    float qt;//quantite commandee
    float op;//prix de la commande
    int ref;//reference de la commande
    date od;//date de la commande

}st6;

typedef struct facture
{
    int num_fac;//numero de la facture
    char f[20];//fournisseur
    char cl[20];//nom du client
    int ref;//refernece
    float qt;//quantite
    char no[20];//nom de l'article
    float p_unit;//prix unitaire
    float mt;//montant
    date d;//date de la facture

}st7;

/**********LES FONCTIONS**********/


/***Les fonctions des matieres premieres***/

void Ajout_mp()
{
    st1 mp1;
    FILE *f1;
    f1=fopen("matiere_premiere.txt","a");/*ouverture du fichier en mode ajout*/
    printf("\nAjoutez une matiere premiere\n");
    printf("\nDonnez la reference de la matiere premiere: ");
    scanf("%i",&mp1.ref);
    printf("\nDonnez la categorie de la matiere premiere: ");
    scanf("%s",mp1.cat);
    printf("\nDonnez le nom de la matiere premiere: ");
    scanf("%s",mp1.no);
    printf("\nDonnez le fournisseur de la matiere premiere: ");
    scanf("%s",mp1.f);
    printf("\nDonnez la quantite de la matiere premiere en Kg: ");
    scanf("%f",&mp1.qt);
    printf("\nDonnez le prix d'achat de la matiere premiere en Dt: ");
    scanf("%f",&mp1.pa);
    printf("\nDonnez la date d'entree de la forme jj mm aa: ");
    scanf("%i  %i  %i",&mp1.de.jour,&mp1.de.mois,&mp1.de.annee);
    printf("\nDonnez la date de sortie la forme jj mm aa: ");
    scanf("%i  %i  %i",&mp1.ds.jour,&mp1.ds.mois,&mp1.ds.annee);
    printf("\nDonnees bien saisies \n");
    fprintf(f1,"%i %s %s %s %f %f %i/%i/%i %i/%i/%i \n",mp1.ref,mp1.cat,mp1.no,mp1.f,mp1.qt,mp1.pa,mp1.de.jour,mp1.de.mois,mp1.de.annee,mp1.ds.jour,mp1.ds.mois,mp1.ds.annee);/*ajout des info dans le fichier*/
    fclose(f1);
}



int supprimer_mp()
{
   int  ctr = 0;
        char ch;
        FILE *f1, *f11;
        char str[MAX], temp[] = "temp.txt";char ch1[20];
        f1 = fopen("matiere_premiere.txt", "r");
        if (!f1)
		{
                printf(" Impossible d'ouvrir le fichier!!\n");
                return 0;
        }
        f11 = fopen(temp, "w"); // ouverture du fichier temporaire en mode écriture
        if (!f11)
		{
                printf("Impossible d'ouvrir le fichier temporaire!!\n");
                        fclose(f11);
                return 0;
        }
        printf("\nDonnez la reference de la matiere premiere que vous voulez supprimer : ");
        scanf("%s", ch1);

        while (!feof(f1))//copier tout le contenu du fichier original au fichier temporaire sauf la ligne à supprimer
        {
            strcpy(str, "\0");
            fgets(str, MAX, f1);
            if (!feof(f1))
            {
                ctr++;

                if (!strstr(str,ch1))//comparaison de la ligne à supprimer et la reference saisie
                {
                    fprintf(f11, "%s", str);
                }
            }
        }
        fclose(f1);
        fclose(f11);
        remove("matiere_premiere.txt");  		// suppression du fichier original
        rename(temp, "matiere_premiere.txt"); 	// renommer le fichier temporaire par le fichier original
        /*------ lecture du fichier ----------------*/
   f1=fopen("matiere_premiere.txt","r");
            ch=fgetc(f1);
          printf("\nle nouveau contenu du stock des matieres premieres est : \n");
          while(ch!=EOF)
            {
                printf("%c",ch);
                 ch=fgetc(f1);
            }
        fclose(f1);
/*------- fin de la lecture ---------------*/
        return 0;

  }



int modifier_mp()
{
    st1 mp1;
    int  ctr = 0;
        char ch;
        FILE *f1, *f11;
        char str[MAX], temp[] = "temp.txt";char ch1[20];
        f1 = fopen("matiere_premiere.txt", "r");
        if (!f1)
		{
                printf(" Impossible d'ouvrir le fichier!!\n");
                return 0;
        }
        f11 = fopen(temp, "w");
        if (!f11)
		{
                printf("Impossible d'ouvrir le fichier temporaire!!\n");
                        fclose(f11);
                return 0;
        }
        printf("\nDonnez la reference de la matiere premiere que vous voulez modifier : ");
        scanf("%s", ch1);

        while (!feof(f1))
        {
            strcpy(str, "\0");
            fgets(str, MAX, f1);
            if (!feof(f1))
            {
                ctr++;

                if (!strstr(str,ch1))
                {
                    fprintf(f11, "%s", str);
                }
            }
        }
        fclose(f1);
        fclose(f11);
        remove("matiere_premiere.txt");
        rename(temp, "matiere_premiere.txt");

    f1=fopen("matiere_premiere.txt","a+");

        printf("\nDonnez la nouvelle reference de la matiere premiere: ");
        scanf("%i",&mp1.ref);
        printf("\nDonnez la nouvelle categorie de la matiere premiere: ");
        scanf("%s",mp1.no);
        printf("\nDonnez le nouveau nom: ");
        scanf("%s",mp1.no);
        printf("\nDonnez le nouveau fournisseur: ");
        scanf("%s",mp1.f);
        printf("\nDonnez la nouvelle quantite en Kg: ");
        scanf("%f",&mp1.qt);
        printf("\nDonnez le nouveau prix d'achat en Dt: ");
        scanf("%f",&mp1.pa);
        printf("\nDonnez la nouvelle date d'entree de la forme jj mm aa: ");
        scanf("%i  %i  %i",&mp1.de.jour,&mp1.de.mois,&mp1.de.annee);
        printf("\nDonnez la nouvelle date de sortie la forme jj mm aa: ");
        scanf("%i  %i  %i",&mp1.ds.jour,&mp1.ds.mois,&mp1.ds.annee);
        printf("\nDonnees bien modifiees \n");
        fprintf(f1,"%i %s %s %s %f %f %i/%i/%i %i/%i/%i\n",mp1.ref,mp1.cat,mp1.no,mp1.f,mp1.qt,mp1.pa,mp1.de.jour,mp1.de.mois,mp1.de.annee,mp1.ds.jour,mp1.ds.mois,mp1.ds.annee);
        fclose(f1);
         /*------ lecture du fichier ----------------*/
   f1=fopen("matiere_premiere.txt","r");
            ch=fgetc(f1);
          printf("\nle nouveau contenu du stock des matieres premieres est : \n");
          while(ch!=EOF)
            {
                printf("%c",ch);
                 ch=fgetc(f1);
            }
        fclose(f1);
/*------- fin de la lecture ---------------*/
    return 0;

}


int affiche_mp()
{
    /* BUFSIZ : macro prédéfini qui correspond à la longueur max d'une ligne dans un fichier*/
    char tab[BUFSIZ]; /* tableau pour récupérer un mot saisi au clavier sur une ligne */
    char buffer[BUFSIZ]; /* tableau pour la lecture d'une ligne à partir du fichier */
    FILE *f1;
    char *p; /* pointeur pour récupérer l'adresse d'un caractère */
    f1=fopen("matiere_premiere.txt","r");
     /* en cas d'erreurs d'ouverture */
    if(f1==NULL)
    {
        fputs("erreur à l'ouverture du fichier\n",stderr);
        return EXIT_FAILURE;
    }
    /* en cas d'ouverture réussie, saisie du mot à rechercher dans le fichier */
    puts("\nVoici le contenu du stock des matieres premieres : ");
    /*récuparation du mot à partir du clavier */
    fgets(tab, sizeof tab, stdin);
    /* remplacement du caractère espace par le caractère 0 */
     p=strchr(tab, '\n'); if (p!=NULL) *p='\0';
    /* lecture du fichier ligne par ligne */
     while(fgets(buffer, sizeof buffer,f1))
        {
            /* remplacement des retours chariots par caractère 0 au niveau de chaque ligne lue*/
            p=strchr(buffer,'\n'); /* p : adresse du carctère de retour chariot */
            if(p!=NULL)
                { *p='\0';}
            puts(buffer);

        }

        /* fermeture du fichier */
        fclose(f1);

        return 0;


}


/***Les fonctions des produits en cours de fabrication***/


void Ajout_pc()
{
    st2 mp2;
    FILE *f2;
    f2=fopen("produit_en_cour.txt","a");/*ouverture du fichier en mode ajout*/
    printf("\nAjoutez un produit en cours de fabrication\n");
    printf("\nDonnez la reference du produit en cours de fabrication: ");
    scanf("%i",&mp2.ref);
    printf("\nDonnez la categorie du produit en cours de fabrication: ");
    scanf("%s",mp2.cat);
    printf("\nDonnez le nom du produit en cours de fabrication: ");
    scanf("%s",mp2.no);
    printf("\nDonnez la quantite du produit en cours de fabrication en Kg: ");
    scanf("%f",&mp2.qt);
    printf("\nDonnez la date d'entree de la forme jj mm aa: ");
    scanf("%i  %i  %i",&mp2.de.jour,&mp2.de.mois,&mp2.de.annee);
    printf("\nDonnez la date de sortie la forme jj mm aa: ");
    scanf("%i  %i  %i",&mp2.ds.jour,&mp2.ds.mois,&mp2.ds.annee);
    printf("\nDonnees bien saisies \n");
    fprintf(f2,"%i %s %s %f %i/%i/%i %i/%i/%i \n",mp2.ref,mp2.cat,mp2.no,mp2.qt,mp2.de.jour,mp2.de.mois,mp2.de.annee,mp2.ds.jour,mp2.ds.mois,mp2.ds.annee);/*ajout des info  dans le fichier*/
    fclose(f2);
}

int supprimer_pc()
{
   int  ctr = 0;
        char ch;
        FILE *f2, *f22;
        char str[MAX], temp[] = "temp.txt";char ch1[20];
        f2 = fopen("produit_en_cour.txt", "r");
        if (!f2)
		{
                printf(" Impossible d'ouvrir le fichier!!\n");
                return 0;
        }
        f22 = fopen(temp, "w"); // ouverture du fichier temporaire en mode écriture
        if (!f22)
		{
                printf("Impossible d'ouvrir le fichier temporaire!!\n");
                        fclose(f22);
                return 0;
        }
        printf("\nDonnez la reference du produit en cours de fabrication que vous voulez supprimer : ");
        scanf("%s", ch1);

        while (!feof(f2))//copier tout le contenu du fichier original vers le fichier temporaire sauf la ligne a
        {
            strcpy(str, "\0");
            fgets(str, MAX, f2);
            if (!feof(f2))
            {
                ctr++;

                if (!strstr(str,ch1))
                {
                    fprintf(f22, "%s", str);
                }
            }
        }
        fclose(f2);
        fclose(f22);
        remove("produit_en_cour.txt");  		// supprimer le fichier original
        rename(temp, "produit_en_cour.txt"); 	// renommer le fichier temporaire par le fichier original
        /*------lecture du fichier ----------------*/
   f2=fopen("produit_en_cour.txt","r");
            ch=fgetc(f2);
          printf("\nle nouveau contenu du stock des produits en cours de fabrication est : \n");
          while(ch!=EOF)
            {
                printf("%c",ch);
                 ch=fgetc(f2);
            }
        fclose(f2);
/*-------fin de la lecture ---------------*/
        return 0;

  }


int modifier_pc()
{
    st2 mp2;
    int  ctr = 0;
        char ch;
        FILE *f2, *f22;
        char str[MAX], temp[] = "temp.txt";char ch1[20];
        f2 = fopen("produit_en_cour.txt", "r");
        if (!f2)
		{
                printf(" Impossible d'ouvrir le fichier!!\n");
                return 0;
        }
        f22 = fopen(temp, "w");
        if (!f22)
		{
                printf("Impossible d'ouvrir le fichier temporaire!!\n");
                        fclose(f22);
                return 0;
        }
        printf("\nDonnez la reference du produit en cours de fabrication que vous voulez modifier : ");
        scanf("%s", ch1);

        while (!feof(f2))
        {
            strcpy(str, "\0");
            fgets(str, MAX, f2);
            if (!feof(f2))
            {
                ctr++;

                if (!strstr(str,ch1))
                {
                    fprintf(f22, "%s", str);
                }
            }
        }
        fclose(f2);
        fclose(f22);
        remove("produit_en_cour.txt");
        rename(temp, "produit_en_cour.txt");

    f2=fopen("produit_en_cour.txt","a+");

    printf("\nDonnez la nouvelle reference du produit en cours de fabrication: ");
    scanf("%i",&mp2.ref);
    printf("\nDonnez la nouvelle categorie du produit en cours de fabrication: ");
    scanf("%s",mp2.cat);
    printf("\nDonnez le nouveau nom du produit en cours de fabrication: ");
    scanf("%s",mp2.no);
    printf("\nDonnez la nouvelle quantite du produit en cours de fabrication en Kg: ");
    scanf("%f",&mp2.qt);
    printf("\nDonnez la nouvelle date d'entree de la forme jj mm aa: ");
    scanf("%i  %i  %i",&mp2.de.jour,&mp2.de.mois,&mp2.de.annee);
    printf("\nDonnez la nouvelle date de sortie la forme jj mm aa: ");
    scanf("%i  %i  %i",&mp2.ds.jour,&mp2.ds.mois,&mp2.ds.annee);
    printf("\nDonnees bien modifiees \n");
    fprintf(f2,"%i %s %s %f %i/%i/%i %i/%i/%i \n",mp2.ref,mp2.cat,mp2.no,mp2.qt,mp2.de.jour,mp2.de.mois,mp2.de.annee,mp2.ds.jour,mp2.ds.mois,mp2.ds.annee);
        fclose(f2);
         /*------ lecture du fichier ----------------*/
   f2=fopen("produit_en_cour.txt","r");
            ch=fgetc(f2);
          printf("\nle nouveau contenu du stock des produits en cours de fabrication est : \n");
          while(ch!=EOF)
            {
                printf("%c",ch);
                 ch=fgetc(f2);
            }
        fclose(f2);
/*------- fin de la lecture ---------------*/
    return 0;

}


int affiche_pc()
{
    /* BUFSIZ : macro prédéfini qui correspond à la longueur max d'une ligne dans un fichier*/
    char tab[BUFSIZ]; /* tableau pour récupérer un mot saisi au clavier sur une ligne */
    char buffer[BUFSIZ]; /* tableau pour la lecture d'une ligne à partir du fichier */
    FILE *f2;
    char *p; /* pointeur pour récupérer l'adresse d'un caractère */
    f2=fopen("produit_en_cour.txt","r");
     /* en cas d'erreurs d'ouverture */
    if(f2==NULL)
    {
        fputs("erreur de l'ouverture du fichier\n",stderr);
        return EXIT_FAILURE;
    }
    /* en cas d'ouverture réussie, saisie du mot à rechercher dans le fichier */
    puts("Voici le contenu du stock des produits en cours de fabrication : \n");
    /*récuparation du mot à partir du clavier */
    fgets(tab, sizeof tab, stdin);
    /* remplacement du caractère espace par le caractère 0 */
     p=strchr(tab, '\n'); if (p!=NULL) *p='\0';
    /* lecture du fichier ligne par ligne */
     while(fgets(buffer, sizeof buffer,f2))
        {
            /* remplacement des retours chariots par caractère 0 au niveau de chaque ligne lue*/
            p=strchr(buffer,'\n'); /* p : adresse du carctère de retour chariot */
            if(p!=NULL)
                { *p='\0';}
            puts(buffer);

        }

        /* fermeture du fichier */
        fclose(f2);

        return 0;


}


/***Les fonctions des produits fini***/

void Ajout_pf()
{
    st3 mp3;
    FILE *f3;
    f3=fopen("produits_finis.txt","a");/*ouverture du fichier en mode ajout*/
    printf("Ajoutez un produit fini\n");
    printf("\nDonnez la reference du produit fini: ");
    scanf("%i",&mp3.ref);
    printf("\nDonnez la categorie du produit fini: ");
    scanf("%s",mp3.cat);
    printf("\nDonnez le nom du produit fini: ");
    scanf("%s",mp3.no);
    printf("\nDonnez la quantite du produit fini en Kg: ");
    scanf("%f",&mp3.qt);
    printf("\nDonnez le prix du produit fini en Dt: ");
    scanf("%f",&mp3.p);
    printf("\nDonnez la date d'entree de la forme jj mm aa: ");
    scanf("%i  %i  %i",&mp3.de.jour,&mp3.de.mois,&mp3.de.annee);
    printf("\nDonnez la date de sortie la forme jj mm aa: ");
    scanf("%i  %i  %i",&mp3.de.jour,&mp3.de.mois,&mp3.de.annee);
    printf("\nDonnees bien saisies \n");
    fprintf(f3,"%i %s %s %f %f %i/%i/%i %i/%i/%i \n",mp3.ref,mp3.cat,mp3.no,mp3.qt,mp3.p,mp3.de.jour,mp3.de.mois,mp3.de.annee,mp3.ds.jour,mp3.ds.mois,mp3.ds.annee);/*ajout des info dans le fichier*/
    fclose(f3);
}

int supprimer_pf()
{
   int  ctr = 0;
        char ch;
        FILE *f3, *f33;
        char str[MAX], temp[] = "temp.txt";char ch1[20];
        f3 = fopen("produits_finis.txt", "r");
        if (!f3)
		{
                printf(" Impossible d'ouvrir le fichier!!\n");
                return 0;
        }
        f33 = fopen(temp, "w"); // ouverture du fichier temporaire en mode écriture
        if (!f33)
		{
                printf("Impossible d'ouvrir le fichier temporaire!!\n");
                        fclose(f33);
                return 0;
        }
        printf("\nDonnez la reference du produit fini que vous voulez supprimer : ");
        scanf("%s", ch1);

        while (!feof(f3))//copier tout le contenu du fichier original vers le fichier temporaire sauf la ligne a
        {
            strcpy(str, "\0");
            fgets(str, MAX, f3);
            if (!feof(f3))
            {
                ctr++;

                if (!strstr(str,ch1))
                {
                    fprintf(f33, "%s", str);
                }
            }
        }
        fclose(f3);
        fclose(f33);
        remove("produits_finis.txt");  		// supprimer le fichier original
        rename(temp, "produits_finis.txt"); 	// renommer le fichier temporaire par le fichier original
        /*------lecture du fichier ----------------*/
   f3=fopen("produits_finis.txt","r");
            ch=fgetc(f3);
          printf("\nle nouveau contenu du stock des produits finis est : \n");
          while(ch!=EOF)
            {
                printf("%c",ch);
                 ch=fgetc(f3);
            }
        fclose(f3);
/*-------fin de la lecture ---------------*/
        return 0;

  }

int modifier_pf()
{
    st3 mp3;
    int  ctr = 0;
        char ch;
        FILE *f3, *f33;
        char str[MAX], temp[] = "temp.txt";char ch1[20];
        f3 = fopen("produits_finis.txt", "r");
        if (!f3)
		{
                printf(" Impossible d'ouvrir le fichier!!\n");
                return 0;
        }
        f33 = fopen(temp, "w");
        if (!f33)
		{
                printf("Impossible d'ouvrir le fichier temporaire!!\n");
                        fclose(f33);
                return 0;
        }
        printf("\nDonnez la reference du produit fini que vous voulez modifier : ");
        scanf("%s", ch1);

        while (!feof(f3))
        {
            strcpy(str, "\0");
            fgets(str, MAX, f3);
            if (!feof(f3))
            {
                ctr++;

                if (!strstr(str,ch1))
                {
                    fprintf(f33, "%s", str);
                }
            }
        }
        fclose(f3);
        fclose(f33);
        remove("produits_finis.txt");
        rename(temp, "produits_finis.txt");

     f3=fopen("produits_finis.txt","a+");
     printf("\nDonnez la nouvelle reference du produit fini: ");
     scanf("%i",&mp3.ref);
     printf("\nDonnez la nouvelle categorie du produit fini: ");
     scanf("%s",mp3.cat);
     printf("\nDonnez le nouveau nom du produit fini: ");
     scanf("%s",mp3.no);
     printf("\nDonnez la nouvelle quantite du produit fini en Kg: ");
     scanf("%f",&mp3.qt);
     printf("\nDonnez le nouveau prix du produit fini en Dt: ");
     scanf("%f",&mp3.p);
     printf("\nDonnez la nouvelle date d'entree de la forme jj mm aa: ");
     scanf("%i  %i  %i",&mp3.de.jour,&mp3.de.mois,&mp3.de.annee);
     printf("\nDonnez la nouvelle date de sortie la forme jj mm aa: ");
     scanf("%i  %i  %i",&mp3.de.jour,&mp3.de.mois,&mp3.de.annee);
     printf("\nDonnees bien saisies \n");
     fprintf(f3,"%i %s %s %f %f %i/%i/%i %i/%i/%i \n",mp3.ref,mp3.cat,mp3.no,mp3.qt,mp3.p,mp3.de.jour,mp3.de.mois,mp3.de.annee,mp3.ds.jour,mp3.ds.mois,mp3.ds.annee);

        fclose(f3);
         /*------ lecture du fichier ----------------*/
   f3=fopen("produits_finis.txt","r");
            ch=fgetc(f3);
          printf("\nle nouveau contenu du stock des produits finis est : \n");
          while(ch!=EOF)
            {
                printf("%c",ch);
                 ch=fgetc(f3);
            }
        fclose(f3);
/*------- fin de la lecture ---------------*/
    return 0;

}


int affiche_pf()
{
    /* BUFSIZ : macro prédéfini qui correspond à la longueur max d'une ligne dans un fichier*/
    char tab[BUFSIZ]; /* tableau pour récupérer un mot saisi au clavier sur une ligne */
    char buffer[BUFSIZ]; /* tableau pour la lecture d'une ligne à partir du fichier */
    FILE *f3;
    char *p; /* pointeur pour récupérer l'adresse d'un caractère */
    f3=fopen("produits_finis.txt","r");
     /* en cas d'erreurs d'ouverture */
    if(f3==NULL)
    {
        fputs("erreur à l'ouverture du fichier\n",stderr);
        return EXIT_FAILURE;
    }
    /* en cas d'ouverture réussie, saisie du mot à rechercher dans le fichier */
    puts("Voici le contenu du stock des produits finis : \n");
    /*récuparation du mot à partir du clavier */
    fgets(tab, sizeof tab, stdin);
    /* remplacement du caractère espace par le caractère 0 */
     p=strchr(tab, '\n'); if (p!=NULL) *p='\0';
    /* lecture du fichier ligne par ligne */
     while(fgets(buffer, sizeof buffer,f3))
        {
            /* remplacement des retours chariots par caractère 0 au niveau de chaque ligne lue*/
            p=strchr(buffer,'\n'); /* p : adresse du carctère de retour chariot */
            if(p!=NULL)
                { *p='\0';}
            puts(buffer);

        }

        /* fermeture du fichier */
        fclose(f3);

        return 0;


}
/***Les fonctions des marchandises***/

void Ajout_m()
{
    st4 mp4;
    FILE *f4;
    f4=fopen("marchandise.txt","a");/*ouverture du fichier en mode ajout*/
    printf("Ajoutez une marchandise\n");
    printf("\nDonnez la reference de la marchandise: ");
    scanf("%i",&mp4.ref);
    printf("\nDonnez la categorie de la marchandise: ");
    scanf("%s",mp4.cat);
    printf("\nDonnez le nom de la marchandise: ");
    scanf("%s",mp4.no);
    printf("\nDonnez le fournisseur de la marchandise: ");
    scanf("%s",mp4.f);
    printf("\nDonnez la quantite de la marchandise en Kg: ");
    scanf("%f",&mp4.qt);
    printf("\nDonnez le prix d'achat de la marchandise en Dt: ");
    scanf("%f",&mp4.p);
    printf("\nDonnez le prix de vente de la marchandise en Dt: ");
    scanf("%f",&mp4.p);
    printf("\nDonnez la date d'entree de la forme jj mm aa: ");
    scanf("%i  %i  %i",&mp4.de.jour,&mp4.de.mois,&mp4.de.annee);
    printf("\nDonnez la date de sortie la forme jj mm aa: ");
    scanf("%i  %i  %i",&mp4.ds.jour,&mp4.ds.mois,&mp4.ds.annee);
    printf("\nDonnees bien saisies \n");
    fprintf(f4,"%i %s %s %s %f %f %f %i/%i/%i %i/%i/%i\n",mp4.ref,mp4.cat,mp4.no,mp4.f,mp4.qt,mp4.p,mp4.p,mp4.de.jour,mp4.de.mois,mp4.de.annee,mp4.ds.jour,mp4.ds.mois,mp4.ds.annee);/*ajout des info dans le fichier*/
    fclose(f4);
}

int supprimer_m()
{
   int  ctr = 0;
        char ch;
        FILE *f4, *f44;
        char str[MAX], temp[] = "temp.txt";char ch1[20];
        f4 = fopen("marchandise.txt", "r");
        if (!f4)
		{
                printf(" Impossible d'ouvrir le fichier!!\n");
                return 0;
        }
        f44 = fopen(temp, "w"); // ouverture du fichier temporaire en mode écriture
        if (!f44)
		{
                printf("Impossible d'ouvrir le fichier temporaire!!\n");
                        fclose(f44);
                return 0;
        }
        printf("\nDonnez la reference de la marchandise que vous voulez supprimer : ");
        scanf("%s", ch1);

        while (!feof(f4))//copier tout le contenu du fichier original vers le fichier temporaire sauf la ligne a
        {
            strcpy(str, "\0");
            fgets(str, MAX, f4);
            if (!feof(f4))
            {
                ctr++;

                if (!strstr(str,ch1))
                {
                    fprintf(f44, "%s", str);
                }
            }
        }
        fclose(f4);
        fclose(f44);
        remove("marchandise.txt");  		// supprimer le fichier original
        rename(temp, "marchandise.txt"); 	// renommer le fichier temporaire par le fichier original
        /*------lecture du fichier ----------------*/
   f4=fopen("marchandise.txt","r");
            ch=fgetc(f4);
          printf("\nle nouveau contenu du stock des marchandises est : \n");
          while(ch!=EOF)
            {
                printf("%c",ch);
                 ch=fgetc(f4);
            }
        fclose(f4);
/*-------fin de la lecture ---------------*/
        return 0;

  }


int modifier_m()
{
    st4 mp4;
    int  ctr = 0;
        char ch;
        FILE *f4, *f44;
        char str[MAX], temp[] = "temp.txt";char ch1[20];
        f4 = fopen("marchandise.txt", "r");
        if (!f4)
		{
                printf(" Impossible d'ouvrir le fichier!!\n");
                return 0;
        }
        f44 = fopen(temp, "w");
        if (!f44)
		{
                printf("Impossible d'ouvrir le fichier temporaire!!\n");
                        fclose(f44);
                return 0;
        }
        printf("\nDonnez la reference de la marchandise que vous voulez modifier : ");
        scanf("%s", ch1);

        while (!feof(f4))
        {
            strcpy(str, "\0");
            fgets(str, MAX, f4);
            if (!feof(f4))
            {
                ctr++;

                if (!strstr(str,ch1))
                {
                    fprintf(f44, "%s", str);
                }
            }
        }
        fclose(f4);
        fclose(f44);
        remove("marchandise.txt");
        rename(temp, "marchandise.txt");

     f4=fopen("marchandise.txt","a+");
     printf("\nDonnez la nouvelle reference de la marchandise: ");
    scanf("%i",&mp4.ref);
    printf("\nDonnez la novelle categorie de la marchandise: ");
    scanf("%s",mp4.cat);
    printf("\nDonnez le nouveau nom de la marchandise: ");
    scanf("%s",mp4.no);
    printf("\nDonnez le nouveau fournisseur de la marchandise: ");
    scanf("%s",mp4.f);
    printf("\nDonnez la nouvelle quantite de la marchandise en Kg: ");
    scanf("%f",&mp4.qt);
    printf("\nDonnez le nouveau prix d'achat de la marchandise en Dt: ");
    scanf("%f",&mp4.p);
    printf("\nDonnez le nouveau prix de vente de la marchandise en Dt: ");
    scanf("%f",&mp4.p);
    printf("\nDonnez la nouvelle date d'entree de la forme jj mm aa: ");
    scanf("%i  %i  %i",&mp4.de.jour,&mp4.de.mois,&mp4.de.annee);
    printf("\nDonnez la nouvelle date de sortie la forme jj mm aa: ");
    scanf("%i  %i  %i",&mp4.ds.jour,&mp4.ds.mois,&mp4.ds.annee);
    printf("\nDonnees bien saisies \n");
    fprintf(f4,"%i %s %s %s %f %f %f %i/%i/%i %i/%i/%i\n",mp4.ref,mp4.cat,mp4.no,mp4.f,mp4.qt,mp4.p,mp4.p,mp4.de.jour,mp4.de.mois,mp4.de.annee,mp4.ds.jour,mp4.ds.mois,mp4.ds.annee);/*ajout des info dans le fichier*/
    fclose(f4);
         /*------ lecture du fichier ----------------*/
   f4=fopen("marchandise.txt","r");
            ch=fgetc(f4);
          printf("\nle nouveau contenu du stock des marchandises est : \n");
          while(ch!=EOF)
            {
                printf("%c",ch);
                 ch=fgetc(f4);
            }
        fclose(f4);
/*------- fin de la lecture ---------------*/
    return 0;

}

int affiche_m()
{
    /* BUFSIZ : macro prédéfini qui correspond à la longueur max d'une ligne dans un fichier*/
    char tab[BUFSIZ]; /* tableau pour récupérer un mot saisi au clavier sur une ligne */
    char buffer[BUFSIZ]; /* tableau pour la lecture d'une ligne à partir du fichier */
    FILE *f4;
    char *p; /* pointeur pour récupérer l'adresse d'un caractère */
    f4=fopen("marchandise.txt","r");
     /* en cas d'erreurs d'ouverture */
    if(f4==NULL)
    {
        fputs("erreur à l'ouverture du fichier\n",stderr);
        return EXIT_FAILURE;
    }
    /* en cas d'ouverture réussie, saisie du mot à rechercher dans le fichier */
    puts("Voici le contenu du stock des marchandises : \n");
    /*récuparation du mot à partir du clavier */
    fgets(tab, sizeof tab, stdin);
    /* remplacement du caractère espace par le caractère 0 */
     p=strchr(tab, '\n'); if (p!=NULL) *p='\0';
    /* lecture du fichier ligne par ligne */
     while(fgets(buffer, sizeof buffer,f4))
        {
            /* remplacement des retours chariots par caractère 0 au niveau de chaque ligne lue*/
            p=strchr(buffer,'\n'); /* p : adresse du carctère de retour chariot */
            if(p!=NULL)
                { *p='\0';}
            puts(buffer);

        }

        /* fermeture du fichier */
        fclose(f4);

        return 0;


}
/***Les fonctions des clients***/

void Ajout_cl()
{
    st5 mp5;
    FILE *f5;
    f5=fopen("clients.txt","a");/*ouverture du fichier en mode ajout*/
    printf("Ajoutez un client\n");
    printf("\nDonnez la reference du client: ");
    scanf("%i",&mp5.ref);
    printf("\nDonnez le telephone du client: ");
    scanf("%i",&mp5.tel);
    printf("\nDonnez le nom du client: ");
    scanf("%s",mp5.no);
    printf("\nDonnez l'addresse du client: ");
    scanf("%s",mp5.ad);
    printf("\nDonnez la quantite achetee en Kg: ");
    scanf("%f",&mp5.qt);
    printf("\nDonnez le prix d'achat en Dt: ");
    scanf("%f",&mp5.pa);
    printf("\nDonnez le produit achete: ");
    scanf("%s",mp5.p);
    printf("\nDonnez la date d'achat de la forme jj mm aa: ");
    scanf("%i  %i  %i",&mp5.da.jour,&mp5.da.mois,&mp5.da.annee);
    printf("\nDonnees bien saisies \n");
    fprintf(f5,"%i %i %s %s %f %f %s %i/%i/%i \n",mp5.ref,mp5.tel,mp5.no,mp5.ad,mp5.qt,mp5.pa,mp5.p,mp5.da.jour,mp5.da.mois,mp5.da.annee);/*ajout des info dans le fichier*/
    fclose(f5);
}

int supprimer_cl()
{
   int  ctr = 0;
        char ch;
        FILE *f5, *f55;
        char str[MAX], temp[] = "temp.txt";char ch1[20];
        f5 = fopen("clients.txt", "r");
        if (!f5)
		{
                printf(" Impossible d'ouvrir le fichier!!\n");
                return 0;
        }
        f55 = fopen(temp, "w"); // ouverture du fichier temporaire en mode écriture
        if (!f55)
		{
                printf("Impossible d'ouvrir le fichier temporaire!!\n");
                        fclose(f55);
                return 0;
        }
        printf("\nDonnez la reference du client que vous voulez supprimer : ");
        scanf("%s", ch1);

        while (!feof(f5))//copier tout le contenu du fichier original vers le fichier temporaire sauf la ligne a
        {
            strcpy(str, "\0");
            fgets(str, MAX, f5);
            if (!feof(f5))
            {
                ctr++;

                if (!strstr(str,ch1))
                {
                    fprintf(f55, "%s", str);
                }
            }
        }
        fclose(f5);
        fclose(f55);
        remove("clients.txt");  		// supprimer le fichier original
        rename(temp, "clients.txt"); 	// renommer le fichier temporaire par le fichier original
        /*------lecture du fichier ----------------*/
   f5=fopen("clients.txt","r");
            ch=fgetc(f5);
          printf("\nle nouveau contenu du stock des clients est : \n");
          while(ch!=EOF)
            {
                printf("%c",ch);
                 ch=fgetc(f5);
            }
        fclose(f5);
/*-------fin de la lecture ---------------*/
        return 0;

  }


int modifier_cl()
{
    st5 mp5;
    int  ctr = 0;
        char ch;
        FILE *f5, *f55;
        char str[MAX], temp[] = "temp.txt";char ch1[20];
        f5 = fopen("clients.txt", "r");
        if (!f5)
		{
                printf(" Impossible d'ouvrir le fichier!!\n");
                return 0;
        }
        f55 = fopen(temp, "w");
        if (!f55)
		{
                printf("Impossible d'ouvrir le fichier temporaire!!\n");
                        fclose(f55);
                return 0;
        }
        printf("\nDonnez la reference du client que vous voulez modifier : ");
        scanf("%s", ch1);

        while (!feof(f5))
        {
            strcpy(str, "\0");
            fgets(str, MAX, f5);
            if (!feof(f5))
            {
                ctr++;

                if (!strstr(str,ch1))
                {
                    fprintf(f55, "%s", str);
                }
            }
        }
        fclose(f5);
        fclose(f55);
        remove("clients.txt");
        rename(temp, "clients.txt");

     f5=fopen("clients.txt","a+");
      printf("\nDonnez la nouvelle reference du client: ");
    scanf("%i",&mp5.ref);
    printf("\nDonnez le nouveau telephone du client: ");
    scanf("%i",&mp5.tel);
    printf("\nDonnez le nouveau nom du client: ");
    scanf("%s",mp5.no);
    printf("\nDonnez la nouvelle addresse du client: ");
    scanf("%s",mp5.ad);
    printf("\nDonnez la nouvelle quantite achetee en Kg: ");
    scanf("%f",&mp5.qt);
    printf("\nDonnez le nouveau prix d'achat en Dt: ");
    scanf("%f",&mp5.pa);
    printf("\nDonnez le nouveau produit achete: ");
    scanf("%s",mp5.p);
    printf("\nDonnez la nouvelle date d'achat de la forme jj mm aa: ");
    scanf("%i  %i  %i",&mp5.da.jour,&mp5.da.mois,&mp5.da.annee);
    printf("\nDonnees bien saisies \n");
    fprintf(f5,"%i %i %s %s %f %f %s %i/%i/%i \n",mp5.ref,mp5.tel,mp5.no,mp5.ad,mp5.qt,mp5.pa,mp5.p,mp5.da.jour,mp5.da.mois,mp5.da.annee);/*ajout des info dans le fichier*/
    fclose(f5);
         /*------ lecture du fichier ----------------*/
   f5=fopen("clients.txt","r");
            ch=fgetc(f5);
          printf("\nle nouveau contenu du stock des clients est : \n");
          while(ch!=EOF)
            {
                printf("%c",ch);
                 ch=fgetc(f5);
            }
        fclose(f5);
/*------- fin de la lecture ---------------*/
    return 0;

}

int affiche_cl()
{
    /* BUFSIZ : macro prédéfini qui correspond à la longueur max d'une ligne dans un fichier*/
    char tab[BUFSIZ]; /* tableau pour récupérer un mot saisi au clavier sur une ligne */
    char buffer[BUFSIZ]; /* tableau pour la lecture d'une ligne à partir du fichier */
    FILE *f5;
    char *p; /* pointeur pour récupérer l'adresse d'un caractère */
    f5=fopen("clients.txt","r");
     /* en cas d'erreurs d'ouverture */
    if(f5==NULL)
    {
        fputs("erreur à l'ouverture du fichier\n",stderr);
        return EXIT_FAILURE;
    }
    /* en cas d'ouverture réussie, saisie du mot à rechercher dans le fichier */
    puts("Voici le contenu du stock des clients : \n");
    /*récuparation du mot à partir du clavier */
    fgets(tab, sizeof tab, stdin);
    /* remplacement du caractère espace par le caractère 0 */
     p=strchr(tab, '\n'); if (p!=NULL) *p='\0';
    /* lecture du fichier ligne par ligne */
     while(fgets(buffer, sizeof buffer,f5))
        {
            /* remplacement des retours chariots par caractère 0 au niveau de chaque ligne lue*/
            p=strchr(buffer,'\n'); /* p : adresse du carctère de retour chariot */
            if(p!=NULL)
                { *p='\0';}
            puts(buffer);

        }

        /* fermeture du fichier */
        fclose(f5);

        return 0;


}
/***Les fonctions des commandes***/

void Ajout_c()
{
    st6 mp6;
    FILE *f6;
    f6=fopen("commandes.txt","a");/*ouverture du fichier en mode ajout*/
    printf("Ajoutez une commande\n");
    printf("\nDonnez la reference de la commande : ");
    scanf("%i",&mp6.ref);
    printf("\nDonnez le nom du client: ");
    scanf("%s",mp6.no);
    printf("\nDonnez le produit commande: ");
    scanf("%s",mp6.p);
    printf("\nDonnez la quantite commandee en Kg: ");
    scanf("%f",&mp6.qt);
    printf("\nDonnez le prix de la commande en Dt: ");
    scanf("%f",&mp6.op);
    printf("\nDonnez la date de la commande de la forme jj mm aa: ");
    scanf("%i  %i  %i",&mp6.od.jour,&mp6.od.mois,&mp6.od.annee);
    printf("\nDonnees bien saisies \n");
    fprintf(f6,"%i %s %s %f %f %i/%i/%i\n",mp6.ref,mp6.no,mp6.p,mp6.qt,mp6.op,mp6.od.jour,mp6.od.mois,mp6.od.annee);/*ajout des info dans le fichier*/
    fclose(f6);
}

int supprimer_c()
{
   int  ctr = 0;
        char ch;
        FILE *f6, *f66;
        char str[MAX], temp[] = "temp.txt";char ch1[20];
        f6 = fopen("commandes.txt", "r");
        if (!f6)
		{
                printf(" Impossible d'ouvrir le fichier!!\n");
                return 0;
        }
        f66 = fopen(temp, "w"); // ouverture du fichier temporaire en mode écriture
        if (!f66)
		{
                printf("Impossible d'ouvrir le fichier temporaire!!\n");
                        fclose(f66);
                return 0;
        }
        printf("\nDonnez la reference de la commande que vous voulez supprimer : ");
        scanf("%s", ch1);

        while (!feof(f6))//copier tout le contenu du fichier original vers le fichier temporaire sauf la ligne a
        {
            strcpy(str, "\0");
            fgets(str, MAX, f6);
            if (!feof(f6))
            {
                ctr++;

                if (!strstr(str,ch1))
                {
                    fprintf(f66, "%s", str);
                }
            }
        }
        fclose(f6);
        fclose(f66);
        remove("commandes.txt");  		// supprimer le fichier original
        rename(temp, "commandes.txt"); 	// renommer le fichier temporaire par le fichier original
        /*------lecture du fichier ----------------*/
   f6=fopen("commandes.txt","r");
            ch=fgetc(f6);
          printf("\nle nouveau contenu du stock des commandes est : \n");
          while(ch!=EOF)
            {
                printf("%c",ch);
                 ch=fgetc(f6);
            }
        fclose(f6);
/*-------fin de la lecture ---------------*/
        return 0;

  }

int modifier_c()
{
    st6 mp6;
    int  ctr = 0;
        char ch;
        FILE *f6, *f66;
        char str[MAX], temp[] = "temp.txt";char ch1[20];
        f6 = fopen("commandes.txt", "r");
        if (!f6)
		{
                printf(" Impossible d'ouvrir le fichier!!\n");
                return 0;
        }
        f66 = fopen(temp, "w");
        if (!f66)
		{
                printf("Impossible d'ouvrir le fichier temporaire!!\n");
                        fclose(f66);
                return 0;
        }
        printf("\nDonnez la reference de la commande que vous voulez modifier : ");
        scanf("%s", ch1);

        while (!feof(f6))
        {
            strcpy(str, "\0");
            fgets(str, MAX, f6);
            if (!feof(f6))
            {
                ctr++;

                if (!strstr(str,ch1))
                {
                    fprintf(f66, "%s", str);
                }
            }
        }
        fclose(f6);
        fclose(f66);
        remove("commandes.txt");
        rename(temp, "commandes.txt");

     f6=fopen("commandes.txt","a+");
     printf("\nDonnez la nouvelle reference de la commande : ");
    scanf("%i",&mp6.ref);
    printf("\nDonnez le nouveau nom du client: ");
    scanf("%s",mp6.no);
    printf("\nDonnez le nouveau produit commande: ");
    scanf("%s",mp6.p);
    printf("\nDonnez la nouvelle quantite commandee en Kg: ");
    scanf("%f",&mp6.qt);
    printf("\nDonnez le nouveau prix de la commande en Dt: ");
    scanf("%f",&mp6.op);
    printf("\nDonnez la nouvelle date de la commande de la forme jj mm aa: ");
    scanf("%i  %i  %i",&mp6.od.jour,&mp6.od.mois,&mp6.od.annee);
    printf("\nDonnees bien saisies \n");
    fprintf(f6,"%i %s %s %f %f %i/%i/%i\n",mp6.ref,mp6.no,mp6.p,mp6.qt,mp6.op,mp6.od.jour,mp6.od.mois,mp6.od.annee);/*ajout des info dans le fichier*/
    fclose(f6);
         /*------ lecture du fichier ----------------*/
   f6=fopen("commandes.txt","r");
            ch=fgetc(f6);
          printf("\nle nouveau contenu du stock des commandes est : \n");
          while(ch!=EOF)
            {
                printf("%c",ch);
                 ch=fgetc(f6);
            }
        fclose(f6);
/*------- fin de la lecture ---------------*/
    return 0;

}


int affiche_c()
{
    /* BUFSIZ : macro prédéfini qui correspond à la longueur max d'une ligne dans un fichier*/
    char tab[BUFSIZ]; /* tableau pour récupérer un mot saisi au clavier sur une ligne */
    char buffer[BUFSIZ]; /* tableau pour la lecture d'une ligne à partir du fichier */
    FILE *f6;
    char *p; /* pointeur pour récupérer l'adresse d'un caractère */
    f6=fopen("commandes.txt","r");
     /* en cas d'erreurs d'ouverture */
    if(f6==NULL)
    {
        fputs("erreur à l'ouverture du fichier\n",stderr);
        return EXIT_FAILURE;
    }
    /* en cas d'ouverture réussie, saisie du mot à rechercher dans le fichier */
    puts("Voici le contenu du stock des commandes : \n");
    /*récuparation du mot à partir du clavier */
    fgets(tab, sizeof tab, stdin);
    /* remplacement du caractère espace par le caractère 0 */
     p=strchr(tab, '\n'); if (p!=NULL) *p='\0';
    /* lecture du fichier ligne par ligne */
     while(fgets(buffer, sizeof buffer,f6))
        {
            /* remplacement des retours chariots par caractère 0 au niveau de chaque ligne lue*/
            p=strchr(buffer,'\n'); /* p : adresse du carctère de retour chariot */
            if(p!=NULL)
                { *p='\0';}
            puts(buffer);

        }

        /* fermeture du fichier */
        fclose(f6);

        return 0;


}

void creer_fact()
{
     st7 mp7;
    FILE *f7;
    f7=fopen("factures.txt","a");/*ouverture du fichier en mode ajout*/
    printf("Creez une facture\n");
    printf("\nDonnez la reference de la facture: ");
    scanf("%i",&mp7.ref);
    printf("\nDonnez le numero de la facture : ");
    scanf("%i",&mp7.num_fac);
    printf("\nDonnez le fournisseur: ");
    scanf("%s",mp7.f);
    printf("\nDonnez le nom du client: ");
    scanf("%s",mp7.cl);
    printf("\nDonnez la quantite commandee en Kg: ");
    scanf("%f",&mp7.qt);
    printf("\nDonner le prix unitaire en Dt: ");
    scanf("%f",&mp7.p_unit);
    printf("\nDonnez le montant en Dt: ");
    scanf("%f",&mp7.mt);
    printf("\nDonnez la date de la forme jj mm aa: ");
    scanf("%i  %i  %i",&mp7.d.jour,&mp7.d.mois,&mp7.d.annee);
    printf("\nDonnees bien saisies \n");
    fprintf(f7,"%i %i %s %s %f %f %f %i/%i/%i\n",mp7.ref,mp7.num_fac,mp7.f,mp7.cl,mp7.qt,mp7.p_unit,mp7.mt,mp7.d.jour,mp7.d.mois,mp7.d.annee);/*ajout des info dans le fichier*/
    fclose(f7);
}


int modif_fact()
{
     st7 mp7;
    int  ctr = 0;
        char ch;
        FILE *f7, *f77;
        char str[MAX], temp[] = "temp.txt";char ch1[20];
        f7 = fopen("facture.txt", "r");
        if (!f7)
		{
                printf(" Impossible d'ouvrir le fichier!!\n");
                return 0;
        }
        f77 = fopen(temp, "w");
        if (!f77)
		{
                printf("Impossible d'ouvrir le fichier temporaire!!\n");
                        fclose(f77);
                return 0;
        }
        printf("\nDonnez la reference de la facture que vous voulez modifier : ");
        scanf("%s", ch1);

        while (!feof(f7))
        {
            strcpy(str, "\0");
            fgets(str, MAX, f7);
            if (!feof(f7))
            {
                ctr++;

                if (!strstr(str,ch1))
                {
                    fprintf(f77, "%s", str);
                }
            }
        }
        fclose(f7);
        fclose(f77);
        remove("facture.txt");
        rename(temp, "facture.txt");

     f7=fopen("facture.txt","a+");
      printf("\nDonnez la nouvelle reference de la facture: ");
    scanf("%i",&mp7.ref);
    printf("\nDonnez le nouveau numero de la facture : ");
    scanf("%i",&mp7.num_fac);
    printf("\nDonnez le nouveau fournisseur: ");
    scanf("%s",mp7.f);
    printf("\nDonnez le nouveau nom du client: ");
    scanf("%s",mp7.cl);
    printf("\nDonnez la nouvelle quantite commandee en Kg: ");
    scanf("%f",&mp7.qt);
    printf("\nDonner le nouveau prix unitaire en Dt: ");
    scanf("%f",&mp7.p_unit);
    printf("\nDonnez le nouveau montant en Dt: ");
    scanf("%f",&mp7.mt);
    printf("\nDonnez la nouvelle date de la forme jj mm aa: ");
    scanf("%i  %i  %i",&mp7.d.jour,&mp7.d.mois,&mp7.d.annee);
    printf("\nDonnees bien saisies \n");
    fprintf(f7,"%i %i %s %s %f %f %f %i/%i/%i\n",mp7.ref,mp7.num_fac,mp7.f,mp7.cl,mp7.qt,mp7.p_unit,mp7.mt,mp7.d.jour,mp7.d.mois,mp7.d.annee);/*ajout des info dans le fichier*/
    fclose(f7);
         /*------ lecture du fichier ----------------*/
   f7=fopen("facture.txt","r");
            ch=fgetc(f7);
          printf("\nle nouveau contenu du stock des factures est : \n");
          while(ch!=EOF)
            {
                printf("%c",ch);
                 ch=fgetc(f7);
            }
        fclose(f7);
/*------- fin de la lecture ---------------*/
    return 0;


}

int supp_fact()
{
     int  ctr = 0;
        char ch;
        FILE *f7, *f77;
        char str[MAX], temp[] = "temp.txt";char ch1[20];
        f7 = fopen("facture.txt", "r");
        if (!f7)
		{
                printf(" Impossible d'ouvrir le fichier!!\n");
                return 0;
        }
        f77 = fopen(temp, "w"); // ouverture du fichier temporaire en mode écriture
        if (!f77)
		{
                printf("Impossible d'ouvrir le fichier temporaire!!\n");
                        fclose(f77);
                return 0;
        }
        printf("\nDonnez la reference de la facture que vous voulez supprimer : ");
        scanf("%s", ch1);

        while (!feof(f7))//copier tout le contenu du fichier original vers le fichier temporaire sauf la ligne a
        {
            strcpy(str, "\0");
            fgets(str, MAX, f7);
            if (!feof(f7))
            {
                ctr++;

                if (!strstr(str,ch1))
                {
                    fprintf(f77, "%s", str);
                }
            }
        }
        fclose(f7);
        fclose(f77);
        remove("facture.txt");  		// supprimer le fichier original
        rename(temp, "facture.txt"); 	// renommer le fichier temporaire par le fichier original
        /*------lecture du fichier ----------------*/
   f7=fopen("facture.txt","r");
            ch=fgetc(f7);
          printf("\nle nouveau contenu du stock des factures est : \n");
          while(ch!=EOF)
            {
                printf("%c",ch);
                 ch=fgetc(f7);
            }
        fclose(f7);
/*-------fin de la lecture ---------------*/
    return 0;
}

int affiche_fact()
{
    /* BUFSIZ : macro prédéfini qui correspond à la longueur max d'une ligne dans un fichier*/
    char tab[BUFSIZ]; /* tableau pour récupérer un mot saisi au clavier sur une ligne */
    char buffer[BUFSIZ]; /* tableau pour la lecture d'une ligne à partir du fichier */
    FILE *f7;
    char *p; /* pointeur pour récupérer l'adresse d'un caractère */
    f7=fopen("facture.txt","r");
     /* en cas d'erreurs d'ouverture */
    if(f7==NULL)
    {
        fputs("erreur à l'ouverture du fichier\n",stderr);
        return EXIT_FAILURE;
    }
    /* en cas d'ouverture réussie, saisie du mot à rechercher dans le fichier */
    puts("Voici le contenu du stock des factures : \n");
    /*récuparation du mot à partir du clavier */
    fgets(tab, sizeof tab, stdin);
    /* remplacement du caractère espace par le caractère 0 */
     p=strchr(tab, '\n'); if (p!=NULL) *p='\0';
    /* lecture du fichier ligne par ligne */
     while(fgets(buffer, sizeof buffer,f7))
        {
            /* remplacement des retours chariots par caractère 0 au niveau de chaque ligne lue*/
            p=strchr(buffer,'\n'); /* p : adresse du carctère de retour chariot */
            if(p!=NULL)
                { *p='\0';}
            puts(buffer);

        }

        /* fermeture du fichier */
        fclose(f7);

        return 0;


}

/*******Fonction des couleurs*******/

void Color(int couleurDuTexte,int couleurDeFond) // fonction d'affichage de couleurs
{
        HANDLE H=GetStdHandle(STD_OUTPUT_HANDLE);
        SetConsoleTextAttribute(H,couleurDeFond*16+couleurDuTexte);
}



int main()
{

     char ch[10];
     do
     {
         Color(11,0);
         printf("Donnez le mot de passe ");
         printf("\n**********************\n");
         scanf("%s",ch);
     }
     while((ch[0]!='b')||(ch[1]!='i')||(ch[2]!='e')||(ch[3]!='n')||(ch[4]!='v')||(ch[5]!='e')||(ch[6]!='n')||(ch[7]!='u')||(ch[8]!='e'));

     system("cls");


         int choix_menu,choix1,choix2,choix3,choix4,choix5,choix6;
         Color(3,0);

         printf("***********************************************************************************************************************\n");
         printf("*           _ _ _ _ _   _ _ _ _   _ _ _ _   _ _ _ _ _   _ _ _ _ _   _ _ _ _ _   _ _ _   _                             *\n");
         printf("*          | _ _  _ _| |  _ _ _| |  _ _ _| |_ _   _ _| |_ _   _ _| |  _ _ _  | |  _  | | |                            *\n");
         printf("*          | |  _ _ _  | |_ _ _  | |_ _ _      | |         | |     | |     | | | | | | | |                            *\n");
         printf("*          | | |_ _  | |  _ _ _| |_ _ _  |     | |         | |     | |     | | | | | | | |                            *\n");
         printf("*          | |_ _ _| | | |_ _ _   _ _ _| |     | |      _ _| |_ _  | |_ _ _| | | | | |_| |                            *\n");
         printf("*          |_ _ _ _ _| |_ _ _ _| |_ _ _ _|     |_|     |_ _ _ _ _| |_ _ _ _ _| |_| |_ _ _|                            *\n");
         printf("*                                                                                                                     *\n");
         printf("*                                              _ _ _ _    _ _ _ _                                                     *\n");
         printf("*                                             |  _ _  |  |  _ _ _|                                                    *\n");
         printf("*                                             | |   | |  | |_ _ _                                                     *\n");
         printf("*                                             | |   | |  |  _ _ _|                                                    *\n");
         printf("*                                             | |_ _/ |  | |_ _ _                                                     *\n");
         printf("*                                             |_ _ _ _/  |_ _ _ _|                                                    *\n");
         printf("*                                                                                                                     *\n");
         printf("*                                                         _ _ _ _   _ _ _ _ _   _ _ _ _ _   _ _ _ _   _    _          *\n");
         printf("*                                                        |  _ _ _| |_ _   _ _| |  _ _ _  | |  _ _ _| | |  / /         *\n");
         printf("*                                                        | |_ _ _      | |     | |     | | | |       | |_/ /          *\n");
         printf("*                                                        |_ _ _  |     | |     | |     | | | |       |  _ /           *\n");
         printf("*                                                         _ _ _| |     | |     | |_ _ _| | | |_ _ _  | | \\\ \\          *\n");
         printf("*                                                        |_ _ _ _|     |_|     |_ _ _ _ _| |_ _ _ _| |_|  \\\_\\         *\n");
         printf("*                                                                                                                     *\n");
         printf("***********************************************************************************************************************\n");
         Color(6,0);
         printf("\n          1:Gestion des matieres premieres\n**********\n          2:Gestion des produits en cours de fabrication\n**********\n          3:Gestion des produits finis\n**********\n          4:Gestion des marchandises\n**********\n          5:Gestion des clients\n**********\n          6:Gestion des commandes\n**********\n          7:Quitter\n\nChoisissez une option : ");
         scanf("%i",&choix_menu);
         system("cls");

         switch(choix_menu)
         {
            case 1:
                Color(3,0);
                printf("\nvous avez choisi : Gestion des matieres premieres\n");
                printf("\n**************************************************\n1:Ajouter une matiere premiere\n\n2:Supprimer une matiere premiere\n\n3:Modifier une matiere premiere\n\n4:Afficher le contenu du stock des matieres premieres\n\nchoisissez une fonction : ");
                scanf("%i",&choix1);
                system("cls");
                switch(choix1)
                {
                    case 1:
                        printf("\nVous avez choisi : Ajouter une matiere premiere\n");
                        Ajout_mp();
                        break;
                    case 2:
                        printf("\nVous avez choisi : Supprimer une matiere premiere\n");
                        supprimer_mp();
                        break;
                    case 3:
                        printf("\nVous avez choisi : Modifier une matiere premiere\n");
                        modifier_mp();
                        break;
                    case 4:
                        printf("\nVous avez choisi : Afficher le contenu du stock des matieres premieres\n");
                        affiche_mp();
                    default:
                        printf("\nchoix impossible\n");
                        break;

                }
                break;
            case 2:
                Color(4,0);
                printf("\nVous avez choisi : Gestion des produits en cours de fabrication\n");
                printf("\n****************************************************************\n1:Ajouter un produit en cours de fabrication\n\n2:Supprimer un produit en cours de fabrication\n\n3:Modifier produit en cours de fabrication\n\n4:Afficher le contenu du stock des produits en cours de fabrication\n\nChoisissez une fonction : ");
                scanf("%i",&choix2);
                system("cls");
                switch(choix2)
                {
                    case 1:
                        printf("\nVous avez choisi : Ajouter un produit en cours de fabrication\n");
                        Ajout_pc();
                        break;
                    case 2:
                        printf("\nVous avez choisi : Supprimer un produit en cours de fabrication\n");
                        supprimer_pc();
                        break;
                    case 3:
                        printf("\nVous avez choisi : Modifier un produit en cours de fabrication\n");
                        modifier_pc();
                        break;
                    case 4:
                        printf("\nVous avez choisi : Afficher le contenu du stock des produits en cours de fabrication\n");
                        affiche_pc();
                        break;
                    default:
                        printf("\nchoix impossible\n");
                        break;
                }
                break;
            case 3:
                Color(8,0);
                printf("\nVous avez choisi : Gestion des produits finis\n");
                printf("\n*******************************************\n1:Ajouter un produit fini\n\n2:Supprimer un produit fini\n\n3:Modifier un produit fini\n\n4:Afficher le contenu du stock des produits finis\n\nchoisissez une fonction : ");
                scanf("%i",&choix3);
                system("cls");
                switch(choix3)
                {
                    case 1:
                        printf("Vous avez choisi : Ajouter un produit fini\n");
                        Ajout_pf();
                        break;
                    case 2:
                        printf("Vous avez choisi : Supprimer un produit fini\n");
                        supprimer_pf();
                        break;
                    case 3:
                        printf("Vous avez choisi : Modifier un produit fini\n");
                        modifier_pf();
                        break;
                    case 4:
                        printf("Vous avez choisi : Afficher le contenu du stock des produits finis\n");
                        affiche_pf();
                        break;
                        default:
                        printf("\nchoix impossible\n");
                        break;
                }
                break;
            case 4:
                Color(11,0);
                printf("\nVous avez choisi : Gestion des marchandises\n");
                printf("\n*****************************************\n1:Ajouter une marchandise\n\n2:Supprimer une marchandise\n\n3:Modifier une marchandise\n\n4:Afficher le contenu du stock des marchandises\n\nchoisissez une fonction : ");
                scanf("%i",&choix4);
                system("cls");
                switch(choix4)
                {
                    case 1:
                        printf("Vous avez choisi : Ajouter une marchandise\n");
                        Ajout_m();
                        break;
                    case 2:
                        printf("Vous avez choisi : Supprimer une marchandise\n");
                        supprimer_m();
                        break;
                    case 3:
                        printf("Vous avez choisi : Modifier une marchandise\n");
                        modifier_m();
                        break;
                    case 4:
                        printf("Vous avez choisi : Afficher le contenu du stock des marchandises\n");
                        affiche_m();
                        break;
                    default:
                        printf("\nchoix impossible\n");
                        break;

                }
                break;
            case 5:
                Color(13,0);
                printf("\nVous avez choisi : Gestion des clients\n");
                printf("\n*************************************\n1:Ajouter un client\n\n2:Supprimer un client\n\n3:Modifier les informations d'un client\n\n4:Afficher tous les clients\n\nchoisissez une fonction : ");
                scanf("%i",&choix5);
                system("cls");
                switch(choix5)
                {
                    case 1:
                        printf("Vous avez choisi : Ajouter un client\n");
                        Ajout_cl();
                        break;
                    case 2:
                        printf("Vous avez choisi : Supprimer un client\n");
                        supprimer_cl();
                        break;
                    case 3:
                        printf("Vous avez choisi : Mofifier les informations d'un client\n");
                        modifier_cl();
                        break;
                    case 4:
                        printf("Vous avez choisi : Afficher tous les clients\n");
                        affiche_cl();
                        break;
                    default:
                        printf("\nchoix impossible\n");
                        break;

                }
                break;
            case 6:
                Color(14,0);
                printf("\nVous avez choisi : Gestion des commandes\n");
                printf("\n****************************************\n1:Ajouter une commande\n\n2:Supprimer une commande\n\n3:Modifier une commande\n\n4:Afficher toutes les commandes\n\n5:Creer une facture\n\n6:Modifier une facture\n\n7:Supprimer une facture\n\nchoisissez une fonction : ");
                scanf("%i",&choix6);
                system("cls");
                switch(choix6)
                {
                    case 1:
                        printf("Vous avez choisi : Ajouter une commande \n");
                        Ajout_c();
                        break;
                    case 2:
                        printf("Vous avez choisi : Supprimer une commande\n");
                        supprimer_c();
                        break;
                    case 3:
                        printf("Vous avez choisi : Modifier une commande\n");
                        modifier_c();
                        break;
                    case 4:
                        printf("Vous avez choisi : Afficher toutes les commandes\n");
                        affiche_c();
                        break;
                    case 5:
                        printf("Vous avez choisi : Creer une facture\n");
                        creer_fact();
                        break;
                    case 6:
                        printf("Vous avez choisi : Modifier une facture\n");
                        modif_fact();
                        break;
                    case 7:
                        printf("Vous avez choisi : Supprimer une facture\n");
                        supp_fact();
                        break;
                    default:
                        printf("\nchoix impossible\n");
                        break;
                }
                break;
            case 7:
                Color(10,0);
                printf("\nVous avez choisi : Quitter\n");
                exit(-1);
            default:
                printf("\nchoix impossible\n\n");
                break;
            }






    return 0;
}
