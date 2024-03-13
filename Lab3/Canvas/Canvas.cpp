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
			w[i][j] = '.';
	}
}
void Canvas::DrawCircle(int x, int y, int ray, char ch) {
	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			int dist = (i - x)* (i - x) + (j - y) * (j - y);
			if (dist >= ray * (ray - 1) && dist <= ray * (ray + 1))
				SetPoint(x, y, ch);
		}
	}
}
void Canvas::FillCircle(int x, int y, int ray, char ch) {
	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			int dist = (i - x) * (i - x) + (j - y) * (j - y);
			if (dist <= ray * ray)
				SetPoint(x, y, ch);
		}
	}
}
void Canvas::DrawRect(int left, int top, int right, int bottom, char ch) {
	for (int j = left; j <= right; j++) {
		SetPoint(top, j, ch);
		SetPoint(bottom, j, ch);
	}
	for (int i = top; i <= bottom; i++) {
		SetPoint(i, left, ch);
		SetPoint(bottom, right, ch);
	}

}
void Canvas::FillRect(int left, int top, int right, int bottom, char ch) {
	for (int i = top; i <= bottom; i++) {
		for (int j = left; j <= right; j++)
			SetPoint(i, j, ch);
	}
}
void Canvas::SetPoint(int x, int y, char ch) {
	if (x < 0 || y < 0 || x >= width || y >= height)
		return;
	w[x][y] = ch;
}
void Canvas::DrawLine(int x1, int y1, int x2, int y2, char ch) {
	int sx = (x1 < x2) ? 1 : -1, sy = 1;
	int dx = x2 - x1, dy = y2 - y1;
	if (dy < 0) {
		sy = -1;
		dy = -dy;
	}

	int delta = 2 * dy - dx, y = y1;
	for (int i = x1; i <= x2; i+=sx) {
		SetPoint(y, i, ch);
		if (delta > 0) {
			y+=sy;
			delta += 2 * (dy - dx);
		}
		else
			delta += 2 * dy;
	}
}