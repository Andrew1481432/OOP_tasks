#include "Task114.h"

std::string Task114::getName() {
    return "Занятие № 1_1_4";
}

int Task114::getId() {
    return 114;
}


/**
 * Программа демонстрирует работу
 * условного оператора и построение
 * логического выражения.
 * Написать программу, которая проверяет,
 * принадлежит или нет введенный символ английскому алфавиту.
 * Если принадлежит, то проверяет, является ли введенный символ гласным или
 * согласным английского алфавита.
 */
int Task114::execute() {
	char c;
	std::cin>>c;
	if (c>='A'&&c<='Z'||c>='a'&&c<='z'){
		if (c=='A'||c=='a'||
		    c=='E'||c=='e'||
		    c=='I'||c=='i'||
		    c=='O'||c=='o'||
		    c=='U'||c=='u'||
		    c=='Y'||c=='y') {
			std::cout<<"vowel";
		} else std::cout<<"consonant";
	} else std::cout<<"Not letter";
	return EXIT_SUCCESS;
}
