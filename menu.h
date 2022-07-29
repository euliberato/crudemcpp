#include "funcoes.h"
using namespace std;
void menu(){

    int n = -1;
    cout << "" << endl;
    cout << "Bem-vindo ao sistema de TCC's" << endl;
    cout << "Escolha uma opcao: " << endl;
    cout << "1 - Cadastrar TCC" << endl;
    cout << "2 - Exibir trabalhos" << endl;
    cout << "3 - Atualizar dados do TCC" << endl;
    cout << "4 - Remover TCC" << endl;
    cout << "0 - Sair" << endl;
    cin >> n;
    if(n == 1){
        formulario();
        menu();
    }else if(n == 2){
        int i = 0;
        cout << "Exibir dados:" << endl;
        cout << "1 - Visualizar todos os trabalhos" << endl;
        cout << "2 - Pesquisar trabalho específico" << endl;
        cin >> i;
        if(i == 1){
            exibir();
            menu();
        }else if(i == 2){
            int nome_arq;
            cout << "Digite sua matrícula:" << endl;
            cin >> nome_arq;
            ler_dados(nome_arq);
            menu();
        }else{
            cout << "[ERRO] Funcao invalida, tente novamente!" << endl;
            menu();
        }
       
    }else if(n == 3){
        int matricula;
        cout << "Digite sua matrícula:" << endl;
        cin >> matricula;
        atualizar(matricula);
        menu();
    }else if(n == 4){
        int i;
        cout << "Digite a matrícula para remover um TCC: " << endl;
        cin >> i;
        remover(i);
        menu();
    }else if(n == 0){
        cout << "Encerrado." << endl;
    }else{
        cout << "[ERRO] Funcao invalida, tente novamente!" << endl;
        menu();
    }

}
