#include"sheng_ming.h"

//-----------------------------------------------------------------------------------------------------------

bool gang_wei_ji_gang_wei_deng_ji_guan_li()
{
	gang_wei gang_wei_head;
	gang_wei_head.next = NULL;

	gang_wei gang_wei_p;
	gang_wei_p.next = NULL;

	gang_wei_f_in(&gang_wei_head, &gang_wei_p);

	gang_wei_deng_ji gang_wei_deng_ji_head;
	gang_wei_deng_ji_head.next = NULL;

	gang_wei_deng_ji gang_wei_deng_ji_p;
	gang_wei_deng_ji_p.next = NULL;

	gang_wei_deng_ji_f_in(&gang_wei_deng_ji_head, &gang_wei_deng_ji_p);

qi_dian:

	system("cls"); //����

	cout << "\n";
	cout << "\n\t\t*******************��λ����λ�ȼ�����*******************\n";
	cout << "\t\t*                                                      *\n";
	cout << "\t\t*       1.���Ӹ�λ��Ϣ            5.���Ӹ�λ�ȼ�       *\n";
	cout << "\t\t*                                                      *\n";
	cout << "\t\t*       2.�޸ĸ�λ��Ϣ            6.�޸ĸ�λ�ȼ�       *\n";
	cout << "\t\t*                                                      *\n";
	cout << "\t\t*       3.ɾ����λ��Ϣ            7.ɾ����λ�ȼ�       *\n";
	cout << "\t\t*                                                      *\n";
	cout << "\t\t*       4.�����λ��Ϣ            8.�����λ�ȼ�       *\n";
	cout << "\t\t*                                                      *\n";
	cout << "\t\t*       9.����                    0.�˳�               *\n";
	cout << "\t\t*                                                      *\n";
	cout << "\t\t********************************************************\n";

	cout << "\n\t\t��ѡ�������֣�";

	char x[100];

	cin >> x;      //��������

	switch (x[0])
	{
	case '1':
		gang_wei_in(&gang_wei_head, &gang_wei_p);
		goto qi_dian;

	case '2':
		gang_wei_xiu_gai(&gang_wei_head);
		goto qi_dian;

	case '3':
		gang_wei_del(&gang_wei_head);
		goto qi_dian;

	case '4':
		gang_wei_put(&gang_wei_head);
		cout << "\n\t(���������)"; system("pause");
		goto qi_dian;

	case '5':
		gang_wei_deng_ji_in(&gang_wei_deng_ji_head, &gang_wei_deng_ji_p);
		goto qi_dian;

	case '6':
		gang_wei_deng_ji_xiu_gai(&gang_wei_deng_ji_head);
		goto qi_dian;

	case '7':
		gang_wei_deng_ji_del(&gang_wei_deng_ji_head);
		goto qi_dian;

	case '8':
		gang_wei_deng_ji_put(&gang_wei_deng_ji_head);
		cout << "\n\t(���������)"; system("pause");
		goto qi_dian;

	case '9':
		gang_wei_dong_tai_hui_shou(&gang_wei_head);
		gang_wei_deng_ji_dong_tai_hui_shou(&gang_wei_deng_ji_head);
		return true;

	case '0':
		gang_wei_dong_tai_hui_shou(&gang_wei_head);
		gang_wei_deng_ji_dong_tai_hui_shou(&gang_wei_deng_ji_head);
		return false;


	default:
		cout << "\n\t\t�Ƿ�����,������Ŀ¼!\n";
		cout << "\n\t(���������)"; system("pause");
		goto qi_dian;
	}
}

//-----------------------------------------------------------------------------------------------------------

