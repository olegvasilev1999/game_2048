#pragma once

using namespace sf;

struct Playing_Square {
	RectangleShape square;
	RectangleShape lineV[3];
	RectangleShape lineH[3];

	Playing_Square() {
		square.setSize(Vector2f(410, 410));
		square.setFillColor(Color(204, 192, 180));
		square.setOutlineColor(Color(187, 173, 160));
		square.setOutlineThickness(10);
		square.setPosition(10, 180);

		int X = 105, Y = 180;
		for (int i = 0; i < 3; i++, X += 105) {
			lineV[i].setSize(Vector2f(10, 410));
			lineV[i].setFillColor(Color(187, 173, 160));
			lineV[i].setPosition(X, Y);
		}
		X = 10, Y = 275;
		for (int i = 0; i < 3; i++, Y += 105) {
			lineH[i].setSize(Vector2f(410, 10));
			lineH[i].setFillColor(Color(187, 173, 160));
			lineH[i].setPosition(X, Y);
		}
	}
};

struct Bloks {
	RectangleShape score;
	RectangleShape best;
	CircleShape restart;
	CircleShape quit;

	Bloks() {
		score.setSize(Vector2f(200, 150));
		score.setFillColor(Color(187, 173, 160));
		score.setPosition(515, 50);

		best.setSize(Vector2f(200, 150));
		best.setFillColor(Color(187, 173, 160));
		best.setPosition(515, 250);

		restart.setRadius(25);
		restart.setFillColor(Color(237, 153, 91));
		restart.setPosition(500, 500);

		quit.setRadius(25);
		quit.setFillColor(Color(237, 153, 91));
		quit.setPosition(680, 500);
	}
};

struct Logo {
	Texture texture;
	Sprite sprite;

	Logo() {
		texture.loadFromFile("logo.png");
		sprite.setTexture(texture);
		sprite.setPosition(85, 27);
	}

};

struct Texts {
	Font font;
	Text score;
	Text best;
	Text restart;
	Text quit;

	Text Score;

	Texts() {
		font.loadFromFile("Alte_Haas_Grotesk_Bold.ttf");
		score.setFont(font);
		score.setString("SCORE");
		score.setCharacterSize(50);
		score.setFillColor(Color(238, 228, 213));
		score.setPosition(525, 55);

		best.setFont(font);
		best.setString("BEST");
		best.setCharacterSize(50);
		best.setFillColor(Color(238, 228, 213));
		best.setPosition(550, 255);

		restart.setFont(font);
		restart.setString("Restart");
		restart.setCharacterSize(30);
		restart.setFillColor(Color(219, 198, 166));
		restart.setPosition(470, 460);

		quit.setFont(font);
		quit.setString("Quit");
		quit.setCharacterSize(30);
		quit.setFillColor(Color(219, 198, 166));
		quit.setPosition(672, 460);
	}
};
