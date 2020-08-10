#include <stdio.h>

#include <stdlib.h>

#define title 1

#define all 0


void read_news(char buffer[500], char file_path[10], int is_only_Title) { 
  FILE * fp, * fp1;
  int c, i = 0;

  fp = fopen(file_path, "r");
  if (is_only_Title == 1) { //just title was read
    while (!feof(fp)) {
      c = fgetc(fp);

      if (c == '\n') {
        break;

      } else {
        buffer[i] = c;
        i++;
      }
    }
    buffer[i] = '\0';
    printf("%s", buffer);
  } else {   //all of the news was read

    while (!feof(fp)) {
      c = fgetc(fp);
      buffer[i] = c;
      i++;

    }
    buffer[i-1] = '\0';
    printf("%s\n", buffer);

  }
  fclose(fp);

}
void append_file(char * file_path, char c) { //read news were written in file
  FILE * fp;
  fp = fopen(file_path, "a");
  fprintf(fp, "%c\n", c);

  fclose(fp);
}
int check_news(char * file_path, char a) { //whether the news was read before was checked 
  FILE * fp;
  char c;
  int flag = 0;
  fp = fopen(file_path, "r");
  while (!feof(fp)) {
    c = fgetc(fp);
    if (c == a) {

      flag++;

    }

  }
  if (flag != 0) {
    return 1;
  } else {
    return 0;
  }
  fclose(fp);
}
int get_readed_news(char * file_path, int b) { //read news were read for case b 
  FILE * fp;
  int c, flag = 0;
  fp = fopen(file_path, "r");
  while (!feof(fp)) {
    c = (int)(fgetc(fp) - 48);
    if (b == c) {
      flag++;
    }
  }
  if (flag != 0) {
    return 1;
  } else {
    return 0;
  }
  fclose(fp);

}

double f_func(int x) {

  return (x * x * x) - (x * x) + 2;

}
double g_func(double f(int x), int a) {

  return f(a) * f(a);

}
void read_magic_numbers(char buffer_magic[10], char buffer_news[500]) { //calculation was made by applying the relevant formula
  int i, j = 0, a, num;
  double b, sum = 0;
  for (i = 0; i < 500; i++) {
    if (buffer_news[i] == '#') {
      buffer_magic[j] = (buffer_news[i + 1]);
      j++;
    }

  }
  for (a = 0; a < j; a++) {
    num = buffer_magic[a] - '0';
    b = g_func(f_func, num);
    sum += b;
  }
  printf("%.1f\n", sum);

}
void menu() {
  FILE * fp, * fp1;
  char buffer[500], selection, selection3, a, b, magic[10];
  int selection2, selection4, selection5, c[500], i;
  while (selection3 != 'n') {
    system("clear");
    selection3 = 'q';
    printf("*********Daily Press*********\n\nToday's news are listed for you :\n\nTitle of 1.news:");
    read_news(buffer, "news/1.txt", title);
    printf("\nTitle of 2.news:");
    read_news(buffer, "news/2.txt", title);
    printf("\nTitle of 3.news:");              //titles were printed
    read_news(buffer, "news/3.txt", title);
    printf("\nTitle of 4.news:");
    read_news(buffer, "news/4.txt", title);
    printf("\n\nWhat do you want to do\na.Read a new\nb.List the read news\nc.Get decrypted information from the news\n");
    scanf("%c", & selection);
    switch (selection) {
    case 'a': //news reading has been done
      printf("Which news do you want to read?\n");
      scanf("%d", & selection2);
      a = selection2 + '0';
      switch (selection2) {
      case 1:
        if (check_news("readed_news_id.txt", a) == 1) { //read news were checked with if else

          printf("This new is readed...Do you want to read again? Yes(1)/No(0) :");
          scanf("%d", & selection4);
          if (selection4 == 1) {
            read_news(buffer, "news/1.txt", all);

          } else if (selection4 == 0) {

          } else {
            printf("Invalid option\n");

          }

        } else {
          read_news(buffer, "news/1.txt", all);
          append_file("readed_news_id.txt", a);
        }
        break;
      case 2:
        if (check_news("readed_news_id.txt", a) == 1) {

          printf("This new is readed...Do you want to read again? Yes(1)/No(0) :");
          scanf("%d", & selection4);
          if (selection4 == 1) {
            read_news(buffer, "news/2.txt", all);
          } else if (selection4 == 0) {

          } else {
            printf("Invalid option\n");

          }

        } else {
          read_news(buffer, "news/2.txt", all);
          append_file("readed_news_id.txt", a);
        }
        break;

      case 3:
        if (check_news("readed_news_id.txt", a) == 1) {

          printf("This new is readed...Do you want to read again? Yes(1)/No(0) :");
          scanf("%d", & selection4);
          if (selection4 == 1) {
            read_news(buffer, "news/3.txt", all);
          } else if (selection4 == 0) {

          } else {
            printf("Invalid option\n");

          }

        } else {
          read_news(buffer, "news/3.txt", all);
          append_file("readed_news_id.txt", a);
        }
        break;

      case 4:
        if (check_news("readed_news_id.txt", a) == 1) {

          printf("This new is readed...Do you want to read again? Yes(1)/No(0) :");
          scanf("%d", & selection4);
          if (selection4 == 1) {
            read_news(buffer, "news/4.txt", all);
          } else if (selection4 == 0) {

          } else {
            printf("Invalid option\n");

          }

        } else {
          read_news(buffer, "news/4.txt", all);
          append_file("readed_news_id.txt", a);
        }
        break;

      }
      while (selection3 != 'y' && selection3 != 'n') {
        printf("Do you want to continue? Yes(y)/No(n) :");
        scanf(" %c", & selection3);
        if (selection3 == 'n') {
          printf("Good Bye!\n");
        } else
          printf("Invalid option!\n");
      }
      break;
    case 'b': //read news were printed
      printf("Readed news are listed below:\n");
      for (i = 1; i <= 4; i++) {
        if (get_readed_news("readed_news_id.txt", i) == 1) {
          printf("%d. new is read!\n", i);
        }

      }

      while (selection3 != 'y' && selection3 != 'n') {
        printf("Do you want to continue? Yes(y)/No(n) :");
        scanf(" %c", & selection3);
        if (selection3 == 'n') {
          printf("Good Bye!\n");

        } else
          printf("Invalid option!\n");
      }
      break;
    case 'c': //decryption was done and printed
      printf("Which news would you like to decrypted?\n");
      scanf("%d", & selection5);
      switch (selection5) {
      case 1:
        read_news(buffer, "news/1.txt", all);
        printf("\n");
        printf("Number of tests performed = ");
        read_magic_numbers(magic, buffer);
        break;
      case 2:
        read_news(buffer, "news/2.txt", all);
        printf("\n");
        printf("Number of sick people = ");
        read_magic_numbers(magic, buffer);
        break;
      case 3:
        read_news(buffer, "news/3.txt", all);
        printf("\n");
        printf("Number of deaths = ");
        read_magic_numbers(magic, buffer);
        break;
      case 4:
        read_news(buffer, "news/4.txt", all);
        printf("\n");
        printf("Expected number of sick people = ");
        read_magic_numbers(magic, buffer);
        break;

      }
      while (selection3 != 'y' && selection3 != 'n') {
        printf("Do you want to continue? Yes(y)/No(n) :");
        scanf(" %c", & selection3);
        if (selection3 == 'n') {
          printf("Good Bye!\n");

        } else
          printf("Invalid option!\n");
      }
      break;

    }

  }

}
int main() {
  menu();

  return 0;
}