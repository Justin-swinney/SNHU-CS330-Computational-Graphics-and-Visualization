#include "MeshData.h"
#include <GL/glew.h>
#include <iostream>



MeshData::MeshData() {

}
MeshData::~MeshData() {}




/*******************************************************************************************************************************/
	/**************************************************************************************************
	*																								  *
	*   DESK																						  *
	*																								  *
	**************************************************************************************************/
void MeshData::createDeskMesh() {
	indices.clear();
	vertices = {
		// bottom
		-0.5f, 0.0f, -0.4f,		0.0f, 0.0f, 0.0f,		0.0f, 0.0f,	 // A 0
		 0.5f, 0.0f, -0.4f,		0.0f, 0.0f, 0.0f,		0.0f, 0.0f,	 // B 1
		 0.5f, 0.0f, 0.5f,		0.0f, 0.0f, 0.0f,		0.0f, 0.0f,	 // C 2
		-0.5f, 0.0f, 0.5f,		0.0f, 0.0f, 0.0f,		0.0f, 0.0f,	 // D 3

		// top
		 0.5f, 0.2f, 0.5f,		0.0f, 0.0f, 0.0f,		1.0f, 0.0f,	 // E 4
		-0.5f, 0.2f, 0.5f,		0.0f, 0.0f, 0.0f,		0.0f, 0.0f,	 // F 5
		-0.5f, 0.2f, -0.4f,		0.0f, 0.0f, 0.0f,		0.0f, 1.0f,	 // G 6
		 0.5f, 0.2f, -0.4f,		0.0f, 0.0f, 0.0f,		1.0f, 1.0f,	 // H 7

		// bottom sides
		-0.5f, 0.0f, -0.4f,		0.0f, 0.0f, 0.0f,		0.0f, 0.0f,	 // 8
		 0.5f, 0.0f, -0.4f,		0.0f, 0.0f, 0.0f,		0.0f, 0.0f,	 // 9
		 0.5f, 0.0f, 0.5f,		0.0f, 0.0f, 0.0f,		0.0f, 0.0f,	 // 10
		-0.5f, 0.0f, 0.5f,		0.0f, 0.0f, 0.0f,		0.0f, 0.0f,	 // 11

		// top sides
		 0.5f, 0.2f, 0.5f,		0.0f, 0.0f, 0.0f,		0.0f, 0.0f,	 // 12
		-0.5f, 0.2f, 0.5f,		0.0f, 0.0f, 0.0f,		0.0f, 0.0f,	 // 13
		-0.5f, 0.2f, -0.4f,		0.0f, 0.0f, 0.0f,		0.0f, 0.0f,	 // 14
		 0.5f, 0.2f, -0.4f,		0.0f, 0.0f, 0.0f,		0.0f, 0.0f,	 // 15
	};

	indices = {
		// Bottom
		0, 2, 3,
		2, 0, 1,

		// Top
		4, 6, 5,// A, B, C
		4, 5, 6, 
		4, 6, 7,
		4, 7, 6,

		// Side 1
		10, 12, 13,
		10, 13, 11,

		// Side 2
		10, 9, 12,
		9, 15, 12,

		// Side 3 long 
		8, 9, 15,
		8, 14, 15,

		// Side 4 short
		8, 14, 13,
		8, 13, 11,
	};
}
/*******************************************************************************************************************************/
	/**************************************************************************************************
	*																								  *
	*   KEYBOARD		 																			  *
	*																								  *
	**************************************************************************************************/
