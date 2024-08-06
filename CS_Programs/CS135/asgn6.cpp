/*
 * Alec Him
 * CS 135 - Assignment 6
 * Description: Distribute droids (randomly) to either a User or Admin
 * Input: Strings and Char
 * Output: Outfile
 */
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <fstream>

int main()
{
    // Initialize Random Seed
    srand(time(nullptr));
    
    // Variables
    int value = rand() % 4, recordCount = 0;
    int admin_count = 0, main_count = 0, proto_count = 0, astro_count = 0;
    std::string inFile = "", outFile = "";
    std::ifstream iFile;
    std::ofstream oFile;
    char y_n;
    std::string name1 = "", name2 = "", type = "", model = "";

    enum DROID_TYPES { ADMINISTRATIVE, MAINTENANCE, PROTOCOL, ASTROMECH };
    enum ADMINISTRATIVE_TYPES { ET_74, XA_540, a3D_4X };
    enum MAINTENANCE_TYPES { F1_DX, EB_89, CB_2B, SA_45 };
    enum PROTOCOL_TYPES { C3PO, L80, SA_5, RA_7 };
    enum ASTROMECH_TYPES { M4_Y6, BB_8, D3_S5, R2_D2 };

    // Display Menu  
    // -Input File
    do{
        std::cout << "Enter file name to process: ";
        std::cin >> inFile;
        iFile.open(inFile);
        if(!iFile.is_open())
            std::cout << "Error - \"" << inFile << "\" did not open.\n";
    } while(!iFile.is_open());
    // - Output File
    do{
        std::cout << "Enter output file name: ";
        std::cin >> outFile;
        oFile.open(outFile);
        if(!oFile.is_open())
            std::cout << "Error - \"" << outFile << "\" did not open.\n";
    } while(!oFile.is_open());

    // True or False Records Processing
    do{
        std::cout << "Would you like to process all the records in the file? (y/n): ";
        std::cin >> y_n;
        switch(y_n)
        {
            case 'y':
                // Count all the records
                while(iFile >> name1 >> name2)
                {       
                    recordCount++;
                }
                iFile.clear();      // Clear EOF Flag
                iFile.seekg(0);     // Return to beginning of file
                break;
            case 'n':
                do{
                    std::cout << "Enter number of records to process: ";
                    std::cin >> recordCount;
                    if(std::cin.fail() || recordCount <= 0)
                    {
                        std::cin.clear();
                        std::cin.ignore(40, '\n');
                        std::cout << "\nXXXXXXXXXX Error-non numeric or negative value, try again\n\n";
                    }
                } while(recordCount <= 0);
                
                std::cout << "Maximum requested record count of " << recordCount << " reached.\n";
                break;

            default:
                std::cin.clear();
                std::cin.ignore(40, '\n');
                std::cout << "Invalid Character - Please Try Again.\n";
        }
    } while(y_n != 'y' && y_n != 'n');

    for(int i = 0; i < recordCount; i++)
    {
        iFile >> name1 >> name2;

        DROID_TYPES droid = ADMINISTRATIVE;
        droid = static_cast<DROID_TYPES>(value);

        ADMINISTRATIVE_TYPES admin = ET_74;
        admin = static_cast<ADMINISTRATIVE_TYPES> (value);

        MAINTENANCE_TYPES main = F1_DX;
        main = static_cast<MAINTENANCE_TYPES> (value);

        PROTOCOL_TYPES proto = C3PO;
        proto = static_cast<PROTOCOL_TYPES> (value);

        ASTROMECH_TYPES astro = M4_Y6;
        astro = static_cast<ASTROMECH_TYPES> (value);

        switch(droid)
        {
            case ADMINISTRATIVE:
                if(name1 == "Admiral" || name1 == "Captain" || name1 == "Commander" || name1 == "Darth" || name1 == "Emperor" || name1 == "Queen")
                {
                    type = "administrative";
                }
                switch(admin)
                {
                    case ET_74:
                        model = "ET-74";
                        break;
                    case XA_540:
                        model = "XA-540";
                        break;
                    case a3D_4X:
                        model = "a3D-4X";
                        break;
                }
                admin_count++;
                break;
            case MAINTENANCE:
                type = "maintenance";
                switch(main)
                {
                    case F1_DX:
                        model = "F1-DX";
                        break;
                    case EB_89:
                        model = "EB-89";
                        break;
                    case CB_2B:
                        model = "CB-2B";
                        break;
                    case SA_45:
                        model = "SA-45";
                        break;
                }
                main_count++;
                break;
            case PROTOCOL:
                type = "protocol";
                switch(proto)
                {
                    case C3PO:
                        model = "C-3PO";
                        break;
                    case L80:
                        model = "L-80";
                        break;
                    case SA_5:
                        model = "SA-5";
                        break;
                    case RA_7:
                        model = "RA-7";
                        break;
                }
                proto_count++;
                break;
            case ASTROMECH:
                type = "astromech";
                switch(astro)
                {
                    case M4_Y6:
                        model = "M4-Y6";
                        break;
                    case BB_8:
                        model = "BB-8";
                        break;
                    case D3_S5:
                        model = "D3-S5";
                        break;
                    case R2_D2:
                        model = "R2-D2";
                        break;
                }
                astro_count++;
                break;
        }

        // Output Data to File
        oFile << "Number";
        oFile << std::setw(11) << "First Name";
        oFile << std::setw(14) << "Last Name";
        oFile << std::setw(16) << "Droid Type";
        oFile << std::setw(11) << "Model";
        oFile << "\n------------------------------------------------------------" << std::endl;

        oFile << std::setw(4) << std::setfill('0') << i;
        oFile << std::setfill(' ') << std::setw(10) << name1;
        oFile << std::setw(14) << name2;
        oFile << std::setw(23) << type;
        oFile << std::setw(8) << model << std::endl;

        oFile << "*********************" << std::endl;
        oFile << "Assigned Droid Count " << std::endl;
        oFile << "*********************" << std::endl;

        oFile << "Astromech:" << std::setw(10) << astro_count << std::endl;
        oFile << "Maintenance:" << std::setw(8) << main_count << std::endl;
        oFile << "Protocol:" << std::setw(11) << proto_count << std::endl;
        oFile << "Administrative:" << std::setw(5) << admin_count << std::endl << std::endl << std::endl;

        oFile << "Total Droids Required" << std::setw(6) << i << std::endl;

    }

    // Close files
    iFile.close();
    oFile.close();

    // End Menu
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