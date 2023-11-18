
/*
* AstroTinker Bot (AB): Task 1B Path Planner
*
* This program computes the valid path from the start point to the end point.
* Make sure you don't change anything outside the "Add your code here" section.
*/

#include <stdlib.h>
#include <stdbool.h>
#include <stdint.h>

#ifdef __linux__ // for host pc

    #include <stdio.h>

    void _put_byte(char c) { putchar(c); }

    void _put_str(char *str) {
        while (*str) {
            _put_byte(*str++);
        }
    }

    void print_output(uint8_t num) {
        if (num == 0) {
            putchar('0'); // if the number is 0, directly print '0'
            _put_byte('\n');
            return;
        }

        if (num < 0) {
            putchar('-'); // print the negative sign for negative numbers
            num = -num;   // make the number positive for easier processing
        }

        // convert the integer to a string
        char buffer[20]; // assuming a 32-bit integer, the maximum number of digits is 10 (plus sign and null terminator)
        uint8_t index = 0;

        while (num > 0) {
            buffer[index++] = '0' + num % 10; // convert the last digit to its character representation
            num /= 10;                        // move to the next digit
        }

        // print the characters in reverse order (from right to left)
        while (index > 0) { putchar(buffer[--index]); }
        _put_byte('\n');
    }

    void _put_value(uint8_t val) { print_output(val); }

#else  // for the test device

    void _put_value(uint8_t val) { }
    void _put_str(char *str) { }

#endif

#define V 30 // Number of vertices in the graph
uint8_t minDistance(uint8_t dist[], bool sptSet[]) {
    uint8_t min = UINT8_MAX, min_index;
    for (uint8_t v = 0; v < V; v++) {
        if (!sptSet[v] && dist[v] < min) {
            min = dist[v];
            min_index = v;
        }
    }
    return min_index;
}

