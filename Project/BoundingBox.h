#ifndef BOUNDINGBOX_H
#define BOUNDINGBOX_H
#include <GLM/glm.hpp>

using namespace glm;

namespace Engine {
	class BoundingBox {
	public:
		bool CollideWith(BoundingBox* other);
		void SetMinX(float minX);
		void SetMaxX(float maxX);
		void SetMinY(float minY);
		void SetMaxY(float maxY);
		float GetMinX();
		float GetMinY();
		float GetMaxX();
		float GetMaxY();
	private:
		float minX = 0, maxX = 0, minY = 0, maxY = 0;
	};
}

#endif

