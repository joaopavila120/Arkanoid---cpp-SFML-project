#include <SFML/Graphics.hpp>
#include <time.h>

using namespace sf;

int pt = 0;
int vidas = 3;

int main()
{
  //Janela
  RenderWindow game(VideoMode(520, 450), "Arkanoid Space"); //janela com o nome

  game.setFramerateLimit(60); // limitar frame

  //Texturas do fundo,bolinha,nave,asteroide

  Texture t1, t2, t3, t4, t5;
  t1.loadFromFile("img/block01.png");
  t2.loadFromFile("img/background.jpg");
  t3.loadFromFile("img/ball.png");
  t4.loadFromFile("img/paddle.png");
  //t5.loadFromFile("img/game over.jpg");
  //t5.loadFromFile("images/game over.jpg");

  Sprite sBackground(t2), sBall(t3), sPaddle(t4); //sprites
  sPaddle.setPosition(300, 440);                  //posicionar a nave

  Sprite block[1000]; //sprites

  Font AtariSmall;                           //declara a fonte do atari
  AtariSmall.loadFromFile("AtariSmall.ttf"); //carrega o arquivo da fonte

  Text pontos;                       //define o texto para aparecer
  pontos.setFont(AtariSmall);        //cor
  pontos.setFillColor(Color::White); //define cor
  pontos.setCharacterSize(25);       //tamanho fonte
  pontos.setPosition(0, 0);          //posição do texto

  Text vida;                       //define o texto para aparecer
  vida.setFont(AtariSmall);        //cor
  vida.setFillColor(Color::White); //define cor
  vida.setCharacterSize(25);       //tamanho fonte
  vida.setPosition(495, 0);        //posição do texto

  Text GameOver;
  GameOver.setFont(AtariSmall);        //cor
  GameOver.setFillColor(Color::Green); //define cor
  GameOver.setCharacterSize(50);       //tamanho fonte
  GameOver.setPosition(140, 220);      //posição do texto

  Text opcoes;
  opcoes.setFont(AtariSmall);        //cor
  opcoes.setFillColor(Color::Green); //define cor
  opcoes.setCharacterSize(25);       //tamanho fonte
  opcoes.setPosition(110, 300);      //posição do texto

  int n = 0, i = 0, j = 0;

  for (int i = 1; i <= 10; i++)
    for (int j = 1; j <= 10; j++)
    {
      block[n].setTexture(t1);              //setar as texturas
      block[n].setPosition(i * 43, j * 20); //setar o lugar delas
      n++;
    }

  float dx = 4, dy = 5;   //velocidade dela
  float x = 300, y = 300; //setar bolinea

  while (game.isOpen()) //quando abre o jogo
  {
    Event ev; //cria um evento
    while (game.pollEvent(ev))
    {
      if (ev.type == Event::Closed) //fechar o jogo e tecla esc pra close
        game.close();
      else if (ev.type == Event::KeyPressed)
      {
        if (ev.key.code == Keyboard::Escape)
          game.close();
        if (ev.key.code == Keyboard::R)
        {
          pt = 0;
          vidas = 3;
          x = 300;
          y = 300;
          i = 0;
          j = 0;
          GameOver.setPosition(-140, -220);
          opcoes.setPosition(-110, -300);

          for (int i = 0; i < n; i++) //remove os asteroides da tela
            block[i].setPosition(-100, 0);

          for (int i = 1; i <= 10; i++) //mostra os asteroides novamente
            for (int j = 1; j <= 10; j++)
            {
              block[n].setTexture(t1);              //setar as texturas
              block[n].setPosition(i * 43, j * 20); //setar o lugar delas
              n++;
            }
        }
      }
    }

    //se a bolinha a bolinha bater no asteroide ele vai sumindo
    x += dx;
    for (int i = 0; i < n; i++)
      if (FloatRect(x + 3, y + 3, 6, 6).intersects(block[i].getGlobalBounds()))
      {
        block[i].setPosition(-100, 0);
        dx = -dx;
        pt++;
      }

    y += dy;
    for (int i = 0; i < n; i++)
      if (FloatRect(x + 3, y + 3, 6, 6).intersects(block[i].getGlobalBounds()))
      {
        block[i].setPosition(-100, 0);
        dy = -dy;
        pt++;
      }

    if (y >= 452) // se a bolinha bater no chão diminui uma vida
    {
      vidas--;
    }
    if (vidas == 0) //chegou no 0 game over
    {
      x = 0;    //tirar a bolinha da tela
      y = -100; // tirar a bolinha da tela
      GameOver.setString("Game Over");
      GameOver.setPosition(140, 220);
      opcoes.setString("R = restart | ESC = sair");
      opcoes.setPosition(110, 300);
    }

    //muda a direção da bolinha
    if (x < 0 || x > 520)
      dx = -dx;
    if (y < 0 || y > 450)
      dy = -dy;

    if (Keyboard::isKeyPressed(Keyboard::Right))
      sPaddle.move(7, 0); //movimentação
    if (Keyboard::isKeyPressed(Keyboard::Left))
      sPaddle.move(-7, 0); //movimentação

    if (FloatRect(x, y, 12, 12).intersects(sPaddle.getGlobalBounds()))
      dy = -(rand() % 5 + 2); //quando bate na nave

    sBall.setPosition(x, y); //bolinea posição inicial

    game.clear();
    game.draw(sBackground); //desenha o fundo
    game.draw(sBall);       // desenha o bolinea
    game.draw(sPaddle);     //desenha a nave

    for (int i = 0; i < n; i++) //desenha o asteroide e posi
      game.draw(block[i]);
    //if(gameWin) window.draw(menuSprite); Se tirar todos os asteroides;
    pontos.setString(std::to_string(pt)); //seta os pontos pra aparecer
    game.draw(pontos);                    //coloca os pontos na tela
    vida.setString(std::to_string(vidas));
    game.draw(vida);     //botar as vidas na tela
    game.draw(GameOver); //game over na tela
    game.draw(opcoes);   //opções na tela
    game.display();
  }

  return 0;
}
