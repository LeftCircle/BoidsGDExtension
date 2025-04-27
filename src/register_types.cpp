#include "register_types.h"

#include "gdexample.h"

#include <gdextension_interface.h>
#include <godot_cpp/core/defs.hpp>
#include <godot_cpp/godot.hpp>

using namespace godot;

// void initialize_example_module(ModuleInitializationLevel p_level) {
// 	if (p_level != MODULE_INITIALIZATION_LEVEL_SCENE) {
// 		return;
// 	}

// 	GDREGISTER_RUNTIME_CLASS(GDExample);
// }

// void uninitialize_example_module(ModuleInitializationLevel p_level) {
// 	if (p_level != MODULE_INITIALIZATION_LEVEL_SCENE) {
// 		return;
// 	}
// }

// extern "C" {
// // Initialization.
// GDExtensionBool GDE_EXPORT example_library_init(GDExtensionInterfaceGetProcAddress p_get_proc_address, const GDExtensionClassLibraryPtr p_library, GDExtensionInitialization *r_initialization) {
// 	godot::GDExtensionBinding::InitObject init_obj(p_get_proc_address, p_library, r_initialization);

// 	init_obj.register_initializer(initialize_example_module);
// 	init_obj.register_terminator(uninitialize_example_module);
// 	init_obj.set_minimum_library_initialization_level(MODULE_INITIALIZATION_LEVEL_SCENE);

// 	return init_obj.init();
// }
// }

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