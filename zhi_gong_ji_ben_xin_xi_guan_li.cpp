#include"sheng_ming.h"

//-----------------------------------------------------------------------------------------------------------

bool zhi_gong_ji_ben_xin_xi_guan_li()
{
	zhi_gong zhi_gong_head;
	zhi_gong_head.next = NULL;

	zhi_gong zhi_gong_p;
	zhi_gong_p.next = NULL;

	zhi_gong_f_in(&zhi_gong_head, &zhi_gong_p);

qi_dian:

	system("cls");

	cout << "\n";
	cout << "\n\t\t********************ְ��������Ϣ����********************\n";
	cout << "\t\t*                                                      *\n";
	cout << "\t\t*                                                      *\n";
	cout << "\t\t*   1.����ְ����Ϣ   2.�޸�ְ����Ϣ   3.ɾ��ְ����Ϣ   *\n";
	cout << "\t\t*                                                      *\n";
	cout << "\t\t*                                                      *\n";
	cout << "\t\t*   4.���ְ����Ϣ   5.��ѯ           6.����           *\n";
	cout << "\t\t*                                                      *\n";
	cout << "\t\t*                                                      *\n";
	cout << "\t\t*                    7.�˳�                            *\n";
	cout << "\t\t*                                                      *\n";
	cout << "\t\t*                                                      *\n";
	cout << "\t\t********************************************************\n";

	cout << "\n\t\t��ѡ�������֣�";

	char x[100];

	cin >> x;      //��������

	switch (x[0])
	{
	case '1':
		zhi_gong_in(&zhi_gong_head, &zhi_gong_p);
		goto qi_dian;

	case '2':
		zhi_gong_xiu_gai(&zhi_gong_head);
		goto qi_dian;

	case '3':
		zhi_gong_del(&zhi_gong_head);
		goto qi_dian;

	case '4':
		zhi_gong_put(&zhi_gong_head);
		cout << "\n\t(���������)"; system("pause");
		goto qi_dian;

	case '5':
		zhi_gong_cha_xun(&zhi_gong_head);
		goto qi_dian;

	case '6':
		zhi_gong_dong_tai_hui_shou(&zhi_gong_head);
		return true;

	case '7':
		zhi_gong_dong_tai_hui_shou(&zhi_gong_head);
		return false;

	default:
		cout << "\n\t\t�Ƿ�����,������Ŀ¼!\n";
		cout << "\n\t(���������)"; system("pause");
		goto qi_dian;
	}
}

//-----------------------------------------------------------------------------------------------------------

