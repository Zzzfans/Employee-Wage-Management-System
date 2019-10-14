#include"sheng_ming.h"

//-----------------------------------------------------------------------------------------------------------

bool bu_men_guan_li()
{
	bu_men bu_men_head;
	bu_men_head.next = NULL;

	bu_men bu_men_p;
	bu_men_p.next = NULL;

	bu_men_f_in(&bu_men_head, &bu_men_p);

qi_dian:

	system("cls");

	cout << "\n";
	cout << "\n\t\t************************���Ź���************************\n";
	cout << "\t\t*                                                      *\n";
	cout << "\t\t*                                                      *\n";
	cout << "\t\t*   1.���Ӳ�����Ϣ   2.�޸Ĳ�����Ϣ   3.ɾ��������Ϣ   *\n";
	cout << "\t\t*                                                      *\n";
	cout << "\t\t*                                                      *\n";
	cout << "\t\t*   4.���������Ϣ   5.����           6.�˳�           *\n";
	cout << "\t\t*                                                      *\n";
	cout << "\t\t*                                                      *\n";
	cout << "\t\t********************************************************\n";

	cout << "\n\t\t��ѡ��������:";

	char x[100];
	cin >> x;      //��������

	switch (x[0])
	{
	case '1':
		bu_men_in(&bu_men_head, &bu_men_p);
		goto qi_dian;

	case '2':
		bu_men_xiu_gai(&bu_men_head);
		goto qi_dian;

	case '3':
		bu_men_del(&bu_men_head);
		goto qi_dian;

	case '4':
		bu_men_put(&bu_men_head);
		cout << "\n\t(���������)"; system("pause");
		goto qi_dian;

	case '5':
		bu_men_dong_tai_hui_shou(&bu_men_head);
		return true;

	case '6':
		bu_men_dong_tai_hui_shou(&bu_men_head);
		return false;

	default:
		cout << "\n\t\t�Ƿ�����,������Ŀ¼!\n";
		cout << "\n\t(���������)"; system("pause");
		goto qi_dian;
	}
}

//-----------------------------------------------------------------------------------------------------------

