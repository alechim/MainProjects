/*
 * Alec Him
 * CS 135 - Assignment 4
 * Description: Calculates dimensions of star shapes
 * Input: Length, Base Length, Edge Length, Inner Angle, Point Count, Outer Angle
 * Output: Height, Lateral Surface, Area, Volume, Focal Point, Gain
*/
#include <iostream>    // For console input and output
#include <cmath>       // For pow(), sqrt(), etc.
#include <iomanip>     // For setprecision(), fixed(), etc.

int main()
{
    // Variables
    const double PI = 3.141592653589;
    char c;
    // - Double Star Polygon
    double height, length, base, diameter, heightLong, heightShort, perimeter, lengthShort, lengthLong, area = 0.0;
    // - Threestar Polygon
    double outerAngle, innerAngle, spikeBase, edgeLength, spikeHeight, chordLength = 0.0;
    // - Polygram
    double pointCount, baseLength = 0.0;

    // Display Options for User
    std::cout << "\n****************************************\n";
    std::cout << "*  Rebel Alliance Computation Support  *\n";
	std::cout << "*  Star Area Calculator                *\n";
	std::cout << "****************************************\n";
    std::cout << "\n(d/D/2) - Double Star Polygon\n";
    std::cout << "(t/T/3) - Three Star Polygon\n";
    std::cout << "(p/P) - Polygram Polygon\n";
    std::cout << "(q/Q) - Quit\n";

    // Prompt User for Input
    std::cout << "\nYour Selection: ";
    std::cin >> c;

    switch(c)
    {
        case 'd':
        case 'D':
        case '2':
            // Double Star Polygon
            std::cout << "\n Double Star Polygon Calculator:\n";
            std::cout << "------------------------------\n\n";

            std::cout << "Length Long Valid Range [1.00 < Length Long < 236.00]\n";
            do
            {
                std::cout << "Length Long: ";
                std::cin >> lengthLong;
            } while (1.00 >= lengthLong && lengthLong >= 236.00);
            
            std::cout << "Length Short Valid Range [1.00 < Length Short < 118.00]\n";
            do
            {
                std::cout << "Length Short: ";
                std::cin >> lengthShort;
            } while (1.00 >= lengthShort && lengthShort >= 118.00);
            
            std::cout << "Base Length Valid Range [1.00 < Base Short < 29.50]\n";
            do
            {
                std::cout << "Base: ";
                std::cin >> base;
            } while (1.00 >= base && base >= 29.50);

            // Perform Calculations based on prior input
            height = sqrt(pow(length, 2.0) - pow(base, 2.0) / 4.0);
			heightLong = sqrt(pow(lengthLong, 2.0) - pow(base, 2.0) / 4.0);
			heightShort = sqrt(pow(lengthShort, 2.0) - pow(base, 2.0) / 4.0);
			length = sqrt(pow(height, 2.0) + pow(base, 2.0) / 4.0);
			diameter = 2 * heightLong + base * (1 + sqrt(2));
			perimeter = 8 * (lengthShort + lengthLong);
			area = 2 * base * (base * (1 + sqrt(2)) + (heightLong + heightShort));
        
            // Display Calculations
            std::cout << "--------------------------------------\n";
            std::cout << "Calculations for a Double Star Polygon\n";
            std::cout << "Base Length: " << std::fixed << std::setprecision(2) << base << std::endl;
            std::cout << "Length Long: " << std::fixed << std::setprecision(2) << lengthLong << std::endl;
            std::cout << "Length Short: " << std::fixed << std::setprecision(2) << lengthShort << std::endl;
            std::cout << "--------------------------------------\n";
            std::cout << "Height Long: " << heightLong << std::endl;
            std::cout << "Height Short: " << heightShort << std::endl;
            std::cout << "Diameter: " << diameter << std::endl;
            std::cout << "Perimeter: " << perimeter << std::endl;
            std::cout << "Area: " << area << std::endl;

            break;
        case 't':
        case 'T':
        case '3':
            // Three Star Polygon
            std::cout << "\n Three Star Polygon Calculator:\n";
            std::cout << "------------------------------\n\n";

            std::cout << "Edge Length Valid Range [1.00 < Edge Length < 132.00]\n";
            do
            {
                std::cout << "Edge Length: ";
                std::cin >> edgeLength;
            } while (1.00 >= edgeLength && edgeLength >= 132.00);

            std::cout << "Inner Angle (Degrees) Valid Range [0.00 < Inner Angle < 60.00]\n";
            do
            {
                std::cout << "Inner Angle (Degrees): ";
                std::cin >> innerAngle;
            } while (0.00 >= innerAngle && innerAngle >= 60.00);

            // Perform Calculations based on prior input
            outerAngle = 120 + edgeLength;
			spikeBase = sqrt(2 * pow(edgeLength, 2.0) * (1 - cos(edgeLength * PI/180)));
			spikeHeight = sqrt((4 * pow(edgeLength, 2.0) - pow(spikeBase, 2.0)) / 4.0);
			chordLength = sqrt(2 * pow(edgeLength, 2.0) * (1 - cos(outerAngle * PI/180)));
			height = sqrt(3) / 2 * chordLength;
			perimeter = 6 * edgeLength;
			area = 3.0/2.0 * spikeHeight * spikeBase + sqrt(3)/4 * pow(spikeBase, 2.0);

            // Display Calculations
            std::cout << "------------------------------------\n";
            std::cout << "Calculations for a Threestar Polygon\n";
            std::cout << "Edge Length: " << std::fixed << std::setprecision(2) << edgeLength << std::endl;
            std::cout << "Outer Angle: " << std::fixed << std::setprecision(2) << outerAngle << std::endl;
            std::cout << "Inner Angle: " << std::fixed << std::setprecision(2) << innerAngle << std::endl;
            std::cout << "------------------------------------\n";
            std::cout << "Spike Base: " << spikeBase << std::endl;
            std::cout << "Spike Height: " << spikeHeight << std::endl;
            std::cout << "Chord Length: " << chordLength << std::endl;
            std::cout << "Height: " << height << std::endl;
            std::cout << "Perimeter: " << perimeter << std::endl;
            std::cout << "Area: " << area << std::endl;

            break;
        case 'p':
        case 'P':
            // Polygram
            std::cout << "\n Polygram Polygon Calculator:\n";
            std::cout << "-----------------------------\n\n";

            std::cout << "Point Count Valid Range [3.00 < Point Count < 100.00]\n";
            do
            {
                std::cout << "Point Count: ";
                std::cin >> pointCount;
            } while (3.00 >= pointCount && pointCount >= 100.00);

            std::cout << "Edge Length Valid Range [1.00 < Edge Length < 132.00]\n";
            do
            {
                std::cout << "Edge Length: ";
                std::cin >> edgeLength;
            } while (0.00 >= edgeLength && edgeLength >= 132.00);
            
            std::cout << "Outer Angle (Degrees) Valid Range [0.00 < Outer Angle < 60.00]\n";
            do
            {
                std::cout << "Outer Angle: ";
                std::cin >> outerAngle;
            } while (0.00 >= outerAngle && outerAngle >= 60.00);

            // Perform Calculations based on prior input
            innerAngle = ((outerAngle * PI/180) - (2 * PI) / pointCount) * (180 / PI);
            baseLength = sqrt(2 * pow(edgeLength, 2.0) * (1 - cos(innerAngle * PI/180)));
            spikeHeight = sqrt((4 * pow(edgeLength, 2.0) - pow(baseLength, 2.0)) / 4.0);
            chordLength = sqrt(2 * pow(edgeLength, 2.0) * (1 - cos(outerAngle * PI/180)));
            perimeter = 2 * pointCount * edgeLength;
            area = pointCount * pow(baseLength, 2.0) / (4 * tan(PI / pointCount)) + pointCount * spikeHeight * baseLength / 2.0;

            // Display Calculations
            std::cout << "-------------------------\n";
            std::cout << "Calculations for Polygram\n";
            std::cout << "Point Count: " << pointCount << std::endl;
            std::cout << "Edge Length: " << std::fixed << std::setprecision(2) << edgeLength << std::endl;
            std::cout << "Outer Angle: " << std::fixed << std::setprecision(2) << outerAngle << std::endl;
            std::cout << "-------------------------" << std::endl;
            std::cout << "Inner Angle: " << innerAngle << std::endl;
            std::cout << "Base Length: " << baseLength << std::endl;
            std::cout << "Chord Length: " << chordLength << std::endl;
            std::cout << "Spike Height: " << spikeHeight << std::endl;
            std::cout << "Perimeter: " << perimeter << std::endl;
            std::cout << "Area: " << area << std::endl;
            break;
        case 'q':
        case 'Q':
            break;
        default:
            std::cout << "\nError - Invalid Entry\n";
    }

    std::cout << "\nThank you for using Rebel Alliance Computational Support" << std::endl;
	std::cout << "May the Force be with you!" << std::endl;

	std::cout << "            x            " << std::endl;
	std::cout << "      x    xxx    x      " << std::endl;
	std::cout << "     x    x x x    x     " << std::endl;
	std::cout << "    x      xxx      x    " << std::endl;
	std::cout << "   xx       x       xx   " << std::endl;
	std::cout << "  xxx      xxx      xxx  " << std::endl;
	std::cout << "  xxxx     xxx     xxxx  " << std::endl;
	std::cout << "  xxxxx    xxx    xxxxx  " << std::endl;
	std::cout << "   xxxxxxxxxxxxxxxxxxx   " << std::endl;
	std::cout << "    xxxxxxxxxxxxxxxxx    " << std::endl;
	std::cout << "     xxxxxxxxxxxxxxx     " << std::endl;
	std::cout << "      xxxxxxxxxxxxx      " << std::endl;

    return 0;
}