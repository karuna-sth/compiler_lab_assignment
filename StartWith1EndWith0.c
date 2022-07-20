#include <stdio.h>
#include <string.h>
#define max 100
int main() {
  char str[max];
  int len, i, accept = 0, checkString = 1;
  printf("Enter the string to be checked(0 or 1): ");
  gets(str);
  len = strlen(str);
  for(i = 0; i < len-1; i++){
    if(str[i] != '0' && str[i] != '1'){
      checkString = 0;
    }
  }
  if(str[0] == '1' && str[len-1] == '0')
    accept = 1;
  if(accept == 1 && checkString == 1)
    printf("\nString is accepted");
  else 
    printf("\nString is not accepted");
  return 0;
}