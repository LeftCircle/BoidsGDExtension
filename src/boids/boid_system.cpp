#include "boid_system.h"

using namespace godot;

void BoidSystem::_bind_methods() {
	ClassDB::bind_method(D_METHOD("update_boids_oop", "delta"), &BoidSystem::update_boids_oop);


	ADD_PROPERTY(PropertyInfo(Variant::ARRAY, "boids"), "track_boid", "get_boid_count");
}

BoidSystem::BoidSystem() {}
BoidSystem::~BoidSystem() {}

void BoidSystem::_ready() {
	// Initialize the boids array
	boid_oops.clear();
}

void BoidSystem::_process(double delta) {
	
}

void BoidSystem::register_boid(BoidOOP &boid) {
	// Add the boid to the array
	boid_oops.push_back(boid);
}

void BoidSystem::update_boids_oop(double delta) {
	for (int i = 0; i < boid_oops.size(); ++i) {
		std::vector<const BoidOOP*> neighbors = boid_oops[i].find_neighbors(boid_oops);
		boid_oops[i].update(delta);
	}
}