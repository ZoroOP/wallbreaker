#ifndef ENTITY_HPP
#define ENTITY_HPP

#include <SFML/Graphics/Sprite.hpp>

class Ball;
class Paddle;
class Brick;

/**
 * Base class for game entities
 */
class Entity: public sf::Sprite
{
public:
	Entity();
	virtual ~Entity() {}

	// callbacks ---------------------------------------------------------------

	virtual void onUpdate(float frametime) = 0;

	virtual void onCollide(const Paddle&) {}

	bool collidesWith(const Entity& other) const;

	virtual void onBrickHit(Brick& brick, const sf::Vector2f& previous_pos) {};

	virtual void onCeilHit() {}

	virtual void onWallHit() {}

	// position helpers --------------------------------------------------------

	inline float getX() const { return getPosition().x; }
	inline float getY() const { return getPosition().y; }
	inline void setX(float x) { setPosition(x, getPosition().y); }
	inline void setY(float y) { setPosition(getPosition().x, y); }

	// size

	float getWidth() const;
	float getHeight() const;

	sf::IntRect getCollisionRect() const;

	inline void kill() { m_alive = false; }
	inline bool isAlive() const { return m_alive; }

private:
	bool m_alive;
};

#endif // ENTITY_HPP
