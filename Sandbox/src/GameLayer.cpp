#include "clvpch.hpp" //TODO: See note in example layer
#include "GameLayer.hpp"

#include "Clove/Application.hpp"
#include "Clove/ECS/Components/CameraComponent.hpp"
#include "Clove/ECS/Components/MeshComponent.hpp"
#include "Clove/ECS/Components/Transform3DComponent.hpp"

#include "Clove/ECS/Components/LightComponent.hpp"

GameLayer::GameLayer()
	: Layer("Game Layer"){
}

void GameLayer::onAttach(){
	cameraEntity = clv::Application::get().getManager().createEntity<clv::ecs::CameraComponent, clv::ecs::Transform3DComponent>();
	sphereEntity = clv::Application::get().getManager().createEntity<clv::ecs::MeshComponent, clv::ecs::Transform3DComponent>();

	tempLight = clv::Application::get().getManager().createEntity<clv::ecs::LightComponent, clv::ecs::Transform3DComponent>();

	sphereEntity.getComponent<clv::ecs::Transform3DComponent>()->setLocalPosition({ 5.0f, 0.0f, 0.0f });
	sphereEntity.getComponent<clv::ecs::MeshComponent>()->setMesh("res/Objects/sphere.obj");
	sphereEntity.getComponent<clv::ecs::MeshComponent>()->setDiffuseTexture("res/Textures/container2.png");
	//sphereEntity.getComponent<clv::ecs::MeshComponent>()->setSpecularTexture("res/Textures/container2_specular.png");
}

void GameLayer::onDetach(){

}

void GameLayer::onUpdate(clv::utl::DeltaTime deltaTime){

}

void GameLayer::onEvent(clv::Event& e){

}