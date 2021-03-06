#pragma once

#include "Tunic/ECS/Core/ECSTypes.hpp"

namespace tnc::ecs{
	class Manager;
}

namespace tnc::ecs{
	class Entity{
		//VARIABLES
	private:
		Manager* manager = nullptr;

		EntityID entityID = INVALID_ENTITY_ID;

		//FUNCTIONS
	public:
		Entity();
		Entity(EntityID entityID, Manager* manager);

		Entity(const Entity& other);
		Entity(Entity&& other) noexcept;

		Entity& operator=(const Entity& other);
		Entity& operator=(Entity&& other) noexcept;

		~Entity();

		bool isValid() const;

		EntityID getID() const;

		template<typename ComponentType, typename ...ConstructorArgs>
		ComponentType* addComponent(ConstructorArgs&& ...args);
		template<typename ComponentType>
		ComponentType* getComponent() const;
		template<typename ComponentType>
		void removeComponent();
	};
}

#include "Entity.inl"