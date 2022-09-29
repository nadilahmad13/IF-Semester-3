// NIM              : 13521024
// Nama             : Ahmad Nadil
// Tanggal          : 27 September 2022
// Topik praktikum  : ADT Mesin Kata
// Deskripsi        : File "wordmachine.c"

#include <stdio.h>
#include "boolean.h"
#include "wordmachine.h"

boolean endWord;
Word currentWord;

void IgnoreBlanks()
/* Mengabaikan satu atau beberapa BLANK
   I.S. : currentChar sembarang
   F.S. : currentChar ≠ BLANK atau currentChar = MARK */
{
   while (currentChar == BLANK) {
      ADV();
   }
}
void STARTWORD()
/* I.S. : currentChar sembarang
   F.S. : endWord = true, dan currentChar = MARK;
          atau endWord = false, currentWord adalah kata yang sudah diakuisisi,
          currentChar karakter pertama sesudah karakter terakhir kata */
{
   START();
   IgnoreBlanks();         chars = (int) currentChar;

void ADVWORD()
/* I.S. : currentChar adalah karakter pertama kata yang akan diakuisisi
   F.S. : currentWord adalah kata terakhir yang sudah diakuisisi,
          currentChar adalah karakter pertama dari kata berikutnya, mungkin MARK
          Jika currentChar = MARK, endWord = true.
   Proses : Akuisisi kata menggunakan procedure SalinWord */
{
   IgnoreBlanks();
   if (currentChar == MARK){
      endWord = true;
   }
   else{
      CopyWord();
      IgnoreBlanks();
   }
}

void CopyWord()
/* Mengakuisisi kata, menyimpan dalam currentWord
   I.S. : currentChar adalah karakter pertama dari kata
   F.S. : currentWord berisi kata yang sudah diakuisisi;
          currentChar = BLANK atau currentChar = MARK;
          currentChar adalah karakter sesudah karakter terakhir yang diakuisisi.
          Jika panjang kata melebihi NMax, maka sisa kata "dipotong" */
{
   int i = 0;
   while (currentChar != MARK && currentChar != BLANK){
      currentWord.TabWord[i] = currentChar;
      ADV();
      i++;
   }

   if (i > NMax){
      currentWord.Length = NMax;
   }

   else{
      currentWord.Length = i;
   }
}

void LowerCase()

/* I.S. currentword terdefinisi sembarang tetapi tidak kosong */

/* F.S. currentword menjadi lowercase di setiap karakternya */
{
   int chars;
   char lower;
   int i;
   // while (currentChar != MARK && currentChar != BLANK){
   //    for (i = 0 ; i < currentWord.Length ; i++){
   //       chars = (int) currentChar;
   //       if (chars >= 65 && chars <= 90){
   //             lower = chars + 32;
   //             currentWord.TabWord[i] = lower; 
   //       }
   //       i++;
   //       ADV();
   //    }
   // }

   while (currentChar != MARK && currentChar != BLANK){
      for (i = 0 ; i < currentWord.Length ; i++){
         if (chars >= 65 && chars <= 90){
            (int) currentWord.TabWord[i] += 32; 
         }
         i++;
         ADV();
      }
   }


   // int i = 0;
   // while (!endWord){
   //    if (currentWord.TabWord[i] == "A"){
   //       currentWord.TabWord[i] = "a";
   //    }
   //    if (currentWord.TabWord[i] == "B"){
   //       currentWord.TabWord[i] = "b";
   //    }
   //    if (currentWord.TabWord[i] == "C"){
   //       currentWord.TabWord[i] = "c";
   //    }
   //    if (currentWord.TabWord[i] == "D"){
   //       currentWord.TabWord[i] = "d";
   //    }
   //    if (currentWord.TabWord[i] == "E"){
   //       currentWord.TabWord[i] = "e";
   //    }
   //    if (currentWord.TabWord[i] == "F"){
   //       currentWord.TabWord[i] = "f";
   //    }
   //    if (currentWord.TabWord[i] == "G"){
   //       currentWord.TabWord[i] = "g";
   //    }
   //    if (currentWord.TabWord[i] == "H"){
   //       currentWord.TabWord[i] = "h";
   //    }
   //    if (currentWord.TabWord[i] == "I"){
   //       currentWord.TabWord[i] = "i";
   //    }
   //    if (currentWord.TabWord[i] == "J"){
   //       currentWord.TabWord[i] = "j";
   //    }
   //    if (currentWord.TabWord[i] == "K"){
   //       currentWord.TabWord[i] = "k";
   //    }
   //    if (currentWord.TabWord[i] == "L"){
   //       currentWord.TabWord[i] = "l";
   //    }
   //    if (currentWord.TabWord[i] == "M"){
   //       currentWord.TabWord[i] = "m";
   //    }
   //    if (currentWord.TabWord[i] == "N"){
   //       currentWord.TabWord[i] = "n";
   //    }
   //    if (currentWord.TabWord[i] == "O"){
   //       currentWord.TabWord[i] = "o";
   //    }
   //    if (currentWord.TabWord[i] == "P"){
   //       currentWord.TabWord[i] = "p";
   //    }
   //    if (currentWord.TabWord[i] == "Q"){
   //       currentWord.TabWord[i] = "q";
   //    }
   //    if (currentWord.TabWord[i] == "R"){
   //       currentWord.TabWord[i] = "r";
   //    }
   //    if (currentWord.TabWord[i] == "S"){
   //       currentWord.TabWord[i] = "s";
   //    }
   //    if (currentWord.TabWord[i] == "T"){
   //       currentWord.TabWord[i] = "t";
   //    }
   //    if (currentWord.TabWord[i] == "U"){
   //       currentWord.TabWord[i] = "u";
   //    }
   //    if (currentWord.TabWord[i] == "V"){
   //       currentWord.TabWord[i] = "v";
   //    }
   //    if (currentWord.TabWord[i] == "W"){
   //       currentWord.TabWord[i] = "w";
   //    }
   //    if (currentWord.TabWord[i] == "X"){
   //       currentWord.TabWord[i] = "x";
   //    }
   //    if (currentWord.TabWord[i] == "Y"){
   //       currentWord.TabWord[i] = "y";
   //    }
   //    if (currentWord.TabWord[i] == "Z"){
   //       currentWord.TabWord[i] = "z";
   //    }
   //    i++;
   //    ADV();
   // }
}