#include<stdio.h>
#include<windows.h>
#include<string.h>
#include<malloc.h>
#include<ctype.h>
#include <stdlib.h>
#include <conio.h>
#include<stdio.h>
#include<windows.h>
#include<string.h>
#include<malloc.h>
#include<ctype.h>
#include <stdlib.h>
#include <conio.h>
void Locate(SHORT x,SHORT y)
{
    HANDLE hmenu=GetStdHandle(STD_OUTPUT_HANDLE);
    COORD Pos;
    Pos.X = x;
    Pos.Y = y;
    SetConsoleCursorPosition(hmenu,Pos);
}

void AfficherART(int curs)
{
    Locate(3,0);
    printf("%c Ajouter Article\n\n",(curs==0)?'>':' ');
    Locate(3,2);
    printf("%c Modifier Article\n\n",(curs==1)?'>':' ');
    Locate(3,4);
    printf("%c Supprimer Article\n\n",(curs==2)?'>':' ');
    Locate(3,6);
    printf("%c Quitter\n\n",(curs==3)?'>':' ');
}
void ChoisirART()
{
    int curs = 0;
    int touche;
    do
    {
        AfficherART(curs);
        touche = _getch();
        if (touche==0xE0) // fleche : le code fleche renvoie 2 caracteres.
        {
            touche = _getch();
            if (touche==0x50 && curs==0)  // fleche bas
                curs = 1 ;


            else if (touche==0x50 && curs==1)  // fleche bas
                curs = 2;

            else if (touche==0x50 && curs==2)  // fleche bas
                curs = 3;
            else if (touche==0x48 && curs==2)  // fleche haut
                curs = 1;
            else if (touche==0x48 && curs==1)  // fleche haut
                curs = 0;
            else if (touche==0x48 && curs==3)  // fleche haut
                curs = 2;
        }
    }
    while (touche!=0x0D);    // enter
    //return ajouterclt();
}

void Afficher(int curs)
{
    Locate(3,0);
    printf("%c Gestion des articles\n\n",(curs==0)?'>':' ');
    Locate(3,2);
    printf("%c Gestion des Entrees\n\n",(curs==1)?'>':' ');
    Locate(3,4);
    printf("%c Gestion des Sorties\n\n",(curs==2)?'>':' ');
    Locate(3,6);
    printf("%c Quitter\n\n",(curs==3)?'>':' ');
}
int Choisir()
{
    int curs = 0;
    int touche;
    do
    {
        Afficher(curs);
        touche = _getch();
        if (touche==0xE0) // fleche : le code fleche renvoie 2 caracteres.
        {
            touche = _getch();
            if (touche==0x50 && curs==0)  // fleche bas
                curs = 1;


            else if (touche==0x50 && curs==1)  // fleche bas
                curs = 2;

            else if (touche==0x50 && curs==2)  // fleche bas
                curs = 3;
            else if (touche==0x48 && curs==2)  // fleche haut
                curs = 1;
            else if (touche==0x48 && curs==1)  // fleche haut
                curs = 0;
            else if (touche==0x48 && curs==3)  // fleche haut
                curs = 2;
        }
    }
    while (touche!=0x0D);    // enter
    return 0;
}

