#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
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
static string start_btn_clicked_img = "./img/main_start_btn_clicked.png";
static Counter c;
static Customer cu;
// static Kitchen k;

static Font font;
static Text customer_order;  // 손님 주문

static string order_menu = "";  // 주문 메뉴

enum class GameState { Main, Counter, Kitchen };

// 메인화면
int main()
{
	srand(time(NULL));

	bool is_btn_clicked = false;
	GameState current_state = GameState::Main;
	Clock delay_clock;
	Clock delay_customer;
	Music music;

	font.loadFromFile("./font/SKYBORI.ttf");

	// 메인 배경화면 이미지
	Texture main_background_img;
	if (!main_background_img.loadFromFile(main_img)) {
		return -1;
	}

	// 배경화면 이미지 저장
	Sprite background_sprite;
	background_sprite.setTexture(main_background_img);

	// 시작 버튼 이미지
	Texture start_btn_img;
	if (!start_btn_img.loadFromFile(start_btn)) {
		cerr << "이미지를 로드할 수 없음" << endl;
		return -1;
	}

	// 시작 버튼 이미지 저장
	Sprite start_btn_sprite(start_btn_img);
	start_btn_sprite.setPosition(245, 350);

	// 클릭된 버튼 이미지
	Texture start_btn_clicked_texture;
	if (!start_btn_clicked_texture.loadFromFile(start_btn_clicked_img)) {
		cerr << "이미지를 로드할 수 없음" << endl;
		return -1;
	}

	// 클릭된 버튼 이미지 저장
	Sprite start_btn_clicked_sprite(start_btn_clicked_texture);
	start_btn_clicked_sprite.setPosition(245, 350);

	while (window.isOpen()) {

		Event event;
		while (window.pollEvent(event)) {
			if (event.type == Event::Closed) {
				window.close();
			}
		}

		if (current_state == GameState::Main) {  // GameState가 Main일 때
			if (event.type == Event::MouseButtonPressed && !is_btn_clicked) {

				// 마우스의 위치 좌표를 가져와 버튼 클릭 여부 확인
				Vector2i mousePosition = Mouse::getPosition(window);
				if (start_btn_sprite.getGlobalBounds().contains(static_cast<float>(mousePosition.x), static_cast<float>(mousePosition.y))) {
					is_btn_clicked = true;
					delay_clock.restart();  // 클릭된 시간 기록, 타이머 리셋
				}
			}

			window.clear();

			// 화면 그리기
			window.draw(background_sprite);
			window.draw(start_btn_sprite);

			// 버튼을 클릭했을 때
			if (is_btn_clicked) {
				// 클릭된 상태에서만 타이머를 체크
				if (delay_clock.getElapsedTime().asMilliseconds() < 300) {
					// 0.5초 동안 클릭된 이미지를 보여줌
					start_btn_sprite.setTexture(start_btn_clicked_texture);
				}
				else {
					// 0.5초 뒤에는 카운터 페이지로 전환
					current_state = GameState::Counter;
					is_btn_clicked = false;
					start_btn_sprite.setTexture(start_btn_img);
				}
			}
			else {
				start_btn_sprite.setTexture(start_btn_img);
			}

		}
		else if (current_state == GameState::Counter) {  // GameState가 Counter일 때
			// 손님 주문
			if (customer_order.getString().isEmpty()) {
				customer_order.setString(cu.randomOrder());
				customer_order.setCharacterSize(30);
				customer_order.setFont(font);
				customer_order.setFillColor(Color::Black);

				order_menu = customer_order.getString().toAnsiString();
				cout << order_menu << endl;
				delay_customer.restart();  // 클릭된 시간 기록, 타이머 리셋
			}

			// 위치
			c.getCounterCheckoutSprite().setPosition(0, 460);
			cu.getTextSprite().setPosition(430, 70);
			c.getNextBtnSprite().setPosition(880, 530);
			c.getExitBtn().setPosition(30, 525);
			cu.getRandomCustomer().setPosition(300, 100);
			customer_order.setPosition(450, 100);

			bool is_exit_btn_clicked = false;
			bool is_next_btn_clicked = false;

			if (event.type == Event::MouseButtonPressed && !is_exit_btn_clicked) {
				// 마우스의 위치 좌표를 가져와 버튼 클릭 여부 확인
				Vector2i mousePosition = Mouse::getPosition(window);
				if (c.getExitBtn().getGlobalBounds().contains(static_cast<float>(mousePosition.x), static_cast<float>(mousePosition.y))) {
					is_exit_btn_clicked = true;
				}
			}
			if (event.type == Event::MouseButtonPressed && !is_next_btn_clicked) {
				// 마우스의 위치 좌표를 가져와 버튼 클릭 여부 확인
				Vector2i mousePosition = Mouse::getPosition(window);
				if (c.getNextBtnSprite().getGlobalBounds().contains(static_cast<float>(mousePosition.x), static_cast<float>(mousePosition.y))) {
					is_next_btn_clicked = true;
				}
			}

			window.clear();
			window.draw(c.getCounterBackgroundSprite());  // 카운터 배경

			// 특정 시간이 지나면 손님이 나타남
			if (delay_customer.getElapsedTime().asMilliseconds() > 5000) {
				window.draw(cu.getRandomCustomer());  // 손님 이미지
				window.draw(cu.getTextSprite());  // 말풍선
				window.draw(customer_order);  // 주문
			}
			window.draw(c.getCounterCheckoutSprite());  // 카운터 계산대
			window.draw(c.getNextBtnSprite());  // 주방 이동 버튼
			window.draw(c.getExitBtn());  // 나가기 버튼

			// 버튼을 클릭했을 때
			if (is_exit_btn_clicked) {  // 나가기 버튼을 클릭했을 때
				current_state = GameState::Main;
				is_exit_btn_clicked = false;
			}
			if (is_next_btn_clicked) {  // 주방 이동 버튼을 클릭했을 때
				current_state = GameState::Kitchen;
				is_next_btn_clicked = false;
			}

		}
		else if (current_state == GameState::Kitchen) {  // GameState가 Kitchen일 때
			// 주방 코드
		}

		window.display();
	}
}