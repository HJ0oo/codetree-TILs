from collections import deque

N_large = 5
N_small = 3

def in_range(y, x):
    return 0 <= y < N_large and 0 <= x < N_large

def rotate(board, sy, sx, cnt):
    result = [row[:] for row in board]
    for _ in range(cnt):
        tmp = result[sy + 0][sx + 2]
        result[sy + 0][sx + 2] = result[sy + 0][sx + 0]
        result[sy + 0][sx + 0] = result[sy + 2][sx + 0]
        result[sy + 2][sx + 0] = result[sy + 2][sx + 2]
        result[sy + 2][sx + 2] = tmp
        tmp = result[sy + 1][sx + 2]
        result[sy + 1][sx + 2] = result[sy + 0][sx + 1]
        result[sy + 0][sx + 1] = result[sy + 1][sx + 0]
        result[sy + 1][sx + 0] = result[sy + 2][sx + 1]
        result[sy + 2][sx + 1] = tmp
    return result

def cal_score(board):
    score = 0
    visit = [[False for _ in range(N_large)] for _ in range(N_large)]
    dy, dx = [0, 1, 0, -1], [1, 0, -1, 0]

    for i in range(N_large):
        for j in range(N_large):
            if not visit[i][j]:
                q, trace = deque([(i, j)]), deque([(i, j)])
                visit[i][j] = True
                while q:
                    cur = q.popleft()
                    for k in range(4):
                        ny, nx = cur[0] + dy[k], cur[1] + dx[k]
                        if in_range(ny, nx) and board[ny][nx] == board[cur[0]][cur[1]] and not visit[ny][nx]:
                            q.append((ny, nx))
                            trace.append((ny, nx))
                            visit[ny][nx] = True
                if len(trace) >= 3:
                    score += len(trace)
                    while trace:
                        t = trace.popleft()
                        board[t[0]][t[1]] = 0
    return score

def fill(board, que):
    for j in range(N_large):
        for i in reversed(range(N_large)):
            if board[i][j] == 0 and que:
                board[i][j] = que.popleft()

# 코드 실행부
K, M = map(int, input().split())
board = [[0] * N_large for _ in range(N_large)]
for i in range(N_large):
    board[i] = list(map(int, input().split()))
q = deque(map(int, input().split()))

for _ in range(K):
    maxScore = 0
    maxScoreBoard = None
    for cnt in range(1, 4):
        for sx in range(N_large - N_small + 1):
            for sy in range(N_large - N_small + 1):
                rotated = rotate(board, sy, sx, cnt)
                # board 자체를 전달해 참조 유지를 위해 복사본 생성을 제거
                score = cal_score(rotated)
                if score > maxScore:
                    maxScore = score
                    maxScoreBoard = rotated
    if maxScoreBoard is None:
        break
    board = [row[:] for row in maxScoreBoard]
    while True:
        fill(board, q)
        newScore = cal_score(board)
        if newScore == 0:
            break
        maxScore += newScore

    print(maxScore, end=" ")