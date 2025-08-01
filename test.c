#include <stdio.h>
#include <string.h>

/*
int main(){
    char buffer[5];
    gets(buffer);
    printf("You entered: %s\n", buffer);
    return 0;
}
*/


int main() {
    char buffer[5];  // Our toy box can hold 5 toys (letters)
    
    // Ask for toys safely with fgets
    printf("Put some letters in my box (like ABC): ");
    if (fgets(buffer, sizeof(buffer), stdin) != NULL) {
        
        // Clean up any extra toys (if someone typed too much)
        char *newline = strchr(buffer, '\n');  // Look for the "end of toys" marker
        if (newline != NULL) {
            *newline = '\0';  // Replace the marker with a stop sign
        } else {
            // If there’s no marker, there might be extra toys left behind!
            int c;
            while ((c = getchar()) != '\n' && c != EOF);  // Throw away extra toys
        }
        
        // Show what’s in the box
        printf("You entered: %s\n", buffer);
    } else {
        printf("Oops, something went wrong with my box!\n");
    }
    
    return 0;  // Done playing!
}

