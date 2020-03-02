#include<stdio.h>
#include <windows.h>
#include<string.h>
#include<stdlib.h>

COORD coord={0,0};
void gotoxy(int x, int y)
{
    coord.X=x;
    coord.Y=y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
}
typedef struct
{
    int codeclasse;
    char libelle[30];
    char specialite[30];
    int capacite;
}classe;
typedef struct
{
    int jour;
    int mois;
    int annee;
}date;
typedef struct
{
    int CIN;
    char nom[30];
    char prenom[30];
    date date_de_naissance;
    int code_classe;
}etudiant;
typedef struct
{
    int code_classe;
    int code_matiere;
    char libelle_matiere[30];
    float coefficient_matiere;
    int charge_horaire;


}matiere;
typedef struct
{
    int CIN;
    int code_matiere;
    float ds;
    float exam;
}note;
typedef struct
{
    int CIN;
    char nom[30];
    char prenom[30];
    float moyenne;
    char decision[40];
    int codeclasse;
}resultat;
int test_str_espace(char s[])
{
  int i=0;
  for(i=0;i<strlen(s);i++)
  {
     if(!(isalpha(s[i])))
     {
         return(-1);

     }
  }
  return(1);
}
int test_date(int dd,int mm,int yy)
{

    //check year
    if(yy>=1900 && yy<=9999)
    {
        //check month
        if(mm>=1 && mm<=12)
        {
            //check days
            if((dd>=1 && dd<=31) && (mm==1 || mm==3 || mm==5 || mm==7 || mm==8 || mm==10 || mm==12))
                return(1);
            else if((dd>=1 && dd<=30) && (mm==4 || mm==6 || mm==9 || mm==11))
                return(1);
            else if((dd>=1 && dd<=28) && (mm==2))
                return(1);
            else if(dd==29 && mm==2 && (yy%400==0 ||(yy%4==0 && yy%100!=0)))
                return(1);
            else
                return(-1);
        }
        else
        {
            return(-1);
        }
    }
    else
    {
        return(-1);
    }

}
int test_float(char s[])
{
  int i=0;
  for (i=0;i<strlen(s);i++)
  {
     if((isdigit(s[i])==0)&&(s[i]!='.'))
     {
         return(-1);
     }
  }
  return(1);
}

int test_int(char s[])
{
  int i=0;
  for (i=0;i<strlen(s);i++)
  {
     if(isdigit(s[i])==0)
     {
         return(-1);
     }
  }
  return(1);
}
int test_str(char s[])
{
  int i=0;
  for(i=0;i<strlen(s);i++)
  {
     if(isalpha(s[i])==0)
     {
         return(-1);

     }
  }
  return(1);
}
int nbr_etudiant(int codeclasse,etudiant tab[],int n)
{
    int i,nbr;
    for(i=0;i<n;i++)
    {
        if(tab[i].code_classe==codeclasse)
        {
            nbr++;
        }
    }
    return(nbr);
}
void affiche_mprincipal()
{
    printf("\t\t\t Application Gestion de la scolarité d un \n\t\t\t etablissement universitaire\n\n");
    printf("1-Gestion des classes\n");
    printf("2-Gestion des etudiants\n");
    printf("3-Gestion des matieres\n");
    printf("4-Gestion des notes\n");
    printf("5-Statistiques\n");
    printf("6-Quitter\n");
    printf("REPONSE: ");
}
void gestion_classes()
{
   printf("\t\t\t Gestion des classes\n\n");
   printf("1-Creation d une nouvelle classe\n");
   printf("2-Modification d une classe existante\n");
   printf("3-Supression d une classe existance\n");
   printf("4-Quitter\n");
   printf("REPONSE: ");

}
void gestion_etudiant()
{
    printf("\t\t\t Gestion des etudiants\n\n");
    printf("1-Inscription d un nouvel etudiant\n");
    printf("2-Modification d un nouvel etudiant\n");
    printf("3-Suppression d un etudiant existant\n");
    printf("4-Quitter\n");
    printf("REPONSE: ");
}
void statistique()
{
    printf("\t\t\t Statistiques des resultat\n\n");
    printf("1-Etablissement des resultats par classe\n");
    printf("2-La liste de laureats par classe\n");
    printf("3-Histogramme des resultats\n");
    printf("4-Quitter\n");
    printf("REPONSE: ");
}
int recherche_classe(classe tab[],int n,int code)
{
    int i=0;
    while((i<n))
    {
        if(tab[i].codeclasse==code)
        {
            return(i);
        }
        i++;
    }
    return(-1);
}

char ajout_classe(classe tab[],int *n)
{
    classe c;
    int code;
    char r;
    char s[30],s1[30];
    do
    {
    printf("\t\t\t Creation d une nouvelle classe\n\n");
    printf("code classe : \n");
    printf("libelle classe : \n");
    printf("specialite : \n");
    printf("capacite :\n\n");
    printf("Voulez-vous ajoutez une autre classe O/N: ");
      gotoxy(14,2);
      scanf("%s",s);
      system("cls");
      code=atoi(s);

    }while((recherche_classe(tab,*n,code)!=-1)||(test_int(s)==-1));
    c.codeclasse=code;


    do
    {
    printf("\t\t\t Creation d une nouvelle classe\n\n");
    printf("code classe : \n");
    printf("libelle classe : \n");
    printf("specialite : \n");
    printf("capacite :\n\n");
    printf("Voulez-vous ajoutez une autre classe O/N: ");
      gotoxy(14,2);
      printf("%s",s);
        gotoxy(17,3);
        scanf("%s",c.libelle);
        system("cls");
    }while(test_str(c.libelle)==-1);



      do
      {

    printf("\t\t\t Creation d une nouvelle classe\n\n");
    printf("code classe : \n");
    printf("libelle classe : \n");
    printf("specialite : \n");
    printf("capacite :\n\n");
    printf("Voulez-vous ajoutez une autre classe O/N: ");
      gotoxy(14,2);
      printf("%s",s);
        gotoxy(17,3);
        printf("%s",c.libelle);
        gotoxy(17,4);
        scanf("%s",c.specialite);
        system("cls");
      }while(test_str(c.specialite)==-1);

    do
    {

    printf("\t\t\t Creation d une nouvelle classe\n\n");
    printf("code classe : \n");
    printf("libelle classe : \n");
    printf("specialite : \n");
    printf("capacite :\n\n");
    printf("Voulez-vous ajoutez une autre classe O/N: ");
      gotoxy(14,2);
      printf("%s",s);
        gotoxy(17,3);
        printf("%s",c.libelle);
        gotoxy(17,4);
        printf("%s",c.specialite);
      gotoxy(17,5);
      scanf("%s",s1);
      c.capacite=atoi(s1);
      system("cls");
    }while(test_int(s1)==-1);
    tab[*n]=c;
    *n=*n+1;
    do
    {

    printf("\t\t\t Creation d une nouvelle classe\n\n");
    printf("code classe : \n");
    printf("libelle classe : \n");
    printf("specialite : \n");
    printf("capacite :\n\n");
    printf("Voulez-vous ajoutez une autre classe O/N: ");
      gotoxy(14,2);
      printf("%s",s);
        gotoxy(17,3);
        printf("%s",c.libelle);
        gotoxy(17,4);
        printf("%s",c.specialite);
      gotoxy(17,5);
      printf("%s",s1);
      gotoxy(42,7);
      scanf("%c",&r);
      system("cls");
    }while((r!='O')&&(r!='N'));
    return(r);

}

