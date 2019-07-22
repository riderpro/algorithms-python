def issafe(arr,row,col):
    n=len(arr)
    for i in range(col):
        if arr[row][i]==1:
            return False
    # #check upper left diagonal
    # i=row-1
    # j=col-1
    # while(i>-1 and j>-1):
    #     if arr[i][j]==1:
    #         return False
    #     i-=1
    #     j-=1
    # #check lower left diagonal
    # i=row+1
    # j=col-1
    # while(i<n and j>-1):
    #     if arr[i][j]==1:
    #         return False
    #     i+=1
    #     j-=1
    # Check upper diagonal on left side 
    for i, j in zip(range(row, -1, -1), range(col, -1, -1)): 
        if arr[i][j] == 1: 
            return False
  
    # Check lower diagonal on left side 
    for i, j in zip(range(row, n, 1), range(col, -1, -1)): 
        if arr[i][j] == 1: 
            return False
    return True
        
def nqueen(arr,col):
    n=len(arr)
    print(n)
    if col>=n:
        return True
    for i in range(n):
        if issafe(arr,i,col):
            arr[i][col]=1
            if nqueen(arr,col+1)==True:
                return True
            arr[i][col]=0
    print(arr)
    print("iter")
    return False
if __name__=='__main__':
    n=int(input("Enter the value of n for n queen problem"))
    arr=[[0]*n]*n
    
    if nqueen(arr,0)==False:
        print("no solution")
    
    for i in range(n):
        print(" ".join(map(str,arr[i])))