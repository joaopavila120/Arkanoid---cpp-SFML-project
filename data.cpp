#include <iostream>
#include <ctime>
#include <fstream>
#include "nick.cpp"

using namespace std;

int main()
{
  ofstream arquivoS;
  time_t timer;
  struct tm *horarioLocal;

  time(&timer); // Obtem informações de data e hora
  horarioLocal = localtime(&timer); // Converte a hora atual para a hora local

  int dia = horarioLocal->tm_mday;
  int mes = horarioLocal->tm_mon + 1;
  int ano = horarioLocal->tm_year + 1900;

  int hora = horarioLocal->tm_hour;
  int min  = horarioLocal->tm_min;
  int sec  = horarioLocal->tm_sec;

  arquivoS.open("Ranking.txt",ios::app);

  arquivoS <<"Nick:  " << "\n" << "Horário: " << hora << ":" << min << ":" << sec <<"\n" <<"Data: " << dia  << "/" << mes << "/" << ano <<" \n"<<"Pontos:" <<"       "<< endl;

  arquivoS.close();


  return 0;
}