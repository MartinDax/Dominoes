/**\file library.cpp
 * \brief Ficheiro com a implementa��o da classe library.
 *
 * PROJECTO: Projecto 1 - Programa��o - 10-11 - MIEIC\n
 * FICHEIRO: library.cpp \n
 * DESCRI��O: Ficheiro com a implementa��o da classe library que representa uma dada biblioteca. \n
 *
 * AUTOR:
 * - Carlos Miguel Correia da Costa
 */

#include "library.h"



//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>   <constructors>   <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
/**
 * Contructor por default que inicializa a biblioteca com 0 users e books
 * e cujo nome do ficheiro onde s�o guardados os users � "users.txt"
 * e o nome do ficheiro onde ser�o guardados os livros � "books.txt"
 */
Library::Library() : filenameUsers("users.txt"), filenameBooks("books.txt") {}

/**
 * Constructor de Library que inicializa a biblioteca com 0 users e books
 * e cujo nome do ficheiro onde ser�o guardados os users � <fileUsers>
 * e o nome do ficheiro onde ser�o guardados os livros � <fileBooks>
 * @param fileUsers Nome do ficheiro onde ser�o guardados os users da biblioteca
 * @param fileBooks Nome do ficheiro onde ser�o guardados os livros do biblioteca
 */
Library::Library(string fileUsers, string fileBooks) : filenameUsers(fileUsers), filenameBooks(fileBooks) {}
//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>   <constructors>   <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<



//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>   <gets>   <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
/**
 * M�todo que devolve o indice que um user com o userID dado tem no vector<User> da library
 * Lan�a uma exception (ElementDoesntExistsException) caso esse id n�o exista
 * @param userID id do user que se quer obter a posi��o no vector
 * @return Retorna o indice do user com o id dado no vector<User> da library
 */
size_t Library::getUserIndexByID(IdentNum userID) const throw(ElementDoesntExistsException<IdentNum>) {
	//percorre o vector onde est�o os users e tenta encontrar aquele que tem o id dado
	for (size_t i = 0; i < users.size(); ++i) {
		if (userID == users[i].getID()) {
			return i;
		}
	}

	stringstream message;
	message << "O user com o ID" << userID << "n�o existe!!!";
	//caso n�o encontre um user com o id especificado lan�a uma excep��o
	throw ElementDoesntExistsException<IdentNum>(userID, message.str().c_str());
}

/**
 * M�todo que devolve uma c�pia do user com o ID especificado
 * Caso o userID n�o exista lan�a uma excep��o (ElementDoesntExistsException)
 * @param userID id do User que se quer obter
 * @return Retorna uma c�pia do user que tem o ID especificado
 */
User Library::getUserByID(IdentNum userID) const {
	return users[getUserIndexByID(userID)];
}

/**
 * M�todo que devolve uma refer�ncia para o user com o ID especificado
 * Caso o userID n�o exista lan�a uma excep��o (ElementDoesntExistsException)
 * @param userID id do User que se quer obter
 * @return Retorna ua refer�ncia para o user que tem o ID especificado
 */
User& Library::getRefToUserByID(IdentNum userID) {
	return users[getUserIndexByID(userID)];
}

//-------------------------------------------------------------------------------------------------------------------

/**
 * M�todo que devolve o indice que um livro com o bookID dado tem no vector<Book> da library
 * Lan�a uma exception (ElementDoesntExistsException) caso esse id n�o exista
 * @param bookID id do lvro que se quer obter a posi��o no vector
 * @return Retorna o indice do livro com o id dado no vector<Book> da library
 */
size_t Library::getBookIndexByID(IdentNum bookID) const throw(ElementDoesntExistsException<IdentNum>) {
	//percorre o vector onde est�o os livros e tenta encontrar aquele que tem o id dado
	for (size_t i = 0; i < books.size(); ++i) {
		if (bookID == books[i].getID()) {
			return i;
		}
	}

	stringstream message;
	message << "O livro com o ID" << bookID << "n�o existe!!!";
	//caso n�o encontre um livro com o id especificado lan�a uma excep��o
	throw ElementDoesntExistsException<IdentNum>(bookID, message.str().c_str());
}


/**
 * M�todo que devolve o livro com o id especificado
 * Caso o bookID n�o exista lan�a uma excep��o (ElementDoesntExistsException)
 * @param bookID Id do livro que se quer obter
 * @return Retorna uma c�pia do livro que tem o id especificado
 */
Book Library::getBookByID(IdentNum bookID) const {
	return books[getBookIndexByID(bookID)];
}


/**
 * M�todo que devolve uma refer�ncia para o livro com o ID especificado
 * Caso o bookID n�o exista lan�a uma excep��o (ElementDoesntExistsException)
 * @param bookID id do Book que se quer obter
 * @return Retorna uma refer�ncia para o livro que tem o ID especificado
 */
Book& Library::getRefToBookByID(IdentNum bookID) {
	return books[getBookIndexByID(bookID)];
}


/**
 * M�todo que retorna o vector de User da biblioteca
 * @return vector<User>
 */
const vector<User> &Library::getUsers() const {
	return this->users;
}

