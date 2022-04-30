#include "Task212.h"
#include "triangle/Triangle.h"

std::string Task212::getName() {
    return "Занятие № 2_1_2";
}

int Task212::getId() {
    return 212;
}

int Task212::execute() {
    int a, b, c = 0;
    cin >> a >> b >> c;
    Triangle triangle = Triangle(a, b, c);
    cout<<"P = "<<triangle.per()<<endl;
    cout<<"S = "<<triangle.square();
	return EXIT_SUCCESS;
}
