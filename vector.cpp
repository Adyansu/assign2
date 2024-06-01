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

    vector3d mult(float k)
    {
        return vector3d(x*k, y*k, z*k);
    }

    vector3d div(float k)
    {
        
        return vector3d(x/k, y/k, z/k);
    }

    vector3d add(vector3d vec1)
    {
        return vector3d(x+vec1.x, y+vec1.y, z+vec1.z);
    }

    vector3d sub(vector3d vec1)
    {
        return vector3d(x-vec1.x, y-vec1.y, z-vec1.z);
    }

    float dot(vector3d vec1)
    {
        return vec1.x * x + vec1.y * y + vec1.z * z;
    }

    vector3d cross(vector3d vec1)
    {
        float x1 = y * vec1.z - z * vec1.y;
        float y1 = z * vec1.x - x * vec1.z;
        float z1 = x * vec1.y - y * vec1.x;
        return vector3d(x1, y1, z1);
    }

    vector3d rev()
    {
        
        return vector3d(-x,-y,-z);
    }

    vector3d comp_mult()
    {
        return vector3d(x*x, y*y, z*z);
    }

    float len()
    {
        return sqrt(x * x + y * y + z * z);
    }

    float stp(vector3d vec1, vector3d vec2)
    {
        vector3d vec4 = cross(vec1);
        return vec4.dot(vec2);
    }

    vector3d unitvec()
    {
        float d = len();
        return vector3d(x / d, y / d, z / d);
    }

    vector3d vectorgener(float r, int a, int b, int c)
    {
        float x1 = r * cos((a/180)*(acos(0.0)));
        float y1 = r * cos((b/180)*(acos(0.0)));
        float z1 = r * cos((c/180)*(acos(0.0)));
        return vector3d(x1, y1, z1);
    }

    vector3d vtp(vector3d vec1, vector3d vec2)
    {
        vector3d vec4 = cross(vec1);
        
        return vec4.cross(vec2);
    }

    int angle(vector3d vec1)
    {
        vector3d uv1 = unitvec();
        vector3d uv2 = vec1.unitvec();
        float d = uv1.dot(uv2);
        int a =(acos(d)/M_PI)*180;
        return a;
    }

    vector3d inter_plane(float a, float b, float c, float d)
    {
        vector3d uvec = unitvec();
        float k = a * uvec.x + b * uvec.y + c * uvec.z;
        if (k == 0)
        {
            throw runtime_error("line is parallel to plane");
        }
        float t = -d / k;
        return vector3d(t * x, t * y, t * z);
    }

    vector3d rotate_x(int a)
    {
        float y1 = y * cos((a/180)*acos(0.0)) - z * sin((a/180)*acos(0.0));
        float z1 = z * cos((a/180)*acos(0.0)) - y * sin((a/180)*acos(0.0));
        return vector3d(x, y1, z1);
    }
    vector3d rotate_y(int a)
    {
        float x1 = x * (cos((a/180)*acos(0.0))) + z * sin((a/180)*acos(0.0));
        float z1 = z * cos((a/180)*acos(0.0)) - x * sin((a/180)*acos(0.0));
        return vector3d(x1, y, z1);
    }
    vector3d rotate_z(int a)
    {
        float x1 = x * cos((a/180)*acos(0.0)) - y * sin((a/180)*acos(0.0));
        float y1 = x * sin((a/180)*acos(0.0)) + y * cos((a/180)*acos(0.0));
        return vector3d(x1, y1, z);
    }

    vector3d along_dir(vector3d vec1)
    {
        float t = angle(vec1);
        vector3d vec3 = vec1.unitvec();
        float a = len();
        return vec3.mult(cos(t/180)*(acos(0.0)) * a);
    }

    float along_len(vector3d vec1)
    {
        vector3d vec2 = along_dir(vec1);
        return vec2.len();
    }

    vector3d per_dir(vector3d vec1)
    {
        vector3d vec3 = along_dir(vec1);
        return sub(vec3);
        
    }

    float per_len(vector3d vec1)
    {
        vector3d vec3 = per_dir(vec1);
        return vec3.len();
    }
    vector3d operator+(vector3d vec1){
        return vector3d(x+vec1.x,y+vec1.y,z+vec1.z);
    }
    vector3d operator-(vector3d vec1){
        return vector3d(x-vec1.x,y-vec1.y,z-vec1.z);
    }
    vector3d operator*(vector3d vec1){
        return vector3d(x*vec1.x,y*vec1.y,z*vec1.z);
    }
    void print() const {
        cout<<x<<" "<<y<<" "<<z<<"\n";
    }
    
   
};

