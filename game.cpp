//bibliotecas
#include <SFML/Graphics.hpp>
#include <time.h>


using namespace sf;

int main(){
 //Janela
    RenderWindow app(VideoMode(520, 450), "Arkanoid!");//janela com o nome
    app.setFramerateLimit(60); // limitar frame
 
  //Texturas do fundo,bolinha,nave,asteroide
    Texture t1,t2,t3,t4;
    t1.loadFromFile("images/block01.png");
    t2.loadFromFile("images/background.jpg");
    t3.loadFromFile("images/ball.png");
    t4.loadFromFile("images/paddle.png");

    Sprite sBackground(t2), sBall(t3), sPaddle(t4); //sprites
    sPaddle.setPosition(300,440); //posicionar a nave
  
    Sprite block[1000];//sprites

    int n=0;
    for (int i=1;i<=10;i++)
    for (int j=1;j<=10;j++)
      {
        block[n].setTexture(t1); //setar as texturas
        block[n].setPosition(i*43,j*20); //setar o lugar delas
        n++;
      }

    float dx=4, dy=5;//velocidade bola
    float x=300, y=300;//setar bolinea

  
  
  
  
  while (app.isOpen()) //quando abre o jogo
    {
       Event e;//cria um evento
       while (app.pollEvent(e))
       {
         if (e.type == Event::Closed) //fechar o jgo
             app.close();
       }
    
    app.clear();
    app.draw(sBackground);//desenha o fundo
    app.draw(sBall); // desenha o bolinea
    app.draw(sPaddle);//desenha a nave
      app.display();

   }

  return 0;
}
