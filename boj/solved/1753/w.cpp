// writer: wjdghwls0514
#include <stdio.h>
#include <stdlib.h>
#include <queue>
using namespace std;

typedef struct node  // 노드의 정보를 담을 자료형
{
	int node_index, distance, edge_num;  // node_index: 현재 노드의 인덱스, distance: 현재 노드까지의 거리, edge_num: 연결된 edge의 개수
	bool check;  // 현재 노트 탐색 여부
	struct edge* first;  // 첫 번째 연결된 edge
} node;

typedef struct edge  // edge의 정보를 담을 자료형
{
	int edge_index, weight;  // edge_index: 연결된 node의 인덱스, weight: edge의 가중치
	struct edge* next;  // 다음으로 연결된 edge
} edge;

struct cmp  // 우선순위 큐에서 이용할 비교함수 -> 노드를 distance에 대해 오름차순으로 정렬
{
	bool operator() (node* node1, node* node2)
	{
		return (node1->distance > node2->distance);
	}
};

int V = 0, E = 0;
int start_node_index = 0;  // 시작 노드의 번호
node* head;  // 노드를 모아놓을 배열
int inf = 100000000;  // 연결되지 않았다는 정보를 표현할 변수
priority_queue<node*, vector<node*>, cmp> q;  // 노드의 인덱스를 오름차순으로 정렬할 우선순위 큐

void solve();  // 문제를 해결할 알고리즘 -> 다익스트라 알고리즘
void make_edge(int, int, int);  // edge를 연결할 함수
void clear_edge(int);  // 연결된 edge의 메모리를 해제할 함수
void search_edge(int);  // 연결된 edge 탐색

/*
solve 함수를 통해 문제를 푼다.
make_edge 함수를 통해 edge를 다 연결한 다음, 다익스트라 알고리즘을 적용하여 각 노드까지의 최단거리를 구한다.
  -> 노드에서 edge를 탐색할 때 search_edge 함수를 이용한다.
clear_edge 함수를 통해 edge의 메모리를 해제한다.
*/

int main()
{
	// 문제의 입력 조건과 변수 초기화
	scanf("%d %d", &V, &E);

	head = (node*)malloc(sizeof(node) * (V + 1));
	for (int i = 0; i <= V; i++)
	{
		head[i].node_index = i;
		head[i].distance = inf;
		head[i].edge_num = 0;
		head[i].check = false;
		head[i].first = NULL;
	}

	scanf("%d", &start_node_index);

	for (int i = 0; i < E; i++)
	{
		int u = 0, v = 0, w = 0;
		scanf("%d %d %d", &u, &v, &w);

		make_edge(u, v, w);
	}

	solve();  // 정답 찾고 출력
	for (int i = 1; i <= V; i++)
	{
		if (head[i].distance != inf) printf("%d\n", head[i].distance);
		else printf("INF\n");
	}

	for (int i = 1; i <= V; i++) clear_edge(i);  // edge의 메모리 해제
	free(head);  // head의 메모리 해제

	return 0;
}

void solve()  // 문제를 해결할 알고리즘 -> 다익스트라 알고리즘
{
	// 시작점부터 탐색
	head[start_node_index].distance = 0;
	q.push(head + start_node_index);
	search_edge(start_node_index);

	// 시작점 탐색 후 가장 짧은 거리로 도달한 노드를 탐색 (이전에 이미 탐색한 노드라면 pop) -> 반복 -> 모든 노드에서 탐색 후 종료 (계속 거리 갱신)
	while (!q.empty())
	{
		if (!q.top()->check) search_edge(q.top()->node_index);
		q.pop();
	}

	return;
}

void make_edge(int u, int v, int w)  // edge를 연결할 함수
{
	// 새로운 edge 생성
	edge* new_edge = (edge*)malloc(sizeof(edge));
	new_edge->edge_index = v;
	new_edge->weight = w;
	new_edge->next = NULL;

	int edge_num = head[u].edge_num;  // 현재 연결되어 있는 edge의 수

	if (edge_num)  // 이미 연결된 edge가 있을 때
	{
		edge* last = head[u].first;  // 연결된 edge 탐색 시작

		for (int i = 0; i < edge_num - 1; i++)  // edge 탐색
		{
			// 같은 노드로 연결되는 edge를 발견했을 때 -> 더 작은 weight를 갖고 있다면 weight 갱신 후 새로 만든 edge는 메모리 해제
			if (last->edge_index == v)
			{
				if (w < last->weight) last->weight = w;
				free(new_edge);
				return;
			}

			last = last->next;
		}

		last->next = new_edge;  // 맨 마지막 edge에 도달하면 그 뒤에 edge 연결
	}
	else head[u].first = new_edge;  // 연결된 edge가 없다면 node에 바로 연결

	head[u].edge_num++;
	return;
}

void clear_edge(int node_index)  // 연결된 edge의 메모리를 해제할 함수
{
	int edge_num = head[node_index].edge_num;  // 연결된 edge의 수
	edge* edge_for_delete = head[node_index].first;  // 삭제할 edge

	if (edge_num >= 2)  // 앞에 있는 edge부터 순서대로 지우기
	{
		for (int i = 0; i < edge_num - 1; i++)
		{
			edge* temp = edge_for_delete;
			edge_for_delete = edge_for_delete->next;
			free(temp);
		}
	}
	if (edge_num >= 1) free(edge_for_delete);  // edge가 하나 남았을 때 메모리 해제
	return;
}

void search_edge(int node_index)  // 연결된 edge 탐색 -> node1: 탐색할 노드
{
	// 현재 노드에 도달했다고 표시한 후 탐색
	head[node_index].check = true;
	edge* now_edge = head[node_index].first;
	int now_distance = head[node_index].distance;  // 현재 노드까지의 거리

	// 연결된 node까지의 최단거리를 발견하면 갱신 후 q에 넣기
	while (now_edge != NULL)
	{
		int edge_index = now_edge->edge_index;
		if (!head[edge_index].check && now_distance + now_edge->weight < head[edge_index].distance)
		{
			head[edge_index].distance = now_distance + now_edge->weight;
			q.push(head + edge_index);
		}

		now_edge = now_edge->next;
	}

	return;
}