/**
 * M�todo que retorna o vector de livros da biblioteca
 * @return vector<Book>
 */
const vector<Book> &Library::getBooks() const {
	return this->books;
}

/**
 * M�todo que retorna o filename onde s�o guardados os Users da biblioteca
 * @return
 */
string Library::getFilenameUsers() const {
	return this->filenameUsers;
}

/**
 * M�todo que retorna o filename onde s�o guardados os Books da biblioteca
 * @return
 */
string Library::getFilenameBooks() const {
	return this->filenameBooks;
}

//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>   </gets>   <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<



//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>   <sets>   <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
//set functions
void Library::setUsers(vector<User> &users) {
	this->users = users;
}

void Library::setBooks(vector<Book> &books) {
	this->books = books;
}

void Library::setFilenameUsers(string filename) {
	this->filenameUsers = filename;
}

void Library::setFilenameBooks(string filename) {
	this->filenameBooks = filename;
}
//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>   </sets>   <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<



//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>   <libraryManagement>   <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
/**
 * M�todo que adiciona um user � biblioteca
 * @param user User a adicionar
 */
void Library::addUser(User user) {
	users.push_back(user);
}


/**
 * M�todo que adciona um livro � biblioteca
 * @param book Livro a adicionar
 */
void Library::addBook(Book book) {
	books.push_back(book);
}


/**
 * M�todo que trata da requesi��o do livro com o id bID por parte do utilizador com id uID
 * P.S. S� utilizadores activos podem requesitar livros
 * @param uID id do utilizador que vai requesitar o livro
 * @param bID id do livro que vai ser requesitado
 */
void Library::loanBook(IdentNum uID, IdentNum bID) {
	try {
		User& user = getRefToUserByID(uID);
		Book& book = getRefToBookByID(bID);

		//se o user n�o estiver activo n�o pode requesitar livros
		if (user.isActive()) {
			//s� � possivel requesitar se houver exemplares disponiveis
			if (book.getNumAvailable() > 0) {
				user.borrowBook(bID);
				book.loanBook();
			}
		}
	} catch (ElementDoesntExistsException<IdentNum>& e) {
		cerr << e.what() << endl;
	}
}

/**
 * M�todo que trata da devolu��o de um livro � biblioteca por parte de um utilizador
 * @param uID id do utilizador que vai devolver o livro
 * @param bID id do livro que vai ser devolvido
 */
void Library::returnBook(IdentNum uID, IdentNum bID) {
	try {
		User& user = getRefToUserByID(uID);
		Book& book = getRefToBookByID(bID);

		//caso os ids n�o existam as fun��es acima lan�am uma excep��o, portanto nunca ir� executar o c�digo a seguir

		//tira o livro do vector<IdentNum> que tem os livros reqesitados pelo user
		user.returnBook(bID);
		//incrementa de uma unidade o n�mero de exemplares dispon�veis
		book.returnBook();

	} catch (ElementDoesntExistsException<IdentNum>& e) {
		cerr << e.what() << endl;
	}
}
//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>   <libraryManagement>   <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<



//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>   <library loads-saves>   <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<

/**
 * M�todo que carrega os utilizadores da biblioteca
 */
void Library::loadUsers() {
	ifstream inputFileStream(this->filenameUsers.c_str());

	if (inputFileStream.is_open()) {
		string numUsersStr;
		getline(inputFileStream, numUsersStr);

		int numUsers = atoi(numUsersStr.c_str());

		for (int userIndex = 0; userIndex < numUsers; ++userIndex) {
			//nome
			string userName;
			getline(inputFileStream, userName);

			//activo ou n�o
			string userActiveStr;
			getline(inputFileStream, userActiveStr);
			bool userActive = true;
			if (userActiveStr == (string)"Inactive") {
				userActive = false;
			}

			//cria��o do user(id � reconstituido, porque a ordem de escrita � igual ao da leitura)
			User newUser(userName);
			newUser.setActive(userActive);



			//leitura dos ids dos livros que requesitou
			string numBooksRequestedByUserStr;
			getline(inputFileStream, numBooksRequestedByUserStr);

			int numBooksRequestedByUser = atoi(numBooksRequestedByUserStr.c_str());

			for (int bookIdIndex = 0; bookIdIndex < numBooksRequestedByUser; ++bookIdIndex) {
				string bookIdStr;
				getline(inputFileStream, bookIdStr);
				IdentNum bookId = (IdentNum)atoi(bookIdStr.c_str());

				//acrescenta��o do id ao user
				newUser.borrowBook(bookId);
			}


			//adi��o do user � biblioteca
			this->addUser(newUser);
		}

		inputFileStream.close();
	} else {
		//cout << flush;
		cerr << flush;
		cerr << "\nO ficheiro de utilizadores da biblioteca n�o foi encontrado!!" << endl;
		cout << flush;
		utils::getUserInput();
	}
}


/**
 * M�todo que grava os utilizadores da biblioteca
 */