// main function
int main(int argc, char const *argv[]) {

    #ifdef __linux__

        const uint8_t START_POINT   = atoi(argv[1]);
        const uint8_t END_POINT     = atoi(argv[2]);
        uint8_t CPU_DONE            = 0;

    #else

        #define START_POINT        (* (volatile uint8_t * ) 0x20000000)
        #define END_POINT          (* (volatile uint8_t * ) 0x20000001)
        #define CPU_DONE            (* (volatile uint8_t * ) 0x20000003)

    #endif

    // array to store the planned path
    uint8_t path_planned[32];

    // index to keep track of the path_planned array
    uint8_t idx = 0;

    // instead of using printf() function for debugging,
    // use the below function calls to print a number, string or a newline

    // for newline: _put_byte('\n');
    // for string:  _put_str("your string here");
    // for number:  _put_value(your_number_here);

    // Examples:
    // _put_value(START_POINT);
    // _put_value(END_POINT);
    // _put_str("Hello World!");
    // _put_byte('\n');

    // ############# Add your code here #############
uint8_t graph[V][V] = {
                    {0,1,0,0,0    ,0,0,0,0,0   ,0,0,0,0,0    ,0,0,0,0,0,    0,0,0,0,0,    0,0,0,0,0},//0
                    {1,0,1,0,0     ,0,0,0,0,0   ,0,0,0,0,0    ,0,0,0,0,0    ,0,0,0,0,0,    0,0,0,0,1},//1
                    {0,1,0,2,0     ,0,0,0,2,0   ,0,0,0,0,0    ,0,0,0,0,0    ,0,0,0,0,0,    0,0,0,0,0},//2
                    {0,0,2,0,2     ,0,0,0,0,0   ,0,0,0,0,0    ,0,0,0,0,0    ,0,0,0,0,0,    0,0,0,7,0},//3
                    {0,0,0,2,0,    1,5,0,0,0  ,0,0,0,0,0    ,0,0,0,0,0    ,0,0,0,0,0,    0,0,0,0,0},//4
                    {0,0,0,0,1,     0,0,0,0,0    ,0,0,0,0,0    ,0,0,0,0,0    ,0,0,0,0,0,    0,0,0,0,0},//5
                    {0,0,0,0,5,     0,0,4,0,0    ,0,0,0,0,0    ,0,0,0,0,0    ,0,0,0,0,0,    0,0,0,0,0},//6
                    {0,0,0,0,0,     0,4,0,1,0    ,0,0,0,0,0    ,0,0,0,0,0    ,0,0,0,0,0,    0,0,0,0,0},//7
                    {0,0,3,0,0,     0,0,1,0,1    ,0,0,3,0,0  ,0,0,0,0,0    ,0,0,0,0,0,    0,0,0,0,0},//9
                    {0,0,0,0,0,     0,0,0,0,1    ,0,0,0,0,0    ,0,0,0,0,0    ,0,0,0,0,0,    0,0,0,0,0},//10
                    {0,0,0,0,0,     0,0,0,0,1    ,0,0,0,0,0    ,0,0,0,0,0    ,0,0,0,0,0,    0,0,0,0,0},//11
                    {0,0,0,0,0,     0,0,0,3,0  ,0,0,0,6,0    ,0,0,0,0,6    ,0,0,0,0,0,    0,0,0,0,0},//12
                    {0,0,0,0,0,     0,0,0,0,0   ,0,0,6,0,5     ,0,0,0,0,0    ,0,0,0,0,0,    0,0,0,0,0},//13
                    {0,0,0,0,0,     0,0,0,0,0   ,0,0,0,5,0     ,1,3,0,0,0  ,0,0,0,0,0,    0,0,0,0,0},//14
                    {0,0,0,0,0,     0,0,0,0,0  ,0,0,0,0,1     ,0,0,0,0,0    ,0,0,0,0,0,    0,0,0,0,0},//15
                    {0,0,0,0,0,     0,0,0,0,0   ,0,0,0,0,3   ,0,0,1,6,0  ,0,0,0,0,0,    0,0,0,0,0},//16
                    {0,0,0,0,0,     0,0,0,0,0   ,0,0,0,0,0     ,0,1,0,0,0    ,0,0,0,0,0,    0,0,0,0,0},//17
                    {0,0,0,0,0,     0,0,0,0,0   ,0,0,0,0,0     ,0,6,0,0,6  ,0,0,0,0,0,    0,0,0,0,0},//18
                    {0,0,0,0,0,     0,0,0,0,0  ,0,0,6,0,0     ,0,0,0,6,0    ,3,0,0,0,0,  0,0,0,0,0},//19
                    {0,0,0,0,0,     0,0,0,0,0   ,0,0,0,0,0     ,0,0,0,0,3  ,0,1,0,0,1,    0,0,0,0,3},//20
                    {0,0,0,0,0,     0,0,0,0,0  ,0,0,0,0,0     ,0,0,0,0,0    ,1,0,1,1,0,    0,0,0,0,0},//21
                    {0,0,0,0,0,     0,0,0,0,0  ,0,0,0,0,0     ,0,0,0,0,0    ,0,1,0,0,0,    0,0,0,0,0},//22
                    {0,0,0,0,0,     0,0,0,0,0  ,0,0,0,0,0     ,0,0,0,0,0    ,0,1,0,0,0,    0,0,0,0,0},//23
                    {0,0,0,0,0,     0,0,0,0,0  ,0,0,0,0,0     ,0,0,0,0,0    ,1,0,0,0,0,    3,0,0,0,0},//24
                    {0,0,0,0,0,     0,0,0,0,0  ,0,0,0,0,0     ,0,0,0,0,0    ,0,0,0,0,3,    0,4,0,0,0},//25
                    {0,0,0,0,0,     0,0,0,0,0   ,0,0,0,0,0     ,0,0,0,0,0    ,0,0,0,0,0,    4,0,1,3,0},//26
                    {0,0,0,0,0,     0,0,0,0,0  ,0,0,0,0,0     ,0,0,0,0,0    ,0,0,0,0,0,    0,1,0,0,0},//27
                    {0,0,0,1,0,     0,0,0,0,0  ,0,0,0,0,0     ,0,0,0,0,0    ,0,0,0,0,0,    0,3,0,0,2},//28
                    {0,1,0,0,0,     0,0,0,0,0  ,0,0,0,0,0     ,0,0,0,0,0    ,3,0,0,0,0,  0,0,0,2,0}};//29 
    uint8_t distance[V];  
    uint8_t spath[V];  
    bool sset[V];
    for (uint8_t i = 0; i < V; i++) {
        distance[i] = UINT8_MAX;
        spath[i] = UINT8_MAX;
        sset[i] = false;
    }
    distance[START_POINT] = 0;

    for (uint8_t count = 0; count < V - 1; count++) {
        uint8_t u = minDistance(distance, sset);
        sset[u] = true;
        for (uint8_t v = 0; v < V; v++) {
            if (!sset[v] && graph[u][v] && distance[u] != UINT8_MAX && distance[u] + graph[u][v] < distance[v]) {
                distance[v] = distance[u] + graph[u][v];
                spath[v] = u;
            }
        }
    }
    uint8_t current = END_POINT;
    uint8_t length = 0;
    
    while (current != UINT8_MAX) {
        path_planned[length] = current;
        current = spath[current];
        length++;
    }
    idx = length;
    
    for (uint8_t i = 0; i < length / 2; i++) {
        uint8_t temp = path_planned[i];
       path_planned[i] = path_planned[length - i - 1];
        path_planned[length - i - 1] = temp;
    }
    path_planned[length] = UINT8_MAX;


    // ##############################################

    #ifdef __linux__    // for host pc

        _put_str("######### Planned Path #########\n");
        for (int i = 0; i < idx; ++i) {
            _put_value(path_planned[i]);
        }
        _put_str("################################\n");

    #endif

    return 0;
}
