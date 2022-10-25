#include <stdio.h>
typedef struct{char* babi;int asu;}Capek;
void setChar(Capek *C, char* babi){C->babi = babi;}
void setInt(Capek *C, int asu){C->asu = asu;}
int main(){Capek lelah;setChar(&lelah, "====D");setInt(&lelah, 8);printf("%d%s", lelah.asu, lelah.babi);return 0;}