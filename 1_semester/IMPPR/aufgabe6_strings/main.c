#include <stdio.h>

int main(int argc, char **argv) {
  char text1[20 + 1];
  char text2[20 + 1];
  char zieltext[40 + 1];
  char *p_text = text1;
  char *p_zieltext = zieltext;

  printf("Ersten String eingeben: ");
  scanf("%s", text1);
  printf("Zweiten String eingeben: ");
  scanf("%s", text2);

  while(*p_zieltext++ = *p_text++) ;

  p_zieltext--;
  p_text = text2;

  while(*p_zieltext++ = *p_text++);

  printf("%s\n", zieltext);
  return 0;
}
