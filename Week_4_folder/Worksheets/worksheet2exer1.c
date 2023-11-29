#include <stdio.h>

typedef struct{
    double x;
    double y;
}point;

int main(){
    int number_of_points = 10;
    int i;
    point points[number_of_points];
    for (i = 0; i < number_of_points; i++){
        points[i].x = i;
        points[i].y = 3 * i;
    }

    for (i = 0; i < number_of_points; i++){
        printf("(%.2lf, %.2lf)\n", points[i].x, points[i].y);
    }

    return 0;

}