#include <stdio.h>
#include <string.h>

// Struct completa com os campos exigidos
struct Contato {
    int id;
    char nome[50];
    char telefone[20];
    char email[50];
};

struct Contato agenda[100]; // Array para 100 contatos
int total = 0;

void cadastrar() {
    if (total < 100) {
        agenda[total].id = total + 1;
        
        printf("\nNome: "); 
        fflush(stdin);
        scanf("%[^\n]", agenda[total].nome);
        
        printf("Telefone: "); 
        fflush(stdin);
        scanf("%[^\n]", agenda[total].telefone);
        
        printf("Email: ");
        fflush(stdin);
        scanf("%[^\n]", agenda[total].email);
        
        total++;
        printf("Contato salvo com sucesso!\n");
    } else {
        printf("Erro: Agenda cheia!\n");
    }
}

void listar() {
    int i;
    
    if(total == 0) {
        printf("\n !!! LISTA VAZIA !!!!\n");
    } else {
        printf("\n--- LISTA DE CONTATOS ---\n");
        for (i = 0; i < total; i++) {
            printf("ID: %d | Nome: %s | Tel: %s | Email: %s\n", agenda[i].id, agenda[i].nome, agenda[i].telefone, agenda[i].email);
        }
    }
}

void buscar() {
    char nomeBusca[50];
    int i, achou = 0;
    
    printf("\nNome para buscar: "); 
    fflush(stdin);
    scanf("%[^\n]", nomeBusca);
    
    for (i = 0; i < total; i++) {
        if (strcasecmp(agenda[i].nome, nomeBusca) == 0) { // Compara strings ignorando maiusculas
            printf("Achado! ID: %d | Email: %s\n", agenda[i].id, agenda[i].email);
            achou = 1;
        }
    }
    
    if (!achou) printf("Contato nao encontrado.\n");
}

void excluir() {
    char nomeDeletar[50];
    int i, j;
    
    printf("\nNome para excluir: "); 
    fflush(stdin);
    scanf("%[^\n]", nomeDeletar);
    
    for (i = 0; i < total; i++) {
        if(strcasecmp(agenda[i].nome, nomeDeletar) == 0) {
            for(j = i; j < total - 1; j++) {
                agenda[j] = agenda[j + 1];
            }
            // CORRIGIDO: Chaves ajustadas. O total-- e return devem ficar dentro do IF.
            total--;
            printf("Contato excluido!\n");
            return; 
        }
    }
    printf("Contato nao encontrado.\n");
}

// Requisito Obrigatorio: Edição utilizando Ponteiros
void atualizarContato() {
    char emailBusca[50];
    int i, achou = 0;
    struct Contato *ptrContato; // Ponteiro exigido no projeto

    printf("\nDigite o Email do contato que deseja atualizar: ");
    fflush(stdin);
    scanf("%[^\n]", emailBusca);

    for (i = 0; i < total; i++) {
        if (strcasecmp(agenda[i].email, emailBusca) == 0) {
            achou = 1;
            
            // O ponteiro recebe o endereço de memória exato do contato
            ptrContato = &agenda[i]; 

            printf("\n--- Atualizando Contato: %s ---\n", ptrContato->nome);
            
            // Usando o operador seta (->) para modificar os dados via ponteiro
            printf("Novo Nome: ");
            fflush(stdin);
            scanf("%[^\n]", ptrContato->nome); 
            
            printf("Novo Telefone: ");
            fflush(stdin);
            scanf("%[^\n]", ptrContato->telefone);
            
            printf("Novo Email: ");
            fflush(stdin);
            scanf("%[^\n]", ptrContato->email);
            
            printf("\nContato atualizado com sucesso!\n");
            break; 
        }
    }
    
    if (achou == 0) {
        printf("\nErro: Contato com o email [%s] nao encontrado.\n", emailBusca);
    }
}

// Requisito Obrigatorio: Funcao Recursiva
int contarRecursivo(int indice) {
    if (indice >= total) return 0; // Caso base
    return 1 + contarRecursivo(indice + 1); // Chamada recursiva
}
