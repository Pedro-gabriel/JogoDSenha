#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <stdbool.h>


void add_tabuleiro(int coluna, char tabuleiro[4][4], char senha[4]){ // adicionar as escolhar do jogador no tabuleiro.
    for(int i = 0; i < 4; i++){
        tabuleiro[coluna][i] = senha[i];
    }
}

void compara(char porta[], char senha[]){ // nessa funcao, ela ira avisa para o jogador se as cores que ele escolheu estao certas ou nao.
    for(int i = 0; i < 4;i++){
        bool apareceu = false;
        for(int j = 0; j < 4; j++){
            if((porta[i] == senha[j]) && (i == j)){
                printf("cor %c na posicao %d certa\n", senha[j], j+1);
                apareceu = true;
            }else if((porta[i] == senha[j]) && (i != j)){
                printf("cor %c certa, posicao errada\n", senha[j]);
                apareceu = true;
            }
        }
            if(!apareceu){
                printf("cor %c nao faz parte da senha\n", senha[i]);
            }
    }
}

void chave(char chave[4]){ // funcao que ira escolher as 4 cores que serviram de chave para o jogo.
    char cores[10] = {'a', 'r', 'r', 'z', 'm', 'c', 'x', 'j', 'p', 'b'};
    for(int i = 0; i < 4;i++){
        chave[i] = cores[(rand() % 9) + 1]; // rand para escolher as cores.
    }
}

void clear(char tabuleiro[4][4]){ // funcao que ira limpa o tabuleiro para o jogo.
    for(int i = 0; i < 4;i++){
        for(int j = 0; j < 4; j++){
            tabuleiro[i][j] = 'x';
        }
    }
}

bool ganhou(char senha[], char porta[]){ // Essa funcao ira avaliar se o jogador ganhou ou nao
    int cont =0;
    for(int i =0; i<4;i++){
        if(senha[i] == porta[i]){  // aqui ira compara as opcoes que o jogado escolheu e a senha
            cont++;
        }
    }
    if(cont == 4){ // se as 4 opcoes forem iguais ele ira retorna true
        return true;
    }
    return false;
}

void show(char tabuleiro[4][4]){
    for(int i = 0; i < 4;i++){
        puts("------------------------");
        for(int j = 0; j < 4; j++){
            printf(" [%c] ",tabuleiro[i][j]);
        }
        puts("");
    }
}

int main(){
    srand(time(NULL));
    while(1){ // while principal
        puts("JOGO DA SENHA DAS CORES - escolha 4 cores por rodada, seram 4 rodadas a onde\n voce pode escolher 4 cores e depois saber se a cor e a posicao estaram corretas");
        puts("Escolha 4 cores entre a - Amarelo, r - Rosa, v - Vermelhor, z - Azul, \n m - Marrom, c - Cinza, x - Roxo, j - Laranja, p - Preto, b - Branco");
        int coluna = 3;
        int cont = 4;
        char porta[4];
        char senha[4];
        char tabuleiro[4][4];

        chave(porta); // escolher as cores que serviram de senha para tenta ser descoberta.
        clear(tabuleiro); // limpa a matriz

        while(cont--){
            for(int i = 0; i < 4; i++){
                printf("Digite a %d cor ", (i+1));
                scanf(" %c", &senha[i]);
            }
            compara(porta, senha);
            puts("");
            add_tabuleiro(coluna, tabuleiro, senha); // adicionar os opcoes que o jogador escolhei para o tabuleiro
            coluna-=1;  // coluna serve como
            show(tabuleiro);  // mostra o tabuleiro
            if(ganhou(senha, porta)){
                printf("Parabens voce venceu");
                break;
            }
        }
        if(cont == 0){
               printf("Mais sorte na proxima!!!!");
        }
        char continuar = '0';
        puts("Novo jogo? (s/n)");
        scanf(" %c", &continuar);
        if(continuar == 'n'){
            return 0;
        }
        system("cls");

    }
}
