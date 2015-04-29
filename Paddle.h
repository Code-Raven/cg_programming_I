#include "Object.h"

#pragma once

class Paddle : public Object{
	
	public:
		Paddle();
		~Paddle();

		void Update(const float& deltaTime);
		void SetKeys(const int& upKey, const int&downKey);

	private:
		int upKey, downKey;
};