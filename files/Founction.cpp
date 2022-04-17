#include <iostream>
#include <fstream>

using namespace std;

double pow(double x, int p) 
{//степень
	double up = 1;
	for (int m = p; m > 0; m--) {
		up = up * x;
	}
	return up;
}
int factorial(int i)
{
	if (i == 1) {
		return i;
	}
	return i * factorial(i - 1);// 4* 3 * 2 * 1
}
double g(double x, int i)
{
	if (i == 1)
	{
		return 1;
	}
	double a = -1 * ((i + 3) * pow(x, i));
	return (g(x, i - 1) * a) / 2 * factorial(i);
	
}
void infile(double x, int i)
{
	ofstream file("file.txt");
	int sum = 0;
	for (int y = 1; y <= i; y++) {
		sum += g(x, y);
		file << g(x, y) <<"	";
		if ((y % 2) == 0) {
			file << endl;
		}
	}
	file << "\n Summ = " << sum;
}
void outfile() {
	const int MAX = 80; // размер буфера
	char buffer[MAX]; // буфер символов
	ifstream file("file.txt"); // создать входной файл
	while (!file.eof()) // цикл до End Of File
	{
		file.getline(buffer, MAX); // читает строку текста
		cout << buffer << endl; // и выводит ее
	}
}
/*
double sum(double x, double epsilon)
{
	double first, second;
	double sum = 1;
	int i = 2;
	while ((g(x, i - 1) - g(x, i)) > epsilon) {
		first = g(x, i - 1);
		second = g(x, i);
		sum = second + sum;
		out(first, second, i);
		i++;

	}
	return sum;
}
*/