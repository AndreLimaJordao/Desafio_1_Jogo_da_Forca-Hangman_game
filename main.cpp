#include <iostream>

using namespace std;

//VARIABLES
char palavra[] = "escola";
bool testPalavra[sizeof(palavra) - 1];
char letrasDisp[] = "abcdefghijklmnopqrstuvwxyz";
bool testLetraDisp[sizeof(letrasDisp) - 1];
int vidas = 7;
char letra;
bool acerto = false;
bool ganhou = false;

int main(){
    cout << "Jogo da Forca\n";
    while(!ganhou && vidas > 0) {
        cout << "\nDigite uma letra (tamanho da palavra: " << sizeof(palavra) - 1 << "):";
        cin >> letra;
        for( int i = 0; i < sizeof(palavra) - 1; i++) {
            if(letra == palavra[i]) {
                testPalavra[i] = true;                            // Se a letra digitada for igual a alguma letra da
                acerto = true;                                    // palavra, a variável testPalavra recebe true na posição
            }
        }
        if (!acerto){
            for(int i = 0; i < sizeof(testLetraDisp); i++){
                if(letra == letrasDisp[i]){                       // Se a letra digitada não pertence a palavra,
                    testLetraDisp[i] = true;                      // essa letra é marcada como já digitada e erradas.
                }
            }
        }
        ganhou = true;
        for (int i = 0; i < sizeof(testPalavra); i++) {
            if (testPalavra[i] == 1) {                            // Se a letra estiver correta, vai odernar a palavra,
                cout << palavra[i];                               // caso contrário, vai mostrar um "-".
            } else {
                cout << "-";
                ganhou = false;
            }
        }
        cout << "\nLetras erradas:";
        for (int i = 0; i < sizeof(testLetraDisp); i++){
            if (testLetraDisp[i] == 1){                          // Vai passar por todas as 26 letras disponíveis
                cout << letrasDisp[i];                           // e salva as digitadas que foram erradas.
            }
        }
        cout << "\n";
        if (!acerto) {
            cout << "\nA letra " << letra << " nao pertence a palavra!\n";  //  Quando a letra digitada não pertence
            vidas--;                                                        //  a palavra, o jogador perde uma vida e
            cout << "Vidas: " << vidas;                                     //  avisa o restante de vidas
        }
        if (vidas == 0) {
            cout << "\nFim do jogo\nPalavra: " << palavra; //fim do loop na condição perda
        }
        if (ganhou) {
            cout << "\nVoce ganhou!"; //fim do loop na condição ganha
        }
        acerto = false; //zerar a condição de acerto
    }
    return 0;
}
