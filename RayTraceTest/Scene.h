// Scene.h: interface for the Scene class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_SCENE_H__1BB16233_561A_4D63_BA15_8FE397FA36DF__INCLUDED_)
#define AFX_SCENE_H__1BB16233_561A_4D63_BA15_8FE397FA36DF__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
//#include <vector>
//#include "glut.h"
#include "GL\glut.h"
#include "ray.h"
//#define TRACE_DEPTH 1
//using namespace std;
#include "Sphere.h"
class Scene {
public:

	//	bool load_scene(char*);
	void create_scene();  //��������
	int m_nObject;       //����������ĸ���
	Object3D *m_objlist[2];//�������������
	Material *m_matlist[2];//��������
};
void Scene::create_scene() {
	m_nObject = 2;     //��������
	Color m_c1, m_c2; //������ɫ
	m_c1.Set(0, 0, 1);  //��������1����ɫ
	m_c2.Set(1, 1, 0);  //��������2����ɫ

	Material m_material1, m_material2;  //��������Ĳ���
	m_material1.SetColor(m_c1);  //���ò���1����ɫ
	m_material1.SetShininess(100); //���ò���1�ľ���ָ��
	m_material1.SetDiffuse(0.8);   //���ò���1��������ϵ��
	m_material1.SetSpecular(0.5);  //���ò���1�ľ���ָ��
	m_material1.SetReflection(0.3);//���ò���1��Ӱ��
	m_matlist[0] = &m_material1;     // �Ѳ���2�ŵ�������

	m_material2.SetColor(m_c2);//���ò���2����ɫ
	m_material2.SetShininess(100);//���ò���2�ľ���ָ��
	m_material2.SetDiffuse(0.8);  //���ò���2��������ϵ��
	m_material2.SetSpecular(0.5); //���ò���2�ľ���ָ��
	m_material2.SetReflection(0.3);//���ò���2��Ӱ��
	m_matlist[1] = &m_material2;   // �Ѳ���2�ŵ�������

	Vector3 m_center1, m_center2;  //������������
	m_center1.Set(100, 200, 200);   //��������ֵ
	m_center2.Set(300, 260, 180);   //��������ֵ

	Sphere *m_pSphere1, *m_pSphere2;  //��������
	m_pSphere1 = new Sphere();   //��������1
	m_pSphere1->SetCenter(m_center1); //�������������
	m_pSphere1->SetRadius(100);  //��������İ뾶
	m_pSphere1->SetMaterial(*m_matlist[0]);//��������Ĳ���
	m_objlist[0] = m_pSphere1;  //������1���볡����������


	m_pSphere2 = new Sphere();  //��������2	
	m_pSphere2->SetCenter(m_center2);  //�������������
	m_pSphere2->SetRadius(80);        //��������İ뾶
	m_pSphere2->SetMaterial(*m_matlist[1]);//��������Ĳ���
	m_objlist[1] = m_pSphere2;  //������2���볡����������
}

#endif