void modification_classe(classe tab[],int n)
{

  int code;
  int p;
  char s[30],s1[30];

  do
    {
      printf("\t\t\t Saisissez le code de la classe a modifier\n\n");
      printf("code classe : \n");
      printf("Appuyez sur ENTREE pour valider");
      gotoxy(14,2);
      scanf("%s",s);

        code=atoi(s);
        system("cls");

    }while((test_int(s)==-1)||(recherche_classe(tab,n,code)==-1));

  p=recherche_classe(tab,n,code);
  classe c;
  char r;
  system("cls");


   do
    {
  printf("\t\t\t Modification de la classe %d\n\n",code);
  printf("libelle classe : \n");
  printf("specialite : \n");
  printf("capacite :\n\n");
  printf("voulez vous confirmer la modification O/N : \n");
  gotoxy(17,2);
        scanf("%s",c.libelle);
        system("cls");
    }while(test_str(c.libelle)==-1);




    do
      {
  printf("\t\t\t Modification de la classe %d\n\n",code);
  printf("libelle classe : \n");
  printf("specialite : \n");
  printf("capacite :\n\n");
  printf("voulez vous confirmer la modification O/N : \n");
  gotoxy(17,2);
    printf("%s",c.libelle);
    gotoxy(17,3);
    scanf("%s",c.specialite);
    system("cls");
      }while(test_str(c.specialite)==-1);

    do
    {
  printf("\t\t\t Modification de la classe %d\n\n",code);
  printf("libelle classe : \n");
  printf("specialite : \n");
  printf("capacite :\n\n");
  printf("voulez vous confirmer la modification O/N : \n");
  gotoxy(17,2);
    printf("%s",c.libelle);
    gotoxy(17,3);
    printf("%s",c.specialite);
    gotoxy(17,4);
      scanf("%s",s1);
      c.capacite=atoi(s1);
      system("cls");
    }while(test_int(s1)==-1);


    do
    {
  printf("\t\t\t Modification de la classe %d\n\n",code);
  printf("libelle classe : \n");
  printf("specialite : \n");
  printf("capacite :\n\n");
  printf("voulez vous confirmer la modification O/N : \n");
  gotoxy(17,2);
    printf("%s",c.libelle);
    gotoxy(17,3);
    printf("%s",c.specialite);
    gotoxy(17,4);
    printf("%s",s1);
    gotoxy(44,6);

        scanf("%c",&r);
        system("cls");
    }while((r!='O')&&(r!='N'));
  c.codeclasse=code;
  if(r=='O')
  {
      tab[p]=c;

  }
}
void supression_classe(classe tab[],int *n)
{

   int code;
   char s[30];
   int p,i;

   do
    {
   printf("\t\tSaisissez le code de la classe a supprimer\n\n");
   printf("code classe : \n");
   printf("Appuyez sur ENTREE pour valider la suppression");
   gotoxy(14,2);
      scanf("%s",s);
      code=atoi(s);
      system("cls");

    }while((recherche_classe(tab,*n,code)==-1)||(test_int(s)==-1));
    p=recherche_classe(tab,*n,code);
    for(i=p;i<*n-1;i++)
    {
        tab[i]=tab[i+1];
    }
    *n=*n-1;

}
int recherche_etudiant(etudiant tab[],int n,int CIN)
{
    int i=0;
    while((i<n))
    {
        if(tab[i].CIN==CIN)
        {
            return(i);
        }
        i++;
    }
    return(-1);
}
char ajout_etudiant(etudiant tab[],int *n,classe tab1[],int n1)
{
    etudiant e;
    int CIN;
    char s[30],s1[30],s2[30],s3[30],s4[30];
    char r;
    do
    {
    printf("\t\t\t Inscription d'un etudiant\n\n");
    printf("Cin: \n");
    printf("Nom etudiant : \n");
    printf("Prenom etudiant : \n");
    printf("Date de naissance :           \n");
    printf("Code classe: \n\n");
    printf("Voulez-vous une autre inscription O/N : ");
      gotoxy(14,2);
      scanf("%s",s);
      system("cls");
      CIN=atoi(s);

    }while((recherche_etudiant(tab,*n,CIN)!=-1)||(test_int(s)==-1)||(strlen(s)!=8));
    e.CIN=CIN;


    do
    {
    printf("\t\t\t Inscription d'un etudiant\n\n");
    printf("Cin: \n");
    printf("Nom etudiant : \n");
    printf("Prenom etudiant : \n");
    printf("Date de naissance :           \n");
    printf("Code classe \n\n");
    printf("Voulez-vous une autre inscription O/N : ");
      gotoxy(14,2);
      printf("%s",s);
        gotoxy(17,3);
        scanf("%s",e.nom);
        system("cls");
    }while(test_str_espace(e.nom)==-1);



      do
      {

    printf("\t\t\t Inscription d'un etudiant\n\n");
    printf("Cin: \n");
    printf("Nom etudiant : \n");
    printf("Prenom etudiant : \n");
    printf("Date de naissance :           \n");
    printf("Code classe: \n\n");
    printf("Voulez-vous une autre inscription O/N : ");
      gotoxy(14,2);
      printf("%s",s);
        gotoxy(17,3);
        printf("%s",e.nom);
        gotoxy(17,4);
        scanf("%s",e.prenom);
        system("cls");
      }while(test_str_espace(e.prenom)==-1);
    do
    {
    do
    {
    printf("\t\t\t Inscription d'un etudiant\n\n");
    printf("Cin: \n");
    printf("Nom etudiant : \n");
    printf("Prenom etudiant : \n");
    printf("Date de naissance :           \n");
    printf("Code classe: \n\n");
    printf("Voulez-vous une autre inscription O/N : ");
      gotoxy(14,2);
      printf("%s",s);
        gotoxy(17,3);
        printf("%s",e.nom);
        gotoxy(17,4);
        printf("%s",e.prenom);
      gotoxy(21,5);
      scanf("%s",s2);
      system("cls");
    }while((test_int(s2)==-1)||(strlen(s2)!=2)||(atoi(s2)>31)||(atoi(s2)<1));
    e.date_de_naissance.jour=atoi(s2);
    do
    {
    printf("\t\t\t Inscription d'un etudiant\n\n");
    printf("Cin: \n");
    printf("Nom etudiant : \n");
    printf("Prenom etudiant : \n");
    printf("Date de naissance :           \n");
    printf("Code classe: \n\n");
    printf("Voulez-vous une autre inscription O/N : ");
      gotoxy(14,2);
      printf("%s",s);
        gotoxy(17,3);
        printf("%s",e.nom);
        gotoxy(17,4);
        printf("%s",e.prenom);
        gotoxy(21,5);
      printf("%s",s2);

      gotoxy(24,5);
      scanf("%s",s3);
      system("cls");
    }while((test_int(s3)==-1)||(strlen(s3)!=2)||(atoi(s3)<1)||(atoi(s3)>12));
    e.date_de_naissance.mois=atoi(s3);
    do
    {
    printf("\t\t\t Inscription d'un etudiant\n\n");
    printf("Cin: \n");
    printf("Nom etudiant : \n");
    printf("Prenom etudiant : \n");
    printf("Date de naissance :           \n");
    printf("Code classe: \n\n");
    printf("Voulez-vous une autre inscription O/N : ");
      gotoxy(14,2);
      printf("%s",s);
        gotoxy(17,3);
        printf("%s",e.nom);
        gotoxy(17,4);
        printf("%s",e.prenom);
        gotoxy(21,5);
      printf("%s",s2);

      gotoxy(24,5);
      printf("%s",s3);
      gotoxy(27,5);
      scanf("%s",s4);
      system("cls");
    }while((test_int(s4)==-1)||(strlen(s4)!=4)||(atoi(s4)<1980)||(atoi(s4)>2002));
    e.date_de_naissance.annee=atoi(s4);
    }while(test_date(e.date_de_naissance.jour,e.date_de_naissance.mois,e.date_de_naissance.annee)==-1);
    do
    {
    printf("\t\t\t Inscription d'un etudiant\n\n");
    printf("Cin: \n");
    printf("Nom etudiant : \n");
    printf("Prenom etudiant : \n");
    printf("Date de naissance :           \n");
    printf("Code classe: \n\n");
    printf("Voulez-vous une autre inscription O/N : ");
      gotoxy(14,2);
      printf("%s",s);
        gotoxy(17,3);
        printf("%s",e.nom);
        gotoxy(17,4);
        printf("%s",e.prenom);
        gotoxy(21,5);
        printf("%s",s2);
          gotoxy(24,5);
        printf("%s",s3);
          gotoxy(27,5);
        printf("%s",s4);
      gotoxy(17,6);
      scanf("%s",s1);
      e.code_classe=atoi(s1);
      system("cls");
    }while((test_int(s1)==-1)||(recherche_classe(tab1,n1,e.code_classe)==-1)||(tab1[recherche_classe(tab1,n1,e.code_classe)].capacite<=nbr_etudiant(e.code_classe,tab,*n)));
    tab[*n]=e;
    *n=*n+1;
    do
    {
    printf("\t\t\t Inscription d'un etudiant\n\n");
    printf("Cin: \n");
    printf("Nom etudiant : \n");
    printf("Prenom etudiant : \n");
    printf("Date de naissance :           \n");
    printf("Code classe: \n\n");
    printf("Voulez-vous une autre inscription O/N : ");
      gotoxy(14,2);
      printf("%s",s);
        gotoxy(17,3);
        printf("%s",e.nom);
        gotoxy(17,4);
        printf("%s",e.prenom);
        gotoxy(21,5);
        printf("%s",s2);
          gotoxy(24,5);
        printf("%s",s3);
          gotoxy(27,5);
        printf("%s",s4);
      gotoxy(17,6);
      printf("%s",s1);
    gotoxy(40,8);
    scanf("%c",&r);
      system("cls");
    }while((r!='O')&&(r!='N'));
    return(r);

}
void modification_etudiant(etudiant tab[],int n,classe tab1[],int n1)
{
  int CIN;
  int p;
  char  s[30],s1[30],s2[30],s3[30],s4[30];

  do
    {
      printf("\t\t\t Saisissez le cin de l etudiant a modifier\n\n");
      printf("Cin de letudiant : \n");
      printf("Appuyez sur ENTREE pour valider");
      gotoxy(20,2);
      scanf("%s",s);
        CIN=atoi(s);
        system("cls");
     }while((recherche_etudiant(tab,n,CIN)==-1)||(test_int(s)==-1)||(strlen(s)!=8));
  p=recherche_etudiant(tab,n,CIN);
  etudiant e;
  char r;
  system("cls");
   do
    {
        printf("\t\t\t Modification d un etudiant existant %d\n\n",CIN);
        printf("Nom etudiant : \n");
        printf("Prenom etudiant : \n");
        printf("Date de naissance :\n");
        printf("Code classe : \n");
        printf("Voulez vous confirmer la modification O/N : \n");
        gotoxy(17,2);
        scanf("%s",e.nom);
        system("cls");
     }while(test_str_espace(e.nom)==-1);
   do
      {
       printf("\t\t\t Modification d un etudiant existant %d \n\n",CIN);
       printf("Nom etudiant : \n");
       printf("Prenom etudiant : \n");
       printf("Date de naissance :\n");
       printf("Code classe : \n");
       printf("Voulez vous confirmer la modification O/N : \n");
       gotoxy(17,2);
       printf("%s",e.nom);
       gotoxy(17,3);
       scanf("%s",e.prenom);
       system("cls");
      }while(test_str_espace(e.prenom)==-1);
    do
      {
       do
        {
           printf("\t\t\t Modification dun etudiant existant %d \n\n",CIN);
           printf("Nom etudiant : \n");
           printf("Prenom etudiant : \n");
           printf("Date de naissance :\n");
           printf("Code classe : \n");
           printf("Voulez vous confirmer la modification O/N : \n");
           gotoxy(17,2);
           printf("%s",e.nom);
           gotoxy(17,3);
           printf("%s",e.prenom);
           gotoxy(21,4);
           scanf("%s",s2);
           system("cls");
    }while((test_int(s2)==-1)||(strlen(s2)!=2)||(atoi(s2)>31)||(atoi(s2)<1));
    e.date_de_naissance.jour=atoi(s2);
      do
        {
           printf("\t\t\t Modification dun etudiant existant %d \n\n",CIN);
           printf("Nom etudiant : \n");
           printf("Prenom etudiant : \n");
           printf("Date de naissance :\n");
           printf("Code classe : \n");
           printf("Voulez vous confirmer la modification O/N : \n");
           gotoxy(17,2);
           printf("%s",e.nom);
           gotoxy(17,3);
           printf("%s",e.prenom);
           gotoxy(21,4);
           printf("%s",s2);
           gotoxy(24,4);
           scanf("%s",s3);
           system("cls");
        }while((test_int(s3)==-1)||(strlen(s3)!=2)||(atoi(s3)<1)||(atoi(s3)>12));
    e.date_de_naissance.mois=atoi(s3);
     do
        {
           printf("\t\t\t Modification dun etudiant existant %d \n\n",CIN);
           printf("Nom etudiant : \n");
           printf("Prenom etudiant : \n");
           printf("Date de naissance :\n");
           printf("Code classe : \n");
           printf("Voulez vous confirmer la modification O/N : \n");
           gotoxy(17,2);
           printf("%s",e.nom);
           gotoxy(17,3);
           printf("%s",e.prenom);
           gotoxy(21,4);
           printf("%s",s2);
           gotoxy(24,4);
           printf("%s",s3);
           gotoxy(27,4);
           scanf("%s",s4);
           system("cls");
        }while((test_int(s4)==-1)||(strlen(s4)!=4)||(atoi(s4)<1980)||(atoi(s4)>2002));
       e.date_de_naissance.annee=atoi(s4);
    }while(test_date(e.date_de_naissance.jour,e.date_de_naissance.mois,e.date_de_naissance.annee)==-1);
    do
    {
      printf("\t\t\t Modification dun etudiant existant %d \n\n",CIN);
      printf("Nom etudiant : \n");
      printf("Prenom etudiant : \n");
      printf("Date de naissance :\n");
      printf("Code classe : \n");
      printf("Voulez vous confirmer la modification O/N : \n");
      gotoxy(17,2);
      printf("%s",e.nom);
      gotoxy(17,3);
      printf("%s",e.prenom);
      gotoxy(21,4);
      printf("%s",s2);
      gotoxy(24,4);
      printf("%s",s3);
      gotoxy(27,4);
      printf("%s",s4);
      gotoxy(17,5);
      scanf("%s",s1);
      e.code_classe=atoi(s1);
      system("cls");
    }while((test_int(s1)==-1)||(recherche_classe(tab1,n1,e.code_classe)==-1)||(tab1[recherche_classe(tab1,n1,e.code_classe)].capacite<=nbr_etudiant(e.code_classe,tab,n)));
do
    {
  printf("\t\t\t Modification d un etudiant existant %d\n\n",CIN);
  printf("Nom etudiant : \n");
  printf("Prenom etudiant : \n");
  printf("Date de naissance :\n");
  printf("Code classe : \n");
  printf("Voulez vous confirmer la modification O/N : \n");
  gotoxy(17,2);
  printf("%s",e.nom);
    gotoxy(17,3);
    printf("%s",e.prenom);
      gotoxy(21,4);
      printf("%s",s2);
      gotoxy(24,4);
      printf("%s",s3);
      gotoxy(27,4);
     printf("%s",s4);
     gotoxy(17,5);
     printf("%s",s1);
    gotoxy(44,6);
        scanf("%c",&r);
        system("cls");
    }while((r!='O')&&(r!='N'));
  e.CIN=CIN;
  if(r=='O')
  {
      tab[p]=e;
  }
}
void supression_etudiant(etudiant tab[],int *n)
{

   int code, CIN;
   char s[30];
   int p,i;

   do
    {
   printf("\t\tSaisissez le numero de cin  de l etudiant a supprimer\n\n");
   printf("CIN : \n");
   printf("Appuyez sur ENTREE pour valider la suppression");
   gotoxy(14,2);
      scanf("%s",s);
      CIN=atoi(s);
      system("cls");

    }while((recherche_etudiant(tab,*n,CIN)==-1)||(test_int(s)==-1));
    p=recherche_etudiant(tab,*n,CIN);
    for(i=p;i<*n-1;i++)
    {
        tab[i]=tab[i+1];
    }
    *n=*n-1;

}
int recherche_matiere(matiere tab[],int n,int code)
{
    int i=0;
    while((i<n))
    {
        if(tab[i].code_matiere==code)
        {
            return(i);
        }
        i++;
    }
    return(-1);
}
char ajout_matiere(classe tab[],int n,matiere tab1[],int *n1)
{
    char s[30],s1[30],s2[30],s3[30];
    int code,codematiere;
    char r;
    matiere m;
    do
    {
      printf("\t\t\t Saisissez le code de la classe \n\t\t\tPour Attribuer les matires enseignees\n\n");
      printf("code classe : \n");
      printf("Appuyez sur ENTREE pour valider");
      gotoxy(14,3);
      scanf("%s",s);

        code=atoi(s);
        system("cls");

    }while((test_int(s)==-1)||(recherche_classe(tab,n,code)==-1));
    m.code_classe=code;
    do
    {
        do
        {
        printf("\t\t\tAttribution des matieres\n\t\t\tpour la classe %d\n\n",code);
        printf("Code matiere : \n");
        printf("Libellé matiere : \n");
        printf("Coefficient : \n");
        printf("Charge horaire : \n");
        printf("Voulez-vous ajouter une autre matiere O/N:");
        gotoxy(16,3);
        scanf("%s",s1);
        m.code_matiere=atoi(s1);
        system("cls");
        }while((test_int(s1)==-1)||(recherche_matiere(tab1,*n1,m.code_matiere)!=-1));
        do
        {
        printf("\t\t\tAttribution des matieres\n\t\t\tpour la classe %d\n\n",code);
        printf("Code matiere : \n");
        printf("Libellé matiere : \n");
        printf("Coefficient : \n");
        printf("Charge horaire : \n");
        printf("Voulez-vous ajouter une autre matiere O/N:");
        gotoxy(16,3);
        printf("%s",s1);
        gotoxy(18,4);
        scanf("%s",m.libelle_matiere);
        system("cls");

        }while((test_str(m.libelle_matiere)==-1));
        do
        {
        printf("\t\t\tAttribution des matieres\n\t\t\tpour la classe %d\n\n",code);
        printf("Code matiere : \n");
        printf("Libellé matiere : \n");
        printf("Coefficient : \n");
        printf("Charge horaire : \n");
        printf("Voulez-vous ajouter une autre matiere O/N:");
        gotoxy(16,3);
        printf("%s",s1);
        gotoxy(18,4);
        printf("%s",m.libelle_matiere);
        gotoxy(14,5);
        scanf("%s",s2);
        m.coefficient_matiere=atof(s2);
        system("cls");

        }while((m.coefficient_matiere<0)||test_float(s2)==-1);
        do
        {
        printf("\t\t\tAttribution des matieres\n\t\t\tpour la classe %d\n\n",code);
        printf("Code matiere : \n");
        printf("Libellé matiere : \n");
        printf("Coefficient : \n");
        printf("Charge horaire : \n");
        printf("Voulez-vous ajouter une autre matiere O/N:");
        gotoxy(16,3);
        printf("%s",s1);
        gotoxy(18,4);
        printf("%s",m.libelle_matiere);
        gotoxy(14,5);
        printf("%s",s2);
        gotoxy(17,6);
        scanf("%s",s3);
        m.charge_horaire=atoi(s3);
        system("cls");

        }while((m.charge_horaire<0)||test_int(s3)==-1);
        tab1[*n1]=m;
        *n1=*n1+1;

        do
        {
        printf("\t\t\tAttribution des matieres\n\t\t\tpour la classe %d\n\n",code);
        printf("Code matiere : \n");
        printf("Libellé matiere : \n");
        printf("Coefficient : \n");
        printf("Charge horaire : \n");
        printf("Voulez-vous ajouter une autre matiere O/N:");
        gotoxy(16,3);
        printf("%s",s1);
        gotoxy(18,4);
        printf("%s",m.libelle_matiere);
        gotoxy(14,5);
        printf("%s",s2);
        gotoxy(17,6);
        printf("%s",s3);
        gotoxy(46,7);
        scanf("%c",&r);
        system("cls");

        }while((r!='O')&&(r!='N'));
        system("cls");


    }while((r=='O'));
    return(r);


}
char ajout_note(note tab[],int *n,classe tab1[],int n1,matiere tab2[],int n2,etudiant tab3[],int n3)
{
    char s[30],s1[30],s2[30],s3[30];
    int codeclasse,codematiere;
    int i,j,k,l=0,na;
    char r;
    do
    {
    printf("\t\t\tSaisissez le code de la classe\n\t\t\tPour laquelle vous allez affecter des notes\n\n");
    printf("Code classe : \n");
    printf("Appuyez sur ENTRER pour valider");
    gotoxy(15,3);
    scanf("%s",s);
    codeclasse=atoi(s);
    system("cls");
    }while((recherche_classe(tab1,n1,codeclasse)==-1)||(test_int(s)==-1));
    do
    {
    do
    {
        printf("\t\t\tSaisissez le code de la matiere\n\t\t\tdont les notes seront affectees\n\t\t\taux etudiants de la classe %d\n\n",codeclasse);
        printf("Code matiere : \n");
        printf("Appuyez sur ENTRER pour valider");
        gotoxy(16,4);
        scanf("%s",s1);
        codematiere=atoi(s1);
        system("cls");
    }while((recherche_matiere(tab2,n2,codematiere)==-1)||(test_int(s1)==-1)||(tab2[recherche_matiere(tab2,n2,codematiere)].code_classe!=codeclasse));
    na=*n;
    for(i=0;i<n3;i++)
    {
      if(tab3[i].code_classe==codeclasse)
      {
       tab[*n].CIN=tab3[i].CIN;
       tab[*n].code_matiere=codematiere;
       (*n)++;

      }
    }
    for (j=na;j<*n;j++)
    {
    do
    {

    printf("\t\t\tAffectation des notes de la matiere %d\n\t\t\t\tpour la classe %d\n\n",codematiere,codeclasse);
    printf("   CIN      Nom    Prenom    note DS  note Examen\n\n");
    l=0;
    for(i=0;i<n3;i++)
    {

         if(tab3[i].code_classe==codeclasse)
        {
            gotoxy(0,7+l);
            printf("%d",tab3[i].CIN);
            gotoxy(9,7+l);
            printf("%s",tab3[i].nom);
            gotoxy(18,7+l);
            printf("%s",tab3[i].prenom);
            l++;
        }


    }
    gotoxy(0,7+*n+1);
    printf("Voulez-vous affecter des notes pour une autre matiere O/N: ");

    for(k=na;k<j;k++)
    {
        gotoxy(29,7+k-na);
        printf("%f",tab[k].ds);
        gotoxy(38,7+k-na);
        printf("%f",tab[k].exam);
    }
    gotoxy(29,7+j-na);
    scanf("%s",s2);
    tab[j].ds=atof(s2);
    system("cls");
    }while((tab[j].ds<0)||(tab[j].ds>20)||(test_float(s2)==-1));
    do
    {

    printf("\t\t\tAffectation des notes de la matiere %d\n\t\t\t\tpour la classe %d\n\n",codematiere,codeclasse);
    printf("   CIN      Nom    Prenom    note DS  note Examen\n\n");
    l=0;
    for(i=0;i<n3;i++)
    {

         if(tab3[i].code_classe==codeclasse)
        {
            gotoxy(0,7+l);
            printf("%d",tab3[i].CIN);
            gotoxy(9,7+l);
            printf("%s",tab3[i].nom);
            gotoxy(18,7+l);
            printf("%s",tab3[i].prenom);
            l++;
        }


    }
    gotoxy(0,7+*n+1);
    printf("Voulez-vous affecter des notes pour une autre matiere O/N: ");

    for(k=na;k<j;k++)
    {
        gotoxy(29,7+k-na);
        printf("%f",tab[k].ds);
        gotoxy(38,7+k-na);
        printf("%f",tab[k].exam);
    }
    gotoxy(29,7+j-na);
    printf("%s",s2);
    gotoxy(38,7+j-na);
    scanf("%s",s3);
    tab[j].exam=atof(s3);
    system("cls");
    }while((tab[j].exam<0)||(tab[j].exam>20)||(test_float(s3)==-1));
    }


    do
    {
    printf("\t\t\tAffectation des notes de la matiere %d\n\t\t\t\tpour la classe %d\n\n",codematiere,codeclasse);
    printf("   CIN      Nom    Prenom    note DS  note Examen\n\n");
    l=0;
    for(i=0;i<n3;i++)
    {

         if(tab3[i].code_classe==codeclasse)
        {
            gotoxy(0,7+l);
            printf("%d",tab3[i].CIN);
            gotoxy(9,7+l);
            printf("%s",tab3[i].nom);
            gotoxy(18,7+l);
            printf("%s",tab3[i].prenom);
            l++;
        }


    }
    gotoxy(0,7+*n+1);
    printf("Voulez-vous affecter des notes pour une autre matiere O/N: ");
    for(k=na;k<*n;k++)
    {
        gotoxy(29,7+k-na);
        printf("%f",tab[k].ds);
        gotoxy(38,7+k-na);
        printf("%f",tab[k].exam);
    }
    gotoxy(63,7+*n+1);
    scanf("%c",&r);
    system("cls");
    }while((r!='O')&&(r!='N'));
    }while(r=='O');
    return(r);
}
float moyenne_matiere(float ds,float exam)
{
    return(0.6*exam+0.4*ds);
}
float coef_matiere(int codematiere,matiere tab[],int n)
{
    int i;
    for(i=0;i<n;i++)
    {
        if(tab[i].code_matiere==codematiere)
        {
            return(tab[i].coefficient_matiere);
        }
    }
}
float moyenne_general(int CIN,int codeclasse, note tab[],int n,matiere tab1[],int n1)
{
    int coeftot=0,i,j,k;
    float s=0;
    for(i=0;i<n1;i++)
    {
      if(tab1[i].code_classe==codeclasse)
      {
          coeftot=coeftot+tab1[i].coefficient_matiere;
      }
    }

    for(j=0;j<n;j++)
    {
        if(tab[j].CIN==CIN)
        {

            s=s+coef_matiere(tab[j].code_matiere,tab1,n1)*moyenne_matiere(tab[j].ds,tab[j].exam);

        }
    }
    return(s/coeftot);



}

