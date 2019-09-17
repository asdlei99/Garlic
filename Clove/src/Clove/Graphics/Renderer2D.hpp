#pragma once

#include <queue>

namespace clv::gfx{
	class Sprite;
	class Mesh;
	class Material;

	class Renderer2D{
		//VARIABLES
	private:
		static std::shared_ptr<gfx::Mesh> renderMesh;
		static std::shared_ptr<Material> meshMaterial;

		static std::queue<std::shared_ptr<Sprite>> renderQueue;

		//FUNCTIONS
	public:
		static void initialise();

		static void beginScene();
		static void endScene();

		static void submitSprite(const std::shared_ptr<Sprite>& sprite);
	};
}