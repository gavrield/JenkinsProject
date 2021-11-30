#include <stdio.h>

int main(int argc, char* argv[])
{
  if (argc == 2)
  {
    char* index = argv[1];
    while (*index != '\0')
    {
      if (*index <= 122 && *index >= 97) //ascii table of lowercase 97-122
        *index -= 32;  // ascii table of uppercase 65-90
      index++;
    }
    printf("%s\n", argv[1]);
    return 0;
  }
  else{
    printf("ERROR: This program accepts only 1 argument!\n");
    return 2;
  }
}
