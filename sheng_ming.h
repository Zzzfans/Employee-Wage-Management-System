#define _CRT_SECURE_NO_WARNINGS

//-----------------------------------------------------------------------------------------------------------

#include<iostream>
#include<fstream>
#include<ctime>
#include<iomanip>

//-----------------------------------------------------------------------------------------------------------

using namespace std;

//-----------------------------------------------------------------------------------------------------------

struct zhi_gong
{
	int gong_hao;                    //���� (ϵͳ�Զ���ֵ  ������)
	char name[20];                   //����
	char sex[10];                    //�Ա���Ů��
	char chu_sheng_day[20];          //��������
	char ru_zhi_day[20];             //��ְ����
	int bu_men_bian_hao;             //���ű��
	int gang_wei_bian_hao;           //��λ���
	int gang_wei_deng_ji_bian_hao;   //��λ�ȼ����
	char jia_ting_zhu_zhi[100];      //��ͥסַ
	char dian_hua[20];               //�绰����
	char dian_zi_you_jian[50];       //�����ʼ�
	int age;                           //����

	zhi_gong *next;
};

struct bu_men
{
	int bu_men_bian_hao;             //���ű�ţ�ϵͳ�Զ���ֵ��
	char bu_men_ming_cheng[20];             //��������
	int bu_men_bian_zhi_shu;            //���ű�����
	char bu_men_jian_jie[1000];            //���ż��

	bu_men *next;
};

struct gang_wei
{
	int gang_wei_bian_hao;  //��λ���
	char gang_wei_ming_cheng[20]; //��λ����
	double basic_gong_zi;  //��λ��������
	char zhi_ze[1000]; //��λְ��

	gang_wei *next;
};

struct gang_wei_deng_ji
{
	int gang_wei_deng_ji_bian_hao; //��λ�ȼ����
	char gang_wei_deng_ji_ming_cheng[20];  //��λ�ȼ�����
	double gong_zi_xi_shu; //��λ�ȼ�����ϵ��

	gang_wei_deng_ji *next;
};

struct gong_zi_xin_xi
{
	int gong_hao;
	char time[64];
	double basic_gong_zi = 0;
	double ji_xiao = 0;
	double jia_ban = 0;
	double jiang_li = 0;
	double yang_lao = 0;
	double zhi_ye_nian_jin = 0;
	double gong_ji_jin = 0;
	double shi_ye_bao_xian = 2;
	double yi_liao_bao_xian = 0;
	double ge_shui = 0;
	double ying_fa = 0;
	double shi_fa = 0;

	gong_zi_xin_xi *next;
};

//-----------------------------------------------------------------------------------------------------------

void guan_li_xi_tong();    //����ϵͳ��һ���˵���

//-----------------------------------------------------------------------------------------------------------

bool zhi_gong_ji_ben_xin_xi_guan_li();   //ְ��������Ϣ���������˵���
bool bu_men_guan_li();     //���Ź��������˵���
bool zhi_gong_gong_zi_guan_li();  //ְ�����ʹ��������˵���
bool gang_wei_ji_gang_wei_deng_ji_guan_li();  //��λ����λ�ȼ����������˵���

//-----------------------------------------------------------------------------------------------------------

void bu_men_f_in(bu_men *head, bu_men *p);
void bu_men_in(bu_men *head, bu_men *p);
void bu_men_put(bu_men *head);
void bu_men_del(bu_men *head);
void bu_men_f_out(bu_men *head);
void bu_men_xiu_gai(bu_men *head);
void bu_men_dong_tai_hui_shou(bu_men *head);

//-----------------------------------------------------------------------------------------------------------

void gang_wei_f_in(gang_wei *head, gang_wei *p);
void gang_wei_in(gang_wei *head, gang_wei *p);
void gang_wei_put(gang_wei *head);
void gang_wei_del(gang_wei *head);
void gang_wei_f_out(gang_wei *head);
void gang_wei_xiu_gai(gang_wei *head);
void gang_wei_dong_tai_hui_shou(gang_wei *head);

//-----------------------------------------------------------------------------------------------------------

void gang_wei_deng_ji_f_in(gang_wei_deng_ji *head, gang_wei_deng_ji *p);
void gang_wei_deng_ji_in(gang_wei_deng_ji *head, gang_wei_deng_ji *p);
void gang_wei_deng_ji_put(gang_wei_deng_ji *head);
void gang_wei_deng_ji_del(gang_wei_deng_ji *head);
void gang_wei_deng_ji_f_out(gang_wei_deng_ji *head);
void gang_wei_deng_ji_xiu_gai(gang_wei_deng_ji *head);
void gang_wei_deng_ji_dong_tai_hui_shou(gang_wei_deng_ji *head);

//-----------------------------------------------------------------------------------------------------------

void yue_fen_gong_zi_ji_chu_shu_ju_sheng_cheng(gong_zi_xin_xi *head, gong_zi_xin_xi *p);
void gong_zi_xin_xi_f_out(gong_zi_xin_xi *head);
void gong_zi_xin_xi_f_in(gong_zi_xin_xi *head, gong_zi_xin_xi *p);
void gong_zi_dan(gong_zi_xin_xi *head);
void gong_zi_shu_ru(gong_zi_xin_xi *head);
void gong_zi_cha_xun(gong_zi_xin_xi *head);
void gong_zi_tong_ji(gong_zi_xin_xi *head);
void gong_zi_dong_tai_hui_shou(gong_zi_xin_xi *head);

//-----------------------------------------------------------------------------------------------------------

void zhi_gong_f_in(zhi_gong *head, zhi_gong *p);
void zhi_gong_in(zhi_gong *head, zhi_gong *p);
void zhi_gong_put(zhi_gong *head);
void zhi_gong_del(zhi_gong *head);
void zhi_gong_f_out(zhi_gong *head);
void zhi_gong_xiu_gai(zhi_gong *head);
void zhi_gong_dong_tai_hui_shou(zhi_gong *head);
void zhi_gong_cha_xun(zhi_gong *head);