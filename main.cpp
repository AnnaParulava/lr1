/*
���������� �����: 3. �������: �������� ������������ ��������, �����������������, ��� �����
� ������������, ����������� �����. ���������� �����  ������ ����������� ��������.
*/

#include <iostream>
#include <fstream>
#include <iomanip>
#include <stdlib.h>

using namespace std;

struct TechnicalMeans
{
    char title[15];
    char author[20]; // ��������� ���� - ������ � ���� ������� ��������
    int year; // ���, ���� ������ ����
    int inventory_number;
};

//������ �� ���������� �����:
void input_from_file(char* filetitle, TechnicalMeans* tm, int n)
{
    ifstream fin(filetitle); //�������� �������� ������
    if(fin) //�������� �������� �����
    {
       for (int i=0; i<n; i++)
       {
           fin>>tm[i].title; //������ �� ����� � ����������
           fin>>tm[i].author;
           fin>>tm[i].inventory_number;
           fin>>tm[i].year;
       }
       fin.close(); //�������� ������

    }
    else
    cout <<"���� �� ������!"<<endl;
}

//������ ���������
void output_struct(TechnicalMeans* tm, int n)
{
    int min = tm[0].year; //��� ������ ������ ������� ���. ��������
    int number = 0;

    std::string userfile; //���� ��� ������
    std::cout<<"������� �������� ����� (�������� userfile): "<<endl;
    std::cin>>userfile;

    //�������� ������� ������ ��� ������ � ����
    std::ofstream fout; // �������� ��������� ������
    fout.open(userfile); // �������� ��������� ������

    //������ ������ ������� ������������ ��������
    for (int i=0; i<n; i++)
    {
        if(tm[i].year < min)
        {
            min = tm[i].year;
            number=i;
        }
    }

    //������ � ����
    fout<<tm[number].title<<endl;
    fout<<tm[number].author<<endl;
    fout<<tm[number].inventory_number<<endl;
    fout<<tm[number].year<<endl;

    fout.close(); //�������� ������

    //����� �� �������
    cout<<"\n����� ������ ����������� ��������: "<<endl;
    cout<<tm[number].title<<endl;
    cout<<tm[number].author<<endl;
    cout<<tm[number].inventory_number<<endl;
    cout<<tm[number].year<<endl;

};


int main()
{
    setlocale(LC_ALL, "rus");

    const int N =3; //���������� ���� � �����

    TechnicalMeans *tm = new TechnicalMeans[N]; //�������� ����������� ����������
    input_from_file("test.txt", tm, N);
    output_struct(tm, N);

    delete []tm; //������������ ������ ����� ��������� ����������.

    return 0;
}





