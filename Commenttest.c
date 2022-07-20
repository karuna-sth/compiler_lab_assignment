#include<stdio.h>
#include<string.h>
int main(){
  char com[30];
  int len, comment=0;
  printf("Enter comment:\n");
  gets(com);
  len = strlen(com);
  if(com[0] == '/'){
    if(com[1]=='/')
      comment = 1;
    else if(com[1] == '*'){
      if(com[len-2]=='*' && com[len-1]=='/'){
        comment = 1;
      }
    }
    else
      comment = 0;
  }
  if (comment){
    printf("It is a comment\n");
  }
  else{
    printf("It is not a comment\n");
  }
  return 0; 
}