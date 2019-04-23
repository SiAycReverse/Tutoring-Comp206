#include <stdio.h>
#include <string.h>
#include <ctype.h>

void encrypt(char source[], char destination[], int key)
{
   int i = 0;
   int size = strlen(source);
   int j = size - 1;
   int temp = 0;
   for (i = 0; i < size; i++, j--)
   {
      if (source[i] >= 'a' && source[i] <= 'z')
      {
         temp = source[i] - 'a';
      }
      else if (source[i] >= 'A' && source[i] <= 'Z')
      {
         temp = source[i] - 'A';
      }
      else
      {
         temp = 0;
      }

      temp = (temp + key) % 26;

      if (source[i] >= 'a' && source[i] <= 'z')
      {
         destination[j] = 'a' + temp;
      }
      else if (source[i] >= 'A' && source[i] <= 'Z')
      {
         destination[j] = 'A' + temp;
      }
      else
      {
         destination[j] = source[i];
      }
      
   }
   
}

int main()
{
   FILE *file_path;
   char filename[256];
   char *p;
   char c;
   int alpha;
   int total;

   printf("Please enter a filename: ");
   scanf("%s", filename);

   file_path = fopen(filename, "r");
   if (file_path != NULL)
   {
      
      while(!feof(file_path))
      {
         c = fgetc(file_path);
         if (isalpha(c))
         {
            alpha++;
            total++;
         }
         else
         {
            total++;
         }
      }
   }

   fclose(file_path);

   printf("The ratio alphabet : total is %d : %d\n", alpha, total );

   char src[] = "ABC! HeLlo WorLD 1234";
   char dest[22];
   printf("src: %s\n", src);
   printf("dest before encrypt: %s\n", dest);
   encrypt(src, dest, 5);
   printf("dest after encrypt: %s\n", dest);

}
