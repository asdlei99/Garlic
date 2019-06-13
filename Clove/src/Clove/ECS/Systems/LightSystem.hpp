#pragma once

#include "Clove/ECS/System.hpp"

#include "Clove/ECS/Components/TransformComponent.hpp"
#include "Clove/ECS/Components/LightComponent.hpp"

namespace clv::ecs{
	class LightSystem : public System<TransformComponent, LightComponent>{
		//VARIABLES
	public:
		static constexpr SystemID ID = 0xb46079ac;

		//FUNCTIONS
	public:
		LightSystem();
		LightSystem(const System& other) = delete;
		LightSystem(LightSystem&& other) noexcept;
		LightSystem& operator=(const LightSystem& other) = delete;
		LightSystem& operator=(LightSystem&& other) noexcept;
		virtual ~LightSystem();

		virtual void update(float deltaTime) override;
	};
}