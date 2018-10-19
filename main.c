#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
 /*-------------------------------------------------------------------------------------------------------*/
 void creer_fichier(char nom_fichier[30],char* texte)
 {
     int i ;
     FILE* fichier;
     char c ;
     fichier = fopen(nom_fichier,"w") ;
     fputs(texte,fichier) ;

  fclose(fichier);
 }
 void lire_fichier(char nom_fichier[30])
{
    FILE* fichier ;
    char c ;

    fichier = fopen(nom_fichier,"r");
    if (fichier == NULL)
    {
        printf("ce fichier %s n'existe pas dans le repertoire de ce programme\n",nom_fichier);
        return -1 ;
    }
    printf("Le fichier %s contient :\n",nom_fichier);
    while(!feof(fichier))
    {
        c = fgetc(fichier) ;
        printf("%c",c) ;
    }
    fclose(fichier);
}
 void concatener_2_fichiers(char nom_fichier1[30],char nom_fichier2[30],char fichier_final[30])
 {
   FILE* fichier1 , *fichier2 , *fichier_resultat;
    char buf[256] ;
    fichier1 = fopen(nom_fichier1,"r");
    fichier2 = fopen(nom_fichier2,"r");
    fichier_resultat = fopen(fichier_final,"w+") ;
    if ((fichier1== NULL) || (fichier2 == NULL) )
    {
       printf("l'un  de ces deux fichier %s , %s n'existe pas !\n",nom_fichier1,nom_fichier2);
       return -2    ;

    }
      while(!feof(fichier1)){
        fgets(buf,256,fichier1) ;
        fputs(buf,fichier_resultat);
    }
    while(!feof(fichier2)){
        fgets(buf,256,fichier2);
        fputs(buf,fichier_resultat);
    }
    fclose(fichier1);
    fclose(fichier2);
    fclose(fichier_resultat);
 }