void MeshData::createKeyboardMesh() {
	indices.clear();
	vertices = {
		// Bottom face
		-0.5f, 0.0f, -0.3f,		1.0f, 1.0f, 1.0f,		0.0f, 1.0f, // 0
		 0.5f, 0.0f, -0.3f,		1.0f, 1.0f, 1.0f,		1.0f, 0.0f, // 1
		 0.5f, 0.0f, 0.3f,		1.0f, 1.0f, 1.0f,		1.0f, 1.0f, // 2
		-0.5f, 0.0f, 0.3f,		1.0f, 1.0f, 1.0f,		0.0f, 0.0f, // 3

		// Top face
		-0.5f, 0.2f, -0.3f,		1.0f, 1.0f, 1.0f,		0.0f, 1.0f, // 4
		 0.5f, 0.2f, -0.3f,	    1.0f, 1.0f, 1.0f,		1.0f, 0.0f, // 5
		 0.5f, 0.2f, 0.3f,		1.0f, 1.0f, 1.0f,		1.0f, 1.0f, // 6
		-0.5f, 0.2f, 0.3f,		1.0f, 1.0f, 1.0f,		0.0f, 0.0f, // 7

		// Right face
		 0.5f, 0.0f, -0.3f,		1.0f, 1.0f, 1.0f,		0.0f, 1.0f, // 8
		 0.5f, 0.2f, -0.3f,		1.0f, 1.0f, 1.0f,		1.0f, 0.0f, // 9
		 0.5f, 0.2f, 0.3f,		1.0f, 1.0f, 1.0f,		1.0f, 1.0f, // 10
		 0.5f, 0.0f, 0.3f,		1.0f, 1.0f, 1.0f,		0.0f, 0.0f, // 11

		// Left face
		 -0.5f, 0.0f, -0.3f,	1.0f, 1.0f, 1.0f,		0.0f, 1.0f, // 12
		 -0.5f, 0.2f, -0.3f,	1.0f, 1.0f, 1.0f,		1.0f, 0.0f, // 13
		 -0.5f, 0.2f, 0.3f,		1.0f, 1.0f, 1.0f,		1.0f, 1.0f, // 14
		 -0.5f, 0.0f, 0.3f,		1.0f, 1.0f, 1.0f,		0.0f, 0.0f, // 15

		// Back face
		 -0.5f, 0.0f, -0.3f,	1.0f, 1.0f, 1.0f,		0.0f, 1.0f, // 16
		 -0.5f, 0.2f, -0.3f,	1.0f, 1.0f, 1.0f,		1.0f, 0.0f, // 17
		  0.5f, 0.2f, -0.3f,	1.0f, 1.0f, 1.0f,		1.0f, 1.0f, // 18
		  0.5f, 0.0f, -0.3f,	1.0f, 1.0f, 1.0f,		0.0f, 0.0f, // 19

		// Front face
		 -0.5f, 0.0f, 0.3f,		1.0f, 1.0f, 1.0f,		0.0f, 1.0f,  // 20
		 -0.5f, 0.2f, 0.3f,		1.0f, 1.0f, 1.0f,		1.0f, 0.0f,  // 21
		  0.5f, 0.2f, 0.3f,		1.0f, 1.0f, 1.0f,		1.0f, 1.0f,  // 22
		  0.5f, 0.0f, 0.3f,		1.0f, 1.0f, 1.0f,		0.0f, 0.0f,  // 23
	};
	indices = {
		// Bottom face
		0, 1, 2,
		0, 2, 3,

		// Top face
		4, 5, 6,
		4, 6, 7,

		// Right face
		8, 9, 10,
		8, 10, 11,

		// Left face
		12, 13, 14,
		12, 14, 15,

		// Back face
		16, 17, 18,
		16, 18, 19,

		// Front face
		20, 21, 22,
		20, 22, 23,
	};
}
/*******************************************************************************************************************************/
	/**************************************************************************************************
	*																								  *
	*   SPACEBAR		 																			  *
	*																								  *
	**************************************************************************************************/
void MeshData::createSpacebarMesh() {
	indices.clear();
	vertices = {
		// Bottom 
		-0.5f, 0.0f, -0.05f,	0.9f, 0.9f, 0.9f,		0.0f, 0.0f, // 1
		 0.5f, 0.0f, -0.05f,	0.9f, 0.9f, 0.9f,		0.0f, 0.0f, // 2
		 0.5f, 0.0f, 0.05f,		0.9f, 0.9f, 0.9f,		0.0f, 0.0f, // 3
		-0.5f, 0.0f, 0.05f,		0.9f, 0.9f, 0.9f,		0.0f, 0.0f, // 4

		// Top
		-0.5f, 0.2f, -0.05f,	0.9f, 0.9f, 0.9f,		0.0f, 1.0f, // 5 M TOP LEFT
		 0.5f, 0.2f, -0.05f,	0.9f, 0.9f, 0.9f,		1.0f, 1.0f, // 6 N TOP RIGHT
		 0.5f, 0.2f, 0.05f,		0.9f, 0.9f, 0.9f,		1.0f, 0.0f, // 7 O  BOT RIGHT
		-0.5f, 0.2f, 0.05f,		0.9f, 0.9f, 0.9f,		0.0f, 0.0f, // 8 P BOT LEFT

		// Side 
		0.5f, 0.0f, -0.05f,		1.0f, 0.0f, 1.0f,		0.0f, 0.0f, // 9
		0.5f, 0.2f, -0.05f,		0.0f, 0.0f, 1.0f,		0.0f, 0.0f, // 10
		0.5f, 0.2f, 0.05f,		1.0f, 1.0f, 1.0f,		0.0f, 0.0f, // 11
		0.5f, 0.0f, 0.05f,		1.0f, 0.0f, 0.0f,		0.0f, 0.0f, // 12

		-0.5f, 0.0f, -0.05f,	1.0f, 0.0f, 1.0f,		0.0f, 0.0f, // 13
		-0.5f, 0.2f, -0.05f,	0.0f, 0.0f, 1.0f,		0.0f, 0.0f, // 14
		-0.5f, 0.2f, 0.05f,		1.0f, 1.0f, 1.0f,		0.0f, 0.0f, // 15
		-0.5f, 0.0f, 0.05f,		1.0f, 0.0f, 0.0f,		0.0f, 0.0f, // 16

		// Front
		-0.5f, 0.0f, 0.05f,		1.0f, 0.0f, 1.0f,		0.0f, 0.0f, // 17
		 0.5f, 0.0f, 0.05f,		0.0f, 0.0f, 1.0f,		0.0f, 0.0f, // 18
		 0.5f, 0.2f, 0.05f,		1.0f, 1.0f, 1.0f,		0.0f, 0.0f, // 19
		-0.5f, 0.2f, 0.05f,		1.0f, 0.0f, 0.0f,		0.0f, 0.0f, // 20

		// Back
		-0.5f, 0.0f, -0.05f,	1.0f, 0.0f, 1.0f,		0.0f, 0.0f, // 21
		 0.5f, 0.0f, -0.05f,	0.0f, 0.0f, 1.0f,		0.0f, 0.0f, // 22
		 0.5f, 0.2f, -0.05f,	1.0f, 1.0f, 1.0f,		0.0f, 0.0f, // 23
		-0.5f, 0.2f, -0.05f,	1.0f, 0.0f, 0.0f,		0.0f, 0.0f, // 24
	};
	indices = {
		// Bottom 
		0, 1, 2,
		0, 2, 3,

		// Top 
		4, 5, 6,
		4, 6, 7,

		// Side 1
		8, 9, 10,
		8, 10, 11,

		// Side 2
		12, 13, 14,
		12, 14, 15,

		// Front
		16, 17, 18,
		16, 18, 19,

		//Back
		20, 21, 22,
		20, 22, 23,
	};
}
/*******************************************************************************************************************************/
	/**************************************************************************************************
	*																								  *
	*   STANDARD KEYS		 																		  *
	*																								  *
	**************************************************************************************************/
