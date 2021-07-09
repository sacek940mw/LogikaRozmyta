

#include <iostream>
#include <string>
#include <exception>

using namespace std;

int main()
{
	bool correctSpeed = false;
	bool correctAngle = false;
	string string;
	double speed = 0;;
	double angle = 0;;

	double rules[15];

	double rSpeed = 0; //pomocnicze
	double rAngle = 0;

	double powerLow = 0;
	double powerMedium = 0;
	double powerHigh = 0;

	double wynikDefuzyfikacjiMax = 0;
	double wynikDefuzyfikacjiSrC = 0;

	while (correctSpeed == false) {
		correctSpeed = true;
		
		cout << "Podaj wartosc atrybutu \"speed\" (np 3.4): ";
		cin >> string;

		try {
			speed = std::stod(string);
		}
		catch(std::exception& e){
			correctSpeed = false;
		}
	}

	while (correctAngle == false) {
		correctAngle = true;

		cout << "Podaj wartosc atrybutu \"angle\" (np 3.4): ";
		cin >> string;

		try {
			angle = std::stod(string);
		}
		catch (std::exception& e) {
			correctAngle = false;
		}
	}

	cout << endl;

	//Wylicznie wartosci dla poszczegolnych regul
	//speed low

	//1.	IF speed ∈ low AND angle ∈ large_negative THEN power ∈ low
	if (speed<6 && angle<-2) {
		if (speed <= 3) {
			rSpeed = 1.0;
		}
		else {
			rSpeed = (6 - speed) / 3;
		}

		if (angle <= -5) {
			rAngle = 1.0;
		}
		else {
			rAngle = (-angle - 2) / 3;
		}

		if (rSpeed < rAngle) { //wyznaczenie min(𝜇speed x , 𝜇angle y = ?) - agregacja deccyzji reguły
			rules[0] = rSpeed;
		}
		else {
			rules[0] = rAngle;
		}
	}

	//2.	IF speed ∈ low AND angle ∈ small negative THEN power ∈ medium
	if (speed < 6 && (angle > -5 && angle < 0)) {
		if (speed <= 3) {
			rSpeed = 1.0;
		}
		else {
			rSpeed = (6 - speed) / 3;
		}

		if (angle <= -2) {
			rAngle = (angle+5)/3;
		}
		else {
			rAngle = -angle / 2;
		}

		if (rSpeed < rAngle) { //wyznaczenie min(𝜇speed x , 𝜇angle y = ?)
			rules[1] = rSpeed;
		}
		else {
			rules[1] = rAngle;
		}
	}

	//3.	IF speed ∈ low AND angle ∈ zero THEN power ∈ high
	if (speed < 6 && (angle > -2 && angle < 2)) {
		if (speed <= 3) {
			rSpeed = 1.0;
		}
		else {
			rSpeed = (6 - speed) / 3;
		}

		if (angle <= 0) {
			rAngle = (angle + 2) / 2;
		}
		else {
			rAngle = (2 - angle) / 2;
		}

		if (rSpeed < rAngle) {
			rules[2] = rSpeed;
		}
		else {
			rules[2] = rAngle;
		}
	}

	//4.	IF speed ∈ low AND angle ∈ small positive THEN power ∈ medium
	if (speed < 6 && (angle > 0 && angle < 5)) {
		if (speed <= 3) {
			rSpeed = 1.0;
		}
		else {
			rSpeed = (6 - speed) / 3;
		}

		if (angle <= 2) {
			rAngle = angle * 2;
		}
		else {
			rAngle = (5 - angle) / 3;
		}

		if (rSpeed < rAngle) { //wyznaczenie min(𝜇speed x , 𝜇angle y = ?)
			rules[3] = rSpeed;
		}
		else {
			rules[3] = rAngle;
		}
	}

	//5.	IF speed ∈ low AND angle ∈ large positive THEN power ∈ low
	if (speed > 6 && angle > 2) {
		if (speed <= 3) {
			rSpeed = 1.0;
		}
		else {
			rSpeed = (6 - speed) / 3;
		}

		if (angle < 5) {
			rAngle = (angle - 2) / 3;
		}
		else {
			rAngle = 1;
		}

		if (rSpeed < rAngle) { //wyznaczenie min(𝜇speed x , 𝜇angle y = ?)
			rules[4] = rSpeed;
		}
		else {
			rules[4] = rAngle;
		}
	}

	//speed medium

	//6.	IF speed ∈ medium AND angle ∈ large_negative THEN power ∈ medium
	if ((speed >3 && speed <9) && angle < -2) {
		if (speed < 6) {
			rSpeed = (speed - 3) / 3;
		}
		else if(speed <= 8){
			rSpeed = 1;
		}
		else {
			rSpeed = speed - 9;
		}

		if (angle <= -5) {
			rAngle = 1.0;
		}
		else {
			rAngle = (-angle - 2) / 3;
		}

		if (rSpeed < rAngle) {
			rules[5] = rSpeed;
		}
		else {
			rules[5] = rAngle;
		}
	}

	//7.	IF speed ∈ medium AND angle ∈ small negative THEN power ∈ low
	if ((speed > 3 && speed < 9) && (angle > -5 && angle < 0)) {
		if (speed < 6) {
			rSpeed = (speed - 3) / 3;
		}
		else if (speed <= 8) {
			rSpeed = 1;
		}
		else {
			rSpeed = speed - 9;
		}

		if (angle <= -2) {
			rAngle = (angle + 5) / 3;
		}
		else {
			rAngle = -angle / 2;
		}

		if (rSpeed < rAngle) { //wyznaczenie min(𝜇speed x , 𝜇angle y = ?)
			rules[6] = rSpeed;
		}
		else {
			rules[6] = rAngle;
		}
	}

	//8.	IF speed ∈ medium AND angle ∈ zero THEN power ∈ high
	if ((speed > 3 && speed < 9) && (angle > -2 && angle < 2)) {
		if (speed < 6) {
			rSpeed = (speed - 3) / 3;
		}
		else if (speed <= 8) {
			rSpeed = 1;
		}
		else {
			rSpeed = speed - 9;
		}

		if (angle <= 0) {
			rAngle = (angle + 2) / 2;
		}
		else {
			rAngle = (2 - angle) / 2;
		}

		if (rSpeed < rAngle) {
			rules[7] = rSpeed;
		}
		else {
			rules[7] = rAngle;
		}
	}

	//9.	IF speed ∈ medium AND angle ∈ small positive THEN power ∈ low
	if ((speed > 3 && speed < 9) && (angle > 0 && angle < 5)) {
		if (speed < 6) {
			rSpeed = (speed - 3) / 3;
		}
		else if (speed <= 8) {
			rSpeed = 1;
		}
		else {
			rSpeed = speed - 9;
		}

		if (angle <= 2) {
			rAngle = angle * 2;
		}
		else {
			rAngle = (5 - angle) / 3;
		}

		if (rSpeed < rAngle) { //wyznaczenie min(𝜇speed x , 𝜇angle y = ?)
			rules[8] = rSpeed;
		}
		else {
			rules[8] = rAngle;
		}
	}

	//10.	IF speed ∈ medium AND angle ∈ large positive THEN power ∈ medium
	if ((speed > 3 && speed < 9) && angle > 2) {
		if (speed < 6) {
			rSpeed = (speed - 3) / 3;
		}
		else if (speed <= 8) {
			rSpeed = 1;
		}
		else {
			rSpeed = speed - 9;
		}

		if (angle < 5) {
			rAngle = (angle - 2) / 3;
		}
		else {
			rAngle = 1;
		}

		if (rSpeed < rAngle) { //wyznaczenie min(𝜇speed x , 𝜇angle y = ?)
			rules[9] = rSpeed;
		}
		else {
			rules[9] = rAngle;
		}		
	}

	//speed high

	//11.	IF speed ∈ high AND angle ∈ large_negative THEN power ∈ medium
	if (speed > 8 && angle < -2) {
		if (speed < 9) {
			rSpeed = speed -8;
		}
		else {
			rSpeed = 1.0;
		}

		if (angle <= -5) {
			rAngle = 1.0;
		}
		else {
			rAngle = (-angle - 2) / 3;
		}

		if (rSpeed < rAngle) {
			rules[10] = rSpeed;
		}
		else {
			rules[10] = rAngle;
		}
	}

	//12.	IF speed ∈ high AND angle ∈ small negative THEN power ∈ low
	if (speed > 8 && (angle > -5 && angle < 0)) {
		if (speed < 9) {
			rSpeed = speed - 8;
		}
		else {
			rSpeed = 1.0;
		}

		if (angle <= -2) {
			rAngle = (angle + 5) / 3;
		}
		else {
			rAngle = -angle / 2;
		}

		if (rSpeed < rAngle) { //wyznaczenie min(𝜇speed x , 𝜇angle y = ?)
			rules[11] = rSpeed;
		}
		else {
			rules[11] = rAngle;
		}
	}

	//13.	IF speed ∈ high AND angle ∈ zero THEN power ∈ medium
	if (speed > 8 && (angle > -2 && angle < 2)) {
		if (speed < 9) {
			rSpeed = speed - 8;
		}
		else {
			rSpeed = 1.0;
		}

		if (angle <= 0) {
			rAngle = (angle + 2) / 2;
		}
		else {
			rAngle = (2 - angle) / 2;
		}

		if (rSpeed < rAngle) {
			rules[12] = rSpeed;
		}
		else {
			rules[12] = rAngle;
		}
	}

	//14.	IF speed ∈ high AND angle ∈ small positive THEN power ∈ low
	if (speed > 8 && (angle > 0 && angle < 5)) {
		if (speed < 9) {
			rSpeed = speed - 8;
		}
		else {
			rSpeed = 1.0;
		}

		if (angle <= 2) {
			rAngle = angle * 2;
		}
		else {
			rAngle = (5 - angle) / 3;
		}

		if (rSpeed < rAngle) { //wyznaczenie min(𝜇speed x , 𝜇angle y = ?)
			rules[13] = rSpeed;
		}
		else {
			rules[13] = rAngle;
		}
	}

	//15.	IF speed ∈ high AND angle ∈ large positive THEN power ∈ medium
	if (speed > 8 && angle > 2) {
		if (speed < 9) {
			rSpeed = speed - 8;
		}
		else {
			rSpeed = 1.0;
		}

		if (angle < 5) {
			rAngle = (angle - 2) / 3;
		}
		else {
			rAngle = 1;
		}

		if (rSpeed < rAngle) { //wyznaczenie min(𝜇speed x , 𝜇angle y = ?)
			rules[14] = rSpeed;
		}
		else {
			rules[14] = rAngle;
		}
	}

	for (int i = 0; i < 15; i++) {
		if (rules[i] < 0) { //redukcja bledu zwiazanego z dokladnoscia bitowa
			rules[i] = 0;
		}
		cout << "Regula " << i + 1 << ": " << rules[i] << endl;
	}

	//wartosc atrybytu power dla kazdego przedzialu (szukanie max)
	//power_low - reguly: 1, 5, 7, 9, 12, 14
	powerLow = rules[0];
	if (rules[4] > rules[0]) {
		powerLow = rules[4];
	}
	if (rules[6] > rules[4]) {
		powerLow = rules[6];
	}
	if (rules[8] > rules[6]) {
		powerLow = rules[8];
	}
	if (rules[11] > rules[8]) {
		powerLow = rules[11];
	}
	if (rules[13] > rules[11]) {
		powerLow = rules[13];
	}

	//power_medium - reguly: 2, 4, 6, 10, 11, 13, 15
	powerMedium = rules[1];
	if (rules[3] > rules[1]) {
		powerMedium = rules[3];
	}
	if (rules[5] > rules[3]) {
		powerMedium = rules[5];
	}
	if (rules[9] > rules[5]) {
		powerMedium = rules[9];
	}
	if (rules[10] > rules[9]) {
		powerMedium = rules[10];
	}
	if (rules[12] > rules[10]) {
		powerMedium = rules[12];
	}
	if (rules[14] > rules[12]) {
		powerMedium = rules[14];
	}

	//power_high - reguly: 3, 8
	powerHigh = rules[2];
	if (rules[7] > rules[2]) {
		powerHigh = rules[7];
	}

	cout << endl;
	cout << "power_low: " << powerLow << endl;
	cout << "power_medium: " << powerMedium << endl;
	cout << "power_high: " << powerHigh << endl;


	//defuzyfikacja:

	//metoda sredniego maksimum:
	if (powerLow > 0) {
		wynikDefuzyfikacjiMax = 0.3;
	}
	if (powerMedium > 0 && powerMedium > powerLow) {
		wynikDefuzyfikacjiMax = 0.5;
	}
	if (powerHigh > 0 && powerHigh > powerMedium) {
		wynikDefuzyfikacjiMax = 0.7;
	}
		
	//metoda srodka ciezkosci
	double tmp = 0;
	if (powerLow > 0) {
		tmp += 0.3;
	}
	if (powerMedium > 0) {
		tmp += 0.5;
	}
	if (powerHigh > 0) {
		tmp += 0.7;
	}

	wynikDefuzyfikacjiSrC = (0.3 * powerLow + 0.5 * powerMedium + 0.7 * powerHigh) / (tmp);


	cout << endl;
	cout << "Wynik defuzyfikacji metoda sredniego maksimum: " << wynikDefuzyfikacjiMax << endl;
	cout << "Wynik defuzyfikacji metoda srodka ciezkosci: " << wynikDefuzyfikacjiSrC << endl;


	cout << endl << endl;
	cout << "!Wcisnij klawisz by zakonczyc dzialanie programu!" << endl;
	cin.get();
	cin.ignore();
}
