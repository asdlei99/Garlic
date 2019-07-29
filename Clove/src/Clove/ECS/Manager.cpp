#include "clvpch.hpp"
#include "Manager.hpp"

#include "Clove/ECS/2D/Systems/Render2DSystem.hpp"
#include "Clove/ECS/3D/Systems/Render3DSystem.hpp"
#include "Clove/ECS/2D/Systems/Transform2DSystem.hpp"
#include "Clove/ECS/3D/Systems/Transform3DSystem.hpp"
#include "Clove/ECS/3D/Systems/LightSystem.hpp"
#include "Clove/ECS/3D/Systems/CameraSystem.hpp"

namespace clv::ecs{
	EntityID Manager::nextID = 0;

	Manager::Manager(){
		systems.reserve(6);
		systems.emplace_back(std::make_unique<Render2DSystem>());
		systems.emplace_back(std::make_unique<Render3DSystem>());
		systems.emplace_back(std::make_unique<Transform2DSystem>());
		systems.emplace_back(std::make_unique<Transform3DSystem>());
		systems.emplace_back(std::make_unique<LightSystem>());
		systems.emplace_back(std::make_unique<CameraSystem>());
	}

	Manager::~Manager() = default;

	void Manager::update(utl::DeltaTime deltaTime){
		for(const auto& system : systems){
			system->update(deltaTime);
		}
	}

	void Manager::destroyEntity(EntityID ID){
		if(ID == INVALID_ENTITY_ID){
			return;
		}

		components.erase(ID);
		for(const auto& system : systems){
			system->onEntityDestroyed(ID);
		}
	}

	Entity Manager::getEntity(EntityID ID){
		if(const auto foundEnt = components.find(ID); foundEnt != components.end()){
			Entity entity{ ID };
			entity.onComponentRequestedDelegate.bind(&Manager::getComponentForEntity, this);
			entity.isEntityIdValidDelegate.bind(&Manager::isEntityValid, this);

			return entity;
		}
		return {};
	}

	Component* Manager::getComponentForEntity(EntityID entityID, ComponentID componentID){
		return components[entityID][componentID].get();
	}

	bool Manager::isEntityValid(EntityID entityID){
		const auto it = components.find(entityID);
		return it != components.end();
	}
}