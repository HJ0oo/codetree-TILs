import sys

sys.stdin=open('input.txt', 'r')

dxs = [0,1,1,1,0,-1,-1,-1]
dys = [1,1,0,-1,-1,-1,0,1]

sdxs = [-1,0,1,0]
sdys = [0,1,0,-1]

def select_santa(cow):
    r1,c1=cow
    close_dis=2500
    select_santa_num=0
    select_santa_loc=[0,0]
    for i in santa:
        r2,c2 = santa[i]
        dis = (r1-r2)**2 + (c1-c2)**2
        if dis < close_dis:
            select_santa_num=i
            select_santa_loc=[r2,c2]
            close_dis = dis
        elif dis == close_dis:
            if r2>select_santa_loc[0]:
                select_santa_num=i
                select_santa_loc=[r2,c2]
                close_dis = dis
            elif r2==select_santa_loc[0]:
                if c2>select_santa_loc[1]:
                    select_santa_num=i
                    select_santa_loc=[r2,c2]
                    close_dis = dis
                    
    return select_santa_num, select_santa_loc

def Interaction(crush_new_santa_num,dict_x,dict_y):
    
    x,y = santa[crush_new_santa_num]
    new_x = x + dict_x
    new_y = y + dict_y
    
    if not in_range(new_x,new_y):
        del santa[crush_new_santa_num]     # 보드 밖으로 나감
        faint[crush_new_santa_num] = 0
    else:
        TF, p_num = check(crush_new_santa_num,new_x,new_y)              # 새 위치에 산타가 있는지 없는지 확인 
        if not TF:                                  # 있는경우 상호작용 
            Interaction(p_num,dict_x,dict_y)
        
        santa[crush_new_santa_num] = [new_x,new_y]  # 상호작용이랑 상관없이 이동할건 해야지
            
        

def cow_crash(cow_loc,x1,y1,p_num,x2,y2,k):
    santa_score[p_num] += C
    dict_x = x1-cow_loc[0]
    dict_y = y1-cow_loc[1]
    
    x2 += dict_x*C
    y2 += dict_y*C
    
    if not in_range(x2,y2):
        del santa[p_num]      # 보드 밖으로 나감 
        faint[p_num] = 0
    else:
        faint[p_num] = 2            # 기절  # 두턴뒤에 풀림 
        TF,crush_new_santa_num = check(p_num,x2,y2)
        if not TF:
            # 상호작용 crush_new_santa_num
            Interaction(crush_new_santa_num,dict_x,dict_y)

        santa[p_num] = [x2,y2]  # 상호작용이랑 상관없이 이동할건 해야지

def santa_crash(p_num,x1,y1,k):
    santa_score[p_num] += D
    dict_x = santa[p_num][0] - x1
    dict_y = santa[p_num][1] - y1
    
    x1 += dict_x*D
    y1 += dict_y*D
    
    if not in_range(x1,y1):
        del santa[p_num]      # 보드 밖으로 나감 
        faint[p_num] = 0
    else:
        faint[p_num] = 1            # 기절  # 두턴뒤에 풀림 
        TF,crush_new_santa_num = check(p_num,x1,y1)
        if not TF:
            # 상호작용 crush_new_santa_num
            Interaction(crush_new_santa_num,dict_x,dict_y)
            
        santa[p_num] = [x1,y1]   # 상호작용이랑 상관없이 이동할건 해야지

def in_range(x,y):
    return 0<x<N+1 and 0<y<N+1

def check(p_num,x1,y1):
    for i in santa:
        if i == p_num:
            continue
        if santa[i] == [x1,y1]:
            return False, i
    return True, 0

def santa_move_rule(p_num,x1,y1,x2,y2):
    dis = (x1-x2)**2 + (y1-y2)**2
    new_x,new_y=x1,y1
    for dx,dy in zip(sdxs,sdys):
        nx=x1+dx
        ny=y1+dy
        
        if in_range(nx,ny):
            new_dis = (nx-x2)**2 + (ny-y2)**2
            if new_dis < dis:
                TF,_ = check(p_num,nx,ny)
                if TF:
                    dis = new_dis
                    new_x,new_y=nx,ny
    return new_x,new_y                

def cow_move_rule(x1,y1,x2,y2):
    if x1>x2:
        x1 -= 1
    elif x1<x2:
        x1 += 1
    else:
        x1 = x1 
    
    if y1>y2:
        y1 -= 1
    elif y1<y2:
        y1 += 1
    else:
        y1 = y1
    
    return x1,y1    

# 루돌프 움직임 
def cow_move(cow_loc,k):
    x1,y1 = cow_loc
    p_num, [x2,y2] = select_santa(cow_loc)
    x1,y1 = cow_move_rule(x1,y1,x2,y2)

    # 만약 루돌프가 산타랑 충돌할때 
    if [x1,y1]==[x2,y2]:
        cow_crash(cow_loc,x1,y1,p_num,x2,y2,k)
    
    return [x1,y1]


# 산타 움직임 
def santa_move(cow_loc,k):
    x2,y2=cow_loc
    for i in range(1,P+1):
        if santa.get(i)==None:
            continue
        if faint[i]!=0:          # 기절한 산타는 움직임 없음 
            faint[i]-=1
            continue
        
        x1,y1=santa[i]
        x1,y1 = santa_move_rule(i,x1,y1,x2,y2)
        
        # 산타가 움직였는데 루돌프랑 부딪칠 경우 
        if [x1,y1] == [x2,y2]:
            santa_crash(i,x1,y1,k)
        else:
            santa[i]=[x1,y1]

    
if __name__=="__main__":
    # N:게임격자, M: 게임턴수, P:산타개수, C:루돌프 힘, D: 산타의 힘
    N,M,P,C,D = map(int, input().split())   
    board = [[0]*(N+1) for _ in range(N+1)]
    cow_loc = list(map(int, input().split()))   # 소의 위치 (Rr, Rc)
    
    santa = {}
    for _ in range(P):
        pid,x,y=map(int, input().split())
        santa[pid]=[x,y]
    

    # 기절 상태 기록 
    faint = [0]*(P+1)
    santa_score = [0]*(P+1)

    total_score = 0
    # 게임 플레이수 M
    for k in range(1,M+1):
        # 루돌프 움직이고 
        cow_loc = cow_move(cow_loc,k)

        if len(santa)==0:
            break
        
        # 1번 산타부터 P번산타까지 산타들 움직임 
        santa_move(cow_loc,k)

        if len(santa)==0:
            break
        
        for pid in santa:
            santa_score[pid] += 1

        
    print(*santa_score[1:])