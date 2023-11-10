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

// ����ȭ��
int main()
{
    srand(time(NULL));

    bool isButtonClicked = false;

    // ���� ���ȭ�� �̹���
    Texture backgroundImage;
    if (!backgroundImage.loadFromFile(mainImage)) {
        return -1;
    }

    // ���� ��ư �̹���
    Texture startBtnImage;
    if (!startBtnImage.loadFromFile(startBtn)) {
        cerr << "�̹����� �ε��� �� ����" << endl;
        return -1;
    }

    // Ŭ���� ��ư �̹���
    Texture startBtnClickedImage;
    if (!startBtnClickedImage.loadFromFile(startBtnClicked)) {
        cerr << "�̹����� �ε��� �� ����" << endl;
        return -1;
    }

    // ���ȭ�� �̹��� ����
    Sprite backgroundSprite;
    backgroundSprite.setTexture(backgroundImage);

    // ���� ��ư �̹��� ����
    Sprite startBtnSprite(startBtnImage);
    startBtnSprite.setPosition(245, 350);

    // Ŭ���� ��ư �̹��� ����
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
                // ��ư�� Ŭ������ ��
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