#include <iostream>
#include<cmath>
#include<string>
using namespace std;

// variables
int flag, months, days, year;
string gov[1];
long long int ID;
long long int national[14];
int GovernmentCode[28] = {01,02,03,04,11,12,13,14,15,16,17,18,19,21,22,23,24,25,26,27,28,29,31,32,33,34,35,88};
string GovernmentName[28] = { "Cairo","Alexandria","Portsaid","suiz","Damait","Dikahlia","Sharkia","qalubia","Kafr el-shikh","Gharbia","Monofia",
"Behira","Ismailia","Giza","Beni-Swif", "Al-Fayoum","Al-Minia" , "Assiut", "Sohag" , "Qina","Aswan","Luxor","RedSea", "El-Wadi El-gadid","Matrouh",
"North Sinai", "South Sinai", "Abroad" };

// checking that the number of digits is 14
int NumberOfDigits(long long int ID) {
	int flag, x, y;

	x = ID / (pow(10, 14));
	y = ID / (pow(10, 13));

	if ((x == 0) && (y > 0)) {
		flag = 1;

	}
	else {
		flag = 0;
	}


	return flag;
}


// checking the century and year
int century () {
	int cen = (national[1] * 10) + national[2];
	switch (national[0]) {

	case 2:
	{
		if (cen >= 0 && cen <= 99) {
			year = 1900 + cen;
			flag = 1;
		}
		else
			flag = 0;
	}

	break;

	case 3:
	{
		if (cen >= 0 && cen <= 21) {
			year = 2000 + cen;
			flag = 1;
		}
		else
			flag = 0;
	}

	break;

	default:
		flag = 0;
	}
	return flag;
}

// checking the months and days
int Months_Days()
{
	months = national[3] * 10 + national[4];
	days = national[5] * 10 + national[6];


	if (months > 0 && months <= 12)
	{
		if (months == 1 || months == 3 || months == 5 || months == 7 || months == 8 || months == 10 || months == 12)
		{
			flag = (days <= 31) ? 1 : 0;

		}
		else if (months == 4 || months == 6 || months == 9 || months == 11)
		{
			flag = (days <= 30) ? 1 : 0;
		}
		else if (months == 2)
		{
			flag = (days <= 29 ) ? 1 : 0;
		}
	}
	else { flag = 0; }

	return flag;
}


// checking the government

int government() {
	int x;
	x = (national[7] * 10) + national[8];

	for (int i = 0; i <= 27; ++i) {
		if (x == GovernmentCode[i]) {
			gov[0] = GovernmentName[i];
			flag = 1;
			break;
		}
		else {
			flag = 0;
		}
	}

	return flag;
}

// checking the gender
void gender() {
	int gen = national[12];
	if (gen % 2 == 0)
		cout << "Gender : Female" << endl;
	else
		cout << "Gender : Male" << endl;
}

	/////////////////////////////////////

int main(){

	int check=1 ,x;
loop:

	cout << "Enter your ID : "<<endl;
	ID=0;
	cin >> ID;


	check = NumberOfDigits(ID);

	for (int i = 0; i <= 13; i++)
	{
		national[i] = (ID / (pow(10, (13 - i))));

		ID = ID - (national[i] * (pow(10,(13- i))));

	}

	if (check == 1) {
		if (century() * government() *  Months_Days() == 1) {
			century();
			Months_Days();
			government();

			cout << "Date of Birth : " << year << "/" << months << "/" << days << endl;
			cout << "BirthPalce : " << gov[0] << endl;
			gender();
		}
		else {
			cout << "Please enter a Vaild ID number" << endl;
			goto loop;

		}
	}
	else {
		cout << "Please enter a Vaild ID number....." << endl;

		goto loop;
	}



	system("pause");
	return 0;
}