void gang_wei_f_in(gang_wei *head, gang_wei *p)
{
	ifstream in("gang_wei_shu_ju.txt", ios::_Nocreate);

	if (!in.is_open())
		return;

	while (!in.eof())
	{
		gang_wei *a = new gang_wei;

		in >> a->gang_wei_bian_hao >> a->gang_wei_ming_cheng >> a->basic_gong_zi >> a->zhi_ze;

		if (in.fail())
		{
			delete a;

			break;
		}

		if (head->next == NULL)
		{
			a->next = head->next;
			head->next = a;
			p->next = a;
		}
		else
		{
			p->next->next = a;
			a->next = NULL;
			p->next = a;
		}
	}
	in.close();
}

void gang_wei_in(gang_wei *head, gang_wei *p)
{
	gang_wei *a = new gang_wei;

	if (head->next == NULL)
		a->gang_wei_bian_hao = 1;
	else
		a->gang_wei_bian_hao = p->next->gang_wei_bian_hao + 1;

	gang_wei *b = head->next;

	while (b != NULL)
	{
		if (a->gang_wei_bian_hao == b->gang_wei_bian_hao)
		{
			a->gang_wei_bian_hao++;

			b = head->next;
		}
		else
			b = b->next;
	}

	cout << "\n\t\t�������λ����:"; cin >> a->gang_wei_ming_cheng;
	cout << "\n\t\t�������λ��������(ʵ��):"; cin >> a->basic_gong_zi;
	cout << "\n\t\t�������λְ��:"; cin >> a->zhi_ze;

	if (head->next == NULL)
	{
		a->next = head->next;
		head->next = a;
		p->next = a;
	}
	else
	{
		p->next->next = a;
		a->next = NULL;
		p->next = a;
	}

	gang_wei_f_out(head);   // ���浽�ļ� gang_wei_shu_ju.txt

	cout << "\n\t\t�������!" << endl << "\n\t(���������)"; system("pause");
}

void gang_wei_put(gang_wei *head)
{
	if (head->next == NULL)
	{
		cout << "\n\t\tû�и�λ��Ϣ!" << endl;

		return;
	}

	gang_wei *b = head->next;

	cout << "\n     ��λ���     " << "��λ����     " << "��λ��������     " << "��λְ��     " << endl;
	cout << "   |-----------------------------------------------------------------------------------------------------|" << endl;

	while (b != NULL)
	{
		cout << setw(9) << b->gang_wei_bian_hao << setw(16) << b->gang_wei_ming_cheng << setw(15) << b->basic_gong_zi << "         " << b->zhi_ze << endl;
		cout << "   |-----------------------------------------------------------------------------------------------------|" << endl;

		b = b->next;
	}
}

void gang_wei_del(gang_wei *head)
{
	if (head->next == NULL)
	{
		cout << "\n\t\tû�пɹ�ɾ���ĸ�λ��Ϣ!" << endl;

		cout << "\n\t(���������)";

		system("pause");

		return;
	}

	gang_wei_put(head);

	cout << "\n������Ҫɾ���ĸ�λ�ı��:";

	int n;
	cin >> n;

	zhi_gong zhi_gong_head;
	zhi_gong_head.next = NULL;

	zhi_gong zhi_gong_p;
	zhi_gong_p.next = NULL;

	zhi_gong_f_in(&zhi_gong_head, &zhi_gong_p);

	zhi_gong *b2 = zhi_gong_head.next;

	while (b2 != NULL)
	{
		if (b2->gang_wei_bian_hao == n)
		{
			cout << "\n\t\t�ø�λ��Ա��,����ɾ��!" << endl;
			cout << "\n\t(���������)"; system("pause");
			return;
		}

		b2 = b2->next;
	}

	zhi_gong_dong_tai_hui_shou(&zhi_gong_head);

	gang_wei *last = NULL;
	gang_wei *b = head->next;

	int y = 1;

	while (b != NULL)
	{
		if (b->gang_wei_bian_hao == n)
		{
			y = 0;
			if (b->gang_wei_bian_hao == head->next->gang_wei_bian_hao)
			{
				head->next = b->next;
				delete b;
				gang_wei_f_out(head);
				cout << "\n\t\tɾ���ɹ�!" << endl;
				break;
			}
			else if (b->next == NULL)
			{
				last->next = NULL;
				delete b;
				gang_wei_f_out(head);
				cout << "\n\t\tɾ���ɹ�!" << endl;
				break;
			}
			else
			{
				last->next = b->next;
				delete b;
				gang_wei_f_out(head);
				cout << "\n\t\tɾ���ɹ�!" << endl;
				break;
			}
		}
		last = b;
		b = b->next;
	}
	if (y == 1)
		cout << "\n\t\t��λϵͳ�в�δ¼��˸�λ,��ȷ������ĸ�λ����Ƿ�����!" << endl;

	cout << "\n\t(���������)"; system("pause");
}

