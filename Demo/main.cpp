#include <iostream>
#include <vector>
#include <time.h>
#include <stdlib.h>
#include <vector>

#include "Raylacer/Core/Pixel.h"
#include "Raylacer/Core/Color.h"
#include "Raylacer/Core/Vector.h"
#include "Raylacer/Export/Export.h"
#include "Raylacer/Shapes/Sphere.h"
#include "Raylacer/Core/Ray.h"
#include "Raylacer/Core/Screen.h"
#include "Raylacer/Core/Light.h"
#include "Raylacer/Core/Material.h"

int main(int argc, char* argv[])
{
  Screen screen;
  screen.background_color.r = 0;
  screen.background_color.g = 0;
  screen.background_color.b = 0;
  srand(time(NULL));

  Light l;
  l.position.x = WIDTH/2.0f-500;
	l.position.y = HEIGHT/2.0f + 1000;
	l.position.z = 100;
	l.color.r = 1.0f;
	l.color.g = 1.0f;
	l.color.b = 1.0f;

  Light l2;
  l2.position.x = WIDTH-(WIDTH/4.0f);
  l2.position.y = HEIGHT/2.0f;
  l2.position.z = -200;
  l2.color.r = 1.0f;
  l2.color.g = 1.0f;
  l2.color.b = 1.0f;

  Light l3;
  l3.position.x = WIDTH/2.0f;
	l3.position.y = 0;
	l3.position.z = -2000;
	l3.color.r = 1.0f;
	l3.color.g = 1.0f;
	l3.color.b = 1.0f;

  Sphere s;
	s.position.x = WIDTH-(WIDTH/3);
	s.position.y = HEIGHT-(HEIGHT/3);
	s.position.z = 0;
  s.material.color.r = 0.0f;
  s.material.color.g = 0.0f;
  s.material.color.b = 1.0f;
  s.material.reflectivity = 1.0f;
	s.radius = 200;

  Sphere s2;
	s2.position.x = WIDTH/5;
	s2.position.y = HEIGHT/5;
	s2.position.z = 0;
  s2.material.color.r = 0.7f;
  s2.material.color.g = 0.2f;
  s2.material.color.b = 0.2f;
  s2.material.reflectivity = 1.0f;
	s2.radius = 200;

  Sphere s3;
	s3.position.x = (WIDTH/2)-250;
	s3.position.y = (HEIGHT/2);
	s3.position.z = -350;
  s3.material.color.r = 0.2f;
  s3.material.color.g = 0.6f;
  s3.material.color.b = 0.2f;
  s3.material.reflectivity = 1.0f;
	s3.radius = 100;

  std::vector<Sphere> spheres;
  std::vector<Light> lights;
  spheres.push_back(s);
  spheres.push_back(s2);
  spheres.push_back(s3);
  lights.push_back(l);
  lights.push_back(l2);
  lights.push_back(l3);

  Ray r;
	r.dir.x = 0;
	r.dir.y = 0;
	r.dir.z = 1;
	r.start.z = 0;

	for(int y=0;y<HEIGHT;y++){
		r.start.y = y;
		for(int x=0;x<WIDTH;x++){
      int p = y*WIDTH+x;
			r.start.x = x;

      int level = 0;

      float red = 0;
			float green = 0;
			float blue = 0;
      float coef = 1.0;

      r.start.x = x;
      r.start.y = y;
      r.start.z = -2000;

      r.dir.x = 0;
      r.dir.y = 0;
      r.dir.z = 1;

      do{
				/* Find closest intersection */
				float t = 20000.0f;
				int currentSphere = -1;

				unsigned int i;
				for(i = 0; i < spheres.size(); i++){
					if(r.intersect_sphere(&spheres[i], &t))
						currentSphere = i;
				}
				if(currentSphere == -1) break;

				Vector scaled = r.dir.scale(t, &r.dir);
				Vector newStart = r.start.add(&r.start, &scaled);

				/* Find the normal for this new vector at the point of intersection */
				Vector n = spheres[currentSphere].position.sub(&newStart, &spheres[currentSphere].position);
				float temp = n.dot(&n, &n);
				if(temp == 0) break;

				temp = 1.0f / sqrtf(temp);
				n = n.scale(temp, &n);

				/* Find the material to determine the colour */
				Material currentMat = spheres[currentSphere].material;

				/* Find the value of the light at this point */
				unsigned int j;
        bool inShadow = false;
				for(j=0; j < 3; j++){
					Light currentLight = lights[j];
					Vector dist = currentLight.position.sub(&currentLight.position, &newStart);
					if(n.dot(&n, &dist) <= 0.0f) continue;
					float t = sqrtf(dist.dot(&dist,&dist));
					if(t <= 0.0f) continue;

					Ray lightRay;
					lightRay.start = newStart;
					lightRay.dir = dist.scale((1/t), &dist);

          unsigned int k;
          for (k = 0; k < 3; ++k) {
          	if (lightRay.intersect_sphere(&spheres[k], &t)){
          		inShadow = true;
          	break;
          	}
          }
					/* Lambert diffusion */
          if (!inShadow){
  					float lambert = n.dot(&lightRay.dir, &n) * coef;
  					red += lambert * currentLight.color.r * currentMat.color.r;
  					green += lambert * currentLight.color.g * currentMat.color.g;
  					blue += lambert * currentLight.color.b * currentMat.color.b;
          }
				}
				/* Iterate over the reflection */
				    coef *= currentMat.reflectivity;

				/* The reflected ray start and direction */
				r.start = newStart;
				float reflect = 2.0f * n.dot(&r.dir, &n);
				Vector tmp = n.scale(reflect, &n);
				r.dir = r.dir.sub(&r.dir, &tmp);

				level++;

			}while((coef > 0.0f) && (level < 15));

      screen.frame[p].r = red;
      screen.frame[p].g = green;
      screen.frame[p].b = blue;

		}
	}
  Export::savebmp("randomMaze.bmp", WIDTH, HEIGHT, 72, screen.frame);
  delete screen.frame;
  return 0;
}
