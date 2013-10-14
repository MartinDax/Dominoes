/**\file book.cpp
 * \brief Ficheiro com a implementa��o da classe book.
 *
 * PROJECTO: Projecto 1 - Programa��o - 10-11 - MIEIC\n
 * FICHEIRO: book.cpp \n
 * DESCRI��O: Ficheiro com a implementa��o da classe book que representa um dado livro numa dada biblioteca. \n
 *
 * AUTOR:
 * - Carlos Miguel Correia da Costa
 */

#include "book.h"



//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>   <init-variables>   <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
/**
 * Inicializa��o do static data member que conta o n�mero de livros que foram criados at� um dado momento
 * de forma a poder atribuir um id �nico a cada um.
 */
IdentNum Book::numBooks = 0;
//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>   </init-variables>   <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<



//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>   <constructors>   <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
/**
 * Constructor por default que cria um livro com um titulo da forma <"Unknown title of book with id: " + ID>,
 * com o autor da forma <"Unknown author of book with id: " + ID> e com 0 exemplares
 */
Book::Book() : ID(++numBooks), title("Unknown title of book"), author("Unknown author of book"), numAvailable(0) {}

/**
 * Constructor de Book que cria um novo livro com o titulo, autor e n�mero de exemplares que � forneciido
 * @param bookTitle T�tulo a atribuir ao livro
 * @param bookAuthor Autor a atribuir ai livro
 * @param bookQuantity N�mero de exemplares que este livro tem
 */
Book::Book(string bookTitle, string bookAuthor, unsigned int bookQuantity) : ID(++numBooks), title(bookTitle), author(bookAuthor), numAvailable(bookQuantity) {}
//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>   </constructors>   <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<



//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>   <gets>   <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<

/**
 * M�todo que retorna o n�mero de livros que foram criados at� agora
 * @return Numero de livros criados at� ao momento
 */
IdentNum Book::getNumBooks() {
	return Book::numBooks;
}

/**
 * M�todo que devolve o ID do livro
 * @return Retorna o ID do livro
 */
IdentNum Book::getID() const {
	return ID;
}

/**
 * M�todo que devolve o titulo do livro
 * @return Retorna o t�tulo do livro
 */
string Book::getTitle() const {
	return title;
}

/**
 * M�todo que devolve o(s) autor(es) do livro
 * @return Retorna o(s) autor(es) do livro
 */
string Book::getAuthor() const {
	return author;
}

/**
 * M�todo que devolve o n�mero de exemplares dispon�veis do livro
 * @return Retorna o n� de exemplares.
 */
unsigned int Book::getNumAvailable() const {
	return numAvailable;
}
//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>   </gets>   <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<



//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>   <sets>   <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
/**
 * M�todo que altera o ID do livro para o bookID dado
 * @param bookID ID a atribuir ao livro
 */
void Book::setID(IdentNum bookID) {
	ID = bookID;
}

/**
 * M�todo que altera o t�tulo do livro para o bookTitle dado
 * @param bookTitle T�tulo a atribuir ao livro
 */
void Book::setTitle(string bookTitle) {
	title = bookTitle;
}

/**
 * M�todo que altera o(s) autor(es) do livro para o bookAuthor dado
 * @param bookAuthor Autor(es) a atribuir ao livro
 */
void Book::setAuthor(string bookAuthor) {
	author = bookAuthor;
}

/**
 * M�todo que altera o n�mero de exemplares do livro para o numBooks dado
 * S� altera se numBooks >= 0
 * @param numBooks N�mero de exemplares a atribuir ao livro
 */
void Book::setNumAvailable(unsigned int numBooks) {
	if (numBooks >= 0) {
		numAvailable = numBooks;
	}
}

/**
 * M�todo que modifica a vari�vel est�tica numBooks para o "num" dado desde que "num" n�o seja inferior ao valor de numBooks,
 * visto que n�o havendo elimina��o de livros, caso numBooks fosse alterado para um n�mero inferior haveria livros com o mesmo id,
 * o que deve ser evitado
 * @param num N�mero de livros que foram criados at� ao momento na bilioteca (tem que ser > que o numBooks actual)
 */
void Book::setNumBooks(IdentNum num) {
	if (num > numBooks) {
		numBooks = num;
	}
}
//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>   </sets>   <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<



//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>   <bookManagement>   <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
/**
 * M�todo que acrescenta bookQuantity aos exemplares do livro
 * @param bookQuantity N�mero de exemplares a acrescentar aos actuais deste livro
 */
void Book::addBooks(int bookQuantity) {
	numAvailable += bookQuantity;
}

/**
 * M�tode que trata do emprestimo de um livro
 * Equivale a diminuir o n�mero de exemplares em uma unidade
 * (nunca passa abaixo de 0)
 */
void Book::loanBook() {
	if (numAvailable > 0) {
		--numAvailable;
	}
}

/**
 * M�tode que trata do retorno de um livro
 * Equivale a aumentar o n�mero de exemplares em uma unidade
 */
void Book::returnBook() {
	++numAvailable;
}
//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>   </bookManagement>   <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