void Library::saveUsers() {
	ofstream outputFileStream(this->filenameUsers.c_str());

	//guarda o n�mero de users
	outputFileStream << this->users.size() << "\n";

	for (size_t userIndex = 0; userIndex < this->users.size(); ++userIndex) {
		//outputFileStream << this->users[userIndex].getID() << "\n";			//guarda o id
		outputFileStream << this->users[userIndex].getName() << "\n";		//guarda o nome
		outputFileStream << (this->users[userIndex].isActive() ? "Active" : "Inactive") << "\n";		//guarda se esta activo

		//guarda o n�mero de livros que o user tem requesitados
		size_t numBooksRequested = this->users[userIndex].getRequestedBooks().size();
		outputFileStream << numBooksRequested << "\n";
		//guarda os is dos livros que o user requesitou
		for (size_t bookIdIndex = 0; bookIdIndex < numBooksRequested; ++bookIdIndex) {
			outputFileStream << this->users[userIndex].getRequestedBooks()[bookIdIndex] << "\n";
		}
	}

	outputFileStream.close();
}


/**
 * M�todo que carrega os livros da biblioteca
 */
void Library::loadBooks() {
	ifstream inputFileStream(this->filenameBooks.c_str());

	if (inputFileStream.is_open()) {
		string numBooksStr;
		getline(inputFileStream, numBooksStr);

		int numBooks = atoi(numBooksStr.c_str());

		for (int userIndex = 0; userIndex < numBooks; ++userIndex) {
			//titulo do livro
			string bookTitle;
			getline(inputFileStream, bookTitle);


			//autor do livro
			string bookAuthor;
			getline(inputFileStream, bookAuthor);


			//numero de exemplares
			string numCopiesOfTheBookStr;
			getline(inputFileStream, numCopiesOfTheBookStr);
			unsigned int numCopiesOfTheBook = (unsigned int)atoi(numCopiesOfTheBookStr.c_str());


			//cria��o do livro
			Book newBook(bookTitle, bookAuthor, numCopiesOfTheBook);

			//acrescenata��o do livro � biblioteca
			this->addBook(newBook);
		}

		inputFileStream.close();
	} else {
		//cout << flush;
		cerr << flush;
		cerr << "\nO ficheiro de livros da biblioteca n�o foi encontrado!!" << endl;
		cout << flush;
		utils::getUserInput();
	}
}


/**
 * M�todo que grava os utilizadores da biblioteca
 */
void Library::saveBooks() {
	ofstream outputFileStream(this->filenameBooks.c_str());

	//guarda o n�mero de livros
	outputFileStream << this->books.size() << "\n";

	for (size_t userIndex = 0; userIndex < this->books.size(); ++userIndex) {
		//outputFileStream << this->books[userIndex].getID() << "\n";					//guarda o id
		outputFileStream << this->books[userIndex].getTitle() << "\n";				//guarda o titulo
		outputFileStream << this->books[userIndex].getAuthor() << "\n";				//guarda o autor
		outputFileStream << this->books[userIndex].getNumAvailable() << "\n";		//guarda o numero de exemplares
	}

	outputFileStream.close();
}
//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>   </library loads-saves>   <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<



//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>   <user | books - listing>   <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<

/**
 * M�todo que mostra todos os utilizadores da biblioteca se stringToSerach estiver vazia ou caso contr�rio
 * mostra apenas os utilizadores que tenham a stringToSearch no seu nome
 * P.S. Evita repeti��o de c�digo nas fun��es showUsers() e showUsers(string str)
 * @param stringToSearch String que ser� usada como filtro de resultados.
 * 						 Se n�o se pretender usar o filtro deve estar vazia.
 * 						 P.S. N�o � case sensitive.
 */
void Library::showUsersParameterized(string stringToSearch) const {
	cout << "#### Utilizadores ####\n";

	//se n�o houver utilizadores mostra a mensagem de erro e retorna
	if (users.empty()) {
		cout << "\nN�o existem utilizadores na biblioteca!" << endl;
		return;
	}

	//cria��o do separador que se adapta ao comprimento que se d� �s macros que definem o comprimento de cada campo da tabela
	stringstream tableSeparator;
	tableSeparator << " ";
	size_t numberOfDashes = USER_ID_SIZE + USER_NAME_SIZE + USER_ACTIVE_STATE_SIZE + 2; //2 � o n� de ":" que separa os campos da tabela
	for (size_t i = 0; i < numberOfDashes; ++i) {
		tableSeparator << "-";
	}
	tableSeparator << " ";


	cout << tableSeparator.str() << "\n";
  //cout << ":ID   :Nome:                         :Activo         :\n";
	cout << left;
	cout << ":" << setw(USER_ID_SIZE) << "ID";
	cout << ":" << setw(USER_NAME_SIZE) << "Nome:";
	cout << ":" << setw(USER_ACTIVE_STATE_SIZE) << "Activo";
	cout << ":\n";
	cout << tableSeparator.str() << "\n";

	//visualiza��o dos users da biblioteca
	for (size_t i = 0; i < users.size(); ++i) {
		//caso se pretenda filtrar o resultado atrav�s de stringToSearch, para mostrar apenas os utilizadores
		//que tenham stringToSearch no seu nome
		if (!stringToSearch.empty()) {
			//se n�o encontrar na string do nome do utilizador a stringToSearch, n�o mostra este utilizador
			//passa o nome e a string a pesquisar para maiusculas, para n�o ser case sensitive
			if (utils::toUpper(users[i].getName()).find(utils::toUpper(stringToSearch)) == string::npos) {
				continue;
			}
		}


		cout << ":" << setw(USER_ID_SIZE) << users[i].getID();
		cout << ":" << setw(USER_NAME_SIZE) << users[i].getName();
		cout << ":" << setw(USER_ACTIVE_STATE_SIZE);

		if (users[i].isActive()) {
			cout << "Sim";
		} else {
			cout << "N�o";
		}

		cout << ":\n";
	}

	cout << tableSeparator.str() << endl;
}


