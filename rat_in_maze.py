def issafe(maze,x,y,n):
    if x<n[0] and y<n[1] and maze[x][y]==1:
        return True
    return False

def findpath(maze,x,y,path,n):
    if x==n[0]-1 and y==n[1]-1:
        path[x][y]=1
        return True
    if issafe(maze,x,y,n):
        path[x][y]=1
        if findpath(maze,x+1,y,path,n):
            path[x+1][y]=1
            return True
        if findpath(maze,x,y+1,path,n):
            path[x][y+1]=1
            return True
        path[x][y]=0
        return False






#maze=[[1,1,1,1],[1,1,1,1],[0,1,0,0],[0,1,1,1]]
#n=4
print("Enter the size of square maze (row<space>col)")
n=list(map(int,input().split(" ")))
path=[[0 for i in range(n[1])]for j in range(n[0])]
path[0][0]=1
maze=[]
print("Enter the maze")
for i in range(n[0]):
    z=list(map(int,input().split(" ")))
    maze.append(z)
print("Your maze")
for i in range(n[0]):
    for j in range(n[1]):
        print(maze[i][j],' ',end="")
    print()
if findpath(maze,0,0,path,n)==False:
    print("Solution does not exist")
else:
    print("Solution")
    for i in range(n[0]):
        for j in range(n[1]):
            if path[i][j]==0:
                print(" -",end="")
            else:
                print(" 1",end="")
        print()
