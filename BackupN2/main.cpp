#include "interface.h"
#include <iostream>
#include <locale.h>
#include <math.h>
#include <stdlib.h>

int main() {
  using namespace std;

  setlocale(LC_ALL, "Portuguese");

  Lista *li = cria_lista();
  struct aluno dados_aluno;
  int matricula_aluno, posicao;
  char opcao;
  int aux = 0;
  int i = 1;

  while (i == 1) {
    printf("\n#############################################");
    printf("\n           MENU - Lista de informacao      ");
    printf("\n\n");
    printf("\n-->  1 = Total de Alunos Matriculados\n");
    printf("\n-->  2 = Adicionar um Novo Aluno\n");
    printf("\n-->  3 = Remover um Aluno da Lista\n");
    printf("\n-->  4 = Buscar um Aluno\n");
    printf("\n-->  5 = Calcular a Media Final Aritmética da Turma\n");
    printf("\n-->  6 = Imprimir a Lista de Alunos Matriculados\n");
    printf("\n-->  7 = Limpar a Lista de Alunos\n");
    printf("\n");
    printf("\nPressione qualquer outra Tecla para Sair!\n");
    printf("\n");
    printf("\n#############################################");
    printf("\n\n\n>> ");
    cin >> opcao;

    // 1- TOTAL DE ALUNOS NA LISTA, 2- ADICIONAR NOVO ALUNO, 3- REMOVER ALUNO,
    // 4- BUSCAR ALUNO, 5- MEDIA DA TURMA, 6- LISTA DE ALUNOS, 7- Limpar Lista.

    switch (opcao) {
    case '1':
      system("cls||clear");
      cout << "\nAlunos Matriculados: " << tamanho_lista(li) << endl;
      break;

    case '2':
      system("cls||clear");
      cout << "Digite a Matricula: ";
      cin >> dados_aluno.matricula;
      cout << "Digite o Nome: ";
      cin.ignore();
      cin.getline(dados_aluno.nome, 50);
      cout << "Digite a idade: ";
      cin >> dados_aluno.idade;
      dados_aluno.n1 = 0;
      dados_aluno.n2 = 0;
      dados_aluno.media = 0;
      dados_aluno.situacao = 0;
      insere_aluno_ordenada_matricula(li, dados_aluno);
      break;

    case '3':
      system("cls||clear");
      cout << "Digite a Matricula a ser Removida: ";
      cin >> matricula_aluno;
      remove_lista(li, matricula_aluno);
      break;

    case '4':
      system("cls||clear");
      cout << "Digite a Matricula a ser Buscada: ";
      cin >> matricula_aluno;
      consulta_lista_mat(li, matricula_aluno, &dados_aluno);
      break;

    case '5':
      system("cls||clear");
      Calc_Final_Med(li, tamanho_lista(li));
      break;

    case '6':
      system("cls||clear");
      imprime_lista(li, tamanho_lista(li));
      break;

    case '7':
      system("cls||clear");
      liberarLista(li);
      break;

    default:
      cout << "\nDeseja Realmente Sair? (S-SIM | N-NÃO): ";
      cin >> opcao;
      system("clear||cls");
      opcao = toupper(opcao);
      if (opcao == 'S') {
        cout << "Aplicação encerrada!" << endl << endl;
        exit(0);
      }
      break;
    }
  }
}