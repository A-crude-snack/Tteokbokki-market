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
static string mainImage = "./img/main_background.png";
static string startBtn = "./img/main_start_btn.png";
static string startBtnClicked = "./img/main_start_btn_clicked.png";


enum class GameState { Menu, Game };

void changePage() {

}

// 메인화면
int main()
{
    srand(time(NULL));

    bool isButtonClicked = false;

    // 메인 배경화면 이미지
    Texture backgroundImage;
    if (!backgroundImage.loadFromFile(mainImage)) {
        return -1;
    }

    // 시작 버튼 이미지
    Texture startBtnImage;
    if (!startBtnImage.loadFromFile(startBtn)) {
        cerr << "이미지를 로드할 수 없음" << endl;
        return -1;
    }

    // 클릭된 버튼 이미지
    Texture startBtnClickedImage;
    if (!startBtnClickedImage.loadFromFile(startBtnClicked)) {
        cerr << "이미지를 로드할 수 없음" << endl;
        return -1;
    }

    // 배경화면 이미지 저장
    Sprite backgroundSprite;
    backgroundSprite.setTexture(backgroundImage);

    // 시작 버튼 이미지 저장
    Sprite startBtnSprite(startBtnImage);
    startBtnSprite.setPosition(245, 350);

    // 클릭된 버튼 이미지 저장
    Sprite startBtnClickedSprite(startBtnClickedImage);
    startBtnClickedSprite.setPosition(245, 350);

    while (window.isOpen()) {
        Event event;
        while (window.pollEvent(event)) {
            if (event.type == Event::Closed) {
                window.close();
            }
        }

        if (event.type == Event::MouseButtonPressed) {
            Vector2i mousePosition = Mouse::getPosition(window);

            if (startBtnSprite.getGlobalBounds().contains(static_cast<float>(mousePosition.x), static_cast<float>(mousePosition.y))) {
                // 버튼을 클릭했을 때
                if (isButtonClicked) {
                    startBtnSprite.setTexture(startBtnClickedImage);
                }
                else {
                    startBtnSprite.setTexture(startBtnImage);
                }
                isButtonClicked = !isButtonClicked;
            }
        }

        window.clear();

        window.draw(backgroundSprite);
        window.draw(startBtnSprite);
        window.display();
    }
}