void tri(resultat tab[],int n)
{
    int permute,i;
    resultat x;
    do
    {
        permute=0;
        for (i=0;i<n-1;i++)
        {
          if (tab[i].moyenne<tab[i+1].moyenne)
          {
              permute=1;
              x=tab[i];
              tab[i]=tab[i+1];
              tab[i+1]=x;

          }
        }
    }while(permute==1);

}
char resultat_classe(classe tab4[],int n4,note tab1[],int n1,etudiant tab2[],int n2,matiere tab3[],int n3)
{
    char s[30];
    int codeclasse;
    int i,j;
    resultat tab[30];
    int n;
    char r;
  do
  {
      n=0;
  do
    {
    printf("\t\t\tSaisissez le code de la classe\n\n");
    printf("Code classe : \n");
    printf("Appuyez sur ENTRER pour valider");
    gotoxy(15,2);
    scanf("%s",s);
    codeclasse=atoi(s);
    system("cls");
    }while((recherche_classe(tab4,n4,codeclasse)==-1)||(test_int(s)==-1));
    for(i=0;i<n2;i++)
    {

      if(tab2[i].code_classe==codeclasse)
      {
         tab[n].CIN=tab2[i].CIN;
         strcpy(tab[n].nom,tab2[i].nom);
         strcpy(tab[n].prenom,tab2[i].prenom);
         tab[n].moyenne=moyenne_general(tab2[i].CIN,codeclasse,tab1,n1,tab3,n3);
         if (tab[n].moyenne<10)
    {
         strcpy(tab[n].decision,"Redouble") ;
    }
    else if((tab[n].moyenne<13)&&(tab[n].moyenne>=10))
    {
         strcpy(tab[n].decision,"Admis Assez bien");
    }
    else if((tab[n].moyenne<15)&&(tab[n].moyenne>=13))
    {
          strcpy(tab[n].decision,"Admis  bien");
    }
    else if (tab[n].moyenne>=15)
    {
          strcpy(tab[n].decision,"Admis tres bien");
    }

         n++;

      }
    }
    tri(tab,n);
    do
    {

    printf("\t\t\tEtablissement des resultats de\t\tdela classe %d par ordre de merite\n\n",codeclasse);
    printf("   CIN      Nom    Prenom    Moyenne  Decision\n\n");
    for(j=0;j<n;j++)
    {
            gotoxy(0,7+j);
            printf("%d",tab[j].CIN);
            gotoxy(9,7+j);
            printf("%s",tab[j].nom);
            gotoxy(18,7+j);
            printf("%s",tab[j].prenom);
            gotoxy(29,7+j);
            printf("%f",tab[j].moyenne);
            gotoxy(38,7+j);
            printf("%s",tab[j].decision);

    }
    gotoxy(0,7+n+1);
    printf("Voulez-vous voir les resultat d une autre classe O/N: ");
    gotoxy(56,7+n+1);
    scanf("%c",&r);
    system("cls");
    }while((r!='O')&&(r!='N'));
  }while(r=='O');
  return(r);

}
char liste_laureats(classe tab4[],int n4,note tab1[],int n1,etudiant tab2[],int n2,matiere tab3[],int n3)
{
   int i,n,j;
   char r;
   resultat tab[30];
   do
   {
   printf("\t\t\tLa liste des laureats par classe\n\n\n");
   printf("   CIN      Nom    Prenom    Classe  Moyenne Decision\n\n");
   for(i=0;i<n4;i++)
   {
       n=0;
      for(j=0;j<n2;j++)
    {
      if(tab2[j].code_classe==tab4[i].codeclasse)
      {
         tab[n].CIN=tab2[j].CIN;
         tab[n].codeclasse=tab2[j].code_classe;
         strcpy(tab[n].nom,tab2[j].nom);
         strcpy(tab[n].prenom,tab2[j].prenom);
         tab[n].moyenne=moyenne_general(tab2[j].CIN,tab4[i].codeclasse,tab1,n1,tab3,n3);
         if (tab[n].moyenne<10)
    {
         strcpy(tab[n].decision,"Redouble") ;
    }
    else if((tab[n].moyenne<13)&&(tab[n].moyenne>=10))
    {
         strcpy(tab[n].decision,"Admis Assez bien");
    }
    else if((tab[n].moyenne<15)&&(tab[n].moyenne>=13))
    {
          strcpy(tab[n].decision,"Admis  bien");
    }
    else if (tab[n].moyenne>=15)
    {
          strcpy(tab[n].decision,"Admis tres bien");
    }
         n++;

      }
    }
    tri(tab,n);
            gotoxy(0,7+i);
            printf("%d",tab[0].CIN);
            gotoxy(9,7+i);
            printf("%s",tab[0].nom);
            gotoxy(18,7+i);
            printf("%s",tab[0].prenom);
            gotoxy(29,7+i);
            printf("%d",tab[0].codeclasse);
            gotoxy(38,7+i);
            printf("%f",tab[0].moyenne);
            gotoxy(47,7+i);
            printf("%s\n",tab[0].decision);

   }
   printf("Appuyez sur R pour retourner");
   scanf("%c",&r);
   system("cls");
   }while(r!='R');
   return(r);

}
int nbr_admis(int codeclasse,note tab1[],int n1,etudiant tab2[],int n2,matiere tab3[],int n3)
{
    int n=0,nbradm,i,j;
    resultat tab[30];
    for(i=0;i<n2;i++)
    {
      if(tab2[i].code_classe==codeclasse)
      {
         tab[n].CIN=tab2[i].CIN;
         strcpy(tab[n].nom,tab2[i].nom);
         strcpy(tab[n].prenom,tab2[i].prenom);
         tab[n].moyenne=moyenne_general(tab2[i].CIN,codeclasse,tab1,n1,tab3,n3);
         if (tab[n].moyenne<10)
    {
         strcpy(tab[n].decision,"Redouble") ;
    }
    else if((tab[n].moyenne<13)&&(tab[n].moyenne>=10))
    {
         strcpy(tab[n].decision,"Admis Assez bien");
    }
    else if((tab[n].moyenne<15)&&(tab[n].moyenne>=13))
    {
          strcpy(tab[n].decision,"Admis  bien");
    }
    else if (tab[n].moyenne>=15)
    {
          strcpy(tab[n].decision,"Admis tres bien");
    }
         n++;

      }
    }
    nbradm=n;
    for(j=0;j<n;j++)
    {
        if(strcmp(tab[j].decision,"Redouble")==0)
        {
            nbradm--;
        }
    }
    return(nbradm);



}
int maxi(int tab[],int n)
{
    int i,maxi;
    maxi=tab[0];
    for (i=1;i<n;i++)
    {
       if(tab[i]>maxi)
       {
           maxi=tab[i];
       }
       return(maxi);

    }

}
int mini(int tab[],int n)
{
    int i,mini;
    mini=tab[0];
    for (i=1;i<n;i++)
    {
       if(tab[i]<mini);
       {
           mini=tab[i];
       }
       return(mini);

    }

}
void histog(classe tab[],int n,note tab1[],int n1,etudiant tab2[],int n2,matiere tab3[],int n3)
{
    int i,j,k,l;
    int t[100];
    int mi,ma;
    for(l=0;l<n;l++)
    {
        t[l]=nbr_admis(tab[l].codeclasse,tab1,n1,tab2,n2,tab3,n3);
    }
    mi=mini(t,n);
    ma=maxi(t,n);
    gotoxy(11,25);
    printf("---------------------------------------------------------------------->");
    gotoxy(9,26);
    printf("\t");
    for (k=0;k<n;k++)
    {

        printf("%d  ",tab[k].codeclasse);
    }
    printf("classe");
    gotoxy(0,ma+3);
    printf("Nombre^\ndes admis|\n           |\n           |\n");
    for (j=ma ;j >0 ; j-- )
    {   printf("          %d|",j);
        for ( i = 0 ; i <n ; i++ )
        {
            if ( t[i]<j )
            {
                printf("   ");
            }
            else
                printf("  %c",219);
        }
        printf("\n");
    }
    printf("\n\n\n---");
}
int convfichtab_classe(FILE *fc,classe tab[])
{
  int i=0;
  char s[100];
  classe c;
  while(!feof(fc))
  {
    fscanf(fc,"%s",s);
    tab[i].codeclasse=atoi(s);
    fscanf(fc,"%s",s);
    strcpy(tab[i].libelle,s);
    fscanf(fc,"%s",s);
    strcpy(tab[i].specialite,s);
    fscanf(fc,"%s",s);
    tab[i].capacite=atoi(s);
    i++;
  }
  return(i);
}

