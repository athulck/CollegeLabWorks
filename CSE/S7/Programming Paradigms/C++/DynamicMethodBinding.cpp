/**/

#include <iostream>


class Person {

	public:

		// For Dynamic Method binding, uncomment the below line and comment the line below that.
		// virtual void print_mailing_list() {
		
		void print_mailing_list() {
			std::cout<<"\nPerson : Mailing List";
		}

		// Abstract Method
		// virtual void print_mailing_list() = 0;
};


class Student : public Person {

	public:

		void print_mailing_list() {
			std::cout<<"\nStudent : Mailing List";
		}
};

class Professor : public Person {

	public:

		void print_mailing_list() {
			std::cout<<"\nProfessor : Mailing List";
		}
};



int main() {

	Student s;
	Professor p;

	Person *x = &s;
	Person *y = &p;


	s.print_mailing_list();
	p.print_mailing_list();

	x->print_mailing_list();
	y->print_mailing_list();

}
