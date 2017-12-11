// RayTrace.cpp : Defines the entry point for the console application.
//

#include <stdlib.h>
#include <math.h>

#include "GL\glut.h"
#include "Light.h"
#include "Hit.h"
#include "Material.h"
#include "Object3D.h"
#include "Ray.h"
#include "Scene.h"

float max(float x, float y)  //�������ֵ
{
	if (x >= y)
		return x;
	else
		return y;
}

float min(float x, float y)  //������Сֵ
{
	if (x <= y)
		return x;
	else
		return y;
}

Color RayTracing(Scene&, Light&, Ray&, int);//���߸���

Color RayShading(Scene& s1, Light& light, Object3D* object, int o, Ray& ray,
	Hit& hit, Vector3& point, Vector3& noraml, int depth) {
	Color color;//���ߵ���ɫ
	Ray rRay, sRay;//������ߣ���Ӱ����
	Color rColor;//������ߵ���ɫ
	color = light.GetAmbient()*(object->GetMaterial().GetColor());//��û��������ɫ
	sRay.SetOrigin(hit.GetPosition());//�ӽ��㵽��Դ�Ĺ���
	sRay.SetDirection(light.GetPosition() - hit.GetPosition());//���ù��ߵķ���
															   //��������Ӱ���ߵ������0�����ܱ����յ���
	if (sRay.GetDirection().Dot(hit.GetNormal())>0) {
		Hit h;
		if (s1.m_objlist[1 - o]->intersect(sRay, h, h.GetTmin())) {
		}
		else {
			color += max(((light.GetPosition() - hit.GetPosition()).Normalize()).Dot(hit.GetNormal().Normalize()), 0)*light.GetDiffuse()*(object->GetMaterial().GetColor());
			color += pow(max((((light.GetPosition() - hit.GetPosition()) + (ray.GetOrigin() - hit.GetPosition())).Normalize()).Dot(hit.GetNormal().Normalize()), 0), object->GetMaterial().GetShininess())*light.GetSpecular()*(object->GetMaterial().GetSpecular());//�����
		}
	}
	if (depth<4) {//������̫���򷵻�
		if (object->GetMaterial().GetReflection()>0) {//�����Ƿ�����
			rRay.SetOrigin(hit.GetPosition());
			Vector3 r, d;
			d = ray.GetDirection();
			r = d + 2 * fabs(d.Dot(hit.GetNormal().Normalize()))*(hit.GetNormal().Normalize());
			rRay.SetDirection(r);
			rColor = RayTracing(s1, light, rRay, depth + 1);
			color += rColor*(object->GetMaterial().GetReflection());
		}
	}
	color.Set(min(color.GetFirst(), 1.0), min(color.GetSecond(), 1.0), min(color.GetThird(), 1.0));
	return color;
}
//���߸���
Color RayTracing(Scene& s1, Light& light, Ray& ray, int depth) {
	Hit hit;
	bool flag[2];
	flag[0] = s1.m_objlist[0]->intersect(ray, hit, hit.GetTmin());
	float t1 = hit.GetTmin();
	flag[1] = s1.m_objlist[1]->intersect(ray, hit, hit.GetTmin());
	float t2 = hit.GetTmin();
	if (flag[0] || flag[1]) {
		if (flag[0] && !flag[1]) {
			return RayShading(s1, light, s1.m_objlist[0], 0, ray, hit, hit.GetPosition(), hit.GetNormal(), depth);
		}
		else if (!flag[0] && flag[1]) {
			return RayShading(s1, light, s1.m_objlist[1], 1, ray, hit, hit.GetPosition(), hit.GetNormal(), depth);
		}
		else {
			if (t1>t2)
				return RayShading(s1, light, s1.m_objlist[1], 1, ray, hit, hit.GetPosition(), hit.GetNormal(), depth);
			else
				return RayShading(s1, light, s1.m_objlist[0], 0, ray, hit, hit.GetPosition(), hit.GetNormal(), depth);
		}
	}
	else {
		if (depth == 1) {
			return BACKGROUND;
		}
		else {
			return RayShading(s1, light, s1.m_objlist[0], 0, ray, hit, hit.GetPosition(), hit.GetNormal(), depth);
		}
	}
}

void display(void)
{
	glClear(GL_COLOR_BUFFER_BIT);

	Scene s1;
	s1.create_scene();// ��������

	Light light;  //��������
	light.SetPosition(Vector3(0, 500, -100));
	light.SetAmbient(Vector3(0.1, 0.1, 0.1));
	light.SetDiffuse(Vector3(1.0, 1.0, 1.0));
	light.SetSpecular(Vector3(1.0, 1.0, 1.0));
	Vector3 e(SCRWIDTH / 2, SCRHEIGHT / 2, -200);
	for (int b = 0; b<SCRHEIGHT; b++) {
		for (int a = 0; a<SCRWIDTH; a++) {
			Vector3 s(a, b, 0);//s����Ļ�ϵ����ص�
			Ray ray(e, (s - e));
			hit[a][b].SetColor(RayTracing(s1, light, ray, 1));

		}
	}
	/*��������Ļ�ϵ����ص����*/
	for (int d = 0; d<SCRHEIGHT; d++) {
		for (int c = 0; c<SCRWIDTH; c++) {
			glColor3f(hit[c][d].GetColor().GetFirst(), hit[c][d].GetColor().GetSecond(), hit[c][d].GetColor().GetThird());
			glBegin(GL_POINTS);
			glVertex2d(c, d);// �м��ǵ������ 
			glEnd();
		}
	}

	glFlush();
}

void init(void)
{
	glClearColor(0.0, 0.0, 0.0, 0.0);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0, 500, 0, 500);
}


int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(SCRWIDTH, SCRHEIGHT);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("Ray Trace (by TuringGu)");
	init();
	glutDisplayFunc(display);
	glutMainLoop();
	return 0;
}