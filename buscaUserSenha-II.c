#include<stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>

//Mostra na tela o dia de hoje // Shows current date in screen
void Dia (){
    const time_t timer = time(NULL);
    printf("Today is %s\n\n Have a NICE DAY \n\n\t \t:)\n\n", ctime(&timer));
}
//Conta as linhas que tem no arquivo // Function to count the number of lines in the file

int linhas(FILE *FP){
    int linha=0;
    char buffer[1024];
    while(fgets(buffer,sizeof(buffer),FP)!=NULL)
        linha++;

        return linha;
    }
// Acha palavra na linha // Finds a given string in the line

void AchaPalavra(FILE *FP,char palavra[1024]){
   int ocorrencia=0;
   char buffer[1024];


   while(fgets(buffer,sizeof(buffer), FP) != NULL) {



		if((strstr(buffer, palavra)) !=NULL) {

			printf("\n%s encontrada na linha : %d\n",buffer, ocorrencia);

		}
		ocorrencia++;

		if (ocorrencia==0)
            printf("Sem Ocorencias no arquivo\n");
        }
        //printf("pesquisa concluida\n");
    }



int main(void){

    int i,j=0,line;
    char nomeArquivo[256],linhaBuffer[256];
    char palavra[1024],linha;

    Dia();

    printf("\tBuscador de palavras\n");
    printf("\nDigite a palavra ou frase\n\n");
    scanf("%s",&palavra);

    printf("\n Quer buscar em quantos arquivos\n");
    scanf("%d",&j);
    if(j>112)printf("Digite um numero entre 1 a 111\n");
    printf("\n");

    FILE *fp;
    for(i=1;i<=j;i++){
        sprintf(nomeArquivo,"%d.txt",i);
        printf("\n LENDO O ARQUIVO ----- %s -----\n",nomeArquivo);
        fp=fopen(nomeArquivo,"r");
        if(fp==NULL)printf("\nImpossivel abrir o arquivo %s\n Arquivo nao existe\n",nomeArquivo);
        while(fgets(linhaBuffer,sizeof(linhaBuffer),fp)){
            AchaPalavra(fp,palavra);
        }
        fclose(fp);
        printf("\n FIM DA LEITURA DO ARQUIVO ----- %s -----\n",nomeArquivo);
    }


return 0;
}
