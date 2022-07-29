#include <iostream> //Equivale a stdio
#include <cstdlib> //Equivale a stdlib

#include "struct.h"
//#include "menu.h"

using namespace std;

tcc * inicio = NULL;
tcc * fim = NULL;
int tam = 0;

void ler_dados(int matricula){

    tcc * aux = inicio;
    for(int i = 0; i < tam; i++){
        if(matricula == aux->matricula){
           cout << "Aluno: " << aux->nome_aluno << endl;
           cout << "Matricula: " << aux->matricula << endl;
           cout << "Curso: " << aux->curso_aluno << endl;
           cout << "Orientador: " << aux->nome_orientador << endl;
           cout << "Titulo: " << aux->titulo_tcc << endl;
           cout << "Resumo: " << aux->resumo_tcc << endl;
           cout << "Local: " << aux->local << endl;
        }
        //printf("%d\n", i);
        aux = aux->prox;
    }

    //menu();

}

void exibir(){

    if(inicio == NULL){
        cout << "Nenhum item encontrado." << endl;
    }else{
        cout << "Previas:" << endl;
        tcc * aux = inicio;
        for(int i = 0; i < tam; i++){
            cout << "Aluno: " << aux->nome_aluno << endl;
            cout << "Matricula: " << aux->matricula << endl;
            cout << "Título TCC: " << aux->titulo_tcc << endl;
            aux = aux->prox; 
            if(aux == NULL){
                break;
            }
        }
    }

    //menu();
}

void remover(int matricula){

    if(tam == 1){
        free(inicio);
        tam--;
    };

    if(inicio == NULL){
        cout << "Lista vazia" << endl;
    }else{
        if(matricula == inicio->matricula){ //Inicio
            inicio = inicio->prox;
            free(inicio->ant);
            tam--;
        }else if(matricula == fim->matricula){ //Fim
            fim = fim->ant;
            free(fim->prox);
            tam--;
        }else{ //Meio
            tcc * aux = inicio;
            for(int i = 0; i < tam; i++){
                if(matricula == aux->matricula){
                    aux->prox->ant = aux->ant;
                    aux->ant->prox = aux->prox;
                    free(aux);
                    tam--;
                }
                //printf("%d\n", i);
                aux = aux->prox;
            }
        }

    }
   
    char nomearquivo[100];
    sprintf(nomearquivo, "%d.bin", matricula);
    remove(nomearquivo);
    cout << "TCC Removido!" << endl;

    //menu();
}

void atualizar(int matricula){

    char novo_nome[50], novo_curso[50],novo_email[50], novo_orientador[50], novo_titulo[50], novo_resumo[50], novo_local[50];

    tcc * aux = inicio;
    for(int i = 0; i < tam; i++){
        if(matricula == aux->matricula){
            cout << "Alterar nome do aluno:" << endl;
            cin >> novo_nome;
            aux->nome_aluno = novo_nome;
            cout << "Alterar nome de curso do aluno:" << endl;
            cin >> novo_curso;
            aux->curso_aluno = novo_curso;
            cout << "Alterar email do aluno:" << endl;
            cin >> novo_email;
            aux->email_aluno = novo_email;
            cout << "Alterar nome do orientador:" << endl;
            cin >> novo_orientador;
            aux->nome_orientador = novo_orientador;
            cout << "Alterar título do TCC:" << endl;
            cin >> novo_titulo;
            aux->titulo_tcc = novo_titulo;
            cout << "Alterar resumo do TCC:" << endl;
            cin >> novo_resumo;
            aux->resumo_tcc = novo_resumo;
            cout << "Alterar local do TCC:" << endl;
            cin >> novo_local;
            aux->local = novo_local;
        }
        //printf("%d\n", i);
        aux = aux->prox;
    }

    cout << "Dados atualizados com sucesso" << endl;

    //menu();

}

/*cadastro(nome_aluno, matricula, curso_aluno, email_aluno,  nome_avaliador,  instituicao, email_avaliador, titulo_tcc,  resumo_tcc, local, nome_orientador, frequencia);*/

void cadastro(char *nome_aluno, int matricula, char * curso_aluno, char * email_aluno, char * nome_avaliador, char * instituicao, char * email_avaliador, char * titulo_tcc, char * resumo_tcc, char * local, char * nome_orientador, int frequencia){

    tcc * novo_tcc = new(tcc); 
    novo_tcc->nome_aluno = nome_aluno;
    novo_tcc->matricula = matricula;
    novo_tcc->curso_aluno = curso_aluno;
    novo_tcc->email_aluno = email_aluno;

    novo_tcc->nome_orientador = nome_orientador;
    //novo_tcc->frequencia = frequencia;

    novo_tcc->nome_avaliador = nome_avaliador;
    novo_tcc->instituicao = instituicao;
    novo_tcc->email_avaliador = email_avaliador;

    novo_tcc->titulo_tcc = titulo_tcc;
    novo_tcc->resumo_tcc = resumo_tcc;
    novo_tcc->local = local;

    novo_tcc->prox = NULL;
    novo_tcc->ant = NULL;

    /*FILE * arquivo;
    arquivo = fopen(matricula, "a");
    sprintf(arquivo, "Nome: %s\n", nome_aluno);
    fprintf(arquivo, "Matricula %d\n", matricula);
    fclose(arquivo);*/

    char nome_arquivo[100];
    FILE *arquivo;
    sprintf(nome_arquivo, "%d.bin", matricula);

    arquivo = fopen(nome_arquivo, "w");
    fwrite(novo_tcc, 1, sizeof(tcc), arquivo);
    
    if(arquivo != NULL){
        fclose(arquivo);
    }else{
        perror(nome_arquivo);
        exit(EXIT_FAILURE);
    }

    if(inicio == NULL){
        inicio = novo_tcc;
        fim = novo_tcc;
    }else{
        fim->prox = novo_tcc;
        novo_tcc->ant = fim;
        fim = novo_tcc;  
    }
    tam++;

    cout << "Cadastro completo!" << endl;
    //menu();
    
}

void formulario(){

    char nome_aluno[50], curso_aluno[50], email_aluno[50], nome_avaliador[50], instituicao[50], email_avaliador[50], titulo_tcc[50], resumo_tcc[50], local[50], nome_orientador[50];
    int matricula, frequencia;

    cout << "Preencha os dados abaixo para cadastrar seu TCC" << endl;
    cout << "Nome do aluno: " << endl;
    cin >> nome_aluno;
    cout << "Matricula do aluno: " << endl;
    cin >> matricula;
    cout << "Curso do aluno: " << endl; 
    cin >> curso_aluno;
    cout << "Email do aluno: " << endl;
    cin >> email_aluno;

    cout << "Nome do Orientador: " << endl;
    cin >> nome_orientador;
    cout << "Frequencia: " << endl;
    cin >> frequencia;

    cout << "Nome do avaliador: " << endl;
    cin >> nome_avaliador;
    cout << "Instituicao do avaliador: " << endl;
    cin >> instituicao;
    cout << "Email do avaliador: " << endl;
    cin >> email_avaliador;

    cout << "Nome do TCC: " << endl;
    cin >> titulo_tcc;
    cout << "Resumo do TCC: " << endl;
    cin >> resumo_tcc;
    cout << "Local do TCC: " << endl;
    cin >> local;

    cadastro(nome_aluno, matricula, curso_aluno, email_aluno,  nome_avaliador,  instituicao, email_avaliador, titulo_tcc,  resumo_tcc, local, nome_orientador, frequencia);

}
