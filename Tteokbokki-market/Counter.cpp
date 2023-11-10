#define _CRT_SECURE_NO_WARNINGS
#include <SFML/Graphics.hpp>
#include <stdlib.h>
#include <string>

using namespace std;
using namespace sf;

// ���
class set_background_counter {
public:
	int set_img() {
		// ī���� ���ȭ�� �̹���
		Texture counterImageTexture;
		if (!counterImageTexture.loadFromFile(counterImage)) {

			return -1;
		}
		
		// ī���� ���ȭ�� �̹��� ����
		Sprite counterImageSprite;
		counterImageSprite.setTexture(counterImageTexture);

		// ��ǳ�� �̹���
		Texture speechImageTexture;
		if (!speechImageTexture.loadFromFile(speechBubbleImage)) {
			return -1;
		}

		// ��ǳ�� �̹��� ����
		Sprite speechBubbleSprite;
		speechBubbleSprite.setTexture(counterImageTexture);
	}
private:
	const string counterImage = "./img/counter_background.png";  // ī���� ��� �̹���
	const string speechBubbleImage = "./img/speech_bubble.png";  // ��ǳ�� �̹���
};