void convtabfich_classe(FILE* fc,classe tab[],int n)
{
   int i;
   char s[30],s1[30];
   for(i=0;i<n;i++)
   {
       //itoa(tab[i].codeclasse,s,10);
       //itoa(tab[i].capacite,s1,10);
       if(i>0)fprintf(fc,"\n");
       fprintf(fc,"%d\n",tab[i].codeclasse);
       fprintf(fc,"%s\n",tab[i].libelle);
       fprintf(fc,"%s\n",tab[i].specialite);
       fprintf(fc,"%d",tab[i].capacite);
       if(i<n-1)fprintf(fc,"\n");
   }
}
int convfichtab_etudiant(FILE *fe,etudiant tab[])
{
  int i=0;
  char s[30];
  etudiant e;
  while(fgets(s,100,fe))
  {
    tab[i].CIN=atoi(s);
    fgets(s,100,fe);
    strcpy(tab[i].nom,s);
    fgets(s,100,fe);
    strcpy(tab[i].prenom,s);
    fgets(s,100,fe);
    tab[i].date_de_naissance.jour=atoi(s);
    fgets(s,100,fe);
    tab[i].date_de_naissance.mois=atoi(s);
    fgets(s,100,fe);
    tab[i].date_de_naissance.annee=atoi(s);
    fgets(s,100,fe);
    tab[i].code_classe=atoi(s);
    i++;

  }
  return(i);
}

