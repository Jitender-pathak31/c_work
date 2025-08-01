#include <stdio.h>
#include <stdlib.h>

int main(){

    int numbers = 5;
    //allocating calloc

    int * array = (int*)calloc(numbers, sizeof(int));

    if(array==0){
        printf("Memory allocaiton is failed\n");

        return 1;
    }

    for(int i=0; i<numbers; i++){
        array[i] = i+1;
        printf("%d ", array[i]);
    }
    printf("\n");

    free(array);

    return 0;
}

// int main(){
//     int numbers = 6;
//     //allocating a malloc

//     int * array = (int*)malloc(numbers*(sizeof(int)));

//     if(array == NULL){
//         printf("Memory allocation is failed\n");
//         return 1;
//     }

//     for(int i =0; i<numbers; i++){
//         array[i] = i+1;
//         printf("%d ", array[i]);
//     }
//     printf("\n");

//     free(array);

//     return 0;
// }