/**
 * M�todo que mostra todos os utilizadores da biblioteca
 */
void Library::showUsers() const {
	showUsersParameterized((string)"");
}


/**
 * M�todo que mostra apenas os utilizadores que tenham str no seu nome
 * @param str Filtro a aplicar aos resultados
 */
void Library::showUsers(string str) const {
	showUsersParameterized(str);
}



//********************************************************************************************************************************
//********************************************************************************************************************************



/**
 * M�todo que mostra os livros que t�m o n�mero de exemplares a 0 caso showUnavailableBooks seja true
 * P.S. Fun��o que evita redund�ncia de c�digo entre as fun��es showBooks(), showBooks(string str) e showAvailableBooks()
 * @param showUnavailableBooks flag usada para saber se s�o ou n�o mostrados os livros com disponibilidade 0
 * @param stringToSearch String que ser� usada para fazer a filtragem de books,
 * 		  em que caso stringToSearch n�o esteja vazia, apenas se mostra os livros que tenham essa string no seu t�tulo
 * 		  P.S. N�o � case sensitive
 */
void Library::showBooksParameterized(bool showUnavailableBooks, string stringToSearch) const {
	cout << "#### Livros ####\n";

	//se n�o houver livros mostra a mensagem de erro e retorna
	if (books.empty()) {
		cout << "\nN�o existem livros na biblioteca!" << endl;
		return;
	}


	//cria��o do separador que se adapta ao comprimento que se d� �s macros que definem o comprimento de cada campo da tabela
	stringstream tableSeparator;
	tableSeparator << " ";
	size_t numberOfDashes = BOOK_ID_SIZE + BOOK_TITLE_SIZE + BOOK_AUTHOR_SIZE + BOOK_QTD_DISP_SIZE + 3; //3 � o n� de ":" que separa os campos da tabela
	for (size_t i = 0; i < numberOfDashes; ++i) {
		tableSeparator << "-";
	}
	tableSeparator << " ";


	cout << tableSeparator.str() << "\n";
  //cout << ":ID   :Titulo                   :Autor               :QTD. Disp.:\n";
	cout << left;
	cout << ":" << setw(BOOK_ID_SIZE) << "ID";
	cout << ":" << setw(BOOK_TITLE_SIZE) << "Titulo";
	cout << ":" << setw(BOOK_AUTHOR_SIZE) << "Autor";
	cout << ":" << setw(10) << "QTD. Disp.";
	cout << ":\n";
	cout << tableSeparator.str() << "\n";

	//visualiza��o dos livros da biblioteca
	for (size_t i = 0; i < books.size(); ++i) {
		//caso n�o se queira mostrar livros que t�m o n�mero de exemplares dispon�veis a 0 (n�o podem ser requesitados)
		if (!showUnavailableBooks && (books[i].getNumAvailable() == 0)) {
			//ignora os livros que t�m disponibilidade a 0 (passa a frente este "i" neste ciclo for)
			continue;
		}

		//caso se pretenda filtrar o resultado atrav�s de stringToSearch, para mostrar apenas os livros
		//que tenham stringToSearch no seu titulo
		if (!stringToSearch.empty()) {
			//se n�o encontrar na string do t�tulo do livro a stringToSearch, n�o mostra este livro
			//passa o titulo e a string a pesquisar para maiusculas, para n�o ser case sensitive
			if (utils::toUpper(books[i].getTitle()).find(utils::toUpper(stringToSearch)) == string::npos) {
				continue;
			}
		}

		cout << ":" << setw(BOOK_ID_SIZE) << books[i].getID();
		cout << ":" << setw(BOOK_TITLE_SIZE) << books[i].getTitle();
		cout << ":" << setw(BOOK_AUTHOR_SIZE) << books[i].getAuthor();
		cout << ":" << setw(BOOK_QTD_DISP_SIZE) << books[i].getNumAvailable();
		cout << ":\n";
	}

	cout << tableSeparator.str() << endl;
}


/**
 * M�todo que lista todos os livros da biblioteca na consola
 */
void Library::showBooks() const {
	showBooksParameterized(true, (string)"");
}

/**
 * M�todo que mostra todos os livros que tenham a string str no seu t�tulo
 * @param str String que se pretende procurar nos t�tulos dos livros que se quer visualizar
 */
void Library::showBooks(string str) const {
	showBooksParameterized(true, str);
}

/**
 * M�todo que mostra apenas os livros da biblioteca que tenham dispon�veis exemplares para empr�stimo
 */
void Library::showAvailableBooks() const {
	showBooksParameterized(false, (string)"");
}


