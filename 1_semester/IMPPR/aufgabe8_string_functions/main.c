#include <stdio.h>
#include <string.h>

/* strcpy() */
void textKopie(char *ziel, char *quelle);
void textKopieWieVomKundenGewuenscht(char *ziel, char *quelle);

/* strlen() */
int textLaenge(char *ziel);
int textLaengeWieVomKundenGewuenscht(char *ziel);

/* strcat() */
void textAnhang(char *ziel, char *quelle);
void textAnhangWieVomKundenGewuenscht(char *ziel, char *quelle);

int main(int argc, char** argv) {
  char str1[20] = "Moin!";
  char str2[20] = "hallo";

  /* textKopieWieVomKundenGewuenscht(str2, str1); */
  printf("textKopie: \tdest=%s\tstr1=%s\tstr2=%s\n", strcpy(str2,str1), str1, str2);

  printf("textLaenge:\tstr1=%d\n", textLaengeWieVomKundenGewuenscht(str1));

  textAnhangWieVomKundenGewuenscht(str1, str2);
  printf("textAnhang:\tstr1=%s\n", str1);

/*
  textKopie(str2, str1);
  printf("textKopie:\tstr1=%s\tstr2=%s\n", str1, str2);

  printf("textLaenge:\tstr1=%d\n", textLaenge(str1));

  textAnhang(str1, str2);
  printf("textAnhang:\ str1=%s\n", str1);
*/

  return 0;
}

/* strcpy() */
void textKopie(char *ziel, char *quelle) {
  while(*ziel++ = *quelle++);
}
void textKopieWieVomKundenGewuenscht(char *ziel, char *quelle) {
  int i;
  for(i = 0; quelle[i]; i++) 
    ziel[i] = quelle[i];
  ziel[i] = quelle[i];
}

/* strlen() */
int textLaenge(char *ziel) {
  int i = 0;
  while(*ziel++)
    i++;
  return i;
}
int textLaengeWieVomKundenGewuenscht(char *ziel) {
  int lang = 0;

  while(ziel[lang]) lang++;

  return lang;
}

/* strcat() */
void textAnhang(char *ziel, char *quelle) {
  ziel = ziel + textLaenge(ziel);
  textKopie(ziel, quelle);
}
void textAnhangWieVomKundenGewuenscht(char *ziel, char *quelle) {
  int i = 0, j = 0;
  while (ziel[i]) i++;

  do {
    ziel[i] = quelle[j++];
  } while (ziel [i++]);
}
