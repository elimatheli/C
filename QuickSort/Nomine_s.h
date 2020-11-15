#define _NOMINE_

struct date{
  int year;
  int month;
  int day;
};

struct Nomine_s{
  int year;
  char domain[30];
  char name[50];
  struct date birthday;
  char nationality[40];
  char gender[7];
};
