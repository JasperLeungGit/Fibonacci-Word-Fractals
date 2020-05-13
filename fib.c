#include "bmp.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define INITIAL 2

typedef enum {
    up,
    down,
    left,
    right
} direction;

void draw(int x, int y, direction dir, int step, int w, RGB* im, RGB c) {
#define I(i, j) im[(i)*w + j]
    int j;
    if (dir == up)
        for (j = 0; j < step; j++)
            I(x + j, y) = c;
    if (dir == down)
        for (j = 0; j < step; j++)
            I(x - j, y) = c;
    if (dir == right)
        for (j = 0; j < step; j++)
            I(x, y + j) = c;
    if (dir == left)
        for (j = 0; j < step; j++)
            I(x, y - j) = c;
#undef I
}

int fib(int n, int x, int y, int step, RGB b, RGB f, int w, int h, RGB* image) {

    int i;

    char *last = malloc(2);
	strcpy(last, "1");
 
	char *cur = malloc(2);
	strcpy(cur, "0");
   
    for (i = 2; i < n; i++) {
        
		char *next = malloc(strlen(cur) + strlen(last) + 1);
		strcpy(next, cur);
		strcat(next, last);
 
		free(last);
		last = cur;
	    cur = next;

	}

    printf("fib: %s\nfib length: %ld\n", cur, strlen(cur));

    // set background colour
    for (i = 0; i < w * h; i++)
        image[i] = b;

    int dir = 0;
    
    for (i = 0; i < strlen(cur); i ++){
        
        switch (dir){ //OUT OF BOUNDS
            case 0: if (x + step > h) return 0; break;
            case 1: if (x - step < 0) return 0; break;
            case 2: if (y - step < 0) return 0; break;
            case 3: if (y + step > w) return 0; break;
        }
        
        draw(x, y, dir, step, w, image, f); 

        switch (dir){
            case 0: x += step; break;
            case 1: x -= step; break;
            case 2: y -= step; break;
            case 3: y += step; break;
        }
        
	    
        if (cur[i] == '0'){

		    if (!(i % 2)){              
                switch (dir){
                    case up: dir = right; break;
                    case down: dir = left; break;
                    case left: dir = up; break;
                    case right: dir = down; break;
                }
            }
		    else{
                switch (dir){           
                    case up: dir = left; break;
                    case down: dir = right; break;
                    case left: dir = down; break;
                    case right: dir = up; break;
                }
            }
        }
    }

    return strlen(cur);
}
