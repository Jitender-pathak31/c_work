#include <stdio.h>
#include <stdlib.h>


int main(){
// declaring a union
union intParts{
    int theInt;
    char bytes[sizeof(int)];
} parts;

//union intParts parts;
parts.theInt = 12340;

printf("The int is %i\nThe bytes are [%i, %i, %i, %i, %i]\n",
parts.theInt, parts.bytes[0], parts.bytes[1], parts.bytes[2], parts.bytes[3], parts.bytes[4]);

//vs

int theInt = parts.theInt;
printf("The int is %i\nThe bytes are [%i, %i, %i,%i, %i]\n",
theInt, *((char*)&theInt+0), *((char*)&theInt+1), *((char*)&theInt+2), *((char*)&theInt+3), *((char*)&theInt+4));


return 0;
}
