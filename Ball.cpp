#include "Ball.h"

Ball::Ball() : Object(){
	LoadTriangles(2, 0, GL_TRIANGLE_STRIP);
	SetScale(vec3(0.025f));
	SetVelocity(vec3(1.0f, 0.0f, 0.0f));
}

Ball::~Ball(){

}

void Ball::Update(const float& deltaTime){
	position += velocity * deltaTime;

	/*if(position.x > 1.5f){
		position.x = 1.5f - (position.x - 1.5f);
		velocity.x = -velocity.x;
	}
	else if(position.x < -1.5f){
		position.x = -1.5f - (position.x + 1.5f);
		velocity.x = -velocity.x;
	}*/

	Object::Update(deltaTime);
}

vec3 Ball::GetVelocity(){
	return velocity;
}

void Ball::SetVelocity(vec3 velocity){
	this->velocity = velocity;
}