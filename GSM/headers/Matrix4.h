////////////////////////////////////////////////////////////////////////////////////////////////////////////
////																									
////		Name:		Matrix4													
////																									
////		Purpose:	Matrix4 class															
////																									
////		Author:		Jack Booker s171742 / CIT213657 2017
////

#pragma once

#include "Vector4.h"

class Matrix4
{
public:
	Matrix4();
	Matrix4(float *a_ptr);
	Matrix4(float a_m1, float a_m2, float a_m3, float a_m4, float a_m5, float a_m6, float a_m7, float a_m8, float a_m9, float m10, float m11, float m12,
	float m13, float m14, float m15, float m16);
	~Matrix4() = default;

	explicit operator float* () { return m; }
	Vector4 operator * (const Vector4 &a_rhs) const;
	Matrix4  operator *(const Matrix4 &a_rhs) const;
	Matrix4 &operator =(const Matrix4 & a_rhs);

	void set(float *a_ptr);
	void set(float a_m1, float a_m2, float a_m3, float a_m4, float a_m5, float a_m6, float a_m7, float a_m8, float a_m9, float m10, float m11, float m12,
		float m13, float m14, float m15, float m16);

	void setRotateX(float a_rot);
	void setRotateY(float a_rot);
	void setRotateZ(float a_rot);
	float getRotationZ();

	Vector4 &operator[] (int a_index) {
		return v[a_index];
	}

	union {
		struct {
			float m1; float m2; float m3; float m4; float m5; float m6; float m7; float m8; float m9; float m10; float m11; float m12;
			float m13; float m14; float m15; float m16;
		};
		struct { float m[16]; };
		struct { float m_floats[4][4]; };
		struct { Vector4 v[3]; };
	};
};

