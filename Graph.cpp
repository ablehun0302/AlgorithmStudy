#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <stack>

using namespace std;

vector<vector<int>> Map;

int M = 0;  // 맵 가로길이
int N = 0;  // 맵 세로길이
int K = 0;  // 배추 위치 좌표 갯수

int DirectionXY[4][2] =
{
    {1, 0}, {-1, 0}, {0, 1}, {0, -1}
};

void DFS(int X, int Y)
{
    // 맵 범위 밖이면 패스
    if (Y < 0 || X < 0 || Y >= N || X >= M)
    {
        return;
    }

    // 배추가 없거나 이미 들렀다면 패스
    if (Map[Y][X] == 0 || Map[Y][X] == 2)
    {
        return;
    }

    // 찾은 노드 == 2
    Map[Y][X] += 1;
    printf("%d %d\n", X, Y);

    for (auto Direction : DirectionXY)
    {
        int NewX = X + Direction[0];
        int NewY = Y + Direction[1];

        DFS(NewX, NewY);
    }
}

int main1()
{
    scanf("%d %d %d", &M, &N, &K);

    // 맵 만들기
    for (int y = 0; y < N; y++)
    {
        Map.push_back(vector<int>());
        for (int x = 0; x < M; x++)
        {
            Map[y].push_back(0);
        }
    }

    // 배추 심기
    for (int i = 0; i < K; i++)
    {
        int X = 0;
        int Y = 0;
        scanf("%d %d", &X, &Y);

        Map[Y][X] = 1;
    }

    cout << "-찾은노드-" << endl;

    int result = 0;
    // 맵 순환하며 DFS
    for (int y = 0; y < N; y++)
    {
        for (int x = 0; x < M; x++)
        {
            if (Map[y][x] == 1)
            {
                result++;
                DFS(x, y);
            }

        }
    }

    printf("%d", result);

    return 0;
}