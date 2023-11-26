#ifndef VEC2_H_
#define VEC2_H_

struct vec2
{
	float x;
	float y;

	vec2(float value) {
		x = value;
		y = value;
	}

	vec2(float x, float y) {
		this->x = x;
		this->y = y;
	}

	vec2 operator+(vec2 const& other) {
		return vec2(x + other.x, y + other.y);
	}


	vec2 operator-(vec2 const& other) {
		return vec2(x - other.x, y - other.y);
	}


	vec2 operator*(vec2 const& other) {
		return vec2(x * other.x, y * other.y);
	}


	vec2 operator/(vec2 const& other) {
		return vec2(x / other.x, y / other.y);
	}
};

#endif