#include <iostream>
#include <string>
#include <time.h>

using namespace std;

void limpaTela(){
    system("CLS");
}

string retornaPalavraAleatoria(){

    //Vetor com palavras disponiveis
    string palavras[3] = {"Abacaxi", "Manga", "Pera"};
    // Indice Gerado no intervalo de 0 ~ 2
    int indiceAleatorio = rand() % 3;

    return palavras[indiceAleatorio];
}

string retornaPalavraComMascara(string palavra, int tamanhoPalavra){
    int cont = 0;
    string palavraComMascara;

    while (cont < tamanhoPalavra)
    {
        palavraComMascara += "_";
        cont++;
    }

    return palavraComMascara;
}

void exibeStatus(string palavraComMascara, int tamanhoPalavra, int tentativasRestantes, string letrasJaArriscadas, string mensagem){

        cout << mensagem << "\n";
        cout << "Palavra: " << palavraComMascara << " Tamanho: " << tamanhoPalavra << "\n";
        cout << "Tentativas Restantes: " <<  tentativasRestantes << "\n";
        cout << "Letras Arriscadas: ";

        for (int i = 0; i < letrasJaArriscadas.size(); i++)
        {
           cout << " " << letrasJaArriscadas[i] << " |";
        }
        

}

int jogar(int nmrJogadores){
    limpaTela();
    //Palavra a ser advinhada
    string palavra;

    //Confere numero de jogadores
    if(nmrJogadores == 1){
        palavra =  retornaPalavraAleatoria();
    }else
    { 
        cout << "Jogador Escolha uma Palavra: ";
        cin >> palavra;
    }
    
    //Tamanho da Palavra
    int tamanhoPalavra = palavra.size();

    //Palavra mascarada
    string palavraComMascara = retornaPalavraComMascara(palavra, tamanhoPalavra);
    
    //Variaveis Gerais
    int opcao = 0;
    int tentativas = 0, maxTentativas = 10;          //Numeros de tentativas e erros
    char letra;                 //Letra Digitada
    string letrasJaArriscadas;  // Acumula Tentativas do jogador
    string mensagem = "Bem vindo ao Jogo"; // Feedback do jogador
    bool jaDigitouLetra = false, acertouLetra = false; 
    
    while (palavra != palavraComMascara && maxTentativas - tentativas  > 0)
    {
        limpaTela();
        exibeStatus(palavraComMascara, tamanhoPalavra, maxTentativas - tentativas, letrasJaArriscadas, mensagem);
        
        //Le o Palpite
        cout << "\nDigite uma letra: ";
        cin >> letra;

         //Percorre as letras ja arriscadas
         for (int i = 0; i < tentativas; i++)
         {
             //Se encontrar a Letra
             if (letrasJaArriscadas[i] == tolower(letra) || letrasJaArriscadas[i] == toupper(letra))
             {
                mensagem = "Essa letra ja foi arriscada";
                //Indica se encontrou
                jaDigitouLetra = true;
             }
         }

         if (jaDigitouLetra == false)
         {
             //Incrementa as letras ja arriscadas
            letrasJaArriscadas += letra;

            //Percorre a palavra real e se a letra existir muda a palavra com mascara
            for (int i = 0; i < tamanhoPalavra; i++)
            {
                //Se a letra existir na palavra
                if(palavra[i] == tolower(letra) || palavra[i] == toupper(letra)){

                //faço a letra apontar na palavraComMascara
                palavraComMascara[i] = palavra[i];
                acertouLetra = true;
                }
            }
            //Almenta a tentativas realizadas 
            tentativas++;
            

            if (acertouLetra == true)
            {
              mensagem = "Voce acertou uma letra";
            }else if(acertouLetra == false){
                mensagem = "Voce errou a letra";
            }
         } 
         //Reinicia Variáveis aux
        jaDigitouLetra = false;
        acertouLetra = false;
    }

    if(palavra == palavraComMascara){
        limpaTela();
        cout << "Parabens voce venceu";
        cout << "\nDeseja Reinciar?";
        cout << "\n1 - Sim \n2 - Nao\n";
        cout << "\nEscolha a opcao: ";
        cin >> opcao;
        
        if( opcao == 1){
            return opcao;
        }else
        {
            limpaTela();
            cout << "Ate mais\n";
            system("Pause");
        }
        
    }else
    {
        limpaTela();
        cout << "Voce Perdeu";
        cout << "\nDeseja Reinciar?"; 
        cout << "\n1 - Sim \n2 - Nao\n";
        cout << "\nEscolha a opcao: ";
        cin >> opcao;
        if( opcao == 1){
            return opcao;
        }else
        {
            limpaTela();
            cout << "Ate mais\n";
            system("Pause");

        }
        
    }
    
}

void menuIncial(){
//Opção escolhida pelo usuário
    int opcao = 0;

    while (opcao < 1 || opcao > 3) 
    { 
        limpaTela();
        cout << "Bem vindo ao jogo da forca";
        cout << "\n1 - Jogar";
        cout << "\n2 - Jogar em dupla";
        cout << "\n3 - Sobre";
        cout << "\n4 - Sair";

        cout << "\n\nEscolha uma opcao e tecle ENTER: ";
        cin >> opcao;

        switch (opcao)
        {
        case 1:
            cout << "\nJogo Inciado\n";
            if(jogar(1) == 1){
                menuIncial();
            }
        break;

        case 2:
            if(jogar(2) == 1){
                menuIncial();
            }
        break;

        case 3:
            limpaTela();
            cout << "\nInformacoes do Jogo";
            cout << "\nJogo da Forca em C++";
            cout << "\nDesenvolvedor: Julio Cezar 2020";
            cout << "\n\nOpcoes";
            cout << "\n1 - Voltar\n";
            cout << "2 - Sair\n";
            cout << "Escolha a Opcao: ";
            cin >> opcao;
            if(opcao == 1){
                menuIncial();
            }
            else
            {
                limpaTela();
                cout << "Ate mais\n";
                system("Pause");
            }
        break;
        
        case 4:
            limpaTela();
            cout << "Ate mais\n";
            system("Pause");
        break;
        }
    }
}

int main(){
    srand((unsigned)time(NULL));
    menuIncial();
    
}