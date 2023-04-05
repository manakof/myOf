#version 150
out vec4 outputColor;
uniform float u_time;
uniform vec2 u_mouse;
uniform vec2 u_resolution;
uniform float sc_msg;
uniform float sc_sin;
uniform float sc_saw;
uniform float sc_noise;

float plotX(vec2 st,vec2 pos){
  return step(pos.x-.004,st.x)-step(pos.x+.004,st.x);
} 
float plotY(vec2 st,vec2 pos){
  return step(pos.y-.004,st.y)-step(pos.y+.004,st.y);
} 
float circle(vec2 st,float radius){
  vec2 dist = st-vec2(0.);
  return smoothstep(radius-.001,radius+.001,dot(dist,dist));
  }

void main(){
  vec2 st = gl_FragCoord.xy/u_resolution;
  st = st*2.-1.;

  vec3 color = vec3(.5);
  float pttn = 1.;

  float pct = st.x;
  float pt  = plotX(st,vec2(.0,.0));
  vec3 plot_color = pt * vec3(.4,.3,.5);
  pttn = pttn*(1.-pt);
  color *= pttn;
  color += plot_color;

  float pty  = plotY(st,vec2(.0,.0));
  color *=  (1.-pty);  
  color += pty*vec3(0.,0.,1.);

  float crcl = circle(st,0.005);
  vec3 crcl_color = (1.-crcl) * vec3(.0,.4,.8);
  color *= crcl;
  color += crcl_color;

  outputColor = vec4(color,1.0);
}
