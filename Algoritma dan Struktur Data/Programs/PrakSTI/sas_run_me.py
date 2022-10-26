# Y TINGGAL DI RUN AJA AWIKWOK
a_wik = ["────────────────","─██████──██████─","─██░░██──██░░██─","─██░░██──██░░██─","─██░░██──██░░██─","─██░░██──██░░██─","─██░░██──██░░██─","─██░░██──██░░██─","─██░░██──██░░██─","─██░░██████░░██─","─██░░░░░░░░░░██─","─██████████████─","────────────────"]
w_ok = ["────────────","─██████████─","─██░░░░░░██─","─████░░████─","───██░░██───","───██░░██───","───██░░██───","───██░░██───","───██░░██───","─████░░████─","─██░░░░░░██─","─██████████─","────────────"]
for i in range(len(w_ok)):
    print(f'         {w_ok[i]}')
alp = [chr(i) for i in range(97, 123)]
s = [alp[18], alp[0], alp[18], alp[8]]
a = 9
b = 3
ind = 0
for i in range(b,-1,-1):
  for x in range(2):
    for j in range(i):
      print(end=' ')
    for j in range(a):
      print(s[ind], end='')
      ind = (ind+1)%len(s)
    if (x == 0):
      for j in range(i):
        print(end=' ')
  a += 2
  print()
a = 15
b = 0
while(a > 0):
  for i in range(b):
    print(end=' ')
  for i in range(2*a):
    print(s[ind], end='')
    ind = (ind+1)%len(s)
  print()
  a -= 1
  b += 1
for i in range(len(a_wik)):
    print(f'       {a_wik[i]}')
input()