arr=[]
n=int(input("enter size="))
for i in range(n):
    x=int(input("enter value="))
    arr.append(x)
key=int(input("enter key ="))
if key in arr:
    print("number found")
else:
    print("number not found")