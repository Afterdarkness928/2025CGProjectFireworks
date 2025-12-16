#version 330 core
layout(location = 0) in vec3 aPos;
layout(location = 1) in vec4 aColor;
layout(location = 2) in float aLife;
layout(location = 3) in float aMaxLife;
layout(location = 4) in float aSize;

out vec4 v_color;      // 传递颜色+alpha
out float v_lifeT;     // 传递生命百分比

uniform mat4 projection;
uniform mat4 view;
uniform mat4 model;

void main(){
    v_lifeT = aLife / aMaxLife;

    // 标准 MVP
    vec4 viewPos   = view * model * vec4(aPos, 1.0);
    gl_Position    = projection * viewPos;

    // 透视缩放：远小近大
    float depth    = max(-viewPos.z, 1.0);
    gl_PointSize   = aSize * (400.0 / depth);   // 整体粗细可调

    // 只衰减 alpha，颜色不变
    v_color        = vec4(aColor.rgb, aColor.a * v_lifeT);
}