/**
 * M�todo que mostra os livros que um utilizador requesitou
 * @param IDsOfBooksRequestedByTheUser vector que contem os ids dos livros a mostrar
 */
void Library::showUserBooks(vector<IdentNum> IDsOfBooksRequestedByTheUser) {
	cout << "#### Livros ####\n";

	//se n�o houver livros mostra a mensagem de erro e retorna
	if (IDsOfBooksRequestedByTheUser.empty()) {
		cout << "\nO utilizador n�o tem livros requesitados!\n" << endl;
		return;
	}


	//cria��o do separador que se adapta ao comprimento que se d� �s macros que definem o comprimento de cada campo da tabela
	stringstream tableSeparator;
	tableSeparator << " ";
	size_t numberOfDashes = BOOK_ID_SIZE + BOOK_TITLE_SIZE + BOOK_AUTHOR_SIZE + 2; //2 � o n� de ":" que separa os campos da tabela
	for (size_t i = 0; i < numberOfDashes; ++i) {
		tableSeparator << "-";
	}
	tableSeparator << " ";


	cout << tableSeparator.str() << "\n";
  //cout << ":ID   :Titulo                   :Autor               :\n";
	cout << left;
	cout << ":" << setw(BOOK_ID_SIZE) << "ID";
	cout << ":" << setw(BOOK_TITLE_SIZE) << "Titulo";
	cout << ":" << setw(BOOK_AUTHOR_SIZE) << "Autor";
	cout << ":\n";
	cout << tableSeparator.str() << "\n";

	//visualiza��o dos livros da biblioteca
	for (size_t i = 0; i < IDsOfBooksRequestedByTheUser.size(); ++i) {
		try {
			Book& currentBook = this->getRefToBookByID(IDsOfBooksRequestedByTheUser[i]); //lan�a excep��o se o id n�o existir

			cout << ":" << setw(BOOK_ID_SIZE) << currentBook.getID();
			cout << ":" << setw(BOOK_TITLE_SIZE) << currentBook.getTitle();
			cout << ":" << setw(BOOK_AUTHOR_SIZE) << currentBook.getAuthor();
			cout << ":\n";
		} catch (ElementDoesntExistsException<IdentNum> &e) {
			cout << "\nO livro com id " << IDsOfBooksRequestedByTheUser[i] << " n�o existe!!\n";
		}
	}

	cout << tableSeparator.str() << endl;
}
//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>   </user | books - listing>   <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<



//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>   <CLI interface>   <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
/**
 * M�todo que regista um utilizador na biblioteca usando a CLI (command line interface)
 */
void Library::registerUserCLI() {
	//limpa o ecra
	utils::clearConsoleScreen();

	cout << "#### Registo de utilizadores ####\n\n";

	bool invalidName = false;
	string name;

	//obten��o do nome a dar ao novo utilizador
	do {
		cout << "Nome: ";

		string nameTemp = utils::getlineCin();

		if (nameTemp.size() > USER_NAME_SIZE) {
			cout << "Introduza um nome com menos de " << USER_NAME_SIZE << " caracteres!!\n\n";
			invalidName = true;
		} else {
			invalidName = false;
			name = nameTemp;
		}
	} while (invalidName);

	//cria��o do novo utilizador
	User newUser(name);

	//adi��o do utilizador ao vector<User>
	this->addUser(newUser);

	//informa��o do utilizador que a adi��o ocorreu com sucesso
	cout << "Utilizador " << name << " adicionado com sucesso, com o ID: " << newUser.getID() << ".\n";


	//espera por input do user
	utils::getUserInput();

	//limpa a consola
	utils::clearConsoleScreen();
}


/**
 * M�todo que adiciona um livro � biblioteca usando a CLI
 */
void Library::addBookCLI() {
	//limpa o ecra
	utils::clearConsoleScreen();

	cout << "#### Registo de livros ####\n\n";


	//***********************************************  <title>  ********************************************
	bool invalidTitle = false;
	string title;

	//obten��o do titulo a dar ao novo livro
	do {
		cout << "Titulo: ";

		string titleTemp = utils::getlineCin();

		if (titleTemp.size() > BOOK_TITLE_SIZE) {
			cout << "Introduza um titulo com menos de " << BOOK_TITLE_SIZE << " caracteres!!\n\n";
			invalidTitle = true;
		} else {
			invalidTitle = false;
			title = titleTemp;
		}
	} while (invalidTitle);
	//***********************************************  </title>  ********************************************


	//***********************************************  <author>  ********************************************
	bool invalidAuthor = false;
	string author;

	//obten��o do autor(es) a dar ao novo livro
	do {
		cout << "Autor(es): ";

		string authorTemp = utils::getlineCin();

		if (authorTemp.size() > BOOK_AUTHOR_SIZE) {
			cout << "Introduza o nome do(s) autor(es) com menos de " << BOOK_AUTHOR_SIZE << " caracteres!!\n\n";
			invalidAuthor = true;
		} else {
			invalidAuthor = false;
			author = authorTemp;
		}
	} while (invalidAuthor);
	//***********************************************  </author>  ********************************************


	//***********************************************  <quantity>  ********************************************
	int bookQuantity = utils::getIntCin("N�mero de exemplares: ", "Introduza um numero >= 0!!\n");
	//***********************************************  </quantity>  ********************************************


	//cria��o do novo livro
	Book newBook(title, author, bookQuantity);

	//adi��o do livro ao vector<Book>
	this->addBook(newBook);

	//informa��o do utilizador que a adi��o ocorreu com sucesso
	cout << "Livro com titulo " << title << ", autor " << author << " e quantidade " << bookQuantity << " adicionado com sucesso, com o ID: " << newBook.getID() << ".\n";


	//espera por input do user
	utils::getUserInput();

	//limpa a consola
	utils::clearConsoleScreen();
}


