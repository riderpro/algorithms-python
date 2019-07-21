#codevita solution 1
arr=[]
arr=input().strip()
arr=list(arr.split(sep=None))
if not arr:
    print("error")
    exit()
if len(arr[0])>5:
    print("error")
    exit()

for q in arr[0]:
    if q.isalpha():
        if(ord(q)>90):
            print("error")
            exit()
        if(ord(q)<65):
            print("error")
            exit()
base=[]
newno=[]
oldno=[]
#if len(str(arr[0]))==1:
 #   if arr[0].isdigit():
  #      res=arr
while 1 :
    for x in arr:
        num=x
        max = 0
        maxAL = '\x00'
        #print(type(num))
        for y in num:
            if y.isdigit():
                y=int(y)
                if y>max:
                    max=y+1
            else:
                if y>maxAL:
                    maxAL=y
            if max < (ord(maxAL)-54):
                max= ord(maxAL)-54
        #print(" max ",max)
        base.append(max)
    #print(base)


    s = 0
    for i in range(len(arr)):
        x = arr[i]
        # num=x[::-1]
        # print(num)
        l = len(x) - 1
        z = base[i]
        for y in x:
            if y.isdigit():
                y = int(y)
                s = s + y * (z ** l)

            else:
                s = s + (ord(y) - 55) * (z ** l)
            l = l - 1
        # print("conv",s)
        newno.append(s)
        s = 0
    #print(newno)
    #print("oldno",oldno)
    #print("newno", newno)
    if oldno==list(map(str,newno)):
        break
    arr=list(map(str,newno))
    oldno=list(map(str,newno))
    #print(arr)
    base.clear()
    newno.clear()
res=arr[0]
print(res,end='')