void gang_wei_f_out(gang_wei *head)
{
	ofstream outf("gang_wei_shu_ju.txt");

	gang_wei *b = head->next;

	while (b != NULL)
	{
		outf << b->gang_wei_bian_hao << " " << b->gang_wei_ming_cheng << " " << b->basic_gong_zi << " " << b->zhi_ze << "\n";

		b = b->next;
	}
	outf.close();
}

void gang_wei_xiu_gai(gang_wei *head)
{
	if (head->next == NULL)
	{
		cout << "\n\t\tû�пɹ��޸ĵĸ�λ��Ϣ!" << endl;

		cout << "\n\t(���������)";

		system("pause");

		return;
	}

	gang_wei_put(head);

	cout << "\n\t\t������Ҫ�޸ĵĸ�λ�ı��:";

	int n;
	cin >> n;

	gang_wei *b = head->next;

	int y = 1;

	while (b != NULL)
	{
		if (b->gang_wei_bian_hao == n)
		{
			y = 0;

			cout << "\n\t     1.��λ����     2.��λ��������     3.��λְ��     4.����\n";

		re_in:

			cout << "\n\t��ѡ����Ҫ�޸ĵĸ�λ��Ϣ:";

			char c[100];
			cin >> c;

			switch (c[0])
			{
			case'1':
				cout << "\n\t\t���ø�λ�����޸�Ϊ:";
				cin >> b->gang_wei_ming_cheng;
				gang_wei_f_out(head);
				cout << "\n\t\t�޸ĳɹ�!";
				break;

			case'2':
				cout << "\n\t\t���ø�λ���������޸�Ϊ:";
				cin >> b->basic_gong_zi;
				gang_wei_f_out(head);
				cout << "\n\t\t�޸ĳɹ�!";
				break;

			case'3':
				cout << "\n\t\t���ø�λְ���޸�Ϊ:";
				cin >> b->zhi_ze;
				gang_wei_f_out(head);
				cout << "\n\t\t�޸ĳɹ�!";
				break;

			case'4':
				return;

			default:
				cout << "\n\t\t��ȷ������Ĺ��ܺ����Ƿ�����!����������!" << endl;
				goto re_in;
			}
		}
		b = b->next;
	}
	if (y == 1)
		cout << "\n\t\t��λϵͳ�в�δ¼��˸�λ,��ȷ������ĸ�λ����Ƿ�����!" << endl;

	cout << "\n\t(���������)"; system("pause");
}

void gang_wei_dong_tai_hui_shou(gang_wei *head)
{
	if (head->next == NULL)
		return;

	gang_wei *a = head->next;
	gang_wei *temp = NULL;

	while (a != NULL)
	{
		temp = a;

		a = a->next;

		delete temp;
	}
}

//-----------------------------------------------------------------------------------------------------------

void gang_wei_deng_ji_f_in(gang_wei_deng_ji *head, gang_wei_deng_ji *p)
{
	ifstream in("gang_wei_deng_ji_shu_ju.txt", ios::_Nocreate);

	if (!in.is_open())
		return;

	while (!in.eof())
	{
		gang_wei_deng_ji *a = new gang_wei_deng_ji;

		in >> a->gang_wei_deng_ji_bian_hao >> a->gang_wei_deng_ji_ming_cheng >> a->gong_zi_xi_shu;

		if (in.fail())
		{
			delete a;

			break;
		}

		if (head->next == NULL)
		{
			a->next = head->next;
			head->next = a;
			p->next = a;
		}
		else
		{
			p->next->next = a;
			a->next = NULL;
			p->next = a;
		}
	}
	in.close();
}