void convtabfich_etudiant(FILE* fe,etudiant tab[],int n)
{
   int i;
   char s[30],s1[4],s2[4],s3[5],s4[30];
   for(i=0;i<n;i++)
   {
       itoa(tab[i].CIN,s,10);
       itoa(tab[i].date_de_naissance.jour,s1,10);
       itoa(tab[i].date_de_naissance.mois,s2,10);
       itoa(tab[i].date_de_naissance.annee,s3,10);
       itoa(tab[i].code_classe,s4,10);

       fprintf(fe,"%s\n",s);
       fprintf(fe,"%s\n",tab[i].nom);
       fprintf(fe,"%s\n",tab[i].prenom);
       fprintf(fe,"%s\n",s1);
       fprintf(fe,"%s\n",s2);
       fprintf(fe,"%s\n",s3);
       fprintf(fe,"%s\n",s4);


   }
}
int convfichtab_matiere(FILE *fm,matiere tab[])
{
  int i=0;
  char s[30];
  while(fgets(s,100,fm))
  {
    tab[i].code_classe=atoi(s);
    fgets(s,100,fm);
    tab[i].code_matiere=atoi(s);
    fgets(s,100,fm);
    strcpy(tab[i].libelle_matiere,s);
    fgets(s,100,fm);
    tab[i].coefficient_matiere=atof(s);
    fgets(s,100,fm);
    tab[i].charge_horaire=atoi(s);
    i++;

  }
  return(i);
}

