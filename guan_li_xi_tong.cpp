#include"sheng_ming.h"

//-----------------------------------------------------------------------------------------------------------

void guan_li_xi_tong()
{
	bool opt = true;        //�Ƿ�ѭ����һ����־

	while (opt == true)
	{
		system("cls"); //����
		//�˵��б�
		cout << "\n";
		cout << "\n\t\t********************ְ�����ʹ���ϵͳ********************\n";
		cout << "\t\t*                                                      *\n";
		cout << "\t\t*                                                      *\n";
		cout << "\t\t*   1.ְ��������Ϣ����   2.���Ź���   3.ְ�����ʹ���   *\n";
		cout << "\t\t*                                                      *\n";
		cout << "\t\t*                                                      *\n";
		cout << "\t\t*         4.��λ����λ�ȼ�����     5.�� ��             *\n";
		cout << "\t\t*                                                      *\n";
		cout << "\t\t*                                                      *\n";
		cout << "\t\t********************************************************\n";

		//��������ѡ��
		cout << "\n\t\t��ѡ�������֣�";
		char x[100];
		cin >> x;

		//�ж��û���ѡ��
		switch (x[0])
		{
		case '1':
			system("cls");
			opt = zhi_gong_ji_ben_xin_xi_guan_li();   //ְ��������Ϣ���������˵���
			break;
		case '2':
			system("cls");
			opt = bu_men_guan_li();     //���Ź��������˵���
			break;
		case '3':
			system("cls");
			opt = zhi_gong_gong_zi_guan_li();  //ְ�����ʹ��������˵���
			break;
		case '4':
			system("cls");
			opt = gang_wei_ji_gang_wei_deng_ji_guan_li();  //��λ����λ�ȼ����������˵���
			break;
		case '5':
			system("cls");
			opt = false;        //�ѱ�־λΪ�٣����˳���ѭ��
			break;
		default:
			cout << "\n\t\t�Ƿ����룬������Ŀ¼!\n";
			cout << "\n\t(���������)"; system("pause");
		}
	}
}