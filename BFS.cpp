#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

const int VertexCount = 6;
int Matrix[VertexCount][VertexCount] =
{
	{0, 1, 0, 1, 0, 0},
	{1, 0, 1, 1, 0, 0},
	{0, 1, 0, 0, 0, 0},
	{1, 1, 0, 0, 1, 0},
	{0, 0, 0, 1, 0, 1},
	{0, 0, 0, 0, 1, 0}
};

bool Visited[VertexCount] = {};
int Distance[VertexCount] = {};	// 시작 지점으로부터 떨어진 거리
int Parent[VertexCount] = {};	// 해당 정점의 부모 Parent[1] = 0 : 1번 정점의 부모 == 0

void PrintShortestPath(int Start, int Dest)
{
	vector<int> Path;
	if (!Visited[Dest])
	{
		cout << "목적지까지 이동할 수 없음";
		return;
	}

	int CurrentNode = Dest;
	Path.push_back(Dest);

	while (CurrentNode != Start)
	{
		CurrentNode = Parent[CurrentNode];
		Path.push_back(CurrentNode);
	}

	reverse(Path.begin(), Path.end());

	for (int i = 0; i < Path.size(); i++)
	{
		cout << Path[i];

		if (i == Path.size() - 1)
		{
			break;
		}
		cout << "->";
	}
}

void BFS(int Start)
{
	queue<int> VertexQueue; // 예약목록
	VertexQueue.push(Start);// 시작지점 예약
	Visited[Start] = true;	// 방문했다
	Parent[Start] = Start;
	Distance[Start] = 0;

	// 큐가 비어있지 않다면 반복
	while (!VertexQueue.empty())
	{
		int Current = VertexQueue.front();
		VertexQueue.pop();

		/*cout << "방문: " << Current << "\n";
		cout << "부모: " << Parent[Current] << "\n";
		cout << "거리: " << Distance[Current] << "\n\n";*/

		for (int Next = 0; Next < VertexCount; Next++)
		{
			if (Matrix[Current][Next] == 0)
			{
				continue;
			}
			if (Visited[Next] == true)
			{
				continue;
			}

			VertexQueue.push(Next);
			Visited[Next] = true;
			Parent[Next] = Current;
			Distance[Next] = Distance[Current] + 1;
		}
	}
}

int main()
{
	BFS(0);
	PrintShortestPath(0, 5);

	return 0;
}