/**
 * M�todo que lista todos os utilizadores registados na biblioteca
 */
void Library::listAllUsersCLI() {
	//limpa a consola
	utils::clearConsoleScreen();


	//litagem de todos os users
	this->showUsers();

	cout << endl;

	//espera por input do user
	utils::getUserInput();

	//limpa a consola
	utils::clearConsoleScreen();
}


/**
 * M�todo que lista todos os livros registados na biblioteca
 */
void Library::listAllBooksCLI() {
	//limpa a consola
	utils::clearConsoleScreen();


	//litagem de todos os users
	this->showBooks();

	cout << endl;

	//espera por input do user
	utils::getUserInput();

	//limpa a consola
	utils::clearConsoleScreen();

}


/**
 * M�todo que lista apenas os utilizadores que tenham no seu nome a string que o utilizador introduzir
 */
void Library::searchUserCLI() {
	//limpa a consola
	utils::clearConsoleScreen();


	//******************************************************  <nameFilter>  *******************************************

	//s� pede a string a pesquisar se houver utilizadores na biblioteca
	string nameFilter;

	if (!users.empty()) {
		cout << "Escreva os termos pelos quais deseja pesquisar: ";
		nameFilter = utils::getlineCin();
		cout << endl;
	}
	//******************************************************  </nameFilter>  ******************************************

	//litagem de todos os users (se n�o houver users s� mostra a mensagem de erro)
	this->showUsers(nameFilter);

	cout << endl;

	//espera por input do user
	utils::getUserInput();

	//limpa a consola
	utils::clearConsoleScreen();
}


/**
 * M�todo que lista apenas os livros que tenham no seu titulo a string que o utilizador introduzir
 */
void Library::searchBookCLI() {
	//limpa a consola
	utils::clearConsoleScreen();

	//******************************************************  <titleFilter>  *******************************************
	string titleFilter;

	//s� pede a string a pesquisar se houver livros na biblioteca
	if (!books.empty()) {
		cout << "Escreva os termos pelos quais deseja pesquisar: ";
		titleFilter = utils::getlineCin();
		cout << endl;
	}
	//******************************************************  </titleFilter>  *******************************************

	//litagem de todos os livros (se n�o houver livros s� mostra a mensagem de erro)
	this->showBooks(titleFilter);

	cout << endl;

	//espera por input do user
	utils::getUserInput();

	//limpa a consola
	utils::clearConsoleScreen();
}


/**
 * M�todo que permite alterar o estado do utilizador para activo ou inactivo na biblioteca
 * P.S. Utilizadores inactivos n�o podem requesitar livros
 */
void Library::changeUserStateCLI() {
	//limpa a consola
	utils::clearConsoleScreen();

	//mostra todos os users
	this->showUsers();

	//caso n�o exista users o showUsers apenas mostrou a mensagem de erro, como tal espera por input e retorna
	if (users.empty()) {
		//espera por input do user
		utils::getUserInput();

		//limpa a consola
		utils::clearConsoleScreen();

		return;
	}


	//sele��o do user a alterar
	int userID;
	bool invalidID = false;

	do {
		try {
			userID = utils::getIntCin("Qual o utilizador do qual deseja actualizar o estado?: ",
					"Introduza o ID do utilizador do qual pretende alterar o estado!!\n\n");

			User& userToChangeState = this->getRefToUserByID(userID); //lan�a excep��o se id n�o existir


			//se id existe pergunta qual � o novo estado que quer dar ai user
			cout << "1 - Activo\n";
			cout << "2 - Inactivo\n\n";

			int newUserState = utils::getIntCin("Op��o: ", "Introduza uma das op��es acima!\n\n", 1,3); //numero tem que ser >=1 e <3

			//altera��o do estado (s� chega aqui depois do user introduzir ou 1 ou 2)
			if (newUserState == 1) {
				userToChangeState.setActive(true);
			} else {
				userToChangeState.setActive(false);
			}

			//altera��o concluida com sucesso
			cout << "O estado do utilizador " << userToChangeState.getName() << " foi actualizado para " << ((newUserState == 1) ? "activo" : "inactivo") << "!" << endl;
			invalidID = false;

		} catch (ElementDoesntExistsException<IdentNum> &e) {
			cout << "O ID que introduziu n�o existe!!\n\n" << endl;
			invalidID = true;
		}
	} while (invalidID);

	cout << endl;

	//espera por input do user
	utils::getUserInput();

	//limpa a consola
	utils::clearConsoleScreen();
}


