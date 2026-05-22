#pragma once
class Location2D {
public:
	int row;
	int col;

	Location2D(int r = 0, int c = 0) {
		row = r;
		col = c;
	}
	//위치 p가 자신의 이웃인지 확인
	bool inNeighbor(Location2D& p) {
		return ((row == p.row && (col == p.col - 1 || col == p.col + 1)) || (col == p.col && (row == p.row - 1 || row == p.row + 1)));
	}
	//p가 자신과 같은 위치인지 검사 (연산자오버로딩)
	bool operator==(Location2D& p) {
		return row == p.row && col == p.col;
	}
};