#ifndef VEC3_H_
#define VEC3_H_
#include "vec2.h"

struct vec3
{
	float x;
	float y;
	float z;

	vec3(float value) {
		x = value;
		y = value;
		z = value;
	}

	vec3(float x, float y, float z) {
		this->x = x;
		this->y = y;
		this->z = z;
	}

	vec3(float x, vec2 uv) {
		this->x = x;
		this->y = uv.x;
		this->z = uv.y;
	}

	vec3 operator+(vec3 const& other) {
		return vec3(x + other.x, y + other.y, z + other.z);
	}


	vec3 operator-(vec3 const& other) {
		return vec3(x - other.x, y - other.y, z - other.z);
	}


	vec3 operator*(vec3 const& other) {
		return vec3(x * other.x, y * other.y, z * other.z);
	}


	vec3 operator/(vec3 const& other) {
		return vec3(x / other.x, y / other.y, z / other.z);
	}

	vec3 operator-() {
		return vec3(-x, -y, -z);
	}
};

#endif