void convtabfich_matiere(FILE* fm,matiere tab[],int n)
{
   int i;
   char s[30],s1[30],s2[30],s3[30];
   for(i=0;i<n;i++)
   {
       itoa(tab[i].code_classe,s3,10);
       itoa(tab[i].code_matiere,s,10);
       sprintf(s1,"%f",tab[i].coefficient_matiere);
       itoa(tab[i].charge_horaire,s2,10);
       fprintf(fm,"%s\n",s3);
       fprintf(fm,"%s\n",s);
       fprintf(fm,"%s\n",tab[i].libelle_matiere);
       fprintf(fm,"%s\n",s1);
       fprintf(fm,"%s\n",s2);
   }
}
int convfichtab_notes(FILE *fn,note tab[])
{
  int i=0;
  char s[30];
  while(fgets(s,100,fn))
  {
    tab[i].CIN=atoi(s);
    fgets(s,100,fn);
    tab[i].code_matiere=atoi(s);
    fgets(s,100,fn);
    tab[i].ds=atoi(s);
    fgets(s,100,fn);
    tab[i].exam=atoi(s);
    i++;

  }
  return(i);
}

void convtabfich_notes(FILE* fn,note tab[],int n)
{
   int i;
   char s[30],s1[30],s2[30],s3[30];
   for(i=0;i<n;i++)
   {
       itoa(tab[i].CIN,s,10);
       itoa(tab[i].code_matiere,s1,10);
       itoa(tab[i].ds,s2,10);
       itoa(tab[i].exam,s3,10);
       fprintf(fn,"%s\n",s);
       fprintf(fn,"%s\n",s1);
       fprintf(fn,"%s\n",s2);
       fprintf(fn,"%s\n",s3);
   }
}

