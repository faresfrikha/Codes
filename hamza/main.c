#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct date
{
    int jour;
    int mois;
    int annee;

} Date;
typedef struct heure
{
    int secondes ;
    int minutes ;
    int heures;

} Heure;
typedef struct auteur
{
    char nom [20];
    char prenom [20];

} Auteur ;
typedef struct articles
{

    int num ;
    char titre [20];
    Date dt;
    Auteur at;
    Heure hr;
    char categorie [20];
    char texte [255];
} Articles ;
int ajouter_article(Articles *tab_articles,int N )
{
    printf(" entrez : titre \n");
    scanf("%s",tab_articles[N].titre);

    printf(" entrez le jour :  \n");
    scanf("%d", &tab_articles[N].dt.jour);

    printf(" entrez le mois :  \n");
    scanf("%d", &tab_articles[N].dt.mois);

    printf(" entrez l annee:  \n");
    scanf("%d", &tab_articles[N].dt.annee);

    printf(" entrez l'heure :  \n");
    scanf("%d", &tab_articles[N].hr.heures);

    printf(" entrez la minutes :  \n");
    scanf("%d", &tab_articles[N].hr.minutes);

    printf(" entrez la seconde:  \n");
    scanf("%d", &tab_articles[N].hr.secondes);

    printf(" entrez le nom de l auteur:  \n");
    scanf("%s", tab_articles[N].at.nom);

    printf(" entrez le prenom auteur:  \n");
    scanf("%s", tab_articles[N].at.prenom );

    printf(" entrez categorie:  \n");
    scanf("%s", tab_articles[N].categorie);

    printf(" entrez texte:  \n");
    scanf("%s", tab_articles[N].texte);

    return N+1;
}


int rechercher(Articles tab_articles[],int N)
{
    int i ;
    char titre[50];
    printf("Entrer le  titre \n");
    scanf("%s",titre);
    for (i=0; i<N ; i++)
    {
        if (!strcmp(tab_articles[i].titre, titre ))
        {
            return i;
        }}
        printf ( " titre n'existe pas ");

    return -1;
}
void mise_a_jour(Articles *tab_articles, int N)
{
    int i, c;
    char titre[25];
    printf("introduire le titre \n " );
        scanf("%s", titre);
    for (i=0; i<N; i++)

    {
        if( !strcmp(titre,tab_articles[i].titre))
        {
            printf("\n choisie un choix :");
            printf(" choix1:titre \n , choix 2: date \n, choix3:heure \n , choix4:auteur \n , choix5:categorie \n, choix6:texte");
            //fflush(stdin);

            scanf("%d",&c);
            switch (c)
            {
            case 1 :
            {
                printf("introduire le nouveau titre \n");
                scanf("%s",tab_articles[i].titre);
                break ;
            }
            case 2 :
            {
                printf("introduire le nouveau date \n");
                scanf("%d",&tab_articles[i].dt.annee);
                scanf("%d",&tab_articles[i].dt.mois);
                scanf("%d",&tab_articles[i].dt.jour);
                break ;
            }
            case 3 :
            {
                printf("introduire le nouveau heure \n");
                scanf("%d",&tab_articles[i].hr.heures);
                scanf("%d",&tab_articles[i].hr.minutes);
                scanf("%d",&tab_articles[i].hr.secondes);
                break ;
            }
            case 4 :
                printf("introduire le nouveau auteur \n");
                scanf("%s",tab_articles[i].at.nom);
                scanf("%s",tab_articles[i].at.prenom);
                break ;
            case 5 :
            {
                printf("introduire le nouveau categorie \n");
                scanf("%s",tab_articles[i].categorie);
                break ;
            }
            case 6 :
            {
                printf("introduire le nouveau texte \n");
                scanf("%s",tab_articles[i].texte);
                break ;
            }
            default:
            {
                printf("operateur errone");
            }

            }
        }
        else
            printf("\n titre n existe pas ");


    }
}
void afficher_art(Articles tab_articles[],int N)
{
        printf(" titre: %s \n", tab_articles[N].titre);
        printf(" date: %d \n", tab_articles[N].dt.annee);
        printf(" date: %d \n", tab_articles[N].dt.mois);
        printf(" date: %d \n", tab_articles[N].dt.jour);
        printf(" heure: %d \n", tab_articles[N].hr.heures);
        printf(" heure: %d \n", tab_articles[N].hr.minutes);
        printf(" heure: %d \n", tab_articles[N].hr.secondes);
        printf(" auteur: %s \n", tab_articles[N].at.nom);
        printf(" auteur: %s \n", tab_articles[N].at.prenom);
        printf(" categorie: %s \n", tab_articles[N].categorie);
        printf(" texte: %s \n", tab_articles[N].texte);

}
void afficher_articles(Articles tab_articles[],int N)
{
    int i ;
    for (i=0; i<N ; i++)
    {
            afficher_art(tab_articles,i);
    }
}
void afficher_article(Articles tab_articles[],int N)
{
    int i ;
    char categorie [50];

    printf("Entrer la  categorie");
    scanf("%s",categorie);
    for (i=0; i<N ; i++)
    {
        if (!strcmp (tab_articles[i].categorie, categorie ))

        {
            afficher_art(tab_articles,i);
            return;
        }
    }


    printf ( " categorie n'existe pas ");


}
void supprimer_article(Articles tab_articles[],int k,int *N)

