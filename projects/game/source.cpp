#include <iostream>
#include <SFML/System/Time.hpp>
#include <SFML/Graphics.hpp>

#include "settings.hpp"

using namespace std;

sf::RenderWindow window(sf::VideoMode(WIDTH, HEIGHT), "DOOM", sf::Style::Titlebar | sf::Style::Close);

string page = "menu";

class Menu {
    public:
        sf::Sprite background;
        sf::Texture background_texture;

        sf::Sprite name;
        sf::Texture name_texture;

        sf::Sprite start;
        sf::Texture start_texture;

        sf::Sprite exit;
        sf::Texture exit_texture;
        
        Menu() {
            if( background_texture.loadFromFile("menu/background.png") )
                background.setTexture( background_texture );
            if( name_texture.loadFromFile("menu/name.png") )
                name.setTexture( name_texture );
                name.setPosition( (float)WIDTH * 3 / 8, (float)HEIGHT / 32 );
            if( start_texture.loadFromFile("menu/start.png") )
                start.setTexture( start_texture );
                start.setPosition( (float)WIDTH * 13 / 32, (float)HEIGHT * 5 / 12 );
            if( exit_texture.loadFromFile("menu/exit.png") )
                exit.setTexture( exit_texture );
                exit.setPosition( (float)WIDTH * 13 / 32, (float)HEIGHT * 8 / 12 );
        }

        void event() {
            sf::Cursor cursor;
            float x = sf::Mouse::getPosition( window ).x, y = sf::Mouse::getPosition( window ).y;
            if( x >= (float)WIDTH * 13 / 32 && x <= (float)WIDTH * 13 / 32 + 240 && y >= (float)HEIGHT * 5 / 12 + 30 && y <= (float)HEIGHT * 5 / 12 + 150 ) {
                cursor.loadFromSystem(sf::Cursor::SizeAll);
                window.setMouseCursor(cursor);
                if( sf::Mouse::isButtonPressed( sf::Mouse::Left ) )
                    page = "game";
            }
            else if( x >= (float)WIDTH * 13 / 32 && x <= (float)WIDTH * 13 / 32 + 240 && y >= (float)HEIGHT * 8 / 12 + 30 && y <= (float)HEIGHT * 8 / 12 + 150 ) {
                cursor.loadFromSystem(sf::Cursor::SizeAll);
                window.setMouseCursor(cursor);
                if( sf::Mouse::isButtonPressed( sf::Mouse::Left ) )
                    window.close();
            }
            else {
                cursor.loadFromSystem(sf::Cursor::Arrow);
                window.setMouseCursor(cursor);
            }
        }

        void draw() {
            window.draw(background);
            window.draw(name);
            window.draw(start);
            window.draw(exit);
        }

        int main() {
            event();
            draw();
            return 0;
        }
};

class Game {
    public:
        sf::Sprite cross;
        sf::Texture cross_texture;

        Game() {
            if( cross_texture.loadFromFile("other/cross.png") )
                cross.setTexture( cross_texture );
                cross.setPosition( WIDTH / 2 - 64, HEIGHT / 2 - 64 );
        }

        void event() {
            sf::Mouse::setPosition( sf::Vector2i(WIDTH / 2, HEIGHT / 2), window );
            if( sf::Keyboard::isKeyPressed( sf::Keyboard::Escape ) ) {
                page = "menu";
            }
        }

        void draw() {
            window.draw( cross );
        }

        int main() {
            event();
            draw();
            return 0;
        }
};

int main() {
    Menu menu;
    Game game;

    sf::Clock clock;
    float current_time = 0, last_time = 0, delay = 0, fps = 0;

    while (window.isOpen())
    {
        sf::Event event;

        while (window.pollEvent(event))
        {
            if ( event.type == sf::Event::Closed )
                window.close();
        }

        window.clear();

        if( page == "game" ) {
            window.setMouseCursorVisible(false);
            game.main();
        }
        else if( page == "menu" )
            menu.main();

        window.display();

        current_time = clock.restart().asSeconds();
        delay = current_time - last_time;
        last_time = clock.restart().asSeconds();

        if( MAX_DELAY > delay) {
            sf::Time pass_time = sf::seconds( MAX_DELAY - delay );
            sf::sleep( pass_time );
            delay = MAX_DELAY;
        }

        fps = 1.f / delay;
    }

    return 0;
}