void main()
{
   FILE *fc;
   FILE *fce;
   FILE *fe;
   FILE *fee;
   FILE *fm;
   FILE *fme;
   FILE *fn;
   FILE *fne;
       fc=fopen("Fclasse.txt","r");
       fe=fopen("Fetudiant.txt","r");
       fm=fopen("Fmatiere.txt","r");
       fn=fopen("Fnote.txt","r");
       int n=0,n1=0,n2=0,n3=0;
       classe tab[100];
       etudiant tab1[100];
       matiere tab2[100];
       note tab3[200];
       if(!(fc)==NULL)
       n=convfichtab_classe(fc,tab);
       if(!(fe)==NULL)
       n1=convfichtab_etudiant(fe,tab1);
       if(!(fm)==NULL)
       n2=convfichtab_matiere(fm,tab2);
       if(!(fn)==NULL)
       n3=convfichtab_notes(fn,tab3);
   int r;
   int r1,r2,r5;
   char rr1,rr2,r3,rr5,r4;
   do
   {

   do
   {  affiche_mprincipal();
      gotoxy(9,9);
       scanf("%d",&r);
       system("cls");
   }while((r!=1)&&(r!=2)&&(r!=3)&&(r!=4)&&(r!=5)&&(r!=6));

   system("cls");

   if(r==1)
   {

   do

{
   do
   {
       gestion_classes();
       gotoxy(8,6);
       scanf("%d",&r1);
       system("cls");
   }while((r1!=1)&&(r1!=2)&&(r1!=3)&&(r1!=4));

   system("cls");
   if(r1==1)
   {

    do
    {
    rr1=ajout_classe(tab,&n);
    system("cls");
    }while(rr1=='O');
   }
    else if(r1==2)
   {
    modification_classe(tab,n);
    system("cls");
   }
    else if(r1==3)
    {
        if (n==0)
        {
            printf("Base de classe vide");
        }
        else
        {supression_classe(tab,&n);
        system("cls");}
    }

}while((r1!=4)&&(rr1=='N'));
   }
else if(r==2)
{   if(n==0)
     {
         printf("Pas de classe");
     }
    else
    {

    do
    {
        do
        {
        gestion_etudiant();
        gotoxy(8,6);
        scanf("%d",&r2);
        system("cls");
        }while((r2!=1)&&(r2!=2)&&(r2!=3)&&(r2!=4));
        if(r2==1)
        {
           do
           {
             rr2=ajout_etudiant(tab1,&n1,tab,n);
             system("cls");
           }while(rr2=='O');
        }
        else if(r2==2)
        {
           if (n1==0)
        {
            printf("Base d eleves vide");
        }
           else{
           modification_etudiant(tab1,n1,tab,n);
           system("cls");}
        }
        else if(r2==3)
    {
        if (n1==0)
        {
            printf("Base d eleves vide");
        }
        else
        {supression_etudiant(tab1,&n1);
        system("cls");}
    }

    }while((r2!=4)&&(rr2=='N'));
    }

}
else if(r==3)
{
    if(n==0)
    {
        printf("Pas de classe");

    }
    else
    {
      r3=ajout_matiere(tab,n,tab2,&n2);
    }
}
else if(r==4)
{
    if(n==0)
    {
        printf("Pas de classes");
    }
    else if(n1==0)
    {
        printf("Pas d etudiants");
    }
    else if(n2==0)
    {
        printf("Pas de matieres");
    }
    if((n!=0)&&(n1!=0)&&(n2!=0))
    {
       r4=ajout_note(tab3,&n3,tab,n,tab2,n2,tab1,n1);
    }
}
else if(r==5)
{
    do
    {
       if(n==0)
    {
        printf("Pas de classes");
    }
    else if(n1==0)
    {
        printf("Pas d etudiants");
    }
    else if(n2==0)
    {
        printf("Pas de matieres");
    }
    else if(n3==0)
    {
       printf("Pas de notes");
    }
    if((n!=0)&&(n1!=0)&&(n2!=0)&&(n3!=0))
    {
        do
        {
        statistique();
        gotoxy(8,6);
        scanf("%d",&r5);
        system("cls");
        }while((r5!=1)&&(r5!=2)&&(r5!=3)&&(r5!=4));
        system("cls");
        if(r5==1)
        {
            rr5=resultat_classe(tab,n,tab3,n3,tab1,n1,tab2,n2);
        }
        if(r5==2)
        {
            rr5=liste_laureats(tab,n,tab3,n3,tab1,n1,tab2,n2);
        }
        if (r5==3)
        {

        }

    }

    }while((r5!=4)&&((rr5=='N')||(rr5=='R')));



}




}while((r!=6)&&((r1==4)||(r2==4)||(r3=='N')||(r4=='N')||(r5==4)));
fclose(fc);
fce=fopen("Fclasse.txt","w");
convtabfich_classe(fce,tab,n);
fclose(fe);
fee=fopen("Fetudiant.txt","w");
convtabfich_etudiant(fee,tab1,n1);
fclose(fm);
fme=fopen("Fmatiere.txt","w");
convtabfich_matiere(fme,tab2,n2);
fclose(fn);
fne=fopen("Fnote.txt","w");
convtabfich_notes(fne,tab3,n3);
exit(0);


}
