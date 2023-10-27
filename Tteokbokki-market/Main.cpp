#include <SFML/Graphics.hpp>
#include <stdlib.h>
#include <time.h>
#include <iostream>
#include <string>

using namespace std;
using namespace sf;

const int WIDTH = 950;
const int HEIGHT = 600;

static RenderWindow window(VideoMode(WIDTH, HEIGHT), "Tteokbokki_Market");

// 메인화면
int main()
{
    srand(time(NULL));

    string img_main = "./img/background_main.png";
    Texture backgroundImage;
    if (!backgroundImage.loadFromFile(img_main)) {
        return -1;
    }

    Sprite backgroundSprite;
    backgroundSprite.setTexture(backgroundImage);

    while (window.isOpen()) {
        Event event;
        while (window.pollEvent(event)) {
            if (event.type == Event::Closed) {
                window.close();
            }
        }

        RectangleShape start_btn(Vector2f(395, 100));
        start_btn.setPosition(280, 400);
        //start_btn.setFillColor(Color::White);

        // 배경 이미지를 윈도우에 그리기
        window.clear();
        window.draw(backgroundSprite);
        window.draw(start_btn);
        window.display();
    }
}