/**\file utils.h
 * \brief Ficheiro com fun��es �teis para a interface com o utilizador.
 *
 * PROJECTO: Projecto 1 - Programa��o - 10-11 - MIEIC\n
 * FICHEIRO: utils.h \n
 * DESCRI��O: Ficheiro com fun��es �teis para a interface com o utilizador. \n
 *
 * AUTOR:
 * - Carlos Miguel Correia da Costa
 */

#ifndef UTILS_H_
#define UTILS_H_

#include <vector>
#include <string>
#include <iostream>
#include <sstream>
#include <iomanip>
#include <limits>
#include <climits>
#include <algorithm>
#include <cstdlib>
#include "LibraryExceptions.h"

using std::string;
using std::stringstream;
using std::vector;
using std::cin;
using std::cout;
using std::setw;
using std::flush;
using std::endl;
using std::max;
using std::getline;
using std::istream;

namespace utils {

/**
 * \brief Limpa as flags do cin e fica � espera de um input para prosseguir.
 * \details Serve para parar o programa e esperar que o utilizador fa�a algum input para prosseguir.
 *          Evita user system("pause"), que n�o � portable, n�o � standard e � muito mais "pesado" para o programa...
 */
void getUserInput();


/**
 * getline que faz o sync para n�o ler lixo do buffer.
 * @return Retorna a string com a linha lida do cin.
 */
string getlineCin();

/**
 * M�todo que limpa o ecr� da consola.
 * Evita usar system("cls"), que n�o � portable, n�o � standard e � muito mais "pesado" para o programa...
 */
void clearConsoleScreen();


/**
 * \brief Mostra a "message" ao utilizador e espera por um input de um n�mero entre min (default � 0) e size-1 (default � INT_MAX).
 * \details Enquanto n�o for introduzido um input v�lido vai pedindo ao utilizador para introduzir novamente os dados mostrando a errorMessage.
 */
int getIntCin(const char* message, const char* errorMessage, int min = 0, int size = INT_MAX);

///Pergunta message ao utilizador e retorna Sim/N�o.
bool getYesNoCin(const char* message, const char* message_erro = "Introduziu uma op��o incorrecta!\nIntroduza S para continuar ou N para parar: ");

///Converte uma string para mai�sculas.
string toUpper(string str);


///Converte uma string para min�sculas.
string toLower(string str);


///Fun��o de convers�o de objecto para string usando o operador <<.
template <class T>
string toString(T obj) {
	stringstream ss;
	ss << obj;
	return ss.str();
}

}

#endif
