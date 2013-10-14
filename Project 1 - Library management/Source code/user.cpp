/**\file user.cpp
 * \brief Ficheiro com a implementa��o da classe user.
 *
 * PROJECTO: Projecto 1 - Programa��o - 10-11 - MIEIC\n
 * FICHEIRO: user.cpp \n
 * DESCRI��O: Ficheiro com a implementa��o da classe user que representa um dado utilizador de uma biblioteca. \n
 *
 * AUTOR:
 * - Carlos Miguel Correia da Costa
 */

#include "user.h"




//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>   <init-variables>   <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
/**
 * Inicializa��o do static data member que conta o n�mero de users que foram criados at� um dado momento
 * de forma a poder atribuir um id �nico a cada um.
 */
IdentNum User::numUsers = 0;
//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>   </init-variables>   <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<



//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>   <constructors>   <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
/**
 * Constructor por default de user
 * Inicializa o name no formato : "Unnamed user with id: " + ID
 * e coloca o user activo na biblioteca
 */
User::User() : ID(++numUsers), name("Unnamed user with id: "), active(true) {}

/**
 * Constructor de User que inicializa o nome a "name"
 * @param name Nome a atribuir ao User que vai ser criado
 */
User::User(string nome) : ID(++numUsers), name(nome), active(true) {}
//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>   </constructors>   <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<



//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>   <gets>   <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<

/**
 * M�todo que retorna o n�mero de users que foram criados at� agora
 */
IdentNum User::getNumUsers() {
	return User::numUsers;
}

/**
 * M�todo que devolve o ID do user.
 * @return Retorna ID do user
 */
IdentNum User::getID() const {
	return ID;
}

/**
 * M�todo que devolve o nome do user
 * @return Retorna o nome do user
 */
string User::getName() const {
	return name;
}

/**
 * M�todo que permite determinar se um user est� activo na biblioteca
 * P.S. S� users activos podem requesitar livros
 * @return Retorna true caso o user esteja activo
 */
bool User::isActive() const {
	return active;
}

/**
 * M�todo que devolve o vector de IdentNum que contem os ids dos livros que o user requesitou � biblioteca
 * @return vector<IdentNum> com os ids dos livros requesitados pelo user.
 */
vector<IdentNum> User::getRequestedBooks() const {
	return requestedBooks;
}

/**
 * M�todo que permite saber se o user requesitou livros
 * @return true caso o user tenha requesitado livros � bilioteca
 */
bool User::hasBooksRequested() const {
	return !requestedBooks.empty();
}
//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>   </gets>   <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<



//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>   <sets>   <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<

/**
 * M�todo que altera o ID do user para o userID fornecido
 * @param userID ID a ser atribuido ao user
 */
void User::setID(IdentNum userID) {
	ID = userID;
}

/**
 * M�todo que altera o nome do user para o userName dado
 * @param userName nome a atribuir ao user
 */
void User::setName(string userName) {
	name = userName;
}

/**
 * M�todo que altera o estado do user perante a biblioteca de acordo com o status que � dado
 * @param status true caso se queira que o user possa requesitar livros na biblioteca
 */
void User::setActive(bool status) {
	active = status;
}

/**
 * M�todo que altera o vector que contem os ids dos livros que o user requesitou � biblioteca pelo booksRequestedByUser
 * @param booksRequestedByUser vector que ir� substituir o vector<IdentNum> actual do user
 */
void User::setRequestedBooks(const vector<IdentNum> & booksRequestedByUser) {
	requestedBooks = booksRequestedByUser;
}

/**
 * M�todo que modifica a vari�vel est�tica numUsers da class User para o valor num
 * P.S. Caso num seja menor que numUsers, n�o altera numUsers, visto que n�o havendo elimina��o de users,
 * caso numUsers fosse colocado para um valor inferior ao actual, iria haver users com ids iguais, o que n�o deve ser permitido
 * @param num N�mero de users que existem registados (tem que ser maior que o n�mero actual)
 */
void User::setNumUsers(IdentNum num) {
	if (num > numUsers) {
		numUsers = num;
	}
}
//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>   </sets>   <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<



//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>   <bookManagement>   <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
/**
 * M�todo que acrescenta o bookID ao vector<IdentNum> do user caso este esteja activo
 * P.S. Equivale a uma requisi��o de um livro por parte do user � bilbioteca
 * @param bookID id do livro a acrescentar
 */
void User::borrowBook(IdentNum bookID) {
	if (active) {
		requestedBooks.push_back(bookID);
	}
}


/**
 * M�todo que retira o livro com o bookID do vector<IdentNum> que contem os livros requisitados pelo user
 * Caso o utilizador n�o tenha um livro com esse id lan�a uma excep��o (ElementDoesntExistsException<IdentNum>)
 * P.S. Equivale ao user retornar o livro � bilioteca
 * P.S. 2 - S� remove esse id se o user tiver requesitado o livro
 * @param bookID
 */
void User::returnBook(IdentNum bookID) throw(ElementDoesntExistsException<IdentNum>) {
	for (vector<IdentNum>::iterator bookIter = requestedBooks.begin(); bookIter != requestedBooks.end(); ++bookIter) {
		if (bookID == (*bookIter)) {
			//remove id do livro
			requestedBooks.erase(bookIter);
			//o m�todo apenas deve retornar um livro, por isso n�o vale a pena continuar a pesquisar o vector se j� se encontrou o id que se ia remover
			return;
		}
	}

	stringstream message;
	message << "O livro com o ID" << bookID << "n�o existe!!!";
	//caso n�o encontre um user com o id especificado lan�a uma excep��o
	throw ElementDoesntExistsException<IdentNum>(bookID, message.str().c_str());
}
//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>   </bookManagement>   <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
