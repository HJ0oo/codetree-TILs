import sys 
import heapq
# sys.stdin=open('input.txt','r')
input=sys.stdin.readline


# 상우하좌 
pdxs=[-1, 0, 1,  0]
pdys=[0,  1, 0, -1]

def in_range(nx,ny):
    return 0<nx<N+1 and 0<ny<N+1

def Distance(r1,c1, r2,c2):
    return (r1-r2)**2 + (c1-c2)**2

# 상호작용
def Interaction(nx,ny,dx,dy):
    global all_in_board
    origin_player_id=board[nx][ny]
    origin_player_loc=playerIdToIndx[origin_player_id]
    opx,opy=origin_player_loc
    nx=opx+dx
    ny=opy+dy
    if not in_range(nx,ny):
        del playerIdToIndx[origin_player_id] # 삭제 
        all_in_board-=1
        is_in_board[origin_player_id]=False
        return
    
    if board[nx][ny]>0: # 튕겨져나간 새 위치에 또 참가자가 있으면 
        Interaction(nx,ny,dx,dy)
    
    board[nx][ny]=origin_player_id
    playerIdToIndx[origin_player_id]=[nx,ny]
    
     

# 충돌 2. 참가자가 소를 박음 
def crush_player_to_cow(t,pid,dir):
    global board, cow_loc, players_score, all_in_board
    px,py=playerIdToIndx[pid]
    nx,ny=cow_loc
    players_score[pid]+=D       # D만큼 점수를 얻음 
    panic_time[pid]=t+1
    dx=-pdxs[dir]               # 반대방향 
    dy=-pdys[dir]
    
    nx=nx+dx*D
    ny=ny+dy*D
    if not in_range(nx,ny):     # 튕겨져 나간곳이 격자 밖이면 
        board[px][py]=0
        del playerIdToIndx[pid] # 삭제 
        all_in_board-=1
        is_in_board[pid]=False
        return 
            
    
    if board[nx][ny]>0: # 튕겨져 나간 곳에 사람이 있으면 
        Interaction(nx,ny,dx,dy)
    
    # 아니면 튕겨져나간곳이 새로운 그사람 위치 
    playerIdToIndx[pid]=[nx,ny]
    board[px][py]=0
    board[nx][ny]=pid

    
    
# 참가자 움직임 
def player_move(t,pid):
    global board, cow_loc

    cx,cy=cow_loc
    px,py=playerIdToIndx[pid]
    possible_loc=[]
    cur_dis=Distance(px,py, cx,cy)
    for dir in range(4):
        nx=px+pdxs[dir]
        ny=py+pdys[dir]
        if in_range(nx,ny) and board[nx][ny]<=0: 
            dis=Distance(nx,ny, cx,cy)
            if dis<cur_dis:
                priority=[dis,dir,nx,ny]
                heapq.heappush(possible_loc,priority)
            
    if len(possible_loc)==0:             # 4가지 경우 중 모두 없는 경우 끝냄 
        return

    dis,dir,nx,ny=heapq.heappop(possible_loc)
    board[px][py]=0
    if (nx,ny)==(cx,cy):    # 참가자가 소를 박음 
        crush_player_to_cow(t,pid,dir)
    else:
        # 참가자가 소를 박은게 아니라면 
        # 참가자 이동 
        board[nx][ny]=pid
        playerIdToIndx[pid]=[nx,ny]


# 충돌 1. 소가 참가자를 박음  dir=[dirX,dirY]
def crush_cow_to_player(t,cx,cy,dir):
    global board, cow_loc, players_score, all_in_board
    pid=board[cx][cy]
    px,py=playerIdToIndx[pid]
    if playerIdToIndx[pid]!=[cx,cy]:
        raise Exception('Error')
    players_score[pid]+=C           # C만큼 점수를 얻음 
    panic_time[pid]=t+1
    px,py=playerIdToIndx[pid]
    nx,ny=px,py
    dx=dir[0]               # 반대방향 
    dy=dir[1]

    nx=nx+dx*C
    ny=ny+dy*C
    if not in_range(nx,ny):     # 격자를 벗어남
        board[px][py]=0         # 그 위치에 있던 사람은 없어지고 
        del playerIdToIndx[pid] # 삭제 
        all_in_board-=1
        is_in_board[pid]=False
        return
    
    if board[nx][ny]>0: # 튕겨져 나간 곳에 사람이 있으면 
        Interaction(nx,ny,dx,dy)
    
    # 기존사람이 있든 없든 튕겨진 사람은 새로운 위치로  
    playerIdToIndx[pid]=[nx,ny]
    board[px][py]=0         # 기존 위치는 비우고 
    board[nx][ny]=pid   

