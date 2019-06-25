#version 330

in vec4 l;
in vec4 l2;
in vec4 n;
in vec4 v;
in vec2 iTexCoord0;

uniform sampler2D textureMap0;

out vec4 pixelColor;

void main(void) {
    vec4 ld=vec4(1,1,1,1); 
    vec4 ks=vec4(1,1,1,1); 
    vec4 ls=vec4(1,1,1,1); 

    vec4 kd=texture(textureMap0,iTexCoord0);

    vec4 ml=normalize(l);
    vec4 ml2=normalize(l2);
    vec4 mn=normalize(n);
    vec4 mv=normalize(v);
    vec4 mr=reflect(-ml,mn); 
    vec4 mr2=reflect(-ml2,mn); 

    float nl=clamp(dot(mn,ml),0,1); 
    float nl2=clamp(dot(mn,ml2),0,1); 
    float rv=pow(clamp(dot(mr,mv),0,1),25); 
    float rv2=pow(clamp(dot(mr2,mv),0,1),25); 

	vec4 color=vec4(kd.rgb*ld.rgb*nl+ks.rgb*ls.rgb*rv,kd.a);
    vec4 color2=vec4(kd.rgb*ld.rgb*nl2+ks.rgb*ls.rgb*rv2,kd.a);
	pixelColor=clamp(color*.7+color2*0.7,0,1);
}