#include "clvpch.hpp"
#include "Material.hpp"

#include "Clove/Rendering/API/Shader.hpp"
#include "Clove/Rendering/API/Texture.hpp"

namespace clv{
	Material::Material(){
		createMaterial("../Clove/res/Textures/DefaultTexture.png");
	}

	Material::Material(const std::string& texturePath){
		createMaterial(texturePath);
	}

	Material::Material(const Material& other){
		CLV_WARN("Copy constructor called on material - creating new material data");
		
		createMaterial(other.diffuseTexturePath);
		
		if(!other.specularTexturePath.empty()){
			createSpecularTexture(other.specularTexturePath);
		} else{
			specularTexturePath.clear();
			specularTexture.reset();
		}
	}

	Material::Material(Material&& other) noexcept{
		shader = std::move(other.shader);
		
		diffuseTexture = std::move(other.diffuseTexture);
		specularTexture = std::move(other.specularTexture);
		
		diffuseTexturePath = std::move(other.diffuseTexturePath);
		specularTexturePath = std::move(other.specularTexturePath);
	}

	Material::~Material() = default;

	void Material::setSpecularTexture(const std::string& path){
		createSpecularTexture(path);
	}

	void Material::bindShader(){
		shader->bind();
	}

	void Material::unbindShader(){
		shader->unbind();
	}

	void Material::bindTexture(){
		shader->bind();

		//NOTE: when binding to slot 1 - any unitialised samplers will use that texture
		//To avoid the spec map using the diffuse map we don't use slot 0
		//TODO: decide if this is desired or not
		diffuseTexture->bind(1);
		shader->setUniform<int>("material.diffuse", 1);

		if(specularTexture){
			specularTexture->bind(2);
			shader->setUniform<int>("material.specular", 2);
		}
	}

	void Material::unbindTexture(){
		diffuseTexture->unbind();
		shader->unbind();
	}

	void clv::Material::setUniform1i(const std::string& name, int value){
		shader->bind();
		shader->setUniform(name, value);
	}

	void Material::setUniform1f(const std::string& name, float value){
		shader->bind();
		shader->setUniform(name, value);
	}

	void Material::setUniform3f(const std::string& name, const math::Vector3f& value){
		shader->bind();
		shader->setUniform(name, value);
	}

	void Material::setUniform4f(const std::string& name, const math::Vector4f& value){
		shader->bind();
		shader->setUniform(name, value);
	}

	void Material::setUniform4m(const std::string& name, const math::Matrix4f& value){
		shader->bind();
		shader->setUniform(name, value);
	}

	Material& Material::operator=(const Material& other){
		CLV_WARN("Copy assignment operator called on material - creating new material data");
		
		createMaterial(other.diffuseTexturePath);
		
		if(!other.specularTexturePath.empty()){
			createSpecularTexture(other.specularTexturePath);
		} else{
			specularTexturePath.clear();
			specularTexture.reset();
		}

		return *this;
	}

	Material& Material::operator=(Material&& other) noexcept{
		shader = std::move(other.shader);
		
		diffuseTexture = std::move(other.diffuseTexture);
		specularTexture = std::move(other.specularTexture);

		diffuseTexturePath = std::move(other.diffuseTexturePath);
		specularTexturePath = std::move(other.specularTexturePath);

		return *this;
	}

	void Material::createMaterial(const std::string& texturePath){
		CLV_TRACE("Creating material with: {0}", texturePath);

		diffuseTexturePath = texturePath;
		
		shader = std::make_unique<Shader>(Shader());

		shader->attachShader(ShaderTypes::Vertex, "../Clove/res/Shaders/VertexShader.glsl");
		shader->attachShader(ShaderTypes::Fragment, "../Clove/res/Shaders/FragmentShader.glsl");

		diffuseTexture = std::make_unique<Texture>(Texture(texturePath));
	}

	void Material::createSpecularTexture(const std::string& texturePath){
		specularTexturePath = texturePath;
		specularTexture = std::make_unique<Texture>(Texture(texturePath));
	}
}