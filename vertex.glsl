#version 330

uniform mat4 P;
uniform mat4 V;
uniform mat4 M;
uniform vec4 lp1;
uniform vec4 lp2;

in vec4 vertex;
in vec4 normal;
in vec2 texCoord0;

out vec4 l1;
out vec4 l2;
out vec4 n;
out vec4 v;
out vec2 iTexCoord0;

void main(void) {

    l1=normalize(V*(lp1-M*vertex));
    l2=normalize(V*(lp2-M*vertex));
    n=normalize(V*M*normal);
    v=normalize(vec4(0,0,0,1)-V*M*vertex);

    iTexCoord0=texCoord0;

    gl_Position=P*V*M*vertex;
}
