void Uncover_Corps_Basement(input)
{
  int check;
  check = strings_not_equal(input,"Welcome to Holo Number 5.");
  if (check != 0) {
    illegal_move();
  }
  return;
}