#pragma once

#include "Core/ECS/System.hpp"

#include "Core/ECS/2D/Components/TransformComponent.hpp"
#include "Core/ECS/2D/Components/RenderableComponent.hpp"

namespace clv::ecs::d2{
	class RenderSystem : public System<TransformComponent, RenderableComponent>{
		//FUNCTIONS
	public:
		RenderSystem();
		RenderSystem(const RenderSystem& other) = delete;
		RenderSystem(RenderSystem&& other) noexcept;
		RenderSystem& operator=(const RenderSystem& other) = delete;
		RenderSystem& operator=(RenderSystem&& other) noexcept;
		virtual ~RenderSystem();

		virtual void update(utl::DeltaTime deltaTime) override;
	};
}