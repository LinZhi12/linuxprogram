#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <sys/types.h>
#include <limits.h>
#include <string.h>
#include <sys/time.h>
struct sendval{
   int n;
   int s;
};
#define NUM 4
