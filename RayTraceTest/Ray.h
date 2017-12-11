// Ray.h: interface for the Ray class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_RAY_H__1E702CD5_E748_4FBF_972F_F6856A823522__INCLUDED_)
#define AFX_RAY_H__1E702CD5_E748_4FBF_972F_F6856A823522__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "Vector3.h"
class Ray
{
public:
	Ray() : m_Origin(Vector3(0, 0, 0)), m_Direction(Vector3(0, 0, 0)) {};//���캯������ʼ���ӵ�����ߵķ���
	Ray(Vector3& a_Origin, Vector3& a_Dir) : m_Origin(a_Origin), m_Direction(a_Dir) {}//�����ӵ�����ߵķ���
	void SetOrigin(Vector3& a_Origin) { m_Origin = a_Origin; }//�����ӵ��λ��
	void SetDirection(Vector3& a_Direction) { m_Direction = a_Direction; }//�������ߵķ���
	Vector3& GetOrigin() { return m_Origin; }//�����ӵ��λ��
	Vector3& GetDirection() { return m_Direction; }//�������ߵķ���
private:
	Vector3 m_Origin;//�ӵ�
	Vector3 m_Direction;//���ߵķ���
};

#endif // !defined(AFX_RAY_H__1E702CD5_E748_4FBF_972F_F6856A823522__INCLUDED_)