/**
 * M�todo que trata da interface CLI para a requesi��o de um livro por parte de um utilizador � biblioteca
 * P.S. S� utilizadores activos podem requesitar livros
 */
void Library::requestBookCLI() {
	//limpa a consola
	utils::clearConsoleScreen();


	//****************************************************  <tests>  ***************************************************************
	//caso n�o exista users, mostra a mensagem de erro, espera por input e retorna
	if (users.empty()) {
		cout << "#### Utilizadores ####\n\n";
		cout << "N�o existem utilizadores na biblioteca!\n\n" << endl;
		//espera por input do user
		utils::getUserInput();

		//limpa a consola
		utils::clearConsoleScreen();

		return;
	}


	//caso n�o existam users activos na biblioteca (ou seja nenhum deles pode requesitar livros)
	//mostra a mensagem de erro, espera por input e retorna
	if (this->countActiveUsers() == 0) {
		cout << "\n\n#### Utilizadores ####\n\n";
		cout << "N�o existem utilizadores activos na biblioteca!!\nComo tal nenhum utilizador pode requesitar livros!!\n\n" << endl;

		//espera por input do user
		utils::getUserInput();

		//limpa a consola
		utils::clearConsoleScreen();

		return;
	}


	//caso n�o exista livros disponiveis para requesitar, mostra a mensagem de erro, espera por input e retorna
	if (this->countAvailableBooks() == 0) {
		cout << "\n\n#### Livros ####\n\n";
		cout << "N�o existem livros dispon�veis para requesitar!!\n\n" << endl;

		//espera por input do user
		utils::getUserInput();

		//limpa a consola
		utils::clearConsoleScreen();

		return;
	}
	//****************************************************  </tests>  ***************************************************************


	//mostra todos os users
	this->showUsers();


	//******************************************  <selec��o do user que vai requesitar o livro>  *************************************************
	int userID;
	User* userThatWillRequestBook = NULL;
	bool userInvalidID = false;

	do {
		try {
			userID = utils::getIntCin("Qual o utilizador que vai efectuar a requesicao?: ",
					"Introduza o ID do utilizador que vai efectuar a requesicao!!\n\n");

			userThatWillRequestBook = (User*)&this->getRefToUserByID(userID); //lan�a excep��o se id n�o existir

			if (!userThatWillRequestBook->isActive()) {
				cout << "O utilizador que seleccionou n�o est� activo na biblioteca!!\nComo tal n�o pode requesitar livros!!\n\n" << endl;
				userInvalidID = true;
			} else {
				userInvalidID = false;
			}

		} catch (ElementDoesntExistsException<IdentNum> &e) {
			cout << "O ID que introduziu n�o existe!!\n\n" << endl;
			userInvalidID = true;
		}
	} while (userInvalidID);
	//******************************************  </selec��o do user que vai requesitar o livro>  ************************************************

	cout << "\n\n" << endl;

	//*************************************************  <selec��o do livro a requesitar>  *******************************************************
	int bookID;
	Book* bookThatWillBeRequest = NULL;
	bool bookInvalidID = false;

	//mostra os livros disponiveis
	this->showAvailableBooks();


	do {
		try {
			bookID = utils::getIntCin("Qual o livro que o utilizador deseja requesitar?: ",
					"Introduza o ID do livro pretende requesitar!!\n\n");

			bookThatWillBeRequest = (Book*)&this->getRefToBookByID(bookID); //lan�a excep��o se id n�o existir

			//os livros sem exemplares disponiveis n�o podem ser requesitados
			//n�o s�o mostrados os livros com disponibilidade 0, mas isso n�o impede o utilizador de meter ids que n�o s�o mostrados...
			if (bookThatWillBeRequest->getNumAvailable() == 0) {
				cout << "O livro que introduziu n�o possui exemplares dispon�veis!!\n\n";
				bookInvalidID = true;
			} else {
				bookInvalidID = false;
			}

		} catch (ElementDoesntExistsException<IdentNum> &e) {
			cout << "O ID que introduziu n�o existe!!\n\n" << endl;
			bookInvalidID = true;
		}
	} while (bookInvalidID);
	//*************************************************  </selec��o do livro a requesitar>  *******************************************************


	//efectua a requesi��o do livro
	userThatWillRequestBook->borrowBook(bookID);

	//diminui o n�mero de exemplares do livro requesitado
	bookThatWillBeRequest->loanBook();


	//mostra a mensagem de requesi��o com sucesso
	cout << "\nRequesi��o efectuada com sucesso!";

	cout << endl;

	//espera por input do user
	utils::getUserInput();

	//limpa a consola
	utils::clearConsoleScreen();
}


/**
 * M�todo que trata da devolu��o de um livro por parte de um utilizador � biblioteca
 * P.S. Utilizadores inactivos podem retornar livros mas n�o podem requesitar
 */
