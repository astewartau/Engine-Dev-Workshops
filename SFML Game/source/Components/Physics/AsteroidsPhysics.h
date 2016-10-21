#pragma once
#include "PhysicsComponent.h"
#include "Helpers\Structs.h"

class AsteroidsPhysics : public PhysicsComponent {
public:
	// Setup an Asteroids physics object
	AsteroidsPhysics(sf::Vector2u bounds) {
		_bounds = bounds;
	}

	void Update(sf::Int32 deltaTime) {
		_gameObject->_sprite.move(_gameObject->_velocity.x * deltaTime, _gameObject->_velocity.y * deltaTime);

		auto spritePosition = _gameObject->_sprite.getPosition();
		auto spriteSize = _gameObject->_sprite.getLocalBounds();
		if (spritePosition.x < -spriteSize.width/2.0f) {
			_gameObject->_sprite.setPosition(_bounds.x + spriteSize.width/2.0f, spritePosition.y);
		} else if (spritePosition.x > _bounds.x + spriteSize.width/2.0f) {
			_gameObject->_sprite.setPosition(-spriteSize.width/2.0f, spritePosition.y);
		}

		if (spritePosition.y < -spriteSize.height/2.0f) {
			_gameObject->_sprite.setPosition(spritePosition.x, _bounds.y + spriteSize.height/2.0f);
		} else if (spritePosition.y > _bounds.y + spriteSize.height/2.0f) {
			_gameObject->_sprite.setPosition(spritePosition.x, -spriteSize.height/2.0f);
		}
	}

private:
	sf::Vector2u _bounds;
};