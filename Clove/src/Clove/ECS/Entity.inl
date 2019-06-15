namespace clv::ecs{
	template<typename EntityType>
	inline EntityType* Entity::getComponent() const{
		if(const auto foundComp = components.find(EntityType::ID); foundComp != components.end()){
			return static_cast<EntityType*>(foundComp->second.get());
		}
		return nullptr;
	}

	template<typename EntityType>
	inline EntityType* Entity::addComponent(){
		std::unique_ptr<EntityType> component = std::make_unique<EntityType>();
		component->entityID = ID;

		EntityType* outPTr = component.get();
		components[EntityType::ID] = std::move(component);

		return outPTr;
	}

	template<typename EntityType, typename ...ConstructTypes>
	inline EntityType* Entity::addComponent(ConstructTypes&&... args){
		std::unique_ptr<EntityType> component = std::make_unique<EntityType>(args...);
		component->entityID = ID;

		EntityType* outPTr = component.get();
		components[EntityType::ID] = std::move(component);

		return outPTr;
	}
}