void gang_wei_deng_ji_in(gang_wei_deng_ji *head, gang_wei_deng_ji *p)
{
	gang_wei_deng_ji *a = new gang_wei_deng_ji;

	if (head->next == NULL)
		a->gang_wei_deng_ji_bian_hao = 1;
	else
		a->gang_wei_deng_ji_bian_hao = p->next->gang_wei_deng_ji_bian_hao + 1;

	gang_wei_deng_ji *b = head->next;

	while (b != NULL)
	{
		if (a->gang_wei_deng_ji_bian_hao == b->gang_wei_deng_ji_bian_hao)
		{
			a->gang_wei_deng_ji_bian_hao++;

			b = head->next;
		}
		else
			b = b->next;
	}

	cout << "\n\t\t�������λ�ȼ�����:"; cin >> a->gang_wei_deng_ji_ming_cheng;
	cout << "\n\t\t������λ�ȼ�����ϵ��:"; cin >> a->gong_zi_xi_shu;

	if (head->next == NULL)
	{
		a->next = head->next;
		head->next = a;
		p->next = a;
	}
	else
	{
		p->next->next = a;
		a->next = NULL;
		p->next = a;
	}

	gang_wei_deng_ji_f_out(head);   // ���浽�ļ� gang_wei_deng_ji_shu_ju.txt

	cout << "\n\t\t�������!" << endl << "\n\t(���������)"; system("pause");
}

void gang_wei_deng_ji_put(gang_wei_deng_ji *head)
{
	if (head->next == NULL)
	{
		cout << "\n\t\tû�и�λ�ȼ���Ϣ!" << endl;

		return;
	}

	gang_wei_deng_ji *b = head->next;

	cout << "\n     ��λ�ȼ����     " << "��λ�ȼ�����     " << "��λ�ȼ�����ϵ��     " << endl;
	cout << "   |------------------------------------------------------|" << endl;

	while (b != NULL)
	{
		cout << setw(12) << b->gang_wei_deng_ji_bian_hao << setw(19) << b->gang_wei_deng_ji_ming_cheng << setw(18) << b->gong_zi_xi_shu << endl;
		cout << "   |------------------------------------------------------|" << endl;

		b = b->next;
	}
}

void gang_wei_deng_ji_del(gang_wei_deng_ji *head)
{
	if (head->next == NULL)
	{
		cout << "\n\t\tû�пɹ�ɾ���ĸ�λ�ȼ���Ϣ!" << endl;

		cout << "\n\t(���������)";

		system("pause");

		return;
	}

	gang_wei_deng_ji_put(head);

	cout << "\n������Ҫɾ���ĸ�λ�ȼ��ı��:";

	int n;
	cin >> n;

	zhi_gong zhi_gong_head;
	zhi_gong_head.next = NULL;

	zhi_gong zhi_gong_p;
	zhi_gong_p.next = NULL;

	zhi_gong_f_in(&zhi_gong_head, &zhi_gong_p);

	zhi_gong *b2 = zhi_gong_head.next;

	while (b2 != NULL)
	{
		if (b2->gang_wei_deng_ji_bian_hao == n)
		{
			cout << "\n\t\t�ø�λ�ȼ���Ա��,����ɾ��!" << endl;
			cout << "\n\t(���������)"; system("pause");
			return;
		}

		b2 = b2->next;
	}

	zhi_gong_dong_tai_hui_shou(&zhi_gong_head);

	gang_wei_deng_ji *last = NULL;
	gang_wei_deng_ji *b = head->next;

	int y = 1;

	while (b != NULL)
	{
		if (b->gang_wei_deng_ji_bian_hao == n)
		{
			y = 0;
			if (b->gang_wei_deng_ji_bian_hao == head->next->gang_wei_deng_ji_bian_hao)
			{
				head->next = b->next;
				delete b;
				gang_wei_deng_ji_f_out(head);
				cout << "\n\t\tɾ���ɹ�!" << endl;
				break;
			}
			else if (b->next == NULL)
			{
				last->next = NULL;
				delete b;
				gang_wei_deng_ji_f_out(head);
				cout << "\n\t\tɾ���ɹ�!" << endl;
				break;
			}
			else
			{
				last->next = b->next;
				delete b;
				gang_wei_deng_ji_f_out(head);
				cout << "\n\t\tɾ���ɹ�!" << endl;
				break;
			}
		}
		last = b;
		b = b->next;
	}
	if (y == 1)
		cout << "\n\t\t��λ�ȼ�ϵͳ�в�δ¼��˸�λ�ȼ�,��ȷ������ĸ�λ�ȼ�����Ƿ�����!" << endl;

	cout << "\n\t(���������)"; system("pause");
}

