#include<stdio.h>
#include<iostream>
#include<fstream>
#include<math.h>
using namespace std;

void main(void)
{
	ofstream scr("ellipsoid.scr");
	cout << "��ص���̬���룬��׽���ȣ����ҽ�wcs�ӽǵ�����ǰ��" << endl;
	cout << "���򷽳�Ϊ(x/a)^2+(y/b)^2+(z/c)^2=r^2" << endl;
	cout << "��һ������abcr,�Կո�������س�����" << endl;

	//��Բ�Ĳ���
	double a = 0.8;
	double b = 1.2;
	double c = 1.5;
	double r = 1.0;
	cin >> a;
	cin >> b;
	cin >> c;
	cin >> r;

	cout << "���򷽳�Ϊ��";
	cout<<"(x/"<<a<< ") ^ 2 + (y /"<< b<<") ^ 2 + (z /"<< c<<") ^ 2 ="<< r<<" ^ 2" << endl;

	double nz = 20;//��Ƭ����̫���˿��ܳ���
	double x1[3];//��������
	double x2[3];//�˵�1
	double x3[3];//�˵�2



	//�������˵��СԲ
	//��Բ���ĵ�
	x1[0] = 0; x1[1] = 0; x1[2] = r*c*0.9999;
	//��Բ�˵�1
	double radius = sqrt(r*r - (x1[2] / c)*(x1[2] / c));
	x2[0] = 0; x2[1] = radius*b; x2[2] = r*c*0.9999;
	//��Բ�˵�2
	x3[0] = radius*a; x3[1] = 0; x3[2] = r*c*0.9999;
	scr << "ELLIPSE C " << x1[0] << "," << x1[1] << "," << x1[2] << " " << x2[0] << "," << x2[1] << " " << x3[0] << endl;
	scr << "ELLIPSE C " << x1[0] << "," << x1[1] << "," << -x1[2] << " " << x2[0] << "," << x2[1] << " " << x3[0] << endl;

	//���ϰ벿��
	for (int i = 0; i < nz; i++)
	{
		//��Բ���ĵ�
		x1[0] = 0; x1[1] = 0; x1[2] = i*r*c / nz;
		//��Բ�˵�1
		double radius = sqrt(r*r - (x1[2] / c)*(x1[2] / c));
		x2[0] = 0; x2[1] = radius*b; x2[2] = i*r*c / nz;
		//��Բ�˵�2
		x3[0] = radius*a; x3[1] = 0; x3[2] = i*r*c / nz;

		scr << "ELLIPSE C " << x1[0] << "," << x1[1] << "," << x1[2] << " " << x2[0] << "," << x2[1] << " " << x3[0] << endl;
		//scr << "ELLIPSE C " << x1[0] << "," << x1[1] << ",-" << x1[2] << " " << x2[0] << "," << x2[1] << ",-" << x2[2] << " " << x3[0] << endl;
	}
	//���°벿��
	for (int i = 1; i < nz; i++)
	{
		//��Բ���ĵ�
		x1[0] = 0; x1[1] = 0; x1[2] = i*r*c / nz;
		//��Բ�˵�1
		double radius = sqrt(r*r - (x1[2] / c)*(x1[2] / c));
		x2[0] = 0; x2[1] = radius*b; x2[2] = i*r*c / nz;
		//��Բ�˵�2
		x3[0] = radius*a; x3[1] = 0; x3[2] = i*r*c / nz;

		//scr << "ELLIPSE C " << x1[0] << "," << x1[1] << "," << x1[2] << " " << x2[0] << "," << x2[1] << "," << x2[2] << " " << x3[0] << endl;
		scr << "ELLIPSE C " << x1[0] << "," << x1[1] << ",-" << x1[2] << " " << x2[0] << "," << x2[1] <<" " << x3[0] << endl;

	}
	//��������άʵ��
	scr << "LOFT" << endl;
	double dz = 0.2*c*r / ((nz-1)*1.0);
	scr <<100 << "," << "-100" << "," <<  r*c-dz<< endl;
	scr <<-100 << "," << "100" << "," << r*c<< endl;
	for (int i = nz-1; i >-0.5; i--)
	{
		//��Բ���ĵ�
		x1[0] = 0; x1[1] = 0; x1[2] = i*r*c / nz;
		//��Բ�˵�1
		double radius = sqrt(r*r - (x1[2] / c)*(x1[2] / c));
		x2[0] = 0; x2[1] = radius*b; x2[2] = i*r*c / nz;
		//��Բ�˵�2
		x3[0] = radius*a; x3[1] = 0; x3[2] = i*r*c / nz;

		//scr << x2[0] << "," <<x2[1] << "," << x2[2] << endl;
		scr << x2[0] + dz << "," << "-100" << "," << x2[2] - dz << endl;
		scr << x2[0] - dz << "," << "100" << "," << x2[2] + dz << endl;
	}
	for (int i = 1; i <nz; i++)
	{
		//��Բ���ĵ�
		x1[0] = 0; x1[1] = 0; x1[2] = i*r*c / nz;
		//��Բ�˵�1
		double radius = sqrt(r*r - (x1[2] / c)*(x1[2] / c));
		x2[0] = 0; x2[1] = radius*b; x2[2] = i*r*c / nz;
		//��Բ�˵�2
		x3[0] = radius*a; x3[1] = 0; x3[2] = i*r*c / nz;

		//scr << x2[0] << "," << x2[1] << ",-" << x2[2] << endl;
		scr << x2[0] + dz << "," << "-100" << ",-" << x2[2] - dz << endl;
		scr << x2[0] - dz << "," << "100" << ",-" << x2[2] + dz << endl;

	}
	scr << 100 << "," << "-100" << "," << -r*c  << endl;
	scr << -100 << "," << "100" << "," << -r*c+dz << endl;
	scr << endl;
	scr << endl;

	scr.close();
}