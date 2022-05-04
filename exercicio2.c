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

void EscreveNome(Aluno* estudante);
void InsereMatricula(Aluno* estudante);
void InsereNotas(Aluno* estudante;
void LiberaAluno(Aluno* estudante);
void imprime_aprovados (int n, Aluno** turma);
float MediaAluno(Aluno* estudante);
float media_turma (int n, Aluno** turma);

int main(){
	int n = 1;
	Aluno** turma = (Aluno**) malloc (n * sizeof(Aluno*));
	for(int i=0; i<n; i++){
		turma[i] = (Aluno*) malloc (sizeof(Aluno));
		EscreveNome(turma[i]);
		InsereMatricula(turma[i]);
		InsereNotas(turma[i]);
	}
	imprime_aprovados (n, turma);
	printf("%.2f", media_turma(n, turma));
	for(int i=0; i<n; i++)
		LiberaAluno(turma[i]);
	
	free(turma);
	return 0;
}

void EscreveNome(Aluno* estudante){
	char* nome = (char*)malloc(81 * sizeof(char));
	scanf("%[^\n]", nome);
	strcpy(estudante->nome, nome);
	free(nome);
}
void InsereMatricula(Aluno* estudante){
	int matricula = 0;
	scanf("%d%*c", &matricula);
	estudante->matricula = matricula;
}
void InsereNotas(Aluno* estudante){
	float p1, p2, p3;
	scanf("%f %f %f", &p1, &p2, &p3);
	estudante->p1 = p1;
	estudante->p2 = p2;
	estudante->p3 = p3;
}
void LiberaAluno(Aluno* estudante){
	free(estudante->nome);
	free(estudante);
}

void imprime_aprovados (int n, Aluno** turma){
	for(int i=0; i<n; i++){
		if(MediaAluno(turma[i]) >= 5){
			printf("%[^\n]\n", turma[i]->nome);
		}
	}
}

float MediaAluno(Aluno* estudante){
	float media = estudante->p1 + estudante->p2 + estudante->p3;
	media /= 3;
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