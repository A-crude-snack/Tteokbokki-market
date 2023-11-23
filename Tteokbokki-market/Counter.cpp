#define _CRT_SECURE_NO_WARNINGS
#include <SFML/Graphics.hpp>
#include <iostream>
#include <stdlib.h>
#include <string>
#define SIZE 3

using namespace std;
using namespace sf;

// 배경
class Counter {
public:
	Counter() {
		// 카운터 배경화면 이미지
		if (!counter_texture.loadFromFile(counter_img)) {
			cerr << "이미지를 로드할 수 없음" << endl;
		}
		// 카운터 배경화면 이미지 저장
		counter_sprite.setTexture(counter_texture);

		// 카운터 계산대 이미지
		if (!counter_checkout_texture.loadFromFile(counter_checkout_img)) {
			cerr << "이미지를 로드할 수 없음" << endl;
		}
		// 카운터 배경화면 이미지 저장
		counter_checkout_sprite.setTexture(counter_checkout_texture);

		// 주방 이동 버튼 이미지
		if (!next_page_texture.loadFromFile(next_page_btn_img)) {
			cerr << "이미지를 로드할 수 없음" << endl;
		}
		// 이미지 저장
		next_page_sprite.setTexture(next_page_texture);

		// 나가기 버튼 이미지		
		if (!exit_texture.loadFromFile(exit_btn_img)) {
			cerr << "이미지를 로드할 수 없음" << endl;
		}
		// 이미지 저장
		exit_sprite.setTexture(exit_texture);
	}

	// 이미지 출력 오류 해결: 이미지 로딩은 한 번만 하고 그로부터 생성된 Sprite 객체를 계속 사용하도록 클래스 수정
	// 카운터 배경화면
	Sprite& getCounterBackgroundSprite() {
		return counter_sprite;
	}

	// 카운터 계산대
	Sprite& getCounterCheckoutSprite() {
		return counter_checkout_sprite;
	}

	// 주방 이동 버튼
	Sprite& getNextBtnSprite() {
		return next_page_sprite;
	}

	// 나가기 버튼
	Sprite& getExitBtn() {
		return exit_sprite;
	}

private:
	const string counter_img = "./img/counter_background.png";  // 카운터 배경 이미지
	const String counter_checkout_img = "./img/counter_checkout.png";  // 카운터 계산대 이미지
	const string next_page_btn_img = "./img/next_page_btn.png";  // 주방으로 가는 화살표 버튼 이미지
	const string exit_btn_img = "./img/exit_btn.png";  // 나가기 버튼 이미지

	Texture counter_texture;
	Sprite counter_sprite;

	Texture counter_checkout_texture;
	Sprite counter_checkout_sprite;

	Texture next_page_texture;
	Sprite next_page_sprite;

	Texture exit_texture;
	Sprite exit_sprite;
};

class Customer {
public:
	Customer() {
		// 말풍선 이미지
		if (!speech_texture.loadFromFile(speech_bubble_img)) {
			cerr << "이미지를 로드할 수 없음" << endl;
		}
		// 말풍선 이미지 저장
		speech_sprite.setTexture(speech_texture);
	}

	// 손님 말풍선
	Sprite& getTextSprite() {
		return speech_sprite;
	}

	// 랜덤 주문 함수
	string randomOrder() {
		srand(time(NULL));

		for (int i = 0; i < order.size(); i++) {
			order_idx[i] = rand() % order[i].size();
			re += order[i][order_idx[i]];
		}
		return re;
	}

	// 랜덤 손님 이미지
	string randomCustomer() {
		srand(time(NULL));

		customer_idx = rand() % 3;

		return customer[customer_idx];
	}
private:
	const string speech_bubble_img = "./img/speech_bubble.png";  // 말풍선 이미지

	Texture speech_texture;
	Sprite speech_sprite;

	// 랜덤 주문 내용
	vector<vector<string>> order = {
		{"Original", "Jajang", "Mala", "Cheese"},
		{" Tteokbbokki", " Rabokki"},
		{" please"} };
	vector<string> customer = { "./img/customer1.png", "./img/customer2.png", "./img/customer3.png" };

	string re;
	int order_idx[SIZE] = { 0 };
	int customer_idx = 0;
};