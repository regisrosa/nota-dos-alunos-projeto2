#include "stdio.h"
#include <stdlib.h>
void nota_individual();
void media_da_turma();
void nota_geral();
void total_alunos();

int num;
int *aluno;

int main(void) {

  printf("Quantos alunos deseja cadastrar?\n");
  scanf("%d", &num);
  
  aluno = (int *) malloc(num * sizeof(int));
  
  float nota;
  for(int i=0; i<num; i++){
    printf("Digite a nota do aluno %d\n", i+1);
    scanf("%f", &nota);
    while(nota<0 || nota>10){ // este while é para não colocar nota fora do limite de 0 a 10
      printf("Nota inválida, favor repetir a operação.\n");
      scanf("%f", &nota);
    }
    aluno[i]= nota;
    printf("\n");
  }
  
  nota_individual(); // chamando a função para obter a nota individual
  media_da_turma(); // chamando a função média da turma
  total_alunos();
  nota_geral(); // chamando a função para obter a nota geral da turma
  
  return 0;
}

void nota_individual(int i){
  printf("Deseja saber a nota individual de qual aluno?\n");
  scanf("%d", &i);
  if(i <=0 || i>num){
    printf("--------------------------------\n");
    printf("Este aluno não existe no sistema.\n\n");
  }
  else{
    printf("-----------------------------\n");
    printf("Aluno %d, nota: %d\n ", i, aluno[i-1]);
    printf("-----------------------------\n");  
  }  
}

void media_da_turma(){
  int soma=0;
  for(int i=0; i<num; i++){
    soma = soma + aluno[i]; 
  }
  float media;
  media = (float) soma / num; //tive de fazer um casting pois a média estava saindo sempre inteira
  printf("Média da turma: %.2f\n ", media);
  printf("-----------------------------\n");
}

void nota_geral(){
  printf("Todas as notas individuais:\n ");
  for(int i=0; i<num; i++){
    printf("\nAluno %d, nota: %d\n ", i+1, aluno[i]);
  }
}

void total_alunos(){
  printf("Total de alunos na turma: %d\n", num);
  printf("------------------------------\n");
}


  
