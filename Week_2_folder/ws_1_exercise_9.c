#include <stdio.h>

int main(){

    double lightspeed;
    int days;
    double lightdistance;

    printf("Enter the number of days light is travelling for: ");
    scanf("%i", &days);

    lightspeed = 299792458;
    lightdistance = (lightspeed * 86400) * days;

    printf("The distance travelled by light in %i days is %f meters!", days, lightdistance);

    return 0;
}