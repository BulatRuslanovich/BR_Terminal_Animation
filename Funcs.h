#ifndef FUNC_H_
#define FUNC_H_
#include <math.h>
#include "vec2.h"
#include "vec3.h"


float clamp(float value, float max, float min) {
	return fmax(fmin(value, max), min);
}

float length(const vec2& vector) {
	return sqrt(vector.x * vector.x + vector.y * vector.y);
}

float length(const vec3& vector) {
	return sqrt(vector.x * vector.x + vector.y * vector.y + vector.z * vector.z);
}

vec3 normalization(vec3 vector) {
	return vector / length(vector);
}

float dot(const vec3& right, const vec3& left) {
	return right.x * left.x + right.y * left.y + right.z * left.z;
}

vec2 sphere(vec3 cameraPosition, vec3 beamDirection, float radius) {
	float b = dot(cameraPosition, beamDirection);
	float c = dot(cameraPosition, cameraPosition) - radius * radius;

	float h = b * b - c;
	
	if (h < 0.0f) {
		return vec2(-1.0f);
	}

	h = sqrt(h);

	return vec2(-b - h, -b + h);
}

#endif
