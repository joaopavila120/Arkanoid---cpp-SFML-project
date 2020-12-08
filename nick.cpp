#include <iostream>
#include <ctime>
#include <fstream>
#include<cstdlib>

using namespace std;

int main()
{
fstream arquivoE;
  char opt='s';
  string nick,linha;

  arquivoE.open("Nicks.txt",ios::out | ios::app);
  
  while((opt=='s')or (opt=='S')){
      cout << "Digite seu nick:  ";
      cin >> nick;
      arquivoE << nick <<"\n";
      cout <<"\nDigite[n]";
      cin >> opt; 
      system("clear");
  }
  arquivoE.close();

  arquivoE.open("Nicks.txt",ios::in);
  cout<< "Jogadores" << endl;

  if(arquivoE.is_open()){
      while(getline(arquivoE,linha)){
          cout << linha << endl;
      }
      arquivoE.close();
  }
  else{
      cout<<"Erro" << endl;
  }
    return 0;
}