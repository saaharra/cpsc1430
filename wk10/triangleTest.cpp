// triangleTest.cpp - Tests Triangles

#include <gtest/gtest.h>
#include "triangle.h"

TEST(TriangleTest, Invalid) {
	EXPECT_EQ(triangleType(1, 2, 4), 'n');
	EXPECT_EQ(triangleType(8, 2, 6), 'n');
	EXPECT_EQ(triangleType(8, 20, 4), 'n');
	EXPECT_EQ(triangleType(0, 0, 0), 'n');
	EXPECT_EQ(triangleType(-1, 1, -1), 'n');
}

TEST(TriangleTest, Equilateral) {
	EXPECT_EQ(triangleType(1, 1, 1), 'e');
	EXPECT_EQ(triangleType(5, 5, 5), 'e');
}

TEST(TriangleTest, Isosceles) {
	EXPECT_EQ(triangleType(6, 6, 9), 'i');
	EXPECT_EQ(triangleType(7, 10, 7), 'i');
	EXPECT_EQ(triangleType(3, 4, 4), 'i');
}

TEST(TriangleTest, Scalene) {
	EXPECT_EQ(triangleType(8, 2, 9), 's');
	EXPECT_EQ(triangleType(7, 12, 10), 's');
}

int main(int argc, char** argv) {
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
