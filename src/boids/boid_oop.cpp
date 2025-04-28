#include "boid_oop.h"

using namespace godot;
// Vector3 position;
// Vector3 velocity;
// float max_speed = 5.0f;
// float neighbor_distance = 5.0f;
// float separation_weight = 1.5f;
// float alignment_weight = 1.0f;
// float cohesion_weight = 1.0f;
void BoidOOP::_bind_methods() {
	ClassDB::bind_method(D_METHOD("set_position", "position"), &BoidOOP::set_position);
	ClassDB::bind_method(D_METHOD("get_position"), &BoidOOP::get_position);
	ClassDB::bind_method(D_METHOD("set_velocity", "velocity"), &BoidOOP::set_velocity);
	ClassDB::bind_method(D_METHOD("get_velocity"), &BoidOOP::get_velocity);
	ClassDB::bind_method(D_METHOD("set_max_speed", "max_speed"), &BoidOOP::set_max_speed);
	ClassDB::bind_method(D_METHOD("get_max_speed"), &BoidOOP::get_max_speed);
	ClassDB::bind_method(D_METHOD("set_neighbor_distance", "distance"), &BoidOOP::set_neighbor_distance);
	ClassDB::bind_method(D_METHOD("get_neighbor_distance"), &BoidOOP::get_neighbor_distance);
	ClassDB::bind_method(D_METHOD("set_separation_weight", "weight"), &BoidOOP::set_separation_weight);
	ClassDB::bind_method(D_METHOD("get_separation_weight"), &BoidOOP::get_separation_weight);
	ClassDB::bind_method(D_METHOD("set_alignment_weight", "weight"), &BoidOOP::set_alignment_weight);
	ClassDB::bind_method(D_METHOD("get_alignment_weight"), &BoidOOP::get_alignment_weight);
	ClassDB::bind_method(D_METHOD("set_cohesion_weight", "weight"), &BoidOOP::set_cohesion_weight);
	ClassDB::bind_method(D_METHOD("get_cohesion_weight"), &BoidOOP::get_cohesion_weight);
	ClassDB::bind_method(D_METHOD("update", "delta"), &BoidOOP::update);
	ClassDB::bind_method(D_METHOD("find_neighbors", "boids", "neighbor_difference"), &BoidOOP::find_neighbors);

	ADD_PROPERTY(PropertyInfo(Variant::VECTOR3, "position"), "set_position", "get_position");
	ADD_PROPERTY(PropertyInfo(Variant::VECTOR3, "velocity"), "set_velocity", "get_velocity");
	ADD_PROPERTY(PropertyInfo(Variant::FLOAT, "max_speed"), "set_max_speed", "get_max_speed");
	ADD_PROPERTY(PropertyInfo(Variant::FLOAT, "neighbor_distance"), "set_neighbor_distance", "get_neighbor_distance");
	ADD_PROPERTY(PropertyInfo(Variant::FLOAT, "separation_weight"), "set_separation_weight", "get_separation_weight");
	ADD_PROPERTY(PropertyInfo(Variant::FLOAT, "alignment_weight"), "set_alignment_weight", "get_alignment_weight");
	ADD_PROPERTY(PropertyInfo(Variant::FLOAT, "cohesion_weight"), "set_cohesion_weight", "get_cohesion_weight");
}

BoidOOP::BoidOOP() {}
BoidOOP::~BoidOOP() {}


const std::vector<const BoidOOP*> BoidOOP::find_neighbors(const std::vector<BoidOOP> &boids) const {
	std::vector<const BoidOOP*> neighbors;
	int n_boids = boids.size();
	for (int i = 0; i < n_boids; ++i) {
		const BoidOOP& other = boids[i];
		if (other.get_position() == position) continue;
		float dist = position.distance_to(other.get_position());
		if (dist < neighbor_distance) {
			neighbors.push_back(&boids[i]);
		}
	}
	return neighbors;
}


void BoidOOP::set_position(const Vector3 &p_position) {
	position = p_position;
}

Vector3 BoidOOP::get_position() const {
	return position;
}

void BoidOOP::set_velocity(const Vector3 &p_velocity) {
	velocity = p_velocity;
}

Vector3 BoidOOP::get_velocity() const {
	return velocity;
}

void BoidOOP::set_max_speed(float p_max_speed) {
	max_speed = p_max_speed;
}

float BoidOOP::get_max_speed() const {
	return max_speed;
}

void BoidOOP::set_neighbor_distance(float p_distance) {
	neighbor_distance = p_distance;
}

float BoidOOP::get_neighbor_distance() const {
	return neighbor_distance;
}

void BoidOOP::set_separation_weight(float p_weight) {
	separation_weight = p_weight;
}

float BoidOOP::get_separation_weight() const {
	return separation_weight;
}

void BoidOOP::set_alignment_weight(float p_weight) {
	alignment_weight = p_weight;
}

float BoidOOP::get_alignment_weight() const {
	return alignment_weight;
}

void BoidOOP::set_cohesion_weight(float p_weight) {
	cohesion_weight = p_weight;
}

float BoidOOP::get_cohesion_weight() const {
	return cohesion_weight;
}