int nbr_d_occurence(char nom_fichier[30],char* mot)
{
    int nb = 0 ;
    char* ligne ;
    FILE* fichier= fopen(nom_fichier,"r") ;
    if (fichier == NULL )
    {
        printf("le fichier n'existe pas \n");
        return 0 ;
    }

char* word ;
word = malloc(30*sizeof(char)) ;
ligne = malloc(256*sizeof(signed char)) ;
while(!feof(fichier))
{
fgets(ligne,256,fichier);
word = strtok(ligne," /-.,:;!?");
while (word != NULL )
{
 if (strcmp(word,mot)==0 )
 {
  nb ++;
 }
word = strtok(NULL," /-.,:;!?)(");
}
}
return nb ;
}
void encoder(char ligne[256],char password[30])
{
    int i ;
    i = 0 ;
    int j = 0 ;
    while (ligne[i] != '\0')
    {
        if (ligne[i] >= 32 && ligne[i] < 127){
            ligne[i] = ligne[i] + password[j] ;
            while (ligne[i] < 32 )
                {ligne[i] = - 127 + 32 + ligne[i] ;}
            i ++ ;
            j ++ ;
            if (password[j] == '\0') j  = 0 ;
        }
    }
}
void decoder(signed char ligne[256],char password[30])
{
    int i ;
    i = 0 ;
    int j = 0 ;
    while (ligne[i] != '\0')
    {
        if (ligne[i] >= 32 && ligne[i] < 127){
            ligne[i] = ligne[i] - password[j] ;
            while (ligne[i] < 32 )
                {ligne[i] =  127 - 32 + ligne[i] ;}
            i ++ ;
            j ++ ;
            if (password[j] == '\0') j  = 0 ;
        }
    }
}
int main()
{
    int choix ;
    char file_name[30] ;
    char file_name2[30] ;
    char file_name3[30] ;
    char* text ;
    char* mot ;
    char cle[30] ;
    char line[256] ;
 /*-------------------------------------------------------------------------------------------------------*/
 printf("\n\n                             ECOLE NATIONAL SUPERIEURE D'INFORMATIQUE\n") ;
 printf("                             ANNEE UNIVERSITAIRE : 2018/2019\n") ;
 printf("                             ETUDIANT : BEN MESSAOUD MOHAMED ISSAM DAOUD | MAIL : hm_ben_messaoud@esi.dz |  FB: facebook.com/zoldic.kilwa\n") ;
 printf("                             PROGRAMMME DE GESTION DES FICHIERS") ;
    choix = -1 ;
    while (choix != 7)
    {
        printf("\n---------------------------------------------------------------\n") ;
    printf("\nVeuillez choisir la fonction a executer s'il veut plait!\n");
        printf("\n---------------------------------------------------------------\n") ;
    printf("   0- Creer un fichier texte .\n   1- Lire un fichier texte. \n   2- Concatener deux fichiers texte\n   3- Calculer le  nombre d'occurence d'un mot.\n   4- calculer le nombre de ligne d'un fichier.\n   5- crypter un fichier.\n   6- decrypter un fichier.\n   7- Quitter.\n");
    printf("--->  ") ;
    scanf("%d",&choix);
    switch(choix)
    {
    default :
        printf("Assurez SVP que votre choix est disponible !\n");
        system("PAUSE") ;
        system("cls") ;
        break;
case 0:
    printf("le nom du fichier que vous voulez creer svp !\n");
    scanf("%s",file_name);
    printf("veuillez introduire svp son contenu :\n");
   text =  malloc(500*sizeof(char)) ;
    scanf("%s",text);
    printf("%s\n",text) ;
    creer_fichier(file_name,text);
    printf("creation avec succes\n");
    printf("\n") ;
     system("PAUSE") ;
    system("cls") ;
    break ;
    case 1:
         printf("Quel est le nom de fichier qu'on va lire svp :\n");
         scanf("%s",file_name);
         lire_fichier(file_name);
         printf("\n") ;
         system("PAUSE") ;
         system("cls") ;
        break;
    case 2:
        printf("Le nom du fichier 1 SVP ");
        scanf("%s",file_name);
        printf("\nle nom du fichier 2 SVP ");
        scanf("%s",file_name2) ;
        printf("\nle nome du fichier qui va contenir le resultat de concatenantion ");
        scanf("%s",file_name3);
        concatener_2_fichiers(file_name,file_name2,file_name3);
        printf("l'operation est terminee\n");
         printf("\n") ;
     system("PAUSE") ;
    system("cls") ;
        break ;
    case 3 :
        printf("le nom du fichier svp ");
        scanf("%s",file_name2);
        printf("\nle mot qu'on va claculer son occurence ");
        mot = malloc(30*sizeof(char));
        scanf("%s",mot);
        printf("\n->le nbr d'occurence du mot '%s' est : %d\n",mot,nbr_d_occurence(file_name2,mot)) ;
      printf("\n") ;
     system("PAUSE") ;
    system("cls") ;
        break ;
    case 5 :

        printf("le nom du fichier a coder svp : ") ;
        scanf("%s",file_name) ;
        printf("\nla cle svp : ") ;
        scanf("%s",cle);
        FILE* fich = fopen(file_name,"r") ;
        printf("le nom du fichier resultat svp : ") ;
        scanf("%s",file_name2) ;
        FILE* fichi = fopen(file_name2,"w");
        if (fich == NULL) {printf("ce fichier n'existe pas\n") ;
        return 0 ;}
        while(!feof(fich))
        {
            fgets(line,256,fich) ;
            encoder(line,cle) ;
            fputs(line,fichi) ;
        }
        fclose(fich) ;
        fclose(fichi) ;
         printf("\n") ;
     system("PAUSE") ;
    system("cls") ;
        break ;
         case 6 :

        printf("le nom du fichier a decoder svp : ") ;
        scanf("%s",file_name) ;
        printf("\nla cle svp : ") ;
        scanf("%s",cle);
        FILE* fich2 = fopen(file_name,"r") ;
        printf("le nom du fichier resultat svp : ") ;
        scanf("%s",file_name2) ;
        FILE* fichi2 = fopen(file_name2,"w");
        if (fich2 == NULL) {printf("ce fichier n'existe pas\n") ;
        return 0 ;}
        while(!feof(fich2))
        {
            fgets(line,256,fich2) ;
            decoder(line,cle) ;
            fputs(line,fichi2) ;
        }
        fclose(fich2) ;
        fclose(fichi2) ;
        break ;
         printf("\n") ;
     system("PAUSE") ;
    system("cls") ;
    case 7:
        return 11 ;


    }

    }

    return 0;
}