# 소 움직임 
def cow_move(t):
    global board, cow_loc
    cx,cy=cow_loc

    # 가장 가까운 참가자부터 찾는다. 
    Finalx, Finaly, FinalId = 10000, 10000, 0
    for pid in range(1, P + 1):
        if not is_in_board[pid]:
            continue
        
        if playerIdToIndx[pid]==None:   # PID 참가자가 없으면 다음 참가자 
            continue
        px,py=playerIdToIndx[pid]
        # 거리, 행, 열 순으로 우선순위
        farest_dis = [Distance(cx,cy,Finalx,Finaly), [-Finalx, -Finaly]]  
        PID_dis = [Distance(cx,cy,px,py), [-px, -py]] 

        if PID_dis < farest_dis:
            Finalx, Finaly = playerIdToIndx[pid]
            FinalId = pid

    # 가장 가까운 산타의 방향으로 루돌프가 이동합니다.
    if FinalId:      # 위 for문에서 조건을 만족 안해서 FinalId가 0을 유지했다면 이 조건문 안들어감 
        
        dirX = 0
        if Finalx > cx:   # 현재 소위치보다 가장 가까운 참가자의 위치의 행이 더 크면 
            dirX = 1               # 소 행으로 1만큼 이동 
        elif Finalx < cx: # 현재 소 위치보다 더 위에 있으면 
            dirX = -1              # 소 위로 이동 

        dirY = 0
        if Finaly > cy:   # 소보다 오른쪽에 있으면 오른쪽으로 이동 
            dirY = 1
        elif Finaly < cy: # 소보다 왼쪽에 있으면 왼쪽으로 이동 
            dirY = -1

        cow_loc = [cx + dirX, cy + dirY]  # 소 위치 새 위치로 업데이트 
        board[cx][cy] = 0                   # 기존 소 위치 비워 두기 
        
        dir=[dirX,dirY]                   # 방향 
        
        nx,ny=cow_loc
        px,py=playerIdToIndx[FinalId]
        if (px,py)==(nx,ny) or board[nx][ny]!=0:                # 소의 새 위치에 사람이 있으면 
            crush_cow_to_player(t,nx,ny,dir)

        
        # 참가자랑 박치기를 하든 안하든 소가 이동만 한다 
        board[nx][ny]=-1
        cow_loc=[nx,ny]
            
    # 가장 가까운 참가자가 없거나 이동할 필요가 없으면 이동 안함             
        

def simulation(t):
    cow_move(t)

    # 만약 P 명의 산타가 모두 게임에서 탈락하게 된다면 그 즉시 게임이 종료됩니다.
    if all_in_board==0:
        return 
    
    for pid in range(1,P+1):  
        if not is_in_board[pid]:    # pid가 격자위에 없으면 다음 참가자 확인하기 
            continue
        if panic_time[pid]<t:
            player_move(t, pid)

        # 만약 P 명의 산타가 모두 게임에서 탈락하게 된다면 그 즉시 게임이 종료됩니다.
        if all_in_board==0:
            return
    # 매 턴 이후 아직 탈락하지 않은 산타들에게는 1점씩을 추가로 부여합니다.
    for pid in playerIdToIndx:
        players_score[pid]+=1

if __name__=="__main__":
    # N:게임격자, M: 게임턴수, P:산타개수, C:루돌프 힘, D: 산타의 힘 
    N, M, P, C, D = map(int, input().split())
    cow_loc=list(map(int, input().split()))
    
    board=[[0]*(N+1) for _ in range(N+1)]
    board[cow_loc[0]][cow_loc[1]]=-1
    
    playerIdToIndx={}                           # 참가자수 다 확인하며 점수를 부여하지 않기 위해 
    
    players_score=[0]*(P+1)                     # 참가자 점수 
    all_in_board=P                              # 격자위 참가자 수 
    panic_time=[0]*(P+1)                        # 참가자당 기절 시간
    is_in_board=[False]*(P+1)                   # 참가자당 격자위에 있는지 유무
    
    for _ in range(1,P+1):
        pid,x,y,=map(int, input().split())
        board[x][y]=pid
        playerIdToIndx[pid]=[x,y]
        is_in_board[pid]=True
    
    for t in range(1,M+1):
        simulation(t)
        if all_in_board==0:
            break

    print(*players_score[1:])