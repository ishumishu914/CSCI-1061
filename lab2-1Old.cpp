#include<iostream>
#include<string>
using namespace std;

int main() 
{
   string text = "ABC",result1, result2;
   char character;
   int shift = 1;

   /*cout << "Enter shift +/- 26: ";
   cin >> shift;
   cout << "Enter plaintext text (A-Z only, no spaces): ";
   cin >> text;*/

   //encryption
   for (int i = 0; i < text.length(); i++) 
   {
      character = text[i];
      if (character >= 'A' && character <= 'Z')
      {
         character += shift;
         if (character > 'Z')
         {
            character = character - 'Z' + 'A' -1;
         }
         else if (character < 'A')
         {
            character = character + 'Z' - 'A' +1;
         }
         result1+= character;
      }    
   }        

   //decryption
   for (int i = 0; i<result1.length(); i++) 
   {
      character = result1[i];
      if (character >= 'A' && character <= 'Z')
      {
         character -= shift;
         if (character < 'A')
         {
            character = character + 'Z' - 'A' +1;
         }
         else if (character > 'Z')
         {
            character = character - 'Z' + 'A' -1;
         }
         result2+= character;
      }
   }
   cout << "Ciphertext: " << result1 << endl;
   cout << "plaintext: " << result2 << endl; 

   return 0;
}