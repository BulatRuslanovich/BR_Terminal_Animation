#include <iostream>
#include <cmath>

#include "Funcs.h"
#include "vec2.h"

using namespace std;

int main() {
    int width = 120;
    int height = 30;
    float aspect = (float)width / height;
    float pixelAspect = 10.5f / 24.0f;
    char* screen = new char[width * height + 1];
	char gradient[] = " .:!/r(l1Z4H9W8$@";
	int gradientSize = size(gradient) - 2;

    screen[width * height] = '\0';
	vec3 cameraPosition = vec3(-5, 0, 0);
	

	printf("\e[?25l"); //? hide cursor
    for (int t = 0; t < 1000000; t++) {
		printf("\033[%d;%dH", (0), (0)); //? set cursor's position 
		vec3 lightDirection = normalization(vec3(cos(t * 0.001), -sin(t * 0.001), -sin(t * 0.001)));
        for (int i = 0; i < width; i++) {
            for (int j = 0; j < height; j++) {
                vec2 uv = vec2(i, j) / vec2(width, height) * 2.0f - 1.0f;
                uv.x *= aspect * pixelAspect;
				
				vec3 beamDirection = normalization(vec3(1, uv));
                char pixel = ' ';
				int color = 0;

				vec2 intersection = sphere(cameraPosition, beamDirection, 3);
				
				if (intersection.x > 0) {
					vec3 n = normalization(cameraPosition + beamDirection * intersection.x);
					float diff = dot(n, lightDirection);
					color = diff * 20;
				}

				color = clamp(color, gradientSize, 0);

                pixel = gradient[color];

                screen[i + j * width] = pixel;
            }
        }
		printf(screen);
    }
	printf("\e[?25h"); //? return cursor

}