void Library::returnBookCLI() {
	//limpa a consola
	utils::clearConsoleScreen();


	//****************************************************  <tests>  ***************************************************************
	//caso n�o exista livros registados na biblioteca, n�o faz sentido fazer retorna...
	//como tal mostra a mensagem de erro, espera por input e retorna
	if (this->books.size() == 0) {
		cout << "\n\n#### Livros ####\n\n";
		cout << "N�o existem livros registados na biblioteca!!\n\n" << endl;

		//espera por input do user
		utils::getUserInput();

		//limpa a consola
		utils::clearConsoleScreen();

		return;
	}


	//caso n�o exista users, mostra a mensagem de erro, espera por input e retorna
	if (users.empty()) {
		cout << "#### Utilizadores ####\n\n";
		cout << "N�o existem utilizadores na biblioteca!\n\n" << endl;
		//espera por input do user
		utils::getUserInput();

		//limpa a consola
		utils::clearConsoleScreen();

		return;
	}

	//se n�o houver utilizadores com livros requesitados, mostra uma mensagem de erro, espera por input e retorna
	if (this->countUsersWithRequestedBooks() == 0) {
		cout << "#### Utilizadores ####\n\n";
		cout << "Nenhum dos utilizadores tem livros requesitados!!\n\n" << endl;

		//espera por input do user
		utils::getUserInput();

		//limpa a consola
		utils::clearConsoleScreen();

		return;
	}
	//****************************************************  </tests>  ***************************************************************

	//mostra todos os users
	this->showUsers();


	//******************************************  <selec��o do user que vai devolver o livro>  *************************************************
	int userID;
	User* userThatWillReturnBook = NULL;
	bool userInvalidID = false;

	do {
		try {
			userID = utils::getIntCin("Qual o utilizador que vai devolver o livro?: ", "Introduza o ID do utilizador que vai devolver o livro!!\n\n");

			userThatWillReturnBook = (User*)&this->getRefToUserByID(userID); //lan�a excep��o se id n�o existir

			//se o user existir verifica se tem livros requesitados
			if (userThatWillReturnBook->hasBooksRequested()) {
				userInvalidID = false;
			} else {
				cout << "\nERRO! Esse utilizador n�o tem nenhum livro a devolver!\n\n";
				userInvalidID = true; //n�o tem livros para devolver
			}

		} catch (ElementDoesntExistsException<IdentNum> &e) {
			cout << "O ID que introduziu n�o existe!!\n\n" << endl;
			userInvalidID = true;
		}
	} while (userInvalidID);
	//******************************************  </selec��o do user que vai devolver o livro>  ************************************************

	cout << "\n\n" << endl;

	//*************************************************  <selec��o do livro a devolver>  *******************************************************
	int bookID;
	Book* bookThatWillBeReturned = NULL;
	bool bookInvalidID = false;

	//mostra os livros que o utilizador selecionado requesitou
	this->showUserBooks(userThatWillReturnBook->getRequestedBooks());

	do {
		try {
			bookID = utils::getIntCin("Qual o livro que quer devolver?: ", "Introduza o ID do livro pretende devolver!!\n\n");

			bookThatWillBeReturned = (Book*)&this->getRefToBookByID(bookID); //lan�a excep��o se id n�o existir

			//o livro existe
			bookInvalidID = false;

		} catch (ElementDoesntExistsException<IdentNum> &e) {
			cout << "O ID que introduziu n�o existe!!\n\n" << endl;
			bookInvalidID = true;
		}
	} while (bookInvalidID);
	//*************************************************  </selec��o do livro a requesitar>  *******************************************************


	//efectua a devolu��o do livro
	userThatWillReturnBook->returnBook(bookThatWillBeReturned->getID());

	//diminui o n�mero de exemplares do livro requesitado
	bookThatWillBeReturned->returnBook();

	//mostra a mensagem de requesi��o com sucesso
	cout << "\nDevolu��o efectuada com sucesso!";


	cout << endl;

	//espera por input do user
	utils::getUserInput();

	//limpa a consola
	utils::clearConsoleScreen();
}
//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>   <CLI interface>   <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<




//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>   <contagens>   <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
/**
 * M�todo que conta o n�mero de livros dispon�veis para serem requesitados
 * @return N�mero de livros na biblioteca prontos a serem requesitados
 */
size_t Library::countAvailableBooks() {
	size_t numAvailableBooks = 0;

	for (size_t i = 0; i < books.size(); ++i) {
		if (books[i].getNumAvailable() > 0) {
			++numAvailableBooks;
		}
	}

	return numAvailableBooks;
}


/**
 * M�todo que conta o n�mero de utilizadores que tem livros requesitados
 * @return N�mero de utilizadores que devem retornar livros
 */
size_t Library::countUsersWithRequestedBooks() {
	size_t usersWithRequestedBooks = 0;

	for (size_t i = 0; i < users.size(); ++i) {
		if (users[i].hasBooksRequested()) {
			++usersWithRequestedBooks;
		}
	}

	return usersWithRequestedBooks;
}


/**
 * M�todo que conta o n�mero de utilizadores activos que existem na biblioteca
 * @return N�mero de utilizadores que podem requesitar livros
 */
size_t Library::countActiveUsers() {
	size_t activeUsers = 0;

	for (size_t i = 0; i < users.size(); ++i) {
		if (users[i].isActive()) {
			++activeUsers;
		}
	}

	return activeUsers;
}
//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>   </contagens>   <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