void gang_wei_deng_ji_f_out(gang_wei_deng_ji *head)
{
	ofstream outf("gang_wei_deng_ji_shu_ju.txt");

	gang_wei_deng_ji *b = head->next;

	while (b != NULL)
	{
		outf << b->gang_wei_deng_ji_bian_hao << " " << b->gang_wei_deng_ji_ming_cheng << " " << b->gong_zi_xi_shu << "\n";

		b = b->next;
	}
	outf.close();
}

void gang_wei_deng_ji_xiu_gai(gang_wei_deng_ji *head)
{
	if (head->next == NULL)
	{
		cout << "\n\t\tû�пɹ��޸ĵĸ�λ�ȼ���Ϣ!" << endl;

		cout << "\n\t(���������)";

		system("pause");

		return;
	}

	gang_wei_deng_ji_put(head);

	cout << "\n\t\t������Ҫ�޸ĵĸ�λ�ȼ��ı��:";

	int n;
	cin >> n;

	gang_wei_deng_ji *b = head->next;

	int y = 1;

	while (b != NULL)
	{
		if (b->gang_wei_deng_ji_bian_hao == n)
		{
			y = 0;

			cout << "\n\t     1.��λ����     2.��λ�ȼ�����ϵ��     3.����\n";

		re_in:

			cout << "\n\t��ѡ����Ҫ�޸ĵĸ�λ�ȼ���Ϣ:";

			char c[100];
			cin >> c;

			switch (c[0])
			{
			case'1':
				cout << "\n\t\t���ø�λ�����޸�Ϊ:";
				cin >> b->gang_wei_deng_ji_ming_cheng;
				gang_wei_deng_ji_f_out(head);
				cout << "\n\t\t�޸ĳɹ�!";
				break;

			case'2':
				cout << "\n\t\t���ø�λ�ȼ�����ϵ���޸�Ϊ:";
				cin >> b->gong_zi_xi_shu;
				gang_wei_deng_ji_f_out(head);
				cout << "\n\t\t�޸ĳɹ�!";
				break;

			case'3':
				return;

			default:
				cout << "\n\t\t��ȷ������Ĺ��ܺ����Ƿ�����!����������!" << endl;
				goto re_in;
			}
		}
		b = b->next;
	}
	if (y == 1)
		cout << "\n\t\t��λ�ȼ�ϵͳ�в�δ¼��˸�λ�ȼ�,��ȷ������ĸ�λ�ȼ�����Ƿ�����!" << endl;

	cout << "\n\t(���������)"; system("pause");
}

void gang_wei_deng_ji_dong_tai_hui_shou(gang_wei_deng_ji *head)
{
	if (head->next == NULL)
		return;

	gang_wei_deng_ji *a = head->next;
	gang_wei_deng_ji *temp = NULL;

	while (a != NULL)
	{
		temp = a;

		a = a->next;

		delete temp;
	}
}