#include<stdio.h>
#include <string.h>
typedef struct
{
    int immatriculation;
    char marque[20];
    float prix;
} voiture;
int verif (voiture tvoiture[],int n,int imma)
{
    int i=0 ;
    while ((i<n)&&(imma!=tvoiture[i].immatriculation))
        i+=1;
    if (i==n-1)
        return(0);
    else
        return(1);
}
int saisie (voiture Tvoiture[],int anciennombre)
{
    int imma;
    int i=anciennombre;
    int a;
    do
    {
        printf("donner l immatriculation n: %d  ",i);
        scanf("%d",&imma);
        while(!verif(Tvoiture,i,imma)||imma<=0)
        {
            printf("donner l immatriculation n: %d  ",i);
            scanf("%d",&imma);
        }
        Tvoiture[i].immatriculation=imma;
        printf("\ndonner la marque");
        scanf("%s",Tvoiture[i].marque);
        printf("\ndonner le prix");
        scanf("%f",&Tvoiture[i].prix);
        printf("saisir 1 si vouz voulez continuer à remplir ou 0 si non ");
        scanf ("%d",&a);
        if (a==1)
            i++;
        else
            return(i);
    }
    while(i<100);
    return(i);
}
float valeurstock(voiture tvoiture[],int n,char marque[] )
{
    float s=0;
    int i;
    for (i=0; i<n; i++)
        if (tvoiture[i].marque==marque)
            s++;
    return(s);
}
void choixmarque (voiture tvoiture[],int n,char marque[])
{
    int i ;
    int b=1,c=1;
    for (i=0; i<n&&c; i++)
        if (!strcmp(tvoiture[i].marque,marque))
        {
            b=0;
            printf("%f, ",tvoiture[i].prix);
        }
    if (b)
        printf("marque introuvable");
}
void choixprix (voiture tvoiture[],int n,float prixinf, float prixsup)
{
    int i;
    for (i=0; i<n; i++)
    {
        if ((tvoiture[i].prix<prixinf)||(tvoiture[i].prix>prixsup))
            printf ("%s",tvoiture[i].marque);
    }
}

int main()
{
    voiture Tvoiture[100];
    int n=0;
    int m,c;
    char marq[10];
    printf("\n\t******************************************\n");
    printf("\t***********GESTION DE PARC AUTO***********\n");
    printf("\t******************************************\n");
    printf("\n\tB    I    E    N    V    E    N    U    E!\n\n\n");
    while(1)
    {
        printf("Choisir un numero pour\n");
        printf("1 ===> saisir des voitures\n");
        printf("2 ===> veriifer l'existance d'une voiture\n");
        printf("3 ===> Recherche d'une voiture d'une marque donnée\n");
        printf("4 ===> valeur de stock de voitures d'une marque donnée\n");
        printf("5 ===> recherhce des voiotures connaissant les limites inf et sup ds prix\n");
        printf("6 ===> quitter\n");
        scanf("%d",&c);
        switch(c)
        {
        case 6:
        {
            return 0;
        }
        case 1:
        {
            n=saisie(Tvoiture,n);
        }
        case 2:
        {
            printf("donner le numero du immatriculation: \n");
            scanf("%d",&m);
            if(verif(Tvoiture,n,m))
                printf("EXISTE\n");
            else
                printf("N'EXISTE PAS\n");
        }
        case 3:
        {
            choixmarque(Tvoiture,n,marq);
        }
        case 4:
        {
            do
            {
                printf("Entrer le numero de la fiche de paie: ");
                scanf("%s",num);
            }
            while(!existenum(*TabFiches,*N,num));
            Supprimer(TabFiches,N,num);
            printf("Suppression effectue avec succes.\n");
        }
        case 5:
        {
            do
            {
                printf("Entrer le mois (exemple 1 pour Janvier): ");
                scanf("%d",&m);
            }
            while(m<=0&&m>=13);
            printf("Le montant total des salaires est %f .\n",Calcul_Montant(*TabFiches,*N,m-1));
        }
        }
    }
}
