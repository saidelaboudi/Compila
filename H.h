#include<stdio.h>
#include<string.h>
#include<stdlib.h>


const int  MOT_CLE_ARRAY_LENGTH=11;
const int SYMBOLE_SPECIAL_ARRAY_LENGTH=15;
const int LES_REGLES_LEXICALES_ARRAY_LENGTH=2;
typedef struct Symbole{
    char NOM[100];
    char CODE[100];
}Symbole;

Symbole LES_MOTS_CLES[]={
    {"program","PROGRAM_TOKEN"},
    {"const","CONST_TOKEN"},
    {"var","VAR_TOKEN"},
    {"begin","BEGIN_TOKEN"},
    {"end","END_TOKEN"},
    {"if" ,"IF_TOKEN"},
    {"then","THEN_TOKEN"},
    {"while","WHILE_TOKEN"},
    {"Do","DO_TOKEN"},
    {"read","READ_TOKEN"},
    {"write","WRITE_TOKEN"}
};
Symbole LES_SYMBOLES_SPECIALE[]={
    {".","PT_TOKEN"},
    {"+","PLUS_TOKEN"},
    {"-","MOINS_TOKEN"},
    {"*","MULT_TOKEN"},
    {"/","DIV_TOKEN"},
    {",","VIR_TOKEN"},
    {":=","AFF_TOKEN"},
    {"<","INF_TOKEN"},
    {"<=","INFEG_TOKEN"},
    {">","SUP_TOKEN"},
    {">=","SUPEG_TOKEN"},
    {"<>","DIFF_TOKEN"},
    {"(","PO_TOKEN"},
    {")","PF_TOKEN"},
    {"EOF","FIN_TOKEN"}
};
Symbole LES_REGLES_LEXICALES[]={
    {"ID","ID_TOKEN"},
    {"NUM","NUM_TOKEN"}
};

int CheckIfMotCle(char * ch);
int CheckIfSymboleSpecial(char * ch);
int CheckIfRegLexic(char * ch);
void Analyseur_Lexical(char * ch);


void  Analyseur_Lexical(char * ch){
    if(CheckIfMotCle(ch)||CheckIfSymboleSpecial(ch)){}
    else
        if(CheckIfRegLexic(ch)){}
}


int CheckIfMotCle(char * ch){
    int i;
    for(i=0;i<MOT_CLE_ARRAY_LENGTH;i++){
        if(!strcmp(LES_MOTS_CLES[i].NOM,ch)){
            printf("( %s , %s)\n",ch,LES_MOTS_CLES[i].CODE);
            return 1;
        }
    }
    return 0;
}


int CheckIfSymboleSpecial(char * ch){
    int i;
    for(i=0;i<SYMBOLE_SPECIAL_ARRAY_LENGTH;i++){
        if(!strcmp(LES_SYMBOLES_SPECIALE[i].NOM,ch)){
            printf("( %s , %s)\n",ch,LES_SYMBOLES_SPECIALE[i].CODE);
            return 1;
        }
    }
    return 0;
}

int CheckIfRegLexic(char * ch){
    int i;
    char* Type=(char*)malloc(sizeof(char*));
    //Pour savoir est ce que le mot saisie est un ID ou bien est un NUM
    for ( i = 0; *(ch+i*sizeof(char))!='\0'; i++){
        if(ch[0]<'9'&&ch[0]>'0'){
            if(ch[i]<'9'&&ch[i]>'0'){
                Type="NUM";
            }else{
                Type="ID";
                break;
            }
        }else{
            Type="ID";
        }
    }
    // Pour afficher le code associe au Nom du symbole

    for(i=0;i<LES_REGLES_LEXICALES_ARRAY_LENGTH;i++){
        if(!strcmp(LES_REGLES_LEXICALES[i].NOM,Type)){
            printf("( %s , %s)\n",ch,LES_REGLES_LEXICALES[i].CODE);
            return 1;
        }
    }
    return 0;
}