{

    int i ;

    for (i=k ; i<*N-1 ; i++)
    {
        tab_articles[i]=tab_articles[i+1] ;
    }
    *N=*N-1;
}
int compare_date ( Articles a, Articles b )
{

    if ( a.dt.annee < b.dt.annee )
        return 1 ;
    else
    {
        if ( a.dt.annee > b.dt.annee )
            return 0 ;
        else
        {
            if ( a.dt.mois < b.dt.mois )
                return 1 ;
            else
            {
                if ( a.dt.mois > b.dt.mois )
                    return 0 ;
                else
                {
                    if ( a.dt.jour < b.dt.jour )
                        return 1 ;
                    else
                    {
                        if ( a.dt.jour > b.dt.jour )
                            return 0 ;
                        else
                        {
                            printf ("egalité") ;
                            return 2 ;
                        }
                    }
                }


            }
        }
    }




    /*  int i;
    for( i=0;i<N;i++)
    {

      if (tab_articles[i]->dt.annee <tab_articles[i]->dt.annee)
      {

          return 1;
      }
      if (tab_articles[i]->dt.annee==tab_articles[i]->dt.annee)
      {
         if ( tab_articles[i]->dt.mois< tab_articles[i]->dt.mois)
      {
          return 1;
      }
      }
      if ( tab_articles[i]->dt.annee ==tab_articles[i]->dt.annee)
      {
           if ( tab_articles[i]->dt.mois== tab_articles[i]->dt.mois)
      {
           if ( tab_articles[i]->dt.jour< tab_articles[i]->dt.jour)
      {

          return 1;
      }
      }
      }
      if ( tab_articles[i]->dt.annee ==tab_articles[i]->dt.annee)
      {
           if ( tab_articles[i]->dt.mois== tab_articles[i]->dt.mois)
      {
           if ( tab_articles[i]->dt.jour ==tab_articles[i]->dt.jour)
      {
        if ( tab_articles[i]->hr.heures <tab_articles[i]->hr.heures)

         {

         return 1;
      }
      }}}
       if ( tab_articles[i]->dt.annee ==tab_articles[i]->dt.annee)
      {
           if ( tab_articles[i]->dt.mois== tab_articles[i]->dt.mois)
      {
           if ( tab_articles[i]->dt.jour ==tab_articles[i]->dt.jour)
      {
           if ( tab_articles[i]->hr.heures == tab_articles[i]->hr.heures)

      {
           if ( tab_articles[i]->hr.minutes <tab_articles[i]->hr.minutes)
      {


          return 1;
      }}}}}
      if ( tab_articles[i]->dt.annee ==tab_articles[i]->dt.annee)
      {
           if ( tab_articles[i]->dt.mois== tab_articles[i]->dt.mois)
      {
           if ( tab_articles[i]->dt.jour ==tab_articles[i]->dt.jour)
      {
           if ( tab_articles[i]->hr.heures == tab_articles[i]->hr.heures)

      {
           if ( tab_articles[i]->hr.minutes ==tab_articles[i]->hr.minutes)
      {
        if ( tab_articles[i]->hr.secondes < tab_articles[i]->hr.secondes)
          {


          return 1;
      }}}}}}
    return 0; */

}
void tri(Articles *tab_articles,int N)
{


    int i;

    for (i=1; i<N; i++)
    {
        Articles x=tab_articles[i];
        int j=i;

        while (compare_date(x,tab_articles[j-1])==1)
        {

            tab_articles[j]=tab_articles[j-1];
            j--;
        }
        tab_articles[j]=x;
    }

}

