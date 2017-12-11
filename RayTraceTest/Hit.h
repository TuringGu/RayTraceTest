// Hit.h: interface for the Hit class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_HIT_H__70A8DBB6_BC95_4345_A75E_8F7ACE8BE314__INCLUDED_)
#define AFX_HIT_H__70A8DBB6_BC95_4345_A75E_8F7ACE8BE314__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#define SCRWIDTH	500
#define SCRHEIGHT	500
#include "Vector3.h"
#include "Material.h"
class Hit {
public:
	Hit() { m_t = 10000000; m_color = BACKGROUND; }//���캯��
	void SetTmin(float a_t) { m_t = a_t; }      //���ý��㴦��Zֵ
	float GetTmin() { return m_t; }      //�õ����㴦��Zֵ
	void SetColor(Color& a_color) { m_color = a_color; } // ������ɫ
	Color GetColor() { return m_color; }    //�õ���ɫ
	void SetPosition(Vector3 a_position) { m_position = a_position; } //���ý��㴦��λ��
	void SetMaterial(Material& a_material) { m_material = a_material; } //���ý��㴦�Ĳ���
	Material GetMaterial() { return m_material; }   //���ز���
	void SetNormal(Vector3& a_normal) { m_normal = a_normal; } //���ý��㴦�ķ�����
	Vector3 GetNormal() { return m_normal; }  //���ؽ��㴦�ķ�����
	Vector3 GetPosition() { return m_position; }  //���ؽ��㴦��λ��
private:
	float m_t;//���㴦��Zֵ
	Color m_color;//��Ļ����ɫ
	Material m_material;//���㴦�Ĳ���
	Vector3 m_normal;//���㴦�ķ�����
	Vector3 m_position;//���㴦��λ��
};

Hit hit[SCRWIDTH][SCRHEIGHT];

#endif // !defined(AFX_HIT_H__70A8DBB6_BC95_4345_A75E_8F7ACE8BE314__INCLUDED_)
