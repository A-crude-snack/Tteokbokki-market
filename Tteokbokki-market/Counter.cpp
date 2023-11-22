#define _CRT_SECURE_NO_WARNINGS
#include <SFML/Graphics.hpp>
#include <iostream>
#include <stdlib.h>
#include <string>

using namespace std;
using namespace sf;

// ���
class Counter {
public:
	Counter() {
		// ī���� ���ȭ�� �̹���
		if (!counterImageTexture.loadFromFile(counterImage)) {
			cerr << "�̹����� �ε��� �� ����" << endl;
		}
		// ī���� ���ȭ�� �̹��� ����
		counterImageSprite.setTexture(counterImageTexture);

		// ��ǳ�� �̹���
		if (!speechImageTexture.loadFromFile(speechBubbleImage)) {
			cerr << "�̹����� �ε��� �� ����" << endl;
		}
		// ��ǳ�� �̹��� ����
		speechBubbleSprite.setTexture(speechImageTexture);
	}

	// �̹��� ��� ���� �ذ�: �̹��� �ε��� �� ���� �ϰ�, �׷κ��� ������ Sprite ��ü�� ��� ����ϵ��� Ŭ������ ����
	// ī���� ���ȭ��
	Sprite& getCounterBackgroundSprite() {
		return counterImageSprite;
	}

	// �մ� ��ǳ��
	Sprite& getTextSprite() {
		return speechBubbleSprite;
	}
private:
	const string counterImage = "./img/counter_background.png";  // ī���� ��� �̹���
	const string speechBubbleImage = "./img/speech_bubble.png";  // ��ǳ�� �̹���

	Texture counterImageTexture;
	Sprite counterImageSprite;

	Texture speechImageTexture;
	Sprite speechBubbleSprite;
};