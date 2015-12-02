#include "Globals.h"
#define VOLCANO "/Users/BrittanyFactura/Desktop/Fall Quarter/CSE 167/projects/final project/BubbleVolcano.obj"


Camera Globals::camera;

Cube Globals::cube(10.0);

Sphere Globals::sphere(10.0, 30.0, 30.0);

House Globals::house(10.0);

Light Globals::light;

DrawData Globals::drawData;
UpdateData Globals::updateData;

//OBJObjects
//OBJObject Globals::bunny("");
//OBJObject Globals::dragon("");
//OBJObject Globals::bear("");
//OBJObject Globals::bunny("/Users/BrittanyFactura/Desktop/Fall\ Quarter/CSE\ 167/project\ 1/bunny.obj");
//OBJObject Globals::dragon("/Users/BrittanyFactura/Desktop/Fall\ Quarter/CSE\ 167/project\ 1/dragon.obj");
//OBJObject Globals::bear("/Users/BrittanyFactura/Desktop/Fall\ Quarter/CSE\ 167/project\ 1/bear.obj");


OBJObject Globals::volcano(VOLCANO);

Drawable *Globals::objdraw = &volcano;

//Lights
DirectionalLight Globals::directionlight = DirectionalLight();
SpotLight Globals::spotlight = SpotLight();
PointLight Globals::pointlight = PointLight();