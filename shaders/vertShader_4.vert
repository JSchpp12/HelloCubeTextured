//Used in rotating flat square, last in branch "UniformBuffers"

#version 450 
//Descriptor Set Note: 
//Can bind to multiple descriptor sets at the same time. 
//In this case, can be accessed with something like: 
//layout(set = 0, binding = 0) uniform UniformBufferObject{...}

layout(binding = 0) uniform UniformBufferObject {
	mat4 model; 
	mat4 view; 
	mat4 proj; 
} ubo; 

layout(location = 0) in vec2 inPosition; 
layout(location = 1) in vec3 inColor; 

layout(location = 0) out vec3 fragColor; 

void main() {
	gl_Position = ubo.proj * ubo.view * ubo.model * vec4(inPosition, 0.0, 1.0); 
	fragColor = inColor; 
}