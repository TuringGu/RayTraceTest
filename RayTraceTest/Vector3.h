// Point.h: interface for the Point class.
//
//////////////////////////////////////////////////////////////////////
#ifndef POINT_H
#define POINT_H
#include <math.h>
#define EPS 1E-6

typedef class Vector3 {
public:
	Vector3() : x(0.0f), y(0.0f), z(0.0f) {};  //���캯��
	Vector3(Vector3& vector3) { x = vector3.x; y = vector3.y; z = vector3.z; }//����������3�������
	Vector3(float a_X, float a_Y, float a_Z) : x(a_X), y(a_Y), z(a_Z) {};//����������3�������
	void Set(float a_X, float a_Y, float a_Z) { x = a_X; y = a_Y; z = a_Z; }//����������3�������
	float Length() { return (float)sqrt(x * x + y * y + z * z); }  //���������ĳ���
	Vector3 Normalize() { float l = 1.0f / Length(); x *= l; y *= l; z *= l; return Vector3(x, y, z); }//ת��Ϊ��λ����
	float Dot(Vector3 a_V) { return x * a_V.x + y * a_V.y + z * a_V.z; }//�������
	float GetFirst() { return x; }  //����������X����
	float GetSecond() { return y; } //����������Y���� 
	float GetThird() { return z; }  //����������Z����
	void operator += (Vector3& a_V) { x += a_V.x; y += a_V.y; z += a_V.z; }//�������
	void operator = (Vector3& a_V) { x = a_V.x; y = a_V.y; z = a_V.z; }//������Ȳ���
	void operator += (Vector3* a_V) { x += a_V->x; y += a_V->y; z += a_V->z; }//�������
	void operator -= (Vector3& a_V) { x -= a_V.x; y -= a_V.y; z -= a_V.z; }//�������
	void operator -= (Vector3* a_V) { x -= a_V->x; y -= a_V->y; z -= a_V->z; }//�������
	void operator *= (float f) { x *= f; y *= f; z *= f; }//������f���
	void operator *= (Vector3& a_V) { x *= a_V.x; y *= a_V.y; z *= a_V.z; }//�������
	void operator *= (Vector3* a_V) { x *= a_V->x; y *= a_V->y; z *= a_V->z; }//�������
	Vector3 operator- () const { return Vector3(-x, -y, -z); }//������
	friend Vector3 operator + (const Vector3& v1, const Vector3& v2) { return Vector3(v1.x + v2.x, v1.y + v2.y, v1.z + v2.z); }//�������
	friend Vector3 operator - (const Vector3& v1, const Vector3& v2) { return Vector3(v1.x - v2.x, v1.y - v2.y, v1.z - v2.z); }//�������
	friend Vector3 operator * (const Vector3& v1, Vector3& v2) { return Vector3(v1.x * v2.x, v1.y * v2.y, v1.z * v2.z); }//�������
	friend Vector3 operator * (float f, const Vector3& v) { return Vector3(v.x * f, v.y * f, v.z * f); } //������f���
	friend Vector3 operator * (const Vector3& v, float f) { return Vector3(v.x * f, v.y * f, v.z * f); } //������f���
	friend Vector3 operator / (const Vector3& v, float f) { return Vector3(v.x / f, v.y / f, v.z / f); } //������f���

private:
	float x;  //������x����
	float y;  //������y����
	float z;  //������z����
}Color;
#define BACKGROUND Vector3( 0, 0, 0 )
#endif