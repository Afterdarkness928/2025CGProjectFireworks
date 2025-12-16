#version 330 core
in  vec4 v_color;
in  float v_lifeT;
out vec4 FragColor;

void main(){
    // 1. 数学软圆：径向指数辉光
    vec2  uv   = gl_PointCoord * 2.0 - 1.0;      // -1→1 圆盘
    float d    = length(uv);
    if (d > 1.0) discard;                        // 硬圆边界

    float glow = exp(-d * 4.0);                  // 指数辉光（可调 3-6）
    float alpha = v_color.a * glow;              // 只调 alpha，不改 rgb

    // 2. 输出：纯颜色 + 软边淡出
    FragColor = vec4(v_color.rgb, alpha);
}