void MeshData::createStandardKeysMesh() {
	indices.clear();
	vertices = {
		// BOTTOM 
	   -0.1f, -0.1f, 0.1f,    1.0f, 0.0f, 1.0f,   0.0f, 0.0f,  // 0 A,  BOT LEFT
		0.1f, -0.1f, 0.1f,    1.0f, 0.0f, 1.0f,   0.0f, 0.0f,  // 1 B,  BOT RIGHT
	   -0.1f, -0.1f, -0.1f,   1.0f, 0.0f, 1.0f,   0.0f, 0.0f,  // 2 C, BOTTOM LEFT 
		0.1f, -0.1f, -0.1f,   1.0f, 0.0f, 1.0f,   0.0f, 0.0f,  // 3 D, BOTTOM RIGHT 

		// TOP
	   -0.1f,  0.1f, 0.1f,    1.0f, 0.0f, 1.0f,   0.0f, 0.0f,  // 4 E,  BOTTOM LEFT CORNER TOP FACE
		0.1f,  0.1f, 0.1f,    1.0f, 0.0f, 1.0f,   1.0f, 0.0f,  // 5 F,  BOTTOM RIGHT CORNER TOP FACE
		0.1f,  0.1f, -0.1f,   1.0f, 0.0f, 1.0f,   1.0f, 1.0f,  // 6 G,  TOP RIGHT TOP FACE
	   -0.1f,  0.1f, -0.1f,   1.0f, 0.0f, 1.0f,  0.0f, 1.0f,   // 7 H,   TOP LEFT TOP FACE

	   // SIDES
	   -0.1f, -0.1f, 0.1f,   1.0f, 0.0f, 1.0f,   0.0f, 0.0f,   // 8 I
		0.1f, -0.1f, 0.1f,   0.0f, 0.0f, 1.0f,   0.0f, 0.0f,   // 9 J
		0.1f,  0.1f, 0.1f,   1.0f, 1.0f, 1.0f,   0.0f, 0.0f,   // 10 K
	   -0.1f,  0.1f, 0.1f,   1.0f, 0.0f, 0.0f,   0.0f, 0.0f,   // 11 L

	   -0.1f, -0.1f, -0.1f,  1.0f, 0.0f, 1.0f,   0.0f, 0.0f,   // 12 
		0.1f, -0.1f, -0.1f,  0.0f, 0.0f, 1.0f,   0.0f, 0.0f,   // 13 
		0.1f,  0.1f, -0.1f,  1.0f, 1.0f, 1.0f,   0.0f, 0.0f,   // 14 
	   -0.1f,  0.1f, -0.1f,  1.0f, 0.0f, 0.0f,   0.0f, 0.0f,   // 15 
	};
	indices = {

		// TOP FACE
		7, 6, 5, // H, G, F 
		7, 5, 6, // H, F, G
		7, 4, 5, // H, E, F
		7, 5, 4, // H, F, E

		//BOT FACE
		0, 2, 3,
		0, 3, 2,
		1, 3, 0,
		1, 3, 2,

		// FRONT SIDE FACE
		8, 10, 9,
		8, 9, 10,
		8, 11, 10,
		8, 10, 11,

		// BACK SIDE FACE
		12, 15, 13,
		12, 13, 15,
		13, 15, 14,
		13, 14, 15,

		// SIDE FACE RIGHT
		10, 9, 13,
		10, 13, 9,
		14, 13, 10,
		14, 10, 13,

		// SIDE FACE LEFT
		11, 15, 12,
		11, 12, 15,
		8, 12, 11,
		8, 11, 12,
	};
}
/*******************************************************************************************************************************/
	/**************************************************************************************************
	*																								  *
	*   SHIFT KEY		 																			  *
	*																								  *
	**************************************************************************************************/
void MeshData::createShiftKeyMesh() {
	indices.clear();
	vertices = {
		//BOTTOM
	   -0.21f, -0.1f, 0.1f,		0.8f, 0.8f, 0.8f,		0.0f, 0.0f, // 0 A
		0.21f, -0.1f, 0.1f,		0.8f, 0.8f, 0.8f,		1.0f, 0.0f, // 1 B
	   -0.21f, -0.1f, -0.1f,	0.8f, 0.8f, 0.8f,		0.0f, 0.0f, // 2 C
		0.21f, -0.1f, -0.1f,	0.8f, 0.8f, 0.8f,		0.0f, 0.0f, // 3 D

		// TOP
		0.21f, 0.1f, 0.1f,		0.8f, 0.8f, 0.8f,		1.0f, 0.0f, // 4 E RIGHT FRONT CORNER
	   -0.21f, 0.1f, 0.1f,		0.8f, 0.8f, 0.8f,		0.0f, 0.0f, // 5 F LEFT FRONT CORNER
		0.21f, 0.1f, -0.1f,		0.8f, 0.8f, 0.8f,		1.0f, 1.0f, // 6 G RIGHT BACK CORNER
	   -0.21f, 0.1f, -0.1f,		0.8f, 0.8f, 0.8f,		0.0f, 1.0f, // 7 H LEFT BACK CORNER

		// SIDES BOT
	   -0.21f, -0.1f, 0.1f,		1.0f, 0.0f, 1.0f,		0.0f, 0.0f, // 8 I
		0.21f, -0.1f, 0.1f,		0.0f, 0.0f, 1.0f,		0.0f, 0.0f, // 9 J
	   -0.21f, -0.1f, -0.1f,	1.0f, 1.0f, 1.0f,		0.0f, 0.0f, // 10 K
		0.21f, -0.1f, -0.1f,	1.0f, 0.0f, 0.0f,		0.0f, 0.0f, // 11 L

		// SIDES TOP
		0.21f, 0.1f, 0.1f,		1.0f, 0.0f, 1.0f,		0.0f, 0.0f, // 12 M
	   -0.21f, 0.1f, 0.1f,		0.0f, 0.0f, 1.0f,		0.0f, 0.0f, // 13 N 
		0.21f, 0.1f, -0.1f,		1.0f, 1.0f, 1.0f,		0.0f, 0.0f, // 14 O 
	   -0.21f, 0.1f, -0.1f,		1.0f, 0.0f, 0.0f,		0.0f, 0.0f, // 15 P 
	};
	indices = {
		//BOT
		0, 3, 1, // A, D, B
		0, 1, 3, // A, B, D
		2, 0, 3, // C, A, D
		2, 0, 1, // C, A, B

		// TOP
		4, 7, 6, // E, H, G
		4, 6, 7, // E, G, H
		5, 7, 4, // F, H, E
		5, 7, 6, // F, H, G

		// **SIDES**

		// FRONT
		13, 9, 8, // N, J, I
		13, 8, 9, // N, I, J
		13, 9, 12, // N, J, M
		13, 12, 9, // N, M, J

		// BACK
		15, 11, 10, // P, L, K
		15, 10, 11, // P, K, L
		15, 11, 14, // P, L, O
		15, 14, 11, // P, O, L

		// LEFT
		15, 8, 13, // P, I, N
		15, 13, 8,// P, N, I
		15, 8, 10,  // P, I, K
		15, 10, 8, // P, K, I

		// RIGHT
		12, 11, 9, // M, L, J
		12, 9, 11,// M, J, L
		12, 11, 14, // M, L, O
		13, 14, 11,// M, O, L
	};
}
/*******************************************************************************************************************************/
	/**************************************************************************************************
	*																								  *
	*   LIGHT SOURCE		 																		  *
	*																								  *
	**************************************************************************************************/
void MeshData::createCubeMesh() {
	indices.clear();
	vertices = {
		// BOTTOM 
	   -0.1f, -0.1f, 0.1f,    0.1f, 0.1f, 0.1f,   1.0f, 1.0f,  // 0 A,
		0.1f, -0.1f, 0.1f,    0.1f, 0.1f, 0.1f,   0.0f, 1.0f,  // 1 B,
	   -0.1f, -0.1f, -0.1f,   0.1f, 0.1f, 0.1f,   1.0f, 0.0f,  // 2 C,
		0.1f, -0.1f, -0.1f,   0.1f, 0.1f, 0.1f,   0.0f, 0.0f,  // 3 D, 

		// TOP
	   -0.1f,  0.1f, 0.1f,    0.1f, 0.1f, 0.1f,   1.0f, 1.0f,  // 4 E,
		0.1f,  0.1f, 0.1f,    0.1f, 0.1f, 0.1f,   0.0f, 1.0f,  // 5 F,
		0.1f,  0.1f, -0.1f,   0.1f, 0.1f, 0.1f,   0.0f, 0.0f,  // 6 G,  
	   -0.1f,  0.1f, -0.1f,   0.1f, 0.1f, 0.1f,   0.0f, 1.0f,  // 7 H,

	   // SIDES
	   -0.1f, -0.1f, 0.1f,    0.1f, 0.1f, 0.1f,   1.0f, 1.0f,  // 8 I
		0.1f, -0.1f, 0.1f,    0.1f, 0.1f, 0.1f,   0.0f, 1.0f,  // 9 J
		0.1f,  0.1f, 0.1f,    0.1f, 0.1f, 0.1f,   0.0f, 0.0f,  // 10 K
	   -0.1f,  0.1f, 0.1f,    0.1f, 0.1f, 0.1f,   0.0f, 1.0f,  // 11 L

	   -0.1f, -0.1f, -0.1f,   0.1f, 0.1f, 0.1f,   1.0f, 1.0f,  // 12 
		0.1f, -0.1f, -0.1f,   0.1f, 0.1f, 0.1f,   0.0f, 1.0f,  // 13 
		0.1f,  0.1f, -0.1f,   0.1f, 0.1f, 0.1f,   0.0f, 0.0f,  // 14 
	   -0.1f,  0.1f, -0.1f,   0.1f, 0.1f, 0.1f,   0.0f, 1.0f,  // 15 
	};
	indices = {
		// BOT FACE
		0, 3, 1,
		0, 1, 3,
		0, 3, 2,
		0, 2, 3,

		// TOP FACE
		7, 6, 5, // H, G, F 
		7, 5, 6, // H, F, G
		7, 4, 5, // H, E, F
		7, 5, 4, // H, F, E

		0, 5, 4,
		0, 4, 5,
		0, 5, 1,
		0, 1, 5,

		1, 6, 3,
		1, 3, 6,
		1, 6, 5,
		1, 5, 6,

		2, 6, 3,
		2, 3, 6,
		2, 6, 7,
		2, 7, 6,

		0, 7, 2,
		0, 2, 7,
		0, 7, 4,
		0, 4, 7



	};
}
/*******************************************************************************************************************************/
	/**************************************************************************************************
	*																								  *
	*   MONITOR			 																			  *
	*																								  *
	**************************************************************************************************/
void MeshData::createMonitorMesh() {
	indices.clear();
	vertices = {
		//FRONT
		-1.0f, 1.0f, 0.0f,		0.0f, 0.0f, 0.0f,		0.0f, 0.0f, // 0 A
		-1.0f, 1.5f, 0.0f,		0.0f, 0.0f, 0.0f,		0.0f, 0.0f, // 1 B
		 1.0f, 1.0f, 0.0f,		0.0f, 0.0f, 0.0f,		0.0f, 0.0f, // 2 C
		 1.0f, 1.5f, 0.0f,		0.0f, 0.0f, 0.0f,		0.0f, 0.0f, // 3 D	

		 //TOP
		-1.0f, 1.0f, -0.02f,	0.0f, 0.0f, 0.0f,		0.0f, 0.0f, // 4 E
		-1.0f, 1.5f, -0.02f,	0.0f, 0.0f, 0.0f,		0.0f, 0.0f, // 5 F
		 1.0f, 1.0f, -0.02f,	0.0f, 0.0f, 0.0f,		0.0f, 0.0f, // 6 G
		 1.0f, 1.5f, -0.02f,	0.0f, 0.0f, 0.0f,		0.0f, 0.0f, // 7 H

		//FRONT
		-0.98f, 1.01f, 0.001f,	0.0f, 0.0f, 0.0f,		0.0f, 0.0f, // 8 A
		-0.98f, 1.488f, 0.001f,	0.0f, 0.0f, 0.0f,		0.0f, 1.0f, // 9 B
		 0.98f, 1.01f, 0.001f,	0.0f, 0.0f, 0.0f,		1.0f, 0.0f, // 10 C
		 0.98f, 1.488f, 0.001f,	0.0f, 0.0f, 0.0f,		1.0f, 1.0f, // 11 D	
	};

	indices = {
		//FRONT TEXTURE FACE
		8, 11, 10,
		8, 10, 11,
		8, 11, 9,
		8, 9, 11,

		// FRONT FACE
		0, 3, 2, // A, D, C
		0, 2, 3, // A, C, D,
		0, 3, 1, // A, D, B
		0, 1, 3, // A, B, D

		// BACK FACE
		4, 7, 6, //E, H, G
		4, 6, 7, // E, G, H
		4, 7, 5, // E, H, F
		4, 5, 7,// E, F, H

		// RIGHT SIDE
		2, 7, 6, // C, H, G
		2, 6, 7, // C, G, H
		2, 7, 3, // C, H, D
		2, 3, 7, // C, D, H
		
		// LEFT SIDE
		0, 5, 1, // A, F, B
		0, 1, 5, // A, B, F
		0, 5, 4, // A, F, E
		0, 4, 5, // A, E, F

		// TOP SIDE
		1, 7, 5, // B, H, F
		1, 5, 7, // B, F, H
		1, 7, 3, // B, H, D
		1, 3, 7, // B, D, H

		// BOTTOM SIDE
		0, 6, 2, // A, G, C
		0, 2, 6, // A, C, G
		0, 6, 4, // A, G, E
		0, 4, 6,// A, E, G
	};
}
/*******************************************************************************************************************************/
	/**************************************************************************************************
	*																								  *
	*   MONITOR SCREEN		 																		  *
	*																								  *
	**************************************************************************************************/
void MeshData::createMonitorScreenMesh() {
	indices.clear();
	vertices = {
		
		-0.98f, 1.01f, 0.0013f,		1.0f, 1.0f, 1.0f,		0.0f, 0.0f, // 0 A
		-0.98f, 1.488f, 0.0013f,	1.0f, 1.0f, 1.0f,		0.0f, 1.0f, // 1 B
		 0.98f, 1.01f, 0.0013f,		1.0f, 1.0f, 1.0f,		1.0f, 0.0f, // 2 C
		 0.98f, 1.488f, 0.0013f,	1.0f, 1.0f, 1.0f,		1.0f, 1.0f, // 3 D
	};
	
}
/*******************************************************************************************************************************/
	/**************************************************************************************************
	*																								  *
	*   MACBOOK 		 																			  *
	*																								  *
	**************************************************************************************************/
void MeshData::createMacBookMesh() {
	indices.clear();
	vertices = {
			// BOTTOM FACE
			-0.5f, 0.0f, -0.4f,		0.4f, 0.4f, 0.4f,		0.0f, 0.0f,	      // A 0 bot left
			 0.5f, 0.0f, -0.4f,		0.4f, 0.4f, 0.4f,		0.0f, 0.0f,       // B 1 bot right
			 0.5f, 0.0f, 0.5f,		0.4f, 0.4f, 0.4f,		0.0f, 0.0f,       // C 2 top right
			-0.5f, 0.0f, 0.5f,		0.4f, 0.4f, 0.4f,		0.0f, 0.0f,	      // D 3 top left
			 // TOP FACE
			 0.5f ,0.15f, 0.5f,		0.4f, 0.4f, 0.4f,		0.25f, 0.19f,	  // E 4 bot left
			-0.5f, 0.15f, 0.5f,		0.4f, 0.4f, 0.4f,		0.25f, 0.82f,	  // F 5 top left
			-0.5f, 0.15f, -0.4f,	0.4f, 0.4f, 0.4f,		0.65f, 0.82f,	  // G 6 top right
			 0.5f, 0.15f, -0.4f,	0.4f, 0.4f, 0.4f,		0.65f, 0.19f,	  // H 7  bot right
			// BACK SIDE 
			 0.5f , 0.0f, 0.5f,		1.0f, 1.0f, 1.0f,		0.4f, 0.080f,     // C 8 bot left 24 25 26
			-0.5f , 0.0f, 0.5f,		1.0f, 1.0f, 1.0f,		0.65f, 0.080f,	  // D 9 bot right 27 28 29
			 0.5f, 0.15f, 0.5f,		1.0f, 1.0f, 1.0f,		0.4f, 0.11545f,   // E 10 top left 30 31 32
			-0.5f, 0.15f, 0.5f,		1.0f, 1.0f, 1.0f,		0.65f, 0.11545f,  // F 11 top right 33 34 35
			// HDMI SIDE 
			-0.5f, 0.0f, -0.4f,		1.0f, 1.0f, 1.0f,		0.65f, 0.924f,	  // A 12 bot left
			-0.5f, 0.0f, 0.5f,		1.0f, 1.0f, 1.0f,		0.24f, 0.924f,	  // D 13 bot right
			-0.5f, 0.15f, 0.5f,		1.0f, 1.0f, 1.0f,		0.24f, 0.89f,	  // F 14 top right
			-0.5f, 0.15f, -0.4f,	1.0f, 1.0f, 1.0f,		0.65f, 0.89f,	  // G 15 top left
			// CHARGER SIDE
			 0.5f, 0.0f, -0.4f,		1.0f, 1.0f, 1.0f,		0.65f, 0.080f,	  // B 16 bot right
			 0.5f, 0.0f, 0.5f,		1.0f, 1.0f, 1.0f,		0.24f, 0.080f,	  // C 17 bot left
			 0.5f, 0.15f, 0.5f,		1.0f, 1.0f, 1.0f,		0.24f, 0.11545f,  // E 18 top left
			 0.5f, 0.15f, -0.4f,	1.0f, 1.0f, 1.0f,		0.65f, 0.11545f,  // H 19 top right
			// FRONT FACE LIP
			 -0.5f, 0.0f, -0.4f,	1.0f, 1.0f, 1.0f,		0.80f, 0.80f,	  // A 20 TOP BOT (TOP RIGHT)
			  0.5f, 0.0f, -0.4f,	1.0f, 1.0f, 1.0f,		0.80f, 0.22f,     // B 21 BOT BOT (BOT RIGHT)
			 -0.5f, 0.15f, -0.4f,	1.0f, 1.0f, 1.0f,		0.775f, 0.80f,	  // G 22 TOP TOP (TOP LEFT)
			  0.5f, 0.15f, -0.4f,	1.0f, 1.0f, 1.0f,		0.775f, 0.22f,	  // H 23 BOT TOP (TOP RIGHT)
	};

	indices = {
		// 
		0, 2, 1,    // A, C, B
		0, 1, 2,    // A, B, C
		0, 2, 3,    // A, C, D
		0, 3, 2,    // A, D, C
		// 
		6, 4, 5,    // G, E, F
		6, 5, 4,    // G, F, E
		6, 4, 7,    // G, E, H
		7, 7, 4,    // G, H, E

		9, 10, 8,   // D, E, C
		9, 8, 10,   // D, C, E
		9, 10, 11,  // D, E, F
		9, 11, 10,  // D, F, E
		//
		12, 14, 15, // A, F, G
		12, 15, 14, // A, G, F
		12, 14, 13, // A, F, D
		12, 13, 14, // A, D, F
		//
		18, 16, 17, // E, B, C
		18, 17, 16, // E, C, B
		18, 16, 19, // E, B, H
		18, 19, 16, // E, H, B
		//
		20, 23, 21, // A, H, B
		20, 21, 23, // A, B, H
		20, 23, 22, // A, H, G
		20, 22, 23  // A, G, H		
	};
}




void MeshData::createMouseMesh(float radius, int parts, float height) {

	float angleIncrement = 3.14 / parts;

	// LEFT SIDE

	float zLeft = height / 2.0f;

	for (int i = 0; i <= parts; ++i) {
		float angle = i * angleIncrement;
		float x = radius * cos(angle);
		float y = radius * sin(angle);
		//POS
		mouseVertices.push_back(x);
		mouseVertices.push_back(y);
		mouseVertices.push_back(zLeft);
		//cout << "(" << x << "," << y << ", " << zTop << ")" << endl;

		// COLORS
		mouseVertices.push_back(0.1f);
		mouseVertices.push_back(0.1f); 
		mouseVertices.push_back(0.1f); 

		// TEX COORDS
		float uLeftFace = 0.0f;
		float vLeftFace = 0.0f;
		mouseVertices.push_back(uLeftFace); 
		mouseVertices.push_back(vLeftFace); 

	}

	// RIGHT SIDE

	float zRight = -height / 2.0f;

	for (int i = 0; i <= parts; ++i) {
		float angle = i * angleIncrement;
		float x = radius * cos(angle);
		float y = radius * sin(angle);

		//POS
		mouseVertices.push_back(x);
		mouseVertices.push_back(y);
		mouseVertices.push_back(zRight);

		// COLORS
		mouseVertices.push_back(0.1f); 
		mouseVertices.push_back(0.1f); 
		mouseVertices.push_back(0.1f); 

		// TEX COORDS
		float uRightFace = 0.0f;
		float vRightFace = 0.0f;
		mouseVertices.push_back(uRightFace); 
		mouseVertices.push_back(vRightFace);
	}

	// TOP


	for (int i = 0; i <= parts; ++i) {
		float angle = i * angleIncrement;
		float x = radius * cos(angle);
		float y = radius * sin(angle);
		//POS
		mouseVertices.push_back(x);
		mouseVertices.push_back(y);
		mouseVertices.push_back(zLeft);

		//cout << x << " " << y << " " << zLeft << endl;
		// COLORS
		mouseVertices.push_back(0.1f);
		mouseVertices.push_back(0.1f);
		mouseVertices.push_back(0.1f);

		// TEX COORDS
		float uTopFace = 1.0 ;
		//cout << uTopFace << endl;
		float vTopFace = static_cast<float>(i) / parts;
		mouseVertices.push_back(uTopFace);
		mouseVertices.push_back(vTopFace);
	}

	// BOTTOM

	for (int i = 0; i <= parts; ++i) {
		float angle = i * angleIncrement;
		float x = radius * cos(angle);
		float y = radius * sin(angle);
		// POS
		mouseVertices.push_back(x);
		mouseVertices.push_back(y);
		mouseVertices.push_back(zRight);
		// COLORS
		mouseVertices.push_back(0.0f);
		mouseVertices.push_back(0.0f);
		mouseVertices.push_back(0.0f);
		// TEX COORDS
		float uBottomFace = 0.0f;
		float vBottomFace = 0.0f;
		mouseVertices.push_back(uBottomFace);
		mouseVertices.push_back(vBottomFace);
	}



	int baseIndex = parts + 1;

	// RIGHT SIDE
	for (int i = 0; i < parts; ++i) {
		mouseIndices.push_back(0);
		mouseIndices.push_back(i);
		mouseIndices.push_back(i + 1);
	}

	// TOP AND BOTTOM
	for (int i = 1; i <= parts; ++i) {
		// Top
		mouseIndices.push_back(i - 1);
		mouseIndices.push_back(i);
		mouseIndices.push_back(baseIndex + i);

		mouseIndices.push_back(baseIndex + i);
		mouseIndices.push_back(baseIndex + i - 1);
		mouseIndices.push_back(i - 1);

		// Bottom
		mouseIndices.push_back(baseIndex + i);
		mouseIndices.push_back(i);
		mouseIndices.push_back(i - 1);

		mouseIndices.push_back(baseIndex + i - 1);
		mouseIndices.push_back(baseIndex + i);
		mouseIndices.push_back(i - 1);
	}

	// LEFT SIDE 
	for (int i = baseIndex + 1; i < baseIndex + parts; ++i) {
		mouseIndices.push_back(baseIndex);
		mouseIndices.push_back(i);
		mouseIndices.push_back(i - 1);
	}
}

void MeshData::createTorusMesh(float outerRadius, float innerRadius, int sides, int rings) {

	float angleIncrement = 2.0f * 3.14 / sides;
	
	for (int i = 0; i <= sides; ++i) {
		float theta = i * angleIncrement;
		float cosTheta = cos(theta);
		float sinTheta = sin(theta);

		for (int j = 0; j <= rings; ++j) {
			float phi = j * angleIncrement;
			float cosPhi = cos(phi);
			float sinPhi = sin(phi);

			float x = (outerRadius + innerRadius * cosPhi) * cosTheta;
			float y = (outerRadius + innerRadius * cosPhi) * sinTheta;
			float z = innerRadius * sinPhi;

			torusVertices.push_back(x);
			torusVertices.push_back(y);
			torusVertices.push_back(z);

			// COLOR
			torusVertices.push_back(0.1f); 
			torusVertices.push_back(0.1f); 
			torusVertices.push_back(0.1f); 

			// TEX COORDS
			float u = static_cast<float>(i) / sides;
			float v = static_cast<float>(j) / rings;
			torusVertices.push_back(u); 
			torusVertices.push_back(v);
		}
	}

	for (int i = 0; i < sides; ++i) {
		for (int j = 0; j < rings; ++j) {
			int index = i * (rings + 1) + j;

			torusIndices.push_back(index);
			torusIndices.push_back(index + rings + 1);
			torusIndices.push_back(index + 1);

			torusIndices.push_back(index + 1);
			torusIndices.push_back(index + rings + 1);
			torusIndices.push_back(index + rings + 2);
			
		}
	}
}

void MeshData::createCylinderMesh(float radius, float height, int sides) {
	float angleIncrement1 = 2.0f * 3.14159265359 / sides;

	for (int i = 0; i <= sides; ++i) {
		float theta1 = i * angleIncrement1;
		float cosTheta1 = cos(theta1);
		float sinTheta1 = sin(theta1);

		float x = radius * cosTheta1;
		float y = radius * sinTheta1;
		float z = 0.0f;

		// POS
		cylinderVertices.push_back(x);
		cylinderVertices.push_back(y);
		cylinderVertices.push_back(z);

		// COLOR
		cylinderVertices.push_back(0.1f);
		cylinderVertices.push_back(0.1f);
		cylinderVertices.push_back(0.1f);

		// TEX COORDS
		float u = static_cast<float>(i) / sides;
		float v = 0.0f;
		cylinderVertices.push_back(u); 
		cylinderVertices.push_back(v); 

		// TOP VERTICES
		cylinderVertices.push_back(x);
		cylinderVertices.push_back(y);
		cylinderVertices.push_back(height);

		// COLOR
		cylinderVertices.push_back(0.1f);
		cylinderVertices.push_back(0.1f);
		cylinderVertices.push_back(0.1f);

		// TEX COORDS
		v = 1.0f;
		cylinderVertices.push_back(u);
		cylinderVertices.push_back(v); 
	}
	for (int i = 0; i < sides; ++i) {
		int index = i * 2;

		cylinderIndices.push_back(index);
		cylinderIndices.push_back(index + 1);
		cylinderIndices.push_back(index + 3);

		cylinderIndices.push_back(index + 3);
		cylinderIndices.push_back(index + 2);
		cylinderIndices.push_back(index);

		// END CAPS
		int topCenterIndex = (sides + 1) * 2;
		cylinderIndices.push_back(index + 1);
		cylinderIndices.push_back(topCenterIndex);
		cylinderIndices.push_back(index + 3);

		cylinderIndices.push_back(index + 2);
		cylinderIndices.push_back(topCenterIndex + 1);
		cylinderIndices.push_back(index);
	}
}


const vector<GLfloat>& MeshData::getVertices() const {
	return vertices;
}

const vector<GLuint>& MeshData::getIndices() const {
	return indices;
}

const vector<GLfloat>& MeshData::getMouseVertices() const {
	return mouseVertices;
}

const vector<GLuint>& MeshData::getMouseIndices() const {
	return mouseIndices;
}
const vector<GLfloat>& MeshData::getTorusVertices() const {
	return torusVertices;
}

const vector<GLuint>& MeshData::getTorusIndices() const {
	return torusIndices;
}
const vector<GLfloat>& MeshData::getCylinderVertices() const {
	return cylinderVertices;
}

const vector<GLuint>& MeshData::getCylinderIndices() const {
	return cylinderIndices;
}










