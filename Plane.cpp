#include "Plane.h"

Plane::Plane(GLuint width, GLuint height) : Object(){
	BuildTriangleStrip(this->width = width, this->height = height, false);
	//BuildTriangles(this->width = width, this->height = height, true);
}

Plane::~Plane(){
	
}