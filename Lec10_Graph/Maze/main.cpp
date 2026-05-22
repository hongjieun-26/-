#include "Location2D.h"
#include <stack>
#include <queue> // 1. BFS 사용을 위해 queue 헤더 추가
using namespace std;

#define MAZE_SIZE   6
char map[MAZE_SIZE][MAZE_SIZE] = {
	{'1', '1', '1', '1', '1', '1'},
	{'e', '0', '1', '0', '0', '1'},
	{'1', '0', '0', '0', '1', '1'},
	{'1', '0', '1', '0', '1', '1'},
	{'1', '0', '1', '0', '0', 'x'},
	{'1', '1', '1', '1', '1', '1'},
};

// 2. 아래에서 미로를 원래대로 되돌릴 때 사용할 백업용 원본 배열 선언
char original_map[MAZE_SIZE][MAZE_SIZE] = {
	{'1', '1', '1', '1', '1', '1'},
	{'e', '0', '1', '0', '0', '1'},
	{'1', '0', '0', '0', '1', '1'},
	{'1', '0', '1', '0', '1', '1'},
	{'1', '0', '1', '0', '0', 'x'},
	{'1', '1', '1', '1', '1', '1'},
};

bool isValidLoc(int r, int c) {
	if (r < 0 || c < 0 || r >= MAZE_SIZE || c >= MAZE_SIZE)
		return false;
	else
		return map[r][c] == '0' || map[r][c] == 'x';
}

int main() {
	int ds_num;
	printf("DFS데이터 구조 라이브러리 선택: 1)stack 2)deque \n");
	scanf_s("%d", &ds_num);
	stack<Location2D> locStack;

	switch (ds_num) {
	case 1:
		//stack 데이터구조 사용
	{
		printf("DFS 미로 탐색 (Stack) \n");
		stack<Location2D> locStack;
		Location2D entry(1, 0);
		locStack.push(entry);

		while (locStack.empty() == false) {
			Location2D here = locStack.top();
			locStack.pop();

			int r = here.row, c = here.col;
			printf("(%d,%d) ", r, c);
			if (map[r][c] == 'x') {
				printf("미로 탐색 성공\n");
				break; // 3. return; 대신 break;를 써야 코드가 안 꺼지고 아래 BFS로 넘어갑니다.
			}
			else {
				map[r][c] = '.';
				if (isValidLoc(r - 1, c)) locStack.push(Location2D(r - 1, c));
				if (isValidLoc(r + 1, c)) locStack.push(Location2D(r + 1, c));
				if (isValidLoc(r, c - 1)) locStack.push(Location2D(r, c - 1));
				if (isValidLoc(r, c + 1)) locStack.push(Location2D(r, c + 1));
			}
		}
		// 4. 원래 있던 미로 탐색 실패 메시지를 중괄호 내부 맨 뒤로 정렬
		if (locStack.empty() && map[4][5] != '.') {
			printf("미로 탐색 실패\n");
		}
		break; // case 1 안전 종료
	}
	case 2:
		//deque 데이터구조 사용
	{
		printf("DFS 미로 탐색 (Deque) \n");
		deque<Location2D> locDeque;
		Location2D entry(1, 0);
		locDeque.push_front(entry);

		while (locDeque.empty() == false) {
			Location2D here = locDeque.front();
			locDeque.pop_front();

			int r = here.row, c = here.col;
			printf("(%d,%d) ", r, c);
			if (map[r][c] == 'x') {
				printf("미로 탐색 성공\n");
				break; // 5. 마찬가지로 무조건 아래로 가게 하기 위해 break;로 변경
			}
			else {
				map[r][c] = '.';
				if (isValidLoc(r - 1, c)) locDeque.push_front(Location2D(r - 1, c));
				if (isValidLoc(r + 1, c)) locDeque.push_front(Location2D(r + 1, c));
				if (isValidLoc(r, c - 1)) locDeque.push_front(Location2D(r, c - 1));
				if (isValidLoc(r, c + 1)) locDeque.push_front(Location2D(r, c + 1));
			}
		}
		if (locDeque.empty() && map[4][5] != '.') {
			printf("미로 탐색 실패\n");
		}
		break; // case 2 안전 종료
	}
	} // switch 문 마감 괄호

	// ====================================================
	// 이 아래는 무조건 이어서 실행되는 BFS 미로 탐색 영역입니다.
	// ====================================================
	printf("\nBFS로 미로탐색\n");

	// 6. 앞의 DFS가 더럽혀놓은 미로 지도를 깨끗하게 원상복구(리셋)합니다.
	for (int i = 0; i < MAZE_SIZE; i++) {
		for (int j = 0; j < MAZE_SIZE; j++) {
			map[i][j] = original_map[i][j];
		}
	}

	//BFS로 미로탐색 구현
	queue<Location2D> locQueue; // 큐 선언
	Location2D entry(1, 0);
	locQueue.push(entry);       // 시작점 큐에 삽입

	while (locQueue.empty() == false) {
		Location2D here = locQueue.front(); // 가장 먼저 들어온 데이터 확인
		locQueue.pop();                     // 큐에서 제거

		int r = here.row, c = here.col;
		printf("(%d,%d) ", r, c);

		if (map[r][c] == 'x') {
			printf("미로 탐색 성공\n");
			return 0; // 모든 작업이 끝났으므로 완전 종료
		}
		else {
			map[r][c] = '.'; // 방문 마킹
			if (isValidLoc(r - 1, c)) locQueue.push(Location2D(r - 1, c));
			if (isValidLoc(r + 1, c)) locQueue.push(Location2D(r + 1, c));
			if (isValidLoc(r, c - 1)) locQueue.push(Location2D(r, c - 1));
			if (isValidLoc(r, c + 1)) locQueue.push(Location2D(r, c + 1));
		}
	}
	printf("미로 탐색 실패\n");

	return 0;
}