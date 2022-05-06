//vert shader that takes color from the vaBufferObject and passes it forward
#version 450 

layout(binding = 0) uniform UniformBufferObject {
	mat4 model; 
	mat4 view; 
	mat4 proj; 
} ubo; 

layout(binding = 1) buffer vaBufferObject {
	vec3[] colors; 
} va; 

layout(location = 0) in vec2 inPosition; 

layout(location = 0) out vec3 fragColor; 

void main() {
	gl_Position = ubo.proj * ubo.view * ubo.model * vec4(inPosition, 0.0, 1.0); 
	/*
	if (gl_VertexIndex == 0){
		fragColor = vec3(1.0, 0.0, 0.0);
	}
	if (gl_VertexIndex == 1){
		fragColor = vec3(1.0, 0.0, 0.0);
	}	
	if (gl_VertexIndex == 2){
		fragColor = vec3(1.0, 0.0, 0.0);
	}	
	if (gl_VertexIndex == 3){
		fragColor = vec3(1.0, 0.0, 0.0);
	}
	*/ 
	fragColor = va.colors[gl_VertexIndex];
	//gl_VertexIndex
}