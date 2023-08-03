//Sarah Nguyen
//March 15, 2021
//triangle.cpp
//correct the functions to try and test the triangles in triangleTest.cpp
//to figure out which triangles they are 

// Returns the triangle type based on the length of the three sides:
// 'e' : Equilateral triangle
// 'i' : Isosceles triangle
// 's' : Scalene triangle
// 'n' : Not a triangle
char triangleType(int side1, int side2, int side3)
{
    char choice = 's';  //default scalene
    if (side1 + side2 <= side3 || side2 + side3 <= side1 || side3 + side1 <= side2)
    {
        if((side1<=0) || (side2<=0) || (side3<=0))
        {
            choice = 'n';
        }
        
        choice = 'n';
    }
    // Check for equilateral triangle
    else if ((side1 == side2) && (side2 == side3))
      {
        choice = 'e';
      }

    // Check for isosceles triangle
    else if ((side1 == side2) || (side2 == side3) || (side1==side3))
      {
        choice = 'i';
      }
    return choice;
}
