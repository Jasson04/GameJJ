// Jasson De Jesus Sepulveda
// Justin D Vaillant Burgos

//PROJECTO PROGRAMACION

//Se identifican las librerias
#include <iostream>
#include <string>
#include <ctime> //Libreria que contiene el seed de random
#include <random> //Libreria que se utiliza para barajear los caracteres
#include <windows.h>//libreria que contiene la funcion para cambiar los colores de la consola
#include <cstdlib>//libreria que contiene la funcion para terminar el programa instantaneamente
#include <algorithm>
#include <thread>//libreria usada para la funcion de esperar
#include <chrono>
using namespace std;

// Funcion para regar las palabras
// Parte hecha por Jason 
string AnagramGenerate(const string& word) {

	//Se crea una variable para que identifique el cual largo es la palabra random para evitar que las letras se repitan
	int l;
	string finalword;

	l = word.length();
	//hecho por jason
	random_device random;
	mt19937 gen(random()); //generador de números pseudoaleatorios utilizando el algoritmo Mersenne Twister

	//Barajea las letras de la palabra
	string anagram = word;
	shuffle(anagram.begin(), anagram.end(), gen);

	return anagram;

}

// Funcion que escoge de manera random una palabra del array 
int random() {

	//Cada vez que se llame la funcion random, seleciona una palabra de array random dependiendo del numero.
	//Se crean variables para poder identificar cual de las palabras del array escojer para que salga en las preguntas del juego
	unsigned seed;
	int worders;

	seed = time(0);
	srand(seed);
	//la variable worders se encarga de tomar la palabra que se encuentra dentro de la cantidad del array es decir [20] o entre 0 a 19
	worders = rand() % 20;


	return worders;
}


// Funcion que guarda las palabras en un array que saldran random en el juego
string chain() {
	//hecho por jason
	string generate, word, words[20] = { "mecanico", "arbol", "teclado",  "motor", "cabra", "martillo", "calculadora", "botella", "salon", "peluche", "piano", "mochila", "dragon", "humano", "azul", "katana", "television", "raqueta", "programa", "estructura" };
	int randomers = random(); // Se llama a la Funcion random() para que selecione de manera aleatoria una de las palabras del array

	word = words[randomers];


	return word;
}


//Funcion que guarda el Programa principal del juego
void second() {

	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	//Se identifican las variables
	int selection, number, points = 0;
	string letter, answer, word;

	//Menu del juego
	system("cls"); //Funcion que borra/limpia pantalla
	//hecho por jason
	cout << "[{-ADIVINATION-}]" << endl;
	cout << " " << endl; // Se deja espacio entre el titulo del juego y las opciones que ofrece
	cout << "1-Start" << endl;
	cout << "2-Exit" << endl;
	//El usuario selecciona que hacer en el Menu colocando un numero
	cin >> selection;
	//hecho por Justin y Jason
	if (selection == 1) {
		// Usuario selecciona "Start" para iniciar el juego

		for (int i = 0; i < 4; i++) {

			system("cls"); //Funcion que borra/limpia pantalla
			string chosenWord = chain(); //Se crea variable que llame a la funcion para generar una palabra random del array
			string anagram = AnagramGenerate(chosenWord); // Se crea variable que llame a la funcion para generar la palabra ya desordenada          
			int Exit;

			cout << anagram << endl;
			cout << endl;
			cin >> answer;
			cout << "(press 1 to continue, press 2 to exit )" << endl;
			cin >> Exit;

			switch (Exit) {
			case 1:
				if (answer == chosenWord) {

					cout << "Correct" << endl;
					points = points + 1;
					this_thread::sleep_for(chrono::seconds(3));

				}
				else {
					cout << "Incorrect" << endl;
					this_thread::sleep_for(chrono::seconds(3));

					system("cls");

					cout << "second oportunitie" << endl;
					cout << anagram << endl;
					cout << endl;
					cin >> answer;

					if (answer == chosenWord) {

						cout << "Correct" << endl;

						points = points + 1;
						this_thread::sleep_for(chrono::seconds(3));
					}
					else {
						SetConsoleTextAttribute(hConsole, 12);
						cout << "Incorrect" << endl;
						SetConsoleTextAttribute(hConsole, 7);

					}
					break;

			case 2:
				system("cls"); //Funcion que borra/limpia pantalla
				SetConsoleTextAttribute(hConsole, 12);
				cout << "Leaving game..." << endl;
				exit(0);//funcion que termina el programa instantaneamente
				break;
				}
			}

		}

		system("cls");
		SetConsoleTextAttribute(hConsole, 1);
		cout << "you have " << points << " points " << points << " / 4" << endl;
		SetConsoleTextAttribute(hConsole, 7);

	}
	else if (selection == 2) {
		// Usuario selecciona "Exit" para salir del programa
		system("cls"); //Funcion que borra/limpia pantalla
		cout << "Bye bye" << endl;
	}
	else {
		system("cls"); //Funcion que borra/limpia pantalla
		cout << "ERROR" << endl;
	}

}

// Programa principal (inicio de sesion)
int main() {
	//hecho por Justin
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);//esto permite cambiar el color de la linea de texto que queramos
	string username, password, username1 = "Justin", password1 = "Justin1", username2 = "Jasson", password2 = "Jasson1";//credenciales para la opcion 2 del switch case iniciar sesion
	int Fselection, passLevel, game;
	cout << "Welcome to our guessing game" << endl;
	cout << "press 1 to create account" << endl;
	cout << "Press 2 if you already have an account" << endl;
	cout << "Press 3 to EXIT" << endl;
	cin >> Fselection;
	int G = 0;
	switch (Fselection) {
	case 1:
		cout << "Enter your username" << endl;
		cin >> username;
		while (G < 1) {// loop que se ejecutara solo si se ingresa un password de menos de 5 letras

			cout << "Create your password" << endl;
			cin >> password;
			passLevel = password.size();// Aqui se almacena el largo de la contraseÃ±a
			if (passLevel >= 5) {
				G = G + 1;
				cout << "Welcome " << username << endl;
				this_thread::sleep_for(chrono::seconds(3));


				second();
			}
			if (passLevel < 5) {

				SetConsoleTextAttribute(hConsole, 12);//cambia el color a rojo
				cout << "Your password has a low level of security" << endl;
				cout << "password must be at least five(5) characters" << endl;
				SetConsoleTextAttribute(hConsole, 7);//cambia el color a blanco
				cout << "Enter a new password please " << endl;


			}
		}
		break;
	case 2:
		cout << "Enter your username: " << endl;
		cin >> username;
		cout << "Enter you password: " << endl;
		cin >> password;
		if (username == username1 and password == password1) {
			cout << "Welcome Justin" << endl;

			second();// Llama a funcion second() para iniciar el juego

		}
		else if (username == username2 and password == password2) {
			cout << "Welcome Jasson" << endl;

			second();// Llama a funcion second() para iniciar el juego

		}
		else {
			SetConsoleTextAttribute(hConsole, 12);
			cout << "Username or password incorrect" << endl;
			SetConsoleTextAttribute(hConsole, 7);
		}
		break;
	case 3:
		exit(0);//funcion que termina el programa instantaneamente


	}
	return 0;
}