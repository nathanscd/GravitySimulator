#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <math.h>

int main() {
    double y = 100.0;
    double v = 0.0;
    double g = -9.81;
    double dt = 0.1;

    while (y > 0) {
        double y_old = y;
        double v_old = v;

        y = y + v * dt + 0.5 * g * (dt * dt);
        v = v + g * dt;

        if (y <= 0) {
            double a = 0.5 * g;
            double b = v_old;
            double c = y_old;

            double discriminant = b*b - 4*a*c;
            double t_hit = (-b - sqrt(discriminant)) / (2*a);

            double v_hit = v_old + g * t_hit;

            printf("Altura: 0.00 m | Velocidade: %.2f m/s\n", v_hit);
            break;
        }

        printf("Altura: %.2f m | Velocidade: %.2f m/s\n", y, v);
        usleep(100000);
    }

    printf("O objeto atingiu o solo.\n");
    return 0;
}
