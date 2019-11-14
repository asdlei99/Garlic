//cmake generated header file

static const std::string shader_2D_ps = R"(
#version 460 core

in vec2 vertTexCoord;

layout(binding = 1) uniform sampler2D albedoSampler;

layout(location = 0) out vec4 fragmentColour;

layout(std140, binding = 11) uniform colourDataBuffer{
	vec4 colour;
};

void main(){
	fragmentColour = vec4(texture(albedoSampler, vertTexCoord) * colour);
}

)";