#include <stdio.h>
#include <process.h>

void main()
{
    FILE *fichier_src,*fichier_dest;
    char nom[20];
    float moyenne;
    if((fichier_src=fopen("text.txt","r"))==NULL)
    {
        printf("erreur d'ouverture du fichier source\n");
        exit(0);
    }
    if( (fichier_dest=fopen("text2.txt","w"))==NULL)
    {
        printf("erreur d'ouverture du fichier destination\n");
        exit(0);
    }
    while (!feof(fichier_src))
    {
        fscanf(fichier_src,"%s%f", nom,&moyenne);
        fprintf(fichier_dest,"%s%f\n",nom,moyenne);
    }
}
