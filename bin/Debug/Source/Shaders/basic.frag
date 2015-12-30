#version 330 core

layout (location = 0) out vec4 color;

in DATA {
	vec4 position;
	vec2 uv;
	float tid;
	vec4 color;
} fs_in; 

uniform vec2 light_pos;
uniform sampler2D tex[32];

void main() {
	
	float intensity = 1.0 / length(fs_in.position.xy - light_pos);	
	
	vec4 texColor = fs_in.color;

	if(fs_in.tid > 0.0) {
		int tid = int(fs_in.tid - 0.5);
		texColor =  fs_in.color * texture(tex[tid], fs_in.uv);
	}

	color = vec4((texColor).rgb, texColor.a);
}