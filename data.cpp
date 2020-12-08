#include <iostream>
#include <ctime>
#include <fstream>

using namespace std;

int main()
{
  ofstream arquivoS; //saindo do programa e indo pro arquivo
  time_t timer; //representar tempos
  struct tm *horarioLocal;

  time(&timer); // Obtem informações de data e hora
  horarioLocal = localtime(&timer); // Converte a hora atual para a hora local

  int dia = horarioLocal->tm_mday;
  int mes = horarioLocal->tm_mon + 1;
  int ano = horarioLocal->tm_year + 1900; //obter as informações da data

  int hora = horarioLocal->tm_hour;
  int min  = horarioLocal->tm_min;
  int sec  = horarioLocal->tm_sec; //obter horario

  arquivoS.open("Ranking.txt",ios::app); //Abrir o arquivo txt e app é pra operações apenas no final

  arquivoS <<"Nick:  " << "\n" << "Horário: " << hora << ":" << min << ":" << sec <<"\n" <<"Data: " << dia  << "/" << mes << "/" << ano <<" \n"<<"Pontos:" <<"       "<< endl;
// o que ira sair dentro do arquivo 

  arquivoS.close(); //fechar arquivo


  return 0;
}
