struct aluno {
    int matricula;
    char nome[50];
    float n1 = 0;
    float n2 = 0;
    float media;
    bool situacao;
	int idade;
};

typedef struct elemento* Lista;

// Cria a Lista
Lista* cria_lista();

// Mostrar o total de Alunos Matriculados
int tamanho_lista(Lista* li);

// Lista de Alunos em Sequencia Pela Matrícula.
int insere_aluno_ordenada_matricula(Lista* li, struct aluno al);

// Mostrar Alunos Matrículados na Lista.
void imprime_lista(Lista* li, int tam);

// Remover Aluno da Lista
int remove_lista(Lista* li, int mat);

// Procurar Aluno na Lista, Situação e Adicionar Notas Para o Aluno.
int consulta_lista_mat(Lista* li, int mat, struct aluno* al);

// Cálculo e Impressão da Média Aritmética Final de Toda a Turma 
void Calc_Final_Med(Lista* li, int tam);

// Limpar a Lista para fechar o programa
void liberarLista(Lista* li);

// Verificar se a Nota Digitada está entre 0.00 e 10.00 
int Verif0_a10(float nt);
