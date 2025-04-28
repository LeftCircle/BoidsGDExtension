#include "boids.h"

using namespace godot;

void Boids::_bind_methods() {
    ClassDB::bind_method(D_METHOD("set_boid_count", "count"), &Boids::set_boid_count);
    ClassDB::bind_method(D_METHOD("get_boid_count"), &Boids::get_boid_count);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "boid_count"), "set_boid_count", "get_boid_count");
}

Boids::Boids() {}
Boids::~Boids() {}

void Boids::_ready() {
    boids.clear();
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<float> dist(-10.0f, 10.0f);
    for (int i = 0; i < boid_count; ++i) {
        Boid b;
        b.position = Vector3(dist(gen), dist(gen), dist(gen));
        b.velocity = Vector3(dist(gen), dist(gen), dist(gen)).normalized() * max_speed;
        boids.push_back(b);
    }
}

void Boids::_process(double delta) {
    // Simple boid update (no rendering, just logic)
    for (auto &boid : boids) {
        Vector3 separation, alignment, cohesion;
        int neighbor_count = 0;
        for (const auto &other : boids) {
            if (&boid == &other) continue;
            float dist = boid.position.distance_to(other.position);
            if (dist < neighbor_distance) {
                separation += (boid.position - other.position) / (dist + 0.01f);
                alignment += other.velocity;
                cohesion += other.position;
                neighbor_count++;
            }
        }
        if (neighbor_count > 0) {
            separation = separation / neighbor_count * separation_weight;
            alignment = (alignment / neighbor_count - boid.velocity) * alignment_weight;
            cohesion = ((cohesion / neighbor_count) - boid.position) * cohesion_weight;
            boid.velocity += separation + alignment + cohesion;
        }
        if (boid.velocity.length() > max_speed) {
            boid.velocity = boid.velocity.normalized() * max_speed;
        }
        boid.position += boid.velocity * (float)delta;
    }
}

void Boids::set_boid_count(int count) {
    boid_count = count;
}

int Boids::get_boid_count() const {
    return boid_count;
}
