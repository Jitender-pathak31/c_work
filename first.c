#include <stdio.h>
#include <stdlib.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

int main() {

    int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
    *returnSize = 0; // Initialize to 0; will be set to 2 if solution is found

    // Check if array is too small
    if (numsSize < 2) {
        return NULL;
    }

    for (int i = 0; i < numsSize - 1; i++) { // i up to second-to-last element
        for (int j = i + 1; j < numsSize; j++) { // j starts after i
            if (nums[i] + nums[j] == target) {
                int* result = (int*)malloc(2 * sizeof(int));
                if (result == NULL) { // Check for malloc failure
                    *returnSize = 0;
                    return NULL;
                }
                result[0] = i;
                result[1] = j;
                *returnSize = 2;
                return result;
            }
        }
    }

    // No solution found
    return NULL;
}

    int nums[] = {3, 2, 4};
    int target = 5;
    int size = sizeof(nums) / sizeof(nums[0]);
    int returnSize;
    int* indices = twoSum(nums, size, target, &returnSize);

    if (indices != NULL && returnSize == 2) {
        printf("Indices: %d, %d\n", indices[0], indices[1]);
        free(indices);
    } else {
        printf("No solution found\n");
    }
    return 0;
}





typedef struct linked_list
{
    int val;
    struct linked_list * next;
} list_1;


list_1 * new_list(int value){

    list_1 * list_2 = (list_1*)malloc(sizeof(list_1));
    list_2->val = value;
    list_2->next = NULL;
    return list_2;
}

 void append(list_1* head, int val){
        list_1* current = head;

        while(current->next != NULL){
           
            current = current->next;
            }

            current->next = new_list(val);
            
     }

     void print_list(list_1* head){
        list_1* current = head;

        while(current != NULL){
             printf("%d ->", current->val);
             current = current->next;
        }

        printf("NULL\n");
     }

int main(){

    list_1 * head = new_list(1);
    append(head, 2);
    append(head, 299);
    append(head, 301);

    print_list(head);

    return 0;
     
  
 
}