int main(){
    vector3d vec1(1.0,1.0,1.0);
    cout<<"the vector is: "<<vec1.getx()<<" "<<vec1.gety()<<" "<<vec1.getz()<<"\n";
    cout<<"enter a scalar: ";
    float a;
    cin>>a;
    vector3d v1= vec1.mult(a);
    vector3d v2= vec1.div(a);
    cout<<"vector after multiplying by scalar: ";
    v1.print();
    
    cout<<"vector after dividing by scalar: ";
    v2.print();
    
    vector3d v3=vec1.rev();
    vector3d v4=vec1.comp_mult();
    float k= vec1.len();
    vector3d v5=vec1.unitvec();
    cout<<"reversing the vector: ";
    v3.print();
    cout<<"component multiplication of the vector: ";
    v4.print();
    cout<<"length of the vector is "<<k<<"\n";
    float p,q,r;
    cout<<"enter a second vector: ";
    cin>>p>>q>>r;
    vector3d vec2(p,q,r);
    vector3d v6=vec1.add(vec2);
    vector3d v7=vec1.sub(vec2);
    vector3d ve=vec1.cross(vec2);
    float dot = vec1.dot(vec2);
    float ang = vec1.angle(vec2);
    vector3d v8=vec1.along_dir(vec2);
    vector3d v9=vec1.per_dir(vec2);
    float l1 = vec1.along_len(vec2);
    float l2 = vec1.per_len(vec2);
    cout<<"on adding: ";
    v6.print();
    cout<<"on subtracting: ";
    v7.print();
    cout<<"angle between the vectors is "<<ang;
    cout<<"\n";
    cout<<"vector along the second vector is ";
    v8.print();
    cout<<"length of the along vector is "<<l1<<"\n";
    cout<<"vector perpendicular to the second vector is ";
    v9.print();
    cout<<"length of the perpendicular vector is "<<l2<<"\n";
    cout<<"cross multiplying :";
    ve.print();
    cout<<"dot product :"<<dot<<"\n";

    float x,y,z;
    cout<<"enter a third vector: ";
    cin>>x>>y>>z;
    vector3d vec3(x,y,z);
    vector3d v10=vec1.vtp(vec2,vec3);
    float st=vec1.stp(vec2,vec3);
    cout<<"vector triple product gives ";
    v10.print();
    cout<<"scalar triple product gives "<<st<<endl;
    float q1,q2,q3;
    cout<<"angle to be rotated about x,y,z axes: ";
    cin>>q1>>q2>>q3;
    vector3d v11=vec1.rotate_x(q1);
    vector3d v12=vec1.rotate_y(q2);
    vector3d v13=vec1.rotate_z(q3);
    cout<<"vector after rotating about x axis is ";
    v11.print();
    cout<<"vector after rotating about y axis is ";
    v12.print();
    cout<<"vector after rotating about z axis is ";
    v13.print();
    float a1,a2,a3,a4;
    cout<<"write the magnitude of the vector followed by angles made by it with x,y,z axes :";
    cin>>a1>>a2>>a3>>a4;
    cout<<"\n";
    vector3d v14=vec1.vectorgener(a1,a2,a3,a4);
    cout<<"vector generated is: ";
    v14.print();
    float b1,b2,b3,b4;

    cout<<"give the values of a,b,c,d if we write equation of the plane as ax+by+cz+d=0 :";
    cin>>b1>>b2>>b3>>b4;
    vector3d v15=vec1.inter_plane(b1,b2,b3,b4);
    cout<<"point of intersection is ";
    v15.print();
    

}
