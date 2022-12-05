//Andre
#include <iomanip>
#include <iostream>

using namespace std;

void preencheTabuleiro(char tabuleiro[8][8], int posicaoX, int posicaoY){
    tabuleiro[posicaoX-2][posicaoY-1] = 'O';
    tabuleiro[posicaoX-2][posicaoY+1] = 'O';
    tabuleiro[posicaoX-1][posicaoY-2] = 'O';
    tabuleiro[posicaoX-1][posicaoY+2] = 'O';
    tabuleiro[posicaoX+1][posicaoY-2] = 'O';
    tabuleiro[posicaoX+1][posicaoY+2] = 'O';
    tabuleiro[posicaoX+2][posicaoY-1] = 'O';
    tabuleiro[posicaoX+2][posicaoY+1] = 'O';
}

int contagem(char tabuleiro[8][8]){
    int X = 0;
    for(int x = 0; x < 8; x++){
        for(int y = 0; y < 8; y++){
            if(tabuleiro[x][y] == 'O'){
                X++;
            }
        }
    }
    return X;
}

void desenhaTabuleiro(char tabuleiro[8][8]){
    char alf[9] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h'};
    for(int x = 0; x < 9; x++){
        if(x == 0){
            cout << "# ";
        }else{
            cout << x << " ";
        }
        for(int y = 0; y < 9; y++){
            if(x == 0){
                cout << alf[y] << " ";
            }else{
                cout << tabuleiro[x-1][y] << " ";
            }
        }
        cout<<endl;
    }
}

int main(){
    char tabuleiro[8][8];
    char linha[2];
    int posicaoX, posicaoY;
    int Y = 0, X, movimentacoes = 8;
    for(int x = 0; x < 8; x++){
        for(int y = 0; y < 8; y++){
            tabuleiro[x][y] = '0';
        }
    }  
    do{
        Y++;
        cin >> linha[0];
        if(linha[0] == '0'){
            break;
        }
        cin >> linha[1];
        tabuleiro[8 - ((linha[0] - 48))][(linha[1] - 96)-1] = 'C';
        posicaoX = 8 - (linha[0] - 48);
        posicaoY = (linha[1] - 96)-1;
        preencheTabuleiro(tabuleiro, posicaoX, posicaoY);
        for(int i = 1; i < 9; i++){
            cin >> linha[0] >> linha[1];
            if(tabuleiro[8 - ((linha[0] - 48))][(linha[1] - 96)-1] != 'O'){
                tabuleiro[8 - ((linha[0] - 48))][(linha[1] - 96)-1] = 'P';
            }
            if(tabuleiro[9 - ((linha[0] - 48))][(linha[1] - 96)-2] == 'O'){
                tabuleiro[9 - ((linha[0] - 48))][(linha[1] - 96)-2] = 'X';
            }
            if(tabuleiro[9 - ((linha[0] - 48))][(linha[1] - 96)] == 'O'){
                tabuleiro[9 - ((linha[0] - 48))][(linha[1] - 96)] = 'X';
            }
        }
        desenhaTabuleiro(tabuleiro);
        cout << "Caso de teste #" << Y << ": " << contagem(tabuleiro) <<" movimento(s).";
        for(int x = 0; x < 8; x++){
            for(int y = 0; y < 8; y++){
                tabuleiro[x][y] = '0';
            }
        }   
    }while(linha[0]!='0');
}
