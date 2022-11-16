int func4(int a,int b)
{
  int temp1;
  int temp2;
  
  temp2 = 0;
  if ((0 < a) && (temp2 = b, a != 1)) {
    temp1 = func4(a + -1,b);
    temp2 = func4(a + -2,b);
    temp2 = temp2 + temp1 + b;
  }
  return temp2;
}

void Secret_Society(input)
{
    int temp;
    int x;
    int y;
    temp = sscanf(input,"%d %d",&y,&x);
    if ((temp != 2) || (2 < x - 2U)) {
        illegal_move();
    }
    temp = func4(6,x);
    if (y != temp) {
        illegal_move();
    }
    return;
}