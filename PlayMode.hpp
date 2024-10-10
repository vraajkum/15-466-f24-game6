#include "Mode.hpp"

#include "Connection.hpp"
#include "Game.hpp"
#include "Sound.hpp"

#include <glm/glm.hpp>
#include <glm/gtc/random.hpp>

#include <vector>
#include <deque>

struct PlayMode : Mode {
	PlayMode(Client &client);
	virtual ~PlayMode();

	//functions called by main loop:
	virtual bool handle_event(SDL_Event const &, glm::uvec2 const &window_size) override;
	virtual void update(float elapsed) override;
	virtual void draw(glm::uvec2 const &drawable_size) override;

	//----- game state -----

	//input tracking for local player:
	Player::Controls controls;

	//latest game state (from server):
	Game game;

	//last message from server:
	std::string server_message;

	//connection to server:
	Client &client;

	// music:
	std::shared_ptr< Sound::PlayingSample > music_loop;

	// enemy plant variables:
	glm::vec3 plantColor = glm::vec3(0.0f, 1.0f, 0.0f);
	glm::vec2 plantPos = glm::vec2(0.0f, 0.0f);
	float plantSize = 0.01f;
	std::string plantName = "Planty";
	int plantHealth = 5;

};
