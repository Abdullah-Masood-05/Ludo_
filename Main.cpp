#include"game.h"
#include<SFML/Graphics.hpp>
#include<SFML/Audio.hpp>
#include"utility.h"
using namespace std;
//using namespace sf;
Position get_xy(sf::RenderWindow& W)
{
    sf::Event ev;
    while (1)
    {
        while (W.pollEvent(ev))
        {
            if (ev.type == ev.Closed)
                W.close();
            if (ev.type == ev.MouseButtonPressed && sf::Mouse::isButtonPressed(sf::Mouse::Button::Left))
            {
                auto po = sf::Mouse::getPosition(W);
                return { po.y,po.x };
            }
        }
    }
}

int main()
{
	
	Ludo game;
	sf::RenderWindow window(sf::VideoMode(1366, 768), "Ludo");
   sf::Texture S1;
    if (!S1.loadFromFile("images/back_ludo.png")) {
        cout << "Failed to load texture!";
    }
    sf::Music music;
    if (!music.openFromFile("music_back.wav")) {
        std::cout << "Failed to load music!" << std::endl;
    }
    music.setLoop(true);
    music.setVolume(30);
    music.play();
    sf::Sprite s(S1);
    s.setPosition(0, 0);
    window.draw(s);
    window.display();
    Position p = get_xy(window);
    int br = 250, bc = 250;
    p.ri = p.ri / br;
    p.ci = p.ci / bc;
    if (p.ri == 1 && p.ci == 1) {
       
        game.Play2(window);
    }
    else if (p.ri == 1 && p.ci == 2) {
       
        game.Play4(window);
    }
    else  {
        
        game.Play(window);

    }
    return 0;
}