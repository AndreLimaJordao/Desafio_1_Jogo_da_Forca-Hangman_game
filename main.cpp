#include <iostream>
#include <string>

using namespace std;

int main(){

    //  VARIAVEIS ALTERAVEIS  // ------------------------------------------------------------------------------------------ //

    string palavra                                  = "";                // Palavra para ser usada no jogo
    int vidas;                                                           // Vidas do jogador
    string dica;                                                         // Dica da palavra

    // -------------------------------------------------------------------------------------------------------------------- //

    cout << "Digite a palavra: ";
    cin >> palavra;
    cout << "Digite a quantidade de vidas: ";
    cin >> vidas;
    cout << "Digite uma dica para ser dada quando chegar a 1 vida: ";
    cin >> dica;
    system("cls");

    // -------------------------------------------------------------------------------------------------------------------- //

    //  *VARIAVEIS NAO ALTERAVEIS*  // ------------------------------------------------------------------------------------ //

    bool testPalavra[palavra.size()];
    char letrasDisp[]                               = "abcdefghijklmnopqrstuvwxyz1234567890";
    bool testLetraDisp[sizeof(letrasDisp) - 1];
    char letra;
    bool acerto                                     = false;
    bool ganhou                                     = false;

    for (int i = 0; i < sizeof(testLetraDisp); i++){
        testLetraDisp[i] = false;
    }

    cout << "Jogo da Forca\n";
    for(int i = 0; i < palavra.size(); i++){
        if(isupper(palavra[i])){
            palavra[i] = tolower(palavra[i]);
        }
    }
    while(!ganhou && vidas > 0) {
        if (vidas == 1){
            cout << "\nDica: " << dica << "\n";                             //  Quando o jogador chegar a 1 vida, ele recebe
        }                                                                   //  uma dica da palavra.

        cout << "\nDigite uma letra (tamanho da palavra: " << palavra.size() << "):";
        cin >> letra;
        if (isupper(letra)) {
            letra = tolower(letra);
        }
        for (int i = 0; i < palavra.size(); i++) {
            if(letra == palavra[i]) {
                testPalavra[i] = true;                                      // Se a letra digitada for igual a alguma letra da
                acerto = true;                                              // palavra, a vari??vel testPalavra recebe true na posi????o
            }
        }
        if (!acerto){
            for (int i = 0; i < sizeof(testLetraDisp); i++){
                if(letra == letrasDisp[i]){                                 // Se a letra digitada n??o pertence a palavra,
                    testLetraDisp[i] = true;                                // essa letra ?? marcada como j?? digitada e erradas.
                }
            }
        }
        ganhou = true;
        for (int i = 0; i < sizeof(testPalavra); i++) {
            if (testPalavra[i] == 1) {                                      // Se a letra estiver correta, vai odernar a palavra,
                cout << palavra[i];                                         // caso contr??rio, vai mostrar um "-".
            } else {
                cout << "-";
                ganhou = false;
            }
        }
        cout << "\nLetras erradas:";
        for (int i = 0; i < sizeof(testLetraDisp); i++){
            if (testLetraDisp[i] == 1){                                     // Vai passar por todas as 26 letras dispon??veis
                cout << letrasDisp[i];
                cout << ",";// e salva as digitadas que foram erradas.
            }
        }
        cout << "\n";
        if (!acerto) {
            cout << "\nA letra " << letra << " nao pertence a palavra!\n";  //  Quando a letra digitada n??o pertence
            vidas--;                                                        //  a palavra, o jogador perde uma vida e
            cout << "Vidas: " << vidas;                                     //  avisa o restante de vidas
        }

        if (vidas == 0) {
            system("cls");
            cout << "\nFim do jogo\nPalavra: " << palavra << "\n\n";        //fim do loop na condi????o perda
        }

        if (ganhou) {
            system("cls");
            cout << "\nVoce ganhou!\nPalavra: " << palavra << "\n\n";       //fim do loop na condi????o ganha
        }

        acerto = false;                                                     //zerar a condi????o de acerto
    }
    system ("pause");
    return 0;
}
