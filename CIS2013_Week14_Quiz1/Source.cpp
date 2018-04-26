#include <iostream>
#include <cstring>
using namespace std;

class Game {
	string name;
	int score;

public:
	Game() {
		score = 0;
		name = "No Name";
	}
	Game(string new_name) {
		score = 0;
		name = new_name;
	}



	string get_name() {
		return name;
	}
	string set_name(string new_name) {
		name = new_name;
		return name;
	}
	int get_score() {
		return score;
	}
	int set_score(int new_score){
		score = new_score;
		return score;
	}
};

class Mine_sweeper: public Game {
	int board_rows, board_columns;
	int **bomb_squares;
	char** selected_squares;
public: 
	Mine_sweeper(int y, int x, int mines) : Game("Minesweeper"){
		
		//generates empty board array
		selected_squares = new char*[y];
		for (int i = 0; i < y; ++i) {
			selected_squares[i] = new char[x];
		}
		//fills in board 
		for (int a = 0; a < y; a++) {
			for (int b = 0; b < x; b++) {
				selected_squares[b][a] = '.';
			}
		}
		////generates key array
		//for (int a = 0; a < y; a++) {
		//	for (int b = 0; b < x; b++) {
		//		bomb_squares[b][a] = 0;
		//	}
		//}
		////adds random bombs
		//for (int i = 0; i < mines; i++) {
		//	int num1 = rand() % x;
		//	int num2 = rand() % y;
		//	bomb_squares[num1][num2] = 1;

		//}
		
	}
	void print_board(int x, int y){
		cout << "    ";
		for (int i = 1; i <= y; i++) {
			if (i > 9) {
				cout << i << " ";
			}
			else { cout << i << "  "; }
		}
		cout << endl;

		for (int a = 0; a < x; a++) {
			if (a < 9) {
				cout << " ";
			}
			cout << a + 1;

			for (int b = 0; b < y; b++) {
				//writes board array
				cout << "  " << selected_squares[a][b];
			}
			cout << endl;
		}
	}
	bool get_square(int x, int y) {
		//return true;

		/*if (bomb_squares[x][y] == 1) {
			cout << "You hit a bomb, game over.\n\n\n";
			return false;
		}*/
	
			selected_squares[x][y] = '0';
			return true;
		
	}
};

int main() {
	char cont = 'y';
	bool contin = true;
	int col, row, mines;
	while (cont == 'y') {
		cout << "\n\nWelcome to Minesweeper.\nHow many rows?\n";
		cin >> row;
		cout << "\nHow many columns?\n";
		cin >> col;
		cout << "\nHow many mines?\n";
		cin >> mines;
		Mine_sweeper newGame(row,col,mines);

		while(contin == true) {
			int x, y;
			newGame.print_board(row,col);
			cout << "Enter coordinates\n";
			cin >> x >> y;
			if (!newGame.get_square(y-1, x-1)) {
				contin = false;
			}
		}

		cout << "Would you like to continue? (y)";
		cin >> cont;
	}
}
