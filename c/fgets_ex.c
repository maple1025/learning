#include <stdio.h>
int main()
{
  // open the text file "fred.txt" for writing
  FILE *out = fopen("fred.txt", "wt");
  // write some text to the file
  fprintf(out, "Hello Fred!\n");
  // close the stream, so all changes to the file are saved
  fclose(out);
  // open the file "fred.txt" for reading
  FILE *in = fopen("fred.txt", "rt");
  // read the first line from the file
  char buffer[100];
  fgets(buffer, 2, in);
  // display what we've just read
  printf("first line of \"fred.txt\": %s\n", buffer);
  // close the stream
  fclose(in);
  return 0;
}