/*
    if( compare_date(tab_articles[i].dt,tab_articles[j].dt)==1)
        {for ( j=1;j<N;j++)


          x=tab_articles[i];
        tab_articles[i]=tab_articles[j];
        tab_articles[j]=x;
        }
        else if
          ( compare_Date (tab_articles[i].dt, tab_articles[j].dt)==0)
        {
            for ( j=1;j<N;j++)
        tab_articles[i]=tab_articles[i];
        tab_articles[j]=tab_articles[j];

        }
            (tab_articles[i].dt.annee==tab_articles[j].dt.annee);
}
{


        if (tab_articles[i].dt.mois <tab_articles[j].dt.mois);
            do
            {

            x=tab_articles[i].dt.mois;
        tab_articles[i].dt.mois =tab_articles[j].dt.mois;
        tab_articles[j].dt.mois=x;
            }
         while(tab_articles[i].dt.mois==tab_articles[j].dt.mois);
}
{

        if  (tab_articles[i].dt.jour <tab_articles[j].dt.jour );
            do
            {


            x=tab_articles[i].dt.jour ;
        tab_articles[i].dt.jour =tab_articles[j].dt.jour;
        tab_articles[j].dt.jour =x;
            }
         while(tab_articles[i].dt.jour==tab_articles [j].dt.jour );
}
{

            if (tab_articles [i].hr.heures <tab_articles [j].hr.heures);
            do{
            x=tab_articles [i].hr.heures ;
        tab_articles [i].hr.heures=tab_articles [j].hr.heures;
        tab_articles [j].hr.heures =x;
        }
         while(tab_articles [i].hr.heures==tab_articles [j].hr.heures);
}
{

        if (tab_articles [i].hr.minutes<tab_articles [j].hr.minutes);
            do
            {
            x=tab_articles [i].hr.minutes;
        tab_articles [i].hr.minutes=tab_articles [j].hr.minutes ;
        tab_articles [j].hr.minutes=x;
            }
         while(tab_articles [i].hr.minutes==tab_articles [j].hr.minutes );
}
{

        if (tab_articles [i].hr.secondes<tab_articles [j].hr.secondes );
            do
                {
            x=tab_articles [i].hr.secondes;
        tab_articles [i].hr.secondes=tab_articles [j].hr.secondes;
        tab_articles [j].hr.secondes =x;}
         while(tab_articles [i].hr.secondes==tab_articles [j].hr.secondes );
}
}
}*/

/*void enregistrer ( Articles tab_articles[],int N)
{
    int i ;

    FILE *fichier=fopen("ficheir_articles.txt","w");
    if (fichier == NULL)
    {
        exit(-1);
    }
        for (i=0;i<N;i++)
        {
            fprintf (fichier,"%s / %d / %d / %d / %d / %d / %d /%s /%s /%s /%s \n",tab_articles[i].titre,tab_articles[i].dt.annee,tab_articles[i].dt.mois,tab_articles[i].dt.jour,tab_articles[i].hr.heures,tab_articles[i].hr.minutes,tab_articles[i].hr.secondes,tab_articles[i].at.nom,tab_articles[i].at.prenom,tab_articles[i].categorie,tab_articles[i].texte);
        }
    fclose(fichier);*/

