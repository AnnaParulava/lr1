/*
Количество строк: 3. Столбцы: Название технического средства, Фирма­изготовитель, Год ввода
в эксплуатацию, Инвентарный номер. Определить самое  старое техническое средство.
*/

#include <iostream>
#include <fstream>
#include <iomanip>
#include <stdlib.h>

using namespace std;

struct TechnicalMeans
{
    char title[15];
    char author[20]; // текстовое поле - строка в виде массива символов
    int year; // год, поле целого типа
    int inventory_number;
};

//чтения из текстового файла:
void input_from_file(char* filetitle, TechnicalMeans* tm, int n)
{
    ifstream fin(filetitle); //Создание входного потока
    if(fin) //проверка открытия файла
    {
       for (int i=0; i<n; i++)
       {
           fin>>tm[i].title; //Чтение из файла в переменную
           fin>>tm[i].author;
           fin>>tm[i].inventory_number;
           fin>>tm[i].year;
       }
       fin.close(); //закрытие потока

    }
    else
    cout <<"Файл не найден!"<<endl;
}

//чтение структуры
void output_struct(TechnicalMeans* tm, int n)
{
    int min = tm[0].year; //для поиска самого старого тех. средства
    int number = 0;

    std::string userfile; //файл для записи
    std::cout<<"Введите название файла (например userfile): "<<endl;
    std::cin>>userfile;

    //Создание объекта потока для записи в файл
    std::ofstream fout; // Создание выходного потока
    fout.open(userfile); // Открытие выходного потока

    //поискк самого старого технического средства
    for (int i=0; i<n; i++)
    {
        if(tm[i].year < min)
        {
            min = tm[i].year;
            number=i;
        }
    }

    //запись в файл
    fout<<tm[number].title<<endl;
    fout<<tm[number].author<<endl;
    fout<<tm[number].inventory_number<<endl;
    fout<<tm[number].year<<endl;

    fout.close(); //закрытие потока

    //вывод на консоль
    cout<<"\nСамое старое техническое средство: "<<endl;
    cout<<tm[number].title<<endl;
    cout<<tm[number].author<<endl;
    cout<<tm[number].inventory_number<<endl;
    cout<<tm[number].year<<endl;

};


int main()
{
    setlocale(LC_ALL, "rus");

    const int N =3; //количество сток в файле

    TechnicalMeans *tm = new TechnicalMeans[N]; //создание структурной переменной
    input_from_file("test.txt", tm, N);
    output_struct(tm, N);

    delete []tm; //освобождение памяти из­под одиночной переменной.

    return 0;
}





