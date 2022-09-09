#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>

#define FALSE 0
#define TRUE  1


typedef char bool; // structure 
int my_putchar(char c) {
  return write(1, &c, 1);
}

int my_putstr(char *str) {
  int indicator = 0;
  
  while (str[indicator] != '\0') {
    my_putchar(str[indicator]);
    indicator += 1;
  }
  return indicator;
}
int proceed_flag(va_list *arg, char flag) {
  int summa = 0;
  char c;
  char *str;

  if (flag == 's') {
    str = va_arg(*arg, char *);
    if (str) {
      summa += my_putstr(str);
    }
  }
  else if (flag == 'c') {
    c = va_arg(*arg, int);
    summa += my_putchar(c);    
  }
  return summa;
}
int my_printf(char* format, ...) {
  va_list arg;
  int  indicator = 0;
  bool flag_spotted = FALSE;
  int  summa = 0;
  va_start(arg, format); 
  while (format[indicator] != 0)
  {
    if (flag_spotted) {
      summa += proceed_flag(&arg, format[indicator]);
      flag_spotted = FALSE;
    }
    else if (format[indicator] == '%') {
      flag_spotted = TRUE;
    }
    else {
      summa += my_putchar(format[indicator]);
    }
    indicator += 1;
  }
  va_end(arg);
  return summa;
}
int main(int argc, char* argv[]){
 int j =  my_printf("%d", 1231);
 printf("%d", j);
}