int digit(char c[])
{
    int j=0;
    while(j<strlen(c))
    {
        if(isdigit(c[j])==0)
            return(0);
        j++;
    }
    return(1);
}
int alpha (char c[] )
{
    int j=0;
    while(j<strlen(c))
    {
        if(isalpha(c[j])==0)
            return(0);
        j++;
    }
    return(1);
}
typedef struct
{
    char codd[10];
    char nomm[30];
    char adresse [30];
    char nume[8];
} fournisseur;
typedef struct
{
    char code[10];
    char nom[20];
    char description[20];
    char seuil[10];
} stock;
typedef struct
{
    char commende[10];
    char art[20];
    char date[10];
    char quantite[10];
    char dateentre[10];
} commande;
COORD coord= {0,0};
void gotoxy(int x,int y)
{
    coord.X=x;
    coord.Y=y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
}
typedef struct noeud
{
    char code[10];
    char nom[20];
    char description[20];
    char seuil[10];
    struct noeud *next;
} liste;
typedef struct noeud2
{
    char commende[10];
    char art[20];
    char date[10];
    char quantite[10];
    char dateentre[10];
    struct noeud2 * next;
} LISTE;
typedef struct noeud3
{
    char codd[10];
    char nom[30];
    char adresse [30];
    char num[8];
    struct noeud2 * next;
} Liste;
void ajouter()
{
    liste *p;
    char aj ;
    int s=0;
    char ch[10];
    FILE *at1,*at2;
    at1=fopen("farticle.txt","r");
    at2=fopen("farticle.txt","a");
    do
    {
        p=(liste*)malloc(sizeof(liste));
        printf("code-Art         [_________]");
        printf("\nDescription    [_________]");
        printf("\nNom-Art        [_________]");
        printf("\nSeuil-stock      [_________]");
        printf("\nVoulez-vous ajouter un autre O/N   [_]");
        fflush(stdin);gotoxy(22,0);
        scanf("%s",p->code);
        system("cls");
        while(!digit(p->code))
        {
            printf("code-Art         [_________]");
        printf("\nDescription    [_________]");
        printf("\nNom-Art        [_________]");
        printf("\nSeuil-stock      [_________]");
        printf("\nVoulez-vous ajouter un autre O/N   [_]");
        fflush(stdin);gotoxy(22,0);
        scanf("%s",p->code);
        system("cls");
        }
        printf("code-Art         [_____%s____]",p->code);
        printf("\nDescription    [_________]");
        printf("\nNom-Art        [_________]");
        printf("\nSeuil-stock      [_________]");
        printf("\nVoulez-vous ajouter un autre O/N   [_]");
        fflush(stdin);
        gotoxy(22,1);
        scanf("%s",p->description);system("cls");
        while(!alpha(p->description))
        {
            printf("code-Art         [_____%s____]",p->code);
        printf("\nDescription    [_________]");
        printf("\nNom-Art        [_________]");
        printf("\nSeuil-stock      [_________]");
        printf("\nVoulez-vous ajouter un autre O/N   [_]");
        fflush(stdin);
        gotoxy(22,1);
        scanf("%s",p->description);system("cls");
        }
        printf("code-Art         [_____%s____]",p->code);
        printf("\nDescription      [____%s_____]",p->description);
        printf("\nNom-Art          [_________]");
        printf("\nSeuil-stock      [_________]");
        printf("\nVoulez-vous ajouter un autre O/N   [_]");
        fflush(stdin);
        gotoxy(22,2);
        scanf("%s",p->nom);system("cls");
        while(!alpha(p->nom))
        {
            printf("code-Art         [_____%s____]",p->code);
        printf("\nDescription      [____%s_____]",p->description);
        printf("\nNom-Art          [_________]");
        printf("\nSeuil-stock      [_________]");
        printf("\nVoulez-vous ajouter un autre O/N   [_]");
        fflush(stdin);
        gotoxy(22,2);
        scanf("%s",p->nom);system("cls");
        }
        printf("code-Art         [_____%s____]",p->code);
        printf("\nDescription      [____%s_____]",p->description);
        printf("\nNom-Art          [_____%s____]",p->nom);
        printf("\nSeuil-stock      [_________]");
        printf("\nVoulez-vous ajouter un autre O/N   [_]");
        fflush(stdin);
        gotoxy(22,3);
        scanf("%s",p->seuil);system("cls");
        while(!digit(p->seuil))
        {
            printf("code-Art         [_____%s____]",p->code);
        printf("\nDescription      [____%s_____]",p->description);
        printf("\nNom-Art          [_____%s____]",p->nom);
        printf("\nSeuil-stock      [_________]");
        printf("\nVoulez-vous ajouter un autre O/N   [_]");
        fflush(stdin);
        gotoxy(22,3);
        scanf("%s",p->seuil);system("cls");
        }
        printf("code-Art         [_____%s____]",p->code);
        printf("\nDescription      [____%s_____]",p->description);
        printf("\nNom-Art          [_____%s____]",p->nom);
        printf("\nSeuil-stock      [_____%s____]",p->seuil);
        printf("\nVoulez-vous ajouter un autre O/N   [_]");
        fflush(stdin);
        gotoxy(37,4);
        scanf("%c",&aj);
        while(aj!='N'&&aj!='O')
        {
            system("cls");
            printf("code-Art         [_____%s____]",p->code);
        printf("\nDescription      [____%s_____]",p->description);
        printf("\nNom-Art          [_____%s____]",p->nom);
        printf("\nSeuil-stock      [_____%s____]",p->seuil);
        printf("\nVoulez-vous ajouter un autre O/N   [_]");
        fflush(stdin);
        gotoxy(37,4);
        scanf("%c",&aj);
        }
    }
    while(aj=='O');
    fclose(at1);
    fclose(at2);
}
liste *consteruire(FILE *p)
{
    char ch[60];
    char f[60];
    liste *first,*k,*preced=NULL;
    int i;
    first=NULL;
    while(!fgets(ch,59,p))
    {
        k=(liste *)malloc(sizeof(liste));
        for (i=0; i<10; i++)
        {
            f[0]=ch[i];
            strcat(k->code,f);
        }
        for (i=10; i<30; i++)
        {
            f[0]=ch[i];
            strcat(k->nom,f);
        }
        for (i=30; i<50; i++)
        {
            f[0]=ch[i];
            strcat(k->description,f);
        }
        for (i=50; i<60; i++)
        {
            f[0]=ch[i];
            strcat(k->seuil,f);
        }
        if (first==NULL)
            first=k;
        else
            preced->next=k;
    }
    return(k);
}
liste *consteruire3(FILE *p)
{
    char ch[79],f[60];
    liste *first,*k,*preced=NULL;
    int i;
    first=NULL;
    while(!fgets(ch,78,p))
    {
        k=(liste *)malloc(sizeof(liste));
        for (i=0; i<10; i++)
        {
            f[0]=ch[i];
            strcat(k->code,f);
        }
        for (i=10; i<40; i++)
        {
            f[0]=ch[i];
            strcat(k->nom,f);
        }
        for (i=30; i<70; i++)
        {
            f[0]=ch[i];
            strcat(k->description,f);
        }
        for (i=50; i<78; i++)
        {
            f[0]=ch[i];
            strcat(k->seuil,f);
        }
        if (first==NULL)
            first=k;
        else
            preced->next=k;
    }
    return(k);
}
void modifier()
{
    char code[10];
    FILE *fp1,*fp2;
    fp1=fopen("farticle.txt","r");
    fp2=fopen("farticle.txt","w");
    printf("code-Art         [_________]");
    scanf("%s",code);
    liste *p;
    p=consteruire(fp1);
    while(p!=NULL)
    {
        if (p->code==code)
        {
            printf("\nNom-Art          [_________]");
            printf("\nDescription      [_________]");
            printf("\nSeuil-stock      [_________]");
            gotoxy(22,1);
            scanf("%s",p->description);
            gotoxy(22,2);
            while(alpha(p->description))
            {
                gotoxy(22,2);
                scanf("%s",p->description);
            }
            scanf("%s",p->nom);
            gotoxy(22,3);
            scanf("%s",p->seuil);
        }
        while(p!=NULL)
            fprintf(fp2,"%s%s%s%s",p->code,p->nom,p->description,p->seuil);

    }
}
void suprimer()
{
    char code[10];
    FILE *fp1,*fp2;
    fp1=fopen("farticle.txt","r");
    fp2=fopen("farticle.txt","w");
    printf("code-Art         [_________]");
    scanf("%s",code);
    liste *first,*p;
    p=consteruire(fp1);
    while(p!=NULL)
    {
        if (p->code==code)
        {
            first=p;
            free(p);
            p=first;
        }

    }
    fclose(fp1);
    fclose(fp2);
}
void Gcommandeentr()
{
    LISTE *p;
    liste *k;
    char aj ;
    int s=0;
    char ch[10];
    FILE *at1,*at2,*at3,*at4;
    at1=fopen("fccomdeentre.txt","r");
    at2=fopen("fccomdeentre.txt","a");
    at3=fopen("farticle.txt","r");
    at4=fopen("farticle.txt","a");
    do
    {
        p=(LISTE*)malloc(sizeof(LISTE));
        k=(liste*)malloc(sizeof(liste));

        k=consteruire(at3);
        printf("code-Cmd            [_________]");
        printf("\ncode-Art          [_________]");
        printf("\nDate-Cmde         [_________]");
        printf("\nQte-Entree        [_________]");
        printf("\nVoulez-vous ajouter un autre O/N   [_]");
        fflush(stdin);
        gotoxy(26,0);
        scanf("%s",p->commende);
        fgets(ch,strlen(p->commende)-1,at1);
        do
        {
            s+=1;
        }
        while(strcmp(ch,p->commende));
        while((fgetc(at1)!=EOF)&&(digit(p->commende)))
        {
            gotoxy(26,0);
            scanf("%s",p->commende);
            do
            {
                s+=1;
            }
            while(strcmp(ch,p->commende));
        }
        while(p!=NULL)
        {
            gotoxy(26,1);
            scanf("%s",p->art);
            if (strcmp(p->art,k->code))
            {
                gotoxy(26,1);
                scanf("%s",p->art);
                gotoxy(26,2);
                scanf("%s",p->quantite);
                while(!digit(p->quantite))
                {
                    scanf("%s",p->quantite);
                }
                sprintf(k->seuil,"%d",atoi(k->seuil)+atoi(p->quantite));
                gotoxy(26,3);
                scanf("%s",p->dateentre);
            }
        }
        gotoxy(37,4);
        scanf("%s",&aj);
    }
    while(aj=='N');
    fclose(at1);
    fclose(at2);
    fclose(at3);
    fclose(at4);
}
void Gcommandesort()
{
    LISTE *p;
    liste *k;
    char aj ;
    int s=0;
    char ch[10];
    FILE *at1,*at2,*at3,*at4;
    at1=fopen("fcmdesortie.txt","r");
    at2=fopen("fcmdesortie.txt","a");
    at3=fopen("farticle.txt","r");
    at4=fopen("farticle.txt","a");
    do
    {
        p=(LISTE*)malloc(sizeof(LISTE));
        k=(liste*)malloc(sizeof(liste));

        k=consteruire(at3);
        printf("code-Cmd            [_________]");
        printf("\ncode-Art          [_________]");
        printf("\nDate-Cmde         [_________]");
        printf("\nQte-sortie       [_________]");
        printf("\nVoulez-vous ajouter un autre O/N   [_]");
        fflush(stdin);
        gotoxy(26,0);
        scanf("%s",p->commende);
        fgets(ch,strlen(p->commende)-1,at1);
        do
        {
            s+=1;
        }
        while(strcmp(ch,p->commende));
        while((fgetc(at1)!=EOF)&&(digit(p->commende)))
        {
            gotoxy(26,0);
            scanf("%s",p->commende);
            do
            {
                s+=1;
            }
            while(strcmp(ch,p->commende));
        }
        while(p!=NULL)
        {
            gotoxy(26,1);
            scanf("%s",p->art);
            if (strcmp(p->art,k->code))
            {
                gotoxy(26,1);
                scanf("%s",p->art);
                gotoxy(26,2);
                scanf("%s",p->quantite);
                while(!isdigit(*p->quantite))
                {
                    scanf("%s",p->quantite);
                }
                sprintf(k->seuil,"%d",atoi(k->seuil)-atoi(p->quantite));
                gotoxy(26,3);
                scanf("%s",p->dateentre);
            }
        }
        gotoxy(37,4);
        scanf("%c",&aj);
    }
    while(aj=='N');
    fclose(at1);
    fclose(at2);
    fclose(at3);
    fclose(at4);
}
LISTE *consteruire2(FILE *p)
{
    char ch[60],f[60];
    LISTE *first,*k,*preced;
    int i;
    first=NULL;
    while(!fgets(ch,59,p))
    {
        k=(LISTE *)malloc(sizeof(LISTE));
        for (i=0; i<10; i++)
        {
            f[0]=ch[i];
            strcat(k->commende,f);
        }
        for (i=10; i<30; i++)
        {
            f[0]=ch[i];
            strcat(k->art,f);
        }
        for (i=30; i<50; i++)
        {
            f[0]=ch[i];
            strcat(k->date,f);
        }
        for (i=50; i<60; i++)
        {
            f[0]=ch[i];
            strcat(k->quantite,f);
        }
        for (i=50; i<60; i++)
        {
            f[0]=ch[i];
            strcat(k->dateentre,f);
        }
        if (first==NULL)
            first=k;
        else
            preced->next=k;
        k->next=NULL;
        preced=k;
    }
    return(k);
}
void statistique()
{
    FILE *fp1;
    fp1=fopen("farticle.txt","r");
    liste *p;
    p=consteruire(fp1);
    int i,j=3;
    printf("qte de stock");
    printf("^");
    while(p)
    {
        for (i=1; i<atoi(p->seuil); i++)
        {
            gotoxy(0,i);
            printf("|");
            gotoxy(j+3,i);
            printf("[|]");
        }
        j+=6;
        p=p->next;
    }
    gotoxy(0,atoi(p->seuil));
    printf("|___");
    for(i=6; i<j; i+=6)
    {
        gotoxy(i,atoi(p->seuil));
        printf("[|]___");
        gotoxy(i,atoi(p->seuil+2));
        printf("%s",p->nom);

    }
    gotoxy(j+6,atoi(p->seuil));
    printf("> artile");
}
void ajouterfor()
{
    Liste *p;
    char aj ;
    int s=0;
    char ch[10];
    FILE *at1,*at2;
    at1=fopen("fornisseur.txt","r");
    at2=fopen("fornisseur.txt","a");
    do
    {
        p=(Liste*)malloc(sizeof(Liste));

        printf("code-fornisseur         [_________]");
        printf("\nNom-fornisseur          [_________]");
        printf("\nadresse                 [_________]");
        printf("\nnumero                  [_________]");
        printf("\nVoulez-vous ajouter un autre O/N   [_]");
        fflush(stdin);
        gotoxy(22,0);
        scanf("%s",p->codd);
        fgets(ch,strlen(p->codd)-1,at1);
        do
        {
            s+=1;
        }
        while(strcmp(ch,p->codd));
        while((fgetc(at1)!=EOF)&&(digit(p->codd)))
        {
            gotoxy(22,0);
            scanf("%s",p->codd);
            do
            {
                s+=1;
            }
            while(strcmp(ch,p->codd));
        }

        gotoxy(22,1);
        scanf("%s",p->nom);
        while(alpha(p->nom))
        {
            scanf("%s",p->nom);
        }
        gotoxy(22,2);
        scanf("%s",p->adresse);
        gotoxy(22,2);
        scanf("%s",p->num);
        while(digit(p->num))
        {
            scanf("%s",p->num);
        }
        gotoxy(37,4);
        scanf("%s",&aj);
    }
    while(aj=='N');
    fclose(at1);
    fclose(at2);
}
void modifierfor()
{
    char code[10];
    FILE *fp1,*fp2;
    fp1=fopen("fornisseur.txt","r");
    fp2=fopen("fornisseur.txt","w");
    printf("code-fornisseur         [_________]");
    scanf("%s",code);
    Liste *p;
    p=consteruire3(fp1);
    while(p!=NULL)
    {
        if (p->codd==code)
        {
            printf("\nNom-fornisseur          [_________]");
            printf("\nadresse                 [_________]");
            printf("\nnumero                  [_________]");
            gotoxy(22,1);
            scanf("%s",p->nom);
            while(alpha(p->nom))
            {
                scanf("%s",p->nom);
            }
            gotoxy(22,2);
            scanf("%s",p->adresse);
            gotoxy(22,2);
            scanf("%s",p->num);
            while(digit(p->num))
            {
                scanf("%s",p->num);
            }
        }
        while(p!=NULL)
            fprintf(fp2,"%s%s%s%s",p->codd,p->nom,p->adresse,p->num);

    }
}
void suprimerfor()
{
    char code[10];
    FILE *fp1,*fp2;
    fp1=fopen("fornisseur.txt","r");
    fp2=fopen("fornisseur.txt","w");
    printf("code-fornisseur       [_________]");
    scanf("%s",code);
    Liste *first,*p;
    p=consteruire3(fp1);
    while(p!=NULL)
    {
        if (p->codd==code)
        {
            first=p;
            free(p);
            p=first;
        }

    }
    fclose(fp1);
    fclose(fp2);
}
void ajouterclt()
{
    Liste *p;
    char aj ;
    int s=0;
    char ch[10];
    FILE *at1,*at2;
    at1=fopen("client.txt","r");
    at2=fopen("client.txt","a");
    do
    {
        p=(Liste*)malloc(sizeof(Liste));

        printf("code-client        [_________]");
        printf("\nNom-client         [_________]");
        printf("\nadresse            [_________]");
        printf("\nnumero             [_________]");
        printf("\nVoulez-vous ajouter un autre O/N   [_]");
        fflush(stdin);
        gotoxy(22,10);
        scanf("%s",p->codd);
        fgets(ch,strlen(p->codd)-1,at1);
        do
        {
            s+=1;
        }
        while(strcmp(ch,p->codd));
        while((fgetc(at1)!=EOF)&&(digit(p->codd)))
        {
            gotoxy(22,10);
            scanf("%s",p->codd);
            do
            {
                s+=1;
            }
            while(strcmp(ch,p->codd));
        }

        gotoxy(22,11);
        scanf("%s",p->nom);
        while(alpha(p->nom))
        {
            scanf("%s",p->nom);
        }
        gotoxy(22,12);
        scanf("%s",p->adresse);
        gotoxy(22,13);
        scanf("%s",p->num);
        while(digit(p->num))
        {
            scanf("%s",p->num);
        }
        gotoxy(37,14);
        scanf("%c",&aj);
    }
    while(aj=='N');
    fclose(at1);
    fclose(at2);
}
void modifierclt()
{
    char code[10];
    FILE *fp1,*fp2;
    fp1=fopen("client.txt","r");
    fp2=fopen("client.txt","w");
    printf("code-client         [_________]");
    scanf("%s",code);
    Liste *p;
    p=consteruire3(fp1);
    while(p!=NULL)
    {
        if (p->codd==code)
        {
            printf("\nNom-client          [_________]");
            printf("\nadresse                 [_________]");
            printf("\nnumero                  [_________]");
            gotoxy(22,1);
            scanf("%s",p->nom);
            while(alpha(p->nom))
            {
                scanf("%s",p->nom);
            }
            gotoxy(22,2);
            scanf("%s",p->adresse);
            gotoxy(22,2);
            scanf("%s",p->num);
            while(digit(p->num))
            {
                scanf("%s",p->num);
            }
        }
        while(p!=NULL)
            fprintf(fp2,"%s%s%s%s",p->codd,p->nom,p->adresse,p->num);

    }
}
void suprimerclt()
{
    char code[10];
    FILE *fp1,*fp2;
    fp1=fopen("client.txt","r");
    fp2=fopen("client.txt","w");
    printf("code-client       [_________]");
    scanf("%s",code);
    Liste *first,*p;
    p=consteruire3(fp1);
    while(p!=NULL)
    {
        if (p->codd==code)
        {
            first=p;
            free(p);
            p=first;
        }
    }
    fclose(fp1);
    fclose(fp2);
}
int main()
{
    int a,c,d,e,b,r;
    fflush(stdin);
    while(1)
    {
        printf("1 ===> gestion des articles\n");
        printf("2 ===> gestion des entree\n");
        printf("3 ===> gestion des sortie\n");
        printf("4 ===> quitter\n");
        printf("*********************************************\n");
        printf("entrez votre choix(1,2,3,4)\n");
        scanf("%d",&c);
        while((c<=0)||(c>4))
        {
            printf("entrez votre choix(1,2,3,4)\n");
            scanf("%d",&c);
            system("cls");
        }
        system("cls");
        switch(c)
        {
        case 6:
        {
            return 0;

        }
        case 1:
        {
            printf("1 ===> ajouter article\n");
            printf("2 ===> modifier article\n");
            printf("3 ===> supprimer article\n");
            printf("4 ===> quitter\n");
            printf("*********************************************\n");
            printf("entrez votre choix(1,2,3,4)\n");
            scanf("%d",&a);
            while((a<=0)||(a>4))
            {
                printf("entrez votre choix(1,2,3,4)\n");
                scanf("%d",&a);
                system("cls");
            }
            system("cls");
            switch(a)
            {
            case 4:
                return 0;
            case 1:
            {
                ajouter();
                break;
            }
            case 2:
            {
                modifier();
                break;
            }
            case 3:
            {
                suprimer();
                break;
            }

            }

        }
        case 2:
        {
            printf("1 ===> gestion des commandes d'entree\n");
            printf("2 ===> gestion des fornisseur\n");
            printf("3 ===> afficher statistique\n");
            printf("4 ===> quitter\n");
            printf("*********************************************\n");
            printf("entrez votre choix(1,2,3,4)\n");
            scanf("%d",&e);
            while((e<=0)||(e>4))
            {
                printf("entrez votre choix(1,2,3,4,5,6)\n");
                scanf("%d",&e);
                system("cls");
            }
            system("cls");
            switch(e)
            {
            case 4:
                return 0;
                break;
            case 1:
            {
                Gcommandeentr();
                break;
            }
            case 2:
            {
                printf("1 ===> ajouter fornisseur\n");
                printf("2 ===> modifier fornisseur\n");
                printf("3 ===> supprimer fornisseur\n");
                printf("4 ===> quitter\n");
                printf("*********************************************\n");
                printf("entrez votre choix(1,2,3,4)\n");
                scanf("%d",&d);
                while((d<=0)||(d>4))
                {
                    printf("entrez votre choix(1,2,3,4,5,6)\n");
                    scanf("%d",&d);
                    system("cls");
                }
                system("cls");
                switch(d)
                {
                case 4:
                    return 0;
                case 1:
                {
                    ajouterfor();
                    break;
                }
                case 2:
                {
                    modifierfor();
                    break;
                }
                case 3:
                {
                    suprimerfor();
                    break;
                }
                }
            }
            case 3:
            {
                statistique();
                break;
            }
            break;
            }
            case 3:
            {
                printf("1 ===> gestion des commandes d'sortie\n");
                printf("2 ===> gestion des clien\n");
                printf("3 ===> afficher statistique\n");
                printf("4 ===> quitter\n");
                printf("*********************************************\n");
                printf("entrez votre choix(1,2,3,4)\n");
                scanf("%d",&r);
                while((r<=0)||(r>4))
                {
                    printf("entrez votre choix(1,2,3,4,5,6)\n");
                    scanf("%d",&r);
                    system("cls");
                }
                system("cls");
                switch(r)
                {
                case 4:
                    return 0;
                    break;
                case 1:
                {
                    Gcommandesort();
                    break;
                }
                case 2:
                {
                    printf("1 ===> ajouter client\n");
                    printf("2 ===> modifier client\n");
                    printf("3 ===> supprimer client\n");
                    printf("4 ===> quitter\n");
                    printf("*********************************************\n");
                    printf("entrez votre choix(1,2,3,4)\n");
                    scanf("%d",&b);
                    while((b<=0)||(b>4))
                    {
                        printf("entrez votre choix(1,2,3,4,5,6)\n");
                        scanf("%d",&d);
                        system("cls");
                    }
                    switch(b)
                    {
                    case 4:
                        return 0;
                        break;
                    case 1:
                    {
                        ajouterclt();
                        break;
                    }
                    case 2:
                    {
                        modifierclt();
                        break;
                    }
                    case 3:
                    {
                        suprimerclt();
                        break;
                    }

                    }
                }
                case 3:
                {
                    statistique();
                    break;
                }
                }
            }
        }
        }
    }
}