void enregistrer (FILE*fichier, Articles tab_articles[],int N )
{
    int i ;

    for (i=0; i<N; i++)
    {
        fprintf (fichier,"%s %d %d %d %d %d %d %s %s %s %s",tab_articles[i].titre,tab_articles[i].dt.annee,tab_articles[i].dt.mois,tab_articles[i].dt.jour,tab_articles[i].hr.heures,tab_articles[i].hr.minutes,tab_articles[i].hr.secondes,tab_articles[i].at.nom,tab_articles[i].at.prenom,tab_articles[i].categorie,tab_articles[i].texte);
        if(i<N-1)
            fprintf(fichier,"\n");
    }
}
void telecharger(FILE* fichier,Articles tab_articles[],int* N)
{
    int i=*N;
    while(!feof(fichier))
    {
        fscanf (fichier,"%s%d%d%d%d%d%d%s%s%s%s",tab_articles[i].titre,&tab_articles[i].dt.annee,
                &tab_articles[i].dt.mois,&tab_articles[i].dt.jour,&tab_articles[i].hr.heures,&tab_articles[i].hr.minutes,
                &tab_articles[i].hr.secondes,tab_articles[i].at.nom,tab_articles[i].at.prenom,tab_articles[i].categorie,tab_articles[i].texte);

        i++;
    }
    *N=i;


}


int main ()
{
    Articles tab_articles [50];
    int N=0;
    int l;
    int k;
    FILE*fichier;

    while(1)
    {


        printf ("                 ***********************************:\n ");
        printf ("                     le menu de fonction est :\n");
        printf ("                 ***********************************:\n  ");
        printf("                  \n");
        printf("                  \n");
        printf("                  \n");
        printf("                      choix 0 Télécharger l'article \n");
        printf ("                      choix 1:ajouter un article \n");
        printf ("                      choix 2 :rechecher un article selon le titre \n"  );
        printf ( "                      choix 3 :mettre a jour \n");
        printf ("                      choix 4:afficher tout les articles d une ctegorie donnee \n ");
        printf ("                     choix 5 :supprimer un article \n");
        printf ("                      choix 6 :faire le tri des articles par date et heure  \n ");
        printf ("                     choix 7 :enrigestrer dns le fichier  et quitter\n");
        printf("                  \n");
        printf("                  \n");
        printf("                  \n");
        printf ("                  *********************************** :\n ");
        printf ("                       choisir votre choix :\n       ");
        printf ("           ***********************************:\n  ");
        scanf ("%d",&l);
        switch (l)
        {
        case 0:
        {
            fichier=fopen("articles.txt","r");
            if (fichier==NULL)
                printf("\n le fichier n'existe pas");
            else
                telecharger(fichier,tab_articles,&N);

            fclose(fichier);
            afficher_articles(tab_articles,N);
            break;
        }
        case 1 :
        {
            N=ajouter_article(tab_articles,N);
            break;
        }
        case 2:
        {
            k=rechercher(tab_articles,N);
            afficher_art(tab_articles,k);
            break;
        }
        case 3:
        {
            mise_a_jour(tab_articles,N);
            break;
        }
        case 4:
        {
            afficher_article(tab_articles,N);
            break;
        }
        case 5:
        {
            k=rechercher(tab_articles,N);
            if (k==-1)
            {
                printf("\n l'article'existe pas ");
            }
            else
            {
                supprimer_article(tab_articles,k,&N);
                afficher_articles(tab_articles,N);
            }

            break ;
        }
        case 6 :
        {
            tri(tab_articles,N)  ;
            afficher_articles(tab_articles,N);
            break ;
        }
        case 7:
        {
            fichier=fopen("articles.txt","w");
            enregistrer(fichier,tab_articles,N);
            fclose(fichier);
            exit(1);
        }
        default:
            printf("choix erroné");
        }
        //fclose(fichier);
    }
    return 0 ;
}
