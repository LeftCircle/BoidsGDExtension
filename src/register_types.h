#ifndef GDEXAMPLE_REGISTER_TYPES_H
#define GDEXAMPLE_REGISTER_TYPES_H

#include <godot_cpp/core/class_db.hpp>

using namespace godot;

//void initialize_example_module(ModuleInitializationLevel p_level);
//void uninitialize_example_module(ModuleInitializationLevel p_level);

// from https://github.com/willroberts/godot-cpp-gdextension/blob/main/src/register_types.h
void initialize_gdextension_types(ModuleInitializationLevel p_level);
void uninitialize_gdextension_types(ModuleInitializationLevel p_level);

#endif // GDEXAMPLE_REGISTER_TYPES_H