#version 330


//Zmienne interpolowane
in vec4 ic;
in vec4 l;
in vec4 n;
in vec4 v;

out vec4 pixelColor; //Zmienna wyjsciowa fragment shadera. Zapisuje sie do niej ostateczny (prawie) kolor piksela

void main(void) {
    vec4 kd=ic; //Kolor obiektu
    vec4 ld=vec4(1,1,1,1); //Kolor swiatla (bialy)
    vec4 ks=vec4(1,1,1,1);
    vec4 ls=ld;

    vec4 ml=normalize(l);
    vec4 mn=normalize(n);
    vec4 mv=normalize(v);

    vec4 mr=reflect(-ml,mn);

    float nl=clamp(dot(mn,ml),0,1);// clamp - jesli ujemne to zwraca 0
    float rv=clamp(dot(mr,mv),0,1);
    rv=pow(rv,50);//cosinus kata rv

    nl=round(4*nl)/4;
    rv=round(4*rv)/4;

	pixelColor=vec4(kd.rgb*ld.rgb*nl + ks.rgb*ls.rgb*rv, kd.a);;
}
