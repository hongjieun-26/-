#include "AdjMatGraph.h"  // 그래프 클래스 포함

int main() {
    //AdjMatGraph g;    // 새로운 그래프 객체 생성
    SrchAMGraph g;  // DFS 탐색기능이 있는 그래프 객체 생성

    for (int i = 0; i < 7; i++)
        g.insertVertex('A' + i);	// 정점 삽입: 'A' 'B', ...
    g.insertEdge(0, 1);      	// 간선 삽입
    g.insertEdge(0, 3);
    g.insertEdge(1, 2);
    g.insertEdge(1, 3);
    g.insertEdge(2, 3);
    printf("인접 행렬로 표현한 그래프\n");
    g.display();

    FILE* fp;
    fopen_s(&fp, "../Text_out.txt", "w"); // ../ <-상위 폴더에 생성하라는 명령어
    g.display(fp);
    fclose(fp);

    // 깊이 우선 탐색 테스트 프로그램
    printf("그래프(graph.txt)\n");
    g.display();

    printf("DFS ==> ");
    g.reserVisited(); //모든 정점 방문하지 않았다고 하고
    g.DFS(0);         //0번째 정점(A)에서 깊이우선탐색 시작
    printf("\n");

    return 0;

}
