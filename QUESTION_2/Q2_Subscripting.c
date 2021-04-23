// Created by: Alanté "Alan" D. Powell on: April 22, 2021 at: 13:04
// Spring 2021 - Programming Language Concepts
// Exam 2 - Question 2 - Q2_Pointer.c
// References: None

#include "stdio.h" // Used for output and string interpolation
#include "time.h" // Used for time calculation

int main() {
//    Start Timer
    clock_t start_clock = clock();
    
//    Begin Function
    int array_size = 180;
    int array [array_size][array_size];
    
    int i;
    int j;
    int n = 0;
    
    for (int i = 0; i < array_size; i++) {
        for (int j = 0; j < array_size; j++) {
            array[i][j] = n;
            n++;
        }
    }
    
//    Stop Timer
    double total_execution_time = static_cast<double>(clock() - static_cast<double>(start_clock)/static_cast<double>(CLOCKS_PER_SEC));
    printf("The execution time is: %f. \n", total_execution_time);
}
