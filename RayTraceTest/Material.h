// Material.h: interface for the Material class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_MATERIAL_H__50634E23_83FA_442F_B629_FACF60489D2E__INCLUDED_)
#define AFX_MATERIAL_H__50634E23_83FA_442F_B629_FACF60489D2E__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "Vector3.h"
class Material
{
public:
	Material() {}  //���캯��
	void SetColor(Color& a_Color) { m_Color = a_Color; } //�����������ɫ
	Color GetColor() { return m_Color; }                   //�����������ɫ
	void SetDiffuse(float a_Diff) { m_Diff = a_Diff; }   //����������ϵ��
	void SetSpecular(float a_Spec) { m_Spec = a_Spec; }  //���þ��淴��ϵ��
	void SetReflection(float a_Refl) { m_Refl = a_Refl; }//���ò��ϵ�Ӱ��
	void SetRefraction(float a_Refr) { m_Refr = a_Refr; }//���ò��ϵ�����ϵ��
	float GetSpecular() { return m_Spec; }                 //���ؾ���ϵ��
	float GetDiffuse() { return m_Diff; }                  //����ɢ��ϵ��
	float GetReflection() { return m_Refl; }               //���ز��ϵ�Ӱ��
	float GetRefraction() { return m_Refr; }               //��������ϵ��  
	void SetRefrIndex(float a_Refr) { m_RIndex = a_Refr; }//���û�����ɢ��;�����ɫ����
	float GetRefrIndex() { return m_RIndex; }               //���ػ�����ɢ��;�����ɫ����
	void SetShininess(int a_Shin) { m_Shin = a_Shin; }        //���þ���ָ��
	int GetShininess() { return m_Shin; }                      //���ؾ���ָ��
	void operator = (Material& a_V)                       //�Ѳ��ϵĸ���ϵ����ֵ����������
	{
		m_Color = a_V.m_Color; m_Refl = a_V.m_Refl; m_Refr = a_V.m_Refr; m_Diff = a_V.m_Diff; m_Spec = a_V.m_Spec; m_RIndex = a_V.m_RIndex; m_Shin = a_V.m_Shin;
	}
private:
	Color m_Color;//���屾������ɫ
	float m_Refl, m_Refr;//���ϵ�Ӱ�������ϵ��
	float m_Diff, m_Spec;//���ϵ�ɢ��ϵ���;���ϵ��
	int m_Shin;//����ָ��
	float m_RIndex;//������ɢ��;�����ɫ����
};

#endif // !defined(AFX_MATERIAL_H__50634E23_83FA_442F_B629_FACF60489D2E__INCLUDED_)
