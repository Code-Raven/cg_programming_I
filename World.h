#include "Object.h"
#include "Plane.h"
#include "Ball.h"
#include "Paddle.h"

#pragma once

#define LEVEL_0 "level_0.txt"

class World{

	public:
		World();
		virtual ~World();

		void Update(const float& deltaTime);
		void Render(const Camera& camera);
		
	private:
		Plane* plane;
		const char* loadedFile;
		const char* loadedLevel;
		unsigned char FindChar(const char* buffer, const char& c);
};