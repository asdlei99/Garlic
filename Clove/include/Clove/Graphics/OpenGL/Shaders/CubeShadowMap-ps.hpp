//cmake generated header file

static const std::string shader_CubeShadowMap_ps = R"(
#version 460 core

in vec4 fragPos;

layout(std140, binding = 11) uniform lightPosBuffer {
	vec3 lightPosition;
	float farPlane;
};

void main(){
	const float lightDistance = (length(fragPos.xyz - lightPosition)) / farPlane;
	gl_FragDepth = lightDistance;
}

)";
