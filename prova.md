---
title: C++ Lucidi 2022
author: Fabrizio Sacco
date: 20 Dic 2021
---
# Nascita del linguaggio

![](img/01.png "B. Stroustrup (AT&T)") [Stroustrup] (AT&T)


Prova [Fabrizio Sacco]

Anni 80: si aggiunsero caratteristiche nuove al [C]

I primi compilatori C++ erano dei traduttori da C++ a C

Il C++ oggi contiene tutti gli elementi del C ANSI


[Fabrizio Sacco]: http://fabriziosacco.it
[Stroustrup]: https://www.stroustrup.com/

## Primo programma in C++

```c
/* Ecco un esempio di I/O in C */
https://aoc.csed22.com/
#include <stdio.h>
int main()
{
	int i;
	long l;
	printf(" Due numeri ..");
	scanf("%d",&i);
	scanf("%ld",&i);
	printf("Numeri: %d %ld",i,l);
	return 0;
}
```

## Lo stesso in C++
```cpp
#include <iostream>
using namespace std;
int main()
{
	int i;
	long l;
	cout << " Due numeri ..";
	cin >> i;
	cin >> l;
	cout << "Numeri: " << i << " " << l;
	return 0;
}
```
## Esempio tabellina (visualizza anche numero di linee)
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ {.cpp .numberLines}
#include <iostream>
using namespace std;
int main(void)
{
	int tabel;
	cout << "Tabellina del..";
	cin >> tabel;
	for(int cont = 1; cont <= 10; cont++)
		cout << tabel << " per " << cont << " fa " << cont * tabel << "\n";
	return 0;
}
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ 

## Prova codice lungo (albero)
```cpp
// F. Sacco 15 feb 2021
#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;

template <typename T> struct nodo { /// nodo con T tipo qualsiasi
	T t; /// t e' un tipo generalizzato:
/// un float, una struct, una classe, etc.
	nodo<T> *sin,*des; /// puntatori al sottoalbero di sinistra e di destra
};

template<typename T> class albero {
		nodo<T> *r; /// Puntatore alla radice deell'albero
		
	public:
		albero() {
			r = NULL; /// r== radice dell'albero
		} /// costruttore
		
	private: // metodi interni, per semplificare quelli pubblici
		void inserisci(nodo <T> * &r, T elem ) { // crea BST
			if(r==NULL) {
				r = new nodo<T>;
				r->t = elem;
				r->sin = r->des = NULL;
			} else {
				if (elem > r->t)
					inserisci(r->des,elem);
				else
					inserisci(r->sin,elem);
			}
		}
		
		void visita(nodo <T> *r) { // visita in ordine nel BST
			if (r != NULL) {
				visita(r->sin);
				cout << r->t << endl;
				visita(r->des);
			}
		}
		
		nodo<T> *ricerca(nodo <T> *r, T dato) { // ricerca dato
			if (r== NULL || r->t == dato) // Occorre overload ==?
				return r;
			else if (dato > r->t)
				return ricerca(r->des,dato);
			else
				return ricerca(r->sin,dato);
		}
		
	public: // front end: metodi pubblici semplici!!!
		void insert(T elem) {
			inserisci (this->r, elem);
		}
		
		void visit() {
			visita(this->r);
		}
		
		bool find(T dato) {
			return ricerca(this->r,dato) != NULL;
		}
		
		friend ostream& operator<<(ostream& out, class albero &a)
/// overload << su classe Template albero
		{
			a.visit();
			return out;
		}
}; /// fine dichiarazione classe Template albero
```
