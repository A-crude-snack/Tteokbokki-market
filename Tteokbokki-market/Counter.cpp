#define _CRT_SECURE_NO_WARNINGS
#include <SFML/Graphics.hpp>
#include <stdlib.h>
#include <string>

using namespace std;
using namespace sf;

// 배경
class set_background_counter {
public:
	int set_img() {
		// 카운터 배경화면 이미지
		Texture counterImageTexture;
		if (!counterImageTexture.loadFromFile(counterImage)) {

			return -1;
		}
		
		// 카운터 배경화면 이미지 저장
		Sprite counterImageSprite;
		counterImageSprite.setTexture(counterImageTexture);

		// 말풍선 이미지
		Texture speechImageTexture;
		if (!speechImageTexture.loadFromFile(speechBubbleImage)) {
			return -1;
		}

		// 말풍선 이미지 저장
		Sprite speechBubbleSprite;
		speechBubbleSprite.setTexture(counterImageTexture);
	}
private:
	const string counterImage = "./img/counter_background.png";  // 카운터 배경 이미지
	const string speechBubbleImage = "./img/speech_bubble.png";  // 말풍선 이미지
};