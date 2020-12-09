#include <iostream>
#include <ctime>
#include <fstream>
#include<cstdlib>

using namespace std;

int main()
{
fstream arquivoE;//Define se é entrada ou saida com espeficiaçãoes
  char opt='s'; //dar a opção mas não irá ter a opção 
  string nick,linha; //variaveis 

  arquivoE.open("Nicks.txt",ios::out | ios::app); //abrir arquivo,app é pra operações apenas no final e out é para sair do sistema e ir pro arquivo

  
  while((opt=='s')or (opt=='S')){ //enquanto o opt foi s ou S ele vai permitir digiar novos nicks
      cout << "Digite seu nick:  "; 
      cin >> nick; //recebendo
      arquivoE << nick <<"\n";//adicionar no arquivo 
      cout <<"\nSalvar[n]"; // digitar N para salvar
      cin >> opt; //vai receber a opção
      system("clear"); //limpar a tela de saida
  }
  arquivoE.close();//fechar os arquivo 

  arquivoE.open("Nicks.txt",ios::in);//ler o arquivo e entrar no sistema
  cout<< "Jogadores" << endl;//mostrar o nome dos jogadores

  if(arquivoE.is_open()){//se abriu ele vai mostrar no terminal tbm
      while(getline(arquivoE,linha)){//vai ler do arquivo e armazenar na linha
          cout << linha << endl;//mostrnado...
      }
      arquivoE.close();//fecha depois de mostrar
  }
  else{
      cout<<"Erro" << endl; //senão der aparecerá erro
  }
    return 0;
}