// Created by: Alanté "Alan" D. Powell on: April 22, 2021 at: 13:04
// Spring 2021 - Programming Language Concepts
// Exam 2 - Question 2 - Q2_Pointer.c
// References: None

#include "stdio.h" // Used for output and string interpolation
#include "time.h" // Used for time calculation

int main() {
//    Begin Timer
    clock_t start_clock = clock();
    
//    Begin Function
    int array_size = 200;
    int array [array_size][array_size]
    
    int* index_of_array = (int*)array;
    int index_offset;
    
    for (index_offset = 0; (index_offset + index_of_array) < (int*)array + (array_size * array_size); index_offset += 1) {
        *(index_of_array + index_offset) = index_offset;
    }
    
//    Stop Timer
    double total_execution_time = static_cast<double>(clock() - static_cast<double>(start_clock)/static_cast<double>(CLOCKS_PER_SEC));
    printf("The execution time is: %f", total_execution_time)
}
