#include "register_types.h"

#include "gdexample.h"
#include "boids/boids.h"
#include "boids/boid_oop.h"
#include "boids/boid_system.h"

#include <gdextension_interface.h>
#include <godot_cpp/core/defs.hpp>
#include <godot_cpp/godot.hpp>
#include <godot_cpp/classes/engine.hpp>
#include <godot_cpp/core/class_db.hpp>


using namespace godot;


void initialize_gdextension_types(ModuleInitializationLevel p_level) {
	if (p_level != MODULE_INITIALIZATION_LEVEL_SCENE) {
		return;
	}
	//GDREGISTER_CLASS(Summator);
	//GDREGISTER_CLASS(TrafficLight);
	// Use GDREGISTER_RUNTIME_CLASS to avoid in-editor execution.
	// Can also use if (Engine->get_singleton()->is_editor_hint()) to isolate editor code.
	//GDREGISTER_RUNTIME_CLASS(Player);
	GDREGISTER_RUNTIME_CLASS(GDExample);
	//GDREGISTER_RUNTIME_CLASS(Boids);
	GDREGISTER_RUNTIME_CLASS(BoidOOP);
	GDREGISTER_RUNTIME_CLASS(BoidSystem);

	Engine::get_singleton()->register_singleton("BoidSystem", memnew(BoidSystem));
}

void uninitialize_gdextension_types(ModuleInitializationLevel p_level) {
	if (p_level != MODULE_INITIALIZATION_LEVEL_SCENE) {
		return;
	}
}

extern "C" {
// Initialization
GDExtensionBool GDE_EXPORT example_library_init(GDExtensionInterfaceGetProcAddress p_get_proc_address, GDExtensionClassLibraryPtr p_library, GDExtensionInitialization *r_initialization) {
	GDExtensionBinding::InitObject init_obj(p_get_proc_address, p_library, r_initialization);
	init_obj.register_initializer(initialize_gdextension_types);
	init_obj.register_terminator(uninitialize_gdextension_types);
	init_obj.set_minimum_library_initialization_level(MODULE_INITIALIZATION_LEVEL_SCENE);

	return init_obj.init();
}
}