#include <iostream>
#include <locale.h>
#include <math.h>
#include <stdlib.h>
#include "interface.h"

using namespace std;

struct elemento {
  struct aluno dados;
  struct elemento* prox;
};

typedef struct elemento Elem;

// Criar a Lista
//(aloca a memória utilizando o malloc e retorna um ponteiro do tipo Lista)
Lista* cria_lista() {
  Lista* li = (Lista*)malloc(sizeof(Lista));
  if (li != NULL) {
    *li = NULL;
  }
  return li;
}

// Mostrar o total de Alunos Matriculados
int tamanho_lista(Lista* li) {
  if (li == NULL) {
    return 0;
  }
  int cont = 0;
  Elem* no = *li;
  while (no != NULL) {
    cont++;
    no = no->prox;
  }
  return cont;
  cout <<" "<< cont;
}

// Inserir Aluno em sequencia ordenanda pela Matrícula
int insere_aluno_ordenada_matricula(Lista* li, struct aluno al) {
  if (li == NULL) {
    return 0;
  }
  Elem* no = (Elem*)malloc(sizeof(Elem));
  if (no == NULL) {
    return 0;
  }
  no->dados = al;
  if (*li == NULL) {
    no->prox = NULL;
    *li = no;
    return 1;
  } else {
    Elem* ant = *li; 
    Elem* atual = *li;
    while (atual != NULL && atual->dados.matricula < al.matricula) {
      ant = atual;
      atual = atual->prox;
    }
    if (atual == *li) {
      no->prox = *li;
      *li = no;
    } else {
      no->prox = atual;
      ant->prox = no;
    }
    return 1;
  }
}

// Mostrar Alunos Matrículados na Lista
void imprime_lista(Lista* li, int tam) {
  if (li == NULL) {
    cout<<"Não há nada para ser impresso!\n"<<endl;
    return;
  } if (tam == 0) {
    cout<<"Não há alunos cadastrados, adicione alunos para começar!\n"<<endl;
  } else {
    Elem* no = *li;
    int i = 1;
    while (no != NULL) {
      cout << "Aluno "<<i<<": "<<endl;
      cout <<"Matricula - "<< no->dados.matricula<<endl;
      cout <<"Nome - " << no->dados.nome<<endl;
			cout <<"Idade - " << no->dados.idade<<endl;
      if (no->dados.media >= 0 && no->dados.media <= 10) {
        cout <<"Media - " << no->dados.media<<endl;
        if (no->dados.situacao == true) {
          cout <<"Situação - Aprovado"<<endl;
        } else if (no->dados.situacao == false && no->dados.media == 0) {
          cout <<"Situação - Cursando"<<endl;
        } else {
          cout <<"Situação - Reprovado"<<endl;
        }
      }
      cout << "\n---------"<<endl<<endl;
      no = no->prox;
      i++;
    }
  }
}

// Remover um Aluno da Lista
int remove_lista(Lista* li, int mat) {
  if (li == NULL) {
    cout<<"\nNão há nada para remover!\n"<<endl;
    return 0;
  }
  if (*li == NULL) {
    return 0;
  }
  Elem* ant, *no = *li;
  while (no != NULL && no->dados.matricula != mat) {
    ant = no;
    no = no->prox;
  }
  if (no == NULL) {
    cout << "O Elemento referente a: " << mat << "\n Não foi encontrado!\n"<<endl;
    return 0;
  }
  if (no == *li) {
    *li = no->prox;
    cout << "O Aluno da Matricula: " <<mat<<", foi removido!"<< endl;
  }
  free(no);
  return 1;
}

// Procurar um Aluno na Lista, Perguntar se deseja Adicionar Notas e Calcular a Media e a Situação
int consulta_lista_mat(Lista* li, int mat, struct aluno* al) {
  if (li == NULL) {
    cout<<"Não há alunos cadastrados!\n"<<endl;
    return 0;
  }
  Elem* no = *li;
  while (no != NULL && no->dados.matricula != mat) {
    no = no->prox;
  }
  if (no == NULL) {
    cout << "Aluno não encontrado!" << endl;
    return 0;
  } else {
    *al = no->dados;
    cout << "\nMatricula - " << al->matricula << endl;
    cout << "Nome - " << al->nome << endl;
    if (al->n1 == 0 && al->n2 == 0) {
      char opcao;
      cout << "Situação - Cursando" << endl<<endl;
      cout << "Deseja adicionar as Notas do Aluno?\n(S-SIM | N-NÃO): ";
      cin >> opcao;
      opcao = toupper(opcao);
      if (opcao == 'S') {
        int n = 1;
        while (n == 1) {
          cout << "\nDigite a Nota 1: "; cin >> no->dados.n1;
          n = Verif0_a10(no->dados.n1);
        }
        n = 1;
        while (n == 1) {
          cout << "Digite a Nota 2: "; cin >> no->dados.n2;
          n = Verif0_a10(no->dados.n2);
        }
      }
      no->dados.media = (no->dados.n1*0.4 + no->dados.n2*0.6);
      cout << "\nMedia = " << no->dados.media << endl;
      if (no->dados.media >= 6) {
        cout << "Aluno Aprovado!" << endl;
        no->dados.situacao = true;
        return 1;
      }
      if (no->dados.media <= 6) {
        cout << "Aluno Reprovado!" << endl;
        no->dados.situacao = false;
        return 1;
      }
    }
  }
  return 1;
}

// Verificar se a Nota Digitada está entre 0.00 e 10.00 
int Verif0_a10(float nt) {
  int n = 1;
  if (nt >= 0 && nt <= 10) {
    n = 0;
  } else {
    cout<<"\nNota inválida! Digite um valor entre 0.00 e 10!\n"<<endl;
  }
  return n;
}

// Cálculo e Impressão da Média Aritmética Final de Toda a Turma 
void Calc_Final_Med(Lista* li, int tam) {
  if (li == NULL) {
    cout<<"\nAinda não há nada para calcular!\n"<<endl;
    return;
  }
  if (tam == 0) {
    cout<<"Não há alunos cadastrados, adicione novos alunos caso queira continuar!\n"<<endl;
  } else {
    float somaMed = 0;
    float finalMedia = 0;
    Elem* no = *li;
    while (no != NULL) {
      somaMed += no->dados.media;
      no = no->prox;
    }
    finalMedia = somaMed / tam;
    cout<<"\nA média final aritmética de toda a turma é: "<<finalMedia<<endl<<endl;
  }
}

// Limpa a Lista para fechar o programa
void liberarLista(Lista* li) {
  if (li == NULL || *li == NULL) {
    cout<<"\nOps! Você já limpou a Lista!"<<endl;
    cout<<"Por favor, feche o Programa!\n"<<endl;
    return;
  } else {
    *li = NULL;
    li = NULL;
    free(li);
  }
}
