#rom array import *

n=int(input("enter size"))
arr=[]
for i in range(n):
    x=int(input("enter value="))
    arr.append(x)

for i in range(n-1):
    for j in range(i+1,n):
        if arr[i]>arr[j]:
            arr[i],arr[j]=arr[j],arr[i]

print(arr)