void Holoh3ro(input)
{
  int temp;
  int y;
  int x;
  
  temp = sscanf(input,"%d %d",&y,&x);
  if (temp < 2) {
    illegal_move();
  }

  switch(y) {
    case 0:
        temp = 0x164;
        break;
    case 1:
        temp = 0x32c;
        break;
    case 2:
        temp = 0x35f;
        break;
    case 3:
        temp = 0x299;
        break;
    case 4:
    case 5:
        temp = 0x10d;
        break;
    case 6:
        temp = 0x114;
        break;
    case 7:
        temp = 0x200;
        goto FLAG;
    default:
        temp = 0;
    FLAG:
        illegal_move();
  }

  if (temp + x != 0) {
    illegal_move();
  }
  
  return;
}