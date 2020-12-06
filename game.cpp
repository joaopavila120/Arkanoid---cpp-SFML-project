//bibliotecas
#include <SFML/Graphics.hpp>
#include <time.h>


using namespace sf;

int main(){
 //Janela
    RenderWindow game(VideoMode(520, 450), "Arkanoid!");//janela com o nome
    game.setFramerateLimit(60); // limitar frame
 
  //Texturas do fundo,bolinha,nave,asteroide
    Texture t1,t2,t3,t4;
    t1.loadFromFile("img/block01.png");
    t2.loadFromFile("img/background.jpg");
    t3.loadFromFile("img/ball.png");
    t4.loadFromFile("img/paddle.png");

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

  
  
  
  
  while (game.isOpen()) //quando abre o jogo
  {
     Event ev;//cria um evento
     while (game.pollEvent(ev))
     {
       if (ev.type == Event::Closed) //fechar o jgo e tecla esc pra close
       game.close();
       else if(ev.type == Event::KeyPressed){
           if(ev.key.code==Keyboard::Escape)
           game.close();
     }
     }
    
    //se a bolinha a bolinha bater no asteroide ele vai sumindo
    x+=dx;
    for (int i=0;i<n;i++)
        if ( FloatRect(x+3,y+3,6,6).intersects(block[i].getGlobalBounds()) ) {
          block[i].setPosition(-100,0); dx=-dx; //tira o bloco e muda a direção da bolinha
          
        }

    y+=dy;
    for (int i=0;i<n;i++)
        if ( FloatRect(x+3,y+3,6,6).intersects(block[i].getGlobalBounds()) ){
          block[i].setPosition(-100,0); dy=-dy;//tira o bloco e muda a direção da bolinha
           
        }
    //muda a direção da bolinha
    if (x<0 || x>520)  dx=-dx;
    if (y<0 || y>450)  dy=-dy;

    if (Keyboard::isKeyPressed(Keyboard::Right)) sPaddle.move(7,0);//movimentação
    if (Keyboard::isKeyPressed(Keyboard::Left)) sPaddle.move(-7,0);//movimentação

    if ( FloatRect(x,y,12,12).intersects(sPaddle.getGlobalBounds()) ) dy=-(rand()%5+2);//quando bate na nave

    sBall.setPosition(x,y);//bolinea posição inicial

    game.clear();
    game.draw(sBackground);//desenha o fundo
    game.draw(sBall); // desenha o bolinea
    game.draw(sPaddle);//desenha a nave
    for (int i=0;i<n;i++) //desenha o asteroide e posi
    game.draw(block[i]);
    game.display();

   }

  return 0;
}
