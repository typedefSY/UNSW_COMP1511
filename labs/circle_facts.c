// COMP1511 Week 4 Lab: Circle Facts
//
// This program was written by Steve Yang (z5374603)
// on 4th. October
//
// This program prints out facts about a circle given its radius,
// using functions.
//

#include <stdio.h>
#include <math.h>
#define PI acos(-1)

struct circle {
    double radius;
    int x;
    int y;
};

double area(struct circle circ);
double circumference(struct circle circ);
struct circle add_position(struct circle circ, int x, int y);

// DO NOT CHANGE THIS MAIN FUNCTION
int main(void) {
    struct circle circ;
    int x_offset;
    int y_offset;

    printf("Enter circle radius: ");
    scanf("%lf", &circ.radius);

    printf("Enter circle position (x, y): ");
    scanf("%d %d", &circ.x, &circ.y);

    printf("Enter an offset for the circle (x, y): ");
    scanf("%d %d", &x_offset, &y_offset);

    printf("\nArea             = %lf\n", area(circ));
    printf("Circumference    = %lf\n", circumference(circ));
    printf("Initial position = (%d, %d)\n", circ.x, circ.y);

    circ = add_position(circ, x_offset, y_offset);

    printf("Offset position  = (%d, %d)\n", circ.x, circ.y);

    return 0;
}

// Calculate the area of the given circle and return it.
double area(struct circle circ)
{
    double area;
    area = circ.radius * circ.radius * PI;
    return area;
}

// Calculate the circumference of the given circle and return it.
double circumference(struct circle circ) {
    double circumference;
    circumference = 2 * PI * circ.radius;
    return circumference;
}

// Add the given coordinates to those in the given circle. Return the circle
// after this addition.
struct circle add_position(struct circle circ, int x, int y) {
    circ.x += x;
    circ.y += y;
    return circ;
}
