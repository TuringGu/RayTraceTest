// Light.h: interface for the Light class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_LIGHT_H__CCD0A844_279D_4B73_910D_008056236329__INCLUDED_)
#define AFX_LIGHT_H__CCD0A844_279D_4B73_910D_008056236329__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "Vector3.h"

class Light {
public:
	void SetAmbient(Vector3& a_ambient) { m_ambient = a_ambient; }  //���û�����
	void SetDiffuse(Vector3& a_diffuse) { m_diffuse = a_diffuse; }  //�������������
	void SetSpecular(Vector3& a_specular) { m_specular = a_specular; }  //���þ��淴�����
	void SetPosition(Vector3& a_position) { m_position = a_position; }   //���ý��㴦��λ��
	Vector3 GetAmbient() { return m_ambient; }    //���ػ�����
	Vector3 GetDiffuse() { return m_diffuse; }    //�������������
	Vector3 GetSpecular() { return m_specular; }  //���ؾ��淴�����
	Vector3 GetPosition() { return m_position; }  //���ؽ��㴦��λ��
private:
	Vector3 m_ambient;  //��������
	Vector3 m_diffuse;  //���������
	Vector3 m_specular; //���淴�����
	Vector3 m_position; //���㴦λ��
};


#endif // !defined(AFX_LIGHT_H__CCD0A844_279D_4B73_910D_008056236329__INCLUDED_)
