#include "Object.h"
#include "Ball.h"
#include "Paddle.h"

class World{

	public:
		World();
		~World();
		void Update(const float& deltaTime);
		void Render(const Camera& camera);

	private:
		GLuint numBalls, numPaddles;
		Ball* balls;
		Paddle* paddles;
};