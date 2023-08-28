#include <stdio.h>

struct game{
	char player;
	char board[3][3];
} ;

void clearScreen() {
	system("cls");
}

int verifyWin(struct game* table, char piece) {
	
	if (table->board[0][0] == piece && table->board[1][1] == piece && table->board[2][2] == piece) {
		return 1;
	}
	else if (table->board[0][2] == piece && table->board[1][1] == piece && table->board[2][0] == piece) {
		return 1;
	}
	else {
		for (int i = 0; i < 3; i++) {
			if (table->board[i][0] == piece && table->board[i][1] == piece && table->board[i][2] == piece) {
				return 1;
			}
		}

		for (int i = 0; i < 3; i++) {
			if (table->board[0][i] == piece && table->board[1][i] == piece && table->board[2][i] == piece) {
				return 1;
			}
		}
	}
	return 0;
}

void fillTable(struct game *table) {
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			table->board[i][j] = ' ';
		}
	}
}

void printTable(struct game *table) {
	clearScreen();
	for (int i = 0; i < 3; i++) {
		printf("%d ", i);
		for (int j = 0; j < 3; j++) {
			printf("%c", table->board[i][j]);
			if (j == 2) {
				printf("\n");
			}
		}
	}
	printf("  012\n");
}

int setPosition(struct game *table, char pos1, char pos2, char piece) {
	if (table->board[pos1][pos2] != ' ') {
		printf("Can't place piece here");
		return 0;
	}
	else {
		printf("Piece '%c' placed!\n", piece);
		table->board[pos1][pos2] = piece;
		return 1;
	}
}

int main() {

	struct game table;
	table.player = 'x';

	fillTable(&table);
	
	int pos1, pos2;

	while (!verifyWin(&table, table.player)) {

		printTable(&table);

		printf("Player '%c' turn\n", table.player);
		printf("Choose position x and y\n");
		scanf_s("%d", &pos1);
		scanf_s("%d", &pos2);
		getchar();

		if (pos1 >= 0 && pos1 < 3 && pos2 >= 0 && pos2 < 3) {
			if (setPosition(&table, pos1, pos2, table.player)) {
				table.player = (table.player == 'x') ? 'o' : 'x';
			}
		}
	}
	printf("Winner: %c", table.player);
	return 0;
}