#include "Canvas.h"
Canvas::Canvas(int width, int height) {
	this->width = width;
	this->height = height;

	w = new char* [height];
	for (int i = 0; i < height; i++) {
		w[i] = new char[width];
	}

	Clear();
}

void Canvas::Print() {
	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++)
			std::cout << w[i][j] << ' ';
		std::cout << '\n';
	}
}

void Canvas::Clear() {
	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++)
			w[i][j] = 0;
	}
}