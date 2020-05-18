// Check if a player won in a tic-tac-toe game

#include <iostream>
using namespace std;
 
int board[3][3];
int dir_x[] = {0, 1, 1, 1};
int dir_y[] = {1, 0, 1, -1};
 
bool check(char p, int x, int y, int dir) {
	int sm = 0;
	for (int i = 0; i < 3; ++i) {
		if (board[x][y] == p) ++sm;
		x += dir_x[dir];
		y += dir_y[dir];
	}
	return sm == 3;
}
 
bool chk(char p, int x, int y, int x_df, int y_df, int dir) {
	for (int i = 0; i < 3; ++i) {
		if (check(p, x, y, dir)) return true;
		x += x_df; y += y_df;
	}
	return false;
}
 
bool won(char p) {
	return chk(p, 0, 0, 1, 0, 0) || chk(p, 0, 0, 0, 1, 1) || 
	chk(p, 0, 0, 0, 0, 2) || chk(p, 0, 2, 0, 0, 3);
}
 
int main() {
	// your code goes here
	board[0][0] = 'x'; board[0][1] = 'o'; board[0][2] = 'o';
	board[1][0] = 'o'; board[1][1] = 'x'; board[1][2] = 'o';
	board[2][0] = 'o'; board[2][1] = 'o'; board[2][2] = 'o';
	if (won('x')) cout << "won" << endl;
	else cout << "no" << endl;
	return 0;
}
