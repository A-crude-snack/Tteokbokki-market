#include <SFML/Graphics.hpp>
#include <stdlib.h>
#include <time.h>
#include <iostream>
#include <string>
#include <Windows.h>
#include "./Counter.cpp";

using namespace std;
using namespace sf;

const int WIDTH = 950;
const int HEIGHT = 600;

static RenderWindow window(VideoMode(WIDTH, HEIGHT), "Tteokbokki_Market");
static string main_img = "./img/main_background.png";
static string start_btn = "./img/main_start_btn.png";
static string start_btn_clicked = "./img/main_start_btn_clicked.png";
static Counter c;
//static Kitchen k;

enum class GameState { Main, Counter, Kitchen };

// ����ȭ��
int main()
{
	srand(time(NULL));

	bool is_btn_clicked = false;
	GameState current_state = GameState::Main;
	Clock delayClock;

	// ���� ���ȭ�� �̹���
	Texture main_background_img;
	if (!main_background_img.loadFromFile(main_img)) {
		return -1;
	}

	// ���� ��ư �̹���
	Texture start_btn_img;
	if (!start_btn_img.loadFromFile(start_btn)) {
		cerr << "�̹����� �ε��� �� ����" << endl;
		return -1;
	}

	// Ŭ���� ��ư �̹���
	Texture start_btn_clicked_img;
	if (!start_btn_clicked_img.loadFromFile(start_btn_clicked)) {
		cerr << "�̹����� �ε��� �� ����" << endl;
		return -1;
	}

	// ���ȭ�� �̹��� ����
	Sprite background_sprite;
	background_sprite.setTexture(main_background_img);

	// ���� ��ư �̹��� ����
	Sprite start_btn_sprite(start_btn_img);
	start_btn_sprite.setPosition(245, 350);

	// Ŭ���� ��ư �̹��� ����
	Sprite start_btn_clicked_sprite(start_btn_clicked_img);
	start_btn_clicked_sprite.setPosition(245, 350);

	while (window.isOpen()) {

		Event event;
		while (window.pollEvent(event)) {
			if (event.type == Event::Closed) {
				window.close();
			}
		}
 
		if (current_state == GameState::Main) {  // GameState�� Main�� ��
			if (event.type == Event::MouseButtonPressed && !is_btn_clicked) {

				// ���콺�� ��ġ ��ǥ�� ������ ��ư Ŭ�� ���� Ȯ��
				Vector2i mousePosition = Mouse::getPosition(window);
				if (start_btn_sprite.getGlobalBounds().contains(static_cast<float>(mousePosition.x), static_cast<float>(mousePosition.y))) {
					is_btn_clicked = true;
					delayClock.restart();  // Ŭ���� �ð� ��� + Ÿ�̸� ����
				}
			}

			window.clear();

			// ȭ�� �׸���
			window.draw(background_sprite);
			window.draw(start_btn_sprite);

			// ��ư�� Ŭ������ ��
			if (is_btn_clicked) {
				// Ŭ���� ���¿����� Ÿ�̸Ӹ� üũ
				if (delayClock.getElapsedTime().asMilliseconds() < 300) {
					// 0.5�� ���� Ŭ���� �̹����� ������
					start_btn_sprite.setTexture(start_btn_clicked_img);
				}
				else {
					// 0.5�� �ڿ��� ī���� �������� ��ȯ
					current_state = GameState::Counter;
					is_btn_clicked = false;
					start_btn_sprite.setTexture(start_btn_img);
				}
			}
			else {
				start_btn_sprite.setTexture(start_btn_img);
			}

		}
		else if (current_state == GameState::Counter) {  // GameState�� Counter�� ��
			c.getCounterCheckoutSprite().setPosition(0, 460);  // ī���� �̹��� ��ġ ����

			window.draw(c.getCounterBackgroundSprite());

			window.draw(c.getCounterCheckoutSprite());
		}
		else if (current_state == GameState::Kitchen) {// GameState�� Kitchen�� ��
			// �ֹ� �ڵ�
		}

		window.display();
	}
}