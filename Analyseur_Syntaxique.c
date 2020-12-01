#include"H.h"
int main(int argc, char const *argv[])
{
    FILE *file=fopen("Hello.txt","r");
    printf("Analyseur Lexical !\n");
    char * ch=(char *)malloc(sizeof(char *));
    do{
    scanf("%s",ch);
    Analyseur_Lexical(ch);
    }while(!feof(file));
    return 0;
}