void bu_men_f_in(bu_men *head, bu_men *p)
{
	ifstream in("bu_men_shu_ju.txt", ios::_Nocreate);

	if (!in.is_open())
		return;

	while (!in.eof())
	{
		bu_men *a = new bu_men;

		in >> a->bu_men_bian_hao >> a->bu_men_ming_cheng >> a->bu_men_bian_zhi_shu >> a->bu_men_jian_jie;

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

void bu_men_in(bu_men *head, bu_men *p)
{
	bu_men *a = new bu_men;

	if (head->next == NULL)
		a->bu_men_bian_hao = 1;
	else
		a->bu_men_bian_hao = p->next->bu_men_bian_hao + 1;

	bu_men *b = head->next;

	while (b != NULL)
	{
		if (a->bu_men_bian_hao == b->bu_men_bian_hao)
		{
			a->bu_men_bian_hao++;

			b = head->next;
		}
		else
			b = b->next;
	}

	cout << "\n\t\t�����벿������:"; cin >> a->bu_men_ming_cheng;
	cout << "\n\t\t�����벿�ű�����(����):"; cin >> a->bu_men_bian_zhi_shu;
	cout << "\n\t\t�����벿�ż��:"; cin >> a->bu_men_jian_jie;

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

	bu_men_f_out(head);   // ���浽�ļ� bu_men_shu_ju.txt

	cout << "\n\t\t�������!" << endl << "\n\t(���������)"; system("pause");
}

void bu_men_put(bu_men *head)
{
	if (head->next == NULL)
	{
		cout << "\n\t\tû�в�����Ϣ!" << endl;

		return;
	}

	bu_men *b = head->next;

	cout << "\n     ���ű��     " << "��������     " << "���ű�����     " << "���ż��     " << endl;
	cout << "   |-----------------------------------------------------------------------------------------------------|" << endl;

	while (b != NULL)
	{
		cout << setw(10) << b->bu_men_bian_hao << setw(15) << b->bu_men_ming_cheng << setw(12) << b->bu_men_bian_zhi_shu << "           " << b->bu_men_jian_jie << endl;
		cout << "   |-----------------------------------------------------------------------------------------------------|" << endl;

		b = b->next;
	}
}

void bu_men_del(bu_men *head)
{
	if (head->next == NULL)
	{
		cout << "\n\t\tû�пɹ�ɾ���Ĳ�����Ϣ!" << endl;

		cout << "\n\t(���������)";

		system("pause");

		return;
	}

	bu_men_put(head);

	cout << "\n\t������Ҫɾ���Ĳ��ŵı��:";

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
		if (b2->bu_men_bian_hao == n)
		{
			cout << "\n\t\t�ò�����Ա��,����ɾ��!" << endl;
			cout << "\n\t(���������)"; system("pause");
			return;
		}

		b2 = b2->next;
	}

	zhi_gong_dong_tai_hui_shou(&zhi_gong_head);

	bu_men *last = NULL;
	bu_men *b = head->next;

	int y = 1;

	while (b != NULL)
	{
		if (b->bu_men_bian_hao == n)
		{
			y = 0;
			if (b->bu_men_bian_hao == head->next->bu_men_bian_hao)
			{
				head->next = b->next;
				delete b;
				bu_men_f_out(head);
				cout << "\n\t\tɾ���ɹ�!" << endl;
				break;
			}
			else if (b->next == NULL)
			{
				last->next = NULL;
				delete b;
				bu_men_f_out(head);
				cout << "\n\t\tɾ���ɹ�!" << endl;
				break;
			}
			else
			{
				last->next = b->next;
				delete b;
				bu_men_f_out(head);
				cout << "\n\t\tɾ���ɹ�!" << endl;
				break;
			}
		}
		last = b;
		b = b->next;
	}
	if (y == 1)
		cout << "\n\t\t����ϵͳ�в�δ¼��˲���,��ȷ������Ĳ��ű���Ƿ�����!" << endl;

	cout << "\n\t(���������)"; system("pause");
}

void bu_men_f_out(bu_men *head)
{
	ofstream outf("bu_men_shu_ju.txt");

	bu_men *b = head->next;

	while (b != NULL)
	{
		outf << b->bu_men_bian_hao << " " << b->bu_men_ming_cheng << " " << b->bu_men_bian_zhi_shu << " " << b->bu_men_jian_jie << "\n";

		b = b->next;
	}
	outf.close();
}

void bu_men_xiu_gai(bu_men *head)
{
	if (head->next == NULL)
	{
		cout << "\n\t\tû�пɹ��޸ĵĲ�����Ϣ!" << endl;

		cout << "\n\t(���������)";

		system("pause");

		return;
	}

	bu_men_put(head);

	cout << "\n\t\t������Ҫ�޸ĵĲ��ŵı��:";

	int n;
	cin >> n;

	bu_men *b = head->next;

	int y = 1;

	while (b != NULL)
	{
		if (b->bu_men_bian_hao == n)
		{
			y = 0;

			cout << "\n\t     1.��������     2.���ű�����     3.���ż��     4.����\n";

		re_in:

			cout << "\n\t��ѡ����Ҫ�޸ĵĲ�����Ϣ�򷵻�:";

			char c[100];
			cin >> c;

			switch (c[0])
			{
			case'1':
				cout << "\n\t\t���ò��������޸�Ϊ:";
				cin >> b->bu_men_ming_cheng;
				bu_men_f_out(head);
				cout << "\n\t\t�޸ĳɹ�!";
				break;

			case'2':
				cout << "\n\t\t���ò��ű������޸�Ϊ:";
				cin >> b->bu_men_bian_zhi_shu;
				bu_men_f_out(head);
				cout << "\n\t\t�޸ĳɹ�!";
				break;

			case'3':
				cout << "\n\t\t���ò��ż���޸�Ϊ:";
				cin >> b->bu_men_jian_jie;
				bu_men_f_out(head);
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
		cout << "\n\t\t����ϵͳ�в�δ¼��˲���,��ȷ������Ĳ��ű���Ƿ�����!" << endl;

	cout << "\n\n\t(���������)"; system("pause");
}

void bu_men_dong_tai_hui_shou(bu_men *head)
{
	if (head->next == NULL)
		return;

	bu_men *a = head->next;
	bu_men *temp = NULL;

	while (a != NULL)
	{
		temp = a;

		a = a->next;

		delete temp;
	}
}