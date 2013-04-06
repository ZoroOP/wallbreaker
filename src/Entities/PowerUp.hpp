#ifndef POWERUP_HPP
#define POWERUP_HPP

#include "Entity.hpp"

class PlayerPad;

class PowerUp: public Entity
{
public:
	enum Type
	{
		SMALL_PADDLE,  // Shrinks the paddle
		LARGE_PADDLE,  // Grows the paddle
		STICKY_PADDLE, // Ball stick to the paddle
		LASER_PADDLE,  // Paddle shoots lasers
		TRIPLE_BALL,   // +2 balls
		POWER_BALL,    // Ball goes through bricks (lasts 10 bricks)
		EXTRA_LIFE,    // +1 life
		BLACKOUT       // Bricks are invisible (lasts 20 sec)
	};

	/**
	 * Alocate a new power up with a random type
	 */
	static PowerUp* createRandom();

	PowerUp(Type type);

	void onPaddleHit(Paddle& paddle);

	void onUpdate(float frametime);

private:
	Type m_type;
};

#endif // POWERUP_HPP
