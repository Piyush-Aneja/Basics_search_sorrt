arr=[]
n=int(input("enter size="))
for i in range(n):
    x=int(input("enter value="))
    arr.append(x)
key=int(input("enter key to search:"))
mid=0
first=0
last=n-1
while first<=last :
    mid=(first+last)//2
    if arr[mid]==key:
        print("number found at {0} location ".format(mid))
        break
    elif arr[mid]<key:
        first=mid+1
    else:
        last=mid-1
else:
    print("number not found")