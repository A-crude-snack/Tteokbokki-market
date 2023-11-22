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
		if (!counter_img_texture.loadFromFile(counter_img)) {
			cerr << "이미지를 로드할 수 없음" << endl;
		}
		// 카운터 배경화면 이미지 저장
		counter_img_sprite.setTexture(counter_img_texture);

		// 카운터 계산대 이미지
		if (!counter_checkout_img_texture.loadFromFile(counter_checkout_img)) {
			cerr << "이미지를 로드할 수 없음" << endl;
		}
		// 카운터 배경화면 이미지 저장
		counter_checkout_img_sprite.setTexture(counter_checkout_img_texture);

		// 말풍선 이미지
		if (!speech_img_texture.loadFromFile(speech_bubble_img)) {
			cerr << "이미지를 로드할 수 없음" << endl;
		}
		// 말풍선 이미지 저장
		speech_bubble_sprite.setTexture(speech_img_texture);
	}

	// 이미지 출력 오류 해결: 이미지 로딩은 한 번만 하고, 그로부터 생성된 Sprite 객체를 계속 사용하도록 클래스를 수정
	// 카운터 배경화면
	Sprite& getCounterBackgroundSprite() {
		return counter_img_sprite;
	}

	// 카운터 계산대
	Sprite& getCounterCheckoutSprite() {
		return counter_checkout_img_sprite;
	}

	// 손님 말풍선
	Sprite& getTextSprite() {
		return speech_bubble_sprite;
	}

private:
	const string counter_img = "./img/counter_background.png";  // 카운터 배경 이미지
	const String counter_checkout_img = "./img/counter_checkout.png";  // 카운터 계산대 이미지
	const string speech_bubble_img = "./img/speech_bubble.png";  // 말풍선 이미지

	Texture counter_img_texture;
	Sprite counter_img_sprite;

	Texture counter_checkout_img_texture;
	Sprite counter_checkout_img_sprite;

	Texture speech_img_texture;
	Sprite speech_bubble_sprite;
};

class Recipe {
public:
	// 랜덤 주문 함수
	string randomOrder() {
		srand((unsigned int)time(NULL));

		for (int i = 0; i < order.size(); i++) {
			order_idx[i] = rand() % order[i].size();
			re += order[i][order_idx[i]];
		}
		return re;
	}

private:
	vector<vector<string>> order = {
		{"기본", "짜장", "마라", "치즈"},
		{" 떡볶이", " 라볶이"},
		{"에 떡은 긴걸로 주세요", "에 떡은 치즈떡으로 해주세요", "에 야채는 모두 뻬주세요", "에 치즈 넣어주세요", "에 야채만 넣어주세요",
		"에 어묵만 넣어주세요", "에 소세지만 넣어주세요", "에 치즈만 넣어주세요", "에 소세지만 빼주세요",
		"에 어묵 빼고 다 주세요", "에 채소는 양파만 넣어주세요", "에 라면사리만 넣어주세요", "에 라면사리 넣어주세요", "주세요"}};

	vector<vector<string>> menu = {
		{"기본떡", "치즈떡", "긴떡", "라면사리"},
		{"기본소스", "짜장소스", "마라소스", "치즈"},
		{"파", "양파", "어묵", "소세지"} };

	string re;
	int order_idx[SIZE];
};