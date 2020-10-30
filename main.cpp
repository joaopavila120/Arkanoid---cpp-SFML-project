#include <SFML/Graphics.hpp>

using namespace std;
using namespace sf;

struct bolinha //Criando a struct do jogador
{
    CircleShape shape; //CircleShape é uma classe do sfml que constroi um circulo

    bolinha(float x, float y) //coordenadas
    {
        //Define o circ
        shape.setPosition(x, y);
        shape.setRadius(10.f);
        shape.setFillColor(Color::Blue);
        shape.setOrigin(10.f, 10.f);
    }
};



int main()
{
    bolinha bolinha(800/2, 600/2);

    sf::RenderWindow window(sf::VideoMode(800, 600), "Arkanoid!");
    window.setFramerateLimit(60);

    float x = 0;

    //gameloop
    while (window.isOpen())
    {
   
        //tratamento dos eventos
        sf::Event event;
        while (window.pollEvent(event))
        {
            
            if (event.type == sf::Event::Closed)
                window.close();
            else if (event.type == sf::Event::KeyPressed) {
                if(event.key.code == sf::Keyboard::Escape)
                    window.close();
            }
        }
        //Atualização de estado do jogo

        window.clear();
        window.draw(bolinha.shape);
        window.display();
    }

    return 0;
}