#include <cs50.h>
#include <stdio.h>



bool real_triangle(float x, float y, float z);

int main(void)
{

printf("Give the three sides of the triangle: ");
float x = get_float("Side x:");
float y = get_float("Side y:");
float z = get_float("Side z:");


if(x<0 || y<0 || z < 0)
{
    return false;
}



if((x + y >= z) || (x + z >= y)|| (z + y >= x))
{
    return false;
}
else
{
    return true;
}

}