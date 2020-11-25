#ifndef TRIANGLES_HPP
#define TRIANGLES_HPP
struct Triangles
{
    int vertexIndex1 { 0 };
    int vertexIndex2 { 0 };
    int vertexIndex3 { 0 };

    bool operator==(const Triangles &rhs) const {
        return vertexIndex1 == rhs.vertexIndex1 &&
               vertexIndex2 == rhs.vertexIndex2 &&
               vertexIndex3 == rhs.vertexIndex3;
    }
};


#endif // TRIANGLES_HPP
