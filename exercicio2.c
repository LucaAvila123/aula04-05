#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct aluno Aluno;
struct aluno{
	char* nome; 
	int matricula; 
	float p1; 
	float p2;
	float p3;
};
char* EscreveNome();
void imprime_aprovados (int n, Aluno** turma);
float MediaAluno(Aluno* estudante);
float media_turma (int n, Aluno** turma);
void LiberaTurma(int n, Aluno** turma);

int main(){
	int n=0;
	scanf("%d", &n);
	int matricula=0;
	float p1=0, p2=0, p3=0;
	Aluno** turma = (Aluno**) malloc (n * sizeof(Aluno*));
	
	for(int i=0; i<n; i++){
		turma[i] = (Aluno*) malloc (sizeof(Aluno));
		turma[i]->nome = EscreveNome();
		//printf("%s\n", turma[i]->nome);
		scanf("%d", &matricula);
		scanf("%f", &p1);
		scanf("%f", &p2);
		scanf("%f", &p3);
		turma[i]->matricula = matricula;
		turma[i]->p1 = p1;
		turma[i]->p2 = p2;
		turma[i]->p3 = p3;
		//scanf("%*[^\n]%*[\n]");
	}
	imprime_aprovados(n, turma);
	printf("%.2f\n", media_turma(n, turma));
	LiberaTurma(n, turma);
	
	return 0;
}

char* EscreveNome(){
	char nome[80];
	scanf("%s", nome);
	char* copia = (char*)malloc((strlen(nome)+1)*sizeof(char));
	strcpy(copia, nome);
	return copia;
}
void imprime_aprovados (int n, Aluno** turma){
	for(int i=0; i<n; i++){
		if(MediaAluno(turma[i]) >= 5)
			printf("%s %d %.2f\n", turma[i]->nome, turma[i]->matricula, MediaAluno(turma[i]));
	}
}
float MediaAluno(Aluno* estudante){
	float total = estudante->p1 + estudante->p2 + estudante->p3;
	float media = total/3;
	return media;
}
float media_turma (int n, Aluno** turma){
	float total = 0;
	for(int i=0; i<n; i++){
		total += MediaAluno(turma[i]);
	}
	total /= n;
	return total;
}
void LiberaTurma(int n, Aluno** turma){
	for(int i=0; i<n; i++){
		free(turma[i]->nome);
		free(turma[i]);
	}
	free(turma);
}