void zhi_gong_f_in(zhi_gong *head, zhi_gong *p)
{
	ifstream in("zhi_gong_shu_ju.txt", ios::_Nocreate);

	if (!in.is_open())
		return;

	while (!in.eof())
	{
		zhi_gong *a = new zhi_gong;

		in >> a->gong_hao >> a->name >> a->sex >> a->age >> a->chu_sheng_day >> a->ru_zhi_day >> a->bu_men_bian_hao >> a->gang_wei_bian_hao\
			>> a->gang_wei_deng_ji_bian_hao >> a->jia_ting_zhu_zhi >> a->dian_hua >> a->dian_zi_you_jian;

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

void zhi_gong_in(zhi_gong *head, zhi_gong *p)
{
	bu_men bu_men_head;
	bu_men_head.next = NULL;

	bu_men bu_men_p;
	bu_men_p.next = NULL;

	bu_men_f_in(&bu_men_head, &bu_men_p);

	if (bu_men_head.next == NULL)
	{
		cout << "\n\t\t�޲�������,�޷�����ְ����Ϣ!" << endl;
		cout << "\n\t(���������)"; system("pause");
		return;
	}

	gang_wei gang_wei_head;
	gang_wei_head.next = NULL;

	gang_wei gang_wei_p;
	gang_wei_p.next = NULL;

	gang_wei_f_in(&gang_wei_head, &gang_wei_p);

	if (gang_wei_head.next == NULL)
	{
		cout << "\n\t\t�޸�λ����,�޷�����ְ����Ϣ!" << endl;
		cout << "\n\t(���������)"; system("pause");
		return;
	}

	gang_wei_deng_ji gang_wei_deng_ji_head;
	gang_wei_deng_ji_head.next = NULL;

	gang_wei_deng_ji gang_wei_deng_ji_p;
	gang_wei_deng_ji_p.next = NULL;

	gang_wei_deng_ji_f_in(&gang_wei_deng_ji_head, &gang_wei_deng_ji_p);

	if (gang_wei_deng_ji_head.next == NULL)
	{
		cout << "\n\t\t�޸�λ�ȼ�����,�޷�����ְ����Ϣ!" << endl;
		cout << "\n\t(���������)"; system("pause");
		return;
	}

	zhi_gong *a = new zhi_gong;

	if (head->next == NULL)
		a->gong_hao = 1;
	else
		a->gong_hao = p->next->gong_hao + 1;

	zhi_gong *b = head->next;

	while (b != NULL)
	{
		if (a->gong_hao == b->gong_hao)
		{
			a->gong_hao++;

			b = head->next;
		}
		else
			b = b->next;
	}

	cout << "\n\t\t������ְ������:"; cin >> a->name;

	cout << "\n\t\t������ְ���Ա�:"; cin >> a->sex;
	while ((strcmp(a->sex, "��") != 0) && (strcmp(a->sex, "Ů") != 0))
	{
		cout << "\n\t\t�������!����������(�л���Ů):";

		cin >> a->sex;
	}

	cout << "\n\t\t������ְ����������(��ʽΪ2000-01-22):"; cin >> a->chu_sheng_day;
	while (a->chu_sheng_day[4] != '-' || a->chu_sheng_day[7] != '-')
	{
		cout << "\n\t\t��ʽ����,����������:";

		cin >> a->chu_sheng_day;
	}
	char x[5] = { 0 };
	int i = 0;
	for (; i < 4; i++)
		x[i] = a->chu_sheng_day[i];
	x[i] = '\0';

	cout << "\n\t\t������ְ����ְ����(��ʽΪ2000-01-22):"; cin >> a->ru_zhi_day;
	while (a->ru_zhi_day[4] != '-' || a->ru_zhi_day[7] != '-')
	{
		cout << "\n\t\t��ʽ����,����������:";

		cin >> a->ru_zhi_day;
	}
	char y[5] = { 0 };
	int q = 0;
	for (; q < 4; q++)
		y[q] = a->ru_zhi_day[q];
	y[q] = '\0';

	a->age = atoi(y) - atoi(x);
	//-----------------------------------------------------------------------------------------------------------
re_in_bu_men:

	cout << "\n\t\t������ְ���������ű��:"; cin >> a->bu_men_bian_hao;

	bu_men *b2 = bu_men_head.next;

	while (1)
	{
		if (b2 == NULL)
		{
			cout << "\n\t\tϵͳ�в�δ¼��˲���,��ȷ������Ĳ��ű���Ƿ�����!����������!" << endl;

			goto re_in_bu_men;
		}

		if (b2->bu_men_bian_hao == a->bu_men_bian_hao)
			break;

		b2 = b2->next;
	}

	bu_men_dong_tai_hui_shou(&bu_men_head);
	//-----------------------------------------------------------------------------------------------------------
re_in_gang_wei:

	cout << "\n\t\t������ְ�����ڸ�λ���:"; cin >> a->gang_wei_bian_hao;

	gang_wei *b3 = gang_wei_head.next;

	while (1)
	{
		if (b3 == NULL)
		{
			cout << "\n\t\tϵͳ�в�δ¼��˸�λ,��ȷ������ĸ�λ����Ƿ�����!����������!" << endl;

			goto re_in_gang_wei;
		}

		if (b3->gang_wei_bian_hao == a->gang_wei_bian_hao)
			break;

		b3 = b3->next;
	}

	gang_wei_dong_tai_hui_shou(&gang_wei_head);
	//-----------------------------------------------------------------------------------------------------------
re_in_gang_wei_deng_ji:

	cout << "\n\t\t������ְ�����ڸ�λ�ȼ����:"; cin >> a->gang_wei_deng_ji_bian_hao;

	gang_wei_deng_ji *b4 = gang_wei_deng_ji_head.next;

	while (1)
	{
		if (b4 == NULL)
		{
			cout << "\n\t\tϵͳ�в�δ¼��˸�λ�ȼ�,��ȷ������ĸ�λ�ȼ�����Ƿ�����!����������!" << endl;

			goto re_in_gang_wei_deng_ji;
		}

		if (b4->gang_wei_deng_ji_bian_hao == a->gang_wei_deng_ji_bian_hao)
			break;

		b4 = b4->next;
	}

	gang_wei_deng_ji_dong_tai_hui_shou(&gang_wei_deng_ji_head);
	//-----------------------------------------------------------------------------------------------------------
	cout << "\n\t\t������ְ����ͥסַ:"; cin >> a->jia_ting_zhu_zhi;
	cout << "\n\t\t������ְ���绰����:"; cin >> a->dian_hua;
	cout << "\n\t\t������ְ�������ʼ�:"; cin >> a->dian_zi_you_jian;


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

	zhi_gong_f_out(head);   // ���浽�ļ� zhi_gong_shu_ju.txt

	cout << "\n\t\t�������!" << endl << "\n\t(���������)"; system("pause");
}

void zhi_gong_put(zhi_gong *head)
{
	if (head->next == NULL)
	{
		cout << "\n\t\tû��ְ����Ϣ!" << endl;

		return;
	}

	zhi_gong *b = head->next;

	cout << "\n     ְ������     " << "ְ������     " << "�Ա�     " << "����     " << "��������     " \
		<< "������λ����     " << "�������ű��     " << "������λ���     " << "��λ�ȼ����     "\
		<< "��ͥסַ     " << "��ϵ�绰     " << "�����ʼ�     " << endl;
	cout << "   |------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|" << endl;

	while (b != NULL)
	{
		cout << setw(9) << b->gong_hao << setw(16) << b->name << setw(9) << b->sex << setw(9) \
			<< b->age << setw(15) << b->chu_sheng_day << setw(15) << b->ru_zhi_day << setw(12) \
			<< b->bu_men_bian_hao << setw(17) << b->gang_wei_bian_hao\
			<< setw(17) << b->gang_wei_deng_ji_bian_hao << setw(22) << b->jia_ting_zhu_zhi << setw(12)\
			<< b->dian_hua << setw(22) << b->dian_zi_you_jian << endl;
		cout << "   |------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|" << endl;

		b = b->next;
	}
}

void zhi_gong_del(zhi_gong *head)
{
	if (head->next == NULL)
	{
		cout << "\n\t\tû�пɹ�ɾ����ְ����Ϣ!" << endl;

		cout << "\n\t(���������)";

		system("pause");

		return;
	}

	zhi_gong_put(head);

	cout << "\n\t������Ҫɾ����ְ���Ĺ���:";

	int n;
	cin >> n;

	zhi_gong *last = NULL;
	zhi_gong *b = head->next;

	int y = 1;

	while (b != NULL)
	{
		if (b->gong_hao == n)
		{
			y = 0;
			if (b->gong_hao == head->next->gong_hao)
			{
				head->next = b->next;
				delete b;
				zhi_gong_f_out(head);
				cout << "\n\t\tɾ���ɹ�!" << endl;
				break;
			}
			else if (b->next == NULL)
			{
				last->next = NULL;
				delete b;
				zhi_gong_f_out(head);
				cout << "\n\t\tɾ���ɹ�!" << endl;
				break;
			}
			else
			{
				last->next = b->next;
				delete b;
				zhi_gong_f_out(head);
				cout << "\n\t\tɾ���ɹ�!" << endl;
				break;
			}
		}
		last = b;
		b = b->next;
	}
	if (y == 1)
		cout << "\n\t\tְ��ϵͳ�в�δ¼���ְ��,��ȷ�������ְ�������Ƿ�����!" << endl;

	cout << "\n\t(���������)"; system("pause");
}

void zhi_gong_f_out(zhi_gong *head)
{
	ofstream outf("zhi_gong_shu_ju.txt");

	zhi_gong *b = head->next;

	while (b != NULL)
	{
		outf << b->gong_hao << " " << b->name << " " << b->sex << " " << b->age << " " << b->chu_sheng_day << " "\
			<< b->ru_zhi_day << " " << b->bu_men_bian_hao << " " << b->gang_wei_bian_hao\
			<< " " << b->gang_wei_deng_ji_bian_hao << " " << b->jia_ting_zhu_zhi << " "\
			<< b->dian_hua << " " << b->dian_zi_you_jian << endl;

		b = b->next;
	}
	outf.close();
}

void zhi_gong_xiu_gai(zhi_gong *head)
{
	if (head->next == NULL)
	{
		cout << "\n\t\tû�пɹ��޸ĵ�ְ����Ϣ!" << endl;

		cout << "\n\t(���������)";

		system("pause");

		return;
	}

	zhi_gong_put(head);

	cout << "\n\t\t������Ҫ�޸ĵ�ְ���ı��:";

	int n;
	cin >> n;

	zhi_gong *b = head->next;

	int y = 1;

	while (b != NULL)
	{
		if (b->gong_hao == n)
		{
			y = 0;
			system("cls");
			cout << "\n";
			cout << "\n\t\t********************�޸�ְ��������Ϣ********************\n";
			cout << "\t\t*                                                      *\n";
			cout << "\t\t*                                                      *\n";
			cout << "\t\t*    1.ְ������     2.ְ���Ա�     3.ְ����������      *\n";
			cout << "\t\t*                                                      *\n";
			cout << "\t\t*                                                      *\n";
			cout << "\t\t*    4.ְ���ϸ����� 5.��������     6.������λ          *\n";
			cout << "\t\t*                                                      *\n";
			cout << "\t\t*                                                      *\n";
			cout << "\t\t*    7.������λ�ȼ� 8.��ͥסַ     9.��ϵ�绰          *\n";
			cout << "\t\t*                                                      *\n";
			cout << "\t\t*                                                      *\n";
			cout << "\t\t*    0.�����ʼ�     a.ְ������     r.����              *\n";
			cout << "\t\t*                                                      *\n";
			cout << "\t\t*                                                      *\n";
			cout << "\t\t********************************************************\n";

		re_in:

			cout << "\n\t��ѡ����Ҫ�޸ĵ�ְ����Ϣ:";

			char c[100];
			cin >> c;

			switch (c[0])
			{

			case'1':
			{
				cout << "\n\t\t����ְ�������޸�Ϊ:";
				cin >> b->name;
				zhi_gong_f_out(head);
				cout << "\n\t\t�޸ĳɹ�!";
				break;
			}

			case'2':
			{
				cout << "\n\t\t����ְ���Ա��޸�Ϊ:";
				cin >> b->sex;
				zhi_gong_f_out(head);
				cout << "\n\t\t�޸ĳɹ�!";
				break;
			}

			case'3':
			{
				cout << "\n\t\t����ְ�����������޸�Ϊ:";
				cin >> b->chu_sheng_day;
				while (b->chu_sheng_day[4] != '-' && b->chu_sheng_day[7] != '-')
				{
					cout << "\n\t\t��ʽ����,����������:";

					cin >> b->chu_sheng_day;
				}
				zhi_gong_f_out(head);
				cout << "\n\t\t�޸ĳɹ�!";
				break;
			}

			case'4':
			{
				cout << "\n\t\t����ְ���ϸ������޸�Ϊ:";
				cin >> b->ru_zhi_day;
				while (b->ru_zhi_day[4] != '-' && b->ru_zhi_day[7] != '-')
				{
					cout << "\n\t\t��ʽ����,����������:";

					cin >> b->ru_zhi_day;
				}
				zhi_gong_f_out(head);
				cout << "\n\t\t�޸ĳɹ�!";
				break;
			}

			case'5':
			{
			re_in_bu_men:

				cout << "\n\t\t����ְ�����������޸�Ϊ:";

				cin >> b->bu_men_bian_hao;

				bu_men bu_men_head;
				bu_men_head.next = NULL;

				bu_men bu_men_p;
				bu_men_p.next = NULL;

				bu_men_f_in(&bu_men_head, &bu_men_p);

				bu_men *b2 = bu_men_head.next;

				while (1)
				{
					if (b2 == NULL)
					{
						cout << "\n\t\tϵͳ�в�δ¼��˲���,��ȷ������Ĳ��ű���Ƿ�����!����������!" << endl;

						goto re_in_bu_men;
					}

					if (b2->bu_men_bian_hao == b->bu_men_bian_hao)
						break;

					b2 = b2->next;
				}

				bu_men_dong_tai_hui_shou(&bu_men_head);
				zhi_gong_f_out(head);
				cout << "\n\t\t�޸ĳɹ�!";
				break;
			}

			case'6':
			{
			re_in_gang_wei:

				cout << "\n\t\t����ְ��������λ�޸�Ϊ:";

				cin >> b->gang_wei_bian_hao;

				gang_wei gang_wei_head;
				gang_wei_head.next = NULL;

				gang_wei gang_wei_p;
				gang_wei_p.next = NULL;

				gang_wei_f_in(&gang_wei_head, &gang_wei_p);

				gang_wei *b3 = gang_wei_head.next;

				while (1)
				{
					if (b3 == NULL)
					{
						cout << "\n\t\tϵͳ�в�δ¼��˸�λ,��ȷ������ĸ�λ����Ƿ�����!����������!" << endl;

						goto re_in_gang_wei;
					}

					if (b3->gang_wei_bian_hao == b->gang_wei_bian_hao)
						break;

					b3 = b3->next;
				}

				gang_wei_dong_tai_hui_shou(&gang_wei_head);
				zhi_gong_f_out(head);
				cout << "\n\t\t�޸ĳɹ�!";
				break;
			}

			case'7':
			{
			re_in_gang_wei_deng_ji:

				cout << "\n\t\t����ְ��������λ�ȼ��޸�Ϊ:";

				cin >> b->gang_wei_deng_ji_bian_hao;

				gang_wei_deng_ji gang_wei_deng_ji_head;
				gang_wei_deng_ji_head.next = NULL;

				gang_wei_deng_ji gang_wei_deng_ji_p;
				gang_wei_deng_ji_p.next = NULL;

				gang_wei_deng_ji_f_in(&gang_wei_deng_ji_head, &gang_wei_deng_ji_p);

				gang_wei_deng_ji *b4 = gang_wei_deng_ji_head.next;

				while (1)
				{
					if (b4 == NULL)
					{
						cout << "\n\t\tϵͳ�в�δ¼��˸�λ�ȼ�,��ȷ������ĸ�λ�ȼ�����Ƿ�����!����������!" << endl;

						goto re_in_gang_wei_deng_ji;
					}

					if (b4->gang_wei_deng_ji_bian_hao == b->gang_wei_deng_ji_bian_hao)
						break;

					b4 = b4->next;
				}

				gang_wei_deng_ji_dong_tai_hui_shou(&gang_wei_deng_ji_head);
				zhi_gong_f_out(head);
				cout << "\n\t\t�޸ĳɹ�!";
				break;
			}

			case'8':
			{
				cout << "\n\t\t����ְ����ͥסַ�޸�Ϊ:";
				cin >> b->jia_ting_zhu_zhi;
				zhi_gong_f_out(head);
				cout << "\n\t\t�޸ĳɹ�!";
				break;
			}

			case'9':
			{
				cout << "\n\t\t����ְ����ϵ�绰�޸�Ϊ:";
				cin >> b->dian_hua;
				zhi_gong_f_out(head);
				cout << "\n\t\t�޸ĳɹ�!";
				break;
			}

			case'0':
			{
				cout << "\n\t\t����ְ�������ʼ��޸�Ϊ:";
				cin >> b->dian_zi_you_jian;
				zhi_gong_f_out(head);
				cout << "\n\t\t�޸ĳɹ�!";
				break;
			}

			case'a':
			{
				cout << "\n\t\t����ְ�������޸�Ϊ:";
				cin >> b->age;
				zhi_gong_f_out(head);
				cout << "\n\t\t�޸ĳɹ�!";
				break;
			}

			case'r':
			{
				return;
			}

			default:
			{
				cout << "\n\t\t��ȷ������Ĺ��ܺ����Ƿ�����!����������!" << endl;
				goto re_in;
			}

			}
		}
		b = b->next;
	}
	if (y == 1)
		cout << "\n\t\tְ��������Ϣϵͳ�в�δ¼���ְ��,��ȷ�������ְ�������Ƿ�����!" << endl;

	cout << "\n\n\t(���������)"; system("pause");
}

void zhi_gong_dong_tai_hui_shou(zhi_gong *head)
{
	if (head->next == NULL)
		return;

	zhi_gong *a = head->next;
	zhi_gong *temp = NULL;

	while (a != NULL)
	{
		temp = a;

		a = a->next;

		delete temp;
	}
}

void zhi_gong_cha_xun(zhi_gong *head)
{
cai_dan:

	system("cls");
	cout << "\n";
	cout << "\n\t\t********************��ѯְ��������Ϣ********************\n";
	cout << "\t\t*                                                      *\n";
	cout << "\t\t*                                                      *\n";
	cout << "\t\t*    1.���Ա�           2.�����ű��    3.����λ���   *\n";
	cout << "\t\t*                                                      *\n";
	cout << "\t\t*                                                      *\n";
	cout << "\t\t*    4.����λ�ȼ����   5.������        6.������       *\n";
	cout << "\t\t*                                                      *\n";
	cout << "\t\t*                                                      *\n";
	cout << "\t\t*    7.������           8.����                         *\n";
	cout << "\t\t*                                                      *\n";
	cout << "\t\t*                                                      *\n";
	cout << "\t\t********************************************************\n";

re_in:

	cout << "\n\t��ѡ���ѯ����:";

	char c[100];
	cin >> c;

	switch (c[0])
	{

	case'1':
	{
		int y = 0;

		cout << "\n\t\t�������Ա�(��\\Ů):";

		char sex[10]; cin >> sex;
		while ((strcmp(sex, "��") != 0) && (strcmp(sex, "Ů") != 0))
		{
			cout << "\n\t\t�������!�����������Ա�(��\\Ů):";

			cin >> sex;
		}

		zhi_gong *b = head->next;

		while (b != NULL)
		{
			if (strcmp(b->sex, sex) == 0)
			{
				y++;

				if (y == 1)
				{
					cout << "\n     ְ������     " << "ְ������     " << "�Ա�     " << "����     " << "��������     " \
						<< "������λ����     " << "�������ű��     " << "������λ���     " << "��λ�ȼ����     "\
						<< "��ͥסַ     " << "��ϵ�绰     " << "�����ʼ�     " << endl;
					cout << "   |------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|" << endl;
				}
				cout << setw(9) << b->gong_hao << setw(16) << b->name << setw(9) << b->sex << setw(9) << b->age \
					<< setw(15) << b->chu_sheng_day << setw(15) << b->ru_zhi_day << setw(12) << b->bu_men_bian_hao\
					<< setw(17) << b->gang_wei_bian_hao\
					<< setw(17) << b->gang_wei_deng_ji_bian_hao << setw(22) << b->jia_ting_zhu_zhi << setw(12)\
					<< b->dian_hua << setw(22) << b->dian_zi_you_jian << endl;
				cout << "   |------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|" << endl;
			}
			b = b->next;
		}
		if (y == 0)
			cout << "\n\t\tû�и��Ա�ְ����Ϣ!";
		else
			cout << "\n\t\t����" << y << "λ���Ա�ְ��!";

		cout << "\n\n\t(���������)"; system("pause");

		goto cai_dan;
	}

	case'2':
	{
		int y = 0;

		cout << "\n\t\t�����벿�ű��:";

		int x; cin >> x;

		zhi_gong *b = head->next;

		while (b != NULL)
		{
			if (b->bu_men_bian_hao == x)
			{
				y++;

				if (y == 1)
				{
					cout << "\n     ְ������     " << "ְ������     " << "�Ա�     " << "����     " << "��������     " \
						<< "������λ����     " << "�������ű��     " << "������λ���     " << "��λ�ȼ����     "\
						<< "��ͥסַ     " << "��ϵ�绰     " << "�����ʼ�     " << endl;
					cout << "   |------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|" << endl;
				}
				cout << setw(9) << b->gong_hao << setw(16) << b->name << setw(9) << b->sex << setw(9) << b->age << setw(15)\
					<< b->chu_sheng_day << setw(15) << b->ru_zhi_day << setw(12) << b->bu_men_bian_hao\
					<< setw(17) << b->gang_wei_bian_hao\
					<< setw(17) << b->gang_wei_deng_ji_bian_hao << setw(22) << b->jia_ting_zhu_zhi \
					<< setw(12) << b->dian_hua << setw(22) << b->dian_zi_you_jian << endl;
				cout << "   |------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|" << endl;
			}
			b = b->next;
		}
		if (y == 0)
			cout << "\n\t\tû�����ڸò��ŵ�ְ��!";
		else
			cout << "\n\t\t����" << y << "λ���ڸò��ŵ�ְ��!";

		cout << "\n\n\t(���������)"; system("pause");

		goto cai_dan;
	}

	case'3':
	{
		int y = 0;

		cout << "\n\t\t�������λ���:";

		int x; cin >> x;

		zhi_gong *b = head->next;

		while (b != NULL)
		{
			if (b->gang_wei_bian_hao == x)
			{
				y++;

				if (y == 1)
				{
					cout << "\n     ְ������     " << "ְ������     " << "�Ա�     " << "����     " << "��������     " \
						<< "������λ����     " << "�������ű��     " << "������λ���     " << "��λ�ȼ����     "\
						<< "��ͥסַ     " << "��ϵ�绰     " << "�����ʼ�     " << endl;
					cout << "   |------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|" << endl;
				}
				cout << setw(9) << b->gong_hao << setw(16) << b->name << setw(9) << b->sex << setw(9) << b->age << setw(15) << b->chu_sheng_day << setw(15) << b->ru_zhi_day << setw(12) << b->bu_men_bian_hao << setw(17) << b->gang_wei_bian_hao\
					<< setw(17) << b->gang_wei_deng_ji_bian_hao << setw(22) << b->jia_ting_zhu_zhi << setw(12) << b->dian_hua << setw(22) << b->dian_zi_you_jian << endl;
				cout << "   |------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|" << endl;
			}
			b = b->next;
		}
		if (y == 0)
			cout << "\n\t\tû�����ڸø�λ��ְ��!";
		else
			cout << "\n\t\t����" << y << "λ���ڸø�λ��ְ��!";

		cout << "\n\n\t(���������)"; system("pause");

		goto cai_dan;
	}

	case'4':
	{
		int y = 0;

		cout << "\n\t\t�������λ�ȼ����:";

		int x; cin >> x;

		zhi_gong *b = head->next;

		while (b != NULL)
		{
			if (b->gang_wei_deng_ji_bian_hao == x)
			{
				y++;

				if (y == 1)
				{
					cout << "\n     ְ������     " << "ְ������     " << "�Ա�     " << "����     " << "��������     " \
						<< "������λ����     " << "�������ű��     " << "������λ���     " << "��λ�ȼ����     "\
						<< "��ͥסַ     " << "��ϵ�绰     " << "�����ʼ�     " << endl;
					cout << "   |------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|" << endl;
				}
				cout << setw(9) << b->gong_hao << setw(16) << b->name << setw(9) << b->sex << setw(9) << b->age << setw(15) << b->chu_sheng_day << setw(15) << b->ru_zhi_day << setw(12) << b->bu_men_bian_hao << setw(17) << b->gang_wei_bian_hao\
					<< setw(17) << b->gang_wei_deng_ji_bian_hao << setw(22) << b->jia_ting_zhu_zhi << setw(12) << b->dian_hua << setw(22) << b->dian_zi_you_jian << endl;
				cout << "   |------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|" << endl;
			}
			b = b->next;
		}
		if (y == 0)
			cout << "\n\t\tû�����ڸø�λ�ȼ���ְ��!";
		else
			cout << "\n\t\t����" << y << "λ���ڸø�λ�ȼ���ְ��!";

		cout << "\n\n\t(���������)"; system("pause");

		goto cai_dan;
	}

	case'5':
	{
		int y = 0;

		cout << "\n\t\t����������:";

		int x; cin >> x;

		zhi_gong *b = head->next;

		while (b != NULL)
		{
			if (b->age == x)
			{
				y++;

				if (y == 1)
				{
					cout << "\n     ְ������     " << "ְ������     " << "�Ա�     " << "����     " << "��������     " \
						<< "������λ����     " << "�������ű��     " << "������λ���     " << "��λ�ȼ����     "\
						<< "��ͥסַ     " << "��ϵ�绰     " << "�����ʼ�     " << endl;
					cout << "   |------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|" << endl;
				}
				cout << setw(9) << b->gong_hao << setw(16) << b->name << setw(9) << b->sex << setw(9) << b->age << setw(15) << b->chu_sheng_day << setw(15) << b->ru_zhi_day << setw(12) << b->bu_men_bian_hao << setw(17) << b->gang_wei_bian_hao\
					<< setw(17) << b->gang_wei_deng_ji_bian_hao << setw(22) << b->jia_ting_zhu_zhi << setw(12) << b->dian_hua << setw(22) << b->dian_zi_you_jian << endl;
				cout << "   |------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|" << endl;
			}
			b = b->next;
		}
		if (y == 0)
			cout << "\n\t\tû�и������ְ��!";
		else
			cout << "\n\t\t����" << y << "λ�������ְ��!";

		cout << "\n\n\t(���������)"; system("pause");

		goto cai_dan;
	}

	case'6':
	{
		cout << "\n\t\t����������:";

		char name[20]; cin >> name;

		zhi_gong *b = head->next;

		while (b != NULL)
		{
			if (strcmp(b->name, name) == 0)
			{
				cout << "\n     ְ������     " << "ְ������     " << "�Ա�     " << "����     " << "��������     " \
					<< "������λ����     " << "�������ű��     " << "������λ���     " << "��λ�ȼ����     "\
					<< "��ͥסַ     " << "��ϵ�绰     " << "�����ʼ�     " << endl;
				cout << "   |------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|" << endl;
				cout << setw(9) << b->gong_hao << setw(16) << b->name << setw(9) << b->sex << setw(9) << b->age << setw(15) << b->chu_sheng_day << setw(15) << b->ru_zhi_day << setw(12) << b->bu_men_bian_hao << setw(17) << b->gang_wei_bian_hao\
					<< setw(17) << b->gang_wei_deng_ji_bian_hao << setw(22) << b->jia_ting_zhu_zhi << setw(12) << b->dian_hua << setw(22) << b->dian_zi_you_jian << endl;
				cout << "   |------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|" << endl;

				cout << "\n\n\t(���������)"; system("pause");

				goto cai_dan;
			}
			b = b->next;
		}
		cout << "\n\t\tû�и�������ְ��!";

		cout << "\n\n\t(���������)"; system("pause");

		goto cai_dan;
	}

	case'7':
	{
		cout << "\n\t\t�����빤��:";

		int x; cin >> x;

		zhi_gong *b = head->next;

		while (b != NULL)
		{
			if (b->gong_hao == x)
			{
				cout << "\n     ְ������     " << "ְ������     " << "�Ա�     " << "����     " << "��������     " \
					<< "������λ����     " << "�������ű��     " << "������λ���     " << "��λ�ȼ����     "\
					<< "��ͥסַ     " << "��ϵ�绰     " << "�����ʼ�     " << endl;
				cout << "   |------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|" << endl;
				cout << setw(9) << b->gong_hao << setw(16) << b->name << setw(9) << b->sex << setw(9) << b->age << setw(15) << b->chu_sheng_day << setw(15) << b->ru_zhi_day << setw(12) << b->bu_men_bian_hao << setw(17) << b->gang_wei_bian_hao\
					<< setw(17) << b->gang_wei_deng_ji_bian_hao << setw(22) << b->jia_ting_zhu_zhi << setw(12) << b->dian_hua << setw(22) << b->dian_zi_you_jian << endl;
				cout << "   |------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|";

				cout << "\n\n\t(���������)"; system("pause");

				goto cai_dan;
			}
			b = b->next;
		}
		cout << "\n\t\tû�иù��ŵ�ְ��!";

		cout << "\n\n\t(���������)"; system("pause");

		goto cai_dan;
	}

	case'8':
	{
		return;
	}

	default:
	{
		cout << "\n\t\t��ȷ������Ĺ��ܺ����Ƿ�����!����������!" << endl;

		goto re_in;
	}

	}
}