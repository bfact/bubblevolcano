#include "Globals.h"
#define VOLCANO "/Users/BrittanyFactura/Github/bubblevolcano/BubbleVolcano.obj"
#define VOLCANO_SEAN "/Users/seanwenzel/Github/bubblevolcano/BubbleVolcano.obj"

Camera Globals::camera;

Cube Globals::cube(10.0);

Sphere Globals::sphere(1.0, 30.0, 30.0);

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

std::vector<Texture> Globals::textures;
BubbleCollection Globals::bubbles;

HeightMap Globals::map;

ParticleSystem Globals::particles;

LSystem Globals::tree(4.0);
LSystem Globals::tree1(6.0);
LSystem Globals::tree2(2.0);
LSystem Globals::tree3(5.0);

float Globals::volcanoHeightDisplacement;
bool Globals::rainbow = false;
bool Globals::red = true;
bool Globals::white = false;
