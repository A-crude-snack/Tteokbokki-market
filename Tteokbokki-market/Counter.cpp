#define _CRT_SECURE_NO_WARNINGS
#include <SFML/Graphics.hpp>
#include <iostream>
#include <stdlib.h>
#include <string>

using namespace std;
using namespace sf;

// 배경
class Counter {
public:
	Counter() {
		// 카운터 배경화면 이미지
		if (!counterImageTexture.loadFromFile(counterImage)) {
			cerr << "이미지를 로드할 수 없음" << endl;
		}
		// 카운터 배경화면 이미지 저장
		counterImageSprite.setTexture(counterImageTexture);

		// 말풍선 이미지
		if (!speechImageTexture.loadFromFile(speechBubbleImage)) {
			cerr << "이미지를 로드할 수 없음" << endl;
		}
		// 말풍선 이미지 저장
		speechBubbleSprite.setTexture(speechImageTexture);
	}

	// 이미지 출력 오류 해결: 이미지 로딩은 한 번만 하고, 그로부터 생성된 Sprite 객체를 계속 사용하도록 클래스를 수정
	// 카운터 배경화면
	Sprite& getCounterBackgroundSprite() {
		return counterImageSprite;
	}

	// 손님 말풍선
	Sprite& getTextSprite() {
		return speechBubbleSprite;
	}
private:
	const string counterImage = "./img/counter_background.png";  // 카운터 배경 이미지
	const string speechBubbleImage = "./img/speech_bubble.png";  // 말풍선 이미지

	Texture counterImageTexture;
	Sprite counterImageSprite;

	Texture speechImageTexture;
	Sprite speechBubbleSprite;
};