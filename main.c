#include <stdio.h>
#include <stdlib.h>

//Métodos do módulo "contatos.c		"
extern void cadastrar();
extern void listar();
extern void buscar();
extern void excluir();
extern void atualizarContato(); 
extern int contarRecursivo(int indice);

int main() {
    int opcao = -1;

    while (opcao != 0) {
        printf("\n### AGENDA CONTATOS ###");
        
        printf("\n1 - Cadastrar\n2 - Listar\n3 - Buscar por Nome\n4 - Excluir por Nome");
        printf("\n5 - Quantidade de Contatos (Recursiva)\n6 - Atualizar Contato (Ponteiro)\n0 - Sair\nEscolha: ");
        
        if (scanf("%d", &opcao) != 1) {
            fflush(stdin);
            printf("\nErro: Digite apenas numeros!\n");
            continue;
        }

        if (opcao == 1) cadastrar();
        else if (opcao == 2) { listar(); system("pause"); }
        else if (opcao == 3) { buscar(); system("pause"); }
        else if (opcao == 4) excluir();
        else if (opcao == 5) {
            printf("\nTotal de contatos: %d\n", contarRecursivo(0));
            system("pause");   
        }
        else if (opcao == 6) { atualizarContato(); system("pause"); }
        else if (opcao != 0) printf("\nOpcao invalida!\n");
    }

    printf("\nSaindo...\n");
    return 0;
}
