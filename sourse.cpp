
#include <SFML\Graphics.hpp>
#include <ctime>
#include <iostream>
#include <fstream>
#include <sstream>
#include "Graphic_elements.h"
#include "Operations.h"
//#include "Menu.h"

using namespace sf;
using namespace std;

void add(int cell[4][4], Sprite Cell[4][4]) {
	int k;
	int s = 95;
	int p = rand() % 10;
	if (p < 9) k = 2;
	else k = 4;
m1:
	int i = rand() % 4;
	int j = rand() % 4;
	if (cell[i][j] == 0) cell[i][j] = k;
	else goto m1;

	if (cell[i][j] == 2) Cell[i][j].setTextureRect(IntRect(s, 0, s, s));
	else if (cell[i][j] == 4) Cell[i][j].setTextureRect(IntRect(2*s, 0, s, s));
	
}

void score_position(int s, Text & score) {
	if (s < 10) score.setPosition(595, 110);
	if (s >= 10 && s < 100) score.setPosition(580, 110);
	if (s >= 100 && s < 1000) score.setPosition(560, 110);
	if (s >= 1000 && s < 10000) score.setPosition(540, 110);
}

void best_score_position(int s, Text & score) {
	if (s < 10) score.setPosition(595, 310);
	if (s >= 10 && s < 100) score.setPosition(580, 310);
	if (s >= 100 && s < 1000) score.setPosition(560, 310);
	if (s >= 1000 && s < 10000) score.setPosition(540, 310);
}

void start(int grid[4][4], Sprite cell[4][4]) {
	int s = 95;
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			grid[i][j] = 0;
		}
	}
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			cell[i][j].setTextureRect(IntRect(0, 0, s, s));
			cell[i][j].setPosition(10 + j * 105, 180 + i * 105);
		}
	}
	add(grid, cell);
	add(grid, cell);
}

struct gameover {
	RectangleShape GameOver;
	Font font;
	Text over;

	gameover() {
		font.loadFromFile("Alte_Haas_Grotesk_Bold.ttf");
		over.setFont(font);
		over.setString("GAME OVER");
		over.setCharacterSize(50);
		over.setFillColor(Color(238, 228, 213));
		over.setPosition(238, 100);

		GameOver.setSize(Vector2f(800, 600));
		GameOver.setFillColor(Color(237, 153, 91, 128));
		GameOver.setPosition(0, 0);
	}
	
	void show(RenderWindow & window) {
		window.draw(GameOver);
		window.draw(over);
	}
};

int main() {
	srand(time(0));
	ContextSettings settings;
	settings.antialiasingLevel = 4;

	RenderWindow window;
	window.create(VideoMode(800, 600), "2048", Style::Default, settings);

	//menu(window);/////////////////////////////////////////////////////////////////

	Playing_Square playing_square;
	Logo logo;
	Bloks bloks;
	Texts texts;

	Font font;
	Text score,best_score;
	font.loadFromFile("Alte_Haas_Grotesk_Bold.ttf");

	int record_score;
	ifstream record("record_score.txt");
	record >> record_score;
	record.close();
	ostringstream BestScore;
	BestScore << record_score;
	best_score.setFont(font);
	best_score.setString(BestScore.str());
	best_score.setCharacterSize(65);
	best_score.setFillColor(Color(255, 247, 231));
	best_score_position(record_score,best_score);

	int player_score = 0;
	score.setFont(font);
	ostringstream PlayerScore;
	PlayerScore << player_score;
	score.setFont(font);
	score.setString(PlayerScore.str());
	score.setCharacterSize(65);
	score.setFillColor(Color(255,247,231));
	score.setPosition(595, 110);

	Texture cells;
	cells.loadFromFile("cells.png");
	
	int grid[4][4] = { 0 };
	Sprite cell[4][4];
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			cell[i][j].setTexture(cells);
		}
	}

	start(grid, cell);

	gameover end;

	while (window.isOpen()) {
		Event event;
		char oper = ' ';
		texts.restart.setFillColor(Color(219, 198, 166));
		texts.quit.setFillColor(Color(219, 198, 166));

		while (window.pollEvent(event)) {
			switch (event.type) {

			case Event::Closed:
					window.close();
					break;

			case Event::KeyPressed:
				switch (event.key.code) {
				case Keyboard::Left:
					oper = 'l';
					break;
				case Keyboard::Right:
					oper = 'r';
					break;
				case Keyboard::Up:
					oper = 'u';
					break;
				case Keyboard::Down:
					oper = 'd';
					break;
				}
				operations(grid, cell,player_score, oper);
				add(grid, cell);
				if (player_score > record_score) {
					record_score = player_score;
					fstream clear_file("record_score.txt", ios::out);
					clear_file.close();

					ofstream record("record_score.txt");
					record << record_score;
					record.close();

					BestScore.str("");
					BestScore << record_score;
					best_score.setString(BestScore.str());
					best_score_position(record_score, best_score);
				}
				PlayerScore.str("");
				PlayerScore << player_score;
				score.setString(PlayerScore.str());
				score_position(player_score, score);
				break;

			case Event::MouseButtonPressed:
				if (IntRect(680, 500, 50, 50).contains(Mouse::getPosition(window)))
					window.close();
				if (IntRect(500, 500, 50, 50).contains(Mouse::getPosition(window))) {
					start(grid, cell);
					player_score = 0;
					PlayerScore.str("");
					PlayerScore << player_score;
					score.setString(PlayerScore.str());
					score_position(player_score, score);
				}
				break;

			}
			
		}
		if (IntRect(680, 500, 50, 50).contains(Mouse::getPosition(window))) 
			texts.quit.setFillColor(Color(237, 153, 91));
		if (IntRect(500, 500, 50, 50).contains(Mouse::getPosition(window)))
			texts.restart.setFillColor(Color(237, 153, 91));


		window.clear(Color(250, 248, 239));

		window.draw(playing_square.square);
		for (int i = 0; i < 3; i++) {
			window.draw(playing_square.lineH[i]);
			window.draw(playing_square.lineV[i]);
		}
		window.draw(logo.sprite);
		window.draw(bloks.score);
		window.draw(bloks.best);
		window.draw(bloks.restart);
		window.draw(bloks.quit);
		window.draw(texts.score);
		window.draw(texts.best);
		window.draw(texts.restart);
		window.draw(texts.quit);
		window.draw(score);
		window.draw(best_score);
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				window.draw(cell[i][j]);
			}
		}
		
		window.display();
	}

	return 0;
}
