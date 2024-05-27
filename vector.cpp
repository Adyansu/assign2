#include <iostream>
#include <cmath>
using namespace std;
class vector3d
{
private:
    float x;
    float y;
    float z;

public:
    vector3d(float x1, float y1, float z1)
    {
        x = x1;
        y = y1;
        z = z1;
        
    }

    int getx() { return x; }
    int gety() { return y; }
    int getz() { return z; }

    void setx(float x1) { x = x1; }
    void sety(float y1) { y = y1; }
    void setz(float z1) { z = z1; }

    vector3d mult(float k, vector3d vec)
    {
        float x1 = vec.x * k;
        float y1 = vec.y * k;
        float z1 = vec.z * k;
        return vector3d(x1, y1, z1);
    }

    vector3d div(float k, vector3d vec)
    {
        float x1 = vec.x / k;
        float y1 = vec.y / k;
        float z1 = vec.z / k;
        return vector3d(x1, y1, z1);
    }

    vector3d add(vector3d vec1, vector3d vec2)
    {

        float x1 = vec1.x + vec2.x;
        float y1 = vec1.y + vec2.y;
        float z1 = vec1.z + vec2.z;
        return vector3d(x1, y1, z1);
    }

    vector3d sub(vector3d vec1, vector3d vec2)
    {
        float x1 = vec1.x - vec2.x;
        float y1 = vec1.y - vec2.y;
        float z1 = vec1.z - vec2.z;
        return vector3d(x1, y1, z1);
    }

    float dot(vector3d vec1, vector3d vec2)
    {
        return vec1.x * vec2.x + vec1.y * vec2.y + vec1.z * vec2.z;
    }

    vector3d cross(vector3d vec1, vector3d vec2)
    {
        float x1 = vec1.y * vec2.z - vec1.z * vec2.y;
        float y1 = vec1.z * vec2.x - vec1.x * vec2.z;
        float z1 = vec1.x * vec2.y - vec1.y * vec2.x;
        return vector3d(x1, y1, z1);
    }

    vector3d rev(vector3d vec)
    {
        vec.x = vec.x * (-1);
        vec.y = vec.y * (-1);
        vec.z = vec.z * (-1);
        return vec;
    }

    vector3d comp_mult(vector3d vec)
    {
        float x1 = vec.x * vec.x;
        float y1 = vec.y * vec.y;
        float z1 = vec.z * vec.z;
        return vector3d(x1, y1, z1);
    }

    float len(vector3d vec)
    {
        return sqrt(vec.x * vec.x + vec.y * vec.y + vec.z * vec.z);
    }

    float stp(vector3d vec1, vector3d vec2, vector3d vec3)
    {
        vector3d vec4 = cross(vec1, vec2);
        return dot(vec4, vec3);
    }

    vector3d unitvec(vector3d vec)
    {
        float d = len(vec);
        return vector3d(vec.x / d, vec.y / d, vec.z / d);
    }

    vector3d vectorgener(float r, float a, float b, float c)
    {
        float x1 = r * cos(a);
        float y1 = r * cos(b);
        float z1 = r * cos(c);
        return vector3d(x1, y1, z1);
    }

    vector3d vtp(vector3d vec1, vector3d vec2, vector3d vec3)
    {
        vector3d vec4 = cross(vec1, vec2);
        vector3d vec5 = cross(vec4, vec3);
        return vec5;
    }

    float angle(vector3d vec1, vector3d vec2)
    {
        vector3d uv1 = unitvec(vec1);
        vector3d uv2 = unitvec(vec2);
        float d = dot(uv1, uv2);
        float a = acos(d);
        return a;
    }

    vector3d inter_plane(float a, float b, float c, float d, vector3d vec)
    {
        vector3d uvec = unitvec(vec);
        float k = a * uvec.x + b * uvec.y + c * uvec.z;
        if (k == 0)
        {
            throw runtime_error("line is parallel to plane");
        }
        float t = -d / k;
        return vector3d(t * vec.x, t * vec.y, t * vec.z);
    }

    vector3d rotate_x(float a, vector3d vec)
    {
        float y1 = vec.y * cos(a) - vec.z * sin(a);
        float z1 = vec.y * sin(a) - vec.z * cos(a);
        return vector3d(x, y1, z1);
    }
    vector3d rotate_y(float a, vector3d vec)
    {
        float x1 = vec.x * cos(a) + vec.z * sin(a);
        float z1 = vec.z * cos(a) - vec.x * sin(a);
        return vector3d(x1, y, z1);
    }
    vector3d rotate_z(float a, vector3d vec)
    {
        float x1 = vec.x * cos(a) - vec.y * sin(a);
        float y1 = vec.x * sin(a) + vec.y * cos(a);
        return vector3d(x1, y1, z);
    }

    vector3d along_dir(vector3d vec1, vector3d vec2)
    {
        float t = angle(vec1, vec2);
        vector3d vec3 = unitvec(vec2);
        float a = len(vec1);
        return mult(t * a, vec3);
    }

    float along_len(vector3d vec1, vector3d vec2)
    {
        vector3d vec3 = along_dir(vec1, vec2);
        return len(vec3);
    }

    vector3d per_dir(vector3d vec1, vector3d vec2)
    {
        vector3d vec3 = along_dir(vec1, vec2);
        vector3d vec4 = sub(vec1, vec3);
        return vec4;
    }

    float per_len(vector3d vec1, vector3d vec2)
    {
        vector3d vec3 = per_dir(vec1, vec2);
        return len(vec3);
    }

    
    
};
