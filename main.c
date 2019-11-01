#include <stdio.h>
#include "point.c"
#include <time.h>
#include <stdlib.h>
#include <math.h>



point* create_point_list(int number_of_points){
    srand(time(NULL));   // Initialization, should only be called once.



    point* point_list;
    point_list = (point*)malloc(sizeof(point*)*number_of_points+1);
    int i;
    for(i=0; i<number_of_points; i++){
        int rx = rand()%100;
        int ry = rand()%100;
        point p;
        p.x = rx;
        p.y = ry;
        p.name = i+1;
        point_list[i] = p;
    }
    return point_list;
}

void print_point(point p){
    printf("%d(%d, %d)\n", p.name, p.x, p.y);
}


float distance(point p1, point p2){
    int x1 = p1.x;
    int x2 = p2.x;
    int y1 = p1.y;
    int y2 = p2.y;
    return sqrt((x1-x2)*(x1-x2) + (y1-y2)*(y1-y2));
}



int main() {
    int i;
    int number_of_points = 10;
    point* point_list = create_point_list(number_of_points);
    printf("Point list : \n");
    for(i=0; i< number_of_points; i++){
        print_point(point_list[i]);
    }

    point origin;
    origin.x = 0;
    origin.y = 0;
    origin.name = 0;

    printf("\n");
    for(i=0; i< number_of_points; i++){
        printf("Distance between Point %d and the origin : %0.2f \n", point_list[i].name, distance(point_list[i], origin));
    }


    return 0;
}