#include <stdio.h>
#include <string.h>

typedef struct
{
    char nom[10];
    int num_tel;
    char adrs_mail[50];
}Contact;

void Saisir(Contact ct)
{
    printf("Entrer les donnees du nouveau contact\n");
    printf("Entrer le nom du contact: ");
    scanf("%s",ct.nom);
    printf("Entrer le numero du contact: ");
    scanf("%d",&ct.num_tel);
    printf("Entrer l'adresse mail du contact: ");
    scanf("%s",ct.adrs_mail);
}

void Afficher(Contact ct)
{
    printf("Les données du contact\n");
    printf("Le nom: %s\n",ct.nom);
    printf("Le numero: %d\n",ct.num_tel);
    printf("L'adresse mail: %s\n",ct.adrs_mail);
}

typedef struct
{
    Contact ct[100];
}Repertoire;

Repertoire Initialiser_repertoire()
{
    Repertoire rep;
    return rep;
}

void Ajout_Contact(Repertoire rep,int N,Contact ct)
{
    if(N<100)
    {
        for(int i=0;i<N;i++)
        {
            if(rep.ct[i].nom<ct.nom)
            {
                for(int j=i+1;j<N;i++)
                {
                    rep.ct[j]=rep.ct[j-1];
                }
            }
            rep.ct[i]=ct;
            N++;
            break;
        }
    }
    else
        printf("repertoire sature");
}
int Rechercher_contact(Repertoire rep,int N,char nm[])
{
    for(int i=0;i<N;i++)
    {
        if(!strcmp(rep.ct[i].nom,nm))
            return i;
    }
    return -1;
}

void Supprimer_contact(Repertoire rep,int N,char nm[])
{
    int p=Rechercher_contact(rep,N,nm);
    for(int i=p;i<N-1;i++)
        rep.ct[i]=rep.ct[i+1];
    N--;
}

int main()
{
    printf("Hello world!\n");
    return 0;
}
