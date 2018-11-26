#pragma once

using namespace sf;

int koef(int a) {
	for (int k = 1; k < 12; k++) {
		if (a == pow(2, k)) return k;
	}
	if (a == 0) return a;
}

void operations(int grid[4][4], Sprite cell[4][4], int & score, char oper) {
	int tmp[4][4] = { 0 };
	switch (oper) {

	case 'l':
		for (int i = 0; i < 4; i++) {
			int p = 0;
			for (int j = 0; j < 4; j++) {
				if (grid[i][j] > 0) {
					tmp[i][p] = grid[i][j];
					grid[i][j] = 0;
					p++;
				}
			}
		}
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				if (tmp[i][j] == tmp[i][j + 1]) {
					tmp[i][j] = tmp[i][j] * 2;
					score += tmp[i][j];
					tmp[i][j + 1] = 0;
				}
			}
		}
		for (int i = 0; i < 4; i++) {
			int p = 0;
			for (int j = 0; j < 4; j++) {
				if (tmp[i][j] > 0) {
					grid[i][p] = tmp[i][j];
					tmp[i][j] = 0;
					p++;
				}
			}
		}
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				int s = 95;
				int k = koef(grid[i][j]);
				cell[i][j].setTextureRect(IntRect(s*k, 0, s, s));
			}
		}
		break;

	case 'r':
		for (int i = 0; i < 4; i++) {
			int p = 3;
			for (int j = 3; j >= 0; j--) {
				if (grid[i][j] > 0) {
					tmp[i][p] = grid[i][j];
					grid[i][j] = 0;
					p--;
				}
			}
		}
		for (int i = 0; i < 4; i++) {
			for (int j = 3; j >= 0; j--) {
				if (tmp[i][j] == tmp[i][j - 1]) {
					tmp[i][j] = tmp[i][j] * 2;
					score += tmp[i][j];
					tmp[i][j - 1] = 0;
				}
			}
		}
		for (int i = 0; i < 4; i++) {
			int p = 3;
			for (int j = 3; j >= 0; j--) {
				if (tmp[i][j] > 0) {
					grid[i][p] = tmp[i][j];
					tmp[i][j] = 0;
					p--;
				}
			}
		}
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				int s = 95;
				int k = koef(grid[i][j]);
				cell[i][j].setTextureRect(IntRect(s*k, 0, s, s));
			}
		}
		break;

	case'd':
		for (int i = 0; i < 4; i++) {
			int p = 3;
			for (int j = 3; j >= 0; j--) {
				if (grid[j][i] > 0) {
					tmp[p][i] = grid[j][i];
					grid[j][i] = 0;
					p--;
				}
			}
		}
		for (int i = 0; i < 4; i++) {
			for (int j = 3; j >= 0; j--) {
				if (tmp[j][i] == tmp[j - 1][i]) {
					tmp[j][i] = tmp[j][i] * 2;
					score += tmp[j][i];
					tmp[j - 1][i] = 0;
				}
			}
		}
		for (int i = 0; i < 4; i++) {
			int p = 3;
			for (int j = 3; j >= 0; j--) {
				if (tmp[j][i] > 0) {
					grid[p][i] = tmp[j][i];
					tmp[j][i] = 0;
					p--;
				}
			}
		}
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				int s = 95;
				int k = koef(grid[i][j]);
				cell[i][j].setTextureRect(IntRect(s*k, 0, s, s));
			}
		}
		break;

	case'u':
		for (int i = 0; i < 4; i++) {
			int p = 0;
			for (int j = 0; j < 4; j++) {
				if (grid[j][i] > 0) {
					tmp[p][i] = grid[j][i];
					grid[j][i] = 0;
					p++;
				}
			}
		}
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				if (tmp[j][i] == tmp[j + 1][i]) {
					tmp[j][i] = tmp[j][i] * 2;
					score += tmp[j][i];
					tmp[j + 1][i] = 0;
				}
			}
		}
		for (int i = 0; i < 4; i++) {
			int p = 0;
			for (int j = 0; j < 4; j++) {
				if (tmp[j][i] > 0) {
					grid[p][i] = tmp[j][i];
					tmp[j][i] = 0;
					p++;
				}
			}
		}
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				int s = 95;
				int k = koef(grid[i][j]);
				cell[i][j].setTextureRect(IntRect(s*k, 0, s, s));
			}
		}
		break;

	}
}
