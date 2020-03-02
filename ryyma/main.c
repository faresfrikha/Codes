#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct dimensions
{
    int hauteur ;
    int largeur ;
} Dimensions;

enum type
{decor,couvert,tableau,instrument};

typedef struct meuble
{
    int code ;
    enum type Type ;
    int epoque ;
    char description [255];
    Dimensions dim ;
    float prix ;
    int vendu ;
} meub ;

int existe_code(meub tab[],int n,int ind)
{
    int i;
    for(i=0; i<n; i++)
    {
        if (ind==tab[i].code)
        {
            return 1;
        }
    }
    return 0;
}

void afficher_meuble(meub M[],int n,int i)
{
    printf(" le code est  : %d \n",M[i].code);
    switch(M[i].Type)
    {
    case 0:
    {
        printf(" le type  est  : decor \n");
        break;
    }
    case 1:
    {
        printf(" le type  est  : couvert \n");
        break;
    }
    case 2:
    {
        printf(" le type  est  : tableau \n");
        break;
    }
    case 3:
    {
        printf(" le type  est  : instrument \n");
        break;
    }
    }
    printf(" la epoque est  : %d \n",M[i].epoque);
    printf(" la description  est : %s \n",M[i].description );
    printf(" la dimention est  : %d et %d \n ",M[i].dim.hauteur,M[i].dim.largeur );
    printf(" le prix est  : %f \n ",M[i].prix);
    printf(" vendu : \n : %d \n",M[i].vendu);
}

void afficher_meubles(meub M[],int n)
{
    int i;
    for(i=0; i<n; i++)
    {
        printf(" le code est  : %d \n",M[i].code);
        switch(M[i].Type)
        {
        case 0:
        {
            printf(" le type  est  : decor \n");
            break;
        }
        case 1:
        {
            printf(" le type  est  : couvert \n");
            break;
        }
        case 2:
        {
            printf(" le type  est  : tableau \n");
            break;
        }
        case 3:
        {
            printf(" le type  est  : instrument \n");
            break;
        }
        }
        printf(" la epoque est  : %d \n",M[i].epoque);
        printf(" la description  est : %s \n",M[i].description );
        printf(" la hauteur est  : %d et la largeur est %d \n ",M[i].dim.hauteur,M[i].dim.largeur );
        printf(" le prix est  : %f \n ",M[i].prix);
        switch(M[i].vendu)
        {
        case 1:
        {
            printf("vendu");
            break;
        }
        case 0:
        {
            printf("non vendu");
            break;
        }
        }
    }
}

void Suprimer_meuble(meub M[],int *n)
{
    int i,j,num;
    do
    {
        printf("Entrer le code\n");
        scanf("%d",&num);
    }
    while(!existe_code(M,*n,num));
    for(i=0; i<*n; i++)
    {
        if(M[i].code==num)
        {
            break;
        }
    }
    for(j=i; j<*n-1; j++)
    {
        M[j]=M[j+1];
    }
    (*n)--;
    printf("Suppression effectue avec succes.\n");
}

void Ajouter_meuble(meub tab[],int *n)
{
    int t;
    printf("\n donner le code:");
    scanf("%d",&tab[*n].code);
    do
    {
        printf("\n donner le type:(exemple 0 pour decor, 1 pour couvert, 2 pour tableau, 3 pour instrument)");
        scanf("%d",&t);
    }
    while(!(t>=0&&t<=3));
    tab[*n].Type=t;
    printf("\n donner la epoque :");
    scanf("%d",&tab[*n].epoque);
    printf(" \n donner la description  :");
    scanf("%s",tab[*n].description);
    printf(" \n donner la dimention (hauteur et largeur):");
    scanf("%d",&tab[*n].dim.hauteur);
    scanf("%d",&tab[*n].dim.largeur);
    printf(("\n donner le prix :"));
    scanf("%f",&tab[*n].prix);
    printf(" \n donner si vendu (1 pour oui/ 0 pour non \n");
    scanf("%d",&tab[*n].vendu);
    (*n)++;
}

void recherche (meub tab [],int n)
{
    int i,c,p=0,ind[255];
    printf("introduire le type du meuble à rechercher:");
    printf("0==>decor ");
    printf("1==>couvert ");
    printf("2==>tableau ");
    printf("3==>instrument");
    scanf("%d",&c);
    for(i=0; i<n; i++)
    {
        if(tab[i].Type==c)
        {
            ind[p]=i;
            p++;
        }
    }
    if(p)
    {
        printf("Les meubles sont:\n");
        for(i=0; i<p; i++)
        {
            afficher_meuble(tab,n,ind[i]);
        }
    }
    else
    {
        printf("N'existe pas\n");
    }
}

void changer_meuble( meub tab[],int n )
{
    int ind,t,c;
    do
    {
        printf("Enter le code du meuble\n");
        scanf("%d",&ind);
    }
    while(!existe_code(tab,n,ind));
    printf("1: changer le type  \n") ;
    printf("2: chaner epoque \n ") ;
    printf("3: changer description \n ");
    printf("4: changer dimention  \n ");
    printf("5: changer  prix  \n ");
    printf("6: changer vendu  \n ");
    printf("entrer le choix \n");
    scanf("%d",&c);
    switch(c)
    {
    case 1 :
    {
        do
        {
            printf("\n donner le type:(exemple 0 pour decor, 1 pour couvert, 2 pour tableau, 3 pour instrument)");
            scanf("%d",&t);
        }
        while(!(t>=0&&t<=3));
        t=tab[ind].Type;
        break;
    }
    case 2 :
    {
        printf("donner la nouvelle epoque  ");
        scanf("%d",&tab[ind].epoque);
        break;
    }
    case 3 :
    {
        printf("donner la nouvelle description  ");
        scanf("%s",tab[ind].description);
        break;
    }
    case 4 :
    {
        printf("donner la nouvelle hauteur  ");
        scanf("%d",&tab[ind].dim.hauteur);
        printf("donner la nouvelle largeur  ");
        scanf("%d",&tab[ind].dim.largeur);
        break;
    }
    case 5 :
    {
        printf("donner le nouveau prix  ");
        scanf("%f",&tab[ind].prix);
        break;
    }
    case 6 :
    {
        do
        {
            printf("donner la nouvelle vendu (1 pour oui/0 pour non) ");
            scanf("%d",&tab[ind].vendu);
        }
        while(!(tab[ind].vendu==0||tab[ind].vendu==1));
        break;
    }
    default:
    {
        printf("erreur");
        break;
    }

    }
}

int main()
{
    int n=0,c;
    meub tab[50];
    while(1)
    {
        printf("Entrer une commande:\n");
        printf("1=> Chercher un meuble\n");
        printf("2=> Changer un meuble\n");
        printf("3=> Ajouter un meuble\n");
        printf("4=> Afficher un meuble\n");
        printf("5=> Suprimer un meuble\n");
        printf("0=> Enregistrer ete Sortir");
        scanf("%d",&c);
        switch(c)
        {
        case 0:
        {
            return 0;
        }
        case 1:
        {
            recherche (tab,n);
            break;
        }
        case 2:
        {
            changer_meuble(tab,n);
            break;
        }
        case 3:
        {
            Ajouter_meuble(tab,&n);
            break;
        }
        case 4:
        {
            afficher_meubles(tab,n);
            break;
        }
        case 5:
        {
            Suprimer_meuble(tab,&n);
            break;
        }
        }
    }
    return 0;
}
