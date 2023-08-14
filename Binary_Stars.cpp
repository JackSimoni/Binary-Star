/*
#include <cmath>
#include <raylib.h>
#include <vector>
#include <iostream>

using namespace std;

struct star 
{
	float x, y;
	float radius;
	float speedx, speedy;
	float accelx, accely;
	float mass;

	void Draw()
	{
		DrawCircle((int)x, (int)y, radius, YELLOW);
	}

};

const float G_const = 500000.0f;

const int Limit_Bezier = 300;
Vector2 points1[Limit_Bezier];
Vector2 points2[Limit_Bezier];
int numofpoints1 = 0;
int numofpoints2 = 0;

int main()
{

	InitWindow(1920, 1000, "Binary_Stars");
	SetWindowState(FLAG_VSYNC_HINT);


	star star1;
	star1.x = 2.4*GetScreenWidth() / 4.0f;
	star1.y = GetScreenHeight() / 3.0f;
	star1.radius = 10;
	star1.speedx = -20;
	star1.speedy = -280;
	star1.mass = 500.0f;

	star star2;
	star2.x = 1.6* GetScreenWidth() / 4.0f;
	star2.y = GetScreenHeight() / 3.0f;
	star2.radius = 25.0f;
	star2.speedx = 20;
	star2.speedy = 200;
	star2.mass = 750.0f;

	while (!WindowShouldClose())
	{
		float position_vector_magnitude = sqrt((pow(star1.x - star2.x, 2)) + (pow(star1.y - star2.y, 2)));

		star1.accelx = abs(G_const * star2.mass * (1 / pow(position_vector_magnitude, 2)) * ((star1.x - star2.x) / sqrt(pow(star1.x - star2.x, 2) + pow(star1.y - star2.y, 2))));

		if (star1.x > star2.x)
		{
			star1.accelx *= -1;
		}

		star1.accely = abs(G_const * star2.mass * (1 / pow(position_vector_magnitude, 2)) * ((star1.y - star2.y) / sqrt(pow(star1.x - star2.x, 2) + pow(star1.y - star2.y, 2))));

		if (star1.y > star2.y)
		{
			star1.accely *= -1;
		}

		star2.accelx = abs(G_const * star1.mass * (1 / pow(position_vector_magnitude, 2)) * ((star1.x - star2.x) / sqrt(pow(star1.x - star2.x, 2) + pow(star1.y - star2.y, 2))));

		if (star2.x > star1.x)
		{
			star2.accelx *= -1;
		}

		star2.accely = abs(G_const * star1.mass * (1 / pow(position_vector_magnitude, 2)) * ((star1.y - star2.y) / sqrt(pow(star1.x - star2.x, 2) + pow(star1.y - star2.y, 2))));
		if (star2.y > star1.y)
		{
			star2.accely *= -1;
		}

		// Equations of Acceleration Using Newton's Law of Gravitation and Vector Decomposition

		star1.speedx += star1.accelx * GetFrameTime(); // Update Speed of Stars
		star1.speedy += star1.accely * GetFrameTime();

		star2.speedx += star2.accelx * GetFrameTime();
		star2.speedy += star2.accely * GetFrameTime();

		star1.x += star1.speedx * GetFrameTime();	// Update Position of Stars
		star1.y += star1.speedy * GetFrameTime();

		star2.x += star2.speedx * GetFrameTime();
		star2.y += star2.speedy * GetFrameTime();

		if (numofpoints1 < Limit_Bezier)
		{
			points1[numofpoints1] = {star1.x, star1.y};
			numofpoints1++;
		}
		else
		{
			// Shift points to the left and discard the first point
			for (int i = 1; i < Limit_Bezier; i++)
			{
				points1[i - 1] = points1[i];
			}

			points1[Limit_Bezier - 1] = {star1.x, star1.y };
		}

		if (numofpoints2 < Limit_Bezier)
		{
			points2[numofpoints2] = {star2.x, star2.y};
			numofpoints2++;
		}
		else
		{
			// Shift points to the left and discard the first point
			for (int i = 1; i < Limit_Bezier; i++)
			{
				points2[i - 1] = points2[i];
			}

			points2[Limit_Bezier - 1] = {star2.x, star2.y};
		}
		
		BeginDrawing();
		ClearBackground(BLACK);

		for (int i = 0; i < numofpoints1 - 1; i++)
		{
			DrawLineBezier(points1[i], points1[i + 1], 1.5f, PINK);
		}

		for (int i = 0; i < numofpoints2 - 1; i++)
		{
			DrawLineBezier(points2[i], points2[i + 1], 1.5f, SKYBLUE);
		}

		star1.Draw();
		star2.Draw();
		
		EndDrawing();
	}
	
	CloseWindow();

	return 0;
}
*/