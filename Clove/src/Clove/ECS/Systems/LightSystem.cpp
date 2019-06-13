#include "clvpch.hpp"
#include "LightSystem.hpp"

#include "Clove/Application.hpp"

namespace clv::ecs{
	LightSystem::LightSystem() = default;

	LightSystem::LightSystem(LightSystem&& other) noexcept = default;

	LightSystem& LightSystem::operator=(LightSystem&& other) noexcept = default;

	LightSystem::~LightSystem() = default;

	void LightSystem::update(float deltaTime){
		for(auto& componentTuple : components){
			TransformComponent* transform = std::get<TransformComponent*>(componentTuple);
			LightComponent* light = std::get<LightComponent*>(componentTuple);

			light->lightData.position = transform->getLocalPosition();

			light->sbo->update(light->lightData, Application::get().getRenderer());
		}
	}
}