#include "VertexBuffers.h"
#include <cstdint>
#include <algorithm>
#include <iostream>
#include <iomanip>
namespace TeraPlay {
	void VertexBuffers::TP_VertexBufferSetup(Vertex vertices[], unsigned int Vert, unsigned int Dimen, const unsigned int IPV[], unsigned int Ind)
	{
		//	float vertices[] = {
		//	-0.5f, -0.5f, 0.0f,
		//	 0.5f, -0.5f, 0.0f,
		//	 0.5f,  0.5f, 0.0f,
		//
		//	 0.5f,  0.5f, 0.0f,
		//	-0.5f,  0.5f, 0.0f,
		//	-0.5f, -0.5f, 0.0f,
		//	};

		glGenBuffers(1, &VBO);
		glBindBuffer(GL_ARRAY_BUFFER, VBO);
		glBufferData(GL_ARRAY_BUFFER, sizeof(vertices->Positions), vertices, GL_STATIC_DRAW);

		glGenVertexArrays(1, &VAO);
		glBindVertexArray(VAO);
		// 2. copy our vertices array in a buffer for OpenGL to use
		glBindBuffer(GL_ARRAY_BUFFER, VBO);
		glBufferData(GL_ARRAY_BUFFER, Vert * sizeof(vertices->Positions), vertices, GL_STATIC_DRAW);

		glGenBuffers(1, &IBO);
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, IBO);
		glBufferData(GL_ELEMENT_ARRAY_BUFFER, Ind * sizeof(unsigned int), IPV, GL_STATIC_DRAW);

		// 3. then set our vertex attributes pointers
		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)0);
		glEnableVertexAttribArray(0);
		glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(3 * sizeof(float)));
		glEnableVertexAttribArray(1);
		glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(6 * sizeof(float)));
		glEnableVertexAttribArray(2);


	}

	void VertexBuffers::TP_RenderVertex(unsigned int Vert, unsigned int Dimen, unsigned int IPV[], unsigned int Ind, bool draw_arrays)
	{
		if (draw_arrays) {
			glBindVertexArray(VAO);
			glPolygonMode(GL_FRONT, GL_FILL);
			glDrawArrays(GL_TRIANGLES, 0, Vert);
		}
		else {
			glBindVertexArray(VAO);
			glDrawElements(GL_TRIANGLES, Ind, GL_UNSIGNED_INT, nullptr);
		}

	}
	
}