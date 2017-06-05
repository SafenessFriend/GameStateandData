#pragma once

class Vector2
{
public:
	Vector2();							// default
	Vector2(float a_x, float a_y);		// parameterized
	Vector2(const Vector2& a_rhs);		// copy
	~Vector2() = default;				// 

	Vector2 operator + (const Vector2& a_rhs) const;						// V2 = V2 + V2 
	Vector2 operator - (const Vector2& a_rhs) const;						// V2 = V2 - V2 
	Vector2& operator += (const Vector2& a_rhs);							// V2 += V2 
	Vector2& operator -= (const Vector2& a_rhs);							// V2 -= V2
	Vector2& operator = (const Vector2& a_rhs);							// V2 = V2

	Vector2 operator * (float a_scalar) const;								// V2 * f
	friend Vector2 operator * (float a_scalar, const Vector2& a_rhs);		//  f * V2

	Vector2& operator *= (float a_scalar);									// V2 *= f

	explicit operator float* () { return &x; }								// *

	float dot(const Vector2& a_rhs);										// dot product

	float magnitude();
	void normalise();
	Vector2 getNormal();

	float x;
	float y;

};



