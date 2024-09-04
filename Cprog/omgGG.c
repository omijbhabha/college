#include <stdio.h>
#include <math.h>

// Function to move n disks from source to destination using auxiliary peg
void tower_of_hanoi(int n, char source, char destination, char auxiliary, int *move_count) {
    if (n == 0) {
        return;
    }

    // Move n-1 disks from source to auxiliary
    tower_of_hanoi(n-1, source, auxiliary, destination, move_count);
    
    // Move the nth disk from source to destination
    (*move_count)++;
    printf("Move disk %d from %c to %c\n", n, source, destination);
    
    // Move n-1 disks from auxiliary to destination
    tower_of_hanoi(n-1, auxiliary, destination, source, move_count);
}

// Main function to initialize parameters and call the Tower of Hanoi function
int main() {
    int n = 3;  // Number of disks
    int move_count = 0;
    
    printf("Solution for %d disks:\n", n);
    tower_of_hanoi(n, 'A', 'C', 'B', &move_count);
    
    // Print the total number of moves
    printf("Number of moves required: %d\n", move_count);
    
    return 0;
}
