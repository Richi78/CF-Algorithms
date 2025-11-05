from datetime import datetime, timedelta

ok= "All OK"
one= "1 Point(s) Deducted"
two= "2 Point(s) Deducted"
three= "3 Point(s) Deducted"
issue= "Issue Show Cause Letter"
mp={
    0:ok , 1:one , 2:two , 3:three
}

lb=datetime.strptime(f"08:30:00","%H:%M:%S")

inD=datetime.strptime(f"09:30:00","%H:%M:%S")
inE=datetime.strptime(f"12:30:00","%H:%M:%S")

d=timedelta(hours=8)
e=timedelta(hours=9)

while True:
    n=int(input())
    if n==0: break
    cnt=0
    for _ in range(n):
        s=input().split(':')
        ini=datetime.strptime(f"{s[1]}:{s[2]}:{s[3]}","%H:%M:%S")
        fin=datetime.strptime(f"{s[4]}:{s[5]}:{s[6]}","%H:%M:%S")
        if ini < lb: 
            ini=lb
        
        # print(ini)
        # print(fin)
        
        if s[0]=='D':
            if ini > inD:
                # llega tarde
                cnt+=1
                # if fin-ini < d:
                    # cnt+=1
            else: 
                # no llega tarde
                if fin-ini < d:
                    cnt+=1

        else:
            if ini > inE:
                # llega tarde
                cnt+=1
                # if fin-ini < e:
                    # cnt+=1 
            else:
                # no llega tarde
                if fin-ini < e:
                    cnt+=1 
        # if cnt>3:
            # break
        # print(cnt)
        # print(fin-ini)

    if cnt>3:
        print(issue)
    else:
        print(mp[cnt])


