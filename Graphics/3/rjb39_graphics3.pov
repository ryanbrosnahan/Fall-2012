#include "colors.inc"                                          
global_settings
{
        assumed_gamma 2.2
        
        // Add a generic ambient light
        ambient_light rgb<1, 1, 1> 
        
}

// Add the camera pointing down into the room
camera
{
        location  <0,  10,  -50>
        look_at   <0,  4,  0>
}

// Create a glass texture
#declare Glass =
material 
{
        texture 
        {
                pigment
                {
                        rgbt 1
                }
                finish 
                {
                        ambient 0.0
                        diffuse 0.5
                        specular 0.6
                        roughness 0.005
                        reflection 
                        {
                                0.1, 1.0
                                fresnel on
                        }
                        conserve_energy
                }
        }
        
}

// Setup our basic box for the scene
union
{
        #declare wavy =
         texture {
             material_map {
                png "povmap.png"
                texture {  //used with index 0
                   pigment {color red 0.3 green 0.1 blue 1}
                   normal  {ripples 0.85 frequency 10 }
                   finish  {specular 0.3}
                   scale 5
                }
        
             }
             scale 30
             translate <-15, -15, 0>
          }

        plane { z, 20  texture { wavy }                  } // back wall
        plane { y, -45   texture { wavy } translate -y * 80 } // floor                
        
        // Create the hollow ceiling dome
        sphere
        {
                <0, 20, 0>, 5
                material { Glass }

        }
        
        cylinder {
                <0, -10, 0>,
                <0, 19, 0>,
                1
                open
                material { Glass }
        }
        
        

}

// Setup some awesome crazy spotlights
light_source
{
        <0, 16, 0>
        color Red
        spotlight
        radius 25
        falloff 25
        tightness 10
        point_at <sin(clock * 2) * 3, sin(clock * 3) * 2, cos(clock * 7) * 10>
}


light_source
{
        <0, 16, 0>
        color Green
        spotlight
        radius 15
        falloff 20
        tightness 10
        point_at <sin(clock * 5) * 3, cos(clock * 5) * 2, sin(clock * 5) * 10>
}

light_source
{
        <0, 16, 0>
        color Blue
        spotlight
        radius 20
        falloff 1
        tightness 10
        point_at <1, sin(clock * 7) * 3, sin(clock * 3) * 3>
}



torus
{
        4, 9              // major and minor radius
        rotate -90*x      // so we can see it from the top
        material { Glass }
}

// Setup a point light for better illumination of the scene
light_source
{
        <0, 15, 0>
        color rgb <0.9, 0.6, 0.6>
}