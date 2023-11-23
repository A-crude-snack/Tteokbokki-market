#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <stdlib.h>
#include <time.h>
#include <iostream>
#include <string>
#include <Windows.h>
#include "./Counter.cpp";
#include "./Order.cpp";

using namespace std;
using namespace sf;

const int WIDTH = 950;
const int HEIGHT = 600;

static RenderWindow window(VideoMode(WIDTH, HEIGHT), "Tteokbokki_Market");
static string main_img = "./img/main_background.png";
static string start_btn = "./img/main_start_btn.png";
static string start_btn_clicked_img = "./img/main_start_btn_clicked.png";
static Counter c;
static Customer cu;
// static Kitchen k;

static Font font;
static Text customer_order;  // �մ� �ֹ�

enum class GameState { Main, Counter, Kitchen };

// ����ȭ��
int main()
{
	srand(time(NULL));

	bool is_btn_clicked = false;
	GameState current_state = GameState::Main;
	Clock delayClock;
	Music music;

	font.loadFromFile("./font/SKYBORI.ttf");

	// ���� ���ȭ�� �̹���
	Texture main_background_img;
	if (!main_background_img.loadFromFile(main_img)) {
		return -1;
	}

	// ���ȭ�� �̹��� ����
	Sprite background_sprite;
	background_sprite.setTexture(main_background_img);

	// ���� ��ư �̹���
	Texture start_btn_img;
	if (!start_btn_img.loadFromFile(start_btn)) {
		cerr << "�̹����� �ε��� �� ����" << endl;
		return -1;
	}

	// ���� ��ư �̹��� ����
	Sprite start_btn_sprite(start_btn_img);
	start_btn_sprite.setPosition(245, 350);

	// Ŭ���� ��ư �̹���
	Texture start_btn_clicked_texture;
	if (!start_btn_clicked_texture.loadFromFile(start_btn_clicked_img)) {
		cerr << "�̹����� �ε��� �� ����" << endl;
		return -1;
	}

	// Ŭ���� ��ư �̹��� ����
	Sprite start_btn_clicked_sprite(start_btn_clicked_texture);
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
					delayClock.restart();  // Ŭ���� �ð� ���, Ÿ�̸� ����
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
					start_btn_sprite.setTexture(start_btn_clicked_texture);
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
			// �մ� �ֹ�
			if (customer_order.getString().isEmpty()) {
				customer_order.setString(cu.randomOrder());
				customer_order.setCharacterSize(20);
				customer_order.setFont(font);
				customer_order.setFillColor(Color::Black);

				cout << customer_order.getString().toAnsiString() << endl;
			}

			c.getCounterCheckoutSprite().setPosition(0, 460);
			cu.getTextSprite().setPosition(600, 100);
			c.getNextBtnSprite().setPosition(880, 530);
			c.getExitBtn().setPosition(30, 525);
			customer_order.setPosition(620, 130);

			window.clear();
			window.draw(c.getCounterBackgroundSprite());
			window.draw(c.getCounterCheckoutSprite());
			window.draw(c.getNextBtnSprite());
			window.draw(c.getExitBtn());
			window.draw(cu.getTextSprite());
			window.draw(customer_order);
		}
		else if (current_state == GameState::Kitchen) {  // GameState�� Kitchen�� ��
			// �ֹ� �ڵ�
		}

		window.display();
	}
}