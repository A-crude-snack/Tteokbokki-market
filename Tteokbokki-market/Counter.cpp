#define _CRT_SECURE_NO_WARNINGS
#include <SFML/Graphics.hpp>
#include <iostream>
#include <stdlib.h>
#include <string>
#define SIZE 3

using namespace std;
using namespace sf;

// ���
class Counter {
public:
	Counter() {
		// ī���� ���ȭ�� �̹���
		if (!counter_img_texture.loadFromFile(counter_img)) {
			cerr << "�̹����� �ε��� �� ����" << endl;
		}
		// ī���� ���ȭ�� �̹��� ����
		counter_img_sprite.setTexture(counter_img_texture);

		// ī���� ���� �̹���
		if (!counter_checkout_img_texture.loadFromFile(counter_checkout_img)) {
			cerr << "�̹����� �ε��� �� ����" << endl;
		}
		// ī���� ���ȭ�� �̹��� ����
		counter_checkout_img_sprite.setTexture(counter_checkout_img_texture);

		// ��ǳ�� �̹���
		if (!speech_img_texture.loadFromFile(speech_bubble_img)) {
			cerr << "�̹����� �ε��� �� ����" << endl;
		}
		// ��ǳ�� �̹��� ����
		speech_bubble_sprite.setTexture(speech_img_texture);
	}

	// �̹��� ��� ���� �ذ�: �̹��� �ε��� �� ���� �ϰ�, �׷κ��� ������ Sprite ��ü�� ��� ����ϵ��� Ŭ������ ����
	// ī���� ���ȭ��
	Sprite& getCounterBackgroundSprite() {
		return counter_img_sprite;
	}

	// ī���� ����
	Sprite& getCounterCheckoutSprite() {
		return counter_checkout_img_sprite;
	}

	// �մ� ��ǳ��
	Sprite& getTextSprite() {
		return speech_bubble_sprite;
	}

private:
	const string counter_img = "./img/counter_background.png";  // ī���� ��� �̹���
	const String counter_checkout_img = "./img/counter_checkout.png";  // ī���� ���� �̹���
	const string speech_bubble_img = "./img/speech_bubble.png";  // ��ǳ�� �̹���

	Texture counter_img_texture;
	Sprite counter_img_sprite;

	Texture counter_checkout_img_texture;
	Sprite counter_checkout_img_sprite;

	Texture speech_img_texture;
	Sprite speech_bubble_sprite;
};

class Recipe {
public:
	// ���� �ֹ� �Լ�
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
		{"�⺻", "¥��", "����", "ġ��"},
		{" ������", " ����"},
		{"�� ���� ��ɷ� �ּ���", "�� ���� ġ����� ���ּ���", "�� ��ä�� ��� ���ּ���", "�� ġ�� �־��ּ���", "�� ��ä�� �־��ּ���",
		"�� ��� �־��ּ���", "�� �Ҽ����� �־��ּ���", "�� ġ� �־��ּ���", "�� �Ҽ����� ���ּ���",
		"�� � ���� �� �ּ���", "�� ä�Ҵ� ���ĸ� �־��ּ���", "�� ���縮�� �־��ּ���", "�� ���縮 �־��ּ���", "�ּ���"}};

	vector<vector<string>> menu = {
		{"�⺻��", "ġ�", "�䶱", "���縮"},
		{"�⺻�ҽ�", "¥��ҽ�", "����ҽ�", "ġ��"},
		{"��", "����", "�", "�Ҽ���"} };

	string re;
	int order_idx[SIZE];
};