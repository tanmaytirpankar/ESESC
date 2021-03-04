#include <stdio.h>
#include <strings.h>
#include <string.h>
#include <stddef.h>
#include <stdlib.h>
#include <unistd.h>
#include <assert.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <ctype.h>
#include <stdint.h>
#include <stdbool.h>
#include "../../esesc/simusignal.h"


#define NO_OF_POINTS 1000
#define DIMENSION 3
int main()
{
	int * arr = malloc(sizeof(int)*1000*3);
	//Trigger search within some address space
	SIMUSIGNAL(arr, 1000*3, SIG_NCACHE | SIG_RAMPAD);
	temp1 = arr[0];

	return 0;

}