//#ifndef struct.h
//#define struct.h
typedef struct tcc_data{
    char * nome_aluno;
    int matricula;
    char * curso_aluno;
    char * email_aluno;

    char * nome_orientador;
    int frequencia;

    char * nome_avaliador;
    char * instituicao;
    char * email_avaliador;

    char * titulo_tcc;
    char * resumo_tcc;
    char * local;

    struct tcc_data * prox;
    struct tcc_data * ant;

}tcc;

//#endf struct.h