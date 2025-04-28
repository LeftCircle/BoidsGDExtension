#pragma once

#include <godot_cpp\classes\node.hpp>
#include <godot_cpp\core\binder_common.hpp>
#include <godot_cpp\core\defs.hpp>
#include <godot_cpp\classes\project_settings.hpp>
#include <godot_cpp\variant\utility_functions.hpp>

#include "boid_oop.h"
#include <vector>

namespace godot {	
class BoidSystem : public Node {
	GDCLASS(BoidSystem, Node);

protected:
	static void _bind_methods();

private:
	std::vector<BoidOOP*> boid_oops;

public:
	BoidSystem();
	~BoidSystem();

	void _ready() override;
	void _process(double delta) override;

	void register_boid(BoidOOP &boid);
	void unregister_boid(BoidOOP &boid);

	void update_boids_oop(double delta);
	const std::vector<BoidOOP*>& get_boid_oops() const { return boid_oops; }
};
} // namespace godot