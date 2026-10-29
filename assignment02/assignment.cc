/*===========================================================================*/
/*                                                                           *
 * Copyright (c) 2026, Computer Graphics Group RWTH Aachen University        *
 *                            All rights reserved                            *
 *                                                                           *
 * Basic Techniques in Computer Graphics Exercise                            *
 *                                                                           */
/*===========================================================================*/

#include "assignment.hh"

namespace
{

// You may want to define the following helper functions to create common
// transformation matrices:

glm::mat4 scale(float const sx, float const sy)
{
    return glm::mat4(
		sx, 0, 0,  0,
		0,  sy, 0, 0,
		0,  0,  1, 0,
		0,  0,  0, 1);
}

glm::mat4 scale(const float s)
{
    return scale(s, s);
}

glm::mat4 rotate(float const angle)
{
    return glm::mat4(
		glm::cos(angle), glm::sin(angle), 0, 0,
		-glm::sin(angle), glm::cos(angle), 0, 0,
		0, 0, 1, 0,
		0, 0, 0, 1);
}

glm::mat4 translate(float const tx, float const ty)
{
    return glm::mat4(
		1,  0,  0, 0,
		0,  1,  0, 0,
		0,  0,  1, 0,
		tx, ty, 0, 1);
}

}

void task::drawScene(int scene, float runTime)
{
    // All further exercise code should replace the content of this drawScene

    const glm::vec3 blue(0.f, 0.f, 1.f), grey(0.2f), black(0.f), white(1.f),
					green(0.f, 1.f, 0.f), yellow(1.f, 1.f, 0.f);

	const float PI = 3.14159f;

	drawCircle(blue, scale(0.90f));
	drawCircle(grey, scale(0.88f));
	drawCircle(blue, scale(0.72f));
	drawCircle(black, scale(0.70f));

	for (int i = 0; i < 9; i++) {
		float x = -0.88f + i * 0.02f;
		drawCircle(white, translate(x, 0.f) * scale(0.004f, 0.03f));
	}

	for (int i = 0; i < 30; i++) {
		// if (i == 12) continue;
		float a = 2.0f * PI * (i + 0.5f) / 30;
		drawCircle(white, rotate(a) * translate(0.8f, 0.f) * scale (0.008f, 0.035f));
	}

	const float w = 0.5f;
	float aSlow = PI - w * runTime;
	float aFast = PI - 2.0f * w * runTime;
	glm::mat4 carShape = scale(0.015f, 0.06f);
	drawCircle(yellow, rotate(aSlow) * translate(0.75f, 0.f) * carShape);

	float p = glm::mod(w * runTime + 0.6f, 2.0f * PI);
	float s = glm::smoothstep(0.20f, 0.35f, p) - glm::smoothstep(0.85f, 1.00f, p);
	float rFast = 0.75f + 0.10f *s;
	drawCircle(green, rotate(aFast) * translate(rFast, 0.f) * carShape);
}
void task::initCustomResources() {}
void